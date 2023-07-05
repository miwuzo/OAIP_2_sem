#include <iostream>
#include <string>

using namespace std;

enum Specialty {
    COMPUTER_SCIENCE,
    ELECTRICAL_ENGINEERING,
    MECHANICAL_ENGINEERING,
    CHEMICAL_ENGINEERING,
    CIVIL_ENGINEERING
};

struct Competition {
    unsigned int computer_science : 1;
    unsigned int electrical_engineering : 1;
    unsigned int mechanical_engineering : 1;
    unsigned int chemical_engineering : 1;
    unsigned int civil_engineering : 1;
};

struct University {
    string name;
    string address;
    Competition competition;
    float payment;
    Specialty specialties[5];
};

const int MAX_UNIVERSITIES = 100;

int numUniversities = 0;
University universities[MAX_UNIVERSITIES];

void addUniversity() {
    if (numUniversities < MAX_UNIVERSITIES) {
        University u;

        cout << "Enter name of university: ";
        getline(cin, u.name);

        cout << "Enter address of university: ";
        getline(cin, u.address);

        for (int i = 0; i < 5; i++) {
            cout << "Enter specialty " << i + 1 << " (0 for end): ";
            int s;
            cin >> s;
            cin.ignore();

            if (s == 0) {
                break;
            }

            u.specialties[i] = static_cast<Specialty>(s - 1);
        }

        cout << "Enter competition for last year's specialties (0 or 1): " << endl;
        cout << "Computer science: ";


        string competitionStr;
        getline(cin, competitionStr);
        u.competition.computer_science = stoi(competitionStr);

        cout << "Electrical engineering: ";

        string competitioStr;
        getline(cin, competitioStr);
        u.competition.electrical_engineering = stoi(competitioStr);

        cout << "Mechanical engineering: ";
        
        string competitiStr;
        getline(cin, competitiStr);
        u.competition.mechanical_engineering = stoi(competitiStr);

        cout << "Chemical engineering: ";
        string competitStr;
        getline(cin, competitStr);
        u.competition.chemical_engineering = stoi(competitStr);

        cout << "Civil engineering: ";
        string competiStr;
        getline(cin, competiStr);
        u.competition.civil_engineering = stoi(competiStr);

        cout << "Enter payment for contract education: ";
        cin >> u.payment;

        universities[numUniversities++] = u;
        cout << "University added successfully!" << endl;
    }
    else {
        cout << "Maximum number of universities reached!" << endl;
    }
}

void displayUniversity(University u) {
    cout << "Name: " << u.name << endl;
    cout << "Address: " << u.address << endl;
    cout << "Specialties: ";

    for (int i = 0; i < 5; i++) {
        if (u.specialties[i] != static_cast<Specialty>(-1)) {
            cout << u.specialties[i] << ", ";
        }
    }

    cout << endl;
    cout << "Competition: " << endl;
    cout << "Computer science: " << u.competition.computer_science << endl;
    cout << "Electrical engineering: " << u.competition.electrical_engineering << endl;
    cout << "Mechanical engineering: " << u.competition.mechanical_engineering << endl;
    cout << "Chemical engineering: " << u.competition.chemical_engineering << endl;
    cout << "Civil engineering: " << u.competition.civil_engineering << endl;
    cout << "Payment for contract education: " << u.payment << endl;
}

void displayUniversities() {
    for (int i = 0; i < numUniversities; i++) {
        displayUniversity(universities[i]);
    }
}

void deleteUniversity() {
    cout << "Enter name of university to delete: ";
    string name;
    getline(cin, name);
    for (int i = 0; i < numUniversities; i++) {
        if (universities[i].name == name) {
            for (int j = i; j < numUniversities - 1; j++) {
                universities[j] = universities[j + 1];
            }

            numUniversities--;
            cout << "University deleted successfully!" << endl;
            return;
        }
    }

    cout << "University not found!" << endl;
}
void searchUniversityBySpecialty() {
    cout << "Enter specialty to search for (0 - computer science, 1 - electrical engineering, 2 - mechanical engineering, 3 - chemical engineering, 4 - civil engineering): ";
    int s;
    cin >> s;
    cin.ignore();
    Specialty specialty = static_cast<Specialty>(s);

    int count = 0;

    for (int i = 0; i < numUniversities; i++) {
        for (int j = 0; j < 5; j++) {
            if (universities[i].specialties[j] == specialty) {
                displayUniversity(universities[i]);
                count++;
                break;
            }
        }
    }

    if (count == 0) {
        cout << "No universities found for this specialty!" << endl;
    }
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add university" << endl;
    cout << "2. Display universities" << endl;
    cout << "3. Delete university" << endl;
    cout << "4. Search university by specialty" << endl;
    cout << "5. Exit" << endl;
}
int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:

            addUniversity();
            break;
        case 2:
            displayUniversities();
            break;

        case 3:
            deleteUniversity();
            break;

        case 4:
            searchUniversityBySpecialty();
            break;

        case 5:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}