"""
Connor made this program after he popped a tired going to school
it is currently 9:23am on 9/3/2026
this program took about 15 minutes to figure out and write
"""

money = float(input("Enter the amount of merchandise: "))  #this gets the input from the user and converts it to a float
print(" ")  #this prints a blank line to make the output look nicer

# this if elif and else statement checks how much money the user entered
if money >= 500:
    discount = .4
    print()
elif 500 > money >= 200:
    discount = .2
elif money < 100:
    discount = .1
else:
    discount = 0


total = money * (1 - discount) 
print(f"You get  {discount * 100:.0f}% off!" "\n")

print(f"Final price: ${total:.2f}")