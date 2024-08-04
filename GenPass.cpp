#include <ctime> // C++ library to retrieve and manipulate time information
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// desired password format: (mix of 5 total letters and numbers)-(mix of 5 total letters and numbers)-(mix of 5 total letters and numbers)
// eg: m8o9H-w39JL-a7x9K
// we need 6 numbers between 0-9
// we need 5 lowercase letters (97-122)
// we need 4 uppercase latters (65-90)

// Function to generate 4 random uppercase letters (ASCII range 65-90)
vector<int> genUps() {
    vector<int> ups(4); // Initialize a vector to store 4 integers

    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator with the current time

    for (int i = 0; i < 4; i++) {
        ups[i] = 65 + (rand() % 26); // Generate a random number between 65 and 90 (inclusive) and store it in the vector
    }

    return ups; // Return the vector of random uppercase letters
}

// Function to generate 5 random lowercase letters (ASCII range 97-122)
vector<int> genLows() {
    vector<int> lows(5); // Initialize a vector to store 5 integers

    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator with the current time

    for (int i = 0; i < 5; i++) {
        lows[i] = 97 + (rand() % 26); // Generate a random number between 97 and 122 (inclusive) and store it in the vector
    }

    return lows; // Return the vector of random lowercase letters
}

// Function to generate 6 random digits (0-9)
vector<int> genNums() {
    vector<int> nums(6); // Initialize a vector to store 6 integers

    srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator with the current time

    for (int i = 0; i < 6; i++) {
        nums[i] = rand() % 10; // Generate a random number between 0 and 9 (inclusive) and store it in the vector
    }

    return nums; // Return the vector of random digits
}

// Function to convert an integer to a single-character string
string asciiConvert(int num){
    char ch = static_cast<char>(num); // Convert the integer to a character
    string str(1, ch); // Create a string from the character
    return str; // Return the string
}

// Function to convert an integer to a string
string intToStr(int num){
    string str = to_string(num); // Convert the integer to a string
    return str; // Return the string
}

// Function to shuffle a vector of strings using the Fisher-Yates shuffle algorithm
void shuffleVector(vector<string>& vec) {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator with the current time

    for (size_t i = vec.size() - 1; i > 0; --i) {
        size_t j = rand() % (i + 1); // Generate a random index from 0 to i
        swap(vec[i], vec[j]); // Swap the elements at index i and j
    }
}

// Function to generate a password
vector<string> genPass(){
    vector<int> ups = genUps(); // Generate uppercase letters
    vector<int> lows = genLows(); // Generate lowercase letters
    vector<int> nums = genNums(); // Generate digits

    vector<string> passWord; // Initialize a vector to store the password

    // Convert the generated uppercase letters to strings and add to the password vector
    for(int num : ups){
        passWord.push_back(asciiConvert(num));
    }

    // Convert the generated lowercase letters to strings and add to the password vector
    for(int num: lows){
        passWord.push_back(asciiConvert(num));
    }

    // Convert the generated digits to strings and add to the password vector
    for(int num : nums){
        passWord.push_back(intToStr(num));
    }

    shuffleVector(passWord); // Shuffle the password vector

    // Insert hyphens at positions 5 and 11 to create the desired password format
    passWord.insert(passWord.begin() + 5, "-");
    passWord.insert(passWord.begin() + 11, "-");

    return passWord; // Return the password vector
}

// Main function
int main(void) {
    vector<string> pass = genPass(); // Generate the password

    cout << "\n";
    cout << "Here's a random password: " ;

    // Print each element of the password vector
    for(string item : pass){
        cout << item;
    }

    cout << "\n\n"; // Print two newline characters
}
