#ifndef SPAN_HPP
# define SPAN_HPP

# include "iostream"
# include <vector>


// Créez une classe Span capable de stocker un maximum de N entiers.
// N est une variable de type `unsigned int` et sera le seul paramètre passé au constructeur.
// sont déjà stockés devra lever une exception. S'il n'y a aucun nombre stocké, ou un seul, aucune distance ne peut être trouvée.

class Span
{
	public:

		Span();
		Span(unsigned int N);
		~Span();
		Span(Span const& copy);
		Span	&operator=(Span const& old);

		void	addNumber(int nb); // ajouter un nb a la liste span // jusqu'a N elements exception leve si au dela
		int		shortestSpan(); //plus courte distance // exception si pas de nombre
		int		longestSpan(); //plus longue distance // exception si pas de nombre

	private:

		unsigned int _size;
		std::vector<int> vect;

};

#endif