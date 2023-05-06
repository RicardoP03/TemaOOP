#ifndef OOP_EPISODE_H
#define OOP_EPISODE_H
#include <iostream>

class Episode{
private:
    std::string name;
    int duration;
public:
    Episode(std::string&& name_ = "Episode", int duration_ = 24);
    Episode(const Episode& other);
    Episode& operator=(const Episode& other);
    friend std::ostream& operator<<(std::ostream& os, const Episode& ep);
    ~Episode();
    std::string getName();
    [[nodiscard]] int getDuration() const;
    void setName(const std::string& newName);
    Episode* clone();
};
#endif