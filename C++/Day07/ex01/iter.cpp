#include <iostream>
#include <string>

template <typename T>
void print(T that){
    std::cout << that << std::endl;
}

template <typename T>
void iter(T *a, std::size_t size, void f(T const that)){
    std::size_t i = 0;
    while (i < size){
        f(a[i]);
        i++;
    }
}

int main(){
    char carr[3] = { 'c', 'd', 's' };
    int iarr[3] = { 3, 1, 2 };

    iter(carr, 3, print);
    iter(iarr, 2, print);
}