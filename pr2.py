from collections import Counter

# Function to compute the average score
def average_score(marks):
    valid_marks = [mark for mark in marks if mark is not None]  # Filter out absent students
    if valid_marks:
        return sum(valid_marks) / len(valid_marks)
    return 0  # Return 0 if no valid marks

# Function to compute highest and lowest scores
def highest_and_lowest_score(marks):
    valid_marks = [mark for mark in marks if mark is not None]  # Exclude absent students
    if valid_marks:
        highest = max(valid_marks)
        lowest = min(valid_marks)
        return highest, lowest
    return None, None  # Return None if no valid marks

# Function to count absent students
def count_absent_students(marks):
    return marks.count(None)  # Count how many students have None as their mark (absent)

# Function to display the mark with the highest frequency (mode)
def most_frequent_mark(marks):
    valid_marks = [mark for mark in marks if mark is not None]  # Exclude absent students
    if valid_marks:
        mark_count = Counter(valid_marks)
        most_common = mark_count.most_common(1)[0]  # Get the most common mark
        return most_common
    return None, 0  # Return None if no valid marks

# Example usage:
# Marks list (None represents students who were absent)
marks = [85, 90, 75, None, 85, 92, 90, 100, None, 80, 75, 85, 85]

# Compute average score
avg_score = average_score(marks)
print(f"Average score of the class: {avg_score:.2f}")

# Compute highest and lowest scores
highest, lowest = highest_and_lowest_score(marks)
if highest is not None and lowest is not None:
    print(f"Highest score: {highest}, Lowest score: {lowest}")
else:
    print("No valid scores available.")

# Count absent students
absent_count = count_absent_students(marks)
print(f"Number of students who were absent: {absent_count}")

# Find the mark with the highest frequency
most_frequent, frequency = most_frequent_mark(marks)
if most_frequent is not None:
    print(f"The mark with the highest frequency: {most_frequent} (Frequency: {frequency})")
else:
    print("No valid marks to determine the frequency.")
