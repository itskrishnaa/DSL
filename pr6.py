def quick_sort(arr):
    """Quick sort function to sort an array of floating point numbers."""
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        lesser = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quick_sort(lesser) + [pivot] + quick_sort(greater)

# Function to display the top five scores
def display_top_five(scores):
    print("Top five scores:")
    for i in range(min(5, len(scores))):
        print(f"{i+1}: {scores[-(i+1)]:.2f}")

# Main program
if __name__ == "__main__":
    # Array to store 12th class percentages
    percentages = []

    # Input for the number of students and their scores
    n = int(input("Enter the number of students: "))
    for i in range(n):
        score = float(input(f"Enter the percentage for student {i+1}: "))
        percentages.append(score)

    # Sort the array using quick sort
    sorted_percentages = quick_sort(percentages)

    # Display the sorted array
    print("\nSorted percentages in ascending order:")
    print(sorted_percentages)

    # Display the top five scores
    display_top_five(sorted_percentages)
