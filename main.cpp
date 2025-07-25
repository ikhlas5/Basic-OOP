#include <iostream>
using namespace std;

class Exception {
    protected:
        string message;

    public:
        Exception(string message) {
            this->message = message;
        }

        void setMessage(string message) {
            this->message = message;
        }

        string getMessage() {
            return this->message;
        }

};

class EightCharacterException : public Exception {
    public:
        EightCharacterException() : Exception("Must contain 8 characters!!!") {

        }
};

class SmallLetterException : public Exception {
    public:
    SmallLetterException() : Exception("Must contain a small letter!!!") {

    }
};

class CapitalLetterException : public Exception {
public:
    CapitalLetterException() : Exception("Must contain a capital letter!!!") {

    }
};

class DigitException : public Exception {
public:
    DigitException() : Exception("Must contain a digit!!!") {

    }
};

class SpecialCharacterException : public Exception {
public:
    SpecialCharacterException() : Exception("Must contain a special character!!!") {

    }
};

class SpaceException : public Exception {
public:
    SpaceException() : Exception("Must not contain a space character!!!") {

    }
};

bool passwordLetterChecker(string password, char lowerLimit, char upperLimit) {
    bool contains = false;
    if(password.length() > 0) {
        for(int i = 0; i < password.length() && !contains; i++) {
            if(password[i] >= lowerLimit && password[i] <= upperLimit) {
                contains = true;
            }
        }
    }

    return contains;
}

bool passwordSpecialCharChecker(string password) {
    bool contains = false;
    if(password.length() > 0) {
        for(int i = 0; i < password.length() && !contains; i++) {
            char letter = password[i];
            if(!(letter >= 'A' && letter <= 'Z') &&
                !(letter >= 'a' && letter <= 'z') &&
                !(letter >= '0' && letter <= '9') &&
                !(letter == ' ')){
                contains = true;
                }
        }
    }

    return contains;
}

int main() {
    bool verified = false;

    do {
        verified = true;
        string password;
        cout << "Enter a password for registration: " << endl;
        getline(cin, password);

        try {
            if(password.length() < 8) {
                throw EightCharacterException();
            }

        }
        catch (EightCharacterException e) {
            verified = false;
            cout << e.getMessage() << endl;
        }

        try {
            if(!passwordLetterChecker(password, 'A', 'Z')) {
                throw CapitalLetterException();
            }
        }
        catch (CapitalLetterException e) {
            verified = false;
            cout << e.getMessage() << endl;
        }

        try {
            if(!passwordLetterChecker(password, 'a', 'z')) {
                throw SmallLetterException();
            }
        }
        catch (SmallLetterException e) {
            verified = false;
            cout << e.getMessage() << endl;
        }

        try {
            if(!passwordLetterChecker(password, '0', '9')) {
                verified = false;
                throw DigitException();
            }
        }
        catch (DigitException e) {
            verified = false;
            cout << e.getMessage() << endl;
        }

        try {
            if(passwordLetterChecker(password, ' ', ' ')) {
                throw SpaceException();
            }
        }
        catch (SpaceException e) {
            verified = false;
            cout << e.getMessage() << endl;
        }

        try {
            if(!passwordSpecialCharChecker(password)) {
                throw SpecialCharacterException();
            }
        }
        catch (SpecialCharacterException e) {
            verified = false;
            cout << e.getMessage() << endl;
        }

        if(!verified) {
            cout << "Password pattern is wrong. Please try again!" << endl << endl;
        }

    }while(!verified);

    cout << "Successfully completed registration" <<endl;
    return 0;
}