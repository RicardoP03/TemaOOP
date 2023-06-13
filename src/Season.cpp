#include "../headers/Season.h"

int Season::idMax = 0;

Season::Season(const std::string& name_): name{name_}{
    idMax++;
    id = idMax;
}


Season& Season::operator=(const Season&other){
    if(this != &other) {
        id = other.id;
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


int Season::getId() const {
    return id;
}


void SeasonEpiosdeFactory::addEpisodes(Season &s, const unsigned int &nr) {
    for(unsigned int i = 0; i < nr; i++){
        auto* ep = new Episode("Episode", 24);
        s.add_episode(*ep);
    }
}


void SeasonEpiosdeFactory::addEpisodesNames(Season &s, std::vector<std::string> &names) {
    unsigned int nr = names.size();
    for(unsigned int i = 0; i < nr; i++){
        auto* ep = new Episode(names[i], 24);
        s.add_episode(*ep);
    }
}


void SeasonEpiosdeFactory::addEpisodesDuration(Season &s, std::vector<int> &durations) {
    unsigned int nr = durations.size();
    for(unsigned int i = 0; i < nr; i++){
        auto* ep = new Episode("Episode", durations[i]);
        s.add_episode(*ep);
    }
}


void SeasonEpiosdeFactory::addEpisodesNamesDuration(Season &s, std::vector<std::string> &names, std::vector<int> &durations) {
    unsigned int nr = names.size();
    for(unsigned int i = 0; i < nr; i++){
        auto* ep = new Episode(names[i], durations[i]);
        s.add_episode(*ep);
    }
}
