import random
import time


def  insertion(array):
    for i in range(1,len(array)):
        k=array[i]
        j=i-1
        while j>=0 and k<array[j]:
            array[j+1]=array[j]
            j=j-1
        array[j+1]=k
        
def merge(left,right):
    new_array=[]
    i=j=0
    while i<len(left) and j<len(right):
        if left[i]<right[i]:
            new_array.append(left[i])
            i=i+1
        else:
            new_array.append(right[j])
            j=j+1
    new_array.extend(left[i:])
    new_array.extend(right[j:])
    return new_array

def merge_sort(array,k):
    if len(array)<=k:
        insertion(array)
    else:
        mid=len(array)//2
        left=array[:mid]
        right=array[mid:]
        
        merge_sort(left,k)
        merge_sort(right,k)
        
        new=merge(left,right)
        for i in range(len(new)):
            array=new[i]
            
def generate(lenght,case):
    if case == "best case":
        return list(range(lenght))
    elif case=="average case":
        return [random.randint(0,lenght)for _ in range(lenght)]
    elif case=="worst case":
        return list(range(lenght,0,-1))
    
def measure_execution_time(sequence,k):
    start=time.time()
    merge_sort(sequence,k)
    end=time.time()
    return end-start
    
def print_time(sequence_l,k_val):
    cases=["best case","average case","worst case"]
    for case in cases:
        print(f"Case: {case}")
        for k in k_val:
            sequence=generate(sequence_l,case)
            execution_time=measure_execution_time(sequence,k)
            print(f"k={k}is {execution_time:.8f} ")  
    
    
def main():
    sequence_l=2000
    k_values=[1,2,3,4,5,6]
    print_time(sequence_l,k_values)        
    
if __name__=="__main__":
    main()