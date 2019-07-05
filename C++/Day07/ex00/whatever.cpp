#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b){
    T c = a;
    a = b;
    b = c;
}
template <typename T>
T min(T a, T b){
    return (a < b ? a : b);
}
template <typename T>
T max(T a, T b){
    return (a > b ? a : b);
}

int main(){
    int a = 9;
    int b = 7;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "swap called" << std::endl;
    swap(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "min called" << std::endl;
    int c = min(a, b);
    std::cout << c << std::endl;
    std::cout << "max called" << std::endl;
    int d = max(a, b);
    std::cout << d << std::endl;
}