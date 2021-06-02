from cs50 import get_int

def main():
    
    height = get_height()
    
    for i in range(height):
        j = i + 1
        h = "#" * j
        print((" " * (height - j))+(h)+("  ")+(h))
        
def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n

main()
    