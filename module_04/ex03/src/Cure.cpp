#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure has been created" << std::endl;
}

Cure::Cure( const Cure & src ) : AMateria("cure")
{
	*this = src;
	std::cout << "Cure materia has been copied" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "Cure has been destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this != &rhs )
		this->_type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */