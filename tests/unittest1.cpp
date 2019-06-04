#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Applicapteur
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Date date1 = Date(1980,4,29,14,5,56);
			Date date2 = Date(1980, 5, 29, 14, 5, 56);

			Assert::AreEqual(
				date1<date2,
				true);
		}

	};
}