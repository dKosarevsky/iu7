#include <iostream>
#include <cstdarg>
#include <cstring>
#include <cstdio>

double sum(int count, ...) {
    // пример из лекции, суммирует адреса, а не значения, возможно криво переписал
    auto *p = (double *) (&count + 1);
    double s = 0.;
    for (int i = 0; i < count; i++) {
        s += p[i];
        // std::cout << p[i] << std::endl;
    }

    return s;
}


int sumArr(int count, ...) {
    // пример stackoverflow
    va_list ap;
    double tot = 0.;
    va_start(ap, count); //Requires the last fixed parameter (to get the address)
    for (int j = 0; j < count; j++)
        tot += va_arg(ap, double); //Requires the type to cast to. Increments ap to the next argument.
    va_end(ap);
    return tot;
}

char *concat(char *S, ...) {
    // пример из лекции, чёт не работает...
    char **Pstr = &S;
    unsigned len = 0;
    for (int i = 0; Pstr[i]; i++)
        len += strlen(Pstr[i]);
    char *sres = new char[len + 1];
    strcpy(sres, Pstr[0]);
    for (int i = 1; Pstr[i]; i++)
        strcat(sres, Pstr[i]);
    return sres;
}

void swap(double &d1, double &d2) {
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

double &maxElem(double *ar, int count) {
    double *pmax = ar;
    for (double *p = ar + 1; p - ar < count; p++)
        if (*p > *pmax)
            pmax = p;
    return *pmax;
}

int main() {
    // Функции с переменным числом параметров
    std::cout << std::endl << "1. Первый параметр информационный:" << std::endl;
    std::cout << sum(3, 1., 2., 3.) << std::endl;
    std::cout << sumArr(3, 1., 2., 3.) << std::endl;

    std::cout << std::endl << "2. Последний параметр терминатор:" << std::endl;
//    const char *words[20]={"DOG", "CAT", "ELEPHANT", "CROCODILE", "HIPPOPOTAMUS", "TORTOISE", "TIGER", "FISH", "SEAGULL", "SEAL", "MONKEY", "KANGAROO", "ZEBRA", "GIRAFFE", "RABBIT", "HORSE", "PENGUIN", "BEAR", "SQUIRREL", "HAMSTER"};
//    std::cout << concat((char *) words, 0) << std::endl;

    std::cout << std::endl << "3. Алиасы:" << std::endl;
    double foo[] = {1.1, 2.2, 3.3};
    swap(foo[0], foo[2]);
    std::cout << foo[0] << std::endl;

    std::cout << std::endl << "4. Поиск максимума:" << std::endl;
    std::cout << maxElem(foo, 3) << std::endl;


    return 0;
}
