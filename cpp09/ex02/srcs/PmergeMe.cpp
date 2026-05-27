#include "../includes/PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& copy){*this = copy;}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T>& other)
{
	if (this != &other)
	{
		_before = other._before;
		_after = other._after;
	}
	return (*this);
}

template <typename T>
void	PmergeMe<T>::_parsing(char **av)
{
	int i = 1;
	std::string avs;

	while(av[i])
	{
		int j = 0;
		int	space = 0;
		while(av[i][j])
		{
			avs = av[i];
			if (!isdigit(av[i][j]) && !(av[i][j] == ' '))
				throw std::invalid_argument("bad input");
			if (av[i][j] == ' ' || (space != 0 && isdigit(av[i][j]) && !av[i][j+1]))
			{
				std::string tmp = avs.substr(space, j);
				if (atoi(tmp.c_str()) >= 0)
					_before.push_back(atoi(tmp.c_str()));
				else
					throw std::invalid_argument("bad input");
				space = j;
			}
			j++;
		}
		if (space == 0)
		{
			if (atoi(av[i]) >= 0)
				_before.push_back(atoi(av[i]));
			else
				throw std::invalid_argument("bad input");
		}
		i++;
	}
	_after = _before;
}

template <typename T>
long PmergeMe<T>::_calculateTime(struct timeval start, struct timeval end) const
{
	return ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);
}

template <typename T>
T	PmergeMe<T>::_sequenceJacobsthal(int n)
{
	T jacob;
	jacob.push_back(0);
	if (n == 0)
		return (jacob);
	jacob.push_back(1);
	
	while (jacob.back() < n)
	{
		int next = jacob[jacob.size()-1] + 2 * jacob[jacob.size() - 2];
		if (next >= n) break;
		jacob.push_back(next);
	}
	return (jacob);
}

template <typename T>
T	PmergeMe<T>::_sequenceInsertion(int n)
{
	T result;
	if (n <= 1)
		return result;
	T jacob = _sequenceJacobsthal(n);
	size_t last_jacob = 1;
	for (size_t i = 2; i < jacob.size(); i++) 
	{
		int current_jacob = jacob[i];
		int start = (current_jacob < n) ? current_jacob : n - 1;
		for (int j = start; j > (int)last_jacob; j--) 
		{
			result.push_back(j);
		}
		last_jacob = current_jacob;
	}

	if ((int)last_jacob < n) 
	{
		for (int j = n - 1; j > (int)last_jacob; j--) 
		{
			result.push_back(j);
		}
	}
	return (result);
}

template <typename T>
void	PmergeMe<T>::_updatePosWinner(int insert_pos, T& idx_main)
{
	for (int i = 0; i < (int)idx_main.size(); i++)
	{
		if (idx_main[i] >= insert_pos)
			idx_main[i]++;
	}
}

template <typename T>
void	PmergeMe<T>::_insertPending(T& main, T& idx_main, T& pending)
{
	if (pending.empty())
		return;
	T jacobsthal = _sequenceInsertion((int) pending.size());
	typename T::iterator it;
	std::vector<bool> inserted(pending.size(), false);

	{
		int value = pending[0];
		if (idx_main[0] < 0 || idx_main[0] > (int)main.size())
			it = lower_bound(main.begin(), main.end(), value);
		else
			it = lower_bound(main.begin(), main.begin() + idx_main[0], value);
		int insert_pos = std::distance(main.begin(), it);
		main.insert(it, value);
		_updatePosWinner(insert_pos, idx_main);
		inserted[0] = true;
	}

	for (int i = (int)jacobsthal.size() - 1; i >= 0; --i)
	{
		int idx = jacobsthal[i];
		if (idx <= 0 || idx >= (int)pending.size() || inserted[idx])
			continue;
		int value = pending[idx];
		if (idx_main[idx] < 0 || idx_main[idx] > (int)main.size())
			it = lower_bound(main.begin(), main.end(), value);
		else
			it = lower_bound(main.begin(), main.begin() + idx_main[idx], value);
		int insert_pos = std::distance(main.begin(), it);
		main.insert(it, value);
		_updatePosWinner(insert_pos, idx_main);
		inserted[idx] = true;
	}

	for (size_t idx = 0; idx < pending.size(); ++idx)
	{
		if (!inserted[idx])
		{
			int value = pending[idx];
			if (idx_main[idx] < 0 || idx_main[idx] > (int)main.size())
				it = lower_bound(main.begin(), main.end(), value);
			else
				it = lower_bound(main.begin(), main.begin() + idx_main[idx], value);
			int insert_pos = std::distance(main.begin(), it);
			main.insert(it, value);
			_updatePosWinner(insert_pos, idx_main);
			inserted[idx] = true;
		}
	}
}

