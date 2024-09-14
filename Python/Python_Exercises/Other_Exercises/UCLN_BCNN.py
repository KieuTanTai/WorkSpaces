#uoc chung lon nhat
def GCD_Euclid(num_1, num_2):
#Cach 1
    # if num_1 > num_2:
    #     spare = num_1%num_2
    #     while spare != 0:
    #         num_1 = num_2
    #         num_2 = spare
    #         spare = num_1%num_2
    #     GCD_N = num_2
    #     return GCD_N
    # else:
    #     spare = num_2%num_1
    #     while spare != 0:
    #         num_2 = num_1
    #         num_1 = spare
    #         spare = num_2%num_1
    #     GCD_N = num_1
    #     return GCD_N
#Cach 2
    while num_1 != num_2:
        if num_1 > num_2:
            num_1 = num_1 - num_2
        else:
            num_2 = num_2 - num_1
    return num_1
    
#boi chung nho nhat
def LCM_Number(num_1, num_2):
    LCM_N = 0
    LCM_N = (num_1 * num_2)/GCD_Euclid(num_1, num_2)
    print("\nThe Least Common Multiple is: ", LCM_N)
#main 
try:
    num_1 = int(input("int num1: "))
    num_2 = int(input("int num2: "))
    if num_1 < 0 or num_2 < 0:
        print("error: ")
    else:
        print("The Largest Common Division is: ", GCD_Euclid(num_1, num_2))
        LCM_Number(num_1, num_2)
except:
    print("error!")