#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Constructor called" << std::endl;
    fixed = 0;
}
Fixed::Fixed(const int j){
    std::cout << "Int Constructor called" << std::endl;
    fixed = j << i;
}
Fixed::Fixed(const float f){
    std::cout << "Float Constructor called" << std::endl;
    fixed = static_cast<int>(roundf(f * (1 << i)));
}
Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy Constructor called" << std::endl;
    fixed = obj.fixed;
};
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits() const{
    std::cout << "getRawBits called" << std::endl;
    return fixed;
}
void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits called" << std::endl;
    fixed = raw;
}
int Fixed::toInt() const{
    return fixed >> i;
}
float Fixed::toFloat() const{
    return static_cast<float>(fixed) / (1 << i);
}

Fixed &Fixed::operator=(const Fixed &first){
    std::cout << "Assignment overload called" << std::endl;
    this->fixed = first.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f){
    return out << f.toFloat();
}