#pragma once
#include "StringTypeTraits.hpp"

template<class CharType, typename = std::enable_if_t<klib::type_trait::Is_CharType_V<CharType>>>
struct DummyString
{
	using String = std::basic_string<CharType>;
	String string;

	DummyString(String&& text)
		: string(std::forward<String>(text))
	{}

	template<size_t Size>
	DummyString(CharType(&text)[Size])
		: string(text)
	{}

	DummyString(const CharType* text)
		: string(text)
	{}

	String ToString() const
	{
		return string;
	}
};

namespace test
{
	class IdentityTest
	{
	public:
		static bool Run();

	private:
		static bool RunIdentityTest();
		static bool RunIdentityPtrTest();
	};
}