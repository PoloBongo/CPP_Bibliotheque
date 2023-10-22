#include <iostream>

template <typename... Types>
class Container {
private:
    void** Tableau;
    size_t tailleTableau;
    size_t capaciteTableauMemoire;

public:
    Container() : Tableau(nullptr), tailleTableau(0), capaciteTableauMemoire(0) {}

    template <typename T>
    void ajouterValeur(const T& value) {
        if (tailleTableau >= capaciteTableauMemoire) {
            if (capaciteTableauMemoire == 0) {
                capaciteTableauMemoire = 1;
                Tableau = new void* [capaciteTableauMemoire];
            }
            else {
                capaciteTableauMemoire *= 2;
                void** newTableau = new void* [capaciteTableauMemoire];
                for (size_t i = 0; i < tailleTableau; ++i) {
                    newTableau[i] = Tableau[i];
                }
                delete[] Tableau;
                Tableau = newTableau;
            }
        }

        Tableau[tailleTableau] = new T(value);
        tailleTableau++;
    }

    void deleteValeur(size_t index) {
        if (index < tailleTableau) {
            for (size_t i = index; i < tailleTableau - 1; i++) {
                Tableau[i] = Tableau[i + 1];
            }
            tailleTableau--;
        }
        else {
            throw std::out_of_range("L'index n'est pas présente dans le Tableau");
        }
    }

    template <typename T>
    T& afficher(size_t index) {
        if (index >= tailleTableau || Tableau[index] == nullptr) {
            throw std::runtime_error("Soit la valeur a été supprimé ou la valeur n'est pas présente dans le tableau");
        }
        return *reinterpret_cast<T*>(Tableau[index]);
    }

    size_t getTailleTableau() const {
        return tailleTableau;
    }

    size_t getCapaciteTableauMemoire() const {
        return capaciteTableauMemoire;
    }

    ~Container() {
        delete[] Tableau;
    }
};
