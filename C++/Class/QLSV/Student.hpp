#include <iostream>
#include <cstring>
#include <bits/stdc++.h> // call most of library standard in C/C++
#include <iomanip> // setprecision library

class Student;
class Teacher;
class Student
{
    private:
        std::string Id, Name, First_Name, Last_Name, Major, Gender, Class;
        double GPA;
    public:
        Student();// constructor 
        Student(std::string, std::string, std::string, std::string, std::string, std::string, std::string, double);//constructor 
        friend std::istream &operator >> (std::istream &in, Student &In);
        friend std::ostream &operator << (std::ostream &out, Student In);
        void config_string();
        //get functions
        std::string get_Id(){return Id;}
        std::string get_First_Name(){return First_Name;}
        std::string get_Last_Name(){return Last_Name;}
        std::string get_Name(){return Name;}
        std::string get_Gender(){return Gender;}
        std::string get_Major(){return Major;}
        std::string get_Class(){return Class;}
        double get_GPA(){return GPA;}
        //set functions
        void set_Id(std::string Id){this->Id = Id; std::cout<<"replace done!";}
        void set_First_Name(std::string First_Name){this->First_Name = First_Name;}
        void set_Last_Name(std::string Last_Name){this->Last_Name = Last_Name;}
        void set_Name(std::string Name){this->Name = Name;}
        void set_Gender(std::string Gender){this->Gender = Gender;}
        void set_Major(std::string Major){this->Major = Major;}
        void set_Class(std::string Class){this->Class = Class;}
        void set_GPA(double GPA){this->GPA = GPA;}
};

// Student Information Definiton
    // ">>" operator overloading
std::istream &operator >> (std::istream &in, Student &In)
{
    std::cout << "ID: ";
    in >> In.Id;
    in.ignore();
    std::cout<< "Last Name: ";
    getline(in, In.Last_Name);
    std::cout << "First Name: ";
    getline(in, In.First_Name);
    In.Name = In.Last_Name + " " + In.First_Name;
    std::cout << "Gender: ";
    in>>In.Gender;
    in.ignore();
    std::cout << "Major: ";
    getline(in, In.Major);
    std::cout << "Class: ";
    getline(in, In.Class);
    std::cout <<"GPA: ";
    in>> In.GPA;
    return in;
}

// show data 
    // "<<" operator overloading
std::ostream &operator << (std::ostream &out, Student In)
{
    //setw: declare length of objects setfill: convert " " to anything you want
    //show information
    out<<std::setw(14)<<std::left<<In.Id<<std::setw(40)<<std::left<<In.Name;
    out<<std::setw(16)<<std::left<<In.Gender;
    out<<std::setw(30)<<std::left<<In.Major;
    out<<std::setw(17)<<std::left<<In.Class;
    out<<std::setw(8)<<std::right<<std::fixed<<std::setprecision(2)<<In.GPA<< std::endl;
    return out;
}
//define constructors
Student::Student(){}
Student::Student(std::string Id, std::string First_Name, std::string Last_Name, std::string Name, std::string Gender, std::string Major, std::string Class, double GPA)
{
    this->Id = Id;
    this->First_Name = First_Name;
    this->Last_Name = Last_Name;
    this->Name = Name;
    this->Gender = Gender;
    this->Major = Major;
    this->Class = Class;
    this->GPA = GPA;
}
