#ifndef OOP_MANGA_H
#define OOP_MANGA_H

#include <iostream>
#include "AnimeInspirationSource.h"

class Manga: public AnimeInspirationSource {
public:
    Manga(const std::string &name_, const std::string& author);
    Manga(const Manga &other);
    Manga &operator=(const Manga &other);
    void afisare(std::ostream& os, const std::string &tp) override;
    friend std::ostream &operator<<(std::ostream &os, Manga& mg);
    ~Manga() override;
    void addContent(const std::string &s) override;
    AnimeInspirationSource* clone() const override;
};


#endif
