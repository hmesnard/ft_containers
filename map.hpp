#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include "red_black_tree.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = allocator<ft::pair<const Key, T> > >
	class map
	{
		public:

			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;

			class value_compare
			{
				protected:

					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			typedef Alloc											allocator_type;
			typedef allocator_type::reference						reference;
			typedef allocator_type::const_reference					const_reference;
			typedef allocator_type::pointer							pointer;
			typedef allocator_type::const_pointer					const_pointer;
			typedef ft::RBTiterator<value_type>						iterator;
			typedef ft::RBTiterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef allocator_type::size_type						size_type;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(RBT<value_type>()) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(RBT<value_type>()) { this->insert(first, last); }
			map (const map& x) { *this = x; }
			~map() { this->clear(); }

			map&	operator=(const map& x) {
				this->clear();
				this->insert(x.begin(), x.end());
				return (*this);
			}

			iterator begin() { return (this->_tree.begin()); }
			const_iterator begin() const { return (this->_tree.begin()); }
			iterator end() { return (this->_tree.end()); }
			const_iterator end() const { return (this->_tree.end()); }
			reverse_iterator rbegin() { return (reverse_iterator()); }

		private:

			allocator_type		_alloc;
			key_compare			_comp;
			ft::RBT<value_type>	_tree;
	};
}

#endif
