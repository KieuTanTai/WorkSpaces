import array  as arr
import math

def check_binary(binary_input, list_collect):
     value = 0
     len_of_str = len(binary_input) - 1
     for i in binary_input:
          if int(i) == 1:
               value += pow(2, len_of_str)
          len_of_str -= 1
     list_collect = list_collect.append(value)
     print(value, end = " ")
     return list_collect

string_input = str.split(input("your string is: "))
_bin_ = int(input("import the number of binary string:  "))
list_collect = arr.array('i', )
for i in range(_bin_):
     arr_bin = list(input(("\nimport your binary: ")))
     new_check = set(arr_bin)
     new_set = {'0', '1'} 
     if (new_check == new_set) or (new_check == {'0'}) or (new_check == {'1'}):
          check_binary(arr_bin, list_collect)
     else:
          print("error binary!")
print("\nstring collect: ", list_collect)
string_reversed = sorted(string_input)