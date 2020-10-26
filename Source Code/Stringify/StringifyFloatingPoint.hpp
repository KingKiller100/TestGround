#pragma once

#include <cstdio>
#include <charconv>
#include <stdexcept>
#include <typeinfo>

#include "../StringConverter.hpp"
#include "../kStringManipulation.hpp"

namespace klib::kFormat::stringify
{
	template<class CharType, typename T
		, typename = std::enable_if_t<std::is_floating_point_v<T>
		|| type_trait::Is_CharType_V<CharType>>
		>
		kString::StringWriter<CharType> StringFloatingPoint(const T val, size_t precision, std::chars_format fmt = std::chars_format::general)
	{
		if (precision == nPrecision)
			precision = 6;

		constexpr auto maxsize = std::numeric_limits<T>::max_exponent10 + 1;
		char buff[maxsize]{};
		char* const end = std::end(buff);
		
#if _HAS_COMPLETE_CHARCONV
		const std::to_chars_result res = std::to_chars(buff, end, val, fmt, static_cast<int>(precision));

		if (res.ec != std::errc{})
		{
			const std::string type = typeid(T).name();
			const std::string n = std::to_string(val);
			throw std::runtime_error("Bad kFormat floating point cast: " + type + " - " + n);
		}

		kString::StringWriter<CharType> str(kString::Convert<CharType>(buff));
		HandleDecimalPrecision(str, precision, CharType('0'));
#else
		const std::string format = "%." + std::to_string(precision) + "f";
		const auto length = _snprintf(buff, maxsize, format.data(), val);
		const auto conv = kString::Convert<CharType>(buff);
		const kString::StringWriter<CharType> str(conv, conv + length);
#endif 

		return str;
	}

}