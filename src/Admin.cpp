#include "..\headers\Admin.h"

Admin::Admin(const std::string& name_, const std::string& password_):Account(name_, password_){
    std::cout << "Constructor Admin\n";
}

Admin::Admin(const Admin& other): Account(other){
    std::cout << "Constructor copiere Admin\n";
}

Admin& Admin::operator=(const Admin &other) {
    if(this != &other){
        Account::operator=(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream& os, const Admin& ad){
    os << static_cast<const Account&>(ad);
    os << "Contul are rolul de ADMIN\n";
    return os;
}

Admin::~Admin() {
    std::cout << "Destructor Admin\n";
}

void Admin::add_season(Anime& an, Season& se){
    if(logged) {
        an.add_season(se);
    }
    else std::cout << "Nu aveti permisiune pentru aceasta modificare\n";
}

void Admin::add_episode(Season& se, Episode& ep) {
    if(logged) {
        se.add_episode(ep);
    }
    else std::cout << "Nu aveti permisiune pentru aceasta modificare\n";
}

std::string Admin::getPermissions() const {
    std::string a;
    a += "Contul are permisiunile de a:\n";
    a += "-De a adauga review-uri\n";
    a += "-De a viziona un episod\n";
    a += "-De a adauga sezoane la un anime\n";
    a += "-De a adauga episoade la un sezon\n";
    return a;
}