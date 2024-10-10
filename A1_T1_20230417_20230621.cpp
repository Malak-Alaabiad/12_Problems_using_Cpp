// => ** FCAI-CU – CS213 - Object Oriented Programming – 2024 - Assignment ( 1 ) - Task ( 1 ) ** <=
// => Last Modification Date: 8/10/2024
// => Under supervision of  : Dr.Mohamed El-Ramly
// => File Name             : CS213_A1_T1_20230417_20230621
// => Purpose               : A program to solve 12 problems using C++
// => Authors               : Malak Mohamed Saad Fahmy Al-Aabiad       => ID: ( 20230417 )    => PROBLEMS:     ( 1, 2, 5, 8, 10, 11 ) , the main function.
//                          : Mo'men Mohamed Mahmoud Mohamed Yosri     => ID: ( 20230621 )    => PROBLEMS:     ( 3, 4, 6, 7, 9, 12 ) , all validation
// => Emails                : malakkalaabiadd@gmail.com
//                          : momen.yosri@gmail.com

#include <bits/stdc++.h>

using namespace std;

// Function declarations
void startInterface();
void mainPage();
void startProgram();
string menu();

// Function to start the program and ask the user to choose between starting or exiting the program
void startInterface(){
    string choice1;
    // Display welcome message and options to the user
    cout << endl << "\n----------------------------------------------------------" << endl;
    cout <<         "||        ** WELCOME TO PROBLEM SOLVER PROGRAM **       ||   ";
    cout << endl << "----------------------------------------------------------" << endl;
    cout <<         "|| => PLEASE, CHOOSE WHAT DO YOU WANT TO DO:            ||";
    cout <<         "\n||     A ) START THE PROGRAM.                           ||"
                    "\n||     B ) EXIT.                                        ||";
    cout <<         "\n----------------------------------------------------------" << endl;
    cout <<         "   => Enter your choice: ";
    cin >> choice1;
    // Checking user's choice
    // If choice is A, continue
    // Change the input "choice" into uppercase
    for (char &c : choice1){
        c = toupper(c);
    }
    if (choice1 == "A") {

    }
    // If choice is B, exit the program
    // Change the input "choice" into uppercase
    else if (choice1 == "B") {
        cout << "\nEXITING the program..." << endl;
        exit(0);
    }
    // If choice is neither A nor B, ask the user to enter a valid choice
    else {
        // Error message for invalid choice
        cout << "\nOops!! INVALID CHOICE, PLEASE TRY AGAIN...";
        // Restart the function
        startInterface();
    }
}

// Function to display the menu to the user for choosing the problem he/she wants to try to solve
string menu() {
    string choice;
    // Displaying the menu with problem options
    cout << "\n------------------------------------------------------------------------------------------------------";
    cout << "\n||                  => Please, Choose the problem that you would like to try:                       ||"
            "\n------------------------------------------------------------------------------------------------------"
         << endl << "\n|| => 1 ) Correct sentence                ||        => 2 ) Convert male speech to inclusive speech  ||"
                    "\n|| => 3 ) Split a string                  ||        => 4 ) Find prime numbers                       ||"
                    "\n|| => 5 ) Player high score management    ||        => 6 ) Manage Binary Operations                 ||"
                    "\n|| => 7 ) Manage Domino Operations        ||        => 8 ) Fractal Pattern                          ||"
                    "\n|| => 9 ) Bears                           ||        => 10) Message Altering                         ||"
                    "\n|| => 11) Compare Files                   ||        => 12) Phishing Scanner                         ||"
                    "\n|| => 13) Exit the program                                                                          ||" << endl;
    cout         << "\n--------------------------------------------------------------------------------------------------------";
    cout         << "\n=> Enter your choice:  ";

    // Getting user's choice
    cin >> choice;
    cin.ignore();
    return choice;
}

