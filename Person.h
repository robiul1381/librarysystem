#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    std::string email;
    std::string address;

public:
    Person();
    Person(const std::string &fullName, const std::string &mail, const std::string &addr);

    // Getter and Setter methods
    std::string getName() const;
    void setName(const std::string &fullName);
    std::string getEmail() const;
    void setEmail(const std::string &mail);
    std::string getAddress() const;
    void setAddress(const std::string &addr);
};

#endif // PERSON_H
