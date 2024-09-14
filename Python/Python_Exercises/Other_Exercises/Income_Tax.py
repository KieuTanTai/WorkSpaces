#calculate income_tax
def calculate_income_tax(taxable_income):
     after_cal = 0
     if taxable_income <= 10000:
          after_cal = taxable_income*0/100
     elif 10000 < taxable_income <= 20000:
          after_cal = (10000*0/100) + ((taxable_income - 10000)*10/100) 
     else:
          after_cal = (10000*0/100) + (10000*10/100)+((taxable_income-20000)*20/100)
     return int(after_cal)
#main 
try:
     print("The money is $ currency: ")
     taxable_income =int(input("taxable income = "))
     if taxable_income < 0:
          print("error value!")
     else:
          print("Income tax is: %d $" %calculate_income_tax(taxable_income)) 
except:  
     print("error code!")