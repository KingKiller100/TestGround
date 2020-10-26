﻿#pragma once
#include "../kStringTypes.hpp"
#include "../StringTypeTraits.hpp"

namespace klib::kFormat::stringify
{
	template<class CharType, typename T
		, typename = std::enable_if_t<std::is_same_v<T, bool>
		|| type_trait::Is_CharType_V<CharType>>
		>
	kString::StringWriter<CharType> StringBool(const bool val)
	{
		std::basic_string_view<CharType> booleanResult;
		if _CONSTEXPR_IF(std::is_same_v<CharType, char>)
			booleanResult = val ? "true" : "false";
		else if _CONSTEXPR_IF(std::is_same_v<CharType, wchar_t>)
			booleanResult = val ? L"true" : L"false";
		else if _CONSTEXPR_IF(std::is_same_v<CharType, char16_t>)
			booleanResult = val ? u"true" : u"false";
		else if _CONSTEXPR_IF(std::is_same_v<CharType, char32_t>)
			booleanResult = val ? U"true" : U"false";
#ifdef __cpp_char8_t
		else if _CONSTEXPR_IF(std::is_same_v<CharType, char8_t>)
			booleanResult = val ? u8"true" : u8"false";
#endif

		return booleanResult;
	}
	
}
