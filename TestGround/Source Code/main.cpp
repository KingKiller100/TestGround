#include "Testing/TesterManager.hpp"
#include <Utility/Localization/kLocale.hpp>
#include <iostream>

int main()
{
	klib::kLocale::SetLocale("");

	auto& testMan = kTest::TesterManager::Get();
	testMan.Initialize();
	testMan.InitializeMaths();
	testMan.InitializeUtility();
	testMan.InitializeTemplates();
	testMan.RunAll(std::thread::hardware_concurrency());
	testMan.RunPerformanceTests();
	testMan.Shutdown();

	std::cin.get();

	return 0;
}
