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

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template<class T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public: 

			random_access_iterator() : ptr(NULL) {}
			random_access_iterator(random_access_iterator const & src) : ptr(src.ptr) {}
			random_access_iterator(T *ptr) : ptr(ptr) {}
			virtual ~random_access_iterator();

			random_access_iterator &	operator=(random_access_iterator const & rhs) { 
				this->ptr = rhs.ptr;
				return (*this);
			}

			bool	operator==(random_access_iterator const &rhs) const { return (this->ptr == rhs.ptr); }
			bool	operator!=(random_access_iterator const &rhs) const { return (this->ptr != rhs.ptr); }
			bool	operator<(random_access_iterator const &rhs) const { return (this->ptr < rhs.ptr); }
			bool	operator>(random_access_iterator const &rhs) const { return (this->ptr > rhs.ptr); }
			bool	operator<=(random_access_iterator const &rhs) const { return (this->ptr <= rhs.ptr); }
			bool	operator>=(random_access_iterator const &rhs) const { return (this->ptr >= rhs.ptr); }

			T &	operator*() const { return (*(this->ptr)); }
			/*->*/
			T &	operator[](int n) const { return (*(this->ptr + n)); }

			random_access_iterator &	operator++() {
				ptr++;
				return (*this);
			}
			random_access_iterator		operator++(int) {
				random_access_iterator	ret = *this;
				++*this;
				return (ret);
			}
			random_access_iterator &	operator--() {
				ptr--;
				return (*this);
			}
			random_access_iterator		operator--(int) {
				random_access_iterator	ret = *this;
				--*this;
				return (ret);
			}

			random_access_iterator		operator+(int n) {
				random_access_iterator	ret = *this;
				tmp.ptr += n;
				return (ret);
			}
			random_access_iterator		operator-(int n) {
				random_access_iterator	ret = *this;
				tmp.ptr -= n;
				return (ret);
			}

			random_access_iterator &	operator+=(int n) {
				this->ptr += n;
				return (*this);
			}
			random_access_iterator &	operator-=(int n) {
				this->ptr -= n;
				return (*this);
			}

		private:
			T*	ptr;
	};

	template<class Iterator>
	class iterator_traits
	{
		public:
			typedef Iterator::difference_type	difference_type;
			typedef Iterator::value_type		value_type;
			typedef Iterator::pointer			pointer;
			typedef Iterator::reference			reference;
			typedef Iterator::iterator_category	iterator_category;
	};

	template<class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef random_access_iterator_tag	iterator_category;
	};

	template<class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef random_access_iterator_tag	iterator_category;
	};

	template<class It>
	class reverse_iterator
	{
		public:
			typedef It										iterator_type;
			typedef iterator_traits<It>::iterator_category	iterator_category;
			typedef iterator_traits<It>::value_type			value_type;
			typedef iterator_traits<It>::difference_type	difference_type;
			typedef iterator_traits<It>::pointer			pointer;
			typedef iterator_traits<It>::reference			reference;

			reverse_iterator() : _base() {}
			explicit reverse_iterator(iterator_type it) : _base(it) {}
			reverse_iterator(reverse_iterator<iterator_type> const & rev_it) : _base(rev_it.base()) {}

			iterator_type	base() const { return (this->base); }

			value_type &	operator*() const { return (*(_base--)); }
			/*->*/
			value_type &	operator[](difference_type n) const { return (*(_base - (n + 1))); }

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
			reverse_iterator	operator--() {
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
