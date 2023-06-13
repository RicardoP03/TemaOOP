#include "../headers/Meniu.h"


Meniu &Meniu::get_meniu() {
    static Meniu app;
    return app;
}


Meniu::Meniu() {
    admins["FirstAdmin"]  = Admin("FirstAdmin", "Randompassword123");
}


void Meniu::start() {
    std::cout << "Pentru a va audentifica intr-un cont apsati tasta A \n";
    std::cout << "Pentru a creea un cont apsati tasta C\n";
    std::cout << "Pentru inchiderea programului apasati tasta D\n";
    char c;
    std::cin >> c;
    if(c == 'A' || c == 'a') return logIn();
    if(c == 'C' || c == 'c') return createAccount();
}


void Meniu::logIn() {
    std::cout << "Introduceti numele: ";
    std::string name, password;
    std::cin >> name;
    std::cout << "Introduceti parola: ";
    std::cin >> password;
    try {
        if(admins.find(name) != admins.end()) {
            admins[name].logIn(name, password);
            return meniuAdmin(admins[name]);
        }
        if(users.find(name) != users.end()) {
            users[name].logIn(name, password);
            return meniuUser(users[name]);
        }
    }
    catch(const std::exception& e){
        std::cout << "Error: " << e.what() << "\n";
        std::cout << "Pentru a va intoarce la meniu de logare apasati L\n";
        std::cout << "Pentru a va intoarce la meniu principal apasati P\n";
        char c;
        std::cin >> c;
        if(c == 'L' || c == 'l') return logIn();
        else return start();
    }
}


void Meniu::createAccount() {
    std::cout << "Introduceti numele: ";
    std::string name, password;
    std::cin >> name;
    std::cout << "Introduceti parola: ";
    std::cin >> password;
    try {
        User u(name, password);
        users[name] = u;
        return meniuUser(u);
    }
    catch(const std::exception& e){
        std::cout << "Error: " << e.what() << "\n";
        std::cout << "Pentru a va intoarce la meniu de creare apasati L\n";
        std::cout << "Pentru a va intoarce la meniu principal apasati P\n";
        char c;
        std::cin >> c;
        if(c == 'L' || c == 'l') return createAccount();
        else return start();
    }
}


template<typename T>
void Meniu::outputMapContents(const std::map<int, T>& map) {
    for (const auto& pair : map) {
        std::cout << pair.second << "\n";
    }
}


void Meniu::getEpisodes() {
    std::cout << "Introduceti id-ul sau -1 in cazul in care doriti listarea tututror episoadelor\n";
    int id;
    std::cin >> id;
    if(id == -1) {
        std::cout << "Lista episoadelor:\n";
        outputMapContents(episodes);
    }
    else{
        if(episodes.find(id) != episodes.end()){
            std::cout << episodes[id] << "\n";
        }
        else{
            std::cout << "Episodul cu id-ul: " << id << " nu exista\n";
        }
    }
}


void Meniu::getSeasons() {
    std::cout << "Introduceti id-ul sau -1 in cazul in care doriti listarea tututror sezoanelor\n";
    int id;
    std::cin >> id;
    if(id == -1){
        std::cout << "Lista sezoanelor:\n";
        outputMapContents(seasons);
    }
    else{
        if(seasons.find(id) != seasons.end()){
            std::cout << seasons[id] << "\n";
        }
        else{
            std::cout << "Sezonul cu id-ul: " << id << " nu exista\n";
        }
    }

}


void Meniu::getManga() {
    std::cout << "Introduceti id-ul sau -1 in cazul in care doriti listarea tututror seriilor manga\n";
    int id;
    std::cin >> id;
    if(id == -1){
        std::cout << "Lista seriilor Manga:\n";
        outputMapContents(mangas);
    }
    else{
        if(mangas.find(id) != mangas.end()){
            std::cout << mangas[id] << "\n";
        }
        else{
            std::cout << "Seria manga cu id-ul: " << id << " nu exista\n";
        }
    }

}


void Meniu::getNovel() {
    std::cout << "Introduceti id-ul sau -1 in cazul in care doriti listarea tututror romanelor\n";
    int id;
    std::cin >> id;
    if(id == -1) {
        std::cout << "Lista romanelor:\n";
        outputMapContents(novels);
    }
    else{
        if(novels.find(id) != novels.end()){
            std::cout << novels[id] << "\n";
        }
        else{
            std::cout << "Romanul cu id-ul: " << id << " nu exista\n";
        }
    }

}


