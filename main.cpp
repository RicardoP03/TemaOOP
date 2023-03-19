#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <memory>

//Am oferit o descriere mai ambla in Readme


//clasa reprezinta un episod dintr-un anime
class Episode{
    private:
        std::string name;
        int duration;
        friend class Season;
        friend class Anime;
        friend class Account;
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


//reprezinta un sezon care este compus din mai multe episoade si are un rating
class Season{
    private:
        std::string name;
        int nrEpisodes = 0;
        std::vector<Episode> episodes;
        std::map<std::string, int> reviews; // mapa folosit pentru a stoca review-urile
        int sumOfRatings = 0, nrReviews = 0;
        long double rating = 0;
        friend class Anime;
        friend class Account;
    public:
        Season(const std::string& name_ = "Season"): name{name_}{
            std::cout << "Sezonul a fost adaugat\n";
        }

        Season(const Season&other): name{other.name}, nrEpisodes{other.nrEpisodes}, episodes{other.episodes},
        reviews{other.reviews}, sumOfRatings{other.sumOfRatings}, nrReviews{other.nrReviews}, rating{other.rating}{
            std::cout << "Constructor copiere Sezon\n";
        }

        Season& operator=(const Season&other){
            name = other.name;
            nrEpisodes = other.nrEpisodes;
            this->episodes = other.episodes;
            this->reviews = other.reviews;
            sumOfRatings = other.sumOfRatings;
            nrReviews = other.nrReviews;
            rating = other.rating;
            std::cout << "operator = copiere Sezon\n";
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Season& sez){
            os << "Numele sezonului este: " << sez.name << "\n";
            os << "Sezonul are " << sez.nrEpisodes << " episoade\n";
            os << "Seazonul are ratingul de: " << sez.rating <<  " obtinut din " << sez.nrReviews << " recenzi" << "\n";
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

        //functie care calculeaza lungimea totala a unui sezon
        int getLength(){
            int sum = 0;
            for(unsigned int i = 0; i < episodes.size(); i++){
                sum += episodes[i].duration;
            }
            std::cout << name << "are lungimea totala de " << sum << "minute\n";
            return sum;
        }
};

//repezinta o serie mang amomentan nu are o utilizare ampla
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
            std::cout << "Seria Manga a fost stearsa\n";
       }

};

//clasa reprezinta un roman, momentan nu are o utilizare mai ampla
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

//clasa Anime, reprezinta un anime care este format din mai multe sezoane si are ratingul ca find media
//ratingurilor sezoanelor
class Anime{
    private:
        std::string name;
        int nrSeasons = 0;
        std::vector<Season*> seasons;
        long double rating = 0;
        friend class Account;
    public:
        Anime(const std::string& name_ = "Anime"): name{name_}{
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
            os << "Animeul are ratingul: " << an.rating << "\n";
            os << "Lista sezoanelor:\n\n";
            for(unsigned int i = 0; i < an.seasons.size() ; i++){
                os << *an.seasons[i] << "\n";
            }
            return os;
        }

        ~Anime(){
            seasons.clear();
            std::cout << "Animeul a fost sters\n";
        }

        //calculeaza lungimea totala a unui anime
        int getLength(){
            int sum = 0;
            for(unsigned int i = 0; i < seasons.size(); i++){
                sum += seasons[i] -> getLength();
            }
            std::cout << "Animeul:" << name << "are lungimea totala de " << sum << "minute\n";
            return sum;
        }

        //recalculeaza raingul animeului
        void ratingUpdate(){
            long double sum = 0;
            for(unsigned int i = 0; i < seasons.size(); i++){
                sum += seasons[i] -> rating;
            }
            rating = sum / nrSeasons;
            std::cout << "Animeul are ratingul: " << rating << "\n";
        }
};

//clasa Account reprezinta un cont care poate sa faca modificari in functie de rolul pe care il are
class Account{
    private:
        std::string name, rol, password;
        static std::map<std::string, std::shared_ptr<Account>> accounts; // mapa folosita sa verificam daca numele sunt unice
    public:
        Account(const std::string& name_, const std::string& rol_, const std::string& password_):name{name_}, rol{rol_}, password{password_}{
            if(rol != "ADMIN") rol = "USER"; //daca rolul este diferit de "ADMIN", il setam automat la "USER"
            try {
                if (Account::accounts.find(name) != Account::accounts.end()) { // verificam daca un cont cu acest nume exista
                    std::cout << "Contul cu numele " << name << " exista deja\n"; //afisem un mesaj si o eroare corespunzatoare
                    throw std::invalid_argument("Numele contului este deja folosit");
                }
                else {
                    accounts[name] = std::make_shared<Account>(*this); //daca nu este il aduagam in mapa
                    std::cout << "Contul cu numele " << name << " a fost creat\n";
                }
            }
            catch (const std::invalid_argument &e) {
                std::cout << "Caught exception: " << e.what() << std::endl; // afisem mesajul de eroare
            }
        }

