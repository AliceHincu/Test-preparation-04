//
// Created by Sakura on 5/23/2021.
//

#ifndef VEGETABLES_SERVICE_H
#define VEGETABLES_SERVICE_H


#include "Repository.h"

class Service {
public:
    Service(Repository &repo);
    void addObject(const std::string&, const std::string&, std::vector<std::string>);
    void readFile();
    std::vector<Object> getObjects();
    std::vector<std::string> tokenize(const std::string& str, char delimiter);
    std::vector<Object> getUniqueObjects();
    std::vector<Object> getFamilyObjects(const std::string &family);
    Object getObjectBasedOnName(const std::string &veggie);
    ~Service();

private:
    Repository repo;
    std::string fileName = "Objects.txt";
    char delimitator = '|';

};


#endif //VEGETABLES_SERVICE_H
