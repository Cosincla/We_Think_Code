#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
private:
    int fixed;
    static const int i = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed &operator=(const Fixed &first);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif