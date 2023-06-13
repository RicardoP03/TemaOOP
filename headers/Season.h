#ifndef OOP_SEASON_H
#define OOP_SEASON_H
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "Episode.h"


class Season{
private:
    static int idMax;
    int id;
    std::string name;
    std::vector<Episode> episodes;
    std::map<std::string, int> reviews;
    int sumOfRatings = 0, nrReviews = 0;
    long double rating = 0;
public:
    Season(const std::string& name_ = "Season");
    Season(const Season&other) = default;
    Season& operator=(const Season&other);
    friend std::ostream& operator<<(std::ostream& os, const Season& sez);
    ~Season() = default;
    int getLength();
    void add_episode(Episode& ep);
    void add_review(const std::string& accountName, const int& rate);
    std::string getName();
    [[nodiscard]] long double getRating() const;
    void setName(const std::string& newName);
    int getId() const;
};

class SeasonEpiosdeFactory{
public:
    static void addEpisodes(Season &s, const unsigned int& nr);
    static void addEpisodesNames(Season& s, std::vector<std::string>& names);
    static void addEpisodesDuration(Season& s, std::vector<int>& durations);
    static void addEpisodesNamesDuration(Season& s, std::vector<std::string>& names, std::vector<int>& durations);
};


#endif
