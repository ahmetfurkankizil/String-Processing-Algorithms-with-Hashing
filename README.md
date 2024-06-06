# String-Processing-Algorithms-with-Hashing

## Overview

This project implements three distinct string processing algorithms, each utilizing hashing techniques for efficient execution. The focus is on leveraging hash tables for tasks like prefix and suffix matching, pattern searching, and string manipulation operations such as reversing and shifting. The implementation is designed to handle large datasets efficiently, adhering to specific computational complexity requirements.

## Table of Contents

1. [Subtask 1: Prefix and Suffix Matching](#subtask-1-prefix-and-suffix-matching)
2. [Subtask 2: Pattern Occurrence in Text](#subtask-2-pattern-occurrence-in-text)
3. [Subtask 3: Minimal Subset of Strings](#subtask-3-minimal-subset-of-strings)
4. [Usage](#usage)
5. [Implementation Details](#implementation-details)

## Subtask 1: Prefix and Suffix Matching

Given a set of unique strings, this algorithm counts the number of pairs `(i, j)` such that the `i`-th string is either a prefix or a suffix of the `j`-th string and `i ≠ j`.

### Key Points:
- **Hashing Technique:** Separate chaining
- **Complexity:** O(total_number_of_characters)
- **File Input:** The name of the input file is provided as a command line argument.

### Example:
```
Strings: ["ab", "abc", "abcde", "cab", "bc", "bca"]
Output: 10 (Number of valid (i, j) pairs)
```

## Subtask 2: Pattern Occurrence in Text

This subtask identifies the occurrences of multiple patterns within a given text.

### Key Points:
- **Hashing Technique:** Standard hashing (no separate chaining required)
- **Complexity:** O((n + m) * log m + total_number_of_characters)
- **File Input:** The name of the input file is provided as a command line argument.

### Example:
```
Text: "abcdbcabcabcbcd"
Patterns: ["bc", "ab", "cd", "bcc"]
Output: 
bc: [2, 4, 11, 14]
ab: [1, 10]
cd: [6, 12, 16]
bcc: [4, 14]
```

## Subtask 3: Minimal Subset of Strings

This algorithm finds the minimal subset of given strings by applying reverse and shift operations. The goal is to minimize the number of reverse operations while ensuring the minimal subset is achieved.

### Key Points:
- **Hashing Technique:** Utilizes hashing to efficiently manage reverse and shift operations
- **Complexity:** O(total_number_of_characters * log n)
- **File Input:** The name of the input file is provided as a command line argument.

### Example:
```
Strings: ["abcd", "bcda", "baaa", "aaab", "bcd"]
Output:
Reverse operations: 1
Size of minimal subset: 2
```

## Usage

To run any of the subtasks, use the following command line interface:

```bash
./program_name input_file output_file
```

- `input_file`: Path to the input file containing the required data.
- `output_file`: Path to the output file where results will be written.

Example:

```bash
./prefix_suffix_matching input.txt output.txt
```

## Implementation Details

### Subtask 1 Implementation

- **Hash Table:** Implemented using separate chaining to handle collisions.
- **Data Structure:** Custom hash table implementation based on lecture slides.
- **Algorithm:** Efficiently computes prefix and suffix pairs without checking all possible pairs.

### Subtask 2 Implementation

- **Hashing:** Utilizes a straightforward hash table for pattern matching.
- **Algorithm:** Finds occurrences of patterns in the text in logarithmic time.

### Subtask 3 Implementation

- **Hashing:** Efficiently manages reverse and shift operations using a hash table.
- **Algorithm:** Minimizes reverse operations and identifies the minimal subset size.

This project showcases the power of hashing in solving complex string processing problems efficiently. Each subtask is designed to meet specific computational requirements, ensuring scalability and performance even with large datasets.
