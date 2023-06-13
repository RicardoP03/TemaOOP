#ifndef OOP_ANIMEINSPIRATIONSOURCE_H
#define OOP_ANIMEINSPIRATIONSOURCE_H

#include <iostream>
#include <vector>
#include <string>

class AnimeInspirationSource {
private:
    static int idMax;
    int id;
    std::string name;
    std::string author;
protected:
    void afisare(std::ostream& os, const std::string& tp);
public:
    AnimeInspirationSource() = default;
    AnimeInspirationSource(const std::string& name_, const std::string& author_);
    AnimeInspirationSource(const AnimeInspirationSource& other) = default;
    AnimeInspirationSource& operator=(const AnimeInspirationSource& other) = default;
    friend std::ostream &operator<<(std::ostream& os, const AnimeInspirationSource& ais);
    virtual ~AnimeInspirationSource() = default;
    [[nodiscard]] virtual std::pair<int, int> getReadingTime(const unsigned int& parte) const = 0;
    [[nodiscard]] virtual std::pair<int, int> getTotalReadingTime() const = 0;
    int getId() const;
};


#endif
