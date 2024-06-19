#pragma once
#include <iostream>
#include <string>

class Name {
protected:
    std::string objectName;

public:
    Name(const std::string& aName);
    Name();
    ~Name();
};
