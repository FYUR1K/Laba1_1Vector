#include <iostream>
#include "Vector.h"

    Vector::~Vector(){
        if(num != nullptr) {
            delete[] num;
            size = 0;
            lenght = 0;
        }
    }

    Vector::Vector(){ //конструктор по умолчанию
        num = new int[10];
        size = 10;
    }

    Vector::Vector(const Vector &other){ // конструктор копирования
        num = new int[other.Size()];
        for(size_t i = 0; i < other.Size(); ++i ){
            num[i] = other.num[i];
        }
        lenght = other.Size();
    }

    Vector::Vector(const size_t& size, int* initValue){ // конструктор с параметрами
        num = new int[size];
        for(size_t i = 0; i < size; ++i){
            num[i] = initValue[i];
        }
        lenght = size;
    }

    Vector&  Vector::operator=(const Vector &other){ //оператор присваивания
        if(num != nullptr){
            delete[] num;
        }
        num = new int[size];
        for(size_t i = 0; i < size; ++i){
            num[i] = other.num[i];
        }
        lenght = size;
    }


    int&  Vector::operator[](const size_t &index){ //возврат по индексу
        return num[index];
    }

    size_t Vector::Size() const{ // Кол-во эл-тов
        return lenght;
    }

    int Vector::find(const int &value) const{ //файнд
        if(num != nullptr){
            for(size_t i = 0; i < lenght; ++i){
                if (num[i] == value){
                            return i;
                        }
                    }
        }
        return -1;
    }

    void  Vector::push_back(const int &value){ //пуш бэк
        if(size == lenght) {
            int *new_num = new int[size + 10];

            for (size_t i = 0; i < size; ++i) { //копируем старый вектор в нью_инт
                new_num[i] = num[i];
            }
            delete[] num;
            new_num[size] = value;
            size += 10;
            lenght++;

            num = new_num;
            new_num = nullptr;
        } else {
            num[lenght] = value;
            ++lenght;
        }
    }

    Vector  Vector::replace(const int &oldValue, const int &newValue){ //реплейс
        if(num != nullptr){
            for(size_t i = 0; i < lenght; ++i){
                if (num[i] == oldValue){
                    num[i] = newValue;
                }
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream &out,const Vector &VEC_ ){
    for(size_t i = 0; i < VEC_.Size(); ++i){
        out << VEC_.num[i] << " ";
    }
    out << "\n";
    return out;
}

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