// Problem 1: Correct sentence spacing and capitalization
void correctSentence() {
    string s, line;
    int empty_line_count = 0;
    cout << "ENTER A SENTENCE (It can be multiple lines, input an empty line to stop): ";

    // Input multiple lines
    while (true) {
        getline(cin, line);
        if (line.empty()) {
            empty_line_count++;
            if (empty_line_count == 2) {
                break;  // Stop input on two empty lines
            }
        } else {
            empty_line_count = 0;  // Reset the counter if the line isn't empty
        };

        // Ensure adding a space between lines
        if (!s.empty()) {
            s += " ";  // Separate lines with a space
        }

        // Check if adding the current line will exceed 100 characters
        if (s.length() + line.length() > 100) {
            s += line.substr(0, 100 - s.length());
            break;
        } else {
            s += line;
        }
    }

    // Process the sentence to correct capitalization and spacing
    string output = "";
    bool capital_letter = true;  // To capitalize the first letter of the sentence
    bool num_of_spaces = false;  // To handle multiple consecutive spaces

    for (int i = 0; i < s.length(); i++) {
        if (isspace(s[i])) {  // Check for spaces
            if (!num_of_spaces && !output.empty()) {
                output += ' ';  // Add a single space if not already added
                num_of_spaces = true;
            }
        } else {  // Process non-space characters
            if (capital_letter && isalpha(s[i])) {
                output += toupper(s[i]);  // Capitalize the first letter
                capital_letter = false;
            } else {
                output += tolower(s[i]);  // Convert the rest to lowercase
            }
            num_of_spaces = false;
        }
    }

    // Check for and remove a space before the period (if any)
    while (!output.empty() && output.back() == ' ' || output.back() == '.') {
        output.pop_back();
    }

    // Ensure the sentence ends with a period
    if (!output.empty() && output.back() != '.') {
        output += '.';
    }

    cout << "\nTHE CORRECTED SENTENCE IS: \n" << output << endl;
}

// Problem 2: Converts male speech to inclusive speech that includes both male and female
void convertMaleSpeech() {
    string s, line;
    int empty_line_count = 0;
    cout << "ENTER A SENTENCE (It can be multiple lines, input an empty line to stop): ";
    // Input multiple lines
    while (true) {
        getline(cin, line);
        if (line.empty()) {
            empty_line_count++;
            if (empty_line_count == 2) {
                break;  // Stop input on two empty lines
            }
        } else {
            empty_line_count = 0;  // Reset the counter if the line isn't empty
        };

        // Ensure adding a space between lines
        if (!s.empty()) {
            s += " ";  // Separate lines with a space
        }

        // Check if adding the current line will exceed 100 characters
        if (s.length() + line.length() > 100) {
            s += line.substr(0, 100 - s.length());
            break;
        } else {
            s += line;
        }
    }

    stringstream ss(s);
    string word, output = "";
    char punc = '\0';  // To store any punctuation after the word
    bool word2 = true;  // To ensure we don't add an extra space at the start

    // Process each word in the sentence
    while (ss >> word) {
        // Check if the word ends with punctuation
        if (!isalpha(word.back())) {
            punc = word.back();  // Store the punctuation
            word = word.substr(0, word.length() - 1);  // Remove punctuation for matching
        } else {
            punc = '\0';
        }

        // Replace masculine pronouns with inclusive ones
        if (word == "he") {
            word = "he or she";
        } else if (word == "him") {
            word = "him or her";
        } else if (word == "his") {
            word = "his or her";
        } else if (word == "He") {
            word = "He or she";
        } else if (word == "Him") {
            word = "Him or her";
        } else if (word == "His") {
            word = "His or her";
        } else if (word == "himself") {
            word = "himself or herself";
        } else if (word == "Himself") {
            word = "Himself or herself";
        }

        // Rebuild the sentence
        if (word2) {
            output += word;
            word2 = false;
        } else {
            output += " " + word;
        }

        // Add punctuation back if there was any
        if (punc != '\0') {
            output += punc;
        }
    }

    cout << "\nTHE INCLUSIVE SENTENCE IS: " << output << endl;
}

// Problem 3: Split a string by a delimiter in a single function
void splitString() {
    string s, delimiter;
    cout << "ENTER THE STRING TO SPLIT: ";
    getline(cin, s);
    cout << "ENTER THE DELIMITER: ";
    getline(cin, delimiter);

    vector<string> output;
    size_t pos = 0;
    string x;

    // Split the sentence based on the delimiter
    while ((pos = s.find(delimiter)) != string::npos) {
        x = s.substr(0, pos);
        output.push_back(x);
        s.erase(0, pos + delimiter.length());
    }

    // Add the last part of the string after the last delimiter
    output.push_back(s);

    cout << "\nTHE SPLIT OUTPUT IS: \n";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << "[\"" << output[i] << "\"]";
        if (i < output.size() - 1) {
            cout << " , ";  // Add a comma if not the last element or second to last
        }
    }
}

