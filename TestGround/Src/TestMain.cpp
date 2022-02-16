#include <kTest.hpp>
#include <iostream>

#include "Exception/ExceptionsHandler.hpp"

void kLibTest();

void FlushStdStreams();

int main()
{
	try
	{
		klib::kLocale::SetDefaultLocale();
		klib::kCalendar::UsePlatformCalendarInfoSource();
		kLibTest();

		std::cout << "\nPress 'ENTER' to exit...";
		std::cin.get();

		FlushStdStreams();
	}
	catch ( ... )
	{
		std::cerr << "Exception occurred:\n";
		std::cerr << debug::ReportNestedExceptions();
		std::cin.get();
		FlushStdStreams();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void kLibTest()
{
	kTest::TesterManager testMan;
	testMan.Initialize( kTest::TesterManager::InitializationRequest::NoPerformanceTests );
	kTest::InitializeMathsTests( testMan );
	kTest::InitializeUtilityTests( testMan, false );
	kTest::InitializeTemplateTests( testMan );
	testMan.RunAll( kTest::TesterManager::ResourceUtilization::Single );
	//testMan.RunPerformanceTests();
	testMan.Shutdown();
}

void FlushStdStreams()
{
	std::cout.flush();
	std::cerr.flush();
	std::clog.flush();
}
