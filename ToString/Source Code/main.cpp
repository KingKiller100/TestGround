#include "ToString.hpp"

#include <iostream>

#include "Tests/IdentityTest.hpp"

template<class CharType, typename = std::enable_if_t<klib::type_trait::Is_CharType_V<CharType>>>
struct DummyString
{
	using String = std::basic_string<CharType>;
	String string;

	DummyString(String&& text)
		: string(std::forward<String>(text))
	{}

	template<size_t Size>
	DummyString(CharType (&text)[Size])
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

int main()
{
	const auto* const txt = "test txt";
	const auto ull = 8680488060ull;
	bool res = false;

	const DummyString<char> dummy("Get Money Fuck Bitches");
	
	const std::string s("pudding");

	constexpr std::string_view data("*blue*");
	constexpr std::string_view search("*");
	const unsigned num = 189;

	if (!test::IdentityTest::Run())
		throw std::exception();

	
	for (auto i = 0ull; i < 5; ++i)
	{
		const auto str = klib::kFormat::ToString("{0}: {1:2}: {2:5} - {3} - {4}", dummy, ull, 120.985f, 24, false);
		const auto str0 = klib::kFormat::ToString("{0}: {1:2} {2} 0x{3:8} {4}", "w", 120.0f, 'l', &dummy, search);
		const auto str1 = klib::kFormat::ToString("{0} {1:2}: string {1} {3} {2:4}", txt, 120.75f, 60u, res);
		const auto str2 = klib::kFormat::ToString("%s %s string %f %u %d %s", txt, "foo", 120.0, 60u, 100, data);
		const auto str3 = klib::kFormat::ToString(L"Const unsigned int pointer: 0x{0}", &num);
		const auto str4 = klib::kFormat::ToString(U"Bool pointer: 0x{0}", &res);

		res = !res;

		std::cout << str << '\n';
		std::cout << str2 << '\n';
		std::wcout << str3 << '\n';
	}

	std::cin.get();
	return EXIT_SUCCESS;
}