// Problem 4: Find prime numbers up to a given number
void findPrimes() {
    int n;
    cout << "ENTER THE UPPER LIMIT (n) TO FIND ALL PRIME NUMBERS UP TO n: ";
    cin >> n;

    if (n < 2) {
        cout << "NO PRIME NUMBERS EXIST BELOW (2)." << endl;
        return;
    }

    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;  // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            // Mark multiples of p as not prime
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    cout << "THE PRIME NUMBERS UP TO " << n << " ARE:\n";
    cout << "[ ";
    bool first = true;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            if (!first) {
                cout << ", ";
            }
            cout << i;
            first = false;
        }
    }
    cout << " ]";
    cout << endl;
}

// Problem 5: Player high score management
void manageScores() {
    vector<string> player_names;
    vector<int> player_scores;
    const int MAX_PLAYERS = 10;

    while (true) {
        // Display menu
        cout << "\n----------------------------------------------------------------------------------------------";
        cout << endl << "||                          ** Welcome To Player High Score Manager **                      ||";
        cout << "\n----------------------------------------------------------------------------------------------"
             << endl << "\n|| => 1 ) Add new player and score                ||        => 2 ) Print top 10 players     ||"
                        "\n|| => 3 ) Find a player's highest score                                                     ||";
        cout         << "\n----------------------------------------------------------------------------------------------";
        cout         << "\n=> Enter your choice:  ";

        int choice;
        cin >> choice;
        cin.ignore(); // Clear input buffer

        if (choice == 1) {
            // Add a new player and score
            string name;
            int score;
            cout << "\nENTER PLAYER NAME: ";
            getline(cin, name);
            cout << "\nENTER PLAYER SCORE: ";
            cin >> score;

            // Add the new player and score to the vectors
            player_names.push_back(name);
            player_scores.push_back(score);
            // Sort the players by score in descending order
            for (int i = 0; i < player_scores.size() - 1; i++) {
                for (int j = i + 1; j < player_scores.size(); j++) {
                    if (player_scores[i] < player_scores[j]) {
                        swap(player_scores[i], player_scores[j]);
                        swap(player_names[i], player_names[j]);
                    }
                }
            }

            // If there are more than MAX_PLAYERS, remove the one with the smallest score
            if (player_scores.size() > MAX_PLAYERS) {
                player_names.pop_back();
                player_scores.pop_back();
            }

        } else if (choice == 2) {
            // Print the top players and scores
            cout << "\nTop " << MAX_PLAYERS << " players and their scores:\n";
            for (int i = 0; i < player_names.size(); i++) {
                cout << player_names[i] << ": " << player_scores[i] << endl;
            }

        } else if (choice == 3) {
            // Find a player's highest score
            string name;
            cout << "ENTER PLAYER NAME: ";
            getline(cin, name);
            bool found = false;
            for (int i = 0; i < player_names.size(); i++) {
                if (player_names[i] == name) {
                    cout << name << "'s highest score is: " << player_scores[i] << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << name << " isn't in the top " << MAX_PLAYERS << " players.\n";
            }

        } else {
            cout << "INVALID CHOICE, PLEASE TRY AGAIN.\n";
        }
    }
}

// Problem 6: Manage binary operations
void binary() {
    while (true) {
        // Display menu
        cout << "\n------------------------------------------------------------";
        cout << "\n||        ** Binary Operations Manager **                 ||";
        cout << "\n------------------------------------------------------------";
        cout << "\n|| => 1) Print Binary Representation                      ||"
             << "\n|| => 2) Generate Binary Numbers with Prefix              ||";
        cout << "\n------------------------------------------------------------";
        cout << "\n=> Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            // Binary Print Operation
            long long n;
            cout << "\nENTER A NON-NEGATIVE NUMBER: ";
            cin >> n;

            if (n < 0) {
                cout << "\nINVALID INPUT. Please enter a non-negative number." << endl;
                continue;
            }

            // Lambda to print binary representation of n
            function<void(long long)> binaryPrint = [&](long long n) {
                if (n == 0) {
                    cout << "\nThe binary representation of 0 is: '0'";
                    return;
                }
                bitset<64> b(n);
                string binary = b.to_string();
                binary.erase(0, binary.find_first_not_of('0'));
                cout << "\nThe binary representation is:" << binary;
            };

            if (n == 0) {
                cout << "\nThe binary representation of 0 is: '0'";
            } else {
                binaryPrint(n);
            }
            cout << endl; // Newline after the output

        } else if (choice == 2) {
            // Generate Binary Numbers with Prefix Operation
            string prefix;
            int k;
            cout << "\nENTER PREFIX: ";
            cin >> prefix;

            // Check if the prefix contains only '0' or '1'
            if (prefix.find_first_not_of("01") != string::npos) {
                cout << "\nINVALID PREFIX. Prefix must contain only 0's and 1's.\n";
                continue;
            }

            cout << "\nENTER THE VALUE OF (k): ";
            cin >> k;

            if (k < 0) {
                cout << "\nINVALID INPUT. k must be non-negative." << endl;
                continue;
            }

            // Lambda to generate binary numbers while ignoring leading zeros
            function<void(const string&, int)> numbers = [&](const string& prefix, int k) {
                if (k == 0) {
                    // Remove leading zeros for printing
                    string noLeadingZeros = prefix;
                    noLeadingZeros.erase(0, min(noLeadingZeros.find_first_not_of('0'), noLeadingZeros.size() - 1));
                    cout << noLeadingZeros << endl;
                } else {
                    numbers(prefix + "0", k - 1);
                    numbers(prefix + "1", k - 1);
                }
            };

            numbers(prefix, k);

        } else {
            cout << "\nINVALID CHOICE. PLEASE TRY AGAIN.\n";
        }
    }
}

