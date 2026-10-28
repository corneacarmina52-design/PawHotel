#pragma once
#include <string>

class Camera 
{
protected:
     int numar;
     bool ocupata;
     
public:
     Camera(int numar) : numar(numar), ocupata(false) {}
     virtual ~Camera() = default;
     void ocupa() { ocupata = true;}
     void elibereaza() { ocupata = false;}
     virtual double pretPeNoapte() const = 0;
     virtual std::string tip() const = 0;
     const int getNumar() const { return numar;}
     const bool getOcupata() const { return ocupata;}

};