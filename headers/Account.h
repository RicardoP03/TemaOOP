//
// Created by Ricardo ROG on 5/5/2023.
//

#ifndef OOP_ACCOUNT_H
#define OOP_ACCOUNT_H

#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include "Season.h"
#include "Anime.h"

class Account{
private:
    std::string name;
    std::string password;
    static std::map<std::string, std::shared_ptr<Account>> accounts;
protected:
    bool logged = false;
public:
    Account(const std::string& name_, const std::string& password_);
    Account(const Account& other);
    Account &operator=(const Account& other);
    friend std::ostream& operator<<(std::ostream& os, const Account& ac);
    virtual ~Account();
    virtual std::string getPermissions() const = 0;
    void add_review(Season& se, const int& rating);
    static void logIn(const std::string& name_, const std::string& password_);
    void logOut();
    static bool regexName(const std::string& name_);
    static std::string regexPassword(const std::string& password_);
};

#endif //OOP_ACCOUNT_H
