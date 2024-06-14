#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    string roll;
    string Name;
    string Dept;
    float CGPA;
    Node* next;

    // Constructor
    Node(string roll, string Name, string Dept, float CGPA) {
        this->roll = roll;
        this->Name = Name;
        this->Dept = Dept;
        this->CGPA = CGPA;
        this->next = nullptr;
    }
};

// Global Variable to store the head of the Linked List
Node* head = nullptr;

// Function to insert a record
void Insert_Record(string roll, string Name, string Dept, float CGPA) {
    Node* newNode = new Node(roll, Name, Dept, CGPA);
    if (head == nullptr || head->roll >= roll) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->roll < roll) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    cout << "Record Inserted Successfully\n";
}

// Function to search for a record by roll number
void Search_Record(string roll) {
    Node* current = head;
    while (current != nullptr) {
        if (current->roll == roll) {
            cout << "Roll Number\t" << current->roll << endl;
            cout << "Name\t\t" << current->Name << endl;
            cout << "Department\t" << current->Dept << endl;
            cout << "CGPA\t\t" << fixed << setprecision(2) << current->CGPA << endl;
            return;
        }
        current = current->next;
    }
    cout << "No record found for Roll Number: " << roll << endl;
}

// Function to delete a record by roll number
void Delete_Record(string roll) {
    if (head == nullptr) {
        cout << "No records to delete\n";
        return;
    }
    if (head->roll == roll) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Record Deleted Successfully\n";
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->roll != roll) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Record Deleted Successfully\n";
    } else {
        cout << "No record found for Roll Number: " << roll << endl;
    }
}

// Function to display all records
void Show_Record() {
    if (head == nullptr) {
        cout << "No records available\n";
    } else {
        cout << "Roll\tName\tDepartment\tCGPA\n";
        Node* current = head;
        while (current != nullptr) {
            cout << current->roll << "\t" << current->Name << "\t" << current->Dept << "\t\t" << fixed << setprecision(2) << current->CGPA << endl;
            current = current->next;
        }
    }
}

// Function to count total records
int Count_Records() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to find and display the record with maximum CGPA
void Find_Max_CGPA() {
    if (head == nullptr) {
        cout << "No records available\n";
        return;
    }
    Node* maxNode = head;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->CGPA > maxNode->CGPA) {
            maxNode = current;
        }
        current = current->next;
    }
    cout << "Student with maximum CGPA:\n";
    cout << "Roll Number\t" << maxNode->roll << endl;
    cout << "Name\t\t" << maxNode->Name << endl;
    cout << "Department\t" << maxNode->Dept << endl;
    cout << "CGPA\t\t" << fixed << setprecision(2) << maxNode->CGPA << endl;
}

// Function to find and display the record with minimum CGPA
void Find_Min_CGPA() {
    if (head == nullptr) {
        cout << "No records available\n";
        return;
    }
    Node* minNode = head;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->CGPA < minNode->CGPA) {
            minNode = current;
        }
        current = current->next;
    }
    cout << "Student with minimum CGPA:\n";
    cout << "Roll Number\t" << minNode->roll << endl;
    cout << "Name\t\t" << minNode->Name << endl;
    cout << "Department\t" << minNode->Dept << endl;
    cout << "CGPA\t\t" << fixed << setprecision(2) << minNode->CGPA << endl;
}

// Function to update record details
void Update_Record(string roll) {
    Node* current = head;
    while (current != nullptr) {
        if (current->roll == roll) {
            cout << "Enter New Name of Student\n";
            cin >> current->Name;
            cout << "Enter New Department of Student \n";
            cin >> current->Dept;
            cout << "Enter New CGPA of Student\n";
            cin >> current->CGPA;
            cout << "Record Updated Successfully\n";
            return;
        }
        current = current->next;
    }
    cout << "No record found for Roll Number: " << roll << endl;
}

// Function to calculate average CGPA of all students
float Average_CGPA() {
    float sum = 0;
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->CGPA;
        count++;
        current = current->next;
    }
    if (count == 0) {
        cout << "No records available\n";
        return 0;
    }
    return sum / count;
}

// Function to search for a record by name
void Search_By_Name(string name) {
    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->Name == name) {
            cout << "Record found:\n";
            cout << "Roll Number\t" << current->roll << endl;
            cout << "Name\t\t" << current->Name << endl;
            cout << "Department\t" << current->Dept << endl;
            cout << "CGPA\t\t" << fixed << setprecision(2) << current->CGPA << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "No record found for Name: " << name << endl;
    }
}

// Driver code
int main() {
    string Name, Dept, roll;
    float CGPA;

    // Menu-driven program
    while (true) {
        cout << "\n\t\tWelcome to Student Management System\n\n\tPress\n\t1 to create a new Record\n\t2 to delete a student record\n\t3 to Search a Student Record\n\t4 to view all students record\n\t5 to Count total records\n\t6 to Find student with maximum CGPA\n\t7 to Find student with minimum CGPA\n\t8 to Update record details\n\t9 to Calculate average CGPA\n\t10 to Search student by name\n\t11 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;

        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Student\n";
            cin >> Name;
            cout << "Enter Roll Number of Student\n";
            cin >> roll;
            cout << "Enter Department of Student \n";
            cin >> Dept;
            cout << "Enter CGPA of Student\n";
            cin >> CGPA;
            Insert_Record(roll, Name, Dept, CGPA);
        } else if (Choice == 2) {
            cout << "Enter Roll Number of Student whose record is to be deleted\n";
            cin >> roll;
            Delete_Record(roll);
        } else if (Choice == 3) {
            cout << "Enter Roll Number of Student whose record you want to Search\n";
            cin >> roll;
            Search_Record(roll);
        } else if (Choice == 4) {
            Show_Record();
        } else if (Choice == 5) {
            cout << "Total Records: " << Count_Records() << endl;
        } else if (Choice == 6) {
            Find_Max_CGPA();
        } else if (Choice == 7) {
            Find_Min_CGPA();
        } else if (Choice == 8) {
            cout << "Enter Roll Number of Student to update details\n";
            cin >> roll;
            Update_Record(roll);
        } else if (Choice == 9) {
            cout << "Average CGPA: " << fixed << setprecision(2) << Average_CGPA() << endl;
        } else if (Choice == 10) {
            cout << "Enter Name of Student to search\n";
            cin >> Name;
            Search_By_Name(Name);
        } else if (Choice == 11) {
            exit(0);
        } else {
            cout << "Invalid Choice. Try Again\n";
        }
    }
    return 0;
}
//
/*In the provided code, several concepts from Data Structures and Algorithms (DSA) are used:

Linked List: The student records are stored using a linked list data structure. Each student record is represented as a node in the linked list.

Insertion: The Insert_Record function inserts a new student record into the linked list in sorted order based on the roll number.

Search: The Search_Record function searches for a student record based on the roll number.

Deletion: The Delete_Record function deletes a student record from the linked list based on the roll number.

Traversal: Traversal of the linked list is done in various functions such as Show_Record, Count_Records, Find_Max_CGPA, Find_Min_CGPA, Average_CGPA, and Search_By_Name.

Update: The Update_Record function updates the details of a student record based on the roll number.*/