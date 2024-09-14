import tracemalloc, time
from math import *
tracemalloc.start()
start_time = time.time()

#prime number
def Prime_number(start, end):
    print("list of prime numbers: ")
    for i in range(start, end+1):
        if i < 2:
            pass
        else:
            for j in range (2, int(sqrt(i))+1):
                if i%j == 0:
                    break
            else:
                print(i, end = "  ")
    
 #symmetrical number
def Symmetrical_number(start, end):
    print("\nlist of symmetrical numbers: ")
    for i in range(start, end+1):
        string_number = str(i)
        str_number_reversed = string_number[::-1]
        if string_number == str_number_reversed:
            print(str_number_reversed, end = "  ")

#perfect number
def perfect_number(start, end):
    sum = 0
    print("\nlist of perfect numbers: ")
    for i in range(start, end+1):
        for j in range(1,i):
            if ((i%j) == 0):
                sum+=j      
        if sum == i:
            sum = 0
            print(i, end = "  ")
        else:
            sum = 0

#square number
def square_number(start, end):
    print("\na list of square numbers: ")
    for i in range(start, end + 1):
        square_n = sqrt(i)
        if float(square_n) == int(square_n):
            print(i, end = "  ")

#the first number%9 == 0 and %7 == 0
def First_Number(start, end):
    print(f"\nThe first number % 9 == 0 and % 7 == 0 in [{start},{end}]:")
    for i in range(start, end+1):
        if (i%9 == 0) and (i%7 == 0):
            print(i)
            break
        else:
            print("don't have any number % 9 == 0 and % 7 == 0.")
            break

 #fast power
def fast_power(num_1, pow_num):
    if pow_num%2 != 0:
        return num_1*pow(pow_num//2, num_1)*pow(pow_num//2, num_1)
    else:
        return pow(pow_num//2, num_1) * pow(pow_num//2, num_1)
#main 
#realtime run file  
try:
    start = int(input("enter a value: "))
    end = int(input("enter a value: "))
    num_1 = int(input("enter num-1: "))
    pow_num = int(input("enter a pow_num: "))
    if start < 0 or end < 0 or num_1 < 0 or pow_num < 0:
        print("error: ")
    elif start > end:
        print("error: ")
    else:
        Prime_number(start, end)
        Symmetrical_number(start, end)
        perfect_number(start, end)
        square_number(start, end)
        First_Number(start, end)
        print("fast power using recursion, divide and conquer: ", fast_power(num_1, pow_num))
except:
    print("\nsyntax error!")
finally:
    end_time = time.time()
    memory_starts = tracemalloc.get_traced_memory()
    elapsed_time = end_time - start_time
    print(f"\ncode run in: {elapsed_time} Millisecond")
    print(f"\nMemory usage:{memory_starts[0]/10**6} MB ")
