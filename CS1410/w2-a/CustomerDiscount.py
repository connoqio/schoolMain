money = float(input("Enter the amount of merchandise: "))

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
print(f"Discount applied: {discount * 100:.0f}%")
print(f"Final price: ${total:.2f}")