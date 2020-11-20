#include "Testing/TesterManager.hpp"

#include <iostream>

int main()
{
	auto& testMan = kTest::TesterManager::Get();
	testMan.Initialize();
	testMan.InitializeMaths();
	testMan.InitializeUtility();
	testMan.InitializeTemplates();
	testMan.RunAll();
	testMan.RunPerformanceTests();
	testMan.Shutdown();

	std::cin.get();

	return 0;
}
