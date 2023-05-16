
#include "../include/BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

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
		atoi(date.c_str()) > 2023 || atoi(date.c_str() + 5) < 1
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
		throw exception("Error: too recent date -> " + inputDate);
	double	it_value = it->second;
	double	result = it_value * inputValue;
	std::cout << inputDate << " => " << inputValue << " = " << result << std::endl;
}


void	BitcoinExchange::parseInput()
{
	std::ifstream	inputFile;
	std::string		buffer;
	std::string		date;

	inputFile.open(_inputFileName.c_str());
	if (inputFile.is_open() == false)
		throw exception("Error: Failed to open input file");
	std::getline(inputFile, buffer);
	if (buffer.compare("date | value"))
		throw exception("Error: Invalid Input file format");
	for (size_t i = 0; std::getline(inputFile, buffer, '|'); i++)
	{
		if (buffer[buffer.size() - 1] == ' ')
			buffer = buffer.substr(0, buffer.size() - 1);
		if (isValidDate(buffer) == false)
			throw exception("Error: Invalid input date -> " + buffer);
		date = buffer;
		std::getline(inputFile, buffer, '\n');
		if (buffer[0] == ' ')
			buffer.erase(0, 1);
		float	value = strtof(buffer.c_str(), NULL);
		if (value < 0)
			throw exception("Error: not a positive number. -> " + buffer);
		if (value > 1000)
			throw exception("Error: too large a number. -> " + buffer);
		if (isValidValue(buffer) == false)
			throw exception("Error: Invalid Value -> " + buffer);
		if (errno == ERANGE)
			throw exception("Error: Invalid Value -> " + buffer);
		try
		{
			showAmount(date, value);
		}
		catch(exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */