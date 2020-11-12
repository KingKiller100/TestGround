#pragma once

namespace test
{
class TestManagerWrapper
{
public:
	static void Init();
	static void ShutDown();
	static void RunAll();
	static void ClearAll();
};
}
