#include <iostream>
#include "/headers/Episode.h"
#include "/headers/Season.h"
#include "/headers/Manga.h"
#include "/headers/Novel.h"
#include "/headers/Account.h"
#include "/headers/Admin.h"
#include "/headers/User.h"

int main() {
    Admin a1{"Jhon", "Paaaa222"};
    try{
        Admin a2{"Jane", "Aaaa22"};
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    try{
        Admin a3{"Jhon", "Ajdsdjsk43"};
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    try{
        Admin a4{"Jho n", "Aaaa224dsd"};
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    User u1{"User1", "Paaaa222"};
    std::cout << u1.getPermissions();
    std::cout << a1.getPermissions();
    try{
        Account::logIn("Jhon", "Paaaa2222");
    }
    catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    Account::logIn("Jhon", "Paaaa222");
    Account::logIn("User1", "Paaaa222");
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
    n1.addContent("Viollet Evergarden 1");
    n1.addContent("Viollet Evergarden 2");
    std::cout << n1;
    Anime an1{"Viollet Evergarden", dynamic_cast<AnimeInspirationSource*> (&n1)};
    a1.add_season(an1, s1);
    a1.add_season(an1, s3);
    a1.add_review(s1, 9);
    Anime an2 = an1;
    an2.ratingUpdate();
    std::cout << an2;
    std::cout << "Animeul: " << an1.getName() << "are lungimea totala de " << an1.getLength() << " minute\n";
    Manga m1("Oshi no ko", "Aka Akasaka");
    m1.addContent("Oshi no ko chap 1");
    m1.addContent("Oshi no ko chap 2");
    std::cout << m1;
    a1.logOut();
    u1.logOut();
    return 0;
}