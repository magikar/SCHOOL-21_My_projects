#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"


namespace ft {


template<class T, class Container = ft::vector<T> >
class stack
{
public:
	typedef Container						container_type;
	typedef T								value_type;
	typedef size_t							size_type;

protected:
	container_type	c;
public:



explicit	stack(const container_type &ctnr = container_type())
{	this->c = ctnr;	}

stack(const stack &copy)
{	*this = copy;	}

~stack()
{}

stack		&operator=(const stack &copy)
{
	this->c = copy.c;
	return (*this);
}

bool		empty() const
{	return (this->c.empty());	}

size_type	size() const
{	return (this->c.size());	}

value_type		&top()
{	return (this->c.back());	}

const value_type		&top() const
{	return (this->c.back());	}

void		push(const value_type &val)
{	this->c.push_back(val);	}

void		pop()
{	this->c.pop_back();	}

template <class value_type, class c>
friend bool		operator==(const stack<value_type,c>& lhs, const stack<value_type,c>& rhs);

template <class value_type, class c>
friend bool		operator< (const stack<value_type,c>& lhs, const stack<value_type,c>& rhs);

template <class value_type, class c>
friend bool		operator> (const stack<value_type,c>& lhs, const stack<value_type,c>& rhs);




};

template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{	return lhs.c == rhs.c;	}

template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{	return !(lhs == rhs);	}

template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{	return lhs.c < rhs.c;	}

template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{	return !(lhs > rhs);	}

template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{	return lhs.c > rhs.c;	}

template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{	return !(lhs < rhs);	}



}

#endif


