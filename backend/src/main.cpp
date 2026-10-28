#include <iostream>
#include <memory>
#include <vector>
#include "Caine.h"
#include "Pisica.h"
#include "CameraStandard.h"
#include "CameraPremium.h"

int main()
{
     std::vector<std::unique_ptr<Animal>> animale;
     animale.push_back(std::make_unique<Caine>(
          "Pit", "Bichon", "Mascul",3,"Alergic la pliculete", true));
     animale.push_back(std::make_unique<Pisica>(
          "Puffy", "British", "Femela",7,"Nu are", true));
     
     for( const auto& a : animale)
     {
          std::cout<< a->tip() <<" : "<<a->getNume()<<" ( " <<a->getRasa()<<" , "<<a->getVarsta()<<" ani)\n";
     }

     std::vector<std::unique_ptr<Camera>> camere;
     camere.push_back(std::make_unique<CameraStandard>(1));
     camere.push_back(std::make_unique<CameraStandard>(2));
     camere.push_back(std::make_unique<CameraPremium>(3));

     camere[0]->ocupa();
     for (const auto& c : camere) {
          std::cout << "Camera " << c->getNumar()
                    << " (" << c->tip() << ") - "
                    << c->pretPeNoapte() << " lei/noapte - "
                    << (c->getOcupata() ? "ocupata" : "libera") << "\n";
     }
     return 0;    


     return 0;
}    