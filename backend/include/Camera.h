#pragma once
#include <string>
#include <stdexcept>

class Camera 
{
protected:
     int numar;
     bool ocupata;
     
public:
     Camera(int numar) : numar(numar), ocupata(false) {}
     virtual ~Camera() = default;
     void ocupa() { 
          if(ocupata){
               throw std::runtime_error("Camera este deja ocupata ");
          }
          ocupata = true;}
     void elibereaza() {
          if(!ocupata)
          {
               throw std::runtime_error("Camera este deja libera ");
          }
          ocupata = false;}
     virtual double pretPeNoapte() const = 0;
     virtual std::string tip() const = 0;
     const int getNumar() const { return numar;}
     const bool getOcupata() const { return ocupata;}

};