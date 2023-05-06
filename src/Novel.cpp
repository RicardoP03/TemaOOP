#include "../headers/Novel.h"

Novel::Novel(const std::string& name_, const std::string& author_): AnimeInspirationSource(name_, author_){
    std::cout << "Romanul a fost creata\n";
}

Novel::Novel(const Novel& other): AnimeInspirationSource(other){
    std::cout << "Constructor de copiere Novel\n";
}

Novel& Novel::operator=(const Novel& other){
    if(this != &other){
        AnimeInspirationSource::operator=(other);
    }
    return *this;
}

void Novel::afisare(std::ostream& os, const std::string &tp) {
    AnimeInspirationSource::afisare(os, tp);
}

std::ostream& operator<<(std::ostream& os, Novel& nv){
    nv.afisare(os, "Novel");
    return os;
}
Novel::~Novel(){
    std::cout << "Romanul a fost stears\n";
}

void Novel::addContent(const std::string &s) {
    std::string a;
    a = "Volumul " + std::to_string(content.size() + 1) + ": " + s;
    content.push_back(a);
}

AnimeInspirationSource* Novel::clone() const {
    return new Novel(*this);
}