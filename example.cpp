#include "counted_ptr.hpp"
#include <iostream>
#include <string>

// Compile with: g++ -O2 -Wall -Wextra -std=c++20 example.cpp -o example

struct user_t
{
    std::string name;
    bool is_admin = false;

    user_t(std::string name, bool is_admin) : name(std::move(name)), is_admin(is_admin) {}
};

using user_ptr = gto::counted_ptr<user_t>;

void print_user(const user_ptr &user) {
    std::cout << user->name << " is " << (user->is_admin ? "" : "not") << " admin" << std::endl;
}

int main()
{
    auto user1 = gto::make_counted<user_t>("admin", true);
    auto user2 = gto::make_counted<user_t>("jdoe", false);

    print_user(user1);
    std::cout << "user1.use_count() = " << user1.use_count() << std::endl;

    if (user1 != user2) {
        print_user(user2);
        std::cout << "user2.use_count() = " << user2.use_count() << std::endl;
    }

    user2 = user1;

    if (user1 != user2)
        print_user(user2);

    std::cout << "user1.use_count() = " << user1.use_count() << std::endl;

    user2 = nullptr;
    std::cout << "user2.reset()" << std::endl;
    std::cout << "user2.use_count() = " << user2.use_count() << std::endl;

    return 0;
}
