#ifndef OOP_USER_H
#define OOP_USER_H

#include "Account.h"

class User:public Account {
public:
    User(const std::string& name_, const std::string& password_);
    User(const User& other);
    User& operator=(const User& other);
    friend std::ostream &operator<<(std::ostream& os, const User& us);
    ~User() override;
    [[nodiscard]] std::string getPermissions() const override;
};


#endif
