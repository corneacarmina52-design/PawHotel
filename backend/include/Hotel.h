#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <utility> //pt std::move
#include <memory>
#include "Camera.h"
#include "Animal.h"
#include "Rezervare.h"

class Hotel 
{
     std::vector<std::unique_ptr<Camera>> camere;
     std::vector<std::unique_ptr<Animal>> animale;
     std::vector<std::unique_ptr<Rezervare>> rezervari;

     public:

     void adaugaCamere(std::unique_ptr<Camera> camera)
     {
          camere.push_back(std::move(camera));
     }

     const Animal* adaugaAnimal(std::unique_ptr<Animal> animal)
     {
          animale.push_back(std::move(animal));
          return animale.back().get();
     }
     
     Camera* gasesteCameraLibera(const std::string& tip)
     {
          for ( auto& c : camere)
          {
               if(!c->getOcupata() && c->tip() == tip){
                    return c.get();
               }
          }
          return nullptr;
     }

     Rezervare& rezerva(const Animal* animal, const std::string& tipCamera, int nrNopti)
     {
          Camera* camera = gasesteCameraLibera(tipCamera);
          if(camera == nullptr)
          {
               throw std::runtime_error("Nu exista camera libera de tipul " + tipCamera);
          }
          rezervari.push_back(std::make_unique<Rezervare>(animal, camera, nrNopti));
          return *rezervari.back();
     }     

     void anuleazaRezervarea(size_t index)
     {
          if(index >= rezervari.size())
          {
               throw std::out_of_range("Rezervare inexistenta ");
          }
          rezervari[index]->anuleaza();

     }

     void afiseazaRezervarea() const{
          for ( size_t i = 0; i < rezervari.size(); ++i)
          {
               const auto& r = rezervari[i];
               std::cout<<i<<". "<<r->getAnimal()->getNume()
                    <<" - camera "<<r->getCamera()->getNumar()
                    <<" ( "<<r->getCamera()->tip()<<" ), " 
                    <<r->getNrNopti()<<" nopti, "
                    <<r->calculeazaTotal()<<" lei "
                    <<(r->esteActiva() ? "" : "[ANULATA]")<<"\n";
          }
     }


};