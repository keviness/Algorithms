'''recrusion'''
def main():
    print("recrusion1".center(28, "*"))
    parameter = eval(input("Enter the parameter:"))
    countdown(parameter)
    print("recursion2".center(28, "*"))
    parameter_str = input("Enter the parameters(spcae to seperate):")
    parameter_list = parameter_str.split(" ")
    my_list = []
    for i in range(len(parameter_list)):
        my_list.append(eval(parameter_list[i]))
    print("The number you input in the array:")
    print(my_list)
    list = quicksort(my_list)
    print("The array after calling quick sort:", list)
    print("recursion3".center(28, "*"))
    parameter2 = eval(input("Enter the parameter2:"))
    first = eval(input("Enter the first number:"))
    second = eval(input("Enter the second number:"))
    fabio_num = fabio(parameter2, first, second)
    print("The {0} fabio number is: {1}".format(parameter2, fabio_num))

def countdown(parameter):
    print(parameter)
    if parameter == 0:
        return
    else:
        countdown(parameter-1)
def quicksort(array):
    if (len(array) < 2):
        return array
    else:
        mid = round(len(array)/2)
        pivot = array[mid]
        less = [ele for ele in array if ele < pivot]
        greater = [ele for ele in array if ele > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)
def fabio(parameter, first, second):
    if parameter <= 2:
        return parameter-1
    elif parameter == 3:
        return first+second
    else:
        return fabio(parameter-1, second, first+second)
if __name__ == "__main__":
    main()