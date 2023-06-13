#include "../headers/Admin.h"

Admin::Admin(const std::string& name_, const std::string& password_): Account(name_, password_){}


Admin& Admin::operator=(const Admin &other) {
    if(this != &other){
        Account::operator=(other);
    }
    return *this;
}


std::ostream &operator<<(std::ostream& os, const Admin& ad){
    ad.afisare(os);
    os << "Contul are rolul de ADMIN\n";
    return os;
}


std::string Admin::getPermissions() const {
    return "Contul are permisiunile de a:\n"
        "-De a adauga review-uri\n"
        "-De a viziona un episod\n"
        "-De a adauga sezoane la un anime\n"
        "-De a adauga episoade la un sezon\n";
}