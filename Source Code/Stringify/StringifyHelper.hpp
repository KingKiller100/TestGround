#pragma once

#include "../kStringManipulation.hpp"


namespace klib::kFormat::stringify
{
	constexpr auto nPrecision = static_cast<size_t>(-1);

	template<typename CharType>
	void PrependPadding(std::basic_string<CharType>& outStr, const size_t minDigits, CharType padding)
	{
		if (outStr.size() >= minDigits)
			return;

		const auto count = minDigits - outStr.size();
		outStr.insert(outStr.begin(), count, padding);
	}

	template<typename CharType>
	void HandleDecimalPrecision(std::basic_string<CharType>& outStr, const size_t precision, CharType padding)
	{
		using namespace kString;

		const auto dotPos = outStr.find(CharType('.'));

		if (dotPos == std::basic_string<CharType>::npos)
		{
			outStr.push_back(CharType('.'));
			outStr.append(precision, CharType('0'));
			return;
		}

		auto decimals = outStr.substr(dotPos);

		if (decimals.size() == precision)
			return;

		if (decimals.size() >= precision)
		{
			const auto lastDigit = decimals[precision + 1];
			if (CharType('4') > lastDigit
				|| CharType('9') <= lastDigit
				)
			{
				--decimals[precision];
			}
			decimals[precision + 1] = CharType('0');
			decimals.erase(decimals.begin() + precision + 2);

			outStr.erase(outStr.begin() + dotPos);
			outStr.append(decimals);
		}
		else // decimal size < precision
		{
			const auto count = precision - decimals.size();
			outStr.append(count, CharType('0'));
		}
	}


}
