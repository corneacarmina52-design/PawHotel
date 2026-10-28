#include <iostream>
#include "httplib.h"

int main() {
    httplib::Server server;

    server.set_mount_point("/", "frontend");

    server.Get("/api/salut", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"mesaj\": \"Salut de la PawHotel!\"}", "application/json");
    });

    std::cout << "Server pornit pe http://localhost:8080\n";
    server.listen("localhost", 8080);
    return 0;
}