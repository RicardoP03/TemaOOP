#include "..\headers\Account.h"

#ifndef MapAccounts
#define MapAccounts
std::map<std::string, std::shared_ptr<Account>> Account::accounts;
#endif

Account::Account(const std::string& name_, const std::string& password_):name{name_}, password{password_}{
    if(!regexName(name_)){
        throw std::runtime_error("Numele trebuie sa contina doar litere si cifre, contul nu a fost creat");
    }
    if(accounts.find(name_) != accounts.end()){
        throw std::runtime_error("Numele este deja folosit");
    }
    if(regexPassword(password_) != "passed"){
        throw std::runtime_error(regexPassword(password_));
    }
    accounts[name_] = std::shared_ptr<Account>(this);
    std::cout << "Contul a fost creat cu succes\n";
}

Account::Account(const Account& other): name{other.name}, password{other.password}, logged{other.logged}{
    std::cout << "Constructor copiere cont\n";
}

Account& Account::operator=(const Account& other){
    name = other.name;
    password = other.password;
    logged = other.logged;
    std::cout << "operator= Account\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Account& ac){
    os << "Numele contului este: " << ac.name << "\n";
    os << "Parola este: " << ac.password << "\n";
    return os;
}

Account::~Account(){
    std::cout<< "Contul a fost sters\n";
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
    if(accounts.find(name_) == accounts.end() || accounts[name_]->password != password_){
        throw std::runtime_error("Numele sau parola gresite");
    }
    else accounts[name_]->logged = true;
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
        if(c == ' ' || c == '\n' || c == '\t') return "Parola nu trebuie sa contina spatii";
    }
    if(!nr) return "Parola trebuie sa contina cel putin o cifra";
    if(!lmic) return  "Parola trebuie sa contina cel putin o litera mica";
    if(!Lmare) return "Parola trebuie sa contina cel putin o litera mare";
    if(password_.length() < 8) return "Parola trebuie sa contina cel putin 8 charactere";
    return "passed";
}

