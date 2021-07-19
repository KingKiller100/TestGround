#include <kLib.hpp>
#include <iostream>

int main()
{
	klib::kLocale::SetLocale("");
	klib::kCalendar::UsePlatformCalendarInfoSource();

	auto* testMan = new kTest::TesterManager{};
	testMan->Initialize(true);
	kTest::InitializeMathsTests(testMan);
	kTest::InitializeUtilityTests(testMan, false);
	kTest::InitializeTemplateTests(testMan);
	testMan->RunAll(std::thread::hardware_concurrency());
	testMan->RunPerformanceTests();
	testMan->Shutdown();

	delete testMan;
	testMan = nullptr;

	std::cout << "\nPress 'ENTER' to exit...";
	std::cout.flush();
	std::cerr.flush();
	std::cin.get();

	return EXIT_SUCCESS;
}