void Meniu::getScript() {
    std::cout << "Introduceti id-ul sau -1 in cazul in care doriti listarea tututror scenariilor\n";
    int id;
    std::cin >> id;
    if(id == -1){
        std::cout << "Lista scenariilor:\n";
        outputMapContents(scripts);
    }
    else{
        if(scripts.find(id) != scripts.end()){
            std::cout << scripts[id] << "\n";
        }
        else{
            std::cout << "Scenariul cu id-ul: " << id << " nu exista\n";
        }
    }
}


void Meniu::getAnime(){
    std::cout << "Introduceti id-ul sau -1 in cazul in care doriti listarea tututror animeurilor\n";
    int id;
    std::cin >> id;
    if(id == -1){
        std::cout << "Lista animeurilor:\n";
        for (const auto& pair : animes) {
            auto& animeVariant = pair.second;
            if (auto* anime1 = std::get_if<Anime<Manga>>(&animeVariant)) {
                std::cout << anime1;
            }
            else if (auto* anime2 = std::get_if<Anime<AnimeScript>>(&animeVariant)) {
                std::cout << anime2;
            }
            else if (auto* anime3 = std::get_if<Anime<Novel>>(&animeVariant)) {
                std::cout << anime3;
            }
        }
    }
    else{
        if(animes.find(id) != animes.end()){
            auto& animeVariant = animes[id];
            if (auto* anime1 = std::get_if<Anime<Manga>>(&animeVariant)) {
                std::cout << anime1;
            }
            else if (auto* anime2 = std::get_if<Anime<AnimeScript>>(&animeVariant)) {
                std::cout << anime2;
            }
            else if (auto* anime3 = std::get_if<Anime<Novel>>(&animeVariant)) {
                std::cout << anime3;
            }
        }
        else{
            std::cout << "Animeul cu id-ul: " << id << " nu exista\n";
        }
    }
}


void Meniu::meniuUser(User& u) {
    std::cout <<"Pentru a afisa un episod introduceti tasta E\n";
    std::cout <<"Pentru a afisa un sezon introduceti tasta S\n";
    std::cout <<"Pentru a afisa o serie manga introduceti tasta M\n";
    std::cout <<"Pentru a afisa un roman introduceti tasta R\n";
    std::cout <<"Pentru a afisa un scenariu manga introduceti tasta C\n";
    std::cout <<"Pentru a adauga o recenzie introduceti tasta Z\n";
    std::cout <<"Pentru afisarea permisiunilor intrdouceti tasta U\n";
    std::cout <<"Pentru a va deconecta introduceti tasta D\n";
    char c;
    std::cin >> c;
    if(c == 'E' || c == 'e') return getEpisodes();
    if(c == 'S' || c == 's') return getSeasons();
    if(c == 'A' || c == 'a') return getAnime();
    if(c == 'M' || c == 'm') return getManga();
    if(c == 'R' || c == 'r') return getNovel();
    if(c == 'C' || c == 'c') return getScript();
    if(c == 'Z' || c =='z'){
        std::cout << "Introduceti id-ul sezonului: ";
        int id;
        std::cin >> id;
        std::cout << "Introduceti nota: ";
        int val;
        std::cin >> val;
        if(seasons.find(id) != seasons.end()){
            u.add_review(seasons[id], val);
        }
        else{
            std::cout << "Sezonul cu id-ul: " << id << " nu exista\n";
        }
    }
    if(c == 'U' || c == 'u'){
        std::cout << u.getPermissions();
    }
    if(c == 'D' || c =='d'){
        u.logOut();
        return start();
    }
    std::cout << "Pentru a va intoarce la meniul de utilizator introduceti orice tasta\n";
    std::cin >> c;
    return meniuUser(u);
}


