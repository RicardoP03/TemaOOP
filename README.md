Clasa Episode:  
- contine variabilele private:  
  - name care reprezinta numele unui episod, daca un nume nu este oferit acesta este initializat cu numele "Episode".  
  - duration care reprezinta lungimea unui episod in minute, daca o durata nu este oferita este initializat cu valoare 24 din constructor.
  - id care reprezinta id-ul unui episod este unic generat in constructorul clasei.
  - idMax este o variabila statica care reprezinta id-ul maxim, este incrementat cu 1 de fiecare data cand constructorul este apelat.  
- ca functii in plus de cele standard mai contine getteri pentru name, duration si id si setter pentru name.   
  
Clasa Season:  
- contine variabilele private:  
  - name, se refera la numele unui sezon, daca un nume nu este oferit se initializata cu numele "season".  
  - episodes, este un vector de pointeri catre obiecte de tipul Episode si reprezinta lista de episoade din sezon.  
  - reviews reprezinta review-urile primite de un sezon, acestea sunt adaugate din apelul functiei add_review, care se apeleaza din clasa Account dupa ce verificarile necesare au fost realizate, acestea sunt salvate sub forma unei mape cu cheia nume si valoarea rezprezentand ratingul reviewului astfel un cont poate avea un sigur review(numele sunt unice) si acesta este updatat cand se apeleaza inca odata functia add_review asupra obiectului de tip account.  
  - sumOfReviews reprezinta suma valorilor tuturor review-urilor, este intializata cu valoarea 0 si este updatata doar din apelul functiei add_review.  
  - nrReviews reprezinta numarul reviewurilor, care este de asemenea initializata cu valoarea 0 si este updatata doar din apelul functiei add_review.  
  - rating reprezint ratingul sezonului si este calculat ca find sumOfRating / nrReviews si updatat la fiecare apel al functiei add_review.
  - id care reprezinta id-ul unui sezon este unic generat in constructorul clasei.
  - idMax este o variabila statica care reprezinta id-ul maxim, este incrementat cu 1 de fiecare data cand constructorul este apelat/  
- constructorul clasei primeste doar un string si seteaza valoarea numelui la acest string.  
- episoadele sunt aduagate din apelul functiei add_episode, daca sezonul are numele standard("Episode"), numele este modificat la "Episode" + numarul adecvat(daca e al 3 lea episodul numarul 3), apoi episodul este adaugat in vectorul de episoade.  
- add_review adauga un review si este apelata din clasa Account, apoi realizeaza calculele necesare si updateaza valoarea ratingului.  
- clasa mai contine functia getLength care returneaza suma lungimilor tuturor episoadelor.  
- class mai are getteri pentru nume si id si setteri pentru nume.
- SeasonEpiosdeFactory este un factory design patern care adauga episoade unui sezon, are mai multe functii care pot adauga episoade standard(nume 'Episod' si durata 24) sau pot primi parametri pentru nume/durata si pe baza lor sa construiasca episoadele


Clasa AnimeInspirationSource:
- contine variabilele:
  - name care reprezinta numele seriei pe care este bazat un anime.
  - author care reprezinta autorul care a scris seria.
  - id care reprezinta id-ul unei surse este unic generat in constructorul clasei.
  - idMax este o variabila statica care reprezinta id-ul maxim, este incrementat cu 1 de fiecare data cand constructorul este apelat.  
- Functia afisare este folosita pentru a afisa derivatele clasei.
- Functile getReadingTime si getTotalReadingTime pure virutale si returneaza vor fi suprascrise pentru a returna o aproximare a timpului necesar citiri.
- Clasa mai are getter pentru id.

Clasa Manga:  
- mosteneste clasa AnimeInspirationSource
- are variabilele private:
    - illustrator care reprezinta ilustratorul seriei
    - artStyle care reprezinta stilul de arta.
    - chapters un vector care tine numele capitolelor.
    - chaptersDetail este un vector de tip pair <int, int> contine detaliile capitolului corespunzator(numarul de pagini si numarul de panele).
- Functia addContent adauga un capitolul now in vectorul chapters si adauga in chaptersDetail detaliile acestuia.
- Functiile getReadingTime si getTotalReadingTime au fost suprascrise pentru a returna durata de citire a unui capitolul primit ca paramentru, respectiv durata totala de citire.
  
Clasa Novel:  
- mosteneste clasa AnimeInspirationSource.
- are variabilele private:
  - volumes, un vector de tip pair<string, string> care retine numele respectiv editorul volumului.
  - bookDetails, un vector de tip pair<int, int> care retine numarul de pagini, respectiv numaraul mediu de cuvinte pe o pagina.    
- Functia addContent adauga un volum in vectorul volumes si detaliile acestuia in vectorul bookDetails.
- Functiile getReadingTime si getTotalReadingTime au fost suprascrise pentru a returna durata de citire a unui volum primit ca paramentru, respectiv durata totala de citire.

Clasa AnimeScript:
- mosteneste clasa AnimeInspirationSource.
- are variabilele private:
  - nrPages care reprezinta numarul de pagini al scenariului.
  - avgWordsPerPage care reprezinta numarul mediu de cuvinte de pe o pagina.
- Functiile getReadingTime si getTotalReadingTime au fost suprascrise pentru a returna durata de citire a unui volum primit ca paramentru, respectiv durata totala de citire, deoarece un scenariu are doar o parte ambele returneaza acelasi rezultat.

