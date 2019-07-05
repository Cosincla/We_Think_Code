#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade):name(_name), grade(_grade){
}
Bureaucrat::Bureaucrat(const Bureaucrat &obj){
    grade = obj.grade;
}
const std::string Bureaucrat::getname() const{
    return name;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &first){
    this->grade = first.grade;
    return *this;
}
Bureaucrat::~Bureaucrat(){
}
void Bureaucrat::gradeinc(){
    grade--;
    if (grade < 0)
    {
        throw GradeTooHighException();
    }
}
void Bureaucrat::gradedec(){
    grade++;
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
}
int Bureaucrat::getgrade() const{
    return grade;
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &f){
    return out << f.getname() << ", Grade: " << f.getgrade() << std::endl;
}

Bureaucrat::GradeTooHighException:std::exception