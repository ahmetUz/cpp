#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm(), _target("default")
{
	std::cout << "[RobotomyRequestForm] default constructor !" << std::endl;
	std::cout << *this << "appeared !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ): AForm("RobotomyRequestForm", 75, 45), _target(target)
{
	std::cout << "[RobotomyRequestForm] constructor !" << std::endl;
	std::cout << *this << "appeared !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): AForm(src)
{
	*this = src;
	std::cout << "[RobotomyRequestForm] copy constructor !" << std::endl;
	std::cout << *this << "appeared !" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] destructor !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	_isSigned = rhs._isSigned;
	_target = rhs._target;
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	beExecuted(executor);
	std::cout << "** BOUM BOUM OULALA Y A DU BRUIT **" << std::endl;
	if ((std::rand() % 2))
		std::cout << this->_target << " get robotomised !" << std::endl;
	else
		std::cout << this->_target << " robotomisation failed !" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */