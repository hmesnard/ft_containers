#ifndef MAP_RED_BLACK_TREE_HPP
# define MAP_RED_BLACK_TREE_HPP

#include <iostream>
#include "utils.hpp"

namespace ft
{
	template<class Key, class T>
	struct Node
	{
		typedef Node * branch;
		typedef ft::pair<Key, T>	value_type;

		Node(value_type val = value_type(), bool red = false, branch parent = NULL) : parent(parent), left(NULL), right(NULL), red(red), value(val) {}

		branch	parent;
		branch	left;
		branch	right;

		bool	red;

		value_type	value; //pointeur plutot ? DONE UNDONE

		bool	leaf() {
			if (this->left && this->right)
				return (false);
			else if (!this->left && !this->right)
				return (true);
			else
				throw (std::string("Incorrect Node"));
		}
	};

	template<class T>
	class RBTiterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:

			typedef  typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef  typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef  typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef  typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;
			typedef  typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;

			typedef	typename value_type::first_type		key_type;
			typedef	typename value_type::second_type	mapped_type;
			typedef Node<const key_type, mapped_type>	Node;

			//RBTiterator() : node(NULL), root(NULL) {}
			RBTiterator(const RBTiterator& src) : node(src.node), root(src.root) {}
			RBTiterator(Node* node = NULL, Node* root = NULL) : node(node), root(root) {}
			virtual ~RBTiterator() {}

			operator RBTiterator<T const>() const { return (RBTiterator<T const>(this->node, this->root)); }

			RBTiterator&	operator=(const RBTiterator& rhs) {
				this->node = rhs.node;
				this->root = rhs.root;
				return (*this);
			}

			bool operator==(const RBTiterator & rhs) const { return (this->node == rhs.node); }
			bool operator!=(const RBTiterator & rhs) const { return (this->node != rhs.node); }

			reference	operator*() const { return (this->node->value); }
			pointer		operator->() const { return (&(this->node->value)); }

			RBTiterator& operator++() {
				if (!this->node)
				{
					this->node = this->root;
					while (!this->node->left->leaf())
						this->node = this->node->left;
				}
				else if (!this->node->leaf() && !this->node->right->leaf())
				{
					this->node = this->node->right;
					while (!this->node->left->leaf())
						this->node = this->node->left;
				}
				else
				{
					while (this->node->parent && this->node->parent->right == this->node)
						this->node = this->node->parent;
					if (this->node->parent)
						this->node = this->node->parent;
					else
						this->node = NULL;
				}
				return (*this);
			}
			RBTiterator	operator++(int) {
				RBTiterator	res = *this;
				++*this;
				return (res);
			}

			RBTiterator&	operator--() {
				if (!this->node)
				{
					this->node = this->root;
					while (!this->node->right->leaf())
						this->node = this->node->right;
				}
				else if (!this->node->leaf() && !this->node->left->leaf())
				{
					this->node = this->node->left;
					while (!this->node->right->leaf())
						this->node = this->node->right;
				}
				else
				{
					while (this->node->parent && this->node->parent->left == this->node)
						this->node = this->node->parent;
					if (this->node->parent)
						this->node = this->node->parent;
					else
						this->node = NULL;
				}
				return (*this);
			}
			RBTiterator	operator--(int) {
				RBTiterator	res = *this;
				--*this;
				return (res);
			}

		private:

