#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
    ~Vector();

    Vector();

    Vector(const Vector &other);

    Vector(const size_t& size, int* initValue);

    Vector& operator=(const Vector &other);

    size_t Size() const;

    int& operator[](const size_t &index);

    int find(const int &value) const;

    void push_back(const int &value);

    Vector replace(const int &oldValue, const int &newValue);

    friend std::ostream& operator<<(std::ostream &out, const Vector &VEC_);
    
private:
    int* num;
    size_t size = 0; // выделенная память
    size_t lenght = 0; //кол-во элементов
};

#endif VECTOR_H
