def longest_ordered_subarray(array):
    n=len(array)
    dp=[1]*n    # stores the lenght of the longest subarray
    prev=[-1]*n # stores the index of the previous element
    
    for i in range(n):
        for j in range(i):
            if array[j]<array[i] and dp[j]+1>dp[i]:
                dp[i]=dp[j]+1
                prev[i]=j
    
    #find the maximum value in dp (longest ordered array)
    max_index=max(range(n),key=lambda i:dp[i])
    longest_subarray=[]
    
    #backtracking using the prev array from the index of the longest array
    while max_index!=-1:
        longest_subarray.append(array[max_index])
        max_index=prev[max_index]

    
    #the longest_subarray is in a reverse way so to print it correctly we reverse it
    longest_subarray.reverse()


def main():
    input_array = list(map(int, "8 3 6 50 10 8 100 30 60 40 80".split()))
    result=longest_ordered_subarray(input_array)
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()