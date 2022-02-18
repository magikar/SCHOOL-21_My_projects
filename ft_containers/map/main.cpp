#ifndef LEAKS
# define LEAKS 0
#endif
#ifndef CHECK
# define CHECK 0
#endif
	// # include <vector>
	// # include <map>
#if CHECK
	# include <iostream>
	# include <string>
	# include <map>
	namespace ft = std;
#else
	# include "map.hpp"
#endif
#include <utility>

template<typename T,typename K>
void		print_map(const ft::map<T, K> &M, const std::string &s = "")
{
		std::cout << "      " << s << "      " << std::endl;
	for (auto iter = M.begin(); iter != M.end(); ++iter)
		std::cout << iter->first << "   " << iter->second << std::endl;
}



#ifndef TEST
# define TEST 0
#endif



#if TEST == 0

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

	ft::map<int, std::string>		m1, m2(m1);

	m1[10] = "as";
	m1[11] = "xz";
	m2 = m1;
	m1[15] = "eqw";
	m1[6] = "qw";
	m1[8] = "8";
	m1[0] = "000";
	m1[13] = "13";
	////				M1.AT()
	m1.at(13) = "99";
	std::cout << "\n\nM1.at() " << m1.at(13) << std::endl;


	/////				EMPTY  / SIZE
	std::cout << "EMPTY " << m1.empty() << "\n";
	std::cout << "M1  size, max_size:  " << m1.size() << "  " << m1.max_size() << std::endl;

	print_map(m1, "<<<M1>>>");

	std::cout << "\n		<<<M1 reverse>>>		\n";
	for (auto it = m1.rbegin(); it != m1.rend(); ++it)
	std::cout << it->first << "   " << it->second << std::endl;
	
	print_map(m2, "<<<M2>>>");

	

}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}

#elif TEST == 1

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

	ft::map<int, std::string>		m1, m2(m1);

	m1[10] = "as";
	m1[11] = "xz";
	m2 = m1;
	m1[15] = "eqw";
	m1[6] = "qw";
	m1[8] = "8";
	m1[13] = "13";
	

	std::cout << "\n		<<<   M1.FIND()   >>>		\n";
	for (auto it = m1.find(10); it != m1.find(15); ++it)
	std::cout << it->first << "   " << it->second << std::endl;
	
	std::cout << "\n		   M1.COUNT()   		\n";
	std::cout << "Count " << m1.count(100) << std::endl;

{	std::cout << "\n		   M1.LOWER / UPPER()   		\n";
	int x = 6;
	auto	low = m1.lower_bound(x), upp = m1.upper_bound(x);
	std::cout << "LOWER " << low->first << "  " << low->second << std::endl;
	std::cout << "UPPER " << upp->first << "  " << upp->second << std::endl;

	std::cout << "\n		   M1.EQ()   		\n";
	auto	equal = m1.equal_range(x);
	// ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> equal = m1.equal_range(x);
	std::cout << "EQ.LOWER " << equal.first->first  << "  " << equal.first->second  << std::endl;
	std::cout << "EQ.UPPER " << equal.second->first << "  " << equal.second->second << std::endl;
}

	
	
}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}


#elif TEST == 2

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  00001; ++qqq) {

	ft::map<int, std::string>		m1, m2(m1);

	m1[10] = "as";
	m1[11] = "xz";
	m1[15] = "eqw";
	m1[6] = "qw";
	m1[8] = "8";
	m1[13] = "13";
	

	std::cout << "\n		<<<   M1.INSERT()   >>>		\n";
	auto	a1 = m1.insert(ft::make_pair(22, "QWER"));
	std::cout << a1.first->first << "  " << a1.first->second << "  bool-> " << a1.second << std::endl;

	auto	a2 = m1.insert(m1.begin(), ft::make_pair(33, "~~~~"));
	std::cout << a2->first << "  " << a2->second << std::endl;

	m2.insert(m1.begin(), --(--m1.end()));


	std::cout << "ERASE  " << m1.erase(11) << std::endl;

	m2.erase(m2.begin());
	// m2.erase(m2.begin(), m2.end());
	
	
	m1.swap(m2);

	print_map(m1, "<<<M1>>>");
	print_map(m2, "<<<M2>>>");


	m1.clear(); m2.clear();
	print_map(m1, "<<<CLEAR M1>>>");
	print_map(m2, "<<<CLEAR M2>>>");
	
	
}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}


#elif TEST == 3//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {

	ft::map<int, std::string>		m1, m2(m1);

	m1[10] = "as";
	m1[11] = "xz";
	m1[1] = "1";
	m2[1] = "1";
	m1[15] = "eqw";
	m1[6] = "qw";
	m1[8] = "8";
	m1[13] = "13";
	m2 = m1;

	// for (int z=0; z != 10000000; ++z)
	// 	m1.swap(m2);

	std::cout << "m1 == m2  " << (m1 == m2) << std::endl;
	std::cout << "m1 != m2  " << (m1 != m2) << std::endl;
	std::cout << "m1 <  m2  " << (m1 <  m2) << std::endl;
	std::cout << "m1 <= m2  " << (m1 <= m2) << std::endl;
	std::cout << "m1 >  m2  " << (m1 >  m2) << std::endl;
	std::cout << "m1 >= m2  " << (m1 >= m2) << std::endl;



	print_map(m1, "<<<M1>>>");
	print_map(m2, "<<<M2>>>");

}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}


#elif TEST == 4//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {


	int psize;
  ft::map<char,int> mymap;
  ft::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);



}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}


#elif TEST == 5//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {



	ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';



}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}

#elif TEST == 6//	


int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {




	ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );





}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}


#elif TEST == 7//	

int		main()
{	size_t	start_time = clock();
try {
for (int qqq = 0; qqq <  000001; ++qqq) {

	





}
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	size_t	end_time = clock();
	std::cout << "\n\e[33mTIME WORK:\e[0m " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks map");
	return (0);
}

#endif

