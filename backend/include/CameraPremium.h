#pragma once
#include "Camera.h"

class CameraPremium: public Camera{
     
     public:
          CameraPremium(int numar)
               : Camera(numar) {}
          
          double pretPeNoapte() const override { return 150.0;}
          std::string tip() const override { return "Premium";}

};