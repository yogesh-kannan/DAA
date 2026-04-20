#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char text[100], pat[50];
    int shift[256], n, m, i, j, k;
    cout<<"Enter text: ";
    cin>>text;
    cout<<"Enter pattern: ";
    cin>>pat;
    n = strlen(text);
    m = strlen(pat);
    for(i=0;i<256;i++)
        shift[i]=m;
    for(i=0;i<m-1;i++)
        shift[pat[i]] = m-1-i;
    i = m-1;
    while(i < n) {
        k = 0;
        while(k < m && pat[m-1-k] == text[i-k]) {
            k++;
        }
        if(k == m) {
            cout<<"Pattern found at position "<<i-m+1<<endl;
            return 0;
        }
        else i += shift[text[i]];
    }
    cout<<"Pattern not found"<<endl;
}
