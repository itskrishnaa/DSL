# Function to display the word with the longest length
def longest_word(string):
    words = string.split()  # Split the string into words
    longest = max(words, key=len)  # Find the word with the maximum length
    return longest

# Function to determine the frequency of a particular character in the string
def character_frequency(string, char):
    return string.count(char)  # Use the count() method to get the frequency of a character

# Function to check whether the given string is a palindrome or not
def is_palindrome(string):
    # Remove spaces and convert to lowercase for case-insensitive comparison
    cleaned_string = string.replace(" ", "").lower()
    return cleaned_string == cleaned_string[::-1]  # Compare string with its reverse

# Function to display index of first appearance of the substring
def first_substring_index(string, substring):
    try:
        return string.index(substring)  # Use index() to get the first appearance index of the substring
    except ValueError:
        return -1  # If substring is not found, return -1

# Function to count the occurrences of each word in a given string
def word_count(string):
    words = string.split()  # Split the string into words
    word_freq = {}
    for word in words:
        word_freq[word] = word_freq.get(word, 0) + 1  # Count each word occurrence
    return word_freq

# Example usage of the functions
input_string = "madam arora teaches malayalam in a very madam way"
character_to_check = 'a'
substring_to_check = 'madam'

# Get longest word
longest = longest_word(input_string)
print(f"The longest word is: {longest}")

# Get character frequency
freq = character_frequency(input_string, character_to_check)
print(f"The frequency of character '{character_to_check}' is: {freq}")

# Check if the string is palindrome
palindrome_status = is_palindrome(input_string)
print(f"Is the string a palindrome? {palindrome_status}")

# Get index of the first appearance of a substring
substring_index = first_substring_index(input_string, substring_to_check)
if substring_index != -1:
    print(f"The first appearance of substring '{substring_to_check}' is at index: {substring_index}")
else:
    print(f"Substring '{substring_to_check}' not found.")

# Count occurrences of each word
word_occurrences = word_count(input_string)
print("Word frequencies:", word_occurrences)
