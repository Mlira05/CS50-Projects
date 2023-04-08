import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as csv_file:
        data_base = csv.DictReader(csv_file)
        for data in data_base:
            database.append(data)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequence_file:
        dna_sample = sequence_file.read()

    # Find longest match of each STR in DNA sequence
    # First I create a list of the databases first line (database[0])
    # Excluding the key "name" we get only the STR sequences
    sub_sequences = list(database[0].keys())[1:]

    # Now we match the subsequence found in the dna sample using the longest_match function
    # The match_sequence stores the results from the investigation
    match_sequence = {}
    for subsequence in sub_sequences:
        match_sequence[subsequence] = longest_match(dna_sample, subsequence)

    # Check database for matching profiles
    # It's important to recall that
    for profile in database:
        match = 0
        for subsequence in sub_sequences:
            if int(profile[subsequence]) == match_sequence[subsequence]:
                match += 1

        # Check if all the subsequences match the database
        # If it matches, print the dna profile's name
        if match == len(sub_sequences):
            print(profile['name'])
            return

    # If there's no match for all the subsequences, it should print "No Match"
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()