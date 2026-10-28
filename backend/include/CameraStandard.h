#pragma once
#include "Camera.h"

class CameraStandard : public Camera{
     
     public:
          CameraStandard(int numar)
               : Camera(numar) {}
          
          double pretPeNoapte() const override { return 80.0;}
          std::string tip() const override { return "Standard";}

};