#include "..\headers\User.h"

User::User(const std::string& name_, const std::string& password_):Account(name_, password_){
    std::cout << "Constructor Admin\n";
}

User::User(const User& other): Account(other){
    std::cout << "Constructor copiere Admin\n";
}

User& User::operator=(const User &other) {
    if(this != &other){
        Account::operator=(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream& os, const User& us){
    os << static_cast<const Account&>(us);
    os << "Contul are rolul de USER\n";
    return os;
}

User::~User() {
    std::cout << "Destructor User\n";
}

std::string User::getPermissions() const {
    std::string a;
    a += "Contul are permisiunile de a:\n";
    a += "-De a adauga review-uri\n";
    a += "-De a viziona un episod\n";
    return a;
}
