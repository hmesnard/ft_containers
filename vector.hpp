#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template<class T>
	class Viterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:

			typedef  typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef  typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef  typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef  typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef  typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

			Viterator() : ptr(NULL) {}
			Viterator(Viterator const & src) : ptr(src.ptr) {}
			Viterator(pointer ptr) : ptr(ptr) {}
			virtual ~Viterator() {}

			operator Viterator<T const>() const { return (Viterator<T const>(this->ptr)); }

			Viterator &	operator=(Viterator const & rhs) {
				this->ptr = rhs.ptr;
				return (*this);
			}

			template<class T1, class T2>
			friend bool	operator==(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			template<class T1, class T2>
			friend bool	operator!=(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			template<class T1, class T2>
			friend bool	operator<(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			template<class T1, class T2>
			friend bool	operator>(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			template<class T1, class T2>
			friend bool	operator<=(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			template<class T1, class T2>
			friend bool	operator>=(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			template<class T1, class T2>
			friend typename Viterator<T1>::difference_type	operator-(Viterator<T1> const &lhs, Viterator<T2> const &rhs);

			reference	operator*() const { return (*(this->ptr)); }
			pointer		operator->() const { return (this->ptr); }
			reference	operator[](difference_type n) const { return (*(this->ptr + n)); }

			Viterator&	operator++() {
				++ptr;
				return (*this);
			}
			Viterator	operator++(int) {
				Viterator	ret = *this;
				++*this;
				return (ret);
			}
			Viterator&	operator--() {
				--ptr;
				return (*this);
			}
			Viterator	operator--(int) {
				Viterator	ret = *this;
				--*this;
				return (ret);
			}

			Viterator	operator+(difference_type n) const {
				Viterator	ret = *this;
				ret.ptr += n;
				return (ret);
			}
			Viterator	operator-(difference_type n) const {
				Viterator	ret = *this;
				ret.ptr -= n;
				return (ret);
			}

			Viterator&	operator+=(difference_type n) {
				this->ptr += n;
				return (*this);
			}
			Viterator&	operator-=(difference_type n) {
				this->ptr -= n;
				return (*this);
			}

		private:
			pointer	ptr;
	};

	template<class T>
	Viterator<T>	operator+(typename Viterator<T>::difference_type n, Viterator<T> const & rhs) { return (rhs.operator+(n)); }

	template<class T1, class T2>
	typename Viterator<T1>::difference_type	operator-(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr - rhs.ptr); }

	template<class T1, class T2>
	bool	operator==(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr == rhs.ptr); }

	template<class T1, class T2>
	bool	operator!=(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr != rhs.ptr); }

	template<class T1, class T2>
	bool	operator<(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr < rhs.ptr); }

	template<class T1, class T2>
	bool	operator>(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr > rhs.ptr); }

	template<class T1, class T2>
	bool	operator<=(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr <= rhs.ptr); }

	template<class T1, class T2>
	bool	operator>=(Viterator<T1> const &lhs, Viterator<T2> const &rhs) { return (lhs.ptr >= rhs.ptr); }


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
			typedef Viterator<value_type>									iterator;
			typedef Viterator<const value_type>								const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;

			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) {}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) { this->assign(n, val); }
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) : _alloc(alloc), _begin(NULL), _size(0), _capacity(0) { this->assign(first, last); }
			vector(const vector& x) : _begin(NULL), _size(0), _capacity(0) { *this = x; }
			~vector() { this->_alloc.deallocate(this->_begin, this->_capacity); }

			vector&	operator=(const vector& x) {
				this->assign(x.begin(), x.end());
				return (*this);
			}

			iterator 				begin() { return (iterator(this->_begin)); }
			const_iterator			begin() const { return (const_iterator(this->_begin)); }
			iterator 				end() { return (iterator(this->_begin + this->_size)); }
			const_iterator			end() const { return (const_iterator(this->_begin + this->_size)); }
			reverse_iterator		rbegin() { return (reverse_iterator(this->_begin + this->_size)); }
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(this->_begin + this->_size)); }
			reverse_iterator		rend() { return (reverse_iterator(this->_begin)); }
			const_reverse_iterator	rend() const { return (const_reverse_iterator(this->_begin)); }

			size_type	size() const { return (this->_size); }
			size_type	max_size() const { return (this->_alloc.max_size()); }
			void 		resize(size_type n, value_type val = value_type()) {
				if (n > this->_capacity * 2)
					this->reserve(n);
				else if (n > this->_capacity)
					this->reserve(this->_capacity * 2);
				if (n > this->_size)
					for (size_type i = this->_size; i < n; ++i)
						this->_alloc.construct(this->_begin + i, val);
				else
					for (size_type i = n; i < this->_size; ++i)
						this->_alloc.destroy(this->_begin + i);
				this->_size = n;
			}
			size_type	capacity() const { return (this->_capacity); }
			bool		empty() const { return(this->_size == 0); }
			void		reserve(size_type n) {
				if (n > this->_capacity)
				{
					if (n > this->max_size())
						throw (std::length_error("vector::_M_fill_insert"));
					pointer	tmp = this->_alloc.allocate(n);
					for(size_type i = 0; i < this->_size; ++i)
					{
						this->_alloc.construct(tmp + i, this->_begin[i]);
						this->_alloc.destroy(this->_begin + i);
					}
					this->_alloc.deallocate(this->_begin, this->_capacity);
					this->_begin = tmp;
					this->_capacity = n;
				}
			}

			reference		operator[](size_type n) {return (this->_begin[n]); }
			const_reference	operator[](size_type n) const {return (this->_begin[n]); }
			reference		at(size_type n) {
				if (n >= this->_size)
					throw (std::out_of_range("vector::_M_range_check"));
				return (this->_begin[n]);
			}
			const_reference	at(size_type n) const {
				if (n >= this->_size)
					throw (std::out_of_range("vector::_M_range_check"));
				return (this->_begin[n]);
			}
			reference		front() { return (*(this->_begin)); }
			const_reference	front() const { return (*(this->_begin)); }
			reference		back() { return (*(this->_begin + this->_size - 1)); }
			const_reference	back() const { return (*(this->_begin + this->_size - 1)); }

			template<class InputIterator>
			void 	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
				this->resize(0);
				size_type		n = 0;
				InputIterator	tmp = first;
				while (tmp++ != last)
					++n;
				this->resize(n);
				InputIterator it2 = first;
				for(iterator it1 = this->begin(); it2 != last; ++it1)
				{
					this->_alloc.construct(&(*it1), *it2);
					++it2;
				}
			}
			void	assign(size_type n, const value_type& val) {
				this->resize(0);
				this->resize(n);
				for(iterator it = this->begin(); it != this->end(); ++it)
					this->_alloc.construct(&(*it), val);
			}
			void	push_back(const value_type& val) { this->resize(this->_size + 1, val); }
			void	pop_back() { this->resize(this->_size - 1); }
			iterator insert(iterator position, const value_type& val) {
				size_type	pos = static_cast<size_type>(position - this->begin());
				this->insert(position, 1, val);
				return (this->begin() + pos);
			}
			void	insert(iterator position, size_type n, const value_type& val) {
				size_type	pos = static_cast<size_type>(position - this->begin());
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_capacity * 2);
				position = this->begin() + pos;
				vector	v(position, this->end());
				for(iterator it = position; it != this->end(); ++it)
					this->_alloc.destroy(&(*it));
				for(size_type i = 0; i < n; ++i)
					this->_alloc.construct(&(*(position++)), val);
				for(iterator it = v.begin(); it != v.end(); ++it)
					this->_alloc.construct(&(*(position++)), *it);
				this->_size += n;
			}
			template<class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL) {
				size_type	n = 0;
				InputIterator	tmp = first;
				while (tmp++ != last)
					++n;
				size_type	pos = static_cast<size_type>(position - this->begin());
				if (this->_size + n > this->_capacity * 2)
					this->reserve(this->_size + n);
				else if (this->_size + n > this->_capacity)
					this->reserve(this->_capacity * 2);
				position = this->begin() + pos;
				vector	v(position, this->end());
				for(iterator it = position; it != this->end(); ++it)
					this->_alloc.destroy(&(*it));
				for(InputIterator it = first; it != last; ++it)
					this->_alloc.construct(&(*(position++)), *it);
				for(iterator it = v.begin(); it != v.end(); ++it)
					this->_alloc.construct(&(*(position++)), *it);
				this->_size += n;
			}
			iterator	erase(iterator position) { return (this->erase(position, position + 1)); }
			iterator	erase(iterator first, iterator last) {
				for(iterator it = first; it != last; ++it)
					this->_alloc.destroy(&(*it));
				for(iterator it = last; it != this->end(); ++it)
				{
					this->_alloc.construct(&(*(first + static_cast<size_type>(it - last))), *it);
					this->_alloc.destroy(&(*it));
				}
				this->_size -= static_cast<size_type>(last - first);
				return (first);
			}
			void	swap(vector& x) {
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
			void	clear() { this->resize(0); }

			allocator_type	get_allocator() const { return (this->_alloc); }

		private:
			allocator_type	_alloc;
			pointer			_begin;
			size_type		_size;
			size_type		_capacity;
	};

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<T>::const_iterator	lit = lhs.begin();
		typename vector<T>::const_iterator	rit = rhs.begin();
		while (lit != lhs.end() && rit != rhs.end())
		{
			if (*lit != *rit)
				return (false);
			++lit;
			++rit;
		}
		if (lit != lhs.end() || rit != rhs.end())
			return (false);
		return (true);
	}

	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) { return (!(lhs == rhs)); }

	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) { return (!(rhs < lhs)); }

	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) { return (rhs < lhs); }

	template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) { return (!(lhs < rhs)); }

	template<class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) { x.swap(y); }
}

#endif
