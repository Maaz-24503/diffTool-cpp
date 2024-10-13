# diffFinder

`diffFinder` is a command-line tool that utilizes the Longest Common Subsequence (LCS) dynamic programming algorithm to compare two text files and highlight the differences. This tool is particularly useful for developers, writers, and anyone who needs to track changes between two versions of a document.

## Real-Life Use of LCS Algorithm

The Longest Common Subsequence (LCS) algorithm is a classic example of dynamic programming (DP) used in various applications, including:

- **Version Control**: LCS can help track changes in source code by identifying lines that have been added, removed, or modified.
- **Text Comparison**: Useful in text editing applications to display differences between two documents.
- **Bioinformatics**: LCS is used in comparing DNA sequences, helping in genetic research and analysis.

### How LCS Works in diffFinder

The `diffFinder` tool applies the LCS algorithm as follows:

1. **Input Files**: The tool reads two input files line by line, storing the contents in vectors.
2. **Dynamic Programming Table**: A 2D vector `memo` is created to store the lengths of common subsequences. The algorithm iterates through both input vectors, filling in the table based on whether characters (or lines) match.
3. **Backtracking**: Once the table is filled, the algorithm backtracks to identify the actual common subsequence, which helps determine which lines are unchanged, added, or removed.
4. **Output**: The differences between the two files are printed, highlighting added lines in green and removed lines in red.

## Cloning and Using diffFinder

To use `diffFinder`, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd diffFinder
   ```
2. **Compile the Code**: Ensure you have a C++ compiler installed. Run the following command in your terminal:
    ```bash
    g++ -o diffFinder diffFinder.cpp printing.cpp
    ```
3. **Run the Program**: You can run the program by providing two text files as arguments:
    ```bash
    ./diffFinder version1.txt version2.txt
    ```