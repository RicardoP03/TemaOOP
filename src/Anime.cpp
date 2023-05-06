#include "..\headers\Anime.h"

Anime::Anime(const std::string& name_, AnimeInspirationSource* source_): name{name_}, source{source_}{
    std::cout << "Animeul a fost adaugat\n";
}

Anime::Anime(const Anime& an){
    name = an.name;
    source = an.source->clone();
    seasons.clear();
    for(auto& s: an.seasons){
        seasons.push_back(s->clone());
    }
    rating = an.rating;
    std::cout << "Constructor copiere Anime\n";
}

Anime& Anime::operator=(const Anime& an){
    if(this != &an) {
        name = an.name;
        delete source;
        source = an.source->clone();
        seasons.clear();
        for (auto &s: an.seasons) {
            seasons.push_back(s->clone());
        }
        rating = an.rating;
    }
    std::cout << "operator = copiere Anime\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Anime& an){
    os << "Numele Animeului este: " << an.name << "\n";
    os << *an.source << "\n";
    os << "Animeul are " << an.seasons.size() << " sezoane\n";
    os << "Animeul are ratingul: " << an.rating << "\n";
    os << "Lista sezoanelor:\n\n";
    for(auto& x: an.seasons){
        os << *x << "\n";
    }
    return os;
}

Anime::~Anime(){
    std::cout << "Animeul a fost sters\n";
}

int Anime::getLength(){
    int sum = 0;
    for(auto&x : seasons){
        sum += x->getLength();
    }
    return sum;
}

void Anime::ratingUpdate(){
    long double sum = 0;
    for(auto& x: seasons){
        x->getRating();
    }
    rating = sum / seasons.size();
    std::cout << "Animeul are ratingul: " << rating << "\n";
}

void Anime::add_season(Season &se){
    if (se.getName() == "Season") {
        std::string aux = "Season " + std::to_string(seasons.size() + 1);
        se.setName(aux);
    }
    seasons.push_back(&se);
    rating = rating * (seasons.size() - 1);
    rating += se.getRating();
    rating = rating / seasons.size();
}

std::string Anime::getName(){
    return name;
}
