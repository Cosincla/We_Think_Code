#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <cfloat>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Invalid arguments" << std::endl;
        return (0);
    }
    std::string str = argv[1];
    std::size_t floatc = str.find("f");
    std::size_t doublec = str.find(".");
    int long fint = atol(str.c_str());
    double d = atof(str.c_str());
    if (isnan(d)){
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    else if (d > FLT_MAX || d > DBL_MAX){
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (d < FLT_MIN || d < DBL_MIN){
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else if (fint != 0 && floatc == 0 && doublec == 0 && fint >= INT_MIN && fint <= INT_MAX){
        std::cout << "Int type" << std::endl;
        if (isprint(fint))
            std::cout << "Char: '" << static_cast<char>(fint) << "'" << std::endl;
        else
            std::cout << "Char: Not displayable" << std::endl;
        std::cout << "Int: " << fint << std::endl;
        if (isfinite(d) && !isnan(d)){
            std::cout << "Float: " << static_cast<float>(d) << ".0f" << std::endl;
            std::cout << "Double: " << static_cast<double>(d) << ".0" << std::endl;
        }
        else {
            std::cout << "Float: Not displayable" << std::endl;
            std::cout << "Double: Not displayable" << std::endl;
        }
    }
    else if (floatc == static_cast<std::size_t>(-1) && d >= DBL_MIN && d <= DBL_MAX){
        std::cout << "Double type" << std::endl;
        if (isprint(d))
            std::cout << "Char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "Char: Not displayable" << std::endl;
        std::cout << "Int: " << static_cast<int>(d) << std::endl;
        if (isfinite(d) && !isnan(d)){
            std::cout << "Float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "Double: " << d << std::endl;
        }
        else {
            std::cout << "Float: Not displayable" << std::endl;
            std::cout << "Double: Not displayable" << std::endl;
        }
    }
    else if (d >= FLT_MIN && d <= FLT_MAX){
        std::cout << "Float type" << std::endl;
        float f = static_cast<float>(d);
        if (isprint(f))
            std::cout << "Char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "Char: Not displayable" << std::endl;
        std::cout << "Int: " << static_cast<int>(f) << std::endl;
        if (isfinite(d) && !isnan(d)){
            std::cout << "Float: " << f << "f" << std::endl;
            std::cout << "Double: " << static_cast<double>(d) << std::endl;
        }
        else {
            std::cout << "Float: Not displayable" << std::endl;
            std::cout << "Double: Not displayable" << std::endl;
        }
    } 
    else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (0);
    }
}