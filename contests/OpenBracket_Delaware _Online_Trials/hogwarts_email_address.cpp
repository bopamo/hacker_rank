#include <bits/stdc++.h>

using namespace std;

const int EMAIL_LENGTH = 18;

const string domain = "@hogwarts.com";

bool valid_letter(char c) {
    
    return ( isalpha(static_cast<unsigned char>(c)) && islower(static_cast<unsigned char>(c)) );
}


string isValid(string email) {
    // Complete this function
    
    string response = "No";
    
    if( email.size() != EMAIL_LENGTH ) return response;
    
    for(int i = 0; i < 5; ++i) {
        if( !valid_letter(email[i]) ) return response;
    }
    
    if ( email.compare(5,13, domain) != 0 ) return response;
    
    return "Yes";
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
