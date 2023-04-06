#include <iostream>
#include <string>
using namespace std;

void intro();
int getNoOfStudent();
int setFee();
string getMonth();
void displayMonth(string);
void displayMonthFee(string, int[], int);
double calcTotalFee(int[], int);
double feeActivity(double);

int main() {
    int numStudent, totalStudent, i, totalFee;
    double totalMonthFee = 0.0;
    string month;

    intro();

    month = getMonth();
    displayMonth(month);

    totalStudent = getNoOfStudent();
    int fee[totalStudent];

    for (i = 0; i < totalStudent; i++) {
        fee[i] = setFee();
    }

    displayMonthFee(month, fee, totalStudent);

    totalFee = calcTotalFee(fee, totalStudent);
    feeActivity(totalFee);

    return 0;
}

void intro() {
    cout << "\n\n\n\n";
    cout << "\n ---SWC PROJECT---\n\n\n\n";
    cout << "\n\n Leader : ABDUL MUHAIMIE AR BAAIN BIN MASORROWEE AWAE";
    cout << "\n\n NO ID : AM2111010416";
    cout << "\n\n Member 1 : MUHAMMAD HAIKAL BIN MUSTHAFFA";
    cout << "\n\n NO ID : AM2111010456";
    cout << "\n\n Member 2 : MUHAMMAD ALIF SERBAINI";
    cout << "\n\n NO ID : AM2111010447";
    cout << "\n\n Section : 1";
    cout << "\n\n Lecturer : WAN ASIAH BT WAN MUHAMMAD TAHIR";
}

int getNoOfStudent() {
    int totalStudent;
    cout << "\nEnter number of students that are registered: ";
    cin >> totalStudent;

    if (totalStudent < 20) {
        cout << "\nNumber of students registered is invalid";
        totalStudent = getNoOfStudent();
    }
    return totalStudent;
}

string getMonth() {
    int userMonth;
    string monthName[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    cout << "\n----------------------------------";
    cout << "\nPLEASE ENTER MONTH TO REGISTER: ";
    cin >> userMonth;

    while (userMonth < 1 || userMonth > 12) {
        cout << "Invalid month. Please enter a value between 1 and 12: ";
        cin >> userMonth;
    }

    return monthName[userMonth - 1];
}

int setFee() {
    int code;
    double fee;

    cout << "\nENTER CODE FOR STUDENT: ";
    cin >> code;

    switch (code) {
        case 1:
            cout << "1. Java Programming\n";
            fee = 200;
            break;
        case 2:
            cout << "2. Microsoft Office\n";
            fee = 150;
            break;
        case 3:
            cout << "3. AutoCad\n";
            fee = 100;
            break;
        default:
            fee = -1;
            cout << "Wrong code\n";
            break;
    }

    return fee;
}

void displayMonth(string month) {
    cout << "MONTH THAT IS REGISTERED: " << month << endl;
    cout << "---------------------------------------" << endl;
}

double calcTotalFee(int fee[], int totalStudent, int totalMonthFee) {
    for (int i = 0; i < totalStudent; i++) {
        totalMonthFee = totalMonthFee + fee[i];
    }
    cout << "\n\nThe Total fee is : RM" << totalMonthFee;
    cout << "\n";
    return totalMonthFee;
}

void displayMonthFee(string month, int fee[], int totalStudent, int totalMonthFee) {
    for (int i = 0; i < totalStudent; i++) {
        cout << "The fee for " << month << " is RM" << fee[i] << endl;
    }
    cout << "\n\nThe Total fee is : RM" << totalMonthFee;
    cout << "\n";
}

double feeActivity(int totalFee) {
    if (totalFee > 2500) {
        double activityFee = totalFee * 0.1;
        cout << "\nThe amount allocated for staff activity is RM " << activityFee << endl;
        return activityFee;
    }
    else {
        cout << "\nThere is no activity fee allocated for staff" << endl;
        return 0;
    }
}

// fix the error in this function