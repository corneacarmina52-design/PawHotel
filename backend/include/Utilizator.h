#pragma once
#include <functional>
#include <string>

class Utilizator {
    std::string email;
    std::string parolaHash;

public:
    static constexpr const char* EMAIL_IMPLICIT = "client@pawhotel.com";
    static constexpr const char* PAROLA_IMPLICITA = "parola123";

    Utilizator(const std::string& email, const std::string& parolaHash)
        : email(email), parolaHash(parolaHash) {}

    const std::string& getEmail() const { return email; }
    const std::string& getParolaHash() const { return parolaHash; }

    bool verificaParola(const std::string& hashIntrodus) const {
        return parolaHash == hashIntrodus;
    }

    static std::string hashParola(const std::string& parola) {
        return std::to_string(std::hash<std::string>{}(parola));
    }
};