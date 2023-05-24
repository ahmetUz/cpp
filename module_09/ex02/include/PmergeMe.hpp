#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <climits>
# include <cstdlib>
# include <sys/time.h>
# include <algorithm>

# define MIN_SPLIT_SIZE 100

class PmergeMe
{

	public:
		PmergeMe();
		PmergeMe(char **args);
		PmergeMe( PmergeMe const & src );
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& rhs);
		void	parseArg(std::string str);

		template	<typename T> double	startProcess(T& t);
		template	<typename T> void	displayContent(T& t);

		void	mergeInsertSort(std::deque<int>& arr);
		void	mergeInsertSort(std::deque<int>& arr, int left, int right, int threshold);
		void	insertionSort(std::deque<int>& arr, int left, int right);
		void	merge(std::deque<int>& arr, int left, int mid, int right);

		void	mergeInsertSort(std::vector<int>& arr);
		void	mergeInsertSort(std::vector<int>& arr, int left, int right, int threshold);
		void	insertionSort(std::vector<int>& arr, int left, int right);
		void	merge(std::vector<int>& arr, int left, int mid, int right);

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
		std::vector<int>	_vector;
		std::deque<int>		_deque;

};

#endif /* ******************************************************** PMERGEME_H */