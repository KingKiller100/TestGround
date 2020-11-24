#include "Testing/TesterManager.hpp"
#include <Utility/String/Tricks/kStringLocale.hpp>


#include <iostream>

int main()
{
	klib::kString::secret::impl::SetLocale("");
	
	auto& testMan = kTest::TesterManager::Get();
	testMan.Initialize();
	// testMan.InitializeMaths();
	testMan.InitializeUtility();
	// testMan.InitializeTemplates();
	testMan.RunAll();
	testMan.RunPerformanceTests();
	testMan.Shutdown();

	std::cin.get();

	return 0;
}
