#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T	type;
	};

	template<bool B, class T = void>
	struct is_integral_parent {
		static const bool value = B;
	};

	template<class T>
	struct is_integral : public is_integral_parent<false> {};

	template<>
	struct is_integral<bool> : public is_integral_parent<true> {};

	template<>
	struct is_integral<char> : public is_integral_parent<true> {};

/*	template<>
	struct is_integral<char16_t> : public is_integral_parent<true> {};

	template<>
	struct is_integral<char32_t> : public is_integral_parent<true> {};
*/
	template<>
	struct is_integral<wchar_t> : public is_integral_parent<true> {};

	template<>
	struct is_integral<signed char> : public is_integral_parent<true> {};

	template<>
	struct is_integral<short int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<long int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<long long int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<unsigned char> : public is_integral_parent<true> {};

	template<>
	struct is_integral<unsigned short int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<unsigned int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<unsigned long int> : public is_integral_parent<true> {};

	template<>
	struct is_integral<unsigned long long int> : public is_integral_parent<true> {};

	template<class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;
			pair() : first(first_type()), second(second_type()) {}
		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
		pair(const first_type& a, const second_type& b) : first(a), second(b) {}
		~pair() {}
			pair&	operator=(const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}

		first_type	first;
		second_type	second;
	};

	template<class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}
}

#endif
