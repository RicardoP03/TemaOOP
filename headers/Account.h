#ifndef OOP_ACCOUNT_H
#define OOP_ACCOUNT_H

#include <iostream>
#include <set>
#include <memory>
#include "Season.h"
#include "Anime.h"

class Account{
private:
    std::string name;
    std::string password;
    std::string salt;
    static std::set <std::string> accounts;
protected:
    void afisare(std::ostream& os) const;
    bool logged = false;
public:
    Account() = default;
    Account(const std::string& name_, const std::string& password_);
    Account(const Account& other) = default;
    Account &operator=(const Account& other);
    friend std::ostream& operator<<(std::ostream& os, const Account& ac);
    virtual ~Account() = default;
    [[nodiscard]] virtual std::string getPermissions() const = 0;
    void add_review(Season& se, const int& rating);
    void logIn(const std::string& name_, const std::string& password_);
    void logOut();
    static bool regexName(const std::string& name_);
    static std::string regexPassword(const std::string& password_);
    static std::string make_salt(); // cod preluat din https://github.com/mcmarius/oop-template/blob/common-libs/main.cpp
    static std::string hash_password(const std::string& plain, const std::string& salt);
};

#endif
