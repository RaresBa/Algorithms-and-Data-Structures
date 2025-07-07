
import random


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
    def case_a(n):
        return list(range(1,n+1))
    def case_b(n):
        return list(range(n,0,-1))
    
    n=(int(input("How many numbers should the arrayies for Case A and Case B have: ")))
    case_a_generated=case_a(n)
    case_b_generated=case_b(n)
    
    print("Case A sequence: ",case_a_generated)
    print("Case B sequence: ",case_b_generated)
    
    sorted_list_a=selection_algorithm(case_a_generated)
    sorted_list_b=selection_algorithm(case_b_generated)
    
    print("The sorted array for case A is: ",sorted_list_a)
    print("The sorted array for case B is: ",sorted_list_b)
    
if __name__ == "__main__":
    main()


#For generating test cases I imported the "random" lib and
#For Case A I am generating random nubmers from 1 to n+1 which have the most cases 
#For Case B I am generating a normal list (decresing order)
#I first print the random values than I print the sorted values