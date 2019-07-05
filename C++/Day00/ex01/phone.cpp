/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:19:01 by cosincla          #+#    #+#             */
/*   Updated: 2019/06/03 15:19:03 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

int main()
{
    int i = 0;
    std::string input;
    Contact phonebook[8];

    while(1){
        std::getline(std::cin, input);
        if (input == "EXIT"){
            break;
        }
        else if (input == "ADD"){
            if (i < 8){
                std::cout << "Please insert First Name:" << std::endl;
                std::getline(std::cin, phonebook[i].Fname);
                if (phonebook[i].Fname == ""){
                    phonebook[i].Fname = "(N/A)";
                }
                std::cout << "Please insert Last Name:" << std::endl;
                std::getline(std::cin, phonebook[i].Lname);
                if (phonebook[i].Lname == ""){
                    phonebook[i].Lname = "(N/A)";
                }
                std::cout << "Please insert Nickname:" << std::endl;
                std::getline(std::cin, phonebook[i].Nname);
                if (phonebook[i].Nname == ""){
                    phonebook[i].Nname = "(N/A)";
                }
                std::cout << "Please insert Login:" << std::endl;
                std::getline(std::cin, phonebook[i].login);
                if (phonebook[i].login == ""){
                    phonebook[i].login = "(N/A)";
                }
                std::cout << "Please insert Postal Address:" << std::endl;
                std::getline(std::cin, phonebook[i].Padd);
                if (phonebook[i].Padd == ""){
                    phonebook[i].Padd = "(N/A)";
                }
                std::cout << "Please insert Email Address:" << std::endl;
                std::getline(std::cin, phonebook[i].Eadd);
                if (phonebook[i].Eadd == ""){
                    phonebook[i].Eadd = "(N/A)";
                }
                std::cout << "Please insert Phone Number:" << std::endl;
                std::getline(std::cin, phonebook[i].phone);
                if (phonebook[i].phone == ""){
                    phonebook[i].phone = "(N/A)";
                }
                std::cout << "Please insert Date of Birth:" << std::endl;
                std::getline(std::cin, phonebook[i].Bday);
                if (phonebook[i].Bday == ""){
                    phonebook[i].Bday = "(N/A)";
                }
                std::cout << "Please insert Favourite Meal:" << std::endl;
                std::getline(std::cin, phonebook[i].Fmeal);
                if (phonebook[i].Fmeal == ""){
                    phonebook[i].Fmeal = "(N/A)";
                }
                std::cout << "Please insert Underwear Colour:" << std::endl;
                std::getline(std::cin, phonebook[i].Ucol);
                if (phonebook[i].Ucol == ""){
                    phonebook[i].Ucol = "(N/A)";
                }
                std::cout << "Please insert Darkest Secret:" << std::endl;
                std::getline(std::cin, phonebook[i].Dsec);
                if (phonebook[i].Dsec == ""){
                    phonebook[i].Dsec = "(N/A)";
                }
                std::cout << "Contact successfully added."  << std::endl;
                i++;
            }
            else{
                std::cout << "Phonebook is full" << std::endl;
            }
        }
        else if (input == "SEARCH"){
            if (i == 0) {
                std::cout << "Phonebook is empty" << std::endl;
            }
            else {
                while (1){
                    int j;
                    std::cout << "Please insert index number (Total indexes: " << i << "):" << std::endl;
                    std::cin >> j;
                    if (std::cin.fail()){
                        std::cin.clear();
                        std::cout << "NICE TRY JACKASS" << std::endl;
                    }
                    std::cin.ignore();
                    if (j <= 0 || j > i){
                        std::cout << "Invalid number" << std::endl;
                    }
                    else{
                        std::cout << "Index     |" << "First Name|" << "Last Name |" << "Nickname  |" << std::endl;
                        std::cout << std::setw(10) << std::setfill(' ') << j << "|";
                        std::cout << std::setw(10) << std::setfill(' ') << phonebook[(j - 1)].Check(phonebook[(j - 1)].Fname) << "|";
                        std::cout << std::setw(10) << std::setfill(' ') << phonebook[(j - 1)].Check(phonebook[(j - 1)].Lname) << "|";
                        std::cout << std::setw(10) << std::setfill(' ') << phonebook[(j - 1)].Check(phonebook[(j - 1)].Nname) << "|";
                        std::cout << std::endl;
                        break;
                    }
                }
            }
        }
        else {
            std::cout << "Please use 'ADD', 'SEARCH' or 'EXIT' commands" << std::endl;
        }
    }
    return (0);
}