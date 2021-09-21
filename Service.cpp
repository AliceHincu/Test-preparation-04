//
// Created by Sakura on 5/23/2021.
//

#include "Service.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>

Service::Service(Repository &repo) : repo(repo) {}

Service::~Service() = default;


void Service::addObject(const std::string &family, const std::string &name, std::vector<std::string> parts) {
    Object c{family, name, std::move(parts)};
    this->repo.addObjectRepo(c);
}

void Service::readFile() {
    // Read from the text file
    std::ifstream myFile(this->fileName);
    Object Object;

    if(myFile.is_open()) {
        std::string line;

        while(std::getline(myFile, line)) {
            std::vector<std::string> attributes = this->tokenize(line, this->delimitator);
            std::vector<std::string> edibleParts = this->tokenize(attributes[2], ',');
            this->addObject(attributes[0], attributes[1], edibleParts);
        }
    }
    else std::cout << "Problem with opening file!";
    // Close the file
    myFile.close();
}

std::vector<std::string> Service::tokenize(const std::string& str, char delimiter){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while(std::getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::vector<Object> Service::getObjects() {
    return this->repo.getObjectsRepo();
}

std::vector<Object> Service::getUniqueObjects() {
    auto obj= this->repo.getObjectsRepo();
    std::sort(obj.begin(), obj.end());
    auto ip = std::unique(obj.begin(), obj.end(), [](const Object& a, const Object& b) {return a.getFamily() == b.getFamily();});
    //auto ip = std::unique(obj.begin(), obj.end());
    obj.erase(ip, obj.end());

    return obj;
}

std::vector<Object> Service::getFamilyObjects(const std::string &family){
    auto obj= this->repo.getObjectsRepo();
    std::vector<Object> result;

    copy_if(obj.begin(), obj.end(), std::back_inserter(result), [family](const Object &o)
    {return o.getFamily() == family;});

    return result;
}

Object Service::getObjectBasedOnName(const std::string &veggie){
    auto obj= this->repo.getObjectsRepo();
    std::vector<std::string> result;
    for(const auto& it: obj){
        if (it.getName() == veggie) {
            return it;
        }
    }
    return Object();
}
