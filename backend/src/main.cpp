#include <iostream>
#include "Caine.h"
#include "Pisica.h"
#include "CameraPremium.h"
#include "Rezervare.h"

int main() {
    Caine rex("Rex", "Ciobanesc German", "Mascul", 5, "Alergic la pui", true);
    Pisica tom("Tom", "Europeana", "Mascul", 3, "Nu are", true);
    CameraPremium camera(1);

    try {
        Rezervare r1(&rex, &camera, 3);
        std::cout << "Rezervare reusita pentru " << rex.getNume()
                  << ", total: " << r1.calculeazaTotal() << " lei\n";

        try {
            Rezervare r2(&tom, &camera, 2);
        } catch (const std::exception& e) {
            std::cout << "Eroare: " << e.what() << "\n";
        }

        r1.anuleaza();
        std::cout << "Rezervarea lui Rex a fost anulata\n";

        Rezervare r3(&tom, &camera, 2);
        std::cout << "Rezervare reusita pentru " << tom.getNume()
                  << ", total: " << r3.calculeazaTotal() << " lei\n";
    } catch (const std::exception& e) {
        std::cout << "Eroare neasteptata: " << e.what() << "\n";
    }
    return 0;
}