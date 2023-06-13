#ifndef OOP_EPISODE_H
#define OOP_EPISODE_H
#include <iostream>

class Episode{
private:
    std::string name;
    int duration;
    int id;
    static int idMax;
public:
    Episode(const std::string& name_ = "Episode", int duration_ = 24);
    Episode(const Episode& other) = default;
    Episode& operator=(const Episode& other) = default;
    friend std::ostream& operator<<(std::ostream& os, const Episode& ep);
    ~Episode() = default;
    std::string getName();
    [[nodiscard]] int getDuration() const;
    void setName(const std::string& newName);
    [[nodiscard]] int getId() const;
};
#endif