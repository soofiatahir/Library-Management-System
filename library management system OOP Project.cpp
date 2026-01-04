#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Author {
public:
    bool login() {
        string user, password;
        cout << "--- Login ---\n";
        cout << "Username: "; cin >> user;

        if (user =="admin" ) {
           cout << "Enter password:";
           cin>>password;
		    cout << "Login Successful!\n";
            return true;
        }
        cout << "Invalid Credentials!\n";
        return false;
    }
};
class Library {
public:
    void addBook() {
        int id;
        string title;
        cout << "Enter Book ID: ";
	    cin >> id;
        cin.ignore();
        cout << "Enter Title: "; 
		getline(cin, title);

        ofstream outFile("library.txt", ios::app);
        outFile << id << " " << title << endl;
        outFile.close();
        cout << "Book added to catalog.\n";
    } 
    void issueBook() {
        string studentName, bookTitle;
        cout << "Enter Student Name: "; 
		cin.ignore(); 
		getline(cin, studentName);
        cout << "Enter Book Title: ";
		getline(cin, bookTitle);

        ofstream outFile("issued.txt", ios::app);
        outFile << "Student: " << studentName << " | Book: " << bookTitle << endl;
        outFile.close();
        cout << "Issue record saved.\n";
    }
    void viewRecords(string fileName, string header) {
        ifstream inFile(fileName);
        string line;
        cout << "\n--- " << header << " ---\n";
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "No records found.\n";
        }
    }
};
int main() {
    Author systemAuth;
    Library lib;
    
    if (systemAuth.login()) {
        int  choice;
        while (true) {
            cout << "\n1. Add New Book\n2. Issue a Book\n3. View Catalog\n4. View Issued Books\n5. Exit\nChoice: ";
            cin >> choice;

            switch(choice) {
                case 1: lib.addBook(); break;
                case 2: lib.issueBook(); break;
                case 3: lib.viewRecords("library.txt", "Book Catalog"); break;
                case 4: lib.viewRecords("issued.txt", "Issued Books Record"); break;
                case 5: return 0;
                default: cout << "Invalid choice!\n";
            }
        }
    }
    return 0;
}
