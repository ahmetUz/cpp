#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer( const Serializer & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	(void)rhs;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	std::cout << "serialize --> convert data to uintptr_t" << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	std::cout << "deserialize --> convert  uintptr_t to data" << std::endl;
	return (reinterpret_cast<Data *>(raw));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */