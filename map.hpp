#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include "map_red_black_tree.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
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
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::RBTiterator<value_type>						iterator;
			typedef ft::RBTiterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;

			typedef ft::MapRBT<key_type, mapped_type, key_compare>	RBT;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(RBT()) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _tree(RBT()) { this->insert(first, last); }
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
			reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }
			reverse_iterator rend() { return (reverse_iterator(this->begin())); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

			bool	empty() const { return (this->_tree.empty()); }
			size_type	size() const { return (this->_tree.size()); }
			size_type	max_size() const { return (this->_tree.max_size()); }

			mapped_type&	operator[](const key_type& k) { return (this->_tree.brackets(k)); }

			pair<iterator, bool> insert(const value_type& val) { return(this->_tree.insert(val)); }
			iterator insert(iterator position, const value_type& val) {
				(void)position;
				return (this->_tree.insert(val).first);
			}
			template<class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				/*for (; first != last; ++first)
					this->_tree.insert(*first);*/
				while (first != last)
				{
					InputIterator it = first;
					++first;
					this->_tree.insert(*it);
				}
			} //potentiel probleme ici si on insert depuis la map itself
			void erase(iterator position) { this->_tree.erase(position->first); }
			size_type erase(const key_type& k) { return (this->_tree.erase(k) ? 1 : 0); }
			void erase(iterator first, iterator last) {
				/*for (; first != last; ++first)
					this->erase(first);*/
				while (first != last)
				{
					iterator it = first;
					++first;
					this->erase(it);
				}
			} //ca buguait sous ubuntu
			void swap(map& x) { this->_tree.swap(x._tree); }
			void clear() { this->erase(this->begin(), this->end()); }

			key_compare key_comp() const { return (this->_comp); }
			value_compare value_comp() const { return (value_compare(_comp)); }

			iterator find(const key_type& k) { return (this->_tree.find(k)); }
			const_iterator find(const key_type& k) const { return (this->_tree.find(k)); }
			size_type count(const key_type& k) const { return(this->_tree.exist(k) ? 1 : 0); }
			iterator lower_bound(const key_type& k) { return (this->_tree.lower_bound(k)); }
			const_iterator lower_bound(const key_type& k) const { return (this->_tree.lower_bound(k)); }
			iterator upper_bound(const key_type& k) { return (this->_tree.upper_bound(k)); }
			const_iterator upper_bound(const key_type& k) const { return (this->_tree.upper_bound(k)); }
			pair<iterator, iterator> equal_range(const key_type& k) { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }
			pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

			allocator_type get_allocator() const { return (this->_alloc); }

		private:

			allocator_type	_alloc;
			key_compare		_comp;
			RBT				_tree;
	};
}

#endif
