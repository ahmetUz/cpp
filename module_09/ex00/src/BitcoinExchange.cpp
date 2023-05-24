
#include "../include/BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::exception::exception(const std::string & str): _msg(str) {}

BitcoinExchange::exception::exception(BitcoinExchange::exception const & src): _msg(src._msg) {}

BitcoinExchange::exception::~exception(){}

BitcoinExchange::exception &		BitcoinExchange::exception::operator=( BitcoinExchange::exception const & rhs )
{
	this->_msg = rhs._msg;
	return *this;
}

const char * BitcoinExchange::exception::what()
{
	_msg += '\n';
	return _msg.c_str();
}

BitcoinExchange::BitcoinExchange(std::string inputFileName) : _inputFileName(inputFileName)
{
	parseData();
	parseInput();
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	this->_inputFileName = rhs._inputFileName;
	this->_db = rhs._db;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


bool	BitcoinExchange::isValidValue(std::string value)
{
	bool	firstDotIsFinded = false;

	if (value.size() == 0)
		return false;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
		{
			if (value[i] == '.' && firstDotIsFinded == false)
				firstDotIsFinded = true;
			else
				return false;
		}
	}
	return true;
}

bool	BitcoinExchange::isValidDate(std::string date)
{
	if (date.size() != 10 || atoi(date.c_str()) < 2009 ||
		atoi(date.c_str()) > 2022 || atoi(date.c_str() + 5) < 1
		|| atoi(date.c_str() + 5) > 12 || atoi(date.c_str() + 8) < 1
		||	atoi(date.c_str() + 8) > 31)
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]))
		{
			if (date[i] != '-' && (i != 4 && i != 7))
				return false;
		}
	}
	return true;
}

void	BitcoinExchange::parseData()
{
	std::ifstream	dataFile;
	std::string		buffer;
	std::string		date;

	dataFile.open("./data.csv");
	if (!dataFile.is_open())
		throw exception("Error: Failed to open data.csv");
	std::getline(dataFile, buffer);
	if (buffer.compare("date,exchange_rate"))
		throw exception("Error: Invalid file format");
	for (size_t i = 0; std::getline(dataFile, buffer, ','); i++)
	{
		if (isValidDate(buffer) == false)
			throw exception("Error: Invalid date");
		date = buffer;
		std::getline(dataFile, buffer, '\n');
		if (_db.find(date) != _db.end())
			throw exception("Date -> " + date + " already exist");
		if (isValidValue(buffer) == false)
			throw exception("Error: Invalid Value");
		float	value = strtof(buffer.c_str(), NULL);
		if (value < 0 || errno == ERANGE)
			throw exception("Error: Invalid Value");
		_db.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::showAmount(std::string inputDate, float inputValue)
{
	std::map<std::string, float>::iterator it = _db.find(inputDate);

	if (it == _db.end())
	{
		it = _db.lower_bound(inputDate);
		it = it == _db.begin() || it == _db.end() ? it : --it;
	}
	if (it == _db.end())
	{
		std::cerr << "Error: too recent date -> " + inputDate << std::endl;
		return ;
	}
	double	it_value = it->second;
	double	result = it_value * inputValue;
	std::cout << inputDate << " => " << inputValue << " = " << result << std::endl;
}


void	BitcoinExchange::parseInput()
{
	std::ifstream	inputFile;
	std::string		buffer;
	std::string		date;
	bool			isValid = true;

	inputFile.open(_inputFileName.c_str());
	if (inputFile.is_open() == false)
		throw exception("Error: Failed to open input file");
	std::getline(inputFile, buffer);
	if (buffer.compare("date | value"))
		throw exception("Error: Invalid Input file format");
	for (size_t i = 0; std::getline(inputFile, buffer); i++)
	{
		std::string	tmp = buffer;
		if (tmp.find(" |") == std::string::npos)
		{
			std::cerr << "Error: Invalid line format "<< std::endl;
			isValid = false;
		}
		else
			tmp = tmp.substr(0, tmp.find(" |"));
		if (isValid && isValidDate(tmp) == false)
		{
			std::cerr << "Error: Invalid input date "<< std::endl;
			isValid = false;
		}
		date = tmp;
		tmp = buffer;
		if (isValid && tmp.find("\n") == std::string::npos
			&& tmp.find("| ") == std::string::npos)
		{
			std::cerr << "Error: Invalid line format "<< std::endl;
			isValid = false;
		}
		else
			tmp = tmp.substr(tmp.find("| ") + 2, tmp.find("\n") - (tmp.find("| ")));
		float	value = strtof(tmp.c_str(), NULL);
		if (isValid && value < 0)
		{
			std::cerr << "Error: not a positive number."<< std::endl;
			isValid = false;
		}
		if (isValid && value > 1000)
		{
			std::cerr << "Error: too large a number. " << std::endl;
			isValid = false;
		}
		if (isValid && isValidValue(tmp) == false)
		{
			std::cerr << "Error: Invalid Value" << std::endl;
			isValid = false;
		}
		if (isValid && errno == ERANGE)
		{
			std::cerr << "Error: Invalid Value" << std::endl;
			isValid = false;
		}
		if (isValid)
			showAmount(date, value);
		isValid = true;
	}
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */