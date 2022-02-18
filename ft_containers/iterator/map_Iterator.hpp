#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>

namespace ft {

template<typename T>
struct Node;

template<typename T>
class map_iterator
{
public:
	typedef T									value_type;
	typedef ft::Node<value_type>*				Pointer;
	typedef ft::Node<value_type>&				reference;
	typedef std::ptrdiff_t						difference_type;
	typedef std::bidirectional_iterator_tag		iterator_category;

protected:
	Pointer		point;
public:
	map_iterator();
	map_iterator(const Pointer p);
	map_iterator(const map_iterator &copy);
	~map_iterator();

	map_iterator	operator++(int);
	map_iterator	operator--(int);
	map_iterator	&operator++();
	map_iterator	&operator--();

	bool	operator!=(const map_iterator &it);
	bool	operator==(const map_iterator &it);
	bool	operator< (const map_iterator &it);
	bool	operator<=(const map_iterator &it);
	bool	operator> (const map_iterator &it);
	bool	operator>=(const map_iterator &it);

	T		&operator*();
	T		*operator->();
	map_iterator		&operator=(const map_iterator &copy);
};

template<typename T>
map_iterator<T>::map_iterator() : point(NULL)
{}

template<typename T>
map_iterator<T>::map_iterator(const map_iterator<T>::Pointer p)// : point(p)
{	this->point = p;	}

template<typename T>
map_iterator<T>::map_iterator(const map_iterator &copy)
{	*this = copy;	}

template<typename T>
map_iterator<T>::~map_iterator()
{}

template<typename T>
map_iterator<T>		map_iterator<T>::operator++(int)
{
	map_iterator<T> it = *this;
	this->operator++();
	return (it);
}

template<typename T>
map_iterator<T>		map_iterator<T>::operator--(int)
{
	map_iterator<T> it = *this;
	this->operator--();
	return (it);
}

template<typename T>
map_iterator<T>		&map_iterator<T>::operator++()
{
	if (!this->point)
		return (*this);
	else if (!this->point->_right)
	{
		while (this->point->_root && this->point == this->point->_root->_right)
			this->point = this->point->_root;
		this->point = this->point->_root;
	}
	else
	{
		this->point = this->point->_right;
		while (this->point && this->point->_left)
			this->point = this->point->_left;
	}
	return (*this);
}

template<typename T>
map_iterator<T>		&map_iterator<T>::operator--()
{
	if (!this->point)
		return (*this);
	else if (!this->point->_left)
	{
		while (this->point->_root && this->point == this->point->_root->_left)
			this->point = this->point->_root;
		this->point = this->point->_root;
	}
	else
	{
		this->point = this->point->_left;
		while (this->point && this->point->_right)
			this->point = this->point->_right;
	}
	return (*this);
}

template<typename T>
bool	map_iterator<T>::operator!=(const map_iterator &it)
{	return (this->point != it.point);	}

template<typename T>
bool	map_iterator<T>::operator==(const map_iterator &it)
{	return (this->point == it.point);	}

template<typename T>
bool	map_iterator<T>::operator< (const map_iterator &it)
{	return (this->point < it.point);	}

template<typename T>
bool	map_iterator<T>::operator<=(const map_iterator &it)
{	return (this->point <= it.point);	}

template<typename T>
bool	map_iterator<T>::operator> (const map_iterator &it)
{	return (this->point > it.point);	}

template<typename T>
bool	map_iterator<T>::operator>=(const map_iterator &it)
{	return (this->point >= it.point);	}

template<typename T>
T		&map_iterator<T>::operator*()
{	return (this->point->_data);	}

template<typename T>
T		*map_iterator<T>::operator->()
{	return (&this->point->_data);	}

template<typename T>
map_iterator<T>		&map_iterator<T>::operator=(const map_iterator<T> &copy)
{
	this->point = copy.point;
	return (*this);
}








template<typename T>
class map_iterator_reverse
{
public:
	typedef T						value_type;
	typedef ft::Node<value_type>*	Pointer;

protected:
	Pointer		point;
public:
	map_iterator_reverse();
	map_iterator_reverse(const Pointer p);
	map_iterator_reverse(const map_iterator_reverse &copy);
	~map_iterator_reverse();

	map_iterator_reverse	operator++(int);
	map_iterator_reverse	operator--(int);
	map_iterator_reverse	&operator++();
	map_iterator_reverse	&operator--();

	bool	operator!=(const map_iterator_reverse &it);
	bool	operator==(const map_iterator_reverse &it);

	T		&operator*();
	T		*operator->();
	map_iterator_reverse		&operator=(const map_iterator_reverse &copy);
};

template<typename T>
map_iterator_reverse<T>::map_iterator_reverse() : point(NULL)
{}

template<typename T>
map_iterator_reverse<T>::map_iterator_reverse(const map_iterator_reverse<T>::Pointer p)// : point(p)
{	this->point = p;	}

template<typename T>
map_iterator_reverse<T>::map_iterator_reverse(const map_iterator_reverse &copy)
{	*this = copy;	}

template<typename T>
map_iterator_reverse<T>::~map_iterator_reverse()
{}

template<typename T>
map_iterator_reverse<T>		map_iterator_reverse<T>::operator++(int)
{
	map_iterator_reverse<T> it = *this;
	this->operator++();
	return (it);
}

template<typename T>
map_iterator_reverse<T>		map_iterator_reverse<T>::operator--(int)
{
	map_iterator_reverse<T> it = *this;
	this->operator--();
	return (it);
}

template<typename T>
map_iterator_reverse<T>		&map_iterator_reverse<T>::operator++()
{
	if (!this->point)
		return (*this);
	else if (!this->point->_left)
	{
		while (this->point->_root && this->point == this->point->_root->_left)
			this->point = this->point->_root;
		this->point = this->point->_root;
	}
	else
	{
		this->point = this->point->_left;
		while (this->point && this->point->_right)
			this->point = this->point->_right;
	}
	return (*this);
}

template<typename T>
map_iterator_reverse<T>		&map_iterator_reverse<T>::operator--()
{
	if (!this->point)
		return (*this);
	else if (!this->point->_right)
	{
		while (this->point->_root && this->point == this->point->_root->_right)
			this->point = this->point->_root;
		this->point = this->point->_root;
	}
	else
	{
		this->point = this->point->_right;
		while (this->point && this->point->_left)
			this->point = this->point->_left;
	}
	return (*this);
}

template<typename T>
bool	map_iterator_reverse<T>::operator!=(const map_iterator_reverse &it)
{	return (this->point != it.point);	}

template<typename T>
bool	map_iterator_reverse<T>::operator==(const map_iterator_reverse &it)
{	return (this->point == it.point);	}

template<typename T>
T		&map_iterator_reverse<T>::operator*()
{	return (this->point->_data);	}

template<typename T>
T		*map_iterator_reverse<T>::operator->()
{	return (&this->point->_data);	}

template<typename T>
map_iterator_reverse<T>		&map_iterator_reverse<T>::operator=(const map_iterator_reverse<T> &copy)
{
	this->point = copy.point;
	return (*this);
}


}

#endif