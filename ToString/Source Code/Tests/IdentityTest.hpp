#pragma once

namespace test
{
	class IdentityTest
	{
	public:
		static bool Run();

	private:
		static bool RunIdentityTest();
		static bool RunIdentityPtrTest();
	};
}