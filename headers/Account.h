#ifndef OOP_ACCOUNT_H
#define OOP_ACCOUNT_H

#include <iostream>
#include <set>
#include <memory>
#include <stdexcept>
#include "Season.h"
#include "Anime.h"

class Account{
private:
    std::string name;
    std::string password;
    static std::set <std::string> accounts;
protected:
    bool logged = false;
public:
    Account(const std::string& name_, const std::string& password_);
    Account(const Account& other);
    Account &operator=(const Account& other);
    friend std::ostream& operator<<(std::ostream& os, const Account& ac);
    virtual ~Account();
    [[nodiscard]] virtual std::string getPermissions() const = 0;
    void add_review(Season& se, const int& rating);
    void logIn(const std::string& name_, const std::string& password_);
    void logOut();
    static bool regexName(const std::string& name_);
    static std::string regexPassword(const std::string& password_);
};

#endif
