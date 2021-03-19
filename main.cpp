#include <iostream>
#include "Vector.h"

int main(){
    Vector(); //конструктор по умолчанию
    int mass[10] = {1,2,3,4,5,6,7,8,9,10}; // конструктор с параметрами
    Vector Primer1(10, mass);

    Vector Primer2 = Primer1; //оператор присваивания

    Vector Primer3(Primer1);// конструктор копирования

    std::cout << "Оператор присваивания: "<< Primer2 << '\n';

    std::cout << "Конструктор копирования: "<< Primer3 << '\n';

    std::cout<< "возврат по индексу: " << Primer1[5] << '\n';//возврат по индексу

    Primer1.replace(3,5);

    std::cout <<"Реплейс: " << Primer1 << '\n'; //Реплейс

    std::cout <<"Кол-во эл-тов: " <<  Primer1.Size() << '\n'; //Кол-во эл-тов

    Primer1.push_back(3); //пуш_бэк

    std::cout <<"Пуш бэк и вывод вектора: " << Primer1 << '\n';

    std::cout <<"Файнд :" <<Primer1.find(3) << '\n'; //Файнд
}
