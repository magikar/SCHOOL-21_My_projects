#ifndef LEAKS
# define LEAKS 0
#endif
#ifndef CHECK
# define CHECK 0
#endif
#if CHECK
	# include <iostream>
	# include <string>
	# include <set>
	namespace ft = std;
#else
	# include "set.hpp"
#endif
#include <utility>

template<typename T>
void		print_set(const ft::set<T> &Set, const std::string &str = "")
{
		std::cout << "      " << str << "      " << std::endl;
	for (auto iter = Set.begin(); iter != Set.end(); ++iter)
		std::cout << *iter << std::endl;
}

#ifndef TEST
# define TEST 0
#endif



#if TEST == 0

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

{	ft::set<int>		s1, s2(s1);

	s1.insert(10);
	s1.insert(20);
	s1.insert(0);
	s1.insert(5);
	s1.insert(15);
	s1.insert(19);
	s1.insert(7);
	s2 = s1;
	s1.insert(11);
	s1.insert(22);


	ft::set<int>		s3(++s1.begin(), ++(++(++(++s1.begin()))) );
	s3.insert(s3.begin(), -1);


	/////				EMPTY  / SIZE
	std::cout << "EMPTY " << s1.empty() << "\n";
	std::cout << "s1  size, max_size:  " << s1.size() << "  " << s1.max_size() << std::endl;

	print_set(s1, "<<<S1>>>");
	print_set(s2, "<<<S2>>>");
	print_set(s3, "<<<S3>>>");

	
	std::cout << "\n		<<<s1 reverse>>>		\n";
	for (auto it = s1.rbegin(); it != s1.rend(); ++it)
	std::cout << *it << std::endl;
}

{	ft::set<std::string>		s1, s2(s1);

	s1.insert("10");
	s1.insert("20");
	s1.insert("0");
	s1.insert("5");
	s1.insert("15");
	s1.insert("19");
	s1.insert("7");
	s2 = s1;
	s1.insert("11");
	s1.insert("22");

	ft::set<std::string>		s3(++s1.begin(), ++(++(++(++s1.begin()))) );
	s3.insert(s3.begin(), "-1");


	/////				EMPTY  / SIZE
	std::cout << "EMPTY " << s1.empty() << "\n";
	std::cout << "s1  size, max_size:  " << s1.size() << "  " << s1.max_size() << std::endl;

	print_set(s1, "<<<S1>>>");
	print_set(s2, "<<<S2>>>");
	print_set(s3, "<<<S3>>>");
	
	std::cout << "\n		<<<s1 reverse>>>		\n";
	for (auto it = s1.rbegin(); it != s1.rend(); ++it)
	std::cout << "\"" << *it << "\"" << std::endl;
}

}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}

#elif TEST == 1

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

{	ft::set<int>		s1, s2(s1);

	s1.insert(0);
	s1.insert(5);
	s1.insert(7);
	s1.insert(10);
	s1.insert(11);
	s1.insert(15);
	s1.insert(19);
	s1.insert(20);
	s1.insert(22);

	s2 = s1;
	s1.erase(19);
	s1.erase(s1.begin());
	// s2.erase(s2.begin(), s2.end());
	s2.erase(++s2.begin(), --(--(--s2.end())));


	print_set(s1, "<<<S1>>>");
	print_set(s2, "<<<S2>>>");

}

{	ft::set<std::string>		s1, s2(s1);

	s1.insert("10");
	s1.insert("20");
	s1.insert("0");
	s1.insert("5");
	s1.insert("15");
	s1.insert("19");
	s1.insert("7");
	s1.insert("11");
	s1.insert("22");

	s2 = s1;
	s1.erase("19");
	s1.erase(s1.begin());
	s2.erase(++s2.begin(), --(--(--s2.end())));

	print_set(s1, "<<<S1>>>");
	print_set(s2, "<<<S2>>>");

}

}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}




#elif TEST == 2

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

	ft::set<std::string>		s1, s2(s1);

	s1.insert("10");
	s1.insert("20");
	s1.insert("0");
	s1.insert("5");
	s1.insert("15");
	s1.insert("19");
	s1.insert("7");
	s2 = s1;
	s1.insert("11");
	s1.insert("22");
	

	std::cout << "\n		<<<   s1.FIND()   >>>		\n";
	auto it1 = s1.find("10");
	std::cout << "Find-> " << *it1 << std::endl;
	for (auto it = s1.find("10"); it != s1.find("15"); ++it)
	std::cout << *it << std::endl;
	
	std::cout << "\n		   s1.COUNT()   		\n";
	std::cout << "Count " << s1.count("10") << std::endl;

