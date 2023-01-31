#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(): _type("")
{
	std::cout << "AMateria --> (empty) material has been created" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria --> "<< this->_type << " has been created" << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << "AMateria --> "<< this->_type << " has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void				AMateria::use(ICharacter& target)
{
	std::cout << "AMateria --> "<< this->_type << " used by " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */