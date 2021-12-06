#include <kTest.hpp>
#include <iostream>

#include "Exception/ExceptionsHandler.hpp"

void kLibTest();

void FlushOutputs();

int main()
{
	try
	{
		kLibTest();
	}
	catch ( ... )
	{
		std::cerr << "Exception occurred:\n";
		std::cerr << debug::UnwrapNestedExceptions();
	}

	std::cout << "\nPress 'ENTER' to exit...";
	std::cin.get();

	FlushOutputs();

	return EXIT_SUCCESS;
}

void kLibTest()
{
		klib::kLocale::SetDefaultLocale();
		klib::kCalendar::UsePlatformCalendarInfoSource();
	kTest::TesterManager testMan;
	testMan.Initialize( true );
	kTest::InitializeMathsTests( testMan );
	kTest::InitializeUtilityTests( testMan, false );
	kTest::InitializeTemplateTests( testMan );
	testMan.RunAll( std::thread::hardware_concurrency() );
	testMan.RunPerformanceTests();
	testMan.Shutdown();
}

void FlushOutputs()
{
	std::cout.flush();
	std::cerr.flush();
	std::clog.flush();
}
