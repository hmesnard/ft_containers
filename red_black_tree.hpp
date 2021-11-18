#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include <iostream>

namespace ft
{
	template<class T>
	struct Node
	{
		typedef Node * branch;

		Node(T val, bool red, branch parent = NULL) : parent(parent), left(NULL), right(NULL), red(red), value(val) {}

		branch	parent;
		branch	left;
		branch	right;

		bool	red;

		T		value;
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
				else if (this->node->right)
				{
					this->node = this->node->right;
					std::cout << "R" << std::endl;
					while (this->node->left)
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
					this->node = parent;
					std::cout << "P" << std::endl;
				}
				return (*this);
			}

		public://

			Node<T>*	node;
	};

	template<class T>
	class RBT
	{
		public:

			RBT() : root(NULL) {}
			void print() {
				RBTiterator<T>	it = this->begin();
				while (it.node)
				{
					std::cout << it.node->value << ((it.node->red) ? " RED" : " BLACK") << std::endl;
					++it;
				}
			}
			RBTiterator<T> begin() {
				if (!this->root)
					return (RBTiterator<T>());
				Node<T>*	node = this->root;
				while (node->left)
					node = node->left;
				return (RBTiterator<T>(node));
			}
			void left_rotate(Node<T>* x) {
				if (!x || !x->right/* || !x->right->left*/)
					return ;
				if (x->right->left)
					x->right->left->parent = x;
				x->right->parent = x->parent;
				x->parent = x->right;
				x->right = x->right->left;
				x->parent->left = x;
				if (x->parent->parent && x->parent->parent->left == x)
					x->parent->parent->left = x->parent;
				else if (x->parent->parent && x->parent->parent->right == x)
					x->parent->parent->right = x->parent;
				else if (this->root == x)
					this->root = x->parent;
			}
			void right_rotate(Node<T>* x) {
				if (!x || !x->left/* || !x->left->right*/)
					return ;
				if (x->left->right)
					x->left->right->parent = x;
				x->left->parent = x->parent;
				x->parent = x->left;
				x->left = x->left->right;
				x->parent->right = x;
				if (x->parent->parent && x->parent->parent->left == x)
					x->parent->parent->left = x->parent;
				else if (x->parent->parent && x->parent->parent->right == x)
					x->parent->parent->right = x->parent;
				else if (this->root == x)
					this->root = x->parent;
			}
			void insert(T x)
			{
				if (!root)
				{
					root = new Node<T>(x, false);
					return ;
				}
				Node<T>* node = root;
				Node<T>* old;
				while (node)
				{
					old = node;
					if (x < node->value)
						node = node->left;
					else if (x > node->value)
						node = node->right;
					else
						return ;
				}
				if (x < old->value)
				{
					old->left = new Node<T>(x, true, old);
					fix(old->left);
				}
				else
				{
					old->right = new Node<T>(x, true, old);
					fix(old->right);
				}
			}

		public://

			Node<T>*	root;
			void fix(Node<T>* node)
			{
				if (node && node == root && node->red)
					node->red = false;
				if (!node || !node->parent || !node->parent->parent || !node->red || !node->parent->red)
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
