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

		TEST_METHOD(testCapteurActifTest)
		{
			Controleur controleur;
			bool fichiersOuverts = controleur.initialiserFichiers("C:/Users/herme/OneDrive/Documents/école/3IF/GL/TP_GLUML_3IF/tests/ficMesures.csv", "C:/Users/herme/OneDrive/Documents/école/3IF/GL/TP_GLUML_3IF/tests/ficAttributs.csv", "C:/Users/herme/OneDrive/Documents/école/3IF/GL/TP_GLUML_3IF/tests/ficCapteurs.csv");
			Assert::IsTrue(fichiersOuverts);
			Date date1 = Date(2017, 2, 1, 1, 0, 0);
			Date date2 = Date(2017, 2, 1, 2, 0, 0);
			bool resultat = controleur.testCapteurActif("Sensor1", date1, date2);

			//Assert::IsTrue(resultat);
		}

	};
}