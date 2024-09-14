import tracemalloc, time, math
tracemalloc.start()
start_time = time.time()

#print reversed string
def reversed_string(s):
     for i in range(1,len(s)+1, 1):
          print(s[-i], end = " ")

#binary to decimal
def binary_to_decimal(binary):
     value = 0
     j =len(binary) - 1
     for i in binary:
          if int(i) == 1:
               value = value + 1*pow(2, j)
          j-=1
     print("decimal_number = ", value)
     return value

#reverse decimal to binary
def decimal_to_binary(decimal):
     binary_number = bin(decimal)[2:]
     #reversed_number = binary_number[::-1]
     return binary_number 
     
#reverse hexadecimal to decimal
def hex_to_dec(Hexadecimal):
     pass

#main
try:
     #s = "pythonfile.py"
     binary = list(input("Binary = "))
     decimal = int((input("Decimal = ")))
     #Hexadecimal = hex(input("hexadecimal = "))
     #print(s[2], s[-1], len(s), s[0:7], s[6:10], s[10:14], sep = " ")
     #check binary input
     ip_binary = set(binary)
     bin_set = {'0', '1'}
     if ip_binary != bin_set:
          print("error value!")
     else:
          binary_to_decimal(binary)
          print("after reversed: ", decimal_to_binary(decimal))
          reversed_string("string after reversed: ", )
except:
     print("error code!")
finally:
     end_time = time.time()
     elapsed_time = end_time - start_time
     memory_start = tracemalloc.get_traced_memory()
     print("\nelapsed_time = ", elapsed_time)
     print(f"\nmemory_start = {memory_start[0]/10**6} MB)")