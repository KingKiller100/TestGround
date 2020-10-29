#include "ToString.hpp"
#include "Tests/IdentityTest.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
	const auto* const txt = "test txt";
	const auto ull = 8680488060ull;
	bool res = false;

	const std::string numStr(" -150 ");
	const auto strTo = klib::kString::StrTo<int>(numStr);
	
	const DummyString<char> dummy("Get Money Fuck Bitches"); // Custom type
	
	const std::string s("pudding");

	constexpr std::string_view data("*blue*");
	constexpr std::string_view search("*");
	const unsigned num = 189'000;

	if (!test::IdentityTest::Run())
		throw std::runtime_error("Identity test failed");

	
	for (auto i = 0ull; i < 5; ++i)
	{
		const auto str = klib::kFormat::ToString("{0}: {1:2}: {2:5} - {3} - {4}", dummy, ull, 120.985f, 24, false);
		const auto str0 = klib::kFormat::ToString("{0}: {1:2} {2} 0x{3:8} {4}", "w", 120.0f, 'l', &dummy, search);
		const auto str1 = klib::kFormat::ToString("{0} {1:2}: string {1} {3} {2:4}", txt, 120.75f, 60u, res);
		const auto str2 = klib::kFormat::ToString("%s %s string %f %u %d %s", txt, "foo", 120.0, 60u, 100, data);
		const auto str3 = klib::kFormat::ToString(L"Const unsigned int : {0}", num);
		const auto str4 = klib::kFormat::ToString(L"Const unsigned int pointer: 0x{0}", &num);
		const auto str5 = klib::kFormat::ToString(U"Bool pointer: 0x{0}", &res);

		res = !res;

		std::cout << str << '\n';
		std::cout << str2 << '\n';
		std::wcout << str3 << '\n';
		std::wcout << str4 << '\n';
		std::wcout << '\n';
	}
	std::cout << std::endl;
	std::cin.get();
	return EXIT_SUCCESS;
}