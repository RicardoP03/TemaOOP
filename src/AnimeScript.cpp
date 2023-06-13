#include "../headers/AnimeScript.h"
#include <cmath>

AnimeScript::AnimeScript(const std::string& name_, const std::string& author_, const int& pages, const int& words):
             AnimeInspirationSource(name_, author_), nrPages(pages), avgWordsPerPage(words){
}



AnimeScript& AnimeScript::operator=(const AnimeScript& other){
    if(this != &other){
        AnimeInspirationSource::operator=(other);
        nrPages = other.nrPages;
        avgWordsPerPage = other.avgWordsPerPage;
    }
    return *this;
}


std::ostream &operator<<(std::ostream &os, AnimeScript &script) {
    script.afisare(os, "Script");
    std::cout << "Scenariul are " << script.nrPages << " pagini\n";
    std::cout << "Parcurgerea scenariul are dura intre " <<
        script.getTotalReadingTime().first << " si " << script.getTotalReadingTime().second << "\n";
    return os;
}


std::pair<int, int> AnimeScript::getReadingTime(const unsigned int& parte) const{
    if(parte != 1){
        std::cout << "Scenariile nu au decat o parte\n";
        return {0, 0};
    }
    unsigned int min = nrPages * avgWordsPerPage;
    return {std::ceil(min / 250), std::ceil(min / 150)};
}


std::pair<int, int> AnimeScript::getTotalReadingTime() const {
    return this->getReadingTime(1);
}


