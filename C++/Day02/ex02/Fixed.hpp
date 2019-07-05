#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
private:
    int fixed;
    static const int i = 8;
public:
    Fixed();
    Fixed(const int j);
    Fixed(const float f);
    Fixed(const Fixed &obj);
    Fixed &operator=(const Fixed &first);
    bool operator<(const Fixed &first) const;
    bool operator>(const Fixed &first) const;
    bool operator<=(const Fixed &first) const;
    bool operator>=(const Fixed &first) const;
    bool operator==(const Fixed &first) const;
    bool operator!=(const Fixed &first) const;
    Fixed operator+(const Fixed &addon) const;
    Fixed operator-(const Fixed &addon) const;
    Fixed operator*(const Fixed &addon) const;
    Fixed operator/(const Fixed &addon) const;
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed &operator++();
    Fixed &operator--();
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

Fixed &max(Fixed &a, Fixed &b);
const Fixed &max(const Fixed &a, const Fixed &b);
Fixed &min(Fixed &a, Fixed &b);
const Fixed &min(const Fixed &a, const Fixed &b);


#endif