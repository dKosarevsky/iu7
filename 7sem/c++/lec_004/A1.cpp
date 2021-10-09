//
// Created by if on 10/9/21.
//

#include "A1.h"

int A1::sc = 2;

inline
int A1::f() {
    this->a = 3; //this - указатель на объект.
    //this можно не писать (?)
    return a;
}

int A1::f() const {
    return 0;
}

int A1::g() {
    return 0;
}
