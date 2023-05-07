#include "../headers/Episode.h"

Episode::Episode(std::string&& name_, int duration_) : name{std::move(name_)}, duration{duration_} {
    std::cout << "Episodul a fost adaugat\n";
}

Episode::Episode(const Episode& other) : name{other.name}, duration{other.duration}{
    std::cout << "Constr de copiere Episod\n";
}

Episode& Episode::operator=(const Episode& other) {
    name = other.name;
    duration = other.duration;
    std::cout << "operator= copiere Episode\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Episode& ep) {
    os << "Numele episodului este: " << ep.name << "\n";
    os << "Durata episodului este: " << ep.duration << "\n";
    return os;
}

Episode::~Episode(){
    std::cout << "Episodul a fost sters\n";
}

int Episode::getDuration() const{
    return duration;
}

std::string Episode::getName(){
    return name;
}

void Episode::setName(const std::string& newName){
    name = newName;
}