//
// Created by Ricardo ROG on 5/5/2023.
//

#ifndef OOP_NOVEL_H
#define OOP_NOVEL_H

#include <iostream>
#include "AnimeInspirationSource.h"

class Novel: public AnimeInspirationSource{
public:
    Novel(const std::string &name_, const std::string& author);
    Novel(const Novel &other);
    Novel &operator=(const Novel &other);
    void afisare(std::ostream& os, const std::string &tp) override;
    friend std::ostream &operator<<(std::ostream &os, Novel& nv);
    ~Novel() override;
    void addContent(const std::string &s) override;
    AnimeInspirationSource* clone() const override;
};


#endif //OOP_NOVEL_H
