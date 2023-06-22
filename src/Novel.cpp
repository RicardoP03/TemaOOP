#include "../headers/Novel.h"
#include <cmath>

Novel::Novel(const std::string& name_, const std::string& author_): AnimeInspirationSource(name_, author_){}


Novel& Novel::operator=(const Novel& other){
    if(this != &other){
        AnimeInspirationSource::operator=(other);
        volumes = other.volumes;
        bookDetails = other.bookDetails;
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
    std::cout << "Parcurgerea romanului are dura intre " <<
              nv.getTotalReadingTime().first << " si " << nv.getTotalReadingTime().second << "\n";
    return os;
}


void Novel::addContent(const std::string& nume, const std::string& editor, const int& nrpages, const int& avgWordsPage){
    volumes.emplace_back(nume, editor);
    bookDetails.emplace_back(nrpages, avgWordsPage);
}


std::pair<int, int> Novel::getReadingTime(const unsigned int& parte) const{
    if(parte < 1 || parte > bookDetails.size()){
        std::cout << "Volumul nu exista\n";
        return {0, 0};
    }
    int min = bookDetails[parte - 1].first * bookDetails[parte - 1].second;
    return {std::ceil(min / 250), std::ceil(min / 150)};
}


std::pair<int, int> Novel::getTotalReadingTime() const {
    std::pair<int, int> aux = {0, 0};
    for(unsigned int i = 0; i < bookDetails.size(); i++){
        aux.first += getReadingTime(i + 1).first;
        aux.second += getReadingTime(i + 1).second;
    }
    return aux;
}