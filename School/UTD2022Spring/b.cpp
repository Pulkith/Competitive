#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >>N;
    int cnt = 0;
    vector<string> reps = {
  "Wow! Either you got incredibly lucky or you are cheating!"
  "Impressive! That didn't take you very long."
  "Nice! Not bad. Not bad at all."
  "Pretty decent."
  "Cutting it a little close there, but we like to see it."
  "Phew! That was a close one!"
};


    while(N--) {
        if(cnt) cout << '\n';
        ++cnt;
        cout << "Game #" << cnt <<  ":" << '\n';
        string word; cin >> word;
        vector<string> words(6);
        for(int i = 0; i < 6; ++i) cin >> words[i];
        bool found = false;
        int numfound = 0;
        for(int i = 0; i < 6; ++i) {    
            if(found) {
                cout << "WWWWW" << '\n';
            } else {
                vector<int> cc(26);
                for(auto ccc : word)
                    cc[ccc - 'A']++;

                string output = "     ";
                for(int j = 0; j < 5; ++j) {
                    if(words[i][j] == word[j]) {
                        cc[word[j] - 'A']--;
                        output[j] = 'G';
                    }
                }
                
                for(int j = 0; j < 5; ++j) {
                    if(words[i][j] != word[j]) {
                        if(cc[words[i][j]- 'A']) {
                            cc[words[i][j] - 'A']--;
                            output[j] = 'Y';
                        } else 
                            output[j] = 'X';
                    }
                }
                cout << output << '\n';
                if(output == "GGGGG") {
                    found = true;
                    numfound = i+1;
                }
            }
        }   
        if(numfound == 0) cout << word << " was not correctly guessed. Better luck next time." << '\n';
        else
        cout << word << " was correctly guessed in "<< numfound << " guesses. " << reps[numfound] << '\n';

    }
    return 0;
}
