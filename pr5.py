# Function to perform Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # Find the minimum element in the remaining unsorted array
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function to perform Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # Last i elements are already in place, so ignore them
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element is greater than the next element
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Function to display the top five scores
def display_top_five_scores(arr):
    # Sort the array first (using any sorting algorithm)
    arr.sort()  # Sorting in ascending order
    print("Top 5 scores in ascending order:")
    # Display the last 5 elements (highest scores)
    for score in arr[-5:]:
        print(f"{score:.2f}")  # Print the score with 2 decimal places

# Example usage
first_year_percentages = [85.4, 92.3, 78.6, 88.5, 91.2, 75.3, 89.4, 80.1, 95.7, 76.8]

print("Original Percentages:")
print(first_year_percentages)

# Using Selection Sort to sort the array
selection_sorted = first_year_percentages.copy()  # Create a copy to preserve the original array
selection_sort(selection_sorted)
print("\nSorted using Selection Sort (Ascending):")
print(selection_sorted)

# Display Top 5 scores using the Selection Sort sorted array
print("\nTop 5 Scores using Selection Sort:")
display_top_five_scores(selection_sorted)

# Using Bubble Sort to sort the array
bubble_sorted = first_year_percentages.copy()  # Create a copy to preserve the original array
bubble_sort(bubble_sorted)
print("\nSorted using Bubble Sort (Ascending):")
print(bubble_sorted)

# Display Top 5 scores using the Bubble Sort sorted array
print("\nTop 5 Scores using Bubble Sort:")
display_top_five_scores(bubble_sorted)