void Meniu::addContent(Admin& a) {
    std::cout << "Pentru a adauga un episod nou apasati tasta E\n";
    std::cout << "Pentru a adauga un sezon nou apasati tasta S\n";
    std::cout << "Pentru a adauga un anime nou apasati tasta A\n";
    std::cout << "Pentru a adauga o serie manga nou apasati tasta M\n";
    std::cout << "Pentru a adauga un roman nou apasati tasta R\n";
    std::cout << "Pentru a adauga un scenariu nou apasati tasta C\n";
    char c;
    std::cin >> c;
    if(c == 'E' || c == 'e'){
        auto e = readContent<Episode>();
        episodes[e.getId()] = e;
        std::cout << "Episodul a fost adaugat\n";
    }
    else if(c == 'S' || c == 's'){
        auto s = readContent<Season>();
        seasons[s.getId()] = s;
        std::cout << "Sezonul a fost adaugat\n";
    }
    else if(c == 'A' || c == 'a'){
        std::cout << "Ce fell de sursa de insipratie doriti sa aiba animeul\n"
                     "Introduceti tasta M pentru manga\n"
                     "Introduceti tasta N pentru un roman\n"
                     "Introduceti tasta S pentru un scenariu\n";
        std::cin >> c;
        if(c == 'M' || c == 'm'){
            auto an = readContent<Anime<Manga>>();
            animes[an.getId()] = an;
        }
        if(c == 'N' || c == 'n'){
            auto an = readContent<Anime<Novel>>();
            animes[an.getId()] = an;
        }
        if(c == 'S' || c == 's'){
            auto an = readContent<Anime<AnimeScript>>();
            animes[an.getId()] = an;
        }
        std::cout << "Animeul a fost adaugat\n";
    }
    else if(c == 'M' || c == 'm'){
        auto m = readContent<Manga>();
        mangas[m.getId()] = m;
        std::cout << "Seria Manga a fost adaugat\n";
    }
    else if(c == 'R' || c == 'r'){
        auto n = readContent<Novel>();
        novels[n.getId()] = n;
        std::cout << "Romanul a fost adaugat\n";
    }
    else if(c == 'C' || c == 'c'){
        auto as = readContent<AnimeScript>();
        scripts[as.getId()] = as;
        std::cout << "Scenariul a fost adaugat\n";
    }
    std::cout << "Pentru a va intoarce la meniul de admin introduceti orice tasta\n";
    std::cin >> c;
    return meniuAdmin(a);
}


void Meniu::addEpisodeSeason(Admin &a) {
    std::cout << "Doriti sa folositi o completare automata? Introduceti tasta D/N\n";
    char c;
    std::cin >> c;
    if(c == 'D' || c == 'd'){
        char n, d;
        int nr, ids;
        std::cout << "Doriti sa intrdouceti numele? Introduceti tasta D/N\n";
        std:: cin >> n;
        std::cout << "Doriti sa intrdouceti durata? Introduceti tasta D/N\n";
        std:: cin >> d;
        std::cout << "Introduceti numarul de episoade: ";
        std::cin >> nr;
        std::cout << "Introduceti id-ul sezonului: ";
        std::cin >> ids;
        if((n == 'N' || n == 'n') && (d == 'N' || d == 'n')){
            if(seasons.find(ids) != seasons.end()){
                SeasonEpiosdeFactory::addEpisodes(seasons[ids], nr);
            }
            else std::cout << "Sezonul nu cu id-ul " << ids << " nu exista\n";
        }

        if((n == 'N' || n == 'n') && (d == 'D' || d == 'd')){
            std::vector<int> durations;
            for(int i = 0; i < nr; i++){
                std::cout << "Introduceti durata episodului " << i + 1 << ":";
                int dur;
                std::cin >> dur;
                durations.push_back(dur);
            }
            if(seasons.find(ids) != seasons.end()){
                SeasonEpiosdeFactory::addEpisodesDuration(seasons[ids], durations);
            }
            else std::cout << "Sezonul nu cu id-ul " << ids << " nu exista\n";
        }

        if((n == 'D' || n == 'd') && (d == 'N' || d == 'n')){
            std::vector<std::string> names;
            for(int i = 0; i < nr; i++){
                std::cout << "Introduceti numele episodului " << i + 1 << ":\n";
                std::string nam;
                std::getline(std::cin, nam);
                names.push_back(nam);
            }
            if(seasons.find(ids) != seasons.end()){
                SeasonEpiosdeFactory::addEpisodesNames(seasons[ids], names);
            }
            else std::cout << "Sezonul cu id-ul " << ids << " nu exista\n";
        }

        if((n == 'D' || n == 'd') && (d == 'D' || d == 'd')){
            std::vector<std::string> names;
            for(int i = 0; i < nr; i++){
                std::cout << "Introduceti numele episodului " << i + 1 << ":\n";
                std::string nam;
                std::getline(std::cin, nam);
                names.push_back(nam);
            }

            std::vector<int> durations;
            for(int i = 0; i < nr; i++){
                std::cout << "Introduceti durata episodului " << i + 1 << ":";
                int dur;
                std::cin >> dur;
                durations.push_back(dur);
            }

            if(seasons.find(ids) != seasons.end()){
                SeasonEpiosdeFactory::addEpisodesNamesDuration(seasons[ids], names, durations);
            }
            else std::cout << "Sezonul nu cu id-ul " << ids << " nu exista\n";
        }
    }

    if(c == 'N' || c == 'n'){
        std::cout << "Introduceti id-ul sezonului: ";
        int ids, ide;
        std::cin >> ids;
        std::cout << "Introduceti id-ul episodului ";
        std::cin >> ide;
        if(seasons.find(ids) != seasons.end() || episodes.find(ide) != episodes.end()){
            seasons[ids].add_episode(episodes[ide]);
            std::cout << "Episodul a fost adaugat\n";
        }
        else std::cout << "Id-ul sezonului/episodului nu exista\n";
    }
    std::cout << "Pentru a va intoarce la meniul de admin introduceti orice tasta\n";
    std::cin >> c;
    return meniuAdmin(a);
}


