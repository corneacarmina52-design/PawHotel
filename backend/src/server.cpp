#include <iostream>
#include <mutex>
#include "httplib.h"
#include "AuthService.h"

int main() {
    httplib::Server server;
    AuthService auth;
    std::mutex mtx;

    server.set_mount_point("/", "frontend");

    server.Get("/api/salut", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"mesaj\": \"Salut de la PawHotel!\"}", "application/json");
    });

    server.Post("/api/register", [&](const httplib::Request& req, httplib::Response& res) {
        std::string email = req.get_param_value("email");
        std::string parola = req.get_param_value("parola");

        {
            std::lock_guard<std::mutex> lock(mtx);
            auth.inregistreaza(email, parola);
        }
        res.set_content("{\"mesaj\": \"Cont pregatit!\"}", "application/json");
    });

    std::cout << "Server pornit pe http://localhost:8080\n";
    server.listen("localhost", 8080);
    return 0;
}