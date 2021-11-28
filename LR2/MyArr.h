//
// Created by Павел Жуков on 21/11/2021.
//

#ifndef LR2_MYARR_H
#define LR2_MYARR_H

#include <exception>
#include <iostream>
#ifndef LR2_USEFUL_H
#include "useful.h"
#endif

template <class T>
class MyArr {
    int sz;
    T* arr;
public:
    MyArr();
    MyArr(const MyArr<T>& src);
    MyArr(int sz);
    ~MyArr();
    void sort(bool comparator(T&, T&));
    void operator << (T right);
    T operator >> (int right);
    T& operator[](int index) const;
    void push(T val);
    int getsz();
};

template<class T>
int MyArr<T>::getsz() {
    return sz;
}

template<class T>
MyArr<T>::MyArr(): sz(0), arr(nullptr) {
    std::cout << "MyArr created";
}

template<class T>
MyArr<T>::MyArr(const MyArr<T> &src): sz(src.sz) {
    arr = new T [sz];
    for (int i = 0; i < sz; i++){
        arr[i] = T(src[i]);
    }
    std::cout << "MyArr copied" << std::endl;
}

template<class T>
MyArr<T>::MyArr(int _sz) {
    if (_sz <= 0){
        sz = 0;
        arr = nullptr;
    } else {
        sz = _sz;
        arr = new T [sz];
    }
    std::cout << "MyArr of size " << sz << " initialized" << std::endl;
}

template<class T>
void MyArr<T>::sort(bool comparator(T&, T&)) {
    for(int i = 1; i < sz; i++){
        for (int j = 0; j < sz - i; j++){
            if (comparator(arr[j+1], arr[j])){
                T tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

template<class T>
T& MyArr<T>::operator[](int index) const{
    if (index < 0 || index >= sz){
        throw std::exception();
    }
    return arr[index];
}

template<class T>
MyArr<T>::~MyArr() {
    delete [] arr;
    std::cout << "Deleted MyArr" << std::endl;
}

template<class T>
void MyArr<T>::operator<<(T right) {
    if (sz == 0){
        sz++;
        arr = new T [sz];
        arr[0] = right;
    } else {
        std::cout << "Pass the place to insert the element.\n"
                     "Available positions: from " << 0 << " to " << sz << "\n"
                     "Your choice: ";
        int res = safe_input();
        while (res < 0 || res > sz){
            std::cout << "Wrong position. Try again: ";
            res = safe_input();
        }
        T* tmp = arr;
        arr = new T[++sz];
        int i2 = 0;
        for(int i = 0; i < sz; i++){
            if (i == res){
                arr[i] = right;
            } else {
                arr[i] = tmp[i2++];
            }
        }
        delete [] tmp;
    }
}

template<class T>
T MyArr<T>::operator>>(int right) {
    if (right < 0 || right >= sz){
        throw std::exception();
    }
    T res = T(arr[right]);
    T* tmp = arr;
    if (sz == 1){
        delete [] tmp;
        arr = nullptr;
        --sz;
        return res;
    }
    arr = new T[--sz];
    int i2 = 0;
    for (int i = 0; i < sz; i++){
        if (i == right){
            i2++;
        }
        arr[i] = tmp[i2++];
    }
    return res;
}

template<class T>
void MyArr<T>::push(T val) {
    T* tmp = arr;
    arr = new T [++sz];
    for (int i = 0; i < sz - 1; i++){
        arr[i] = T(tmp[i]);
    }
    arr[sz - 1] = T(val);
    delete [] tmp;
}


#endif //LR2_MYARR_H
