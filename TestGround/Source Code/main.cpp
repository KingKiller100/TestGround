#include "TestManagerWrapper.hpp"

#include <iostream>


int main()
{
	test::TestManagerWrapper::Init();
	test::TestManagerWrapper::RunAll();
	test::TestManagerWrapper::ClearAll();
	
	std::cin.get();
	
	return 0;
}