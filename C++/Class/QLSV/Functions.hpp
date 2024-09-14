#include <iostream>
//#include <algorithm>
#include "Save_Data.hpp"
// find Student for show information or Replace
void Student_List::Find_Student(int num, bool Replace_Mode, bool Remove_Mode)
{
     bool find_mode = false;
     switch(num)
     {
          case 1: //show Id and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_Id, Replace_Id;
                    std::cout<<"Enter Id: ";
                    std::cin>>Temp_Id;
                    if(SV.size()==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(auto i = 0; i<length; i++)
                    {
                         //find function
                         if(Temp_Id == SV[i].get_Id())
                         {
                              find_mode = true; //replace file_mode
                              //Replace function
                              if((Replace_Mode == true) && (Remove_Mode == false))
                              {
                                   std::cout<<"Replace id: ";
                                   std::cin>>Replace_Id;
                                   SV[i].set_Id(Replace_Id);
                              }
                              //remove mode
                              else if((Replace_Mode == false) && (Remove_Mode == true))
                              {
                                   SV.erase(SV.begin() + i);
                                   break;
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                              break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 2: //show First Name and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_FN, Replace_First_Name;
                    std::cout<<"Enter First Name: ";
                    std::cin>>Temp_FN;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i = 0; i<length; i++)
                    {
                         if(Temp_FN == SV[i].get_First_Name())
                         {
                              find_mode = true; //replace file mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace First Name: ";
                                   std::cin>>Replace_First_Name;
                                   SV[i].set_First_Name(Replace_First_Name);
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 3: //show Last Name and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_LN, Replace_Last_Name;
                    std::cout<<"Enter Last Name: ";
                    std::cin>>Temp_LN;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i = 0; i<length; i++)
                    {
                         if(Temp_LN == SV[i].get_Last_Name())
                         {
                              find_mode = true; //replace file_mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace Last Name: ";
                                   std::cin>>Replace_Last_Name;
                                   SV[i].set_Last_Name(Replace_Last_Name);
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 4: //show Full Name and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_Full_Name, Replace_Full_NameF, Replace_Full_NameL;//replace first name and last name (Replace Full NameF/L)
                    std::cout<<"Enter Full Name: ";
                    std::cin>>Temp_Full_Name;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i = 0; i<length; i++)
                    {
                         if(Temp_Full_Name == (SV[i].get_Name()))
                         {
                              find_mode = true; //replace file_mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace First Name: ";
                                   getline(std::cin, Replace_Full_NameF);
                                   std::cin.ignore();
                                   std::cout<<"Replace Last Name: ";
                                   getline(std::cin, Replace_Full_NameL);
                                   SV[i].set_First_Name(Replace_Full_NameF);
                                   SV[i].set_Last_Name(Replace_Full_NameL);
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 5: //show Gender and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_Gender, Replace_Gender;
                    std::cout<<"Enter Gender: ";
                    std::cin>>Temp_Gender;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i=0; i<length; i++)
                    {
                         if(Temp_Gender == SV[i].get_Gender())
                         {
                              find_mode = true; //replace file_mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace Gender: ";
                                   std::cin>>Replace_Gender;
                                   SV[i].set_Gender(Replace_Gender);
                                   std::cout<<"replace done!"<<std::endl;
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 6: //show Major and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_Major, Replace_Major;
                    std::cout<<"Enter Major: ";
                    std::cin>>Temp_Major;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i = 0; i< length; i++)
                    {
                         if(Temp_Major == SV[i].get_Major())
                         {
                              find_mode = true; //replace file_mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace Major: ";
                                   std::cin>>Replace_Major;
                                   SV[i].set_Major(Replace_Major);
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 7: //show Class and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    std::string Temp_Class, Replace_Class;
                    std::cout<<"Enter Class: ";
                    std::cin>>Temp_Class;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i = 0; i< length; i++)
                    {
                         if(Temp_Class == SV[i].get_Class())
                         {
                              find_mode = true; //replace file_mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace Class: ";
                                   std::cin>>Replace_Class;
                                   SV[i].set_Class(Replace_Class);
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
          case 8: //show GPA and replace it if Replace mode is enable
               {
                    int length = SV.size();
                    double Temp_GPA, Replace_GPA;
                    std::cout<<"Enter GPA: ";
                    std::cin>>Temp_GPA;
                    if(length==0)
                         std::cout<<"Don't have any data!"<<std::endl;
                    for(int i = 0; i<length; i++)
                    {
                         if(Temp_GPA == SV[i].get_GPA())
                         {
                              find_mode = true; //replace file_mode
                              if(Replace_Mode == true)
                              {
                                   std::cout<<"Replace GPA: ";
                                   std::cin>>Replace_GPA;
                                   SV[i].set_GPA(Replace_GPA);
                              }
                              else if((Replace_Mode == false)&&(Remove_Mode == false))
                              {
                                   //set up
                                   std::cout<<std::setfill(' ');
                                   std::cout<<std::setw(14)<<std::left<<"Id"<<std::setw(40)<<std::left<<"Name"<<std::setw(16)<<std::left<<"Gender";
                                   std::cout<<std::setw(30)<<std::left<<"Major"<<std::setw(17)<<std::left<<"Class"<<std::setw(8)<<std::right<<"GPA"<<std::endl;
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                                   //show inf
                                   std::cout<<SV[i];
                                   //set up
                                   std::cout<<std::setfill('-');
                                   std::cout<<std::setw(125)<<"-"<<std::endl;
                                   std::cout<<std::setfill(' ');
                              }
                              else
                                   break;
                         }
                    }
                    if(find_mode != true)
                         std::cout<<"Don't have this student in SGU!"<<std::endl;
                    break;
               }
     }
}

//Replace student information
void Student_List::Replace()
{    
     int Temp_Option;
     set_Replace_Mode(Replace_Mode = true); 
     std::cout<<std::setfill('-')<<std::setw(45)<<"-"<<std::endl;
     std::cout<<"YOU WANT TO Replace: "<<std::endl;
     std::cout<<"I: Student's Id."<<std::endl;
     std::cout<<"II: Student's First Name."<<std::endl;
     std::cout<<"III: Student's Last Name."<<std::endl;
     std::cout<<"IV: Student's Full Name."<<std::endl;
     std::cout<<"V: Student's Gender."<<std::endl;
     std::cout<<"VI: Student's Major."<<std::endl;
     std::cout<<"VII: Student's Class."<<std::endl;
     std::cout<<"VIII: Student's GPA."<<std::endl;
     std::cout<<std::setw(45)<<"-"<<std::endl;
     std::cout<<"Option you want (enter an integer number): ";
     std::cin>>Temp_Option;
     switch (Temp_Option)
     {
          case 1: case 2: case 3: case 4:
               std::cout<<"Find and Replace student's information! "<<std::endl;
               Find_Student(Temp_Option, Replace_Mode, Remove_Mode);
               break;
          case 5: case 6: case 7: case 8:
               std::cout<<"Find and Replace student's information! "<<std::endl;
               Find_Student(Temp_Option, Replace_Mode, Remove_Mode);
               break;
     }
     set_Replace_Mode(Replace_Mode = false); // return Replace mode = false
}

void Student_List::Remove()
{
     int Temp_Option;
     set_Remove_Mode(Remove_Mode = true);
     //system("clear");
     Find_Student(Temp_Option = 1, Replace_Mode, Remove_Mode);
     set_Remove_Mode(Remove_Mode = false);     //return remove mode = false
}
