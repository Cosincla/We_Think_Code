#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Constructor called" << std::endl;
    fixed = 0;
}
Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy Constructor called" << std::endl;
    fixed = obj.fixed;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits() const{
    std::cout << "getRawBits called" << std::endl;
    return fixed;
}
Fixed &Fixed::operator=(const Fixed &first){
    std::cout << "Assignment overload called" << std::endl;
    this->fixed = first.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits called" << std::endl;
    fixed = raw;
}