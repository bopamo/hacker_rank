#include <bits/stdc++.h>

using namespace std;

using uMap = unordered_map<int, int>;

int birthdayCakeCandles(int n, vector <int> ar) {
    // Complete this function
    
    uMap m;
    
    int max = 0;
    for(const auto& i : ar) {
        m[i]++;
        
        if( i > max ) {
            max = i;
        }
    }
    
    return m[max];
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
