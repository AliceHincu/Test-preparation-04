//
// Created by Sakura on 5/23/2021.
//

#include "Repository.h"

Repository::Repository() = default;

Repository::~Repository() = default;

void Repository::addObjectRepo(const Object &Object) {
    this->Objects.push_back(Object);
}

std::vector<Object> Repository::getObjectsRepo() {
    return this->Objects;
}