// Problem 7: Dominos
struct dominoT {
    int leftDots;
    int rightDots;
};
void dominos() {
    function<bool(vector<dominoT>&, vector<bool>&, int, int)> FormsDominoChainHelper = [&](vector<dominoT>& dominos, vector<bool>& used, int lastRight, int depth) {
        if (depth == dominos.size()) {
            return true;
        }

        for (int i = 0; i < dominos.size(); i++) {
            if (!used[i]) {
                if (dominos[i].leftDots == lastRight) {
                    used[i] = true;
                    if (FormsDominoChainHelper(dominos, used, dominos[i].rightDots, depth + 1)) {
                        return true;
                    }
                    used[i] = false;
                }
            }
        }

        return false;
    };

    auto FormsDominoChain = [&](vector<dominoT>& dominos) {
        vector<bool> used(dominos.size(), false);
        for (int i = 0; i < dominos.size(); i++) {
            used[i] = true;
            if (FormsDominoChainHelper(dominos, used, dominos[i].rightDots, 1)) {
                return true;
            }
            used[i] = false;
        }
        return false;
    };

    auto PrintDominoChain = [&](vector<dominoT>& dominos) {
        for (size_t i = 0; i < dominos.size(); ++i) {
            cout << dominos[i].leftDots << "|" << dominos[i].rightDots;
            if (i < dominos.size() - 1) {
                cout << " - ";
            }
        }
        cout << "\n";
    };

    while (true) {
        // Display menu
        cout << "\n------------------------------------------------------------";
        cout << "\n||        ** Domino Chain Manager **                       ||";
        cout << "\n------------------------------------------------------------";
        cout << "\n|| => 1) Check if a Domino Chain is Possible               ||"
             << "\n|| => 2) Print the Domino Chain                            ||";
        cout << "\n------------------------------------------------------------";
        cout << "\n=> Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int n;
            cout << "\nENTER THE NUMBER OF DOMINOS: ";
            cin >> n;
            vector<dominoT> dominos(n);
            cout << "\nENTER THE DOMINOS (leftDots rightDots):\n";
            for (int i = 0; i < n; i++) {
                cin >> dominos[i].leftDots >> dominos[i].rightDots;
            }

            bool result = FormsDominoChain(dominos);
            if (result) {
                cout << "YES!!\n";
            } else {
                cout << "NO!!\n";
            }

        } else if (choice == 2) {
            int n;
            cout << "\nENTER THE NUMBER OF DOMINOS: ";
            cin >> n;
            vector<dominoT> dominos(n);
            cout << "\nENTER THE DOMINOS (leftDots rightDots):\n";
            for (int i = 0; i < n; i++) {
                cin >> dominos[i].leftDots >> dominos[i].rightDots;
            }
            cout << "DOMINO CHAIN: ";
            PrintDominoChain(dominos);

        } else {
            cout << "INVALID CHOICE. PLEASE TRY AGAIN.\n";
        }
    }
}

