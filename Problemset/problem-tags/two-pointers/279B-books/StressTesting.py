import random

# 1. The Slow, Guaranteed Correct Approach (O(N^2))
def solve_brute_force(n, t, a):
    max_books = 0
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += a[j]
            if current_sum <= t:
                max_books = max(max_books, j - i + 1)
            else:
                break # Sum exceeded, this start point 'i' can't go further
    return max_books

# 2. The Fast Sliding Window Approach (O(N)) - The one we proved
def solve_sliding_window(n, t, a):
    left = 0
    current_sum = 0
    max_books = 0
    for right in range(n):
        current_sum += a[right]
        while current_sum > t:
            current_sum -= a[left]
            left += 1
        max_books = max(max_books, right - left + 1)
    return max_books

# 3. Stress Test Runner
def run_stress_test():
    print("Starting Stress Test...")
    for i in range(10000): # Run 10,000 random tests
        # Generate random N (1 to 20) and T (1 to 100)
        n = random.randint(1, 20)
        t = random.randint(1, 100)
        # Generate random array of book times
        a = [random.randint(1, 20) for _ in range(n)]

        # Get results
        ans_fast = solve_sliding_window(n, t, a)
        ans_slow = solve_brute_force(n, t, a)

        # Compare
        if ans_fast != ans_slow:
            print(f"Mismatch found on test #{i}!")
            print(f"Input: n={n}, t={t}, a={a}")
            print(f"Fast Output: {ans_fast}")
            print(f"Slow Output: {ans_slow}")
            return
            
    print("Passed 10,000 random tests. The logic is correct.")

if __name__ == "__main__":
    run_stress_test()