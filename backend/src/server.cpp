#include <iostream>
#include <mutex>          // std::mutex: protejează datele când vin mai multe cereri deodată
#include "httplib.h"
#include "AuthService.h"

int main() {
    httplib::Server server;   // serverul web
    AuthService auth;         // serviciul care ține conturile
    std::mutex mtx;           // "lacătul" pentru acces la conturi

    // Servește fișierele HTML/CSS din folderul "frontend"
    server.set_mount_point("/", "frontend");

    // Endpoint de test: GET /api/salut
    // [](...) {...} este o funcție lambda: o funcție fără nume, apelată la fiecare cerere
    server.Get("/api/salut", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"mesaj\": \"Salut de la PawHotel!\"}", "application/json");
    });

    // Endpoint de cont: POST /api/register
    // [&] = lambda-ul poate folosi variabilele din jur (auth, mtx)
    server.Post("/api/register", [&](const httplib::Request& req, httplib::Response& res) {
        // Citește câmpurile trimise de formular
        std::string email = req.get_param_value("email");
        std::string parola = req.get_param_value("parola");

        {
            // Blochează lacătul cât lucrăm cu conturile; se deschide singur la ieșirea din { }
            std::lock_guard<std::mutex> lock(mtx);
            auth.inregistreaza(email, parola);
        }

        // Răspunde cu succes (cod 200) și un mesaj JSON
        res.set_content("{\"mesaj\": \"Cont pregatit!\"}", "application/json");
    });

    std::cout << "Server pornit pe http://localhost:8080\n";
    server.listen("localhost", 8080);   // pornește și așteaptă cereri
    return 0;
}