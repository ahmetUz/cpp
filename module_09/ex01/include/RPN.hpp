#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		void		add(void);
		void		sub(void);
		void		mult(void);
		void		div(void);

		std::string	compute(std::string str);

	private:
		std::stack<int>	_stack;

};

#endif /* ************************************************************* RPN_H */