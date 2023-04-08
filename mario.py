# To use get_int is necessary to import from cs50 library
from cs50 import get_int

# Get the Height from the user
while True:
    h = get_int("Height: ")
    if not (h < 1 or h > 8):
        break

j = 1
for i in range(h):
    print(" " * (h - j), end="#" * j)
    print()
    j += 1