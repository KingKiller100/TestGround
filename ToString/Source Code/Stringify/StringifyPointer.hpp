#pragma once

#include <array>

#include "StringifyHelper.hpp"
#include "../kStringTypes.hpp"
#include "../StringTypeTraits.hpp"

namespace klib::kFormat::stringify
{
	template<class CharType>
	constexpr std::array<CharType, 16> hex = {
		static_cast<CharType>('0'), static_cast<CharType>('1'), static_cast<CharType>('2'), static_cast<CharType>('3'),
		static_cast<CharType>('4'), static_cast<CharType>('5'), static_cast<CharType>('6'), static_cast<CharType>('7'),
		static_cast<CharType>('8'), static_cast<CharType>('9'), static_cast<CharType>('a'), static_cast<CharType>('b'),
		static_cast<CharType>('c'), static_cast<CharType>('d'), static_cast<CharType>('e'), static_cast<CharType>('f'),
	};

	
	template<class CharType, typename T
		, typename = std::enable_if_t<std::is_pointer_v<T>
		|| type_trait::Is_CharType_V<CharType>>
		>
		kString::StringWriter<CharType> StringifyPointer(const T* ptr, size_t precision)
	{
		if (precision == nPrecision)
			precision = sizeof(size_t) * 2;
		
		kString::StringWriter<CharType> address;
		auto asUint = reinterpret_cast<uintptr_t>(ptr);
		
		while (asUint > 0)
		{
			const auto index = asUint % hex<CharType>.size();
			address.insert(address.begin(), hex<CharType>.at(index));
			asUint /= hex<CharType>.size();
		}
		
		if (precision > address.size())
		{
			const auto count = precision - address.size();
			address.insert(address.begin(), count, '0');
		}
		
		return address;
	}
}
