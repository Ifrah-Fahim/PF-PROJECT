#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Constants for maximum lanes and array size
const int MAX_LANES = 4;
const int MAX_SIZE = 100;
const string USERNAME = "project";
const string PASSWORD = "012345";

struct Lane {
    string name;
    int vehicleCount;
    int signalTime;
};

int a[MAX_SIZE];
int i = 0; // Index for array operations

// Array operations
void add(int a[]) {
    if (i < MAX_SIZE) {
        cout << "Enter the number you want to add: ";
        cin >> a[i];
        i++;
        cout << "Added successfully.\n";
    } else {
        cout << "Array is full. Cannot add more numbers.\n";
    }
}

void search(int a[]) {
    int n;
    cout << "Enter the number you want to search: ";
    cin >> n;
    bool found = false;
    for (int j = 0; j < i; j++) {
        if (a[j] == n) {
            cout << "Your search value is: " << a[j] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Number not found in the array.\n";
    }
}

void update(int a[]) {
    int n, newValue;
    cout << "Enter the number you want to update: ";
    cin >> n;
    bool found = false;
    for (int j = 0; j < i; j++) {
        if (a[j] == n) {
            cout << "Enter the new value: ";
            cin >> newValue;
            a[j] = newValue;
            cout << "Updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Number not found in the array.\n";
    }
}

void show(int a[]) {
    cout << "Array contents: ";
    for (int j = 0; j < i; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
}

void del(int a[]) {
    int n;
    cout << "Enter the number you want to delete: ";
    cin >> n;
    bool found = false;
    for (int j = 0; j < i; j++) {
        if (a[j] == n) {
            found = true;
            for (int k = j; k < i - 1; k++) {
                a[k] = a[k + 1];
            }
            i--;
            cout << "Deleted successfully.\n";
            break;
        }
    }
    if (!found) {
        cout << "Number not found in the array.\n";
    }
}

// Traffic signal logic
void collectTrafficData(Lane lanes[], int numLanes) {
    for (int i = 0; i < numLanes; ++i) {
        cout << "\nEnter vehicle count for " << lanes[i].name << " lane: ";
        cin >> lanes[i].vehicleCount;
    }
}

void calculateSignalTimings(Lane lanes[], int numLanes) {
    int totalVehicles = 0;
    for (int i = 0; i < numLanes; ++i) {
        totalVehicles += lanes[i].vehicleCount;
    }
    for (int i = 0; i < numLanes; ++i) {
        if (totalVehicles > 0) {
            lanes[i].signalTime = (lanes[i].vehicleCount * 60) / totalVehicles;
        } else {
            lanes[i].signalTime = 15;
        }
    }
}

void displaySignalTimings(Lane lanes[], int numLanes) {
    cout << "\nTraffic Signal Timings:\n";
    for (int i = 0; i < numLanes; ++i) {
        cout << lanes[i].name << " lane: "
             << "Vehicles: " << lanes[i].vehicleCount
             << ", Signal Time: " << lanes[i].signalTime << " seconds\n";
    }
}

// Traffic light duration functions
string Lightnames[] = {"Red", "Green", "Yellow"};
int LightDuration[] = {2, 5, 2};
const int numlights = 3;

void viewDurations() {
    cout << "\nCurrent Traffic Light Durations:\n";
    for (int i = 0; i < numlights; i++) {
        cout << Lightnames[i] << ": " << LightDuration[i] << " seconds\n";
    }
}

void updateDuration() {
    string light;
    int newDuration;
    cout << "\nEnter the light to update (Red, Green, Yellow): ";
    cin >> light;
    bool found = false;
    for (int i = 0; i < numlights; i++) {
        if (Lightnames[i] == light) {
            cout << "Enter the new duration (in seconds): ";
            cin >> newDuration;
            LightDuration[i] = newDuration;
            cout << light << " duration updated to " << newDuration << " seconds.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Error: " << light << " not found.\n";
    }
}

void deleteDuration() {
    string light;
    cout << "\nEnter the light to delete (Red, Green, Yellow): ";
    cin >> light;
    bool found = false;
    for (int i = 0; i < numlights; i++) {
        if (Lightnames[i] == light) {
            LightDuration[i] = -1; // Mark the duration as deleted
            cout << light << " duration deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Error: " << light << " not found.\n";
    }
}

void simulateTraffic() {
    string directions[] = {"North-South", "East-West"};
    int currentDirection = 0;
    int currentState = 0;
    char stopSignal;
    cout << "\nStarting Traffic Simulation...\n";
    while (true) {
        cout << directions[currentDirection] << " direction: ";
        cout << Lightnames[currentState] << " - ";
        cout << ((currentState == 0) ? "Stop!" : (currentState == 1) ? "Go!" : "Prepare to stop!") << endl;

        for (int i = LightDuration[currentState]; i > 0; i--) {
            cout << "[" << Lightnames[currentState] << " Timer: " << i << " seconds]\n";
            Sleep(1000); // Wait for 1 second
        }

        currentState = (currentState + 1) % numlights;
        if (currentState == 0) {
            currentDirection = 1 - currentDirection;
        }

        cout << "Press 'q' to quit or any other key to continue: ";
        cin >> stopSignal;
        if (stopSignal == 'q' || stopSignal == 'Q') {
            cout << "Stopping Traffic Simulation...\n";
            break;
        }
        cout << endl;
    }
}
// Login function
bool login() {
    string inputUsername, inputPassword;
    cout << "Enter username: ";
    cin >> inputUsername;
    cout << "Enter password: ";
    cin >> inputPassword;
    if (inputUsername == USERNAME && inputPassword == PASSWORD) {
        cout << "Login successful!\n";
        return true;
    } else {
    	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    	 SetConsoleTextAttribute(h, 9);
        cout << "Invalid username or password.\n";
        return false;
    }
}

// Main function
int main() {
	 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    
    if (!login()) {
        return 0;
    }
    
     system("cls");//clear the [page go to next page   
      SetConsoleTextAttribute(h, 7);
	cout << "\n\t\t\t\t**************************************************\n";
    cout << "\t\t\t\t---- WellCome to Traffic Management System ----\n";
    cout << "\t\t\t\t**************************************************\n";

    Lane lanes[MAX_LANES] = {
        {"North", 0, 0},
        {"South", 0, 0},
        {"East", 0, 0},
        {"West", 0, 0}
    };
    
  
    collectTrafficData(lanes, MAX_LANES);
    calculateSignalTimings(lanes, MAX_LANES);
    displaySignalTimings(lanes, MAX_LANES);
    system ("cls");
    SetConsoleTextAttribute(h,8);
    int choice;
	    while (true)
	    {
             cout << "\nMenu:\n"
             << "1. Add to Array\n"           
             << "2. Search Array\n"
             << "3. Update Array\n"
             << "4. Show Array\n"
             << "5. Delete from Array\n"

			 << "6. View Light Durations\n"
             << "7. Update Light Duration\n"
             << "8. Simulate Traffic\n"
             << "9. Delete Light Duration\n"
			 << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
	    switch (choice)
        {
            case 1:
                add(a);
                break;
            case 2:
                search(a);
                break;
            case 3:
                update(a);
                break;
            case 4:
                show(a);
                break;
            case 5:
                del(a);
                break;
		    case 6:
                viewDurations();
                break;
            case 7:
                updateDuration();
                break;
            case 8:
                simulateTraffic();
                break;
            case 9:
                deleteDuration();
                break;    
			case 10:
				exit(0);      	   
            default:
            	 SetConsoleTextAttribute(h, 6);
                cout << "Invalid choice. Please try again.\n";
        }
}


return 0;
}

