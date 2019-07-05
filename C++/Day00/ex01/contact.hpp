#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
public:
    std::string Fname, Lname, Nname, login, Padd, Eadd, phone, Bday, Fmeal, Ucol, Dsec;

    std::string Check(std::string name){
        if (name.length() > 10){
            return name.substr(0,9) + ".";
        }
        return name;
    }
};

#endif