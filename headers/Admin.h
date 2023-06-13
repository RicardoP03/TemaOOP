#ifndef OOP_ADMIN_H
#define OOP_ADMIN_H

#include <iostream>
#include "Account.h"

class Admin: public Account {
public:
    Admin() = default;
    Admin(const std::string& name_, const std::string& password_);
    Admin(const Admin& other) = default;
    Admin& operator=(const Admin& other);
    friend std::ostream &operator<<(std::ostream& os, const Admin& ad);
    ~Admin() override = default;
    [[nodiscard]] std::string getPermissions() const override;
};


#endif
