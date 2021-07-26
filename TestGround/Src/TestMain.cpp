#include <kLib.hpp>
#include <iostream>

int main()
{
	klib::kLocale::SetDefaultLocale();
	klib::kCalendar::UsePlatformCalendarInfoSource();

	auto testMan = kTest::TesterManager{};
	testMan.Initialize(true);
	kTest::InitializeMathsTests(testMan);
	kTest::InitializeUtilityTests(testMan, false);
	kTest::InitializeTemplateTests(testMan);
	testMan.RunAll(std::thread::hardware_concurrency());
	testMan.RunPerformanceTests();
	testMan.Shutdown();

	std::cout << "\nPress 'ENTER' to exit...";
	std::cout.flush();
	std::cerr.flush();
	std::cin.get();

	return EXIT_SUCCESS;
}
