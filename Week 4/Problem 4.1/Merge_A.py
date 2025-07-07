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

def main():
    array=[1,30,4,26,18,9,19]
    k=2
    merge_sort(array,k)
    print("Sorted: ",array)         
    
if __name__=="__main__":
    main()