#include "ToString.hpp"

#include <iostream>

int main()
{
	const auto* const txt = "test txt";
	bool res = false;
	for (auto i = 0ull; i < 5; ++i)
	{
		const auto str = klib::kFormat::ToString("{0}: {1:2}: {2:5}\n", &res, 8680488060ull, 120.985f, 24);
		// const auto str = klib::kFormat::ToString("{0}: {1:2}\n", "w", 120.0f);
		// const auto str1 = klib::kFormat::ToString("{0} {1:2}: string {1} {3} {2:4} \n", txt, 120.0f, 60u, res);
		// const auto str2 = klib::kFormat::ToString("%s %s string %f %u", txt, "foo", 120.0, 60u);
		//const auto str3 = klib::kFormat::ToString(L"Const unsigned int pointer: 0x{0}", u);
		//const auto str4 = klib::kFormat::ToString(U"Bool pointer: 0x{0}", &res);

		res = !res;

		std::cout << str << '\n';
		//std::cout << str2 << '\n';
		//std::wcout << str3 << '\n';
		//std::cout << str4 << '\n';
	}
	//std::wcout << str << std::endl;
	std::cin.get();
	return EXIT_SUCCESS;
}