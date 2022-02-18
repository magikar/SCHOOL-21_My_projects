#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <string>
# include "../reimplemented/iterators_traits.hpp"

namespace ft {

template<typename T>
class random_access_iterator
{
public:
	typedef T								value_type;
	typedef std::ptrdiff_t					difference_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ft::random_access_iterator_tag	iterator_category;
protected:
	T	*point;
public:
	random_access_iterator();
	random_access_iterator(T *p);
	random_access_iterator(const random_access_iterator &copy);
	~random_access_iterator();

	random_access_iterator	operator+(int n);
	random_access_iterator	operator-(int n);
	int						operator-(const random_access_iterator &it);
	random_access_iterator	&operator+=(int n);
	random_access_iterator	&operator-=(int n);

	random_access_iterator	operator++(int);
	random_access_iterator	operator--(int);
	random_access_iterator	&operator++();
	random_access_iterator	&operator--();

	bool	operator!=(const random_access_iterator &it);
	bool	operator==(const random_access_iterator &it);
	bool	operator> (const random_access_iterator &it);
	bool	operator>=(const random_access_iterator &it);
	bool	operator< (const random_access_iterator &it);
	bool	operator<=(const random_access_iterator &it);

	T		&operator*();
	T		*operator->();
	T		&operator=(const random_access_iterator &copy);
};

template<typename T>
random_access_iterator<T>::random_access_iterator() : point()
{}

template<typename T>
random_access_iterator<T>::random_access_iterator(T *p) : point(p)
{}

template<typename T>
random_access_iterator<T>::random_access_iterator(const random_access_iterator &copy)
{	*this = copy;	}

template<typename T>
random_access_iterator<T>::~random_access_iterator()
{}

template<typename T>
random_access_iterator<T>		random_access_iterator<T>::operator+(int n)
{	
	random_access_iterator<T> tmp = *this;
	tmp.point += n;
	return (tmp);
}

template<typename T>
random_access_iterator<T>		random_access_iterator<T>::operator-(int n)
{	this->point -= n;	return (*this);	}

template<typename T>
int		random_access_iterator<T>::operator-(const random_access_iterator &it)
{	return (this->point - it.point);	}

template<typename T>
random_access_iterator<T>		&random_access_iterator<T>::operator+=(int n)
{
	this->point += n;
	return (*this);
}

template<typename T>
random_access_iterator<T>		&random_access_iterator<T>::operator-=(int n)
{
	this->point -= n;
	return (*this);
}

template<typename T>
random_access_iterator<T>		random_access_iterator<T>::operator++(int)
{
	random_access_iterator<T> it = *this;
	++this->point;
	return (it);
}

template<typename T>
random_access_iterator<T>		random_access_iterator<T>::operator--(int)
{
	random_access_iterator<T> it = *this;
	--this->point;
	return (it);
}

template<typename T>
random_access_iterator<T>		&random_access_iterator<T>::operator++()
{
	++this->point;
	return (*this);
}

template<typename T>
random_access_iterator<T>		&random_access_iterator<T>::operator--()
{
	--this->point;
	return (*this);
}

template<typename T>
bool	random_access_iterator<T>::operator!=(const random_access_iterator &it)
{	return (this->point != it.point);	}

template<typename T>
bool	random_access_iterator<T>::operator==(const random_access_iterator &it)
{	return (this->point == it.point);	}

template<typename T>
bool	random_access_iterator<T>::operator>(const random_access_iterator &it)
{	return (this->point > it.point);	}

template<typename T>
bool	random_access_iterator<T>::operator>=(const random_access_iterator &it)
{	return (this->point >= it.point);	}

template<typename T>
bool	random_access_iterator<T>::operator<(const random_access_iterator &it)
{	return (this->point < it.point);	}

template<typename T>
bool	random_access_iterator<T>::operator<=(const random_access_iterator &it)
{	return (this->point <= it.point);	}

template<typename T>
T		&random_access_iterator<T>::operator*()
{	return (*(this->point));	}

template<typename T>
T		*random_access_iterator<T>::operator->()
{	return (this->point);	}

template<typename T>
T		&random_access_iterator<T>::operator=(const random_access_iterator &copy)
{
	this->point = copy.point;
	return (*this->point);
}

template <typename T>
ft::random_access_iterator<T> operator+(const std::ptrdiff_t &to_add, random_access_iterator<T> &it)
{
    random_access_iterator<T> n;
    n = it + to_add;
    return(n);
}








template<typename T>
class reverse_iterator
{
public:
	typedef T								value_type;
	typedef std::ptrdiff_t					difference_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef ft::reverse_iterator<T>			iterator_category;
protected:
	T	*point;
public:
	reverse_iterator();
	reverse_iterator(T *p);
	reverse_iterator(const reverse_iterator &copy);
	~reverse_iterator();