void Meniu::addChapter(Admin &a) {
    std::string nam;
    int nrpg, nrpan, idm;
    std::cout << "Introduceti numele: ";
    std::cin >> nam;
    std::cout << "Introduceti numarul de pagini: ";
    std::cin >> nrpg;
    std::cout << "Introduceti numarul de panele: ";
    std::cin >> nrpan;
    std::cout << "Intoduceti id-ul seriei Manga: ";
    std::cin >> idm;
    if(mangas.find(idm) != mangas.end()){
        mangas[idm].addContent(nam, nrpg, nrpan);
    }
    else std::cout << "Seria manga cu id-ul " << idm << " nu exista\n";

    std::cout << "Pentru a va intoarce la meniul de admin introduceti orice tasta\n";
    char c;
    std::cin >> c;
    return meniuAdmin(a);

}


void Meniu::addVolum(Admin &a) {
    std::string nam, ed;
    int nrpg, nrWord, idr;
    std::cout << "Introduceti numele: ";
    std::cin >> nam;
    std::cout << "Introduceti numele editorului: ";
    std::cin >> ed;
    std::cout << "Introduceti numarul de pagini: ";
    std::cin >> nrpg;
    std::cout << "Introduceti numarul mediu de cuvinte pe pagina: ";
    std::cin >> nrWord;
    std::cout << "Intoduceti id-ul romanului: ";
    std::cin >> idr;
    if(novels.find(idr) != novels.end()){
        novels[idr].addContent(nam, ed, nrpg, nrWord);
    }
    else std::cout << "Romanul cu id-ul " << idr << " nu exista\n";

    std::cout << "Pentru a va intoarce la meniul de admin introduceti orice tasta\n";
    char c;
    std::cin >> c;
    return meniuAdmin(a);

}


void Meniu::addSeasonAnime(Admin &a) {
    std::cout << "Introduceti id-ul animeului: ";
    int ida, ids;
    std::cin >> ida;
    std::cout << "Introduceti id-ul sezonului: ";
    std::cin >> ids;
    if(animes.find(ida) != animes.end() || seasons.find(ids) != seasons.end()){
        auto& animeVariant = animes[ida];
        if (auto* anime1 = std::get_if<Anime<Manga>>(&animeVariant)) {
            anime1->add_season(seasons[ids]);
        }
        else if (auto* anime2 = std::get_if<Anime<AnimeScript>>(&animeVariant)) {
            anime2->add_season(seasons[ids]);
        }
        else if (auto* anime3 = std::get_if<Anime<Novel>>(&animeVariant)) {
            anime3->add_season(seasons[ids]);
        }
        std::cout << "Sezonul a fost adaugat\n";
    }
    else std::cout << "Id-ul sezonului/animeul nu exista\n";
    std::cout << "Pentru a va intoarce la meniul de admin introduceti orice tasta\n";
    char c;
    std::cin >> c;
    return meniuAdmin(a);
}


