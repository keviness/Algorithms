'''selection sort'''
def main():
    num = eval(input("How many numbers do you want:"))
    num_str = input("Enter your numbers(space to seperator):")
    num_list = num_str.split(" ")
    my_list = []
    for i in range(num):
        my_list.append(eval(num_list[i]))
    print("The numbers you input:", my_list)
    print("The numbers after calling selectionSort:")
    new_list = selectionSort(my_list)
    for element in new_list:
        print(element)

def findSmallest(array):
    smallest = array[0]
    smallest_index = 0
    for i in range(1, len(array)):
        if smallest > array[i]:
            smallest = array[i]
            smallest_index = i
    return smallest_index

def selectionSort(array):
    new_list = []
    for i in range(len(array)):
        smallest = findSmallest(array)
        new_list.append(array.pop(smallest))
    return new_list

if __name__ == "__main__":
    main() 