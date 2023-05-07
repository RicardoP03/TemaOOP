#ifndef OOP_ANIME_H
#define OOP_ANIME_H

#include <iostream>
#include <string>
#include "AnimeInspirationSource.h"
#include "Season.h"

class Anime{
private:
    std::string name;
    AnimeInspirationSource* source;
    std::vector<Season> seasons;
    long double rating = 0;
public:
    Anime(std::string&& name_, AnimeInspirationSource* source_);
    Anime(const Anime& an);
    Anime& operator=(const Anime& an);
    friend std::ostream& operator<<(std::ostream& os, const Anime& an);
    ~Anime();
    int getLength();
    void ratingUpdate();
    void add_season(Season &se);
    std::string getName();
};

#endif