# Define the sets of students who play each sport
cricket_players = {"Alice", "Bob", "Charlie", "David", "Eva"}
badminton_players = {"Bob", "Charlie", "Fay", "David", "George"}
football_players = {"Alice", "Charlie", "David", "George", "Henry"}

# Function to find students who play both cricket and badminton
def players_both_cricket_badminton(cricket_players, badminton_players):
    return cricket_players.intersection(badminton_players)

# Function to find students who play either cricket or badminton but not both
def players_either_but_not_both(cricket_players, badminton_players):
    return cricket_players.symmetric_difference(badminton_players)

# Function to find the number of students who play neither cricket nor badminton
def players_neither_cricket_nor_badminton(total_students, cricket_players, badminton_players):
    return total_students - (cricket_players.union(badminton_players))

# Function to find the number of students who play cricket and football but not badminton
def players_cricket_football_not_badminton(cricket_players, football_players, badminton_players):
    return cricket_players.intersection(football_players).difference(badminton_players)

# Example usage
total_students = {"Alice", "Bob", "Charlie", "David", "Eva", "Fay", "George", "Henry"}

# Get the required lists
both_cricket_badminton = players_both_cricket_badminton(cricket_players, badminton_players)
either_but_not_both = players_either_but_not_both(cricket_players, badminton_players)
neither_cricket_nor_badminton = players_neither_cricket_nor_badminton(total_students, cricket_players, badminton_players)
cricket_football_not_badminton = players_cricket_football_not_badminton(cricket_players, football_players, badminton_players)

# Output the results
print("Students who play both cricket and badminton:", both_cricket_badminton)
print("Students who play either cricket or badminton but not both:", either_but_not_both)
print("Number of students who play neither cricket nor badminton:", len(neither_cricket_nor_badminton))
print("Number of students who play cricket and football but not badminton:", len(cricket_football_not_badminton))
