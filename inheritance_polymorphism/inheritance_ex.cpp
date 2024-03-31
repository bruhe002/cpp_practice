///////////////////////////////////////////////////
// @inheritance_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>

using namespace std;

class Parent {
public:
    void print() const {
        cout << "This is a Parent.\n";
    }
};

class Child : public Parent {
public:
    void print() const {
        cout << "This is a Child.\n";
    }
};

class Grandchild : public Child {
public:
    void print() const {
        cout << "This is a Grandchild.\n";
    }
};

void print_class(const Parent& p) {
    p.print();
}

int main() {

    return 0;
}