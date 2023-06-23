#include <digestpp.hpp>
#include "../headers/Account.h"
#include "../headers/Exception.h"

std::set <std::string> Account::accounts;

Account::Account(const std::string& name_, const std::string& password_):name{name_}, password{password_}{
    if(!regexName(name_)){
        throw errorNameContent();
    }
    if(accounts.find(name_) != accounts.end()){
        throw errorNameUsed();
    }
    if(regexPassword(password_) != "passed"){
        throw errorPasswordContent(regexPassword(password_));
    }
    salt = make_salt();
    password = Account::hash_password(password, salt);
    accounts.insert(name);
}


Account& Account::operator=(const Account& other){
    name = other.name;
    password = other.password;
    logged = other.logged;
    salt = other.salt;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Account& ac){
    os << "Numele contului este: " << ac.name << "\n";
    return os;
}


void Account::afisare(std::ostream& os) const{
    os << "Numele contului este: " << name << "\n";
}


void Account::add_review(Season& se, const int& rating){
    if(!logged){
        std::cout << "Nu sunteti conectat\n";
    }
    else if(rating < 0 || rating > 10){
        std::cout << "Valoare invalida pentru rating\n";
    }
    else{
        se.add_review(name, rating);
    }
}

void Account::logIn(const std::string &name_, const std::string &password_) {
    if(accounts.find(name_) == accounts.end() || Account::hash_password(password_, salt) != password){
        throw errorPaswordName();
    }
    else logged = true;
}

void Account::logOut(){
    logged = false;
}

bool Account::regexName(const std::string& name_) {
    for(auto& c: name_){
        if(!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            return false;
    }
    return true;
}

std::string Account::regexPassword(const std::string& password_) {
    bool lmic = false, Lmare = false, nr = false;
    for(auto& c: password_){
        if(c >= '0' && c <= '9') nr = true;
        if(c >= 'a' && c <= 'z') lmic = true;
        if(c >= 'A' && c <= 'Z') Lmare = true;
        if(std::isspace(c)) return "Parola nu trebuie sa contina spatii";
    }
    if(!nr) return "Parola trebuie sa contina cel putin o cifra";
    if(!lmic) return  "Parola trebuie sa contina cel putin o litera mica";
    if(!Lmare) return "Parola trebuie sa contina cel putin o litera mare";
    if(password_.length() < 12) return "Parola trebuie sa contina cel putin 12 charactere";
    return "passed";
}


std::string Account::make_salt(){
    static uint64_t nr = 1u;
    std::string salt;
    auto bytes = static_cast<unsigned char*>(static_cast<void*>(&nr));
    for(unsigned i = 0; i < 16; i++) {
        salt += bytes[i%8];
    }
    ++nr;
    return salt;
}


std::string Account::hash_password(const std::string& plain, const std::string& salt) {
    return digestpp::blake2b(512).set_salt(salt).absorb(plain).hexdigest();
}
