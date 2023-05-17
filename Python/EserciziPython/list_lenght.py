numbers_x = [10, 20, 30, 40, 10]
numbers_y = [75, 65, 35, 75, 30]

def check_list(list):
    size = len(list)
    if (list[0] == list[size-1]):
        return True
    else:
        return False

print(f"Return list {check_list(numbers_x)}")
print(f"Return list {check_list(numbers_y)}")

