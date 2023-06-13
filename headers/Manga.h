#ifndef OOP_MANGA_H
#define OOP_MANGA_H

#include <iostream>
#include <string>
#include "AnimeInspirationSource.h"

class Manga: public AnimeInspirationSource {
private:
        std::string illustrator, artStyle;
        std::vector<std::string> chapters;
        std::vector<std::pair<int, int>> chapterDetails;
public:
    Manga() = default;
    Manga(const std::string &name_, const std::string& author_, const std::string& illustrator_, const std::string& artStyle_);
    Manga(const Manga &other) = default;
    Manga &operator=(const Manga &other);
    friend std::ostream &operator<<(std::ostream &os, Manga& mg);
    ~Manga() override = default;
    void addContent(const std::string& nume_, const int& pagini, const int& panele);
    [[nodiscard]] std::pair<int, int> getReadingTime(const unsigned int& parte) const override;
    [[nodiscard]] std::pair<int, int> getTotalReadingTime() const override;
};


#endif