template <typename T>
void	PmergeMe<T>::_createPairs(T& arr, std::vector<std::pair<int, int> >& pairs, T& pending, int& non_participating)
{
	if (arr.size() % 2 != 0)
		non_participating = arr.back();
	else
		non_participating = -1;

	for (int i = 0; i + 1 < (int)arr.size(); i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		int winner = std::max(a, b);
		int loser = std::min(a, b);
		pending.push_back(loser);
		pairs.push_back(std::make_pair(winner, (int)pending.size() - 1));
	}
}

template <typename T>
void	PmergeMe<T>::_sort(T& arr)
{	
	std::vector<std::pair<int, int> > pairs;
	T	pending;
	int	non_participating;

	if (arr.size() <= 1)
		return ;

	_createPairs(arr, pairs, pending, non_participating);

	T winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);

	_sort(winners);

	T idx_main;
	{
		std::vector<bool> used(winners.size(), false);
		for (size_t i = 0; i < pairs.size(); ++i)
		{
			int winner_value = pairs[i].first;
			int pos = -1;
			for (size_t j = 0; j < winners.size(); ++j)
			{
				if (!used[j] && winners[j] == winner_value)
				{
					pos = (int)j;
					used[j] = true;
					break;
				}
			}
			if (pos == -1)
			{
				std::cerr << "[PmergeMe] Warning: winner not found for value " << winner_value << ", defaulting pos=0\n";
				pos = 0;
			}
			idx_main.push_back(pos);
		}
	}

	T main = winners;
	_insertPending(main, idx_main, pending);

	if (non_participating != -1)
	{
		typename T::iterator it = lower_bound(main.begin(), main.end(), non_participating);
		main.insert(it, non_participating);
	}

	arr = main;
}

template <typename T>
void	PmergeMe<T>::_printEnd(struct timeval start, struct timeval end)
{
	if (typeid(T) == typeid(std::vector<int>))
	{
		std::cout << "Before: ";
		print(_before); 
		std::cout << "After: ";
		print(_after);
	}

	long time = _calculateTime(start, end);

	if (typeid(T) == typeid(std::vector<int>))
		std::cout << "Time to process a range of " << _before.size() << " elements with std::[vector] : " << time << " us" << "\n";
	else if (typeid(T) == typeid(std::deque<int>))
		std::cout << "Time to process a range of " << _before.size() << " elements with std::[deque] : " << time << " us" << "\n";
	else
		std::cout << "Time to process a range of " << _before.size() << " elements : " << time << " us" << "\n";
}

template <typename T>
void	PmergeMe<T>::process(char **av)
{
	struct timeval start, end;

	_parsing(av);

	gettimeofday(&start, NULL);
	_sort(_after);
	gettimeofday(&end, NULL);

	_printEnd(start, end);

	
	

	bool is_sorted = true;
	bool integrity_ok = true;

	// 1. Vérification du tri croissant
	if (_after.size() > 1)
	{
		typename T::iterator it = _after.begin();
		typename T::iterator next = it;
		++next;
		while (next != _after.end())
		{
			if (*it > *next)
			{
				is_sorted = false;
				break;
			}
			++it;
			++next;
		}
	}

	// 2. Vérification de l'intégrité (Taille + Contenu)
	if (_before.size() != _after.size())
	{
		integrity_ok = false;
	}
	else
	{
		// On effectue une copie locale de nos conteneurs pour les comparer sans altérer les variables de la classe
		T temp_before = _before;
		T temp_after = _after;

		// On trie temp_before avec l'algorithme standard pour référence de comparaison
		std::sort(temp_before.begin(), temp_before.end());
		// Normalement temp_after est déjà trié par ton PmergeMe, mais on s'assure qu'il soit dans le même état au cas où
		std::sort(temp_after.begin(), temp_after.end());

		// Si l'intégrité est respectée, le tableau trié par std::sort et le tien doivent être identiques à 100%
		if (temp_before != temp_after)
		{
			integrity_ok = false;
		}
	}

	// 3. Affichage du verdict
	if (is_sorted && integrity_ok)
	{
		std::cout << "\033[32m[OK] Vérification réussie : Le conteneur est parfaitement trié et toutes les valeurs sont intègres.\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[31m[KO] ERREUR DÉTECTÉE :\033[0m" << std::endl;
		if (!is_sorted)
			std::cout << "\033[31m     -> L'ordre croissant n'est pas respecté.\033[0m" << std::endl;
		if (!integrity_ok)
			std::cout << "\033[31m     -> Problème d'intégrité : des valeurs ont été perdues, modifiées ou dupliquées.\033[0m" << std::endl;
	}
}
