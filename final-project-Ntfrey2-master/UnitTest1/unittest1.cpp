#include "stdafx.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			if (shiploc1[column][row] == true && chosenloc2[column][row] == false) {
				hitCounter1 = 1;
				Assert::AreEqual(hitCounter1, 1);
			}
		}

	};
}