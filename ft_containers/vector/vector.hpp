#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../iterator/random_access_iterator.hpp"
# include "../reimplemented/enable_if.hpp"
# include "../reimplemented/equal.hpp"
# include "../reimplemented/lexicographical_compare.hpp"
# include "../reimplemented/is_integral.hpp"

namespace ft {


template<typename T, class Alloc = std::allocator<T> >
class vector
{
public:
	typedef T										value_type;
	typedef T&										reference;
	typedef T*										pointer;
	typedef const T*								const_pointer;
	typedef const T&								const_reference;
	typedef Alloc									allocator_type;
	typedef ft::random_access_iterator<T>			iterator;
	typedef ft::random_access_iterator<const T>		const_iterator;
	typedef ft::reverse_iterator<T>					reverse_iterator;
	typedef ft::reverse_iterator<const T>			const_reverse_iterator;
	typedef size_t									size_type;
private:
	T			*_vec;
	size_t		_capacity;
	size_t		_size;
	Alloc		alloc;


public:



explicit	vector(const allocator_type& allocc = allocator_type()) : _capacity(0), _size(0), alloc(allocc)
{
	this->_vec = this->alloc.allocate(0);
}

explicit	vector(size_type n, const value_type& val = value_type(),
					const allocator_type& allocc = allocator_type()) : _capacity(n), _size(n), alloc(allocc)
{
	if (n > this->max_size())
		throw Exc();
	this->_vec = this->alloc.allocate(n);
	for (size_t i = 0; i < n; ++i)
		this->alloc.construct(this->_vec + i, val);
}

template <class InputIterator>
vector(typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
		const allocator_type& allocc = allocator_type()) : _capacity(last - first), _size(_capacity), alloc(allocc)
{
	this->_vec = this->alloc.allocate(this->_capacity);
	for (size_t i = 0; first != last; ++i, ++first)
		this->alloc.construct(this->_vec + i, *first);
}

vector(const vector &copy) : _vec(NULL)
{	*this = copy;	}

~vector()
{
	for (size_t i = 0; i < this->_size; i++)
		this->alloc.destroy(this->_vec + i);
	this->alloc.deallocate(this->_vec, this->_capacity);
}

vector<T>		&operator=(const vector &copy)
{
	if (this->_vec) {
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
		this->alloc.deallocate(this->_vec, this->_capacity);
	}
	this->_capacity = copy._capacity;
	this->_size = copy._size;
	this->_vec = this->alloc.allocate(this->_capacity);
	for (size_t i = 0; i < this->_size; i++)
		this->alloc.construct(this->_vec + i, copy._vec[i]);

	return (*this);
}



	// <<<<<<<<<   iterators   >>>>>>>>>

iterator			begin()
{	return (iterator(this->_vec));	}

const_iterator		begin() const
{	return (const_iterator(this->_vec));	}

iterator			end()
{	return (iterator(this->_vec + this->_size));	}

const_iterator		end() const
{	return (const_iterator(this->_vec + this->_size));	}



reverse_iterator			rbegin()
{	return (reverse_iterator(this->_vec + this->_size - 1));	}

const_reverse_iterator		rbegin() const
{	return (const_reverse_iterator(this->_vec + this->_size - 1));	}

reverse_iterator			rend()
{	return (reverse_iterator(this->_vec - 1));	}

const_reverse_iterator		rend() const
{	return (const_reverse_iterator(this->_vec - 1));	}




	// <<<<<<<<<   Capacity   >>>>>>>>>

size_t		size() const
{	return (this->_size);	}

size_t		max_size() const
{	return (std::numeric_limits<size_t>::max());	}

void		resize(size_t n, T val = value_type())
{
	T		*tmp;
	
	if (n == this->_size)
		return ;
	else if (n > this->_capacity)
	{
		if (n > this->_capacity * 2)
			tmp = this->alloc.allocate(n);
		else
			tmp = this->alloc.allocate(this->_capacity * 2);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.construct(tmp + i, this->_vec[i]);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
		this->alloc.deallocate(this->_vec, this->_capacity);
		if (n > this->_capacity * 2)
			this->_capacity = n;
		else
			this->_capacity *= 2;
		this->_vec = tmp;
	}
	else if (n < this->_size)
	{
		for (; n < this->_size; this->_size--)
			this->alloc.destroy(this->_vec + this->_size - 1);
		return ;
	}
	for (; this->_size < n; this->_size++)
		this->alloc.construct(this->_vec + this->_size, val);
}

size_t		capacity() const
{	return (this->_capacity);	}

bool		empty() const
{	return (this->_size ? false : true);	}

void		reserve(size_t n)
{
	if (n > this->_capacity)
	{
		T	*tmp = this->alloc.allocate(n);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.construct(tmp + i, this->_vec[i]);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_capacity = n;
		this->_vec = tmp;
	}
}

void		shrink_to_fit()
{
	if (this->_size < this->_capacity)
	{
		T	*tmp = this->alloc.allocate(this->_size);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.construct(tmp + i, this->_vec[i]);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_capacity = this->_size;
		this->_vec = tmp;
	}
}


	// <<<<<<<<<   Element access   >>>>>>>>>:

reference			operator[](const size_t &n)
{	return (this->_vec[n]);	}

const_reference		operator[](const size_t &n) const
{	return (this->_vec[n]);	}

reference			at(size_t n)
{
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return (this->_vec[n]);
}

const_reference		at(size_t n) const
{
	if (n >= this->_size)
		throw std::out_of_range("vector");
	return (this->_vec[n]);
}

reference			front()
{	return (*(this->_vec));	}

const_reference		front() const
{	return (*(this->_vec));	}

reference			back()
{	return (*(this->_vec + (this->_size - 1)));	}

const_reference		back() const
{	return (*(this->_vec + (this->_size - 1)));	}

T			*data()
{	return (this->_vec);	}

const T		*data() const
{	return (this->_vec);	}



	// <<<<<<<<<   Modifiers   >>>>>>>>>:

template<typename InputIterator>
typename enable_if<!is_integral<InputIterator>::value, void>::type
		assign(InputIterator first, InputIterator last)
{
	T	*tmp = this->_vec;

	if (first > last)
		throw std::exception();
	for (size_t i = 0; i < this->_size; i++)
		this->alloc.destroy(tmp + i);
	if (static_cast<size_t>(last - first) > this->_capacity)
	{
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_capacity = last - first;
		this->_vec = this->alloc.allocate(this->_capacity);
	}
	for (this->_size = 0; first + this->_size < last; this->_size++)
		this->alloc.construct(this->_vec + this->_size, *(first + this->_size));
}

void		assign(size_t n, const T &val)
{
	if (n > this->_capacity)
	{
		T	*tmp;
		tmp = this->alloc.allocate(n);

		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_vec = tmp;
		this->_capacity = n;
	}
	else
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
	for (this->_size = 0; this->_size < n; this->_size++)
		this->alloc.construct(this->_vec + this->_size, val);
}

void		push_back(const T &value)
{
	if (this->_size == this->_capacity)
	{
		T	*tmp;

		if (this->_capacity == 0)
			tmp = this->alloc.allocate(++this->_capacity);
		else
			tmp = this->alloc.allocate((this->_capacity *= 2));
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.construct(tmp + i, this->_vec[i]);
		for (size_t i = 0; i < this->_size; i++)
			this->alloc.destroy(this->_vec + i);
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_vec = tmp;
	}
	this->alloc.construct(this->_vec + this->_size, value);
	++(this->_size);
}

void		pop_back()
{
	if (this->_size)
	{
		this->alloc.destroy(this->_vec + this->_size);
		--(this->_size);
	}
}

iterator		insert(iterator pos, const T &val)
{
	T	*tmp = this->_vec;
	iterator it = this->begin();
	size_t i = 0;

	if (this->_size == this->_capacity)
	{
		tmp = this->alloc.allocate(this->_capacity * 2);
		for (; it + i != pos; i++) {
			this->alloc.construct(tmp + i, this->_vec[i]);
			this->alloc.destroy(this->_vec + i);
		}
	}
	for (i = this->_size; (i != 0) && (it + i != pos); i--)
	{
		this->alloc.construct(tmp + i, this->_vec[i - 1]);
		this->alloc.destroy(this->_vec + i - 1);
	}
	this->alloc.construct(tmp + i, val);
	
	if (this->_size == this->_capacity)
	{
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_vec = tmp;
		this->_capacity *= 2;
	}
	++this->_size;
	return (iterator(&this->_vec[i]));
}

void		insert(iterator pos, size_t n, const T &val)
{
	T				*tmp = this->_vec;
	iterator		it = this->begin();
	size_t			i = 0;
	size_t			N = this->_size + n;

	if (N > this->_capacity)
	{
		if (N <= this->_capacity * 2)
			tmp = this->alloc.allocate(this->_capacity * 2);
		else
			tmp = this->alloc.allocate(N);
		for (; it + i != pos; i++) {
			this->alloc.construct(tmp + i, this->_vec[i]);
			this->alloc.destroy(this->_vec + i);
		}
	}
	for (i = this->_size; (n != 0) && (i != 0) && (it + i  != pos); i--)
	{
		this->alloc.construct(tmp + i + n - 1, this->_vec[i - 1]);
		this->alloc.destroy(this->_vec + i - 1);
	}
	this->_size += n;
	for (;n > 0; n--)
		this->alloc.construct(tmp + i + n - 1, val);
	
	if (N > this->_capacity)
	{
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_vec = tmp;
		if (N <= this->_capacity * 2)
			this->_capacity *= 2;
		else
			this->_capacity = N;
	}
}

template <class InputIterator>
typename enable_if<!is_integral<InputIterator>::value, void>::type
		insert(iterator position, InputIterator first, InputIterator last)
{
	T				*tmp = this->_vec;
	iterator		it = this->begin();
	size_t			i = 0;
	size_t			n = last - first;
	size_t			N = this->_size + n;

	if (first >= last)
		return ;
	if (N > this->_capacity)
	{
		if (N <= this->_capacity * 2)
			tmp = this->alloc.allocate(this->_capacity * 2);
		else
			tmp = this->alloc.allocate(N);
		for (; it + i != position; i++) {
			this->alloc.construct(tmp + i, this->_vec[i]);
			this->alloc.destroy(this->_vec + i);
		}
	}
	for (i = this->_size; (n != 0) && (i != 0) && (it + i  != position); i--)
	{
		this->alloc.construct(tmp + i + n - 1, this->_vec[i - 1]);
		this->alloc.destroy(this->_vec + i - 1);
	}
	this->_size += n;
	for (--last; n > 0; --n, --last)
		this->alloc.construct(tmp + i + n - 1, *last);
	
	if (N > this->_capacity)
	{
		this->alloc.deallocate(this->_vec, this->_capacity);
		this->_vec = tmp;
		if (N <= this->_capacity * 2)
			this->_capacity *= 2;
		else
			this->_capacity = N;
	}
}

iterator		erase(iterator pos)
{
	iterator		it = this->begin();
	size_t			i = 0;

	for (; it + i != pos; i++) {}
	this->alloc.destroy(this->_vec + i);
	for (; it + i + 1 != this->end(); i++)
	{
		this->alloc.construct(this->_vec + i, this->_vec[i + 1]);
		this->alloc.destroy(this->_vec + i + 1);
	}
	this->_size--;
	return (pos);
}

iterator		erase(iterator first, iterator last)
{
	iterator		it = this->begin();
	size_t			i = 0;
	size_t			n = last - first;

	if (first == last)
		return (first);
	for (; it + i != last; i++)
		if (it + i >= first)
			this->alloc.destroy(this->_vec + i);
	for (; it + i != this->end(); i++)
	{
		this->alloc.construct(this->_vec + i - n, this->_vec[i]);
		this->alloc.destroy(this->_vec + i);
	}
	this->_size -= n;
	return (first);
}

void		swap(vector &x)
{
	this->swap1(this->_vec, x._vec);
	this->swap1(this->_size, x._size);
	this->swap1(this->_capacity, x._capacity);
}

void		clear()
{
	for (; this->_size > 0; --this->_size)
		this->alloc.destroy(this->_vec + this->_size - 1);
}

Alloc	get_allocator() const
{
	return (this->alloc);
}

private:

template<typename U>
void	swap1(U &x, U &y)
{
	U	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

class Exc : public std::exception
{
	const char	*error_str;
public:
	Exc() : error_str("vector") {}
	Exc(const char *str) : error_str(str) {}

	const char* what() const throw()
	{	return error_str;	}
};

};

template <class T, class Alloc>
void		swap(ft::vector<T,Alloc>& x, vector<T,Alloc>& y)
{	x.swap(y);	}



template <class T, class Alloc>
bool		operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	return (false);
}

template <class T, class Alloc>
bool		operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{	return (!(lhs == rhs));	}

template <class T, class Alloc>
bool		operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));	}

template <class T, class Alloc>
bool		operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Alloc>
bool		operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return false;
	return (!(lhs < rhs));
}

template <class T, class Alloc>
bool		operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs < rhs));
}


}

#endif


