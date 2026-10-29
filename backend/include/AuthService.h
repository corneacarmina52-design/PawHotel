#pragma once
#include <string>
#include <vector>
#include "Utilizator.h"

class AuthService
{
     std::vector<Utilizator> utilizatori;
     bool existaEmail(const std::string& email) const{
          for( const auto& u : utilizatori)
          {
               if( u.getEmail() == email) return true;
          }
          return false;
     }

     public:
          void inregistreaza(std::string email, std::string parola) 
          {
               if(email.empty()) email = Utilizator::EMAIL_IMPLICIT;
               if(parola.empty()) parola= Utilizator::PAROLA_IMPLICITA;

               if(existaEmail(email)) return;

               utilizatori.emplace_back(email, Utilizator::hashParola(parola));

          }

          
};