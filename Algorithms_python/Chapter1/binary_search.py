'''Algorithms: binary search'''
def main():
    num = eval(input("How many numbers in your list:"))
    num_str = input("Enter your number(space to seperater):")
    num_list = num_str.split(" ")
    my_list = []
    for i in range(num):
        my_list.append(eval(num_list[i]))
    my_list.sort(key=lambda x:x, reverse=False)
    print("The number you input is:", my_list)
    item = eval(input("Enter the number you want to search:"))
    index = binary_search(my_list, item)
    print("The number is at:", index+1)


def binary_search(array, item):
    low = 0
    high = len(array) - 1
    while low<=high:
        middle = round((low+high)/2.0)
        guess = array[middle]
        if guess == item:
            return middle
        if guess < item:
            low = middle + 1
        else:
            high = middle - 1
    return None
    print("The number you input has not find!")

if __name__ == "__main__":
    main()