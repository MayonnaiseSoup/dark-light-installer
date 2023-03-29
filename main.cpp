// Made by Marcus Cornes!
// Only works for Linux + MacOS

// Import files
#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>

// Define colours
#define RESET   "\033[0m"
#define GREEN   "\033[32m" 
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

// Set up namespace
using namespace std;

// Main loop
int main() {
    
    // Establish a Directory pointer
    const char* dir = "dark-light";

    // Make a special struct to hold our metadata
    struct stat sb;


    // Check if directory already exists
    if (stat(dir, &sb) == 0) {
        cout << RED << "---- ERROR: Directory already exists! ----" << RESET << endl;

        return 1;
    } 

    // Print out message
    cout << YELLOW << "Downloading Dark-Light through GIT...\n" << RESET << endl;

    // Download repository through git
    system("git clone https://github.com/MayonnaiseSoup/dark-light.git -q");


    // Check if it successfully downloaded
    if (stat(dir, &sb) == 0) {

        // Print out message
        cout << GREEN << "---- Successfully downloaded Dark-Light! ----" << RESET << endl;
        cout << "Opening application in default web-browser..." << endl;

        // Open up web browser
        system("open dark-light/index.html");

        // Print out message
        cout << "Opened Dark-Light! Enjoy 👋";

    } else {

        // Print an error
        
        cout << RED << "---- ERROR: Failed to download Dark-Light! ----" << RESET << endl;
        return 1;
    }
    

    // Return success
    return 0;

}