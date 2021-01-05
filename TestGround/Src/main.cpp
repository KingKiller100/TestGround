#include "Testing/TesterManager.hpp"
#include <Utility/Localization/kLocale.hpp>
#include <Utility/Calendar/kUseCalendarSourceInfo.hpp>
#include <iostream>

int main()
{
	klib::kLocale::SetLocale("");
	klib::kCalendar::UsePlatformCalendarInfoSource();

	auto& testMan = kTest::TesterManager::Get();
	testMan.Initialize();
	testMan.InitializeMaths();
	testMan.InitializeUtility(false);
	testMan.InitializeTemplates();
	testMan.RunAll(std::thread::hardware_concurrency());
	testMan.RunPerformanceTests();
	testMan.Shutdown();

	std::cin.get();

	return 0;
}
