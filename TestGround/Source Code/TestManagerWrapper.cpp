#include "TestManagerWrapper.hpp"

#include <Testing/TesterManager.hpp>

namespace test
{
	auto& testMan = kTest::TesterManager::Get();
	
	void TestManagerWrapper::Init()
	{
		//kTest::TesterManager::Get().Initialize();
		testMan.InitializeUtilityTests();
	}

	void TestManagerWrapper::ShutDown()
	{
		testMan.Shutdown();
	}

	void TestManagerWrapper::RunAll()
	{
		testMan.RunAll();
	}

	void TestManagerWrapper::ClearAll()
	{
		testMan.ClearAllTests();
	}
}