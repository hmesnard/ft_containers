#ifndef MAP_RED_BLACK_TREE_HPP
# define MAP_RED_BLACK_TREE_HPP

#include <iostream>

namespace ft
{
	template<class Key, class T>
	struct Node
	{
		typedef Node * branch;

		Node(T val = NULL, bool red = false, branch parent = NULL) : parent(parent), left(NULL), right(NULL), red(red), value(val) {}

		branch	parent;
		branch	left;
		branch	right;

		bool	red;

		ft::pair<Key, T>*	value; //pointeur plutot ? DONE

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
	class RBTiterator
	{
		public:

			RBTiterator() : node(NULL) {}
			RBTiterator(Node<T>* node) : node(node) {}

			RBTiterator & operator++() {
				if (!this->node)
					return (*this);
				else if (!this->node->leaf() && !this->node->right->leaf())
				{
					this->node = this->node->right;
					std::cout << "R" << std::endl;
					while (!this->node->left->leaf())
					{
						this->node = this->node->left;
						std::cout << "L" << std::endl;
					}
				}
				else
				{
					Node<T>*	parent = this->node->parent;
					while (parent && parent->right == this->node)
					{
						this->node = parent;
						parent = parent->parent;
						std::cout << "P" << std::endl;
					}
					if (parent)
					{
						this->node = parent;
						std::cout << "P" << std::endl;
					}
					else
					{
						while (this->node->right)
						{
							this->node = this->node->right;
							std::cout << "R" << std::endl;
						}
					}
				}
				return (*this);
			}

			bool operator==(const RBTiterator & rhs) const { return (this->node == rhs.node); }
			bool operator!=(const RBTiterator & rhs) const { return (this->node != rhs.node); }

		public://

			Node<T>*	node;
	};

	template<class Key, class T, class Compare, class Node = Node<Key, T>, class Alloc = std::allocator<Node> >
	class MapRBT
	{
		public:

			typedef Key			key_type;
			typedef T			mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare		key_compare;
			typedef Alloc		allocator_type;
			typedef iterator	RBTiterator<value_type>				iterator;
			typedef allocator_type::size_type						size_type;

			RBT(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _alloc(alloc), _comp(comp) {}
			iterator	begin() {
				if (!this->_root || this->_root->leaf())
					return (RBTiterator<T>());
				Node*	node = this->_root;
				while (!node->left->leaf())
					node = node->left;
				return (RBTiterator<T>(node));
			}
			iterator	end() {
				Node*	node = this->_root;
				if (!this->_root || this->_root->leaf())
					return (iterator());
				while (node->right)
					node = node->right;
				return (RBTiterator<T>(node));
			}

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
			pair<iterator, bool>	insert(T val)
			{
				if (!this->_root)
				{
					//root = new Node();
					this->_root = this->_alloc.allocate(1);
					this->_alloc.construct(_root, Node());
				}
				if (_root->leaf())
				{
					this->_root->value = val;
					//root->left = new Node(T(), false, root);
					this->_root->left = this->_alloc.allocate(1);
					this->_alloc.construct(_root->left, Node(T(), false, this->_root));
					//root->right = new Node(T(), false, root);
					this->_root->right = this->_alloc.allocate(1);
					this->_alloc.construct(_root->right, Node(T(), false, this->_root));
				}
				Node* node = this->_root;
				while (!node->leaf())
				{
					if (val.first < node->value.first)
						node = node->left;
					else if (val.first > node->value.first)
						node = node->right;
					else
						return (ft::make_pair(iterator(node), false));
				}
				node->value = val;
				node->red = true;
				//node->left = new Node<T>(T(), false, node);
				node->left = this->_alloc.allocate(1);
				this->_alloc.construct(node->left, Node(T(), false, node));
				//node->right = new Node<T>(T(), false, node);
				node->left = this->_alloc.allocate(1);
				this->_alloc.construct(node->left, Node(T(), false, node));
				fix(node);
				return (ft::make_pair(iterator(node), true));
			}
			bool erase(const key_type& k)
			{
				Node* node = this->_root;
				Node* next;
				Node* x;
				bool wasRed;

				if (!node)
					return (false);
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
				delete(node);

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
				return (this->insert(ft::make_pair(k, mapped_type()).first->second));
			}
			void	swap(MapRBT& x)
			{
				Node*	temp = this->_root;
				this->_root = x._root;
				x._root = temp;
			}
			iterator find(const key_type& k) {
				Node*	node = this->_root;

				if (!node)
					return (iterator());
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
					return (iterator());
				return (iterator(node));
			}
			bool exist(const key_type& k) {
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
			iterator lower_bound(const key_type& k) {
				Node*	node = this->_root;

				if (!node)
					return (iterator());
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
					return (iterator(node->parent));
				else
					return (++iterator(node->parent));
			}
			iterator upper_bound(const key_type& k) {
				Node*	node = this->_root;

				if (!node)
					return (iterator()); //this->end() partout a la place de ca
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
					return (iterator(node->parent));
				else
					return (++iterator(node->parent));
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
				if (node && !node->leaf() && node == root && node->red)
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
