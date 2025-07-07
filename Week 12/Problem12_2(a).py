def find_max_path(triangle):
    n=len(triangle)
    dp=[[0]*len(row) for row in triangle]  #we store the element that represents the maxmimum sum of al ll the elements
    path = [[None] * len(row) for row in triangle] #we make a path table to trace the path of the maximum sum in the array
    dp[0][0]=triangle[0][0]
    
    for i in range(1, n):
        for j in range(len(triangle[i])):
            if j==0:
                dp[i][j]=dp[i-1][j]+triangle[i][j]
                path[i][j]=j
            elif j==len(triangle[i])-1:
                dp[i][j]=dp[i-1][j-1]+triangle[i][j]
                path[i][j]=j-1
            else:
                if dp[i-1][j-1]>dp[i-1][j]:
                    dp[i][j]=dp[i-1][j-1]+triangle[i][j]
                    path[i][j]=j-1
                else:
                    dp[i][j]=dp[i-1][j]+triangle[i][j]
                    path[i][j]=j

    #we get the maximum sum in the last row
    max_sum=max(dp[-1])
    max_index=dp[-1].index(max_sum)
    result_path=[]
    row=n-1
    while row>=0:
        result_path.append(triangle[row][max_index])
        max_index=path[row][max_index]
        row=row-1

    #since the result_path is in reverse we turn it around
    result_path.reverse()
    return max_sum,result_path

def main():
    
    triangle=[
    [7],
    [3, 8],
    [8, 1, 0],
    [2, 7, 4, 4],
    [4, 5, 2, 6, 5]
    ]
    max_sum,path= find_max_path(triangle)
    print("The Maximum Path Sum:", max_sum)
    print("The Path:", path)

if __name__ == "__main__":
    main()