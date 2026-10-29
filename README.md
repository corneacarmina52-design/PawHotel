# PawHotel

Aplicatie de rezervari pentru un hotel de animale, in c++.

## Ce contine
- ierarhie OOP: Animal (abstracta)->Caine, Pisica;
- Camera standard si premium , cu preturi diferite;
- rezervari cu validare de exceptii;
- clasa hotel care gestioneaza camere, animale si rezervari;
- server web c++(cpp-httpplib) cu o pagina de start si formular de cont(in lucru);

## Cum rulezi
- g++ -std=c++17 -Wall -Ibackend/include backend/src/main.cpp -o hotel
- ./hotel
