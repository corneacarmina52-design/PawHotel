#include <iostream>
#include <memory>
#include "Caine.h"
#include "Pisica.h"
#include "CameraStandard.h"
#include "CameraPremium.h"
#include "Hotel.h"

int main() {
    Hotel hotel;

    hotel.adaugaCamere(std::make_unique<CameraStandard>(1));
    hotel.adaugaCamere(std::make_unique<CameraStandard>(2));
    hotel.adaugaCamere(std::make_unique<CameraPremium>(3));

    const Animal* rex = hotel.adaugaAnimal(std::make_unique<Caine>(
        "Rex", "Ciobanesc German", "Mascul", 5, "Alergic la pui", true));
    const Animal* tom = hotel.adaugaAnimal(std::make_unique<Pisica>(
        "Tom", "Europeana", "Mascul", 3, "Nu are", true));

    try {
        hotel.rezerva(rex, "Standard", 3);
        hotel.rezerva(tom, "Standard", 2);
        hotel.rezerva(tom, "Standard", 1);  // nu mai sunt camere standard libere
    } catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }

    hotel.afiseazaRezervarea();

    hotel.anuleazaRezervarea(0);
    hotel.rezerva(tom, "Standard", 1);

    std::cout << "\nDupa anulare si rezervare noua:\n";
    hotel.afiseazaRezervarea();

    return 0;
}