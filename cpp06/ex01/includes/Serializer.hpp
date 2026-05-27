#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "iostream"
# include "stdint.h"

struct Data
{
	int			nb;
	std::string	name;
};

class Serializer
{
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:

		Serializer();
		~Serializer();
		Serializer(Serializer const& other);
		Serializer& operator=(Serializer const& other);

};

#endif