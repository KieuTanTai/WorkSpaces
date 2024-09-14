#include <iostream>
#include "Student.hpp"
class Student_List
{
     private:
          int Length;
          bool Replace_Mode, Remove_Mode;
          std::vector<Student> SV;
     public:
          Student_List(){Length = 0; Replace_Mode = false, Remove_Mode = false;}     //constructor
          //get methods
          //int get_Length(){return SV.size();}
          bool get_Replace_Mode(){return Replace_Mode;}
          bool get_Remove_Mode(){return Remove_Mode;}
          std::vector<Student> get_SV(){return SV;}
          //set methods
          void set_Replace_Mode(bool Replace_Mode){this->Replace_Mode = Replace_Mode;}
          void set_Remove_Mode(bool Remove_Mode){this->Remove_Mode = Remove_Mode;}
          //void set_Length(int Size){this->Length = Size;};
          // void set_SV(Student List_SV[100]){this->SV[100] = List_SV[100];}
          void Input();
          void Output();
          void Find_Student(int, bool, bool);
          void Replace();
          void Remove();
};

// Student information definition
void Student_List::Input()
{
     Student student; //preference to Student data
     std::cin>>student;
     SV.push_back(student);
     std::cout<<"add completed!"<<std::endl;
     // std::cin>>SV[Length];
     // Student_List::Add(SV[Length]);
}
//show student information
void Student_List::Output()
{
     std::cout<<"STUDENTS LIST: "<< std::endl;
     //setup 
     std::cout<<std::setfill(' ');
     std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
     std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
     std::cout<<std::setfill('-');
     std::cout<<std::setw(125)<<"-"<<std::endl;
     std::cout<<std::setfill(' ');
     //show information
     for(auto student:SV)
          std::cout <<student;
     //setup

     std::cout<<std::setfill('-');
     std::cout<<std::setw(125)<<"-"<<std::endl;
     std::cout<<std::setfill(' ');
}

