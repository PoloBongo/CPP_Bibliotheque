#include "Container.h"

void affichertableau()
{
    Container<int, double> tableau;

    tableau.ajouterValeur(42);
    tableau.ajouterValeur(50);
    tableau.ajouterValeur(3.14159);

    std::cout << tableau.afficher<int>(0) << std::endl;
    std::cout << tableau.afficher<int>(1) << std::endl;
    std::cout << tableau.afficher<double>(2) << std::endl;

    std::cout << "Vector size: " << tableau.getTailleTableau() << std::endl;
}