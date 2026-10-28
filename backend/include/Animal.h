#pragma once
#include <string>

class Animal
{
     protected:
          std::string nume;
          std::string rasa;
          std::string gen;
          int varsta;
          std::string specificatii;
     public:
          Animal(const std::string& nume, const std::string& rasa, const std::string& gen , int varsta, const std::string& specificatii ) : nume(nume) , rasa(rasa), gen(gen), varsta(varsta), specificatii(specificatii){}
          virtual ~Animal() = default;
          const std::string& getNume() const { return nume;}
          const std::string& getRasa() const { return rasa;}
          const std::string& getGen() const { return gen;}
          const std::string& getSpecificatii() const { return specificatii;}
          const int getVarsta() const { return varsta;}

          virtual std::string tip() const=0;
};

