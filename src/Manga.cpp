#include "../headers/Manga.h"
#include <cmath>

Manga::Manga(const std::string &name_, const std::string& author_, const std::string& illustrator_, const std::string& artStyle_):
    AnimeInspirationSource(name_, author_), illustrator(illustrator_), artStyle(artStyle_){
    std::cout << "Seria Manga a fost creata\n";
}

Manga::Manga(const Manga& other): AnimeInspirationSource(other), illustrator(other.illustrator), artStyle(other.artStyle){
    std::cout << "Constructor de copiere Manga\n";
}

Manga& Manga::operator=(const Manga& other){
    if(this != &other){
        AnimeInspirationSource::operator=(other);
        illustrator = other.illustrator;
        artStyle = other.artStyle;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, Manga& mg){
    mg.afisare(os, "Manga");
    os << "Seria este ilustrata de " << mg.illustrator << " in stilul " << mg.artStyle << "\n";
    os << "Seria are " << mg.chapters.size() << " capitole\n";
    for(unsigned int i = 0; i < mg.chapters.size(); i++){
        os << "Capitolul " << i + 1 << ": " << mg.chapters[i] << "\n";
        os << "Capitolul are " << mg.chapterDetails[i].first << " pagini si " << mg.chapterDetails[i].second << " panele\n";
    }
    return os;
}
Manga::~Manga(){
    std::cout << "Seria Manga a fost stearsa\n";
}

void Manga::addContent(const std::string& nume_, const int& pagini, const int& panele) {
    chapters.push_back(nume_);
    chapterDetails.emplace_back(pagini, panele);
}


std::pair<int, int> Manga::getReadingTime(const unsigned int& parte) const {
    if(parte < 1 && parte > chapterDetails.size()){
        std::cout << "Capitolul nu exista\n";
        return {0, 0};
    }
    int min = chapterDetails[parte - 1].first / 8 + chapterDetails[parte - 1].second / 12;
    return {std::ceil(min * 3 / 4), std::ceil(min * 5 / 4)};
}


std::pair<int, int> Manga::getTotalReadingTime() const {
    std::pair<int, int> aux = {0, 0};
    for(unsigned int i = 0; i < chapterDetails.size(); i++){
        aux.first += getReadingTime(i + 1).first;
        aux.second += getReadingTime(i + 1).second;
    }
    return aux;
}



AnimeInspirationSource* Manga::clone() const{
    return new Manga(*this);
}