Tema contine o serie de clase care indeplinesc anumite functionalitatati ale unui site de animeuri.
Ea este compusa din urmatoarele clase:

Clasa Episode:
-contine variabile private name si duration care reprezinta numele, daca un nume nu este oferit acesta este initializat cu numele "Episode", durata, daca o durata nu este oferita este initializat cu valoare 24 din constructor.
-nu are nici o functie inafara de cele standard obligatori
-are classele prietene Anime, Season si Account

Clasa Season:
-contine variabilele locale: name, se refera la numele unui sezon, daca un nume nu este oferit se initializata cu numele "season", nrEpisodes, este intializat mereu cu 0 cand un sezon este creat, episodes, este un vector care contine obiecte de tipul Episode si reprezinta lista de episoade din sezon, reviews reprezinta review-urile primite de sezonul, acest sunt adaugate din apelul functiei add_review din class account, acestea sunt salvate subforma unei mapa cu cheia nume si ratingul review-ului astfel un cont poate avea un sigur review(numele sunt unice) si acesta este updatat cand se mai apeleaza odata functia add_review asupra obiectului de tip account, sumOfReviews si nrReviews reprezinta suma valorile tuturor review-urilor, ele sunt intializate cu valoarea 0 si sunt updatate doar din apelul fuctiei add_review, respectiv numarul lor, mai contine si variabila rating care reprezint ratingul sezonului si este calculat ca find sumOfRating / nrReviews.
-constructorul clasei primeste doar un string si seteaza valoarea numelui la acest string si nrEpisodes la valoarea 0.
-episoadele sunt aduagate din apelul functiei add_episode din clasa account, daca obiectul de tip account are rolul "ADMIN"
-clasa mai contine functia getLength care afiseaza pe ecran lungimea tuturor episoadelor din clasa adunate, apoi returneaza aceasta valoare

Clasa Manga:
