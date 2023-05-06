#ifndef OOP_SEASON_H
#define OOP_SEASON_H
#include <iostream>
#include <vector>
#include <map>
#include "Episode.h"


class Season{
private:
    std::string name;
    std::vector<Episode*> episodes;
    std::map<std::string, int> reviews;
    int sumOfRatings = 0, nrReviews = 0;
    long double rating = 0;
public:
    Season(std::string&& name_ = "Season");
    Season(const Season&other);
    Season& operator=(const Season&other);
    friend std::ostream& operator<<(std::ostream& os, const Season& sez);
    ~Season();
    int getLength();
    void add_episode(Episode& ep);
    void add_review(const std::string& accountName, const int& rate);
    std::string getName();
    [[nodiscard]] long double getRating() const;
    void setName(const std::string& newName);
    Season* clone();
};


#endif
