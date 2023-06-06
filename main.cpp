#include <iostream>
#include "headers/Episode.h"
#include "headers/Season.h"
#include "headers/Manga.h"
#include "headers/Novel.h"
#include "headers/Account.h"
#include "headers/Admin.h"
#include "headers/User.h"
#include "headers/AnimeScript.h"

int main() {
    Admin a1{"Jhon", "ParolaAccounta1"};
    User u1{"User1", "ParolaAccountu1"};
    std::cout << u1.getPermissions();
    std::cout << a1.getPermissions();
    try{
        a1.logIn("Jhon", "ParolaAccounta");
        Episode ep{"Episod 1", 25};
        Season s{"sezon 1"};
        s.add_episode(ep);
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what();
    }
    a1.logIn("Jhon", "ParolaAccounta1");
    u1.logIn("User1", "ParolaAccountu1");
    Episode e1{"Episode 1", 25};
    Episode e2{"Episode", 25};
    Episode e3{"Not coming back", 25};
    Episode e4{"Episode", 25};
    Season s1 = {"Season"};
    a1.add_episode(s1, e1);
    a1.add_episode(s1, e2);
    a1.add_episode(s1, e3);
    a1.add_episode(s1, e4);
    Episode e5 = {"Episode 1", 24};
    Episode e6 = {"Episode 2", 24};
    Episode e7 = {"Episode 3", 24};
    Episode e8 = {"Episode 4", 24};
    Season s2 = {"Season 2"};
    a1.add_episode(s2, e5);
    a1.add_episode(s2, e6);
    a1.add_episode(s2, e7);
    a1.add_episode(s2, e8);
    u1.add_review(s1, 9);
    a1.add_review(s1, 8);
    u1.add_review(s2, 9);
    a1.add_review(s2, 10);
    Season s3 = s2;
    Novel n1("Viollet Evergarden", "Kana Akatsuki");
    n1.addContent("Viollet Evergarden 1", "Yasuhiro Takemoto", 218, 299);
    n1.addContent("Viollet Evergarden 2", "Yasuhiro Takemoto", 190, 310);
    std::cout << n1;
    std::cout << "Citirea ar dura intre " << n1.getTotalReadingTime().first << " - " << n1.getTotalReadingTime().second << " minute\n";
    AnimeInspirationSource* inspirationSource = new Novel(n1);
    Anime an1{"Viollet Evergarden", inspirationSource};
    a1.add_season(an1, s1);
    a1.add_season(an1, s3);
    a1.add_review(s1, 9);
    Anime an2 = an1;
    an2.ratingUpdate();
    std::cout << an2;
    std::cout << "Animeul: " << an1.getName() << "are lungimea totala de " << an1.getLength() << " minute\n";
    Manga m1("Oshi no ko", "Aka Akasaka", "Mengo Yokoyari", "Kawaii");
    m1.addContent("Oshi no ko chap 1", 34, 130);
    m1.addContent("Oshi no ko chap 2", 28, 93);
    std::cout << m1;
    std::cout << "Citirea ar dura intre " << m1.getTotalReadingTime().first << " - " << m1.getTotalReadingTime().second << " minute\n";
    AnimeScript as1("CYBERPUNK script", "Masahiko Otsuka", 230, 400);
    std::cout << as1;
    std::cout << "Citirea ar dura intre " << as1.getTotalReadingTime().first << " - " << as1.getTotalReadingTime().second << " minute\n";
    a1.logOut();
    u1.logOut();
    delete inspirationSource;
    return 0;
}