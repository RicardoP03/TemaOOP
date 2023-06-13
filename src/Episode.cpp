#include "../headers/Episode.h"

int Episode::idMax = 0;


Episode::Episode(const std::string& name_, int duration_) : name{name_}, duration{duration_} {
    idMax++;
    id = idMax;
}


std::ostream& operator<<(std::ostream& os, const Episode& ep) {
    os << "Numele episodului este: " << ep.name << "\n";
    os << "Durata episodului este: " << ep.duration << "\n";
    return os;
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


int Episode::getId() const {
    return id;
}
