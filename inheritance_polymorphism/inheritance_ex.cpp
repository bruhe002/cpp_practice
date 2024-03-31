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
    virtual void print() const {
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
    // First implementation
    Parent par;
    Child kid;
    Grandchild gc;

    cout << "Printing the FIRST Objects:\n";
    print_class(par);
    print_class(kid);
    print_class(gc);

    return 0;
}