#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
	template<class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template<class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};

	template<class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};

	template<class It>
	class reverse_iterator
	{
		public:
			typedef It												iterator_type;
			typedef typename iterator_traits<It>::iterator_category	iterator_category;
			typedef typename iterator_traits<It>::value_type		value_type;
			typedef typename iterator_traits<It>::difference_type	difference_type;
			typedef typename iterator_traits<It>::pointer			pointer;
			typedef typename iterator_traits<It>::reference			reference;

			reverse_iterator() : _base() {}
			explicit reverse_iterator(iterator_type it) : _base(it) {}
			reverse_iterator(reverse_iterator<iterator_type> const & rev_it) : _base(rev_it.base()) {}

			iterator_type	base() const { return (this->base); }

			reference	operator*() const { return (*(_base - 1)); }
			pointer		operator->() const { return (_base - 1); } //test ca
			reference	operator[](difference_type n) const { return (*(_base - (n + 1))); }

			reverse_iterator &	operator++() {
				this->_base--;
				return (*this);
			}
			reverse_iterator	operator++(int) {
				reverse_iterator ret = *this;
				this->_base--;
				return (ret);
			}
			reverse_iterator &	operator--() {
				this->_base++;
				return (*this);
			}
			reverse_iterator	operator--(int) {
				reverse_iterator ret = *this;
				this->_base++;
				return (ret);
			}

			reverse_iterator	operator+(difference_type n) const { return (reverse_iterator/*<It>*/(_base - n)); }
			reverse_iterator	operator-(difference_type n) const { return (reverse_iterator/*<It>*/(_base + n)); }

			reverse_iterator &	operator+=(difference_type n) {
				this->_base -= n;
				return (*this);
			}
			reverse_iterator &	operator-=(difference_type n) {
				this->_base += n;
				return (*this);
			}

		private:
			iterator_type	_base;
	};
}

#endif
