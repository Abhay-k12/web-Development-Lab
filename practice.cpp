#include <iostream>
#include <string>
using namespace std;

string onesComplement(string msg) {
    for(int i=0; i<msg.length(); i++) {
        if(msg[i]=='0')
            msg[i] = '1';
        else
            msg[i] = '0';
    }

    return msg;
}

string checksum(string msg, int blocksize) {
    int n = msg.length();
    string padding = "";

    for(int i=0; i<blocksize - (n%blocksize); i++) {
        padding += "0";
    }

    msg = padding + msg;
    string currBlock = msg.substr(0, blocksize);
    int sum = 0, carry = 0;

    for(int i=blocksize; i<n; i+=blocksize) {
        string nextBlock = msg.substr(i, blocksize);

        string result = "";
        for(int j=blocksize-1; j>=0; j--) {
            sum = (currBlock[j]-'0') + (nextBlock[j]-'0') + carry;
            carry = sum/2;

            if(sum==0 || sum==2) result = "0" + result;
            if(sum==1 || sum==3) result = "1" + result;
        }

        if(carry!=1) {
            currBlock = result;
        }
        else {
            string newResult = "";
            for(int j=blocksize-1; j>=0; j--) {
                sum = (result[j]-'0') + carry;
                carry = sum/2;

                if(sum==0) {
                    newResult = "0" + newResult;
                }
                else if(sum==1) {
                    newResult = "1" + newResult;
                }
                else {
                    newResult = "0" + newResult;
                }
            }

            currBlock = newResult;
        }
    }

    return onesComplement(currBlock);
}


bool checkError(string senderMsg, string receiverMsg, int blocksize) {
    string senderCheckSum = checksum(senderMsg, blocksize);
    cout<<"Sender Message: "<<senderMsg<<endl;
    cout<<"Sender CheckSum: "<<senderCheckSum<<endl;

    string receiverCheckSum = checksum(receiverMsg+senderCheckSum, blocksize);
    cout<<"\n\n";
    cout<<"Receiver Message: "<<receiverMsg<<endl;
    cout<<"Receiver CheckSum: "<<receiverCheckSum<<endl;

    return receiverCheckSum.find('1') == string::npos;
}

int main() {
    string sent_message;
    string recv_message;
    int block_size;

    cout<<"Enter the Sent Meassage: ";
    getline(cin,sent_message);

    cout<<"Enter the Received Message: ";
    getline(cin, recv_message);

    cout<<"Enter the Block Size: ";
    cin>>block_size;

    if (checkError(sent_message, recv_message, block_size)) {
        cout << "RESULT: No Error Detected"<<endl;
    }
    else {
        cout << "Error Detected"<<endl;
    }

    cout<<endl;
    return 0; 
}
