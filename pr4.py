# Function for Linear Search
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return True  # Student attended the program
    return False  # Student did not attend the program

# Function for Sentinel Search
def sentinel_search(arr, target):
    n = len(arr)
    # Add the target value as a sentinel at the end of the array
    arr.append(target)

    i = 0
    while arr[i] != target:
        i += 1

    # Remove the sentinel from the array after search
    arr.pop()

    if i < n:
        return True  # Student attended the program
    return False  # Student did not attend the program

# Example usage
roll_numbers = [101, 102, 103, 105, 107, 108]  # List of roll numbers in random order
target_roll_number = 105

# Linear Search
print("Using Linear Search:")
if linear_search(roll_numbers, target_roll_number):
    print(f"Student with roll number {target_roll_number} attended the program.")
else:
    print(f"Student with roll number {target_roll_number} did not attend the program.")

# Sentinel Search
print("\nUsing Sentinel Search:")
if sentinel_search(roll_numbers, target_roll_number):
    print(f"Student with roll number {target_roll_number} attended the program.")
else:
    print(f"Student with roll number {target_roll_number} did not attend the program.")
