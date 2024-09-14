#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../../Class/Functions_Header/Usually_Use.hpp"
struct node
{
     int data;
     struct node * Continue;
};
//create new node (pointer)
node * Make_Node(int X)
{
     node * New_Node = new node(); 
     New_Node->data = X;
     New_Node->Continue = nullptr;
     return New_Node;
}
//Browse&count data in all note
void Browse(node * head /*pass by value*/)
{
     while(head != nullptr)
     {
          std::cout<< head->data<<"\t";
          head = head->Continue;
     }
}
//Linked_Lists's size!
int Count(node *head)
{
     int count=0;
     while(head != nullptr)
     {
          count++;
          head=head->Continue;
     }
     return count;  
}
//for C++
void Push_Front_Node(node *&head/*parameter*/ , int new_data) 
{
     node *New_Node = Make_Node(new_data);
     New_Node->Continue = head; 
     head = New_Node;
}

void Push_Back_Node(node *&head, int new_data)
{
     node *TEMP = head;
     node *New_Node = Make_Node(new_data);
     if(head==nullptr)
     {
          head=New_Node;
          return;
     }
     while(TEMP->Continue != nullptr)
          TEMP = TEMP->Continue;
     TEMP->Continue = New_Node; //gan phan tiep theo cua node = new node
}
void Add_Node(node *&head, int new_data, int k)
{
     int size=Count(head); //size of linked list
     node *Temp=head;    //after run head would be changed so we need use Temp 
     node *new_node = Make_Node(new_data); //create new node
     if(k<1 || k>size+1) 
          return;
     if(k==1)
          Push_Front_Node(head, new_data);
     else if(k==size)
          Push_Back_Node(head, new_data);
     for(int i=0; i<k-2; i++)
          Temp=Temp->Continue;
     new_node->Continue=Temp->Continue;
     Temp->Continue=new_node;
}
int main()
{
     int Number, data, option;
     node *head = nullptr;
     while(1)
     {
          std::cout<<"I. Push Front"<<std::endl;
          std::cout<<"II. Push Back"<<std::endl;
          std::cout<<"III. Push in somewhere"<<std::endl;
          std::cout<<"IV. Show Size"<<std::endl;
          std::cout<<"V. Show Linked_Lists"<<std::endl;
          std::cout<<"VI. Exit!"<<std::endl;
          std::cin>>option;
          switch (option)
          {
               case 1:
                    std::cout<<"Number = ";
                    std::cin>>Number;
                    for(int i=0; i<Number; i++)
                    {
                         data=random_Number();
                         Push_Front_Node(head, data);
                    }
                    std::cout<<std::endl;
                    break;
               case 2:
                    std::cout<<"Number = ";
                    std::cin>>Number;
                    for(int i=0; i<Number; i++)
                    {
                         data=random_Number();
                         Push_Back_Node(head, data);
                    }
                    std::cout<<std::endl;
                    break;
               case 3:
                    int k;
                    std::cout<<"vi tri k = ";
                    std::cin>>k;
                    std::cout<<"Number = ";
                    std::cin>>Number;
                    for(int i=0; i<Number; i++)
                    {
                         data=random_Number();
                         Add_Node(head, data, k);
                    }
                    std::cout<<std::endl;
                    break;
               case 4:
                    std::cout<<Count(head)<<std::endl;
                    break;
               case 5:
                    Browse(head);
                    std::cout<<std::endl;
                    break;
               case 6:
                    return 0;

          }
     }
     return 0;
     //Node 
}