        Account(const Account& other): name{other.name}, rol{other.rol}, password{other.password}{
            std::cout << "Constructor copiere cont\n";
        }

        Account &operator=(const Account& other){
            name = other.name;
            rol = other.rol;
            password = other.password;
            std::cout << "operator= Account\n";
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Account& ac){
            os << "Numele contului este: " << ac.name << "\n";
            os << "Contul are rolul: " << ac.rol << "\n";
            os << "Parola este: " << ac.password << "\n";
            return os;
        }

        ~Account(){
            std::cout<< "Contul a fost sters\n";
        }

        //functie care adauga un sezon
        void add_season(Anime& an, Season& se){
            if(rol == "ADMIN") { //verificam daca contul are rolul necesar
                an.nrSeasons++;
                if (se.name == "Season") { // setam numele la cel conrespunzator daca un nume nu a fost oferit la creearea obiectulu season
                    se.name = "Season " + std::to_string(an.nrSeasons);
                }
                an.seasons.push_back(&se);
                //recalculam ratigul dupa noul sezon adaugat
                an.rating = an.rating * (an.nrSeasons - 1);
                an.rating += se.rating;
                an.rating = an.rating / an.nrSeasons;
            }
            else std::cout << "Nu aveti permisiunea de a face modificari\n";
        }

        //functia adauga un episod
        void add_episode(Season& se, Episode& ep) {
            if (rol == "ADMIN") { // verificam daca contula re rolul necesar
                se.nrEpisodes++;
                if (ep.name == "Episode") { // verificam daca un nume a fost oferit la crearea episodului daca nu ii oferim un nume corespunzator
                    ep.name = "Episode " + std::to_string(se.nrEpisodes);
                }
                se.episodes.push_back(ep);
            }
            else std::cout << "Nu aveti permisiunea de a face modificari\n";
        }

        //functia aduaga un review la un sezon
        void add_review(Season& se, const int& rating){
            if(rating < 0 || rating > 10){ //verificam daca valoarea este corespunzatoare
                std::cout << "Valoare invalida pentru rating\n";
            }
            else{
                //updatam ratingul cu noul review adaugat
                if(se.reviews.count(name) == 0) se.nrReviews++;
                int oldVal = se.reviews[name];
                se.reviews[name] = rating;
                se.sumOfRatings += rating - oldVal;
                se.rating = 1.0 * se.sumOfRatings / se.nrReviews;
            }
        }
};

std::map<std::string, std::shared_ptr<Account>> Account::accounts;

int main() {
    Account acc1("John", "USER", "password1");
    Account acc2("Jane", "ADMIN", "password2");
    Account acc3("Jim", "USER", "password3");
    Episode e1{"Episode 1", 25};
    Episode e2{"Episode", 25};
    Episode e3{"Not coming back", 25};
    Episode e4{"Episode", 25};
    Season s1 = {"Season"};
    acc1.add_episode(s1, e1);
    acc2.add_episode(s1, e1);
    acc2.add_episode(s1, e2);
    acc2.add_episode(s1, e3);
    acc2.add_episode(s1, e4);
    Episode e5 = {"Episode 1", 24};
    Episode e6 = {"Episode 2", 24};
    Episode e7 = {"Episode 3", 24};
    Episode e8 = {"Episode 4", 24};;
    Season s2 = {"Season 2"};
    acc2.add_episode(s2, e5);
    acc2.add_episode(s2, e6);
    acc2.add_episode(s2, e7);
    acc2.add_episode(s2, e8);
    acc1.add_review(s1, 8);
    acc2.add_review(s1, 9);
    acc3.add_review(s1, 10);
    acc1.add_review(s2, 9);
    acc2.add_review(s2, 9);
    acc3.add_review(s2, 9);
    Anime an1{"Viollet Evergarden"};
    acc2.add_season(an1, s1);
    acc2.add_season(an1, s2);
    acc1.add_review(s2, 10);
    an1.ratingUpdate();
    std::cout << an1;
    Manga mg1{"Rent a girlfriend", 270};
    Novel no1{"Konosuba", 17};
    std::cout << mg1;
    std::cout << no1;
    return 0;
}