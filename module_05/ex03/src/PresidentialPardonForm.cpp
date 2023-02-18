#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("default")
{
	std::cout << "[PresidentialPardonForm] default constructor !" << std::endl;
	std::cout << *this << "appeared !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "[PresidentialPardonForm] constructor !" << std::endl;
	std::cout << *this << "appeared !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src)
{
	*this = src;
	std::cout << "[PresidentialPardonForm] copy constructor !" << std::endl;
	std::cout << *this << "appeared !" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] destructor !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	_isSigned = rhs._isSigned;
	_target = rhs._target;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	beExecuted(executor);
	std::cout << this->_target << " get forgiven by Zaphod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */