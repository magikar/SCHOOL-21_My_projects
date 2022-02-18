#ifndef PAIR_HPP
# define PAIR_HPP


namespace ft {

template<class _T1, class _T2>
class pair
{
public:
	typedef _T1		first_type;
	typedef _T2		second_type;

	first_type		first;
	second_type		second;

	pair();
	pair(const _T1 &t1, const _T2 &t2);
	template<class _U1, class _U2>
	pair(const pair<_U1, _U2> &copy) : first(copy.first), second(copy.second) {}

	~pair();

	pair	&operator=(const pair &copy);
	void	swap(pair &pr);

};

template<class _T1, class _T2>
pair<_T1, _T2>::pair() : first(_T1()), second(_T2())
{}

template<class _T1, class _T2>
pair<_T1, _T2>::pair(const _T1 &t1, const _T2 &t2) : first(t1), second(t2)
{}

// template<class _T1, class _T2>
// pair<_T1, _T2>::pair(const pair<_T1, _T2> &copy) : first(copy.first), second(copy.second)
// {}

template<class _T1, class _T2>
pair<_T1, _T2>::~pair()
{}

template<class _T1, class _T2>
pair<_T1, _T2>	&pair<_T1, _T2>::operator=(const pair &copy)
{
	this->first = copy.first;
	this->second = copy.second;
	return (*this);
}

template<class _T1, class _T2>
void			pair<_T1, _T2>::swap(pair &pr)
{
	pair<_T1, _T2>	tmp = *this;
	*this = pr;
	pr = tmp;
}

// template<class _T1, class _T2>
// bool	pair<_T1, _T2>::operator==(const pair &copy)
// {
// 	return (this->first == copy.first && this->second == copy.second);
// }

// template<class _T1, class _T2>
// bool	pair<_T1, _T2>::operator!=(const pair &copy)
// {
// 	return (!(this->first == copy.first && this->second == copy.second));
// }

template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

template<class _T1, class _T2>
pair<_T1, _T2>			make_pair(_T1 x, _T2 y)
{
	return (ft::pair<_T1, _T2>(x, y));
}



}

#endif