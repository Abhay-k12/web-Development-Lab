#include <iostream>
#include <vector>
using namespace std;

int calculateParityBits(int m) {
    int bits = 0;
    while((1<<bits) < (m+bits+1)) bits += 1;
    return bits;
}

bool isPowerOf2(int num) {
    return (num & (num-1))==0;
}

int main() {
    int m;
    cout<<"Enter the number of bits in data: ";
    cin>>m;

    vector<int> data(m);
    cout<<"Enter the data: ";
    for(int i=0; i<m; i++) cin>>data[i];

    int parityBits = calculateParityBits(m);
    int totalBits = parityBits + m;

    vector<int> hammingCode(totalBits+1);
    int index = 0;
    for(int i=1; i<=totalBits; i++) {
        if(isPowerOf2(i)) hammingCode[i] = 0;
        else hammingCode[i] = data[index++];
    }

    for(int i=0; i<parityBits; i++) {
        int pos = (1<<i);
        int parity = 0;

        for(int k=pos; k<=totalBits; k++) {
            if(k&pos) parity ^= hammingCode[k];
        }

        hammingCode[pos] = parity;
    }

    cout<<"\tHamming Code for input data: ";
    for(int i=1; i<=totalBits; i++) cout<<hammingCode[i]<<" ";
    cout<<endl;

    int choice = 0;
    cout<<"----Enter 1:Bit Flip or 2:No Flip :";
    cin>>choice;

    if(choice==1) {
        int pos = 0;
        cout<<"Enter the position to be flipped: ";
        cin>>pos;

        if(pos>=1 && pos<=totalBits) hammingCode[pos] ^= 1;
    }

    cout<<"\tReceived Code: ";
    for(int i=1; i<=totalBits; i++) cout<<hammingCode[i]<<" ";
    cout<<endl;

    int errorPosition = 0;
    for(int i=0; i<parityBits; i++) {
        int pos = (1<<i);
        int parity = 0;

        for(int k=pos; k<=totalBits; k++) {
            if(k&pos) parity ^= hammingCode[k];
        }

        if(parity) errorPosition += pos;
    }

    if(errorPosition==0) {
        cout<<"\tNo Error Detected"<<endl;
    }
    else {
        cout<<"\tError: Detected at position "<<errorPosition<<endl;
        hammingCode[errorPosition] ^= 1;
        cout<<"\tCorrected Code: ";
        for(int i=1; i<=totalBits; i++) cout<<hammingCode[i]<<" ";
        cout<<endl;
    }

    vector<int> originalData;
    for(int i=1; i<=totalBits; i++) {
        if(!isPowerOf2(i)) originalData.push_back(hammingCode[i]);
    }

    cout<<"\nOriginal Data: ";
    for(int i=0; i<m; i++) cout<<originalData[i];
    cout<<endl;
    return 0;
}