{	std::cout << "\n		   s1.LOWER / UPPER()   		\n";
	std::string x = "6";
	auto	low = s1.lower_bound(x), upp = s1.upper_bound(x);
	std::cout << "LOWER " << *low << std::endl;
	std::cout << "UPPER " << *upp<< std::endl;

	std::cout << "\n		   s1.EQ()   		\n";
	auto	equal = s1.equal_range(x);
	// ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> equal = s1.equal_range(x);
	std::cout << "EQ.LOWER " << *equal.first  << std::endl;
	std::cout << "EQ.UPPER " << *equal.second << std::endl;
}

	
	
}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}


#elif TEST == 3

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

	{	ft::set<int>		s1, s2(s1);

	s1.insert(0);
	s1.insert(5);
	s1.insert(7);
	s2 = s1;
	s1.insert(10);
	s1.insert(11);
	s1.insert(15);
	s1.insert(19);
	s1.insert(20);
	s1.insert(22);

	s1.swap(s2);

	print_set(s1, "<<<S1>>>");
	print_set(s2, "<<<S2>>>");

	s1.clear();
	print_set(s1, "<<<S1.CLEAR>>>");


}

{	ft::set<std::string>		s1, s2(s1);

	s1.insert("10");
	s1.insert("20");
	s1.insert("0");
	s2 = s1;
	s1.insert("5");
	s1.insert("15");
	s1.insert("19");
	s1.insert("7");
	s1.insert("11");
	s1.insert("22");

	s1.swap(s2);


	print_set(s1, "<<<S1>>>");
	print_set(s2, "<<<S2>>>");

	s1.clear();
	print_set(s1, "<<<S1.CLEAR>>>");

}
	
	
}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}


#elif TEST == 4


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {

	{	ft::set<int>		s1, s2(s1);

	s1.insert(0);
	s1.insert(5);
	s1.insert(7);
	s1.insert(10);
	s1.insert(11);
	s1.insert(15);
	s1.insert(19);
	s1.insert(20);
	s1.insert(22);
	s2 = s1;

	
	std::cout << "   <<<  SET INT  >>>   " << std::endl;
	std::cout << "s1 == s2  " << (s1 == s2) << std::endl;
	std::cout << "s1 != s2  " << (s1 != s2) << std::endl;
	std::cout << "s1 <  s2  " << (s1 <  s2) << std::endl;
	std::cout << "s1 <= s2  " << (s1 <= s2) << std::endl;
	std::cout << "s1 >  s2  " << (s1 >  s2) << std::endl;
	std::cout << "s1 >= s2  " << (s1 >= s2) << std::endl;


}

{	ft::set<std::string>		s1, s2(s1);

	s1.insert("10");
	s1.insert("20");
	s1.insert("0");
	s1.insert("5");
	s1.insert("15");
	s1.insert("19");
	s1.insert("7");
	s1.insert("11");
	s1.insert("22");
	s2 = s1;


	std::cout << "   <<<  SET STRING  >>>   " << std::endl;
	std::cout << "s1 == s2  " << (s1 == s2) << std::endl;
	std::cout << "s1 != s2  " << (s1 != s2) << std::endl;
	std::cout << "s1 <  s2  " << (s1 <  s2) << std::endl;
	std::cout << "s1 <= s2  " << (s1 <= s2) << std::endl;
	std::cout << "s1 >  s2  " << (s1 >  s2) << std::endl;
	std::cout << "s1 >= s2  " << (s1 >= s2) << std::endl;
}



}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}


#elif TEST == 5//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {


	ft::set<int> myset;
  int * p;
  unsigned int i;

  // allocate an array of 5 elements using myset's allocator:
  p=myset.get_allocator().allocate(5);

  // assign some values to array
  for (i=0; i<5; i++) p[i]=(i+1)*10;

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  myset.get_allocator().deallocate(p,5);



}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}


#elif TEST == 6//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {



	ft::set<int> myset;
  int highest;

  ft::set<int>::key_compare mycomp = myset.key_comp();

  for (int i=0; i<=5; i++) myset.insert(i);

  std::cout << "myset contains:";

  highest=*myset.rbegin();
  ft::set<int>::iterator it=myset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) );

  std::cout << '\n';



}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}

#elif TEST == 7//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {




	ft::set<int> myset;

  ft::set<int>::value_compare mycomp = myset.value_comp();

  for (int i=0; i<=5; i++) myset.insert(i);

  std::cout << "myset contains:";

  int highest=*myset.rbegin();
  ft::set<int>::iterator it=myset.begin();
  do {
    std::cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) );

  std::cout << '\n';





}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks set");
	return (0);
}

#endif



