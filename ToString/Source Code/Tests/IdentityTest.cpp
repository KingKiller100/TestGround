#include "IdentityTest.hpp"

#include "../Stringify/StringIdentity.hpp"

namespace test
{
	using namespace klib::kFormat::stringify;

	bool result = true;

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

	bool IdentityTest::Run()
	{
		return RunIdentityTest()
			&& RunIdentityPtrTest();
	}

	bool IdentityTest::RunIdentityTest()
	{
		result = true;
		
		{
			constexpr std::string_view obj("string_view");
			const auto* ret = Identity<char>(obj);
			result &= std::is_same_v<
				const decltype(obj)::value_type*,
				decltype(ret)>;
		}

		{
			std::string obj("string_view");
			const auto* ret = Identity<char>(obj);
			result &= std::is_same_v<
				const decltype(obj)::value_type*,
				decltype(ret)>;
		}

		{
			const DummyString<char> obj("dummy");
			const auto* ret = Identity<char>(obj);
			result &= std::is_same_v<
				const decltype(obj)::String::value_type*,
				decltype(ret)>;

		}

		{
			const auto* obj = "raw string";
			const auto* ret = Identity<char>(obj);
			result &= std::is_same_v<
				decltype(obj),
				decltype(ret)>;
		}

		{
			const char obj[] = "array string";
			const auto* ret = Identity<char>(obj);
			result &= std::is_same_v<
				decltype(&obj[0]),
				decltype(ret)>;
		}

		return result;
	}

	bool IdentityTest::RunIdentityPtrTest()
	{
		result = true;

		{
			const std::string_view obj("string");
			auto ret = IdentityPtr<char>(obj);
			result &= std::is_same_v<
				decltype(&obj),
				decltype(ret)>;
		}

		{
			const std::string obj("string");
			auto ret = IdentityPtr<char>(obj);
			result &= std::is_same_v<
				decltype(&obj),
				decltype(ret)>;
		}

		{
			const DummyString<char> obj("dummy");
			const auto* ret = IdentityPtr<char>(obj);
			result &= std::is_same_v<
				const decltype(obj)::String*,
				decltype(ret)>;

		}

		{
			const auto* obj = "raw string";
			const auto* ret = IdentityPtr<char>(obj);
			result &= std::is_same_v<
				const char* const*,
				decltype(ret)>;
		}

		{
			const auto scope = 500;
			const auto* obj = &scope;
			const auto* ret = IdentityPtr<char>(obj);
			result &= std::is_same_v<
				const decltype(500)* const*,
				decltype(ret)>;
		}

		{
			const unsigned long obj[] = { 1, 2, 4 };
			auto ret = IdentityPtr<char>(obj);
			result &= std::is_same_v<
				decltype((&obj[0])),
				decltype(ret)>;
		}

		return result;
	}
}
