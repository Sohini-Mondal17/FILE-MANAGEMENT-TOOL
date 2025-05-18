#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "example.txt";
    string data;

    int choice;
    do {
        cout << "\n--- File Operations Menu ---\n";
        cout << "1. Write to File (Overwrite)\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline after choice input

        switch (choice) {
            case 1: {
                ofstream outfile(filename); // Overwrite mode
                if (!outfile) {
                    cerr << "Error opening file for writing!\n";
                    break;
                }
                cout << "Enter data to write: ";
                getline(cin, data);
                outfile << data << endl;
                outfile.close();
                cout << "Data written to file successfully.\n";
                break;
            }

            case 2: {
                ofstream outfile(filename, ios::app); // Append mode
                if (!outfile) {
                    cerr << "Error opening file for appending!\n";
                    break;
                }
                cout << "Enter data to append: ";
                getline(cin, data);
                outfile << data << endl;
                outfile.close();
                cout << "Data appended to file successfully.\n";
                break;
            }

            case 3: {
                ifstream infile(filename);
                if (!infile) {
                    cerr << "Error opening file for reading!\n";
                    break;
                }
                cout << "--- File Contents ---\n";
                while (getline(infile, data)) {
                    cout << data << endl;
                }
                infile.close();
                break;
            }

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}


