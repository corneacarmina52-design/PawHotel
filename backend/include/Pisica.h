#pragma  once
#include "Animal.h"

class Pisica : public Animal{
     bool folosesteLitiera;

     public:
               Pisica(const std::string& nume, const std::string& rasa,
                    const std::string& gen, int varsta,
                    const std::string& specificatii, bool folosesteLitiera)
                    : Animal(nume, rasa, gen, varsta, specificatii),
                    folosesteLitiera(folosesteLitiera) {}
               std::string tip() const override { return "Pisica";}
               bool getFolosesteLitiera() const { return folosesteLitiera;}

};