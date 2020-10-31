#pragma once

#include "Macros.hpp"

#include <cstdio>
#include <string>
#include <stdexcept>

#include "StringIdentity.hpp"
#include "StringConverter.hpp"

#if defined (_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable : 4996)

namespace klib::kFormat::stringify
{
	template<typename CharType, typename T, typename ...Ts>
	USE_RESULT constexpr std::basic_string<CharType> Sprintf(const std::basic_string_view<CharType>& format, T arg, Ts ...argPack)
	{
		using SignedSize_t = std::make_signed_t<size_t>;
		
		constexpr SignedSize_t npos(0);

		CharType* buffer = nullptr;
		auto length = npos;

		if _CONSTEXPR_IF(std::is_same_v<CharType, char>)
		{
			length = _snprintf(nullptr, 0, format.data(), Identity<CharType>(arg), Identity<CharType>(argPack)...) + 1;
			if (length <= npos) throw std::runtime_error("Error during char type \"" __FUNCSIG__ "\" formatting: string returned length <= 0");
			buffer = new CharType[length]();
			sprintf_s(buffer, length, format.data(), Identity<CharType>(arg), Identity<CharType>(argPack)...);
		}
		else if _CONSTEXPR_IF(std::is_same_v<CharType, wchar_t>)
		{
			length = _snwprintf(nullptr, 0, format.data(), Identity<CharType>(arg), Identity<CharType>(argPack)...) + 1;
			if (length <= npos) throw std::runtime_error("Error during wchar_t type \"" __FUNCSIG__ "\" formatting: string returned length <= 0");
			buffer = new CharType[length]();
			swprintf_s(buffer, length, format.data(), Identity<CharType>(arg), Identity<CharType>(argPack)...);
		}
		else
		{
			const auto fmt = kString::Convert<wchar_t>(format);
			const auto str = Sprintf<wchar_t>(fmt, Identity<CharType>(arg), Identity<CharType>(argPack)...);
			const auto text = kString::Convert<CharType>(str);
			return text;
		}

		const auto formattedText = std::basic_string<CharType>(buffer, buffer + length - 1);
		delete[] buffer;
		
		return formattedText;
	}
}

#	pragma warning(pop)
#endif