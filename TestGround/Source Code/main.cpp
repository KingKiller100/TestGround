#include "TestManagerWrapper.hpp"

#include <Utility/String/kToString.hpp>
#include <iostream>

int main()
{
	const auto wstring = klib::ToString<wchar_t>(1, L"two", 3, 2.5);
	
	test::TestManagerWrapper::Init();
	test::TestManagerWrapper::RunAll();
	test::TestManagerWrapper::ClearAll();
	std::wclog << wstring;
	std::cin.get();
	
	return 0;
}