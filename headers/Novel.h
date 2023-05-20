#ifndef OOP_NOVEL_H
#define OOP_NOVEL_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "AnimeInspirationSource.h"

class Novel: public AnimeInspirationSource{
    std::vector<std::pair<std::string, std::string>> volumes;
    std::vector<std::pair<int, int>> bookDetails;
public:
    Novel(const std::string &name_, const std::string& author);
    Novel(const Novel &other);
    Novel &operator=(const Novel &other);
    friend std::ostream &operator<<(std::ostream &os, Novel& nv);
    ~Novel() override;
    void addContent(const std::string& nume, const std::string& editor, const int& nrpages, const int& avgWordsPage);
    [[nodiscard]] AnimeInspirationSource* clone() const override;
    [[nodiscard]] std::pair<int, int> getReadingTime(const unsigned int& parte) const override;
    [[nodiscard]] std::pair<int, int> getTotalReadingTime() const override;
};

#endif
