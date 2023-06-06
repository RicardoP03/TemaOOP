#include "../headers/AnimeScript.h"
#include <cmath>

AnimeScript::AnimeScript(const std::string& name_, const std::string& author_, const int& pages, const int& words):
             AnimeInspirationSource(name_, author_), nrPages(pages), avgWordsPerPage(words){
    std::cout << "Scenariul a fost creata\n";
}


AnimeScript::AnimeScript(const AnimeScript& other): AnimeInspirationSource(other),
    nrPages(other.nrPages), avgWordsPerPage(other.avgWordsPerPage){
    std::cout << "Constructor de copiere Novel\n";
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
    return os;
}


AnimeScript::~AnimeScript() {
    std::cout << "Scenariul a fost sters\n";
}


AnimeInspirationSource* AnimeScript::clone() const {
    return new AnimeScript(*this);
}


std::pair<int, int> AnimeScript::getReadingTime(const unsigned int& parte) const{
    int min = nrPages * avgWordsPerPage;
    return {std::ceil(min / 250), std::ceil(min / 150)};
}


std::pair<int, int> AnimeScript::getTotalReadingTime() const {
    return this->getReadingTime(0);
}


