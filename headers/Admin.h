#ifndef OOP_ADMIN_H
#define OOP_ADMIN_H

#include <iostream>
#include "Account.h"

class Admin: public Account {
public:
    Admin(const std::string& name_, const std::string& password_);
    Admin(const Admin& other);
    Admin& operator=(const Admin& other);
    friend std::ostream &operator<<(std::ostream& os, const Admin& ad);
    virtual ~Admin() override;
    void add_season(Anime& an, Season& se);
    void add_episode(Season& se, Episode& ep);
    std::string getPermissions() const override;
};


#endif
