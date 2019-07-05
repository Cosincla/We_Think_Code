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
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif