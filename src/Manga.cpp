#include "../headers/Manga.h"

Manga::Manga(const std::string& name_, const std::string& author_): AnimeInspirationSource(name_, author_){
    std::cout << "Seria Manga a fost creata\n";
}

Manga::Manga(const Manga& other): AnimeInspirationSource(other){
    std::cout << "Constructor de copiere Manga\n";
}

Manga& Manga::operator=(const Manga& other){
    if(this != &other){
        AnimeInspirationSource::operator=(other);
    }
    return *this;
}

void Manga::afisare(std::ostream& os, const std::string &tp) {
    AnimeInspirationSource::afisare(os, tp);
}

std::ostream& operator<<(std::ostream& os, Manga& mg){
    mg.afisare(os, "Manga");
    return os;
}
Manga::~Manga(){
    std::cout << "Seria Manga a fost stearsa\n";
}

void Manga::addContent(const std::string &s) {
    std::string a;
    a = "Capitolul " + std::to_string(content.size() + 1) + ": " + s;
    content.push_back(a);
}

AnimeInspirationSource* Manga::clone() const{
    return new Manga(*this);
}