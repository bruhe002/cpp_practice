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
    Parent(int num) {
        this->num = num;
    }

    virtual void print() const {
        cout << "This is a Parent.\n";
    }
private:
    int num;
};

class Child : public Parent {
public:
    Child(int num) : Parent(num) {};

    void print() const {
        cout << "This is a Child.\n";
    }
};

class Grandchild : public Child {
public:
    Grandchild(int num) : Child(num) {};

    void print() const {
        cout << "This is a Grandchild.\n";
    }
};

void print_class(const Parent& p) {
    p.print();
}

int main() {
    // First implementation
    Parent par(6);
    Child kid(5);
    Grandchild gc(4);

    cout << "Printing the Object classes:\n";
    print_class(par);
    print_class(kid);
    print_class(gc);

    return 0;
}