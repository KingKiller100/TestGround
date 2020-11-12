#include <Utility/String/kToString.hpp>

#include <iostream>

using namespace klib;

int main()
{
	const auto str = ToString<char>(1, 2, 3, 4, 5);

	std::cout << str << std::endl;
	std::cin.get();
	
	return 0;
}