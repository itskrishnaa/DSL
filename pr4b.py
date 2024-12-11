# Function for Binary Search
def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return True  # Student attended the program
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return False  # Student did not attend the program

# Function for Fibonacci Search
def fibonacci_search(arr, target):
    n = len(arr)
    fib_m_2 = 0  # (m-2)'th Fibonacci number
    fib_m_1 = 1  # (m-1)'th Fibonacci number
    fib = fib_m_2 + fib_m_1  # m'th Fibonacci number

    # Find the smallest Fibonacci number greater than or equal to the length of the array
    while fib < n:
        fib_m_2 = fib_m_1
        fib_m_1 = fib
        fib = fib_m_2 + fib_m_1

    # Now fib is the smallest Fibonacci number greater than or equal to n
    offset = -1

    while fib > 1:
        i = min(offset + fib_m_2, n - 1)

        # If the target element is greater than the value at index i
        if arr[i] < target:
            fib = fib_m_1
            fib_m_1 = fib_m_2
            fib_m_2 = fib - fib_m_1
            offset = i

        # If the target element is less than the value at index i
        elif arr[i] > target:
            fib = fib_m_2
            fib_m_1 -= fib_m_2
            fib_m_2 = fib - fib_m_1

        # Target found at index i
        else:
            return True

    # Check if the last element is the target
    if fib_m_1 and arr[offset + 1] == target:
        return True

    return False  # Student did not attend the program

# Example usage
sorted_roll_numbers = [101, 102, 103, 105, 107, 108]  # Sorted list of roll numbers
target_roll_number = 105

# Binary Search
print("\nUsing Binary Search:")
if binary_search(sorted_roll_numbers, target_roll_number):
    print(f"Student with roll number {target_roll_number} attended the program.")
else:
    print(f"Student with roll number {target_roll_number} did not attend the program.")

# Fibonacci Search
print("\nUsing Fibonacci Search:")
if fibonacci_search(sorted_roll_numbers, target_roll_number):
    print(f"Student with roll number {target_roll_number} attended the program.")
else:
    print(f"Student with roll number {target_roll_number} did not attend the program.")
