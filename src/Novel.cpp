#include "../headers/Novel.h"
#include <cmath>

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


std::ostream& operator<<(std::ostream& os, Novel& nv){
    nv.afisare(os, "Novel");
    os << "Seria are " << nv.volumes.size() << " volume:\n";
    for(unsigned int i = 0; i < nv.volumes.size(); i++){
        os << "Volumul " << i + 1<< ": " << nv.volumes[i].first << "\n";
        os << "A avut ca editor pe: " << nv.volumes[i].second << "\n";
        os << "Voluml are " <<  nv.bookDetails[i].first << " pagini si o medie de " << nv.bookDetails[i].second << " cuvinte pe pagina\n";
    }
    return os;
}


Novel::~Novel(){
    std::cout << "Romanul a fost stears\n";
}

void Novel::addContent(const std::string& nume, const std::string& editor, const int& nrpages, const int& avgWordsPage){
    volumes.emplace_back(nume, editor);
    bookDetails.emplace_back(nrpages, avgWordsPage);
}

AnimeInspirationSource* Novel::clone() const {
    return new Novel(*this);
}

std::pair<int, int> Novel::getReadingTime(const unsigned int& parte) const{
    int min = bookDetails[parte].first * bookDetails[parte].second;
    return {std::ceil(min / 250), std::ceil(min / 150)};
}

std::pair<int, int> Novel::getTotalReadingTime() const {
    std::pair<int, int> aux = {0, 0};
    for(unsigned int i = 0; i < bookDetails.size(); i++){
        aux.first += getReadingTime(i).first;
        aux.second += getReadingTime(i).second;
    }
    return aux;
}