	reverse_iterator	operator+(int n);
	reverse_iterator	operator-(int n);
	int					operator-(const reverse_iterator &it);
	reverse_iterator	&operator+=(int n);
	reverse_iterator	&operator-=(int n);

	reverse_iterator	operator++(int);
	reverse_iterator	operator--(int);
	reverse_iterator	&operator++();
	reverse_iterator	&operator--();

	bool	operator!=(const reverse_iterator &it);
	bool	operator==(const reverse_iterator &it);
	bool	operator> (const reverse_iterator &it);
	bool	operator>=(const reverse_iterator &it);
	bool	operator< (const reverse_iterator &it);
	bool	operator<=(const reverse_iterator &it);

	T		&operator*();
	T		*operator->();
	T		&operator=(const reverse_iterator &copy);
};

template<typename T>
reverse_iterator<T>::reverse_iterator() : point()
{}

template<typename T>
reverse_iterator<T>::reverse_iterator(T *p) : point(p)
{}

template<typename T>
reverse_iterator<T>::reverse_iterator(const reverse_iterator &copy)
{	*this = copy;	}

template<typename T>
reverse_iterator<T>::~reverse_iterator()
{}

template<typename T>
reverse_iterator<T>		reverse_iterator<T>::operator+(int n)
{	
	reverse_iterator<T> tmp = *this;
	tmp.point -= n;
	return (tmp);
}

template<typename T>
reverse_iterator<T>		reverse_iterator<T>::operator-(int n)
{	this->point += n;	return (*this);	}

template<typename T>
int		reverse_iterator<T>::operator-(const reverse_iterator &it)
{	return (this->point - it.point);	}

template<typename T>
reverse_iterator<T>		&reverse_iterator<T>::operator+=(int n)
{
	this->point -= n;
	return (*this);
}

template<typename T>
reverse_iterator<T>		&reverse_iterator<T>::operator-=(int n)
{
	this->point += n;
	return (*this);
}

template<typename T>
reverse_iterator<T>		reverse_iterator<T>::operator++(int)
{
	reverse_iterator<T> it = *this;
	--this->point;
	return (it);
}

template<typename T>
reverse_iterator<T>		reverse_iterator<T>::operator--(int)
{
	reverse_iterator<T> it = *this;
	++this->point;
	return (it);
}

template<typename T>
reverse_iterator<T>		&reverse_iterator<T>::operator++()
{
	--this->point;
	return (*this);
}

template<typename T>
reverse_iterator<T>		&reverse_iterator<T>::operator--()
{
	++this->point;
	return (*this);
}

template<typename T>
bool	reverse_iterator<T>::operator!=(const reverse_iterator &it)
{	return (this->point != it.point);	}

template<typename T>
bool	reverse_iterator<T>::operator==(const reverse_iterator &it)
{	return (this->point == it.point);	}

template<typename T>
bool	reverse_iterator<T>::operator>(const reverse_iterator &it)
{	return (this->point > it.point);	}

template<typename T>
bool	reverse_iterator<T>::operator>=(const reverse_iterator &it)
{	return (this->point >= it.point);	}

template<typename T>
bool	reverse_iterator<T>::operator<(const reverse_iterator &it)
{	return (this->point < it.point);	}

template<typename T>
bool	reverse_iterator<T>::operator<=(const reverse_iterator &it)
{	return (this->point <= it.point);	}

template<typename T>
T		&reverse_iterator<T>::operator*()
{	return (*(this->point));	}

template<typename T>
T		*reverse_iterator<T>::operator->()
{	return (this->point);	}

template<typename T>
T		&reverse_iterator<T>::operator=(const reverse_iterator &copy)
{
	this->point = copy.point;
	return (*this->point);
}

template <typename T>
ft::reverse_iterator<T> operator+(const std::ptrdiff_t &to_add, reverse_iterator<T> &it)
{
    reverse_iterator<T> n;
    n = it + to_add;
    return(n);
}


}

#endif