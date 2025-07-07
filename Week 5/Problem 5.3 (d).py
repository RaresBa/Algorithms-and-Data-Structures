import matplotlib.pyplot as plt
import time

# Naive Recursive Approach
def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)

# Bottom-Up Approach
def fibonacci_bottom_up(n):
    fib = [0, 1]
    for i in range(2, n+1):
        fib.append(fib[i-1] + fib[i-2])
    return fib[n]

# Closed Form Approach
def fibonacci_closed_form(n):
    phi = (1 + 5 ** 0.5) / 2
    return round((phi ** n) / 5 ** 0.5)

# Matrix Representation Approach
def fibonacci_matrix(n):
    def multiply(A,B):
        return [[A[0][0]*B[0][0]+A[0][1]*B[1][0],A[0][0]*B[0][1]+A[0][1]*B[1][1]],
                [A[1][0]*B[0][0]+A[1][1]*B[1][0],A[1][0]*B[0][1]+A[1][1]*B[1][1]]]

    def power(M, p):
        if p==1:
            return M
        if p%2==0:
            half=power(M,p// 2)
            return multiply(half, half)
        else:
            return multiply(M,power(M,p-1))

    F = [[1,1],[1,0]]
    return power(F,n)[0][1]

def measure_running_times():
    max_time = 1  
    n_values = [0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 32, 40, 50, 63]
    
    methods = {
        "Naive Recursive": fibonacci_recursive,
        "Bottom-Up": fibonacci_bottom_up,
        "Closed Form": fibonacci_closed_form,
        "Matrix Representation": fibonacci_matrix
    }

    results = {method: [] for method in methods}

    for n in n_values:
        for method, func in methods.items():
            start_time=time.time()
            result=func(n)
            end_time=time.time()
            elapsed_time=end_time-start_time
            if elapsed_time>max_time:
                break
            results[method].append((n, elapsed_time))
    return results

def plot_results(results):
    plt.figure(figsize=(10, 6))
    for method, data in results.items():
        n_values = [entry[0] for entry in data]
        times = [entry[1] for entry in data]
        plt.plot(n_values, times, label=method)

    plt.yscale("log")
    plt.xlabel("n")
    plt.ylabel("Running Time (s)")
    plt.title("Running Times of Fibonacci Methods")
    plt.legend()
    plt.grid(True)
    plt.show()

def main():
    results = measure_running_times()
    plot_results(results)

if __name__=="__main__":
    main()
