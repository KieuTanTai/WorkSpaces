import os
#print multiplication number
def Multiplication_Table(end, end_var):
     for i in range(1, end+1, 1):
          for j in range(1, end_var+1, 1):              
               print (j*i, end = " ")
          print("\n")

#main
try:
     end_var = int(input("end number: "))
     end = int(input("Import number of column you want to calculate: "))
     if end_var <= 1 or end <= 0:
          print("please try again!")
     else:
          os.system("clear")
          print("\nyour Multiplication number is: ")
          Multiplication_Table(end, end_var)
except:
     print("error code!")