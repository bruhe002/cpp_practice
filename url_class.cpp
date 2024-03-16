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
    Url(const string& protocol, const string& resource) {
        this->protocol = protocol;
        this->resource = resource;
    }

    void displayUrl() {
        cout << protocol << "://" << resource;
    }

    ~Url() {}
private:
    string protocol;
    string resource;
};

// int main() {
//     // Testing URL class
//     // Make string variables
//     string protocol = "http";
//     string resource = "www.youtube.com";
//     // Instantiate an object
//     Url test_addr(protocol, resource);

//     // Test method
//     test_addr.displayUrl();

//     return 0;
// }