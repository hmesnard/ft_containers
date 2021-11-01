#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef allocator_type::reference						reference;
			typedef allocator_type::const_reference					const_reference;
			typedef allocator_type::pointer							pointer;
			typedef allocator_type::const_pointer					const_pointer;
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;

			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _size(0), _capacity(0) {}
			explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last) {

			}

			void assign(size_t n, const value_type& val) {
				if (n <= this->_capacity)
				{
					for (size_t i = 0; 0 < n; i++)
						_begin[i] = val;
					this->_size = n;
					this->_end = this->_begin + n;
				}
				else
				{

				}
			}

		private:
			allocator_type	_alloc;
			pointer			_begin;
			pointer			_end;
			size_t			_size;
			size_t			_capacity;
	};
}

#endif
