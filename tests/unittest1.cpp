#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Tests_Applicapteur
{		

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			fichiersOuvertstest = controleurtest.initialiserFichiers("C:/Users/herme/OneDrive/Documents/école/3IF/GL/TP_GLUML_3IF/tests/ficMesures.csv", "C:/Users/herme/OneDrive/Documents/école/3IF/GL/TP_GLUML_3IF/tests/ficAttributs.csv", "C:/Users/herme/OneDrive/Documents/école/3IF/GL/TP_GLUML_3IF/tests/ficCapteurs.csv");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(testFichiersOuverts)
			TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(testFichiersOuverts)
		{
			Assert::IsTrue(fichiersOuvertstest);
		}
		
		TEST_CLASS_CLEANUP(ClassCleanup)
		{
			//controleur.destroy();
		}

		TEST_METHOD(TestMethod1)
		{
			Date date1 = Date(1980,4,29,14,5,56);
			Date date2 = Date(1980, 5, 29, 14, 5, 56);

			Assert::AreEqual(
				date1<date2,
				true);
		}

		TEST_METHOD(testCapteurActifTest)
		{
		
			Date date1 = Date(2017, 2, 1, 1, 0, 0);
			Date date2 = Date(2017, 2, 1, 2, 0, 0);

			bool resultat = controleurtest.testCapteurActif("Sensor1", date1, date2);

			Assert::IsTrue(resultat);
		}


	};
}