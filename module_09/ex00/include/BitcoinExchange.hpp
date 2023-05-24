#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange(std::string inputFileName);
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		bool	isValidValue(std::string value);
		bool	isValidDate(std::string date);
		void	parseData();
		void	parseInput();
		void	showAmount(std::string inputDate, float inputValue);

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		class exception
		{
			public:
				exception(const std::string & str);
				exception( exception const & src);
				~exception();

				exception &		operator=( exception const & rhs );
				const char* what();
			private:
				std::string	_msg;
		};
	private:
		std::string						_inputFileName;
		std::map<std::string, float>	_db;
};

#endif /* ************************************************* BITCOINEXCHANGE_H */