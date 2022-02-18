#ifndef LEAKS
# define LEAKS 0
#endif
#ifndef CHECK
# define CHECK 0
#endif
#if CHECK
	# include <iostream>
	# include <string>
	# include <stack>
	namespace ft = std;
#else
	# include "stack.hpp"
#endif

#ifndef TEST
# define TEST 0
#endif




#if TEST == 0

int		main()
{	try {	size_t		start_time = clock();	for(int i = 0; i < 0000001; ++i) {


{	ft::stack<int> st, st1(st);
	
	for (int j = 0; j < 10; ++j)
		st.push(j + j*10);
	std::cout << "SIZE " << st.size() << std::endl;
	st1 = st;
	std::cout << "st == st1  " << (st == st1) << std::endl;
	std::cout << "st != st1  " << (st != st1) << std::endl;
	std::cout << "st < st1  " << (st < st1) << std::endl;
	std::cout << "st <= st1  " << (st <= st1) << std::endl;
	std::cout << "st > st1  " << (st > st1) << std::endl;
	std::cout << "st >= st1  " << (st >= st1) << std::endl;
	while (!st.empty())
	{
		std::cout << st.top() << std::endl;
		st.pop();
	}
	std::cout << "\n\n" << std::endl;
}

{	ft::stack<std::string>	st, st1(st);
	std::string			str = "a";
	
	for (int j = 0; j < 10; ++j) {
		str = 'A' + j;
		st.push(str);
	}
	std::cout << "SIZE " << st.size() << std::endl;
	st1 = st;
	std::cout << "st == st1  " << (st == st1) << std::endl;
	std::cout << "st != st1  " << (st != st1) << std::endl;
	std::cout << "st < st1  " << (st < st1) << std::endl;
	std::cout << "st <= st1  " << (st <= st1) << std::endl;
	std::cout << "st > st1  " << (st > st1) << std::endl;
	std::cout << "st >= st1  " << (st >= st1) << std::endl;
	
	while (!st.empty())
	{
		std::cout << st.top() << std::endl;
		st.pop();
	}

}
	


	


										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << (end_time - start_time) / 1000 << " " << (end_time - start_time) % 1000 << " !" << std::endl;
	if (LEAKS) system("leaks stack");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	return (0);
}

#elif TEST == 1

int		main(int argc, char **argv, char const **en)
{	try {	size_t		start_time = clock();	for(int q = 0; q < 000001; ++q) {


		



										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	return (0);
}

#elif TEST == 2
#elif TEST == 3

#endif