			Node*	node;
			Node*	root;
	};

	template<class Key, class T, class Compare, class Node = Node<const Key, T>, class Alloc = std::allocator<Node> >
	class MapRBT
	{
		public:

			typedef Key			key_type;
			typedef T			mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare		key_compare;
			typedef Alloc		allocator_type;
			typedef RBTiterator<value_type>				iterator;
			typedef typename allocator_type::size_type				size_type;

			MapRBT(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _alloc(alloc), _comp(comp) {}
			iterator	begin() const {
				if (!this->_root || this->_root->leaf())
					return (iterator(NULL, this->_root));
				Node*	node = this->_root;
				while (!node->left->leaf())
					node = node->left;
				return (iterator(node, this->_root));
			}
			iterator	end() const { return (iterator(NULL, this->_root)); }

			bool empty() const { return (!this->_root || this->_root->leaf()); }
			size_type size() const {
				size_type	res = 0;

				for (iterator it = this->begin(); it != this->end(); ++it)
					++res;
				return (res);
			}
			size_type max_size() const { return (this->_alloc.max_size()); }

			void left_rotate(Node* x) {
				if (!x || x->leaf() || x->right->leaf())
					return ;
				//if (x->right->left)
				x->right->left->parent = x;
				x->right->parent = x->parent;
				x->parent = x->right;
				x->right = x->right->left;
				x->parent->left = x;
				if (x->parent->parent && x->parent->parent->left == x)
					x->parent->parent->left = x->parent;
				else if (x->parent->parent && x->parent->parent->right == x)
					x->parent->parent->right = x->parent;
				else if (this->_root == x)
					this->_root = x->parent;
			}
			void right_rotate(Node* x) {
				if (!x || x->leaf() || x->left->leaf())
					return ;
				//if (x->left->right)
				x->left->right->parent = x;
				x->left->parent = x->parent;
				x->parent = x->left;
				x->left = x->left->right;
				x->parent->right = x;
				if (x->parent->parent && x->parent->parent->left == x)
					x->parent->parent->left = x->parent;
				else if (x->parent->parent && x->parent->parent->right == x)
					x->parent->parent->right = x->parent;
				else if (this->_root == x)
					this->_root = x->parent;
			}
			pair<iterator, bool>	insert(value_type val)
			{
				if (!this->_root)
				{
					//root = new Node();
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(_root, Node(val));
					//this->_root->value = val;
					//root->left = new Node(T(), false, root);
					this->_root->left = this->_alloc.allocate(1);
					this->_alloc.construct(_root->left, Node(value_type(), false, this->_root));
					//root->right = new Node(T(), false, root);
					this->_root->right = this->_alloc.allocate(1);
					this->_alloc.construct(_root->right, Node(value_type(), false, this->_root));
					return (ft::make_pair(iterator(this->_root, this->_root), true));
				}
				Node* node = this->_root;
				while (!node->leaf())
				{
					if (val.first < node->value.first)
						node = node->left;
					else if (val.first > node->value.first)
						node = node->right;
					else
						return (ft::make_pair(iterator(node, this->_root), false));
				}
				//node->value = val;
				//node->red = true;
				Node* parent = node->parent;
				this->_alloc.destroy(node);
				this->_alloc.construct(node, Node(val, true, parent));
				//node->left = new Node<T>(T(), false, node);
				node->left = this->_alloc.allocate(1);
				this->_alloc.construct(node->left, Node(value_type(), false, node));
				//node->right = new Node<T>(T(), false, node);
				node->right = this->_alloc.allocate(1);
				this->_alloc.construct(node->right, Node(value_type(), false, node));
				fix(node);
				return (ft::make_pair(iterator(node, this->_root), true));
			}
			bool erase(const key_type& k)
			{
				Node* node = this->_root;
				Node* next;
				Node* x;
				bool wasRed;

				if (!node)
					return (false);
				if (node->left->leaf() && node->right->leaf() && node->value.first == k)
				{
					this->_alloc.deallocate(node->left, 1);
					this->_alloc.deallocate(node->right, 1);
					this->_alloc.deallocate(node, 1);
					this->_root = NULL;
					return (true);
				}
				while (!node->leaf())
				{
					if (k < node->value.first)
						node = node->left;
					else if (k > node->value.first)
						node = node->right;
					else
						break ;
				}
				if (node->leaf())
					return (false);
				wasRed = node->red;
				if (node->left->leaf())
				{
					x = node->right;
					next = x;
					if (node->parent && node->parent->left == node)
						node->parent->left = node->right;
					else if (node->parent)
						node->parent->right = node->right;
					//if (node->right)
					node->right->parent = node->parent;
				}
				else if (node->right->leaf())
				{
					x = node->left;
					next = x;
					if (node->parent && node->parent->left == node)
						node->parent->left = node->left;
					else if (node->parent)
						node->parent->right = node->left;
					//if (node->left)
					node->left->parent = node->parent;
				}
				else
				{
					next = node->right;
					while (!next->left->leaf())
						next = next->left;
					x = next->right;
					//if (next->right)
					next->right->parent = next->parent;
					if (next->parent->right == next)
						next->parent->right = next->right;
					else
						next->parent->left = next->right;

					if (node->parent && node->parent->left == node)
						node->parent->left = next;
					else if (node->parent)
						node->parent->right = next;
					next->parent = node->parent;
					node->left->parent = next;
					next->left = node->left;
					//if (node->right)
					node->right->parent = next;
					next->right = node->right;
				}
				if (node == this->_root)
					this->_root = next;
				this->_alloc.deallocate(node, 1);

				if (wasRed && (next->leaf() || next->red))
					;
				else if (wasRed)
				{
					next->red = true;
					fixdel(x);
				}
				else if (next && next->red)
					next->red = false;
				else if (x != this->_root)
					fixdel(x);
				return (true);
			}
			mapped_type&	brackets(const key_type& k) {
				for(iterator it = this->begin(); it != this->end(); ++it)
				{
					if (it->first == k)
						return(it->second);
				}
				return (this->insert(ft::make_pair(k, mapped_type())).first->second);
			}
			void	swap(MapRBT& x)
			{
				Node*	temp = this->_root;
				this->_root = x._root;
				x._root = temp;
			}
			iterator find(const key_type& k) const {
				Node*	node = this->_root;

				if (!node)
					return (this->end());
				while (!node->leaf())
				{
					if (this->_comp(k, node->value.first))
						node = node->left;
					else if (this->_comp(node->value.first, k))
						node = node->right;
					else
						break ;
				}
				if (node->leaf())
					return (this->end());
				return (iterator(node, this->_root));
			}
			bool exist(const key_type& k) const {
				Node*	node = this->_root;

				if (!node)
					return (false);
				while (!node->leaf())
				{
					if (this->_comp(k, node->value.first))
						node = node->left;
					else if (this->_comp(node->value.first, k))
						node = node->right;
					else
						break ;
				}
				if (node->leaf())
					return (false);
				return (true);
			}
			iterator lower_bound(const key_type& k) const {
				Node*	node = this->_root;

				if (!node)
					return (this->end());
				while (!node->leaf())
				{
					if (!this->_comp(node->value.first, k))
						node = node->left;
					else
						node = node->right;
				}
				if (!node->parent)
					return (this->end());
				else if (node->parent->left == node)
					return (iterator(node->parent, this->_root));
				else
					return (++iterator(node->parent, this->_root));
			}
			iterator upper_bound(const key_type& k) const {
				Node*	node = this->_root;

				if (!node)
					return (this->end()); //this->end() partout a la place de ca
				while (!node->leaf())
				{
					if (this->_comp(k, node->value.first))
						node = node->left;
					else
						node = node->right;
				}
				if (!node->parent)
					return (this->end());
				else if (node->parent->left == node)
					return (iterator(node->parent, this->_root));
				else
					return (++iterator(node->parent, this->_root));
			}

		private:

			Node*			_root;
			allocator_type	_alloc;
			key_compare		_comp;
			void fixdel(Node* node)
			{
				Node* sibling = (node->parent->left == node) ? node->parent->right : node->parent->left;

				if (node->red)
				{
					node->red = false;
					return ;
				}
				else if (sibling->red)
				{
					sibling->red = false;
					node->parent->red = true;
					if (node->parent->left == node)
						left_rotate(node->parent);
					else
						right_rotate(node->parent);
					fixdel(node);
				}
				else if (!sibling->left->red && !sibling->right->red)
				{
					sibling->red = true;
					node = node->parent;
					if (node->red)
					{
						node->red = false;
						return ;
					}
					else if (node->parent)
						fixdel(node);
					else
						return ;
				}
				else if ((node->parent->left == node && sibling->left->red && !sibling->right->red) ||
						(node->parent->right == node && sibling->right->red && !sibling->left->red)) //node peut il etre root ici ???
				{
					sibling->right->red = false;
					sibling->left->red = false;
					sibling->red = true;
					if (node->parent->left == node)
						right_rotate(sibling);
					else
						left_rotate(sibling);
					fixdel(node); //put case 4 here??
				}
				else
				{
					sibling->red = node->parent->red;
					node->parent->red = false;
					if (node->parent->left == node)
						sibling->right->red = false;
					else
						sibling->left->red = false;
					if (node->parent->left == node)
						left_rotate(node->parent);
					else
						right_rotate(node->parent);
					return ;
				}
			}

			void fix(Node* node)
			{
				if (node && !node->leaf() && node == _root && node->red)
					node->red = false;
				if (!node || node->leaf() || !node->parent || !node->parent->parent || !node->red || !node->parent->red)
					return ;
				else if ((node->parent->parent->left == node->parent && node->parent->parent->right && node->parent->parent->right->red)
					|| (node->parent->parent->right == node->parent && node->parent->parent->left && node->parent->parent->left->red))
				{
					node->parent->parent->red = !node->parent->parent->red;
					node->parent->parent->left->red = !node->parent->parent->left->red;
					node->parent->parent->right->red = !node->parent->parent->right->red;
					fix(node->parent->parent);
				}
				else if ((node->parent->left == node && node->parent->parent->right == node->parent && (!node->parent->parent->left || !node->parent->parent->left->red))
						|| (node->parent->right == node && node->parent->parent->left == node->parent && (!node->parent->parent->right || !node->parent->parent->right->red)))
				{
					if (node->parent->left == node)
					{
						right_rotate(node->parent);
						fix(node->right);
					}
					else
					{
						left_rotate(node->parent);
						fix(node->left);
					}
				}
				else if ((node->parent->right == node && node->parent->parent->right == node->parent && (!node->parent->parent->left || !node->parent->parent->left->red))
						|| (node->parent->left == node && node->parent->parent->left == node->parent && (!node->parent->parent->right || !node->parent->parent->right->red)))
				{
					node->parent->red = !node->parent->red;
					node->parent->parent->red = !node->parent->parent->red;
					if (node->parent->right == node)
						left_rotate(node->parent->parent);
					else
						right_rotate(node->parent->parent);
					fix(node->parent);
				}
			}
	};
}

#endif
