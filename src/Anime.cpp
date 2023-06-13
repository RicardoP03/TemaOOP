#include "../headers/Manga.h"
#include "../headers/Novel.h"
#include "../headers/AnimeScript.h"


template<typename T>
int Anime<T>::idMax = 0;


template<typename T>
Anime<T>::Anime(const std::string& name_, const T& source_) : name(name_), source(source_) {
    idMax++;
    id = idMax;
}


template<typename T>
std::ostream& operator<<(std::ostream& os, Anime<T>& an) {
    os << "Numele Animeului este: " << an.name << "\n";
    os << an.source << "\n";
    os << "Sursa de inspiratie nu a fost precizata\n";
    os << "Animeul are " << an.seasons.size() << " sezoane\n";
    an.ratingUpdate();
    os << "Animeul are ratingul: " << an.rating << "\n";
    os << "Animeul are lungime de: " << an.getLength() << " minute\n";
    os << "Lista sezoanelor:\n\n";
    for(unsigned int i = 0; i < an.seasons.size(); i++){
        os << an.seasons[i] << "\n";
    }
    return os;
}


template<typename T>
int Anime<T>::getLength(){
    int sum = 0;
    for(auto&x : seasons){
        sum += x.getLength();
    }
    return sum;
}


template<typename T>
void Anime<T>::ratingUpdate(){
    long double sum = 0;
    for(auto& x: seasons){
        sum += x.getRating();
    }
    rating = sum / seasons.size();
    std::cout << "Animeul are ratingul: " << rating << "\n";
}


template<typename T>
void Anime<T>::add_season(Season &se){
    if (se.getName() == "Season") {
        std::string aux = "Season " + std::to_string(seasons.size() + 1);
        se.setName(aux);
    }
    seasons.push_back(se);
    rating = rating * (seasons.size() - 1);
    rating += se.getRating();
    rating = rating / seasons.size();
}


template<typename T>
int Anime<T>::getId() const{
    return id;
}
