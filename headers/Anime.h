#ifndef OOP_ANIME_H
#define OOP_ANIME_H

#include <iostream>
#include <string>
#include "AnimeInspirationSource.h"
#include "Season.h"


template<typename T>
class Anime{
private:
    static int idMax;
    int id;
    std::string name;
    T source;
    std::vector<Season> seasons;
    long double rating = 0;
public:
    Anime() = default;
    Anime(const std::string& name_, const T& source_);
    Anime(const Anime& an) = default;
    Anime& operator=(const Anime& an) = default;
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, Anime<U>& anime);
    ~Anime() = default;
    int getLength();
    void ratingUpdate();
    void add_season(Season &se);
    int getId() const;
};


#include "../src/Anime.cpp"
#endif