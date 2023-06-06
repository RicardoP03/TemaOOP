#include "../headers/AnimeInspirationSource.h"

AnimeInspirationSource::AnimeInspirationSource(const std::string& name_, const std::string& author_): name{name_}, author{author_} {
    std::cout << "Constructor AnimeInspirationSource\n";
}

AnimeInspirationSource::AnimeInspirationSource(const AnimeInspirationSource &other):
    name{other.name}, author{other.author}{
    std::cout << "Constructor de copiere AnimeInspirationSource\n";
}

AnimeInspirationSource& AnimeInspirationSource::operator=(const AnimeInspirationSource &other) {
    name = other.name;
    author = other.author;
    std::cout << "Operator= AnimeInspirationSource\n";
    return *this;
}


void AnimeInspirationSource::afisare(std::ostream& os, const std::string& tp) {
    if(tp == "Script") os << "Numele scenariului pe care este baza animenul este " << name << "\n";
    else if(tp == "Manga") os << "Numele seriei manga pe care este bazat animeul este " << name << "\n";
    else os << "Numele romanului pe care este bazat animeul este " << name << "\n";
    os << "Autorul seriei este: " << author << "\n";
}

std::ostream &operator<<(std::ostream& os, const AnimeInspirationSource& ais){
    os << "Numele sursei de inspiratie este: " << ais.name << "\n";
    os << "Este scrisa de: " << ais.author << "\n";
    return os;
}


AnimeInspirationSource:: ~AnimeInspirationSource() {
    std::cout << "Destructor AnimeInspirationSource\n";
}