void Meniu::meniuAdmin(Admin &a) {
    std::cout <<"Pentru a afisa un episod introduceti tasta E\n";
    std::cout <<"Pentru a afisa un sezon introduceti tasta S\n";
    std::cout <<"Pentru a afisa o serie manga introduceti tasta M\n";
    std::cout <<"Pentru a afisa un roman introduceti tasta R\n";
    std::cout <<"Pentru a afisa un scenariu manga introduceti tasta C\n";
    std::cout <<"Pentru a adauga o recenzie introduceti tasta Z\n";
    std::cout <<"Pentru a adauga continut introduceti tasta O\n";
    std::cout <<"Pentru a adauga episoade la un sezon introduceti tasta P\n";
    std::cout <<"Pentru a adauga sezon la un anime introduceti tasta I\n";
    std::cout <<"Pentru a adauga un capitol la o serie manga introduceti tasta T\n";
    std::cout <<"Pentru a adauga un volum la un roman introduceti tasta V\n";
    std::cout <<"Pentru afisarea permisiunilor intrdouceti tasta U\n";
    std::cout <<"Pentru a va deconecta introduceti tasta D\n";
    char c;
    std::cin >> c;
    if(c == 'E' || c == 'e') return getEpisodes();
    if(c == 'S' || c == 's') return getSeasons();
    if(c == 'M' || c == 'm') return getManga();
    if(c == 'R' || c == 'r') return getNovel();
    if(c == 'C' || c == 'c') return getScript();
    if(c == 'Z' || c =='z'){
        std::cout << "Introduceti id-ul sezonului: ";
        int id;
        std::cin >> id;
        std::cout << "Introduceti nota: ";
        int val;
        std::cin >> val;
        if(seasons.find(id) != seasons.end()){
            a.add_review(seasons[id], val);
        }
        else{
            std::cout << "Sezonul cu id-ul: " << id << " nu exista\n";
        }
    }
    if(c == 'O' || c =='o'){
        addContent(a);
    }
    if(c == 'P' || c == 'p'){
        return addEpisodeSeason(a);
    }
    if(c == 'I' || c == 'i'){
        return addSeasonAnime(a);
    }
    if(c == 'T' || c == 't'){
        return addChapter(a);
    }
    if(c == 'V' || c == 'v'){
        return addVolum(a);
    }
    if(c == 'U' || c == 'u'){
        std::cout << a.getPermissions();
    }
    if(c == 'D' || c =='d'){
        a.logOut();
        return start();
    }
    std::cout << "Pentru a va intoarce la meniul de utilizator introduceti orice tasta\n";
    std::cin >> c;
    return meniuAdmin(a);
}


template <typename T>
T Meniu::readContent() {
    std::cout << "Introduceti numele: ";
    std::string name;
    std::cin >> name;
    if constexpr (std::is_same<T, Episode>::value){
        std::cout << "Introduceti durata: ";
        int duration;
        std::cin >> duration;
        return Episode(name, duration);
    }
    if constexpr (std::is_same<T, Season>::value){
        return Season(name);
    }
    if constexpr (std::is_same<T, Anime<Manga>>::value){
        std::cout << "Introduceti datele sursei:\n";
        return Anime<Manga>(name, readContent<Manga>());
    }
    if constexpr (std::is_same<T, Anime<Novel>>::value) {
        std::cout << "Introduceti datele sursei:\n";
        return Anime<Novel>(name, readContent<Novel>());
    }
    if constexpr (std::is_same<T, Anime<AnimeScript>>::value) {
        std::cout << "Introduceti datele sursei:\n";
        return Anime<AnimeScript>(name, readContent<AnimeScript>());
    }
    std::cout << "Introduceti autorul: ";
    std::string author;
    std::cin >> author;
    if constexpr (std::is_same<T, Manga>::value){
        std::cout << "Introduce-i ilustratorul: ";
        std::string ilust;
        std::cin  >> ilust;
        std::cout << "Introduceti stilul de arta: ";
        std::string artstyle;
        std::cin  >> artstyle;
        return Manga(name, author, ilust, artstyle);
    }
    if constexpr (std::is_same<T, Novel>::value) {
        return Novel(name, author);
    }
    if constexpr (std::is_same<T, AnimeScript>::value) {
        std::cout << "Introduceti numarul de pagini: ";
        int nrpg;
        std::cin >> nrpg;
        std::cout << "Introduceti numarul de cuvinte pe pagina: ";
        int nrcuv;
        std::cin >> nrcuv;
        return AnimeScript(name, author, nrpg, nrcuv);
    }
}
