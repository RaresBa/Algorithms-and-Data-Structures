def heapify(array,n,i):
    largest=i
    l=2*i+1
    r=2*i+2
    if l<n and array[l]>array[largest]:
        largest=l
    if r<n and array[r]>array[largest]:
        largest=r
    if largest !=i:
        array[i],array[largest]=array[largest]
        heapify(array,n,largest)
 
        
        
def heap(array):
    lenght=len(array)
    
    for i in range(lenght//2-1,-1,-1):
        heapify(array,lenght,i)
        
    for i in range(lenght-1,0,-1):
        array[0],array[i]=array[i],array[0]
        heapify(array,i,0)
        
def main():
    array=[1,10,23,9,11,25,0,8,71,223,3,29942,214321]
    print("The unsorted array:" ,array)
    heap(array)
    print("The sorted array:", array)
    
if __name__=='__main__':
    main()
    