#include<iostream>

using namespace std;

template<class T>
T gen_func(T *elementArray, int length) {
    T smallest = elementArray[0];
    T secondSmallest = elementArray[0];

    //Only for print
    cout << "Array: [";

    for (int i = 0; i < length; i++) {
        T element = *(elementArray + i);

        //This if-else Only for print
        if (i != length-1) {
            cout << element << ", ";
        }
        else {
            cout << element << "]" << endl;
        }


        if (element < secondSmallest) {
            if (element < smallest) {
                smallest = element;
            }
            else {
                secondSmallest = element;
            }
        }
        else {
            if (secondSmallest == smallest) {
                secondSmallest = element;
            }
        }
    }

    //Optional
    cout << "Second Smallest: ";
    return secondSmallest;
}

int main() {
    int intArray[5] = {5, 3, -7, 4, 2};
    char charArray[5] = {'Z', 'x', 'j', 'f', 'e'};
    string stringArray[5] = {"Abir", "Bristy", "Anoy", "Mimi", "Subir"};

    cout << gen_func(intArray, 5) << endl << endl;
    cout << gen_func(charArray, 5) << endl << endl;
    cout << gen_func(stringArray, 5) << endl << endl;
    return 0;
}
