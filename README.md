Tema contine o serie de clase care indeplinesc anumite functionalitatati ale unui site de animeuri.
Ea este compusa din urmatoarele clase:

Clasa Episode:
-contine variabile private name si duration care reprezinta numele, daca un nume nu este oferit acesta este initializat cu numele "Episode", durata, daca o durata nu este oferita este initializat cu valoare 24 din constructor.
-nu are nici o functie inafara de cele standard obligatori

Clasa Season:
-contine variabilele locale: name, se refera la numele unui sezon, daca un nume nu este oferit se initializata cu numele "season", nrEpisodes, este intializat mereu cu 0 cand un sezon este creat, episodes, este un vector care contine obiecte de tipul Episode si reprezinta lista de episoade din sezon, reviews reprezinta review-urile primite de sezonul, acest sunt adaugate din apelul functiei add_review din class account, acestea sunt salvate subforma unei mapa cu cheia nume si ratingul review-ului astfel un cont poate avea un sigur review(numele sunt unice) si acesta este updatat cand se mai apeleaza odata functia add_review asupra obiectului de tip account, sumOfReviews si nrReviews reprezinta suma valorile tuturor review-urilor, ele sunt intializate cu valoarea 0 si sunt updatate doar din apelul fuctiei add_review, respectiv numarul lor, mai contine si variabila rating care reprezint ratingul sezonului si este calculat ca find sumOfRating / nrReviews.
-constructorul clasei primeste doar un string si seteaza valoarea numelui la acest string.
-episoadele sunt aduagate din apelul functiei add_episode din clasa account, daca obiectul de tip account are rolul "ADMIN"
-clasa mai contine functia getLength care afiseaza pe ecran lungimea tuturor episoadelor din clasa adunate, apoi returneaza aceasta valoare

Clasa Manga:
-contine variabilele: name si nrChapters, reprezentand numele si numarul de capitole
-momentan nu are nici o utilizare larga, o sa aiba in temele viitoare.

Clasa Novel:
-contine variabilele: name si nrVolums, reprezentand numele si numarul de volume
-momentan nu are nici o utilizare larga, o sa aiba in temele viitoare.

Clasa Anime:
-cotine variabilele locale: Name(reprezetand numele unui anime), nrSeasons reprezetand numarul de sezoane, este incarcat cu 0 mereu si poate fi modificat numai cu functia add_season din clasa Account, seasons reprezinta un vector de obiecte de timp Season care reprezinta sezoanele animeului si rating este ratingul animeului si este calculat ca find valoarea medie a ratingului unui sezon.
-constructorul clasei primeste doar un string si seteaza valoarea numelui la acest string.
-contine functia getLegth care calculeaza lungimea totala a animeului adunand lungimea tuturor sezoaenelor, apoi o afiseaza pe ecran si o returneaza
-contine functia ratingUpdate care recalculeaza ratingul unui anime si poate fi apelata la modificarea ratingului unui sezon

Clasa Account
-contine variabilele locale, name reprezentand numele, rol reprezentid rolul care e de tip "ADMIN" sau "USER", daca construtorul primeste orice alt string inafara de "ADMIN", seteaza automat rolul la "USER", password reprezinta parola contului si mai contine variabila statica accounts care este o mapa care ne ajuta sa vedem daca numele unui cont este deja utilizat.
-costructorul verifica daca numele este diferit de "ADMIN", daca este il seteaza automat la "USER, apoi verifica daca numele este in mapa, daca returneaza nu mesaj de eroare adecvat care va fi afisat de ecran(try and catch), daca nu este contul este creat.
-functia add_season, verifica daca contul care adauga sezon este admin, daca nu este sezonul nu este adaugat si se afiseaza un mesaj adecvat. Daca contul este cu rolul "ADMIN" atunci se verifica daca sezonul are numele stard("Season") si daca il are numele este modificat la "Season" + numarul adecvat(daca e al 3lea sezon numarul 3), apoi sezonul este aduagat in vectorul de sezoane si ratingul animeului este updatat la noua valoarea care ar trebui sa o aiba.
-functia add_episode, verifica daca contul care adauga episodul este admin, daca nu este episodul nu este adaugat si se afiseaza un mesaj adecvat. Daca contul este cu rolul "ADMIN" atunci se verifica daca sezonul are numele stard("Episode") si daca il are numele este modificat la "Episode" + numarul adecvat(daca e al 3lea sezon numarul 3), apoi sezonul este aduagat in vectorul de episoade.
-functia add_review verifica ca valoarea review-ului sa fie intre 0 si 10, daca nu este afiseaza un mesaj adecvat si review-ul nu este adaugat, daca este atunci ratingul pe care user la oferit este updatat la noua valoarea in mapa din clasa seasons, daca nu era prezent variabila nrReviews creste, apoi suma reviewurilor prin adunarea diferentei dintre valoarea veche si cea noua

Acesta este o scurta descriere a proiectului.
