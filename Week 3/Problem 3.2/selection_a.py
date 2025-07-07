def selection_algorithm(array):
    n=len(array)
    for i in range(n):
        idx=i
        for j in range(i+1,n):
            if array[j]<array[idx]:
                idx=j
        array[i],array[idx]=array[idx],array[i]
    return array

def main():
    list=[]
    n=int(input("Enter how many numbers the array should have: "))
    for i in range(n):
        x=int(input())
        list.append(x)
    new_list=selection_algorithm(list)
    print("The sorted array is: ",new_list)

if __name__ == "__main__":
    main()