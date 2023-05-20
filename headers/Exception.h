//
// Created by Ricardo ROG on 5/19/2023.
//

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H
#include <stdexcept>
#include <string>

class errorConstructorAccount: public std::runtime_error{
    using std::runtime_error::runtime_error;
};


class errorPasswordContent: public errorConstructorAccount{
    public:
        explicit errorPasswordContent(const std::string& eroare): errorConstructorAccount("Eroare parola: " + eroare + "\n") {}
};


class errorNameUsed: public errorConstructorAccount{
    public:
        explicit errorNameUsed(): errorConstructorAccount("Eroare Nume: Numele este deja folosit\n") {}
};



class errorNameContent: public errorConstructorAccount{
    public:
        explicit errorNameContent(): errorConstructorAccount("Eroare Nume: Numele trebuie sa contina doar cifre sau litere\n") {}
};



class errorLogIn: public std::runtime_error{
    using std::runtime_error::runtime_error;
};



class errorPaswordName: public errorLogIn{
    public:
        explicit errorPaswordName(): errorLogIn("Eroare: Numele sau parola sunt gresite\n") {}
};

#endif //OOP_EXCEPTION_H