// Problem 8: A Fractal Pattern
void fractalPattern() {
    int n, i;

    cout << "\nEnter a POWER OF (2) value for the number of stars: ";
    cin >> n;

    // Check if the input n is a power of 2
    if ((n & (n - 1)) != 0) {
        cout << "\nPLEASE ENTER A POWER OF (2)!" << endl;
        return;
    }

    cout << "\nENTER THE STARTING COLUMN (i): ";
    cin >> i;

    cout << endl;

    function<void(int, int)> printPattern = [&](int n, int offset) {
        if (n == 0) return;

        printPattern(n / 2, offset);

        for (int j = 0; j < offset + i; j++) cout << " ";
        for (int j = 0; j < n; j++) cout << "* ";
        cout << endl;

        printPattern(n / 2, offset + n);
    };

    printPattern(n, 0);
}

// Problem 9: Teddy Bear Picnic
bool bears(int n) {
    if (n == 42) {
        return true;
    }

    if (n < 42) {
        return false;
    }

    if (n % 2 == 0) {
        if (bears(n / 2)) {
            return true;
        }
    }

    if (n % 3 == 0 || n % 4 == 0) {
        int lastDigit = n % 10;
        int secondLastDigit = (n % 100) / 10;
        int product = lastDigit * secondLastDigit;
        if (product > 0 && bears(n - product)) {
            return true;
        }
    }

    if (n % 5 == 0) {
        if (bears(n - 42)) {
            return true;
        }
    }

    return false;
}


#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif
// Problem 10: Message Altering to Avoid Censorship
void messageAltering() {
    string messageFile = "message.txt";
    string lookupFile = "lookup.txt";
    string outputFile = "output.txt";

    locale::global(locale(""));

    wifstream messageInput(messageFile);
    messageInput.imbue(locale(messageInput.getloc(), new codecvt_utf8<wchar_t>));

    if (!messageInput) {
        wcerr << L"ERROR!! COULDN'T OPEN MESSAGE FILE!" << endl;
        return;
    }

    wifstream lookupInput(lookupFile);
    lookupInput.imbue(locale(lookupInput.getloc(), new codecvt_utf8<wchar_t>));

    if (!lookupInput) {
        wcerr << L"ERROR!! COULDN'T OPEN LOOKUP FILE!" << endl;
        return;
    }

    map<wstring, vector<wstring>> lookupTable;
    wstring line;
    while (getline(lookupInput, line)) {
        wstringstream ss(line);
        wstring word, alternatives;

        if (getline(ss, word, L':') && getline(ss, alternatives)) {
            vector<wstring> altWords;
            wstringstream altStream(alternatives);
            wstring alt;
            while (getline(altStream, alt, L',')) {
                altWords.push_back(alt);
            }
            lookupTable[word] = altWords;
        }
    }

    wstring message((istreambuf_iterator<wchar_t>(messageInput)), istreambuf_iterator<wchar_t>());

    wstringstream messageStream(message);
    wstring word;
    wstring alteredMessage;
    random_device rd;
    mt19937 gen(rd());

    while (messageStream >> word) {
        if (lookupTable.find(word) != lookupTable.end()) {
            vector<wstring>& alternatives = lookupTable[word];
            uniform_int_distribution<> dis(0, alternatives.size() - 1);
            alteredMessage += alternatives[dis(gen)] + L" ";
        } else {
            alteredMessage += word + L" ";
        }
    }

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#endif

    wcout.imbue(locale());
    wcout << L"\nALTERED MESSAGE: \n" << alteredMessage << endl;

    wofstream output(outputFile);
    output.imbue(locale(output.getloc(), new codecvt_utf8<wchar_t>));

    if (!output) {
        wcerr << L"ERROR!! COULDN'T OPEN OUTPUT FILE!" << endl;
        return;
    }

    output << alteredMessage;
    output.close();
    wcout << L"Altered message saved to " << outputFile.c_str() << endl;
}

#include "cmake-build-debug/tinyfiledialogs.h"

