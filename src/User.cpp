#include "../headers/User.h"

User::User(const std::string& name_, const std::string& password_):Account(name_, password_){
    std::cout << "Constructor User\n";
}

User::User(const User& other): Account(other){
    std::cout << "Constructor copiere User\n";
}

User& User::operator=(const User &other) {
    if(this != &other){
        Account::operator=(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream& os, const User& us){
    us.afisare(os);
    os << "Contul are rolul de USER\n";
    return os;
}

User::~User() {
    std::cout << "Destructor User\n";
}

std::string User::getPermissions() const {
    return "Contul are permisiunile de a:\n"
        "-De a adauga review-uri\n"
        "-De a viziona un episod\n";
}
