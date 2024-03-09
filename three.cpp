
 /*
 * Implementation: ( keep tracking of the head and tail of each version )
     we can say , non - eraseble  queue 
      1. whenever we enqueue the value( push) , tail gone increase and head remain the same as the head of pervious version
        increase the current version 
      
      2. whenever the dequeue operation held , we can increment the head part , and do nothing with the tail part, 
      remain same as the tail of the previous part , 
        , increase the current version , 

 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int inputNumber[n + 1];
    int versionHead[n + 1];
    int versionTail[n + 1];

    int currentNumIndex = 1;
    int currentVersionIndex = 1;


   // inititalize the whole arr buffer
    for (int i = 0; i < n + 1; i++) {
        inputNumber[i] = 0;
        versionHead[i] = 0;
        versionTail[i] = 0;
    }

    versionHead[0] = 1;
    versionTail[0] = 0;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'e') { // the enqueue function  //
            cin >> inputNumber[currentNumIndex];
            currentNumIndex++;

            versionHead[currentVersionIndex] = versionHead[currentVersionIndex - 1];
            versionTail[currentVersionIndex] = versionTail[currentVersionIndex - 1] + 1;
            currentVersionIndex++;
        } else if (c == 'd') { // the dequeue finction //
            if (versionTail[currentVersionIndex] < versionHead[currentVersionIndex]) {
                // Queue is empty
                versionHead[currentVersionIndex] = versionHead[currentVersionIndex - 1];
                versionTail[currentVersionIndex] = versionTail[currentVersionIndex - 1];
                currentVersionIndex++;
            } else {
                versionHead[currentVersionIndex] = versionHead[currentVersionIndex - 1] + 1;
                versionTail[currentVersionIndex] = versionTail[currentVersionIndex - 1];
                currentVersionIndex++;
            }
        } else if (c == 'p') { // the print function //
            int versionToPrint;
            cin >> versionToPrint;

            cout << "printing current version  " << versionToPrint << ": ";
            for (int j = versionHead[versionToPrint]; j <= versionTail[versionToPrint]; j++) {
                cout << inputNumber[j] << " ";
            }
            cout << endl;
        }
    }
   
    // if the version is not here, simple return with "0", output  //

    return 0;
}
