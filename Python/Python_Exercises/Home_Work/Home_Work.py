import math
#so nguyen to
def prime_number(number):
    count = 0
    if number <2:
        print("khong phai so nguyen to")
    else:
        for i in range(2, int(math.sqrt(number))+1):
            if number%i == 0:
                count+=1
                break
    if count != 0:
        print("khong phai so nguyen to")
    else:
        print("la so nguyen to ")

#so doi xung   
def so_doi_xung(number):
    number_string = str(number)
    number_reversed = number_string[::-1]
    if number_string == number_reversed:
        print("so doi xung")
    else:
        print("khong phai so doi xung")

#so hoan thien
def so_hoan_thien(number):
    sum =0
    for i in range(1, number -1, 1):
        if (number % i) == 0:
            sum+=i

    if sum == number:
        print("la so hoan thien")
    else:
        print("khong phai so hoan thien")

#so chinh phuong
def so_chinh_phuong(number):
    number_sqrt = math.sqrt(number)
    if float(number_sqrt) == int(number_sqrt):
        print("la so chinh phuong")
    else:
        print("khong phai so chinh phuong")

#goi ham thuc thi 
number = int(input("nhap so ngau nhien: "))
prime_number(number)
so_doi_xung(number)
so_hoan_thien(number)
so_chinh_phuong(number)