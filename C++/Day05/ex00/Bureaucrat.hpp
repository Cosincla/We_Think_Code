#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string _name, int _grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &first);
    ~Bureaucrat();

    const std::string getname() const;
    int getgrade() const;
    void gradeinc();
    void gradedec();
    class wrrry : std::exception{
    };
    class GradeTooHighException : public std::exception {
        const char *what() const throw(){
            return "Grade too high.";
        }
    };
    class GradeTooLowException : public std::exception{
        const char *what() const throw(){
        return "Grade too low.";
        }
    };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &f);

#endif