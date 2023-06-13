#ifndef OOP_USER_H
#define OOP_USER_H

#include "Account.h"

class User:public Account {
public:
    User() = default;
    User(const std::string& name_, const std::string& password_);
    User(const User& other) = default;
    User& operator=(const User& other);
    friend std::ostream &operator<<(std::ostream& os, const User& us);
    ~User() override = default;
    [[nodiscard]] std::string getPermissions() const override;
};


#endif
