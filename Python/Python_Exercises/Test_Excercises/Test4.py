# import math
# decimal = float(input("decimal = "))
# decimal_1 = 0
# pow_number = 0
# for i in range(decimal):
#      while decimal_1 < decimal:
#           if decimal % pow(2, pow_number) != 0:
#                decimal_1 = pow(2, pow_number)
#                pow_number +=1
#           elif decimal % pow(2, pow_number) == 0:
#                decimal_1 = decimal
#           else:
#                decimal_1 = decimal - pow(2, pow_number)


#      pass

def reverse_decimal_to_binary(decimal_number):
    # Step 1: Convert decimal to binary string
    binary_str = bin(decimal_number)[2:]  # Removing '0b' prefix
    
    # Step 2: Reverse the string
    reversed_binary_str = binary_str[::-1]
    
    # Step 3: Convert reversed binary to integer
    reversed_decimal_number = int(reversed_binary_str, 2)
    
    return reversed_decimal_number

# Example usage:
decimal_number = int(input())
binary_result = reverse_decimal_to_binary(decimal_number)
print(f"Decimal: {decimal_number} -> Reversed Binary: {binary_result}")
