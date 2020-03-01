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
    print("The number is at:%d", index)


def binary_search(array, item):
    low = 0
    high = len(array) - 1
    middle = round((low+high)/2)
    while low<=high:
        if item == array[middle]:
            return middle
        if item > array[middle]:
            low = middle + 1
        else:
            high = middle - 1
    return None
    print("The number you input has not find!")

if __name__ == "__main__":
    main()