// Problem 11: File Comparison
void compareFiles() {
    const char* file1;
    const char* file2;

    // Open file dialog to select files
    file1 = tinyfd_openFileDialog("Select the first file", "", 0, NULL, NULL, 0);
    if (!file1) {
        cerr << "\nERROR!! NO FILE SELECTED FOR THE FIRST FILE!" << endl;
        return;
    }

    file2 = tinyfd_openFileDialog("Select the second file", "", 0, NULL, NULL, 0);
    if (!file2) {
        cerr << "\nERROR!! NO FILE SELECTED FOR THE SECOND FILE!" << endl;
        return;
    }

    // Open the files
    ifstream fileInput1(file1), fileInput2(file2);
    if (!fileInput1 || !fileInput2) {
        cerr << "\nERROR!! COULDN'T OPEN ONE OR BOTH FILES!" << endl;
        return;
    }

    cout << "\nEnter 1 for character-by-character comparison or 2 for word-by-word comparison: ";
    int comparisonType;
    cin >> comparisonType;
    cin.ignore();

    if (comparisonType == 1) {
        // Character-by-character comparison
        char char1, char2;
        int lineNumber = 1;
        bool areIdentical = true;

        while (fileInput1.get(char1) && fileInput2.get(char2)) {
            if (char1 != char2) {
                areIdentical = false;
                cout << "\nFiles differ at line " << lineNumber << ":\n";
                cout << "\nFile (1): " << char1 << "\nFile (2): " << char2 << endl;
                break;
            }
            if (char1 == '\n') {
                lineNumber++;
            }
        }

        if (fileInput1.get(char1) || fileInput2.get(char2)) {
            areIdentical = false;
            cout << "\nOne file has more content than the other." << endl;
        }

        if (areIdentical) {
            cout << "\nThe files are identical (character-by-character)." << endl;
        }

    } else if (comparisonType == 2) {
        // Word-by-word comparison
        string word1, word2;
        string line1, line2;
        int lineNumber = 1;
        bool areIdentical = true;
        while (getline(fileInput1, line1) && getline(fileInput2, line2)) {
            stringstream stream1(line1), stream2(line2);
            while (stream1 >> word1 && stream2 >> word2) {
                if (word1 != word2) {
                    areIdentical = false;
                    cout << "Files differ at line " << lineNumber << ":\n";
                    cout << "File 1: " << word1 << "\nFile 2: " << word2 << endl;
                    break;
                }
            }
            if (!areIdentical) {
                break;
            }
            lineNumber++;
        }

        if (getline(fileInput1, line1) || getline(fileInput2, line2)) {
            areIdentical = false;
            cout << "\nOne file has more content than the other." << endl;
        }

        if (areIdentical) {
            cout << "\nThe files are identical (word-by-word)." << endl;
        }

    } else {
        cout << "\nInvalid comparison type." << endl;
    }
}

// Problem 12: Phishing Scanner
void phishingScanner() {
    unordered_map<string, int> phishingKeywords = {
            {"bank", 3}, {"credit card", 3}, {"password", 3}, {"social security", 3},
            {"verify your account", 2}, {"click here", 2}, {"urgent", 2},
            {"limited time", 1}, {"free", 1}, {"win", 1}, {"offer", 1}, {"secure", 2},
            {"personal", 2}, {"security alert", 3}, {"login", 2}, {"account suspended", 3},
            {"congratulations", 1}, {"confirm", 2}, {"confidential", 3},
            {"credit score", 3}, {"identity theft", 3}, {"paypal", 3}, {"ebay", 3},
            {"social media", 1}, {"reset password", 2}, {"your account", 2},
            {"dear customer", 1}, {"order now", 1}, {"act fast", 2}, {"secure payment", 2}
    };

    string filename;
    cout << "\nENTER THE FULL PATH OF THE FILE TO SCAN FOR PHISHING KEYWORDS: ";
    getline(cin, filename);  // Use getline to allow spaces in the path

    ifstream file(filename);
    if (!file) {
        cerr << "ERROR!! COULDN'T OPEN THE FILE!" << endl;
        return;
    }

    string line, word;
    int totalPoints = 0;

    // Iterate through the file line by line
    while (getline(file, line)) {
        for (const auto& keyword : phishingKeywords) {
            size_t pos = line.find(keyword.first);
            while (pos != string::npos) {
                totalPoints += keyword.second;  // Add points for each keyword found
                cout << "Keyword: " << keyword.first << " | Points: " << keyword.second << endl;
                pos = line.find(keyword.first, pos + keyword.first.length());  // Find next occurrence
            }
        }
    }

    // Print total phishing score
    cout << "\nTOTAL PHISHING POINTS: " << totalPoints << endl;

    file.close();
}

