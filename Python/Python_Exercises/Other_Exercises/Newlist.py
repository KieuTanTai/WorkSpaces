def merge_list(list_number1, list_number2):
    list_empty = []
    for i in list_number1:
        if int(i)%2!=0:
            list_empty.append(i)
    for j in list_number2:
        if int(j)%2==0:
            list_empty.append(j)
    return list_empty

list1 = input("create a list1: ")
list2 = input("create a list2: ")
list_number1 = list1.split()
list_number2 = list2.split()
print("two lists after split: ")
print(list(map(int,list_number1)))
print(list(map(int, list_number2)))
print("merge list: \n", list(map(int,merge_list(list_number1, list_number2))))