#include "CppUnitTest.h"
#include "GameObjectLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			HelloFromLib();
			Assert::IsTrue(1 + 1 == 2);
		}
	};
}
