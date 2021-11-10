#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include "iterator.hpp"
#include "utils.hpp"
#define PV for(vector<int>::iterator it = this->begin(); it != this->end() + 3; it++) std::cout << *it << std::endl; std::cout << std::endl;
namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;

			class iterator : public ft::iterator<std::random_access_iterator_tag, value_type>
			{
				public:

					typedef  typename ft::iterator<std::random_access_iterator_tag, value_type>::value_type			value_type;
					typedef  typename ft::iterator<std::random_access_iterator_tag, value_type>::difference_type	difference_type;
					typedef  typename ft::iterator<std::random_access_iterator_tag, value_type>::pointer			pointer;
					typedef  typename ft::iterator<std::random_access_iterator_tag, value_type>::reference			reference;
					typedef  typename ft::iterator<std::random_access_iterator_tag, value_type>::iterator_category	iterator_category;

					iterator() : ptr(NULL) {}
					iterator(iterator const & src) : ptr(src.ptr) {}
					iterator(pointer ptr) : ptr(ptr) {}
					virtual ~iterator() {}

					iterator &	operator=(iterator const & rhs) {
						this->ptr = rhs.ptr;
						return (*this);
					}

					bool	operator==(iterator const &rhs) const { return (this->ptr == rhs.ptr); }
					bool	operator!=(iterator const &rhs) const { return (this->ptr != rhs.ptr); }
					bool	operator<(iterator const &rhs) const { return (this->ptr < rhs.ptr); }
					bool	operator>(iterator const &rhs) const { return (this->ptr > rhs.ptr); }
					bool	operator<=(iterator const &rhs) const { return (this->ptr <= rhs.ptr); }
					bool	operator>=(iterator const &rhs) const { return (this->ptr >= rhs.ptr); }

					reference	operator*() const { return (*(this->ptr)); }
					pointer		operator->() const { return (this->ptr); }
					reference	operator[](int n) const { return (*(this->ptr + n)); }

					iterator &	operator++() {
						ptr++;
						return (*this);
					}
					iterator		operator++(int) {
						iterator	ret = *this;
						++*this;
						return (ret);
					}
					iterator &	operator--() {
						ptr--;
						return (*this);
					}
					iterator		operator--(int) {
						iterator	ret = *this;
						--*this;
						return (ret);
					}

					iterator		operator+(difference_type n) const {
						iterator	ret = *this;
						ret.ptr += n;
						return (ret);
					}
					friend iterator	operator+(difference_type n, iterator const & rhs) { //bonne maniere d'implementer cet overload ?
						iterator	ret = rhs;
						ret.ptri += n;
						return (ret);
					}
					iterator		operator-(difference_type n) const {
						iterator	ret = *this;
						ret.ptr -= n;
						return (ret);
					}
					difference_type	operator-(iterator const & rhs) const { return (this->ptr - rhs.ptr); }

					iterator &	operator+=(difference_type n) {
						this->ptr += n;
						return (*this);
					}
					iterator &	operator-=(difference_type n) {
						this->ptr -= n;
						return (*this);
					}
					pointer	getPtr() { return (ptr); }

				private:
					pointer	ptr;
			};

			class const_iterator : public ft::iterator<std::random_access_iterator_tag, const value_type>
			{
				public:

					typedef  typename ft::iterator<std::random_access_iterator_tag, const value_type>::value_type const			value_type;
					typedef  typename ft::iterator<std::random_access_iterator_tag, const value_type>::difference_type	difference_type;
					typedef  typename ft::iterator<std::random_access_iterator_tag, const value_type>::pointer			pointer;
					typedef  typename ft::iterator<std::random_access_iterator_tag, const value_type>::reference			reference;
					typedef  typename ft::iterator<std::random_access_iterator_tag, const value_type>::iterator_category	iterator_category;

					const_iterator() : ptr(NULL) {}
					const_iterator(const_iterator const & src) : ptr(src.ptr) {}
					const_iterator(iterator const & src) : ptr(src.getPtr()) {}
					const_iterator(pointer ptr) : ptr(ptr) {}
					virtual ~const_iterator() {}

					const_iterator &	operator=(const_iterator const & rhs) {
						this->ptr = rhs.ptr;
						return (*this);
					}

					bool	operator==(const_iterator const &rhs) const { return (this->ptr == rhs.ptr); }
					bool	operator!=(const_iterator const &rhs) const { return (this->ptr != rhs.ptr); }
					bool	operator<(const_iterator const &rhs) const { return (this->ptr < rhs.ptr); }
					bool	operator>(const_iterator const &rhs) const { return (this->ptr > rhs.ptr); }
					bool	operator<=(const_iterator const &rhs) const { return (this->ptr <= rhs.ptr); }
					bool	operator>=(const_iterator const &rhs) const { return (this->ptr >= rhs.ptr); }

					reference	operator*() const { return (*(this->ptr)); }
					pointer		operator->() const { return (this->ptr); }
					reference	operator[](int n) const { return (*(this->ptr + n)); }

					const_iterator &	operator++() {
						ptr++;
						return (*this);
					}
					const_iterator		operator++(int) {
						const_iterator	ret = *this;
						++*this;
						return (ret);
					}
					const_iterator &	operator--() {
						ptr--;
						return (*this);
					}
					const_iterator		operator--(int) {
						const_iterator	ret = *this;
						--*this;
						return (ret);
					}

					const_iterator		operator+(difference_type n) const {
						const_iterator	ret = *this;
						ret.ptr += n;
						return (ret);
					}
					friend const_iterator	operator+(difference_type n, const_iterator const & rhs) { //bonne maniere d'implementer cet overload ?
						const_iterator	ret = rhs;
						ret.ptri += n;
						return (ret);
					}
					const_iterator		operator-(difference_type n) const {
						const_iterator	ret = *this;
						ret.ptr -= n;
						return (ret);
					}
					difference_type	operator-(const_iterator const & rhs) const { return (this->ptr - rhs.ptr); }

					const_iterator &	operator+=(difference_type n) {
						this->ptr += n;
						return (*this);
					}
					const_iterator &	operator-=(difference_type n) {
						this->ptr -= n;
						return (*this);
					}

				private:
					pointer	ptr;
			};

			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;

			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) {}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) { this->assign(n, val); }
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) { this->assign(first, last); }
			vector(const vector& x) : _begin(NULL), _size(0), _capacity(0) { *this = x; }
			~vector() { this->_alloc.deallocate(this->_begin, this->_capacity); }

			vector&	operator=(const vector& x) {
				this->assign(x.begin(), x.end());
				return (*this);
			}

			iterator begin() { return (iterator(this->_begin)); }
			const_iterator begin() const { return (const_iterator(this->_begin)); }
			iterator end() { return (iterator(this->_begin + this->_size)); }
			const_iterator end() const { return (const_iterator(this->_begin + this->_size)); }
			reverse_iterator rbegin() { return (reverse_iterator(this->_begin + this->_size)); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->_begin + this->_size)); }
			reverse_iterator rend() { return (reverse_iterator(this->_begin)); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(this->_begin)); }

			size_type size() const { return (this->_size); }
			size_type max_size() const { return (this->_alloc.max_size()); }
			void resize(size_type n, value_type val = value_type()) {
				if (n > this->_capacity * 2)
					this->reserve(n);
				else if (n > this->_capacity)
					this->reserve(this->_capacity * 2);
				if (n > this->_size)
					for (size_type i = this->_size; i < n; i++)
						this->_alloc.construct(this->_begin + i, val);
				else
					for (size_type i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_begin + i);
				this->_size = n;
			}
			size_type capacity() const { return (this->_capacity); }
			bool empty() const { return(this->_size == 0); }
			void reserve(size_type n) {
				if (n > this->_capacity)
				{
					pointer	tmp = this->_alloc.allocate(n);
					for(size_type i = 0; i < this->_size; i++)
					{
						this->_alloc.construct(tmp + i, this->_begin[i]);
						this->_alloc.destroy(this->_begin + i);
					}
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_begin = tmp;
					this->_capacity = n;
				}
			}

			reference operator[](size_type n) {return (this->_begin[n]); }
			const_reference operator[](size_type n) const {return (this->_begin[n]); }
			reference at(size_type n) {
				if (n >= this->_size)
					throw (std::out_of_range("vector::_M_range_check"));
				return (this->_begin[n]);
			}
			const_reference at(size_type n) const {
				if (n >= this->_size)
					throw (std::out_of_range("vector::_M_range_check"));
				return (this->_begin[n]);
			}
			reference front() { return (*(this->_begin)); }
			const_reference front() const { return (*(this->_begin)); }
			reference back() { return (*(this->_begin + this->_size - 1)); }
			const_reference back() const { return (*(this->_begin + this->_size - 1)); }

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
				this->resize(0);
				this->resize(static_cast<size_type>(last - first));
				InputIterator it2 = first;
				for(iterator it1 = this->begin(); it2 != last; it1++)
				{
					this->_alloc.construct(&(*it1), *it2);
					it2++;
				}
			}
			void assign(size_type n, const value_type& val) {
				this->resize(0);
				this->resize(n);
				for(iterator it = this->begin(); it != this->end(); it++)
					this->_alloc.construct(&(*it), val);
			}
			void push_back(const value_type& val) { this->resize(this->_size + 1, val); }
			void pop_back() { this->resize(this->_size - 1); }
			iterator insert(iterator position, const value_type& val) {
				this->insert(position, 1, val);
				return (position);
			}
			void insert(iterator position, size_type n, const value_type& val) {
				size_type	pos = static_cast<size_type>(position - this->begin());
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_capacity * 2);
				position = this->begin() + pos;
				for(reverse_iterator rit = this->rbegin(); rit != this->rend(); rit++)
				{
					this->_alloc.construct(&(*(rit)) + n, *rit);
					this->_alloc.destroy(&(*rit));
				}
				for(size_type i = 0; i < n; i++)
					this->_alloc.construct(&(*position) + i, val);
				this->_size += n;
			}
			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
				size_type	n = static_cast<size_type>(last - first);
				size_type	pos = static_cast<size_type>(position - this->begin());
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_capacity * 2);
				position = this->begin() + pos;
				for(reverse_iterator rit = this->rbegin(); rit != this->rend(); rit++)
				{
					this->_alloc.construct(&(*rit) + n, *rit);
					this->_alloc.destroy(&(*rit));
				}
				for(InputIterator it = first; it != last; it++)
					this->_alloc.construct(&(*position) + static_cast<size_type>(it - first), *it);
				this->_size += n;
			}
			iterator erase(iterator position) { return (this->erase(position, position + 1)); }
			iterator erase(iterator first, iterator last) {
				for(iterator it = first; it != last; it++)
					this->_alloc.destroy(&(*it));
				for(iterator it = last; it != this->end(); it++)
				{
					this->_alloc.construct(first + static_cast<size_type>(it - last), *it);
					this->_alloc.destroy(&(*it));
				}
				this->_size -= static_cast<size_type>(last - first);
				return (first);
			}
			void swap(vector& x) {
				allocator_type	tmp_alloc = this->_alloc;
				pointer			tmp_begin = this->_begin;
				size_type		tmp_size = this->_size;
				size_type		tmp_capacity = this->_capacity;

				this->_alloc = x._alloc;
				this->_begin = x._begin;
				this->_size = x._size;
				this->_capacity = x._capacity;

				x._alloc = tmp_alloc;
				x._begin = tmp_begin;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}
			void clear() { this->resize(0); }

			allocator_type get_allocator() const { return (this->_alloc); }

		private:
			allocator_type	_alloc;
			pointer			_begin;
			size_type		_size;
			size_type		_capacity;
	};

	//iterator == const_iterator rchl
}

#endif
