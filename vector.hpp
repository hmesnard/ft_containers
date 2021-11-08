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

			template<class U>
			class Viterator : public ft::iterator<std::random_access_iterator_tag, T>
			{
				public:

					//typedef inheritance with templates
					typedef  typename ft::iterator<std::random_access_iterator_tag, U>::value_type			value_type;
					typedef  typename ft::iterator<std::random_access_iterator_tag, U>::difference_type		difference_type;
					typedef  typename ft::iterator<std::random_access_iterator_tag, U>::pointer				pointer;
					typedef  typename ft::iterator<std::random_access_iterator_tag, U>::reference			reference;
					typedef  typename ft::iterator<std::random_access_iterator_tag, U>::iterator_category	iterator_category;

					Viterator() : ptr(NULL) {}
					Viterator(Viterator const & src) : ptr(src.ptr) {}
					Viterator(pointer ptr) : ptr(ptr) {}
					virtual ~Viterator() {}

					Viterator &	operator=(Viterator const & rhs) {
						this->ptr = rhs.ptr;
						return (*this);
					}

					bool	operator==(Viterator const &rhs) const { return (this->ptr == rhs.ptr); }
					bool	operator!=(Viterator const &rhs) const { return (this->ptr != rhs.ptr); }
					bool	operator<(Viterator const &rhs) const { return (this->ptr < rhs.ptr); }
					bool	operator>(Viterator const &rhs) const { return (this->ptr > rhs.ptr); }
					bool	operator<=(Viterator const &rhs) const { return (this->ptr <= rhs.ptr); }
					bool	operator>=(Viterator const &rhs) const { return (this->ptr >= rhs.ptr); }

					reference	operator*() const { return (*(this->ptr)); }
					pointer		operator->() const { return (this->ptr); }
					reference	operator[](int n) const { return (*(this->ptr + n)); }

					Viterator &	operator++() {
						ptr++;
						return (*this);
					}
					Viterator		operator++(int) {
						Viterator	ret = *this;
						++*this;
						return (ret);
					}
					Viterator &	operator--() {
						ptr--;
						return (*this);
					}
					Viterator		operator--(int) {
						Viterator	ret = *this;
						--*this;
						return (ret);
					}

					Viterator		operator+(int n) {
						Viterator	ret = *this;
						ret.ptr += n;
						return (ret);
					}
					Viterator		operator-(int n) {
						Viterator	ret = *this;
						ret.ptr -= n;
						return (ret);
					}
					difference_type				operator-(Viterator const & rhs) { return (this->ptr - rhs.ptr); }

					Viterator &	operator+=(int n) {
						this->ptr += n;
						return (*this);
					}
					Viterator &	operator-=(int n) {
						this->ptr -= n;
						return (*this);
					}

				private:
					pointer	ptr;
			};

			typedef Viterator<value_type>									iterator;
			typedef Viterator<const value_type>								const_iterator;
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
				this->resize(static_cast<size_type>(last - first));
				InputIterator it2 = first;
				for(iterator it1 = this->begin(); it2 != last; it1++)
				{
					this->_alloc.construct(&(*it1), *it2);
					it2++;
				}
			}
			void assign(size_type n, const value_type& val) { //des trucs a destroy ici
				this->resize(n);
				for(iterator it = this->begin(); it != this->end(); it++)
					this->_alloc.construct(&(*it), val);//*it = val;
			}
			void push_back(const value_type& val) { this->resize(this->_size + 1, val); }
			void pop_back() { this->resize(this->_size - 1); }
			iterator insert(iterator position, const value_type& val) {
				this->insert(position, 1, val);
				return (position);
			}
			void insert(iterator position, size_type n, const value_type& val) {
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_capacity * 2);
				//std::cout << static_cast<size_type>(position - this->begin()) << std::endl; valeur absurde
				for(size_type i = this->_size - 1; i > static_cast<size_type>(position - this->begin()); i--)
				{
					//std::cout << "a" << std::endl;
					this->_alloc.construct(this->_begin + i + n, this->_begin[i]);
					this->_alloc.destroy(this->_begin + i);
				}
				//PV
				for(size_type i = 0; i < n; i++)
					this->_alloc.construct(&(*position) + i, val);
				this->_size += n;
			}
			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
				size_type	n = static_cast<size_type>(last - first);
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_capacity * 2);
				for(size_type i = this->_size - 1; i > static_cast<size_type>(position - this->begin()); i--)
				{
					this->_alloc.construct(this->_begin + i + n, this->_begin[i]);
					this->_alloc.destroy(this->_begin + i);
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
}

#endif
