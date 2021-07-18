#include <kLib.hpp>
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

	std::cout << "\nPress 'ENTER' to exit...";
	std::cout.flush();
	std::cerr.flush();
	std::cin.get();

	return EXIT_SUCCESS;
}
