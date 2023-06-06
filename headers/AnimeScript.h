//
// Created by Ricardo ROG on 6/6/2023.
//

#ifndef OOP_ANIMESCRIPT_H
#define OOP_ANIMESCRIPT_H

#include <ostream>
#include "AnimeInspirationSource.h"

class AnimeScript: public AnimeInspirationSource  {
private:
    int nrPages, avgWordsPerPage;
public:
    AnimeScript(const std::string& name_, const std::string& author_,  const int & pages, const int& words);
    AnimeScript(const AnimeScript& other);
    AnimeScript &operator=(const AnimeScript& other);
    friend std::ostream &operator<<(std::ostream &os, AnimeScript &script);
    ~AnimeScript() override;
    [[nodiscard]] AnimeInspirationSource* clone() const override;
    [[nodiscard]] std::pair<int, int> getReadingTime(const unsigned int& parte) const override;
    [[nodiscard]] std::pair<int, int> getTotalReadingTime() const override;
};


#endif //OOP_ANIMESCRIPT_H