int main() {
    // Display the main page
    mainPage();
    // Start the image processing program
    startProgram();
}

void mainPage() {
    // Display the start interface
    startInterface();
}

void startProgram() {
    string choice2 = menu();
    if (choice2 == "1") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n------------------------------------------------------------------------------------------------------";
            cout << endl << "||                   ** Welcome To Correct sentence spacing and capitalization **                   ||";
            cout << "\n------------------------------------------------------------------------------------------------------";
            cout << endl << "\n|| The program reads in a sentence of up to 100 characters and outputs the sentence with spacing    ||\n"
                            "|| corrected and with letters corrected for capitalization. In other words, in the output sentence, ||\n"
                            "|| all strings of two or more blanks should be compressed to a single blank.                        ||\n"
                            "|| The sentence should start with an uppercase letter but should contain no other uppercase letters.||" << endl;
            cout << "\n------------------------------------------------------------------------------------------------------" << endl;
            correctSentence();
            break;
        }
    }

    else if (choice2 == "2") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n--------------------------------------------------------------------------------------";
            cout << endl << "||            ** Welcome To Convert male speech to inclusive speech **              ||";
            cout << "\n--------------------------------------------------------------------------------------";
            cout << endl << "\n|| This program will ask for a sentence, read the sentence into a string variable,  ||\n"
                            "|| and replace all occurrences of masculine pronouns with both-gender pronouns.     ||\n"
                            "|| For example, it will replace 'he' with 'he or she'.                              ||\n"<< endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            convertMaleSpeech();
            break;
        }
    }

    else if (choice2 == "3") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n------------------------------------------------------------------------------------------";
            cout << endl << "||                    ** Welcome To Split a string by a delimiter **                    ||";
            cout << "\n------------------------------------------------------------------------------------------";
            cout << endl << "\n|| Implement the function split so that it returns a vector of the strings in target    ||\n"
                            "|| that are separated by the string delimiter.                                          ||\n" << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            splitString();
            break;
        }
    }

    else if (choice2 == "4") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n--------------------------------------------------------------------------------------------";
            cout << endl << "||                        ** Welcome To Find prime numbers  **                            ||";
            cout << "\n--------------------------------------------------------------------------------------------";
            cout << endl << "\n|| In the 3rd century B.C., the Greek astronomer Eratosthenes developed an algorithm      ||\n"
                            "|| to find all the prime numbers up to some upper limit N.                                || \n"
                            "|| To apply the algorithm, you write down a list of the integers between 2 and N.         ||\n" << endl;
            cout << "--------------------------------------------------------------------------------------------" << endl;
            findPrimes();
            break;
        }
    }

    else if (choice2 == "5") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n---------------------------------------------------------------------------------------------------------";
            cout << endl << "||                            ** Welcome To Player high score management  **                           ||";
            cout << "\n---------------------------------------------------------------------------------------------------------";
            cout << endl << "\n|| This program manages a list of up to 10 players and their high scores in the computer’s memory.   ||\n"
                            "|| Use suitable arrays, vector and/or structures to manage the list.                                   ||\n" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            manageScores();
            break;
        }
    }

    else if (choice2 == "6") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n------------------------------------------------------------";
            cout << endl << "||       ** Welcome To Manage Binary Operations  **       ||";
            cout << "\n------------------------------------------------------------";
            binary();
            break;
        }
    }

    else if (choice2 == "7") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n-------------------------------------------------------------------------------------------------";
            cout << endl << "||                      ** Welcome To Player Manage Domino Operations  **                      ||";
            cout << "\n-------------------------------------------------------------------------------------------------";
            cout << endl << "\n|| The game of dominos is played with rectangular pieces composed of two connected squares,    ||"
                            "\n|| each of which is marked with a certain number of dots.                                      ||\n" << endl;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            dominos();
            break;
        }
    }

    else if (choice2 == "8") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n--------------------------------------------------------------------";
            cout << endl << "||               ** Welcome To Fractal Pattern  **                ||";
            cout << "\n--------------------------------------------------------------------";
            fractalPattern();
            break;
        }
    }

    else if (choice2 == "9") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n-----------------------------------------------------------------------------------------";
            cout << endl << "||                               ** Welcome To Bears  **                               ||";
            cout << "\n-----------------------------------------------------------------------------------------";
            cout << endl << "\n|| A game with teddy bears. It starts when I give you some bears. You can then         ||"
                            "\n|| give back some bears.                                                               ||\n";
            cout << "\n-----------------------------------------------------------------------------------------" << endl;
            int n;
            cout << "\nENTER THE NUMBER OF BEARS: ";
            cin >> n;

            if (bears(n)) {
                cout << "\nYES, IT'S POSSIBLE TO WIN THE TEDDY BEAR GAME!";
                cout << endl;
            } else {
                cout << "\nNO, IT'S NOT POSSIBLE TO WIN THE TEDDY BEAR GAME!";
                cout << endl;
            }
            break;
        }
    }

    else if (choice2 == "10") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n------------------------------------------------------------------------------------------------------------";
            cout << endl << "||                                   ** Welcome To Message Altering  **                                   ||";
            cout << "\n------------------------------------------------------------------------------------------------------------";
            cout << endl << "\n|| Message Altering to Avoid Censorship. In time of conflict, as currently, social media platforms        ||\n"
                            "|| usually have bias to one side and censor content or posts supporting the other side.                   ||\n" << endl;
            cout << "\n------------------------------------------------------------------------------------------------------------" << endl;
            locale::global(locale(locale(), new codecvt_utf8<wchar_t>));
            messageAltering();
            break;
        }
    }

    else if (choice2 == "11") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n-------------------------------------------------------------------------------------------------------------";
            cout << endl << "||                                     ** Welcome To Compare Files  **                                      ||";
            cout << "\n-------------------------------------------------------------------------------------------------------------";
            cout << endl << "\n|| A file comparison facility that asks the user for the names of                                           ||\n"
                            "|| two files to compare. It also asks the user if he wants a character by character comparison or word by   ||\n"
                            "|| word comparison.                                                                                         ||" << endl;
            cout << "\n--------------------------------------------------------------------------------------------------------------" << endl;
            compareFiles();
            break;
        }
    }

    else if (choice2 == "12") {
        while (true) {
            // Display welcome message and the explanation of the problem to the user
            cout << "\n----------------------------------------------------------------------------------------------";
            cout << endl << "||                             ** Welcome To Phishing Scanner  **                           ||";
            cout << "\n----------------------------------------------------------------------------------------------";
            cout << endl << "\n|| Phishing is a form of identity theft in which, in an e-mail,                             ||\n"
                            "|| a sender posing as a trustworthy source attempts                                         ||\n"
                            "|| to acquire private information, such as your user names, passwords, credit-card numbers  ||\n"
                            "|| and social security number. Phishing e-mails claiming to be from popular banks,          ||\n"
                            "|| credit-card companies, auction sites, social networks                                    ||\n"
                            "|| and online payment services may look quite legitimate.                                   ||\n"
                            "|| These fraudulent messages often provide links to spoofed (fake)                          ||\n"
                            "|| websites where you’re asked to enter sensitive information.                            ||" << endl;
            cout << "\n----------------------------------------------------------------------------------------------" << endl;
            phishingScanner();
            break;
        }
    }

    else if (choice2 == "13") {
        // If choice is 6, exit the program
        cout << "\nExiting the program..." << endl;
        exit(0);
    }
    else {
        // Error message for invalid choice
        cout << endl << "INVALID CHOICE. PLEASE TRY AGAIN.";
        startProgram();
    }

    string choice3;
    // Ask the user if he\she wants to try another filter or exit the program
    while (true){
        cout << endl << "\nDo you want to try to solve another problem? (Yes/No): ";
        // Take user's choice
        cin >> choice3;
        for (char &c : choice3){
            c = tolower(c);
        }
        if (choice3 == "yes") {
            // Start the program again
            cin.ignore();
            startProgram();
        }
        else if (choice3 == "no") {
            // If choice is NO, exit the program
            cout << "\nExiting the program..." << endl;
            exit(0);
        }
        else {
            // Error message for invalid choice
            cout << endl << "INVALID CHOICE. PLEASE TRY AGAIN." << endl;
            cin.ignore();
            continue;
        }
    }
}