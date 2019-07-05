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

bool Fixed::operator<(const Fixed &first) const{
    std::cout << "< overload called" << std::endl;
    return this->fixed < first.getRawBits();
}

bool Fixed::operator>(const Fixed &first) const{
    std::cout << "> overload called" << std::endl;
    return this->fixed > first.getRawBits();
}

bool Fixed::operator<=(const Fixed &first) const {
    std::cout << "<= overload called" << std::endl;
    return this->fixed <= first.getRawBits();
}

bool Fixed::operator>=(const Fixed &first) const{
    std::cout << ">= overload called" << std::endl;
    return this->fixed >= first.getRawBits();
}

bool Fixed::operator==(const Fixed &first) const{
    std::cout << "== overload called" << std::endl;
    return this->fixed == first.getRawBits();
}

bool Fixed::operator!=(const Fixed &first) const{
    std::cout << "!= overload called" << std::endl;
    return this->fixed != first.getRawBits();
}

Fixed Fixed::operator+(const Fixed &addon) const{
    std::cout << "+ overload called" << std::endl;
    return Fixed(this->toFloat() + addon.toFloat());
}

Fixed Fixed::operator-(const Fixed &addon) const{
    std::cout << "- overload called" << std::endl;
    return Fixed(this->toFloat() - addon.toFloat());
}

Fixed Fixed::operator*(const Fixed &addon) const{
    std::cout << "* overload called" << std::endl;
    return Fixed(this->toFloat() * addon.toFloat());
}

Fixed Fixed::operator/(const Fixed &addon) const{
    std::cout << "/ overload called" << std::endl;
    return Fixed(this->toFloat() / addon.toFloat());
}

Fixed Fixed::operator++(int) {
    std::cout << "++(int) overload called" << std::endl;
    Fixed F = Fixed(*this);
    fixed++;
    return F;
}

Fixed Fixed::operator--(int) {
    std::cout << "--(int) overload called" << std::endl;
    Fixed F = Fixed(*this);
    fixed--;
    return F;
}

Fixed &Fixed::operator++() {
    std::cout << "++() overload called" << std::endl;
    ++fixed;
    return *this;
}

Fixed &Fixed::operator--() {
    std::cout << "--() overload called" << std::endl;
    --fixed;
    return *this;
}

Fixed &max(Fixed &a, Fixed &b){
    if (a > b){
        return a;}
    else{
        return b;}
}

const Fixed &max(const Fixed &a, const Fixed &b){
    if (a > b){
        return a;}
    else{
        return b;}
}

Fixed &min(Fixed &a, Fixed &b){
    if (a < b){
        return a;}
    else{
        return b;}
}

const Fixed &min(const Fixed &a, const Fixed &b){
    if (a < b){
        return a;}
    else{
        return b;}
}

std::ostream &operator<<(std::ostream &out, const Fixed &f){
    return out << f.toFloat();
}