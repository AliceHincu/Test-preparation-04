//
// Created by Sakura on 5/23/2021.
//

#ifndef VEGETABLES_OBJECT_H
#define VEGETABLES_OBJECT_H


#include <string>

class Object {
public:
    Object(const std::string &family, const std::string &name, std::vector<std::string> parts);

    Object();

    virtual ~Object();
    bool operator<(const Object&) const;
    bool operator==(const Object&) const;
    const std::string &getFamily() const;

    void setFamily(const std::string &family);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<std::string> &getParts() const;

    void setParts(const std::vector<std::string> &parts);

private:
    std::string family;
    std::string name;
    std::vector<std::string> parts;
};


#endif //VEGETABLES_OBJECT_H
