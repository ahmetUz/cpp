#include "../include/PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

const char * PmergeMe::exception::what()
{
	_msg += '\n';
	return _msg.c_str();
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}

PmergeMe::PmergeMe(char **args)
{
	int	atoied;

	for (size_t i = 0; args[i]; i++)
	{
		parseArg(args[i]);
		atoied = atoi(args[i]);
		_vector.push_back(atoied);
		_deque.push_back(atoied);
	}
	std::cout << "Before: ";
	displayContent(_vector);
	double time_vec = startProcess(_vector);
	double time_deq = startProcess(_deque);
	std::cout << "After: ";
	displayContent(_vector);
	std::cout << "Time to process a range of "<< _vector.size() << " elements with std::vector " << time_vec << " seconds" << std::endl;
	std::cout << "Time to process a range of "<< _deque.size() << " elements with std::deque " << time_deq << " seconds" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	_vector = rhs._vector;
	_deque = rhs._deque;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

template	<typename T> double	PmergeMe::startProcess(T& t)
{
	clock_t	start = clock();
	mergeInsertSort(t);
	clock_t	end = clock();
	double	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	return	time;
}

template	<typename T> void	PmergeMe::displayContent(T& t)
{
	for (typename T::iterator it = t.begin(); it < t.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != t.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::parseArg(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '0' && atoi(str.c_str()) == 0)
			throw exception("Error: invalid charracter");
		else if (atoi(str.c_str()) < 0)
			throw (exception("Error: negative int"));
	}
}

void	PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
	int	n1 = mid - left + 1;
	int	n2 = right - mid;
	
	std::vector<int>	leftArr(n1);
	std::vector<int>	rightArr(n2);

	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int j = 0; j < n2; ++j)
		rightArr[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			++i;
		}
		else
		{
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}
	while (i < n1)
	{
		arr[k] = leftArr[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}

void	PmergeMe::insertionSort(std::vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int key = arr[i];
		int j = i - 1;


		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}
}

void	PmergeMe::mergeInsertSort(std::vector<int>& arr, int left, int right, int threshold)
{
	if (left < right)
	{
		if (right - left <= threshold)
		{
			insertionSort(arr, left, right);
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsertSort(arr, left, mid, threshold);
			mergeInsertSort(arr, mid + 1, right, threshold);
			merge(arr, left, mid, right);
		}
	}
}

void	PmergeMe::mergeInsertSort(std::vector<int>& arr)
{
	int threshold = MIN_SPLIT_SIZE;
	mergeInsertSort(arr, 0, arr.size() - 1, threshold);
}

void	PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right) {
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	std::deque<int>	leftDeque;
	std::deque<int>	rightDeque;

	for (int i = 0; i < n1; ++i)
		leftDeque.push_back(arr[left + i]);
	for (int j = 0; j < n2; ++j)
		rightDeque.push_back(arr[mid + 1 + j]);

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (leftDeque[i] <= rightDeque[j])
		{
			arr[k] = leftDeque[i];
			++i;
		}
		else
		{
			arr[k] = rightDeque[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		arr[k] = leftDeque[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		arr[k] = rightDeque[j];
		++j;
		++k;
	}
}

void	PmergeMe::insertionSort(std::deque<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int	key = arr[i];
		int	j = i - 1;

		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}

		arr[j + 1] = key;
	}
}

void	PmergeMe::mergeInsertSort(std::deque<int>& arr, int left, int right, int threshold)
{
	if (left < right)
	{
		if (right - left <= threshold)
		{
			insertionSort(arr, left, right);
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsertSort(arr, left, mid, threshold);
			mergeInsertSort(arr, mid + 1, right, threshold);
			merge(arr, left, mid, right);
		}
	}
}

void	PmergeMe::mergeInsertSort(std::deque<int>& arr)
{
	int threshold = MIN_SPLIT_SIZE;
	mergeInsertSort(arr, 0, arr.size() - 1, threshold);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */