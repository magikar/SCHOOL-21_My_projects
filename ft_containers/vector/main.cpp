#ifndef LEAKS
# define LEAKS 0
#endif
#ifndef CHECK
# define CHECK 0
#endif
	# include <vector>
#if CHECK
	# include <iostream>
	# include <string>
	// # include <vector>
	namespace ft = std;
#else
	# include "vector.hpp"
#endif

#ifndef TEST
# define TEST 0
#endif


template<typename T>
void		print_vector(const ft::vector<T> &vec, const std::string &s = "")
{
		std::cout << "      " << s << "      " << std::endl;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
		std::cout << *iter << std::endl;
}
template<typename T>
void		std_print_vector(const std::vector<T> &vec, const std::string &s = "")
{std::cout << "      " << s << "      " << std::endl;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
		std::cout << *iter << std::endl;
}




#if TEST == 0

int		main()
{	try {	size_t		start_time = clock();	for(int i = 0; i < 000001; ++i) {


	ft::vector<std::string>	st, st1(st);

	st.push_back("111");
	st.push_back("222");
	st.push_back("333");
	st.push_back("444");
	st.push_back("555");
	st.push_back("666");
	st.push_back("777");
	st.push_back("888");


	st1.push_back("a");
	st1.push_back("b");
	st1.push_back("c");

		// ST  INSERT
	st.insert(st.end(), 4, "WWW");
		// ST1  INSERT
	std::cout << "INSERT  " << *st1.insert(st1.begin() + 1,  "qwer") << std::endl;
	st1.insert(st1.begin() + 1, st.begin() + 1, st.begin() + 5);

	std::cout << "ERASE  " << *st.erase(st.begin() + 1) << std::endl;
	st.pop_back();




	print_vector(st, "<ST>");

		std::cout << "	<<<ST REVERSE>>>" << std::endl;
	for (auto a = st.rbegin(); a != st.rend(); ++a)
		std::cout << *a << std::endl;
		
	print_vector(st1, "<ST1>");


	std::cout << "ST  size, capac, max_size:  " << st.size() << "  " << st.capacity() << "  " << st.max_size() << std::endl;
	std::cout << "ST1  size, capac, max_size:  " << st1.size() << "  " << st1.capacity() << "  " << st1.max_size() << std::endl;
		


										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	return (0);
}

#elif TEST == 1

int		main()
{	try {	size_t		start_time = clock();	for(int q = 0; q < 000001; ++q) {


	ft::vector<int>				vec1(5, 20), vec2(vec1.begin()+1, vec1.begin()+3);


	for (int j = 0; j < 10; ++j)
		vec1.push_back(j*2);
	

	vec2.assign(5, 55);
	vec2.assign(vec1.begin()+3, vec1.begin()+8);

	vec1.erase(vec1.end() - 4, vec1.end());


	print_vector(vec1, "VEC1");

	print_vector(vec2, "VEC2");

	std::cout << "VEC  size, capac:  " << vec1.size() << "  " << vec1.capacity() << std::endl;
	std::cout << "VEC2  size, capac:  " << vec2.size() << "  " << vec2.capacity() << std::endl;
		

	std::cout << "       <<<CLEAR>>>      " << std::endl;
	vec1.clear();
	vec2.clear();
	print_vector(vec1, "VEC1");
	print_vector(vec2, "VEC2");
	std::cout << "VEC  size, capac:  " << vec1.size() << "  " << vec1.capacity() << std::endl;
	std::cout << "VEC2  size, capac:  " << vec2.size() << "  " << vec2.capacity() << std::endl;



										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	return (0);
}

#elif TEST == 2

int		main()
{	try {	size_t		start_time = clock();	for(int i = 0; i < 000001; ++i) {

	ft::vector<std::string>	st(7, "B"), st1(st);

	st[6] = "B";     
	std::cout << "st == st1  " << (st == st1) << std::endl;
	std::cout << "st != st1  " << (st != st1) << std::endl;
	std::cout << "st <  st1  " << (st <  st1) << std::endl;
	std::cout << "st <= st1  " << (st <= st1) << std::endl;
	std::cout << "st >  st1  " << (st >  st1) << std::endl;
	std::cout << "st >= st1  " << (st >= st1) << std::endl;


	std::cout << std::endl;;
	ft::vector<int>	vec1(7, 35), vec2(vec1);

	vec1[6] = 35;
	std::cout << "vec1 == vec2  " << (vec1 == vec2) << std::endl;;
	std::cout << "vec1 != vec2  " << (vec1 != vec2) << std::endl;;
	std::cout << "vec1 <  vec2  " << (vec1 <  vec2) << std::endl;;
	std::cout << "vec1 <= vec2  " << (vec1 <= vec2) << std::endl;;
	std::cout << "vec1 >  vec2  " << (vec1 >  vec2) << std::endl;;
	std::cout << "vec1 >= vec2  " << (vec1 >= vec2) << std::endl;;




										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	return (0);
}


#elif TEST == 3

int		main()
{
try {	size_t		start_time = clock();	for(int z = 0; z < 000001; ++z) {

	ft::vector<int>		vec1;
	
	for (int ij = 0; ij != 5; ++ij)
		vec1.push_back(ij);
	

	print_vector(vec1, "VEC1");
	std::cout << "VEC1  size, capac:  " << vec1.size() << "  " << vec1.capacity() << std::endl;
	
	vec1.resize(3);
	// vec1.resize(15);
	// vec1.resize(15, 33);

	vec1.reserve(1);

	vec1.front() = 100;
	vec1.back() = -100;
	
	print_vector(vec1, "VEC1");
	std::cout << "VEC1  size, capac:  " << vec1.size() << "  " << vec1.capacity() << std::endl;
	std::cout << "EMPTY:  " << vec1.empty() << std::endl;
	vec1.clear();
	std::cout << "EMPTY:  " << vec1.empty() << std::endl;



										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	 catch(const char* exc) {	std::cout << exc << std::endl;	}
	return (0);
}


#elif TEST == 4

int		main()
{
try {	size_t		start_time = clock();	for(int z = 0; z < 000001; ++z) {

	ft::vector<int>		vec1, vec2;
	
	for (int ij = 0; ij != 3; ++ij)
		vec1.push_back(ij);

	for (int ij = 10; ij != 15; ++ij)
		vec2.push_back(ij*2);
	

	print_vector(vec1, "VEC1");
	std::cout << "VEC1  size, capac:  " << vec1.size() << "  " << vec1.capacity() << std::endl;
	print_vector(vec2, "VEC2");
	std::cout << "VEC1  size, capac:  " << vec2.size() << "  " << vec2.capacity() << std::endl;

// for(int zz=0; zz<1000000;++zz)
	vec1.swap(vec2);	

	print_vector(vec1, "VEC1");
	std::cout << "VEC1  size, capac:  " << vec1.size() << "  " << vec1.capacity() << std::endl;
	print_vector(vec2, "VEC2");
	std::cout << "VEC1  size, capac:  " << vec2.size() << "  " << vec2.capacity() << std::endl;



										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	 catch(const char* exc) {	std::cout << exc << std::endl;	}
	return (0);
}


#elif TEST == 5

int		main()
{
try {	size_t		start_time = clock();	for(int z = 0; z < 000001; ++z) {

	ft::vector<int>		v1;
	std::vector<int>		v2;
	// ft::vector<std::string>		v1, v2;

	for (int ij = 0; ij != 5; ++ij)
		v1.push_back(ij);
	// v2 = v1;
	for (int ij = 5; ij != 10; ++ij)
		v1.push_back(ij);
	
	ft::vector<int>::iterator it;
	// ft::vector<std::string>::iterator it;
	it = v1.begin();
    v2.push_back(*(++it));
    v2.push_back(*(--it));
    v2.push_back(*(it + 1));
    it += 1;
    v2.push_back(*(it - 1));
    it -= 1;
    v2.push_back(*it);

	print_vector(v1, "VEC1");
	std_print_vector(v2, "VEC2");



										// END
}
	size_t		end_time = clock();
	std::cout << "TIME WORK: " << end_time - start_time << " !" << std::endl;
	if (LEAKS) system("leaks vector");
	} catch(const std::exception &exc) {	std::cout << exc.what() << std::endl;	}
	 catch(const char* exc) {	std::cout << exc << std::endl;	}
	return (0);
}



#endif

