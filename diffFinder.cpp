#include <iostream>
#include <fstream>
#include "printing.hpp"
#include <vector>
#include <utility> 
#include <stdexcept> 
#include <algorithm> 

using namespace std;

template <typename T>
vector<T> LCS(vector<T> a, vector<T> b){
    vector<vector<int>> memo(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    int ans = memo[a.size()][b.size()];
    vector<T> elements{};
    int n = a.size();
    int m = b.size();
    while (n > 0 && m > 0) {
        if (a[n - 1] == b[m - 1]) {
            elements.push_back(a[n - 1]);
            n--;
            m--;
        } 
        else if (memo[n - 1][m] > memo[n][m - 1]) 
            n--;
        else 
            m--;
    }
    reverse(elements.begin(), elements.end());
    return elements;
}

void fillVectors(vector<string>& file1Lines, vector<string>& file2Lines, string file1Path, string file2Path){
    // Open the first file
    ifstream file1(file1Path);
    if (!file1.is_open()) {
        cerr << "Error: Could not open file " << file1Path << endl;
        throw runtime_error("file cant be opened");
    }

    // Read the first file into a vector
    string line;
    while (getline(file1, line)) {
        file1Lines.push_back(line);
    }
    file1.close();  // Close the file after reading

    // Open the second file
    ifstream file2(file2Path);
    if (!file2.is_open()) {
        cerr << "Error: Could not open file " << file2Path << endl;
        throw runtime_error("file cant be opened");
    }

    // Read the second file into a vector
    while (getline(file2, line)) {
        file2Lines.push_back(line);
    }
    file2.close();  // Close the file after reading
}

int main(int argc, char* argv[]){
    // Ensure two file paths are provided
    if (argc != 3) {
        cerr << "Usage: diffFinder <file1> <file2>" << endl;
        return 1;
    }

    // File paths from command line arguments
    string file1Path = argv[1];
    string file2Path = argv[2];

    // Vectors to store lines from each file
    vector<string> file1Lines;
    vector<string> file2Lines;

    fillVectors(file1Lines, file2Lines, file1Path, file2Path);
    // At this point, file1Lines and file2Lines contain the lines of the respective files
    vector<string> commonLines = LCS(file1Lines, file2Lines);
    int commonLength = commonLines.size();
    int changed = (file1Lines.size() - commonLength) + (file2Lines.size() - commonLength);
    cout<<"lines changes: "<<changed<<endl<<endl;
    printDiff(file1Lines, file2Lines, commonLines);
    return 0;
}