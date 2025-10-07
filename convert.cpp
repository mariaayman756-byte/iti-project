#include<iostream>
#include<string>
using namespace std;

string letters[] = {
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    "0","1","2","3","4","5","6","7","8","9"
};

string morse[] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
    ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
    ".--","-..-","-.--","--..",
    "-----",".----","..---","...--","....-",".....","-....","--...","---..","----."
};

string texttomorse(string text) {
    string res = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            res += "/ ";
            continue;
        }
        text[i] = toupper(text[i]);
        for (int j = 0; j < 36; j++) {
            if (string(1, text[i]) == letters[j]) {
                res += morse[j] + " ";
                break;
            }
        }
    }
    return res;
}

string morsetotext(string code) {
    string res = "", temp = "";
    code += " ";
    for (int i = 0; i < code.length(); i++) {
        if (code[i] != ' ') {
            temp += code[i];
        }
        else {
            if (temp == "/") {
                res += " ";
            }
            else {
                for (int j = 0; j < 36; j++) {
                    if (temp == morse[j]) {
                        res += letters[j];
                        break;
                    }
                }
            }
            temp = "";
        }
    }
    return res;
}

int menu1() {
    int ans;
    cout << "---Morse Code Converter---\n";
    cout << "1. Text to Morse" << endl;
    cout << "2. Morse to Text" << endl;
    cout << "Enter your choice: ";
    cin >> ans;
    cin.ignore();
    return ans;
}

string menu2(int x) {
    string ans, res;
    if (x == 1) {
        cout << "Enter text: ";
        getline(cin, ans);
        res = texttomorse(ans);
    }
    else {
        cout << "Enter Morse (use '/' for spaces): ";
        getline(cin, ans);
        res = morsetotext(ans);
    }
    return res;
}

int main() {
    int answer = menu1();
    string result = menu2(answer);
    cout << "Result: " << result << endl;
    return 0;
}
