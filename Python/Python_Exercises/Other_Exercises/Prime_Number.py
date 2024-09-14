N = int(input("nhap so N= "))
for i in range(2, N):
    if N%i == 0:
        print("so {0} khong phai so nguyen to".format(N))
        break
else:
    print("so {0} la so nguyen to".format(N))
    