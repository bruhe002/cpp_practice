///////////////////////////////////////////////////
// @url_class.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

class Url {

public:
    Url(string& protoc, string& res) {
        this->protocol = protoc;
        this->resource = res;
    }

    void displayUrl() {
        cout << protocol << "://" << resource;
    }
private:
    string protocol;
    string resource;
};

