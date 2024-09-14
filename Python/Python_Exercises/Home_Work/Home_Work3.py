import math, tracemalloc, time, os
#start timing
start_time = time.time()
#get memory usage
tracemalloc.start()

#prime number less than Number
def Prime_Number_Less(Number):
    count = 0
    for i in range(Number):
        if i < 2:
            count+=1
        else:
            for j in range(2, int(math.sqrt(i))+1):
                if i%j == 0:
                    count+=1
                    break
            if count==0:
                print(i, end = "; ")
            else:
                count = 0

#first Number prime numbers
def Prime_Number_F(Number):
    count = 0
    count_prime_number = 2
    while count_prime_number < Number+2:
        for i in range(2, int(math.sqrt(count_prime_number))+1):
            if count_prime_number%i == 0:
                count+=1
                break
        if count == 0:
            print(count_prime_number, end = "; ")
            count_prime_number = count_prime_number + 1
        else:
            count_prime_number+=1
            Number+=1
            count = 0

#Multiple_Divisible by 7
def Divisible_():
    Divisions = 0
    for num in range(99, 999+1, 1):
        if (num%7 == 0) and (num%5!=0):
            print(num, end = "; ")

#print elements in Number
def Separate_Num(Number):
    Mirror_Num = 0
    Mirror_P_Num = 0
    #reversed number input
    while Number != 0:
        Mirror_Num = Number%10
        if Mirror_Num == 0:
            print(Mirror_Num, end = "; ")
            Mirror_P_Num = Mirror_P_Num * 10 + Mirror_Num
            Number = Number//10
            continue
        else:
            Mirror_P_Num = Mirror_P_Num * 10 + Mirror_Num
            Number = Number//10
    #separate elements in number input
    while Mirror_P_Num != 0:
        Mirror_Num = Mirror_P_Num % 10
        Mirror_P_Num = Mirror_P_Num // 10
        print(Mirror_Num, end = "; ")

#main
try:
    Number = int(input("input number: "))
    os.system("clear")
    if Number <=  0:
        print("error Number, please try again!")
    else:
        print("list of prime number less than %d: " %Number)
        Prime_Number_Less(Number)
        print("\n\nlist of first %d prime number: " %Number)
        Prime_Number_F(Number)
        print("\n\nlist of Divisions by 7 and not Multiples of 5: ")
        Divisible_()
        print("\n\nlist of elements in %d: " %Number)
        Separate_Num(Number)
except: 
    print("error code, please try again!")
finally:
    end_time = time.time()
    elapsed_time = end_time - start_time
    memory_start = tracemalloc.get_traced_memory()
    print(f"\ntime run code: {elapsed_time } milliseconds")
    print(f"\nmemory usage: {memory_start[0]/10**6} MB")
