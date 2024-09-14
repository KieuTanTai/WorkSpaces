#include <iostream>
#include <cstdlib>
#include "Functions.hpp"
int Search();  //call for function below
int Declare_What_Are_You(Student_List);  //call for function below
void Choose_Options(int, Student_List); //call for function below

int Declare_What_Are_You(Student_List SV_SGU) //Switch Case Student_List
{
     int option_choose1;
     //Options for Everyone
     std::cout<<"CHOOSE ONE OF THE Student_List YOU WANT IN BELOW!"<<std::endl;
     std::cout<<std::setfill('*')<<std::setw(45)<<"*"<<std::endl;
     std::cout<<"You are a Student or teacher?\n";
     std::cout<<"I: Teacher."<<std::endl;
     std::cout<<"II: Student."<<std::endl;
     std::cout<<"III: Exit!"<<std::endl;
     std::cout<<std::setw(45)<<"*"<<std::endl;
     do
     {
          std::cout<<"Option you want (enter an integer number): ";
          std::cin>>option_choose1;
          if((option_choose1 < 0) || (option_choose1 > 3))
               std::cout<<"error option!"<<std::endl;
     }while((option_choose1 < 0) || (option_choose1 > 3));
     std::cout<<std::endl;
     Choose_Options(option_choose1, SV_SGU);
     return option_choose1;
}
void Choose_Options(int option_choose, Student_List SV_SGU)     //after choose list of options above
{
     bool edit_mod = false;
     int option_choose2, length;
     switch (option_choose)
     {
          //if user's a teacher
          case 1:
               std::cout<<"OPTIONS FOR TEACHER!"<<std::endl;
               std::cout<<std::setfill('=')<<std::setw(45)<<"="<<std::endl;
               std::cout<<"I: Import student's information."<<std::endl;
               std::cout<<"II: Show student's information."<<std::endl;
               std::cout<<"III: Find student with input's information."<<std::endl;
               std::cout<<"IV: Edit student's information."<<std::endl;
               std::cout<<"V: Remove student's information."<<std::endl;
               std::cout<<"VI: Exit!"<<std::endl;
               std::cout<<std::setw(45)<<"="<<std::setfill(' ')<<std::endl;
               std::cout<<"Option you want (enter an integer number): ";
               std::cin>>option_choose2;
               std::cout<<std::endl;
               break;
          //if user's a student
          case 2:
               std::cout<<"----------------------------------------------------\n";
               std::cout<<" don't have any function!"<<std::endl;
               std::cout<<"----------------------------------------------------\n";
               std::cout<<std::endl;
               break;
          //shutdown case
          case 3:
               std::cout<<"This function will be shutdown! "<<std::endl;
               return;
     } 
     //call Student_List
     system("clear");
     switch(option_choose2)
     {
          case 1:
               std::cout<<"\n \t STUDENT INFORMATION DEFINITON!"<<std::endl;
               std::cout<<"Total numbers of student you want to import: ";
               std::cin>>length;
               //length = SV_SGU.get_n();
               for(int i=0;i<length; i++)
               {
                    SV_SGU.Input();
               }
               //SV_SGU.Output();
               Choose_Options(option_choose, SV_SGU);//call again switch case function
               break;
          case 2:
               std::cout<<"\n \t SHOW STUDENT'S INFORMATION!"<<std::endl; 
               SV_SGU.Output();
               Choose_Options(option_choose, SV_SGU);//call again switch case function
               break;
          case 3:
               SV_SGU.Find_Student(Search(), SV_SGU.get_Replace_Mode(), SV_SGU.get_Remove_Mode());
               Choose_Options(option_choose, SV_SGU);//call again switch case function
               break;
          case 4:
               std::cout<<"\n \t ENABLE EDIT MODE!"<<std::endl;
               SV_SGU.Replace();
               Choose_Options(option_choose, SV_SGU);//call again switch case function
               break;
          case 5:
               std::cout<<"\n \t ENABLE REMOVE MODE!"<<std::endl;
               SV_SGU.Remove();
               Choose_Options(option_choose, SV_SGU);
               break;
          case 6:
               std::cout<<"This function will be shutdown! "<<std::endl;
               return;
     }

}
//after Declaration (for teacher)
int Search()
{
     int Temp_Num;
     //Options for teacher
     std::cout<<"OPTIONS FOR TEACHER!"<<std::endl;
     std::cout<<"*********************************************************\n";
     std::cout<<"I: Search through student's Id."<<std::endl;
     std::cout<<"II: Search through student's First Name."<<std::endl;
     std::cout<<"III: Search through student's Last Name."<<std::endl;
     std::cout<<"IV: Search through student's Full Name."<<std::endl;
     std::cout<<"V: Search through student's Gender"<<std::endl;
     std::cout<<"VI: Search through student's Major"<<std::endl;
     std::cout<<"VII: Search through student's Class"<<std::endl;
     std::cout<<"VIII: Search through student's GPA: "<<std::endl;
     std::cout<<"IX: Previous Options!"<<std::endl;
     std::cout<<"X: Exit!"<<std::endl;
     std::cout<<"*********************************************************\n";
     std::cout<<"Option you want (enter an integer number): ";
     std::cin>>Temp_Num;
     std::cout<<std::endl;
     return Temp_Num;
}

 //main
int main()
{
     Student_List SV_SGU;
     system("clear");
     Declare_What_Are_You(SV_SGU);
     return 0;

}