Clasa Anime:
- este o clasa de tip template
- cotine variabilele private:  
  - name reprezinta numele unui anime.  
  - seasons reprezinta un vector de pointeri catre obiecte de tip Season care reprezinta sezoanele animeului.  
  - rating reprezinta ratingul animeului si este calculat ca find valoarea medie a ratingului unui sezon. 
  - source este o variabila de tip template, reprezentand sursa de inspiratie a animeului, meniul suporta doar 3 timpuri de surse de inspiratie, acestea find Manga, Novel si AnimeScript.
  - id care reprezinta id-ul unui anime este unic generat in constructorul clasei.
  - idMax este o variabila statica care reprezinta id-ul maxim, este incrementat cu 1 de fiecare data cand constructorul este apelat.  
- contine functia getLegth care calculeaza lungimea totala a animeului adunand lungimea tuturor sezoaenelor, apoi o afiseaza pe ecran si o returneaza.  
- contine functia ratingUpdate care recalculeaza ratingul unui anime si poate fi apelata la modificarea ratingului unui sezon.  
- sezoanele sunt adaugate in urma apelului functiei add_season, daca sezonul are numele standard("Season"), numele este modificat la "Season" + numarul adecvat(daca e al 3 lea sezon numarul 3), apoi sezonul este aduagat in vectorul de sezoane si ratingul animeului este updatat la noua valoarea care ar trebui sa o aiba.
- clasa mai are getter pentru id.
  
Clasa Account:  
- contine variabilele:  
  - name reprezentand numele contului.  
  - password reprezinta parola contului.  
  - salt reprezinta un salt-ul care este folosit la criptarea parolei
  - variabila statica accounts, este un mapa care ne ajuta sa vedem daca numele unui cont este deja utilizat si tine minte numarul de apariti al acestuia  rezolvand coliziunile.
  - logged este o variabila care reprezinta daca la aces moment contul este logat
- costructorul verifica daca numele este unic, contine nu mai litere si cifre si daca parola contine cel putin o litera mare, una mica si o cifra, in caz contrat
atunca o exceptie potrivita, apoi creaza un salt unic si cripteaza parola + salt inlocuid valoarea parolei la valoarea criptata
- functia add_review verifica daca contul care adauga review-ul este logat si daca valoarea reviewului sa fie intre 0 si 10, daca nu este afiseaza un mesaj adecvat si review-ul nu este adaugat, daca este atunci se apeleaza functia add_review din clasa anime.  
- functia getPermissions este una pura virtuala.
- functia statica regexName este folosita pentru a verifica corectiudinea numelui.
- functia statica regexPassword este folosita pentru a verifica corectiudinea parolei.
- functia statica logIn verifica daca numele corespunde unui cont si daca parola este cea corect, in caz contrar arunca o exceptie corespunzatoare, apoi seteaza valoarea variabilei logged la true.
- functia logOut seteaza valoarea variabilei logged la false.
- functia statica make_salt genereaza un salt unic.
- functia statica hash_password genereaza un hash pentru parola folosid deigestpp.

clasa Admin:
- este derivata din clasa Account.
- nu are variabile in plus.
- functia getPermissions a fost supra scrisa returneaza un string cu permisiunile contului.
- are functionalitati in plus in meniul din clasa Meniu.

clasa User:
- este derivata din clasa Account.
- nu are variabile in plus.
- functia getPermissions a fost supra scrisa returneaza un string cu permisiunile contului.

clasa Meniu:
- este un meniu care leaga toate functionalitatile clasei.
- foloseste design paternul sigleton.
- are urmatoarele variabile:
  - admins, o mapa cu cheie de tip string care reprezinta numele si valoarea un obiect de tip admin, mapa este folosita pentru a retine toate conturile de tip admin si ale putea cauta rapid.
  - users , o mapa cu cheie de tip string care reprezinta numele si valoarea un obiect de tip user, mapa este folosita pentru a retine toate conturile de tip user si ale putea cauta rapid.
  - mapa episodes are ca cheie id-ul unui episod si este folosita pentru a retine toate episoadele si ale pute cauta rapid.
  - mapele seasons/animes/mangas/novels/scripts fac acelasi lucru pentru celalalte obiecte care trebuie retinute in cadrul meniu(seazoane/animeuri/serii manga/romane/scenarii).
- constructorul creaza un cont cu permisiunea de admin care are numele "FirstAdmin" si parola "Randompassword123".
- meniul permite logarea si crearea de conturi avand submeniuri diferite pentru cele 2 tipuri diferite de utilizatori.
- meniul de tip user permite vizionarea continutului din cadrul meniului si adaugarea de recenzi pentru sezoane.
- meniul de tip admin permite in plus adaugarea de continut.
- clasa are functiile template outputMapContents si readContent pentru a realiza functionalitile celor 2 meniuri.
- de asemenea pentru navigarea in submeniuri si functionalitati clasa mai are functiile: start(), logIn(), createAccount(), getEpisodes(), getSeasons(), getAnime(), getManga(), getNovel(), getScript(), meniuUser(), addContent(), addEpisodeSeason(), addSeasonAnime(), addChapter(), addVolum(), meniuAdmin().

  
Resurse:
- [digestpp](https://github.com/kerukuro/digestpp/tree/4ec4106677e652a90716ad929d657a622089ef16)
- [make_salt](https://github.com/mcmarius/oop-template/blob/common-libs/main.cpp)
