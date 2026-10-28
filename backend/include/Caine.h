#pragma once
#include "Animal.h"

class Caine: public Animal{
     bool necesitaPlimbari;
     public:
          Caine(const std::string& nume, const std::string& rasa,
          const std::string& gen, int varsta,
          const std::string& specificatii, bool necesitaPlimbari)
        : Animal(nume, rasa, gen, varsta, specificatii),
          necesitaPlimbari(necesitaPlimbari) {}

          std::string tip() const override { return "Caine";}
          bool getNecesitaPLimbari() const { return necesitaPlimbari;}
};