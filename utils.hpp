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

	template<>
	struct is_integral<char16_t> : public is_integral_parent<true> {};

	template<>
	struct is_integral<char32_t> : public is_integral_parent<true> {};

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
}

#endif
