#include "CppUnitTest.h"
#include "Container.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(UnitTests) {
    public:
        TEST_METHOD(TestContainer) {
            Container<int, float> containerTestUnits;

            containerTestUnits.ajouterValeur(42);
            containerTestUnits.ajouterValeur(1.2f);

            int Taille = containerTestUnits.getTailleTableau();
            int Capacite = containerTestUnits.getCapaciteTableauMemoire();

            Assert::AreEqual(Taille, 2);
            Assert::AreEqual(Capacite, 2);

            Assert::AreEqual(42, containerTestUnits.afficher<int>(0));
            Assert::AreEqual(1.2f, containerTestUnits.afficher<float>(1));
        }

    };
}
