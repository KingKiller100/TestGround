#include "Testing/TesterManager.hpp"

#include <iostream>

int main()
{
	auto& testMan = kTest::TesterManager::Get();
	testMan.Initialize();
	testMan.InitializeUtilityTests();
	testMan.RunAll();
	testMan.Shutdown();

	std::cin.get();

	return 0;
}
