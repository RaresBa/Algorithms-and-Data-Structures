import time

#(1) Naive Recursive:
def fibonacci_recursive(n):
    if n<=1:
        return n
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2)

#(2) Bottom Up:
def fibonacci_bottom_up(n):
    fib=[0,1]
    for i in range(2, n+1):
        fib.append(fib[i-1]+fib[i-2])
    return fib[n]

#(3) Closed Form:
def fibonacci_closed_form(n):
    phi=(1+5**0.5)/2
    return round((phi**n)/5**0.5)

#(4) Using Matrix Representation:
def fibonacci_matrix(n):
    def multiply(A, B):
        return [[A[0][0]*B[0][0]+A[0][1]*B[1][0],A[0][0]*B[0][1]+A[0][1]*B[1][1]],
                [A[1][0]*B[0][0]+A[1][1]*B[1][0],A[1][0]*B[0][1]+A[1][1]*B[1][1]]]

    def power(M, p):
        if p==1:
            return M
        if p%2==0:
            half=power(M,p//2)
            return multiply(half,half)
        else:
            return multiply(M,power(M,p-1))

    F=[[1, 1],[1, 0]]
    return power(F,n)[0][1]

def measure_running_times():
    max_time=1  
    n_values=[0,1,2,3,4,5,6,8,10,13,16,20,25,32,40,50,63]
    
    results = {
        "Naive Recursive":[],
        "Bottom-Up":[],
        "Closed Form":[],
        "Matrix Representation":[]
    }

    for n in n_values:
        for method, func in results.items():
            start_time=time.time()
            result=globals()[f'fibonacci_{method.lower().replace("-", "_")}'](n)
            end_time=time.time()
            elapsed_time=end_time-start_time
            if elapsed_time>max_time:
                break
            results[method].append((n,result,elapsed_time))
    return results


def print_results(results):
    print("Method\t\t\tN\tFib(N)\t\tElapsed Time (s)")
    for method, data in results.items():
        for n, fib_n, time_taken in data:
            print(f"{method.ljust(20)}{str(n).ljust(5)}{str(fib_n).ljust(10)}{time_taken:.6f}")
 
 
def main():
    results=measure_running_times()
    print_results(results)

if __name__=="__main__":
    main()           