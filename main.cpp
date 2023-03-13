#include <iostream>
#include <string>
#include <vector>

class Episode{
    private:
        std::string name;
        int duration;
        friend class Season;
        friend class Anime;
    public:
        Episode(const std::string& name_ = "Episode", int duration_ = 24) : name{name_}, duration{duration_} {
            std::cout << "Episodul a fost adaugat\n";
        }

        Episode(const Episode& other) : name{other.name}, duration{other.duration}{
            std::cout << "Constr de copiere Episod\n";
        }

        Episode& operator=(const Episode& other) {
            name = other.name;
            duration = other.duration;
            std::cout << "operator= copiere Episode\n";
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Episode& ep) {
            os << "Numele episodului este: " << ep.name << "\n";
            os << "Durata episodului este: " << ep.duration << "\n";
            return os;
        }

        ~Episode(){
            std::cout << "Episodul a fost sters\n";
        }
};

class Season{
    private:
        std::string name;
        int nrEpisodes;
        std::vector<Episode> episodes;
        friend class Anime;
    public:
        Season(const std::string& name_ = "Season"): name{name_}, nrEpisodes{0}{
            std::cout << "Sezonul a fost adaugat\n";
        }

        Season(const Season&other): name{other.name}, nrEpisodes{other.nrEpisodes}, episodes{other.episodes}{
            std::cout << "Constructor copiere Sezon\n";
        }

        Season& operator=(const Season&other){
            name = other.name;
            nrEpisodes = other.nrEpisodes;
            this->episodes = other.episodes;
            std::cout << "operator = copiere Sezon\n";
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Season& sez){
            os << "Numele sezonului este: " << sez.name << "\n";
            os << "Sezonul are " << sez.nrEpisodes << " episoade\n";
            os << "Lista Episoadelor:\n\n";
            for(unsigned int i = 0; i < sez.episodes.size(); i++){
                os << sez.episodes[i] << "\n";
            }
            return os;
        }

        ~Season(){
            episodes.clear();
            std::cout << "Sezonul a fost sters\n";
        }

        void add_episode(Episode& ep){
            nrEpisodes++;
            if(ep.name == "Episode"){
                ep.name = "Episode " + std::to_string(nrEpisodes);
            }
            episodes.push_back(ep);
        }
};

class Manga{
    private:
        std::string name;
        int nrChapters;
    public:
        Manga(const std::string& name_, int nrChapters_): name{name_}, nrChapters{nrChapters_}{
            std::cout << "Seria Manga a fost creata\n";
        }

        Manga(const Manga& other): name{other.name}, nrChapters{other.nrChapters}{
            std::cout << "Constructor de copiere Manga\n";
        }

        Manga& operator=(const Manga& other){
            name = other.name;
            nrChapters = other.nrChapters;
            std::cout << "operator= copiere Manga\n";
            return *this;
        }

       friend std::ostream& operator<<(std::ostream& os, const Manga& mg){
            os << "Numele seriei manga este: " << mg.name << "\n";
            os << "Seria contine " << mg.nrChapters << " capitole\n";
            return os;
       }
       ~Manga(){
            std::cout << "Seria Manga a fost stearsa";
       }

};

class Novel{
    private:
        std::string name;
        int nrVolums;
    public:
        Novel(const std::string& name_, int nrVolums_): name{name_}, nrVolums{nrVolums_}{
            std::cout << "Romanul a fost creat\n";
        }

        Novel(const Novel& other): name{other.name}, nrVolums{other.nrVolums}{
            std::cout << "Constructor copiere Nouvel\n";
        }

        Novel& operator=(const Novel &other){
            name = other.name;
            nrVolums = other.nrVolums;
            std::cout << "operator= copiere Manga\n";
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Novel& nov){
            os << "Numele romanului este: " << nov.name << "\n";
            os << "Romanul contine " << nov.nrVolums << " volume\n";
            return os;
       }

       ~Novel(){
            std::cout << "Romanul a fost sters\n";
       }
};

class Anime{
    private:
        std::string name;
        int nrSeasons;
        std::vector<Season> seasons;
    public:
        Anime(const std::string& name_ = "Anime"): name{name_}, nrSeasons{0}{
            std::cout << "Animeul a fost adaugat\n";
        }

        Anime(const Anime& an): name{an.name}, nrSeasons{an.nrSeasons}, seasons{an.seasons}{
            std::cout << "Constructor copiere Anime\n";
        }

        Anime& operator=(const Anime& an){
            name = an.name;
            nrSeasons = an.nrSeasons;
            this->seasons = an.seasons;
            std::cout << "operator = copiere Anime\n";
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Anime& an){
            os << "Numele Animeului este: " << an.name << "\n";
            os << "Animeul are " << an.nrSeasons << " sezoane\n";
            os << "Lista sezoanelor:\n\n";
            for(unsigned int i = 0; i < an.seasons.size() ; i++){
                os << an.seasons[i] << "\n";
            }
            return os;
        }

        ~Anime(){
            seasons.clear();
            std::cout << "Animeul a fost sters\n";
        }

        void add_season(Season& se){
            nrSeasons++;
            if(se.name == "Season"){
                se.name = "Season " + std::to_string(nrSeasons);
            }
            seasons.push_back(se);

        }
};

int main() {
    Episode e1{"Episode 1", 25};
    Episode e2{"Episode", 25};
    Episode e3{"Not coming back", 25};
    Episode e4{"Episode", 25};
    Season s1 = {"Season"};
    s1.add_episode(e1);
    s1.add_episode(e2);
    s1.add_episode(e3);
    s1.add_episode(e4);
    Episode e5 = {"Episode 1", 24};
    Episode e6 = {"Episode 2", 24};
    Episode e7 = {"Episode 3", 24};
    Episode e8 = {"Episode 4", 24};;
    Season s2 = {"Season 2"};
    s2.add_episode(e5);
    s2.add_episode(e6);
    s2.add_episode(e7);
    s2.add_episode(e8);
    Anime a1 = {"Viollet Evergarden"};
    a1.add_season(s1);
    a1.add_season(s2);
    std::cout << a1;
    return 0;
}