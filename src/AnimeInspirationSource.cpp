#include "../headers/AnimeInspirationSource.h"

AnimeInspirationSource::AnimeInspirationSource(const std::string& name_, const std::string& author_): name{name_}, author{author_} {
    std::cout << "Constructor AnimeInspirationSource\n";
}

AnimeInspirationSource::AnimeInspirationSource(const AnimeInspirationSource &other):
    name{other.name}, author{other.author}, content{other.content} {
    std::cout << "Constructor de copiere AnimeInspirationSource\n";
}
AnimeInspirationSource& AnimeInspirationSource::operator=(const AnimeInspirationSource &other) {
    name = other.name;
    author = other.author;
    content = other.content;
    std::cout << "Operator= AnimeInspirationSource\n";
    return *this;
}

std::ostream &operator<<(std::ostream& os, const AnimeInspirationSource& ais){
    os << "Numele sursei de inspiratie este: " << ais.name << "\n";
    os << "Este scrisa de: " << ais.author << "\n";
    os << "Contine " << ais.content.size() << " parti:\n";
    for(auto& x: ais.content){
        os << x << "\n";
    }
    return os;
}

void AnimeInspirationSource::afisare(std::ostream& os, const std::string& tp){
    if(tp == "Manga") os << "Numele seriei manga pe care este bazat animeul este " << name << "\n";
    else os << "Numele romanului pe care este bazat animeul este " << name << "\n";
    os << "Autorul seriei este: " << author << "\n";
    if(tp == "Manga") os << "Contine " << content.size() << " capitole:\n";
    else os << "Contine " << content.size() << " Volume:\n";
    for(auto& x: content){
        os << x << "\n";
    }
}

AnimeInspirationSource:: ~AnimeInspirationSource() {
    std::cout << "Destructor AnimeInspirationSource\n";
}

void AnimeInspirationSource::addContent(const std::string& s) {
    std::string a;
    a = "Partea " + std::to_string(content.size() + 1) + ": " + s;
    content.push_back(a);
}

