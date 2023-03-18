#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <memory>

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

class Season{
    private:
        std::string name;
        int nrEpisodes;
        std::vector<Episode> episodes;
        std::map<std::string, int> reviews;
        int sumOfRatings = 0, nrReviews = 0;
        long double rating = 0;
        friend class Anime;
        friend class Account;
    public:
        Season(const std::string& name_ = "Season"): name{name_}, nrEpisodes{0}{
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

        int getLength(){
            int sum = 0;
            for(unsigned int i = 0; i < episodes.size(); i++){
                sum += episodes[i].duration;
            }
            std::cout << name << "are lungimea totala de " << sum << "minute\n";
            return sum;
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
            std::cout << "Seria Manga a fost stearsa\n";
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
        long double rating = 0;
        friend class Account;
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
            os << "Animeul are ratingul: " << an.rating << "\n";
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

        int getLength(){
            int sum = 0;
            for(unsigned int i = 0; i < seasons.size(); i++){
                sum += seasons[i].getLength();
            }
            std::cout << "Animeul:" << name << "are lungimea totala de " << sum << "minute\n";
            return sum;
        }

        void ratingUpdate(){
            long double sum = 0;
            for(unsigned int i = 0; i < seasons.size(); i++){
                sum += seasons[i].rating;
            }
            rating = sum / nrSeasons;
            std::cout << "Animeul are ratingul: " << rating << "\n";
        }
};

class Account{
    private:
        std::string name, rol, password;
        static std::map<std::string, std::shared_ptr<Account>> accounts;
    public:
        Account(const std::string& name_, const std::string& rol_, const std::string& password_):name{name_}, rol{rol_}, password{password_}{
            if(rol != "ADMIN") rol = "USER";
            try {
                if (Account::accounts.find(name) != Account::accounts.end()) {
                    std::cout << "Contul cu numele " << name << " exista deja\n";
                    throw std::invalid_argument("Numele contului este deja folosit");
                }
                else {
                    accounts[name] = std::make_shared<Account>(*this);
                    std::cout << "Contul cu numele " << name << " a fost creat\n";
                }
            }
            catch (const std::invalid_argument &e) {
                std::cout << "Caught exception: " << e.what() << std::endl;
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


        void add_season(Anime& an, Season& se){
            if(rol == "ADMIN") {
                an.nrSeasons++;
                if (se.name == "Season") {
                    se.name = "Season " + std::to_string(an.nrSeasons);
                }
                an.seasons.push_back(se);
                an.rating = an.rating * (an.nrSeasons - 1);
                an.rating += se.rating;
                an.rating = an.rating / an.nrSeasons;
            }
            else std::cout << "Nu aveti permisiunea de a face modificari\n";
        }

        void add_episode(Season& se, Episode& ep) {
            if (rol == "ADMIN") {
                se.nrEpisodes++;
                if (ep.name == "Episode") {
                    ep.name = "Episode " + std::to_string(se.nrEpisodes);
                }
                se.episodes.push_back(ep);
            }
            else std::cout << "Nu aveti permisiunea de a face modificari\n";
        }

        void add_review(Season& se, const int& rating){
            if(rating <= 0 || rating >= 10){
                std::cout << "Valoare invalida pentru rating\n";
            }
            else{
                int oldVal = se.reviews[name];
                se.reviews[name] = rating;
                se.sumOfRatings += rating - oldVal;
                se.nrReviews++;
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
    acc1.add_review(s1, 7);
    acc1.add_review(s2, 9);
    acc2.add_review(s2, 9);
    acc3.add_review(s2, 9);
    Anime an1;
    acc2.add_season(an1, s1);
    acc2.add_season(an1, s2);
    std::cout << an1;
    Manga mg1{"Rent a girlfriend", 270};
    Novel no1{"Konosuba", 17};
    std::cout << mg1;
    std::cout << no1;
    return 0;
}