#include "../headers/Season.h"

Season::Season(std::string&& name_): name{std::move(name_)}{
    std::cout << "Sezonul a fost adaugat\n";
}

Season::Season(const Season&other): name{other.name}, episodes{other.episodes}, reviews{other.reviews},
                                    sumOfRatings{other.sumOfRatings}, nrReviews{other.nrReviews}, rating{other.rating} {
    std::cout << "Constructor copiere Sezon\n";
}

Season& Season::operator=(const Season&other){
    if(this != &other) {
        name = other.name;
        this->episodes = other.episodes;
        this->reviews = other.reviews;
        sumOfRatings = other.sumOfRatings;
        nrReviews = other.nrReviews;
        rating = other.rating;
    }
    std::cout << "operator = copiere Sezon\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Season& sez){
    os << "Numele sezonului este: " << sez.name << "\n";
    os << "Sezonul are " << sez.episodes.size() << " episoade\n";
    os << "Seazonul are ratingul de: " << sez.rating <<  " obtinut din " << sez.nrReviews << " recenzi" << "\n";
    os << "Lista Episoadelor:\n\n";
    for(unsigned int i = 0; i < sez.episodes.size(); i++){
        os << sez.episodes[i] << "\n";
    }
    return os;
}

Season::~Season() {
    std::cout << "Sezonul a fost sters\n";
}

int Season::getLength(){
    int sum = 0;
    for(const auto& x: episodes){
        sum += x.getDuration();
    }
    return sum;
}

void Season::add_episode(Episode& ep){
    if (ep.getName() == "Episode") {
        std::string aux = "Episode " + std::to_string(episodes.size() + 1);
        ep.setName(aux);
    }
    episodes.push_back(ep);
}

void Season::add_review(const std::string& accountName, const int& rate){
    if(reviews.count(accountName) == 0) nrReviews++;
    int oldVal = reviews[accountName];
    reviews[accountName] = rate;
    sumOfRatings += rate - oldVal;
    rating = 1.0 * sumOfRatings / nrReviews;
}

std::string Season::getName(){
    return name;
}

long double Season::getRating() const{
    return rating;
}

void Season::setName(const std::string& newName){
    name = newName;
}


