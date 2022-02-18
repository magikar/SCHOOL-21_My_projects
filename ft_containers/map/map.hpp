#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "../reimplemented/pair.hpp"
# include "../iterator/map_Iterator.hpp"
# include "../reimplemented/is_integral.hpp"
# include "../reimplemented/enable_if.hpp"
# include "../reimplemented/equal.hpp"
# include "../reimplemented/lexicographical_compare.hpp"

namespace ft {

	int		tabs = 0;

template<typename T>
struct Node
{
	T			_data;
	bool		_color;
	Node<T>		*_root;
	Node<T>		*_left;
	Node<T>		*_right;

	Node() : _data(T()), _color(1), _root(NULL), _left(NULL), _right(NULL)		{	}
	Node(const T &data) : _data(data), _color(1), _root(NULL), _left(NULL), _right(NULL)		{	}
	~Node() {	}

	///////////				PRINT RED BLACK TREE
	// void		printTree(Node<T> *TNULL) const {
	// 	tabs += 5;
	// 	if (this->_left != TNULL)
	// 		this->_left->printTree(TNULL);
	// 	for (int i = 0; i < tabs; i++) std::cout << ' ';
	// 		std::cout << this->_data.first << ' ' << this->_data.second << " - ";
	// 	if (!this->_color)
	// 		std::cout << "\e[3m\e[2mBLACK\e[0m" << std::endl;
	// 	else
	// 		std::cout << "\e[31mRED\e[0m" << std::endl;
	// 	if (this->_right != TNULL)
	// 		this->_right->printTree(TNULL);
	// 	tabs -= 5;
	// 	return;
	// }

};

template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
class map 
{
public:
	typedef Key								key_type;
	typedef T								mapped_type;
	typedef ft::pair<const Key, T>			value_type;
	typedef Compare							key_compare;
	typedef Alloc							allocator_type;
	typedef typename Alloc::template rebind<Node<value_type> >::other	AllocNode;
	typedef Node<value_type>				Node;
	typedef ft::map_iterator<value_type >					iterator;
	typedef ft::map_iterator< value_type >				const_iterator;
	typedef ft::map_iterator_reverse<value_type >			reverse_iterator;
	typedef ft::map_iterator_reverse<const value_type >		const_reverse_iterator;
	#define BLACK 0
	#define RED 1
private:
	Node			*root;
	Node			*_end_right;
	Node			*_end_left;
	size_t			_size;
	AllocNode		alloc;
	key_compare		_comp;


public:
///////////				PRINT RED BLACK TREE
	// void		printTree()  {	if (this->_size) {	this->untie();	this->root->printTree(NULL); this->bind();	}	}




class value_compare
{
	friend class map;
protected:
	Compare _comp;
	value_compare (Compare c) : _comp(c) {}
public:
	typedef bool			result_type;
	typedef value_type		first_argument_type;
	typedef value_type		second_argument_type;
	bool	operator() (const value_type &x, const value_type &y) const
	{	return _comp(x.first, y.first);	}
};




