#include "printing.hpp"
#include "bits/stdc++.h"

using namespace std;
// Function to print text in red
void printRed(const string& text) {
#ifdef _WIN32
    // Windows: use system Color command
    // Red background with white text (0C for background and text)
    system("Color 0C");
    cout << text << endl;
    // Reset to default color
    system("Color 07");
#else
    // Linux/macOS: use ANSI escape codes
    cout << "\033[31m" << text << "\033[0m" << endl;  // 31 is red
#endif
}

// Function to print text in green
void printGreen(const string& text) {
#ifdef _WIN32
    // Windows: use system Color command
    // Green text on black background (0A)
    system("Color 0A");
    cout << text << endl;
    // Reset to default color
    system("Color 07");
#else
    // Linux/macOS: use ANSI escape codes
    cout << "\033[32m" << text << "\033[0m" << endl;  // 32 is green
#endif
}

void printDiff(const vector<string>& file1, const vector<string>& file2, const vector<string>& common){
    int line1 = 0, line2 = 0, commonCount = 0;
    cout<<"Before:"<<endl<<endl;
    while(line1<file1.size()){
        if(commonCount == common.size()) printRed(file1[line1]);
        else if(common[commonCount] == file1[line1]) {
            cout<<file1[line1]<<endl;
            commonCount++;
        }
        else printRed(file1[line1]);
        line1++;
    }
    cout<<endl<<"After:"<<endl<<endl;
    commonCount = 0;
    while(line2<file2.size()){
        if(commonCount == common.size()) printGreen(file2[line2]);
        else if(common[commonCount] == file2[line2]){
            cout<<file2[line2]<<endl;
            commonCount++;
        }
        else printGreen(file2[line2]);
        line2++;
    }
    cout<<endl;
}
