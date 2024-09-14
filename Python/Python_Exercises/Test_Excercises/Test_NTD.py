def first_last_number(list_number):
    first_number = list_number[0]
    last_number = list_number[-1]
    if first_number == last_number:
        return True
    else:
        return False

number_X = [2, 5, 53, 5, 6, 7, 9]
print("the result is: ", first_last_number(number_X))
number_Y = [2, 3 , 4, 5, 6, 9, 2]
print("the result is: ", first_last_number(number_Y))