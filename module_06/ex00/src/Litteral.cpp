/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:21:20 by auzun             #+#    #+#             */
/*   Updated: 2023/02/19 21:45:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Litteral::Litteral() : _str("void"), _impossible(false), _type(NONE),
	_c(0), _i(0), _f(0), _d(0)
{
}

Litteral::Litteral(const char * str): _str(str), _impossible(false), _type(NONE),
	_c(0), _i(0), _f(0), _d(0)
{
}

Litteral::Litteral( const Litteral & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Litteral::~Litteral(){}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Litteral &				Litteral::operator=( Litteral const & rhs )
{
	if (this != &rhs)
	{
		this->_i = rhs._i;
		this->_d = rhs._d;
		this->_f = rhs._f;
		this->_c = rhs._c;
		this->_str = rhs._str;
		this->_impossible = rhs._impossible;
		this->_type = rhs._type;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool	Litteral::isLiteral( void ) const
{
	 if ( ( _impossible ) || ( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
		|| ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 )
		|| ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 )
		|| ( _str.compare( "-inff" ) == 0 ) || ( _str.compare( "-inff" ) == 0 )
		|| ( _str.compare( "+inff" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) )
			return (true);
	return (false);
}


bool	Litteral::isChar( void ) const
{
	return (_str.length() == 1 && std::isalpha( _str[0] ) && std::isprint( _str[0] ));
}

bool	Litteral::isInt( void ) const
{
	int	i = 0;

	if (_str[i] == '-' || _str[i] == '+')
		i++;
	while (std::isdigit(_str[i]))
		i++;
	return (static_cast<int>(_str.length()) == i);
}

bool	Litteral::isFloat( void ) const
{
	if (_str.find('.') == std::string::npos || _str[_str.length() - 1] != 'f'
		|| _str.find('.') == 0 || _str.find('.') == _str.length() - 2)
		return (false);

	int	i = 0;
	int	nbDot = 0;

	if (_str[i] == '-' || _str[i] == '+')
		i++;
	for (int j(i); j < (int)_str.length() - 1; j++)
	{
		if (_str[j] == '.')
			nbDot++;
		if ((!std::isdigit(_str[j]) && _str[j] != '.') || nbDot > 1)
			return (false);
	}
	return (true);
}

bool	Litteral::isDouble( void ) const
{
	if (_str.find('.') == std::string::npos || _str.find('.') == 0
		|| _str.find('.') == _str.length() - 1)
		return (false);

	int	i = 0;
	int	nbDot = 0;

	if (_str[i] == '-' || _str[i] == '+')
		i++;
	for (int j(i); j < (int)_str.length(); j++)
	{
		if (_str[j] == '.')
			nbDot++;
		if ((!std::isdigit(_str[j]) && _str[j] != '.') || nbDot > 1)
			return (false);
	}
	return (true);
}

void	Litteral::putChar( void ) const
{
	std::cout << "char : ";

	if (this->isLiteral())
		std::cout << "Impossible";
	else if ( ((_i >= 127 || _i <= 0) || !std::isprint(_i)))
		std::cout << "None displayable";
	else
		std::cout << "'" << _c << "'";
	std::cout << std::endl;
}

void	Litteral::putInt( void ) const
{
	std::cout << "int : ";

	if (this->isLiteral())
		std::cout << "Impossible";
	else
		std::cout << _i;
	std::cout << std::endl;
	
}
void	Litteral::putFloat( void ) const
{
	std::cout << "float : ";

	if (_str.compare("nan") == 0 || _str.compare("nanf") == 0)
		std::cout << "nanf";
	else if (_str.compare("+inf") == 0 || _str.compare("+inff") == 0)
		std::cout << "+inff";
	else if (_str.compare("-inf") == 0 || _str.compare("-inff") == 0)
		std::cout << "-inff";
	else if (_impossible)
		std::cout << "Impossible";
	else
	{
		std::cout << _f;
		if (_d - static_cast< int > (_d) == 0)
			std::cout << ".0f";	
		else
			std::cout << "f";
	}
	std::cout << std::endl;
}
void	Litteral::putDouble( void ) const
{
	std::cout << "double : ";

	if (_str.compare("nan") == 0 || _str.compare("nanf") == 0)
		std::cout << "nan";
	else if (_str.compare("+inf") == 0 || _str.compare("+inff") == 0)
		std::cout << "+inf";
	else if (_str.compare("-inf") == 0 || _str.compare("-inff") == 0)
		std::cout << "-inf";
	else if (_impossible)
		std::cout << "Impossible";
	else
	{
		std::cout << _d;
		if (_d - static_cast< int > (_d) == 0)
			std::cout << ".0";	
	}
	std::cout << std::endl;
}

void	Litteral::putall( void ) const
{
	if (_type == NONE)
		std::cout << "Unknown type" << std::endl;
	else
	{
		putChar();
		putInt();
		putFloat();
		putDouble();
	}
	
}

void	Litteral::convert(void)
{
	setType();

	if (_impossible)
		return ;
	switch (_type)
	{
		case CHAR:
			_c = _str[0];
			_i = static_cast< int >(_c);
			_f = static_cast< float >(_c);
			_d = static_cast< float >(_c);
			break;
		case INT:
			_i = std::atoi(_str.c_str());
			_c = static_cast< int >(_i);
			_f = static_cast< float >(_i);
			_d = static_cast< float >(_i);
			break;
		case FLOAT:
			_f = std::atof(_str.c_str());
			_i = static_cast< int >(_f);
			_c = static_cast< float >(_f);
			_d = static_cast< float >(_f);
			break;
		case DOUBLE:
			_d = std::atof(_str.c_str());
			_i = static_cast< int >(_d);
			_f = static_cast< float >(_d);
			_c = static_cast< float >(_d);
			break;
		
		default:
			break;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Litteral::setType(void)
{
	if (isChar())
		_type = CHAR;
	else if(isFloat())
		_type = FLOAT;
	else if(isDouble())
		_type = DOUBLE;
	else if(isInt())
		_type = INT;
	else if (!isLiteral())
	{
		_type = NONE;
		_impossible = true;
	}
	
}



/* ************************************************************************** */