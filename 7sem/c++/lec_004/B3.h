//
// Created by if on 10/9/21.
//

#ifndef OOP_LEC_004_B3_H
#define OOP_LEC_004_B3_H


#include "A2.h"

class B3 : /*private V protected V public*/public A2 {
private:
    int c;
protected:
    int d;
public:
    int g();

    using A2::f; //при такой записи будет изменен уровень доступа для всех методов с именем f
    //это восстановление уровня доступа при схеме private и protected для члена
};


#endif //OOP_LEC_004_B3_H