	///////////////////////////////////////////////////////   Member functions   ///////////////////////////////////////////////

//					<<<<<<		CONSTRUCTOR / DESTRUCTOR		>>>>>>

explicit	map(const key_compare& _compp = key_compare(),
				const allocator_type& allocc = allocator_type()) : root(NULL), _size(0), alloc(allocc), _comp(_compp)
{
	this->_end_left = this->alloc.allocate(1);
	this->_end_right = this->alloc.allocate(1);
	this->alloc.construct(this->_end_left);
	this->alloc.construct(this->_end_right);
	this->_end_left->_root = NULL;
	this->_end_right->_root = NULL;
}

template <class InputIterator>
map(InputIterator first, InputIterator last,
		const key_compare& _compp = key_compare(),
		const allocator_type& allocc = allocator_type()) : root(NULL), _size(0), alloc(allocc), _comp(_compp)
{
	this->_end_left = this->alloc.allocate(1);
	this->_end_right = this->alloc.allocate(1);
	this->alloc.construct(this->_end_left);
	this->alloc.construct(this->_end_right);
	this->_end_left->_root = NULL;
	this->_end_right->_root = NULL;
	this->insert(first, last);
}

map(const map &copy) : root(NULL), _size(0), alloc(std::allocator<Node >()), _comp(std::less<Key >())
{
	this->_end_left = this->alloc.allocate(1);
	this->_end_right = this->alloc.allocate(1);
	this->alloc.construct(this->_end_left);
	this->alloc.construct(this->_end_right);
	this->_end_left->_root = NULL;
	this->_end_right->_root = NULL;
	this->insert(copy.begin(), copy.end());
}

~map()
{	ft_del_tree(this->root);	}

map		&operator=(const map &copy)
{
	this->clear();
	this->insert(copy.begin(), copy.end());
	return (*this);
}




//					<<<<<<		ITERATORS		>>>>>>

iterator				begin()
{
	if (this->_end_left->_root)	return (this->_end_left->_root);
	else	return (this->_end_right);
}

const_iterator			begin() const
{
	if (this->_end_left->_root)	return (this->_end_left->_root);
	else	return (this->_end_right);
}

iterator				end()
{	return (this->_end_right);	}

const_iterator			end() const
{	return (this->_end_right);	}

reverse_iterator		rbegin()
{
	if (this->_end_right->_root)	return (this->_end_right->_root);
	else	return (this->_end_right);
}

const_reverse_iterator	rbegin() const
{
	if (this->_end_right->_root)	return (this->_end_right->_root);
	else	return (this->_end_right);
}

reverse_iterator		rend()
{	return (this->_end_left);	}

const_reverse_iterator	rend() const
{	return (this->_end_left);	}



//					<<<<<<		CAPACITY		>>>>>>

bool					empty() const
{
	if (this->_size)
		return (false);
	return (true);
}

size_t					size() const
{	return (this->_size);	}

size_t		max_size() const
{	return (std::numeric_limits<size_t>::max() / sizeof(Node));	}



//					<<<<<<		OBSERVERS		>>>>>>

key_compare			key_comp() const
{	return (this->_comp);	}

value_compare			value_comp() const
{	return (this->_comp);	}



//					<<<<<<		Element access:		>>>>>>

T			&operator[](const Key &k)
{	return (*((this->insert(ft::pair<const Key, T>(k, T()))).first)).second;	}

mapped_type				&at(const key_type &key)
{
	iterator	it = this->find(key);

	if (it == this->end())
		throw Exc();
	return (it->second);
}

const mapped_type				&at(const key_type &key) const
{
	iterator	it = this->find(key);

	if (it == this->end())
		throw Exc();
	return (it->second);
}



//					<<<<<<		OPERATIONS		>>>>>>

iterator			find(const Key &key)
{
	Node	*x = this->root, *z = NULL;

	this->untie();
	while (x)
	{
		if (x->_data.first == key) {
			z = x; break ;	}
		if (x->_data.first < key)
			x = x->_right;
		else
			x = x->_left;
	}
	this->bind();
	if (z == NULL)
	{		return (this->end());	}
	return (iterator(z));
}

size_t				count(const Key &key)
{
	iterator	it = this->find(key);

	if (!this->_size || it == this->end())
		return (0);
	return (1);
}

iterator			lower_bound(const Key &k)
{
	if (this->_size)
	{
		for (iterator it = this->begin(); it != this->end(); ++it)
			if (it->first >= k)
				return (it);
	}
	return (this->end());
}

const_iterator			lower_bound(const Key &k) const
{
	if (this->_size)
	{
		for (iterator it = this->begin(); it != this->end(); ++it)
			if (it->first >= k)
				return (it);
	}
	return (this->end());
}

iterator			upper_bound(const Key &k)
{
	if (this->_size)
	{
		for (iterator it = this->begin(); it != this->end(); ++it)
			if (it->first > k)
				return (it);
	}
	return (this->end());
}

const_iterator			upper_bound(const Key &k) const
{
	if (this->_size)
	{
		for (iterator it = this->begin(); it != this->end(); ++it)
			if (it->first > k)
				return (it);
	}
	return (this->end());
}

pair<iterator,iterator>		equal_range(const Key &k)
{
	return (ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
}

pair<const_iterator,const_iterator>		equal_range(const Key &k) const
{
	return (ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
}

pair<iterator, bool>		insert(const value_type &key)
{
	Node		*x = this->root, *y = NULL, *n = NULL;

	this->untie();
	while (x)
	{
		y = x;
		if (x->_data.first == key.first)
		{	this->bind();	iterator it(x);	return (ft::pair<iterator, bool>(it, false));	}
		else if (x->_data.first > key.first)
			x = x->_left;
		else
			x = x->_right;
	}
	n = this->alloc.allocate(1);
	this->alloc.construct(n, Node(key));
	n->_left = NULL;
	n->_right = NULL;
	n->_root = y;
	++this->_size;
	if (y == NULL)
		this->root = n;
	else if (n->_data.first < y->_data.first)
		y->_left = n;
	else
		y->_right = n;
	if (n->_root == NULL)
	{
		n->_color = BLACK;
		this->bind();	iterator it(n);
		return (ft::pair<iterator, bool>(it, true));
	}
	this->insertFix(n);
	this->bind();	iterator it(n);
	return (ft::pair<iterator, bool>(it, true));
}

iterator			insert(iterator position, const value_type& val)
{
	if (position->first == val.first)
		return position;
	ft::pair<iterator, bool>	p = this->insert(val);
	return (p.first);
}

template <class InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
				insert(InputIterator first, InputIterator last)
{
	for (; first != last; ++first)
		this->insert(*first);
}

size_t	erase(const Key &key)
{
	Node		*z = NULL;
	Node		*x = this->root, *y, *par = NULL;

	this->untie();
	while (x)
	{
		if (x->_data.first == key) {
			z = x; break ;	}
		if (x->_data.first < key)
			x = x->_right;
		else
			x = x->_left;
	}
	if (z == NULL)
	{	this->bind();	return 0;	}
	
	--this->_size;
	y = z;
	bool	y_origin_color = y->_color;
	if (z->_left == NULL)
	{
		x = z->_right;
		par = z->_root;
		this->rbTransplant(z, x);
	}
	else if (z->_right == NULL)
	{
		x = z->_left;
		par = z->_root;
		this->rbTransplant(z, x);
	}
	else
	{
		y = this->minimum(z->_right);
		y_origin_color = y->_color;
		x = y->_right;
		if (y->_root == z)
			par = y;
		else
		{
			par = y->_root;
			this->rbTransplant(y, y->_right);
			y->_right = z->_right;
			y->_right->_root = y;
		}
		this->rbTransplant(z, y);
		y->_left = z->_left;
		y->_left->_root = y;
		y->_color = z->_color;
	}
	this->alloc.destroy(z);
	this->alloc.deallocate(z, 1);
	if (y_origin_color == 0 && par)
		this->deleteFix(x, par);
	this->bind();
	return 1;
}

void				erase(iterator position)
{
	this->erase(position->first);
}

void				erase(iterator first, iterator last)
{
	if (!this->size())
		return ;
	for (iterator tmp; first != last; )
	{
		tmp = first;
		++first;
		this->erase(tmp->first);
	}
	if (!this->size())
	{
		this->_end_left->_root = NULL;
		this->_end_right->_root = NULL;
	}
}

void		swap(map &x)
{
	// this->swap1(this->root, x.root);
	// this->swap1(this->_end_left, x._end_left);
	// this->swap1(this->_end_right, x._end_right);
	// this->swap1(this->_size, x._size);
	Node		*tmpN;
	size_t		tmpS;

	tmpN = this->root;
	this->root = x.root;
	x.root = tmpN;

	tmpN = this->_end_left;//rend()
	this->_end_left = x._end_left;
	x._end_left = tmpN;

	tmpN = this->_end_right;//end()
	this->_end_right = x._end_right;
	x._end_right = tmpN;

	tmpS = this->_size;
	this->_size = x._size;
	x._size = tmpS;
}

void		clear()
{
	this->untie();
	ft_del_tree(this->root);
	this->root = NULL;
	this->_size = 0;
}

Alloc		get_allocator() const
{	return (this->alloc);	}



class Exc : public std::exception {
public:
	const char*  what() const throw() {
		return "map::at:  key not found";
	}
};




private:

template<typename U>
void	swap1(U &x, U &y)
{
	U	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

void		insertFix(Node *n)
{
	if (!n || !n->_root)
		return ;
	while (n->_root->_color == RED)
	{
		if (n->_root->_root && n->_root == n->_root->_root->_left)
		{
			if (n->_root->_root->_right && n->_root->_root->_right->_color == RED)
			{
				n->_root->_root->_right->_color = BLACK;
				n->_root->_color = BLACK;
				n->_root->_root->_color = RED;
				n = n->_root->_root;
			}
			else
			{
				if (n == n->_root->_right)
				{
					Node *tmp = n->_root;
					this->rotate_left(n);
					n = tmp;
				}
				n->_root->_color = BLACK;
				if (n->_root->_root)
					n->_root->_root->_color = RED;
				this->rotate_right(n->_root);
			}
		}
		else
		{
			if (n->_root->_root && n->_root->_root->_left && n->_root->_root->_left->_color == RED)
			{
				n->_root->_root->_left->_color = BLACK;
				n->_root->_color = BLACK;
				n->_root->_root->_color = RED;
				n = n->_root->_root;
			}
			else
			{
				if (n == n->_root->_left)
				{
					Node *tmp = n->_root;
					this->rotate_right(n);
					n = tmp;
				}
				n->_root->_color = BLACK;
				if (n->_root->_root)
					n->_root->_root->_color = RED;
				this->rotate_left(n->_root);
			}
		}
		if (n == this->root)
			break ;
	}
	this->root->_color = BLACK;
}

void		rotate_left(Node *n)
{
	if (n == NULL || n->_root == NULL || n->_root->_left == n)
		return ;
	Node		*parentNode = n->_root;
	Node		*grandParentNode = n->_root->_root;
	parentNode->_right = n->_left;
	if (n->_left) {
		n->_left->_root = parentNode;
		n->_left = NULL;
	}
	n->_root = grandParentNode;
	if (grandParentNode == NULL)
		root = n;
	else if (grandParentNode->_left == parentNode)
		grandParentNode->_left = n;
	else
		grandParentNode->_right = n;
	n->_left = parentNode;
	parentNode->_root = n;
}

void		rotate_right(Node *n)
{
	if (n == NULL || n->_root == NULL || n->_root->_right == n)
		return ;
	Node		*parentNode = n->_root;
	Node		*grandParentNode = n->_root->_root;
	parentNode->_left = n->_right;
	if (n->_right) {
		n->_right->_root = parentNode;
		n->_right = NULL;
	}
	n->_root = grandParentNode;
	if (grandParentNode == NULL)
		root = n;
	else if (grandParentNode->_left == parentNode)
		grandParentNode->_left = n;
	else
		grandParentNode->_right = n;
	n->_right = parentNode;
	parentNode->_root = n;
}



void	deleteFix(Node *x, Node *par)
{
	Node		*s;
	while (par && x != root && (x == NULL || x->_color == BLACK))
	{
		if (x == par->_left)
		{
			s = par->_right;
			if (s && s->_color == RED)
			{
				s->_color = BLACK;
				par->_color = RED;
				this->rotate_left(s);
				s = par->_right;
			}
			if (s && (!s->_left || s->_left->_color == BLACK) && (!s->_right || s->_right->_color == BLACK))
			{
				s->_color = RED;
				x = par;
				par = par->_root;
			}
			else
			{
				if (s && (!s->_right || s->_right->_color == BLACK))
				{
					if (s->_left)
						s->_left->_color = BLACK;
					s->_color = RED;
					this->rotate_right(s->_left);
					s = par->_right;
				}
				if (s)
					s->_color = par->_color;
				par->_color = BLACK;
				if (s && s->_right)
					s->_right->_color = BLACK;
				this->rotate_left(par->_right);
				x = root;
			}
		}
		else
		{
			s = par->_left;
			if (s && s->_color == RED)
			{
				s->_color = BLACK;
				par->_color = RED;
				this->rotate_right(s);
				s = par->_left;
			}
			if (s && (!s->_left || s->_left->_color == BLACK) && (!s->_right || s->_right->_color == BLACK))
			{
				s->_color = RED;
				x = par;
				par = par->_root;
			}
			else
			{
				if (s && (!s->_left || s->_left->_color == BLACK))
				{
					if (s->_right)
						s->_right->_color = BLACK;
					s->_color = RED;
					this->rotate_left(s->_right);
					s = par->_left;
				}
				if (s)
					s->_color = par->_color;
				par->_color = BLACK;
				if (s && s->_left)
					s->_left->_color = BLACK;
				this->rotate_right(par->_left);
				x = root;
			}
		}
	}
	if (x)
	x->_color = BLACK;
}

void	rbTransplant(Node *n1, Node *n2)
{
	if (n1->_root == NULL)
		this->root = n2;
	else if (n1 == n1->_root->_left)
		n1->_root->_left = n2;
	else
		n1->_root->_right = n2;
	if (n2)
	n2->_root = n1->_root;
}

Node		*minimum(Node *n)
{
	while (n->_left)
		n = n->_left;
	return n;
}



void		bind()
{
	Node	*tmp = this->root;
	if (!tmp)	return ;
	while (tmp->_left)
		tmp = tmp->_left;
	tmp->_left = this->_end_left;
	this->_end_left->_root = tmp;
	for (tmp = this->root; tmp->_right; tmp = tmp->_right) ;
	tmp->_right = this->_end_right;
	this->_end_right->_root = tmp;
}

void		untie()
{
	if (this->_end_left->_root)
		this->_end_left->_root->_left = NULL;
	this->_end_left->_root = NULL;
	if (this->_end_right->_root)
		this->_end_right->_root->_right = NULL;
	this->_end_right->_root = NULL;
}

void		ft_del_tree(Node *n)
{
	if (n)
	{
		ft_del_tree(n->_left);
		ft_del_tree(n->_right);
		this->alloc.destroy(n);
		this->alloc.deallocate(n, 1);
		n = NULL;
	}
}

};



template< class Key, class T, class Compare, class Alloc >
bool	operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs.size() == rhs.size())
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	return (false);
}

template< class Key, class T, class Compare, class Alloc >
bool	operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{	return (!(lhs == rhs));	}

template< class Key, class T, class Compare, class Alloc >
bool	operator< ( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));	}

template< class Key, class T, class Compare, class Alloc >
bool	operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{	return (!(lhs > rhs));	}

template< class Key, class T, class Compare, class Alloc >
bool	operator> ( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs == rhs)
		return false;
	return (!(lhs < rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool	operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{	return (!(lhs < rhs));	}




}





#endif