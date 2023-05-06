#ifndef OOP_ANIMEINSPIRATIONSOURCE_H
#define OOP_ANIMEINSPIRATIONSOURCE_H

#include <iostream>
#include <vector>

class AnimeInspirationSource {
private:
    std::string name;
    std::string author;
protected:
    std::vector<std::string> content;
    virtual void afisare(std::ostream& os, const std::string& tp);
public:
    AnimeInspirationSource(const std::string& name_, const std::string& author_);
    AnimeInspirationSource(const AnimeInspirationSource& other);
    AnimeInspirationSource& operator=(const AnimeInspirationSource& other);
    friend std::ostream &operator<<(std::ostream& os, const AnimeInspirationSource& ais);
    virtual ~AnimeInspirationSource();
    virtual void addContent(const std::string& s);
    virtual AnimeInspirationSource* clone() const = 0;
};


#endif
