
#include <iostream>
#include "Calc=.h"
using namespace std;

int main() {
    int sentinal = 0;
    do {
        cout << "Please enter the number of expressions you would like to store: " << endl;
        int values;
        cin >> values;
        if (values < 1) {
            cout << "Error: Number of stored expressions must be positive" << endl;
        } else {
            Calc calc1 = Calc(values);
            for(size_t count = 0; count < values; count++){
                double answer = 0;
                bool flag = true;
                while(flag){
                    string userString;
                    cout << " Please enter your expression (Enter 'STOP' to halt this input stream): \n" << " = " << answer
                              << " + ... " << endl;
                    cin >> userString;
                    if (userString == "STOP") {
                        calc1.storedExpressions[calc1.getStored()] =to_string(answer);
                        flag = false;
                        break;
                    }
                    cout << userString << "= " << calc1.process(userString, answer);
                    answer = calc1.process(userString, answer);
                }
                calc1.setStored(calc1.getStored() + 1);
            }
            calc1.print();
            cout << "Press 1 to continue with another calculator, any other value to quit" << `endl;
           cin >> sentinal;
        }
    }while(sentinal == 1);
    return 0;
}
