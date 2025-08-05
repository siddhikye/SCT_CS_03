#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define CYAN    "\033[36m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define BOLD    "\033[1m"

string checkStrength(const string& password, string& color) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    int length = password.length();

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }

    int score = 0;
    if (length >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    switch (score) {
        case 5: color = GREEN; return "Very Strong";
        case 4: color = CYAN; return "Strong";
        case 3: color = YELLOW; return "Moderate";
        case 2: color = MAGENTA; return "Weak";
        default: color = RED; return "Very Weak";
    }
}

int main() {
    string password, color;
    
    cout << BOLD << BLUE << "🔐 Password Strength Checker 🔐" << RESET << endl;
    cout << "Enter your password: ";
    getline(cin, password);

    string strength = checkStrength(password, color);
    cout << "\nStrength: " << color << BOLD << strength << RESET << endl;

    return 0;
}
