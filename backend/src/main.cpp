#include <iostream>
#include <memory>
#include <vector>
#include "Caine.h"
#include "Pisica.h"

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
     return 0;
}    