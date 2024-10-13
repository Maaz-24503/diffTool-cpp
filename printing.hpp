#ifndef PRINTING_HPP
#define PRINTING_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#ifdef _WIN32
    #include <windows.h>
#endif

// Function to print text in red
void printRed(const std::string& text);

// Function to print text in green
void printGreen(const std::string& text);

// Function to print file differences 
void printDiff(const std::vector<std::string>& file1, const std::vector<std::string>& file2, const std::vector<std::string>& common);

#endif // PRINTING_HPP