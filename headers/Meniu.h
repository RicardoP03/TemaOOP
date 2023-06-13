#ifndef OOP_MENIU_H
#define OOP_MENIU_H

#include <iostream>
#include <string>
#include <map>
#include <any>
#include <cstdlib>
#include <variant>
#include "Anime.h"
#include "Manga.h"
#include "Novel.h"
#include "AnimeScript.h"
#include "Admin.h"
#include "User.h"


class Meniu {
private:
    std::map<std::string, Admin> admins;
    std::map<std::string, User> users;
    std::map<int, Episode> episodes;
    std::map<int, Season> seasons;
    std::map<int,  std::variant<Anime<Manga>, Anime<AnimeScript>, Anime<Novel>>> animes;
    std::map<int, Manga> mangas;
    std::map<int, Novel> novels;
    std::map<int, AnimeScript> scripts;
    Meniu();
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;
    static Meniu& get_meniu();
    void start();
    void logIn();
    void createAccount();
    template<typename T>
    void outputMapContents(const std::map<int, T>& map);
    void getEpisodes();
    void getSeasons();
    void getAnime();
    void getManga();
    void getNovel();
    void getScript();
    void meniuUser(User& u);
    void addContent(Admin &a);
    void addEpisodeSeason(Admin &a);
    void addSeasonAnime(Admin &a);
    void addChapter(Admin &a);
    void addVolum(Admin & a);
    void meniuAdmin(Admin &a);
    template <typename T>
    T readContent();
};


#endif //OOP_MENIU_H
