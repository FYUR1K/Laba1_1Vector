#include <fstream>
#include "Vector.h"

Vector::~Vector(){
    if(num != nullptr) {
        delete[] num;
    }
}

Vector::Vector(){ //конструктор по умолчанию
    num = new int[10];
    size = 10;
}

Vector::Vector(const Vector &other){ // конструктор копирования
    num = new int[other.size];
    for(size_t i = 0; i < other.lenght; ++i ){
        num[i] = other.num[i];
    }
    lenght = other.Size();
    size = other.size;
}

Vector::Vector(const size_t& size, int* initValue){ // конструктор с параметрами
    num = new int[size];
    for(size_t i = 0; i < size; ++i){
        num[i] = initValue[i];
    }
    lenght = size;
    this->size = size;
}

Vector&  Vector::operator=(const Vector &other){ //оператор присваивания копированием
    if (this != &other){
        size = other.size;
        lenght = other.lenght;
        delete[] num;
        num = new int[size];
        for(size_t i = 0; i < size; ++i){
            num[i] = other.num[i];
        }
        return *this;
    }
    return *this;
}


int&  Vector::operator[](const size_t &index)const{ //возврат по индексу
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
                break;
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


