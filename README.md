Tema contine o serie de clase care indeplinesc anumite functionalitatati ale unui site de animeuri.  
Ea este compusa din urmatoarele clase:  

Clasa Episode:  
- contine variabilele private:  
  - name care reprezinta numele unui episod, daca un nume nu este oferit acesta este initializat cu numele "Episode".  
  - duration care reprezinta lungimea unui episod in minute, daca o durata nu este oferita este initializat cu valoare 24 din constructor.    
- ca functii in plus de cele standard mai contine getteri pentru name si duration si setter pentru name.   
  
Clasa Season:  
- contine variabilele private:  
  - name, se refera la numele unui sezon, daca un nume nu este oferit se initializata cu numele "season".  
  - episodes, este un vector de pointeri catre obiecte de tipul Episode si reprezinta lista de episoade din sezon.  
  - reviews reprezinta reviewurile primite de sezonul, acest sunt adaugate din apelul functiei add_review, care se apeleaza din clasa Account dupa ce verificarile necesare au fost realizate, acestea sunt salvate sub forma unei mape cu cheia nume si valoarea rezprezentand ratingul reviewului astfel un cont poate avea un sigur review(numele sunt unice) si acesta este updatat cand se apeleaza inca odata functia add_review asupra obiectului de tip account.  
  - sumOfReviews reprezinta suma valorilor tuturor review-urilor, este intializata cu valoarea 0 si este updatata doar din apelul functiei add_review.  
  - nrReviews reprezinta numarul reviewurilor, care este de asemenea initializata cu valoarea 0 si este updatata doar din apelul functiei add_review.  
  - rating reprezint ratingul sezonului si este calculat ca find sumOfRating / nrReviews si updatat la fiecare apel al functiei add_review.  
- constructorul clasei primeste doar un string si seteaza valoarea numelui la acest string.  
- episoadele sunt aduagate din apelul functiei add_episode dupa ce verificarile necesare au fost facute in clasa Account, daca sezonul are numele standard("Episode"), numele este modificat la "Episode" + numarul adecvat(daca e al 3 lea episodul numarul 3), apoi episodul este adaugat in vectorul de episoade.  
- add_review adauga un review si este apelata din clasa Account, apoi realizeaza calculele necesare si updateaza valoarea ratingului.  
- clasa mai contine functia getLength care returneaza suma lungimilor tuturor episoadelor.  

Clasa AnimeInspirationSource:
- contine variabilele:
  - name care reprezinta numele seriei pe care este bazat un anime.
  - author care reprezinta autorul care a scris seria.
  - content care este un vector care contine partile seriei.
- Functia addContent adauga element in vectorul content.
- Functia afisare este folosita pentru a afisa derivatele clasei.
- Functia clone este una pura virtuala.

Clasa Manga:  
- mosteneste clasa AnimeInspirationSource, nu are variabile in plus.   
- Functia addContent a fost suprascrisa cu mici modificari.
- Functia clone a fost suprascrisa pentru a clona un obiect.
  
Clasa Novel:  
- mosteneste clasa AnimeInspirationSource, nu are variabile in plus.   
- Functia addContent a fost suprascrisa cu mici modificari.
- Functia clone a fost suprascrisa pentru a clona un obiect.

Clasa Anime:  
- cotine variabilele private:  
  - Name reprezinta numele unui anime.  
  - seasons reprezinta un vector de pointeri catre obiecte de tip Season care reprezinta sezoanele animeului.  
  - rating reprezinta ratingul animeului si este calculat ca find valoarea medie a ratingului unui sezon. 
  - source care este un pointer catre un obiect de tip AnimeInspirationSource
- contine functia getLegth care calculeaza lungimea totala a animeului adunand lungimea tuturor sezoaenelor, apoi o afiseaza pe ecran si o returneaza.  
- contine functia ratingUpdate care recalculeaza ratingul unui anime si poate fi apelata la modificarea ratingului unui sezon.  
- sezoanele sunt adaugate in urma apelului functiei add_season, care este apelata din clasa account dupa ce toate verificarile au fost realizate, daca sezonul are numele standard("Season"), numele este modificat la "Season" + numarul adecvat(daca e al 3 lea sezon numarul 3), apoi sezonul este aduagat in vectorul de sezoane si ratingul animeului este updatat la noua valoarea care ar trebui sa o aiba.  
  
Clasa Account:  
- contine variabilele:  
  - name reprezentand numele contului.  
  - password reprezinta parola contului.  
  - variabila statica accounts, este un mapa care ne ajuta sa vedem daca numele unui cont este deja utilizat si tine minte numarul de apariti al acestuia  rezolvand coliziunile.
  - logged este o variabila care reprezinta daca la aces moment contul este logat
- costructorul verifica daca numele este unic, contine nu mai litere si cifre si daca parola contine cel putin o litera mare, una mica si o cifra, in caz contrat
atunca o exceptie potrivita
- functia add_review verifica daca contul care adauga review-ul este logat si daca valoarea reviewului sa fie intre 0 si 10, daca nu este afiseaza un mesaj adecvat si review-ul nu este adaugat, daca este atunci se apeleaza functia add_review din clasa anime.  
- functia getPermissions este una pura virtuala.
- functia statica regexName este folosita pentru a verifica corectiudinea numelui.
- functia statica regexPassword este folosita pentru a verifica corectiudinea parolei.
- functia statica logIn verifica daca numele corespunde unui cont si daca parola este cea corect, in caz contrar arunca o exceptie corespunzatoare, apoi seteaza valoarea variabilei logged la true.
- functia logOut seteaza valoarea variabilei logged la false.

clasa Admin:
- este derivata din clasa Account.
- nu are variabile in plus.
- are in plus functiile addSeason si addEpisod care verifca daca contul este logat, apoi adauga un episod la un sezon respectiv un sezon la un anime.
- functia getPermissions a fost supra scrisa returneaza un string cu permisiunile contului.

clasa User:
- este derivata din clasa Account.
- nu are variabile in plus.
- functia getPermissions a fost supra scrisa returneaza un string cu permisiunile contului.

Acesta este descrierea a proiectului.
