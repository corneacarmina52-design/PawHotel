#pragma once
#include <stdexcept>
#include "Animal.h"
#include "Camera.h"

class Rezervare{
     const Animal* animal;
     Camera* camera;
     int nrNopti;
     bool activa;

     public:
          Rezervare(const Animal* animal, Camera* camera, int nrNopti)
               : animal(animal), camera(camera), nrNopti(nrNopti)
               {
                    if ( nrNopti <= 0)
                    {
                         throw std::invalid_argument("Numarul de nopti trebuie sa fie pozitiv ");

                    }
                    camera->ocupa();
                    activa = true;
               }

          double calculeazaTotal() const { 
               return nrNopti * camera->pretPeNoapte();
          }
          
          void anuleaza()
          {
               if(!activa)
               {
                    throw std::logic_error("Rezervarea este deja anulata ");
               }
               camera->elibereaza();
               activa = false;
          }

          bool esteActiva() const { return activa;}

          const Animal* getAnimal() const { return animal;}
          const Camera* getCamera() const { return camera;}
          int getNrNopti() const { return nrNopti;}
};