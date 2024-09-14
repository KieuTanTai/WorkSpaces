given_number = list(input("enter list of number: ").split())
for spec in given_number:
    if spec == " ":
        given_number.remove(spec)
given_number[0],given_number[-1] = given_number[-1],given_number[0]
after_list = given_number
if  after_list[0] and after_list[-1] != given_number[0] and given_number[-1]:
    print("given number is not Palindrome number: ", after_list)
else:
    print("given number is Palindrome number: ", after_list)
