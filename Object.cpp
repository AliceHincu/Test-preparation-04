//
// Created by Sakura on 5/23/2021.
//

#include <vector>
#include "Object.h"

Object::Object(const std::string &family, const std::string &name, std::vector<std::string> parts) : family(
        family), name(name), parts(parts) {}

Object::Object(): name{""}, family{""}, parts{} {}

const std::string &Object::getFamily() const {
    return family;
}

void Object::setFamily(const std::string &family) {
    Object::family = family;
}

const std::string &Object::getName() const {
    return name;
}

void Object::setName(const std::string &name) {
    Object::name = name;
}

const std::vector<std::string> &Object::getParts() const {
    return parts;
}

void Object::setParts(const std::vector<std::string> &parts) {
    Object::parts = parts;
}

bool Object::operator<(const Object &other) const {
    return this->getFamily()<other.getFamily();
}

bool Object::operator==(const Object &other) const {
    return this->getFamily()==other.getFamily();
}

Object::~Object() = default;