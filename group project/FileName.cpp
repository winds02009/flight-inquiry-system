#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm> // Add this for copy_if and sort
#include <iterator>  // Add this for back_inserter
#include <ctime>
#include <functional>
#include <sstream>


using namespace std;

// Structs to represent Airline and Flight data
struct Airline {
	string codePrefix;
	string name;
};

struct Flight {
	string code;
	string date;
	string time;
	string originDestination;
	string status;
	string direction;
	string month;
	string year;
	string day;
};

bool compareFlights(const Flight& f1, const Flight& f2) {
	string dateTime1 = f1.date + " " + f1.time;
	string dateTime2 = f2.date + " " + f2.time;
	return dateTime1 < dateTime2;
}


// Class for the Flight Schedule Management System
class FlightScheduleManagementSystem {
private:
	vector<Airline> airlines;
	vector<Flight> flights;
	bool dataLoaded;

public:

	// Display the main menu options
	void displayMainMenu() {
		cout << "*** Main Menu ***\n";
		cout << "[1] Load Starting Data\n";
		cout << "[2] Edit Airline\n";
		cout << "[3] Show Schedule\n";
		cout << "[4] Search Flight\n";
		cout << "[5] Edit Flight\n";
		cout << "[6] Credits and Exit\n";
		cout << "*****************\n";
		cout << "Option (1 - 6): ";
	}

	// Function to run the main loop of the program
	void run() {
		int choice;

		do {
			cout << "*******************************************************\n";
			cout << "*  Welcome to the Flight Schedule Management System   *\n";
			cout << "*******************************************************\n";
			displayMainMenu();

			cin >> choice;

			switch (choice) {
			case 1:
				loadStartingData();
				break;
			case 2:
				if (dataLoaded) {
					cout << "Selected option: " << choice << "\n";
				}
				else {
					cout << "Error: Please load starting data first.\n";
					// Display an error message if data is not loaded
				}
				EditAirline();
				break;
			case 3:
				if (dataLoaded) {
					cout << "Selected option: " << choice << "\n";
				}
				else {
					cout << "Error: Please load starting data first.\n";
					// Display an error message if data is not loaded
				}

				ShowSchedule();
				break;
			case 4:
				if (dataLoaded) {
					cout << "Selected option: " << choice << "\n";
				}
				else {
					cout << "Error: Please load starting data first.\n";
					// Display an error message if data is not loaded
				}

				searchFlights();
				break;
			case 5:

				if (dataLoaded) {
					cout << "Selected option: " << choice << "\n";
				}
				else {
					cout << "Error: Please load starting data first.\n";
					// Display an error message if data is not loaded
				}
				EditFlights();
				break;

			case 6:
				char confirmExit;
				cout << "Are you sure you want to exit? (y/n): ";
				cin >> confirmExit;

				if (confirmExit == 'y' || confirmExit == 'Y') {
					displayGroupDetails();
					cout << "Credits and Exit. Goodbye!\n";
					exit(0);
				}
				else if (confirmExit == 'n' || confirmExit == 'N') {
					displayMainMenu();
					cin >> choice;
				}
				else {
					cout << "Invalid input. Please enter 'y' or 'n'.\n";
				}
				break;
			default:
				cout << "Invalid option. Please enter a number between 1 and 6.\n";
			}
		} while (choice != 6);
	}

private:

	// Load starting data for airlines and flights
	void loadStartingData() {
		airlines = {
			{"BA", "British Airways"},
			{"CX", "Cathay Pacific"},
			{"HX", "Hong Kong Airlines"},
			{"JL", "Japan Airlines"},
			{"UO", "Hong Kong Express"}
		};

		flights = {
			{"CX251", "12/09/23", "12:15", "SYD", "On Time", "Arrival"},
			{"BA732", "20/11/23", "06:55", "LHR", "On Time", "Arrival"},
			{"JL114", "12/10/23", "14:45", "NRT", "Delayed", "Arrival"},
			{"UO711", "15/12/23", "09:00", "ICN", "On Time", "Arrival"},
			{"CX651", "30/09/23", "15:55", "KHH", "Cancelled", "Arrival"},
			{"HX892", "01/11/23", "18:00", "BKK", "Delayed", "Departing"},
			{"UO417", "15/12/23", "15:55", "SIN", "On Time", "Departing"},
			{"BA337", "22/10/23", "23:50", "MAN", "On Time", "Departing"},
			{"CX657", "09/11/23", "21:00", "NYC", "Delayed", "Departing"},
			{"JL228", "15/10/23", "19:00", "CTS", "Cancelled", "Departing"}
		};

		dataLoaded = true;

		cout << "Starting data loaded.\n";

		// Display loaded data
		displayLoadedData();
	}

	// Display the loaded airline and flight data
	void displayLoadedData() {
		const int columnWidth = 20;

		cout << "\nAirline records:\n";
		cout << left << setw(columnWidth) << "Flight Code Prefix";
		cout << left << setw(columnWidth) << "Airline Name" << "\n";

		for (const auto& airline : airlines) {
			cout << setw(columnWidth) << airline.codePrefix << setw(columnWidth) << airline.name << "\n";
		}

		cout << "\nFlights information records:\n";
		cout << left << setw(columnWidth) << "Flight Code";
		cout << left << setw(columnWidth) << "Date";
		cout << left << setw(columnWidth) << "Time";
		cout << left << setw(columnWidth) << "Origin/Destination";
		cout << left << setw(columnWidth) << "Status";
		cout << left << setw(columnWidth) << "Direction" << "\n";

		for (const auto& flight : flights) {
			cout << setw(columnWidth) << flight.code << setw(columnWidth) << flight.date << setw(columnWidth) << flight.time
				<< setw(columnWidth) << flight.originDestination << setw(columnWidth) << flight.status
				<< setw(columnWidth) << flight.direction << "\n";
		}
	}

	void displayLoadedData1() {
		const int columnWidth = 20;

		airlines = {
		   {"BA", "British Airways"},
		   {"CX", "Cathay Pacific"},
		   {"HX", "Hong Kong Airlines"},
		   {"JL", "Japan Airlines"},
		   {"UO", "Hong Kong Express"},
		   {"CZ", "China Airline"}
		};

		cout << "\nAirline records:\n";
		cout << left << setw(columnWidth) << "Flight Code Prefix:";
		cout << left << setw(columnWidth) << "Airline Name:" << "\n";

		for (const auto& airline : airlines) {
			cout << setw(columnWidth) << airline.codePrefix << setw(columnWidth) << airline.name << "\n";
		}
	}
	void displayLoadedData2() {
		const int columnWidth = 20;

		flights = {
				   {"CX251", "12/09/23", "12:15", "SYD", "On Time", "Arrival"},
				   {"BA732", "20/11/23", "06:55", "LHR", "On Time", "Arrival"},
				   {"JL114", "12/10/23", "14:45", "NRT", "Delayed", "Arrival"},
				   {"UO711", "15/12/23", "09:00", "ICN", "On Time", "Arrival"},
				   {"CX651", "30/09/23", "15:55", "KHH", "Cancelled", "Arrival"},
				   {"HX892", "01/11/23", "18:00", "BKK", "Delayed", "Departing"},
				   {"UO417", "15/12/23", "15:55", "SIN", "On Time", "Departing"},
				   {"BA337", "22/10/23", "23:50", "MAN", "On Time", "Departing"},
				   {"CX657", "09/11/23", "21:00", "NYC", "Delayed", "Departing"},
				   {"JL228", "15/10/23", "19:00", "CTS", "Cancelled", "Departing"}
		};

		cout << "\nFlights information records:\n";
		cout << left << setw(columnWidth) << "Flight Code";
		cout << left << setw(columnWidth) << "Date";
		cout << left << setw(columnWidth) << "Time";
		cout << left << setw(columnWidth) << "Origin/Destination";
		cout << left << setw(columnWidth) << "Status";
		cout << left << setw(columnWidth) << "Direction" << "\n";

		for (const auto& flight : flights) {
			cout << setw(columnWidth) << flight.code << setw(columnWidth) << flight.date << setw(columnWidth) << flight.time
				<< setw(columnWidth) << flight.originDestination << setw(columnWidth) << flight.status
				<< setw(columnWidth) << flight.direction << "\n";
		}
	}
	void displayNewAirlines() {
		const int columnWidth = 20;

		cout << "\nAirline records:\n";
		cout << left << setw(columnWidth) << "Flight Code Prefix";
		cout << left << setw(columnWidth) << "Airline Name" << "\n";


		for (const auto& airline : airlines) {
			cout << setw(columnWidth) << airline.codePrefix << setw(columnWidth) << airline.name << "\n";
		}
	}





	// Edit airline information
	void EditAirline() {



		int option;

		do {

			cout << "[1] Add a new airline, [2] Edit an existing airline, [3] Delete an existing airline,  [4] Back to menu\n";
			cout << "Please enter 1-4: ";
			cin >> option;

			switch (option) {
			case 1:

				addAirline();
				break;
			case 2:

				editExistingAirline();
				break;
			case 3:

				deleteExistingAirline();
				break;
			case 4:

				break;
			default:
				cout << "Invalid option. Please enter a number between 1 and 4.\n";
			}
		} while (option != 4);
	}

	// Function to add a new airline
	void addAirline() {
		string code, name;
		const int columnWidth = 20;


		displayLoadedData1();
		cout << "Enter the Flight Code Prefix: ";
		cin >> code;

		cout << "Enter the Airline Name: ";
		cin.ignore(); // Clear newline character from the buffer
		getline(cin, name);

		// Check if the code is unique
		if (find_if(airlines.begin(), airlines.end(), [&](const Airline& a) { return a.codePrefix == code; }) != airlines.end()) {
			cout << "Error: Flight code prefix already exists.\n";
			return;
		}


		// Add the new airline
		airlines.push_back({ code, name });
		cout << "Airline added successfully.\n";
		displayNewAirlines();
	}

	// Function to edit an existing airline
	void editExistingAirline() {
		string code, newName;

		displayLoadedData1();
		cout << "Enter the Flight Code Prefix of the airline to edit: ";
		cin >> code;

		// Find the airline
		auto it = find_if(airlines.begin(), airlines.end(), [&](const Airline& a) { return a.codePrefix == code; });

		if (it != airlines.end()) {
			cout << "Enter the new Airline Name: ";
			cin.ignore(); // Clear newline character from the buffer
			getline(cin, newName);

			// Edit the airline name
			it->name = newName;
			cout << "Airline edited successfully.\n";
			displayNewAirlines();
		}
		else {
			cout << "Error: Airline not found.\n";
		}
	}

	// Function to delete an existing airline
	void deleteExistingAirline() {
		string code;

		cout << "Enter the Flight Code Prefix of the airline to delete: ";
		cin >> code;

		// Find the airline with the specified code
		auto it = find_if(airlines.begin(), airlines.end(), [&](const Airline& a) { return a.codePrefix == code; });

		if (it != airlines.end()) {
			// Erase the airline
			airlines.erase(it);
			cout << "Airline deleted successfully.\n";

			// Remove all flights associated with the deleted airline
			auto removeCondition = [&](const Flight& f) { return f.code.substr(0, code.size()) == code; };
			flights.erase(remove_if(flights.begin(), flights.end(), removeCondition), flights.end());

			// Display updated data
			displayNewAirlines();
		}
		else {
			cout << "Error: Airline not found.\n";
		}
	}
	void ShowSchedule() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		int scheduleOption;

		do {
			cout << "Choose schedule type:\n";
			cout << "[1] Arrival Schedule\n";
			cout << "[2] Departure Schedule\n";
			cout << "[3] Back to menu\n";
			cout << "Option (1 to 3): ";
			cin >> scheduleOption;

			switch (scheduleOption) {
			case 1:
				displayFlightSchedule("Arrival");
				break;
			case 2:
				displayFlightSchedule("Departing");
				break;
			case 3:
				// Optionally handle anything you want to do before breaking out of the loop.
				break;
			default:
				cout << "Invalid option. Returning to the Main Menu.\n";
			}
		} while (scheduleOption != 3);
	}

	// Function to display the flight schedule based on direction (Arrival or Departure)
	void displayFlightSchedule(const string& direction) {
		const int columnWidth = 20;

		// Filter flights based on the specified direction
		vector<Flight> filteredFlights;
		copy_if(flights.begin(), flights.end(), back_inserter(filteredFlights), [&](const Flight& f) {
			return f.direction == direction;
			});

		sort(filteredFlights.begin(), filteredFlights.end(),
			[](const Flight& a, const Flight& b) {
				return make_tuple(a.date.substr(3, 2), a.date.substr(0, 2), a.time) <
					make_tuple(b.date.substr(3, 2), b.date.substr(0, 2), b.time);
			});

		// Display the schedule in a table format
		cout << "\nFlight " << direction << " Schedule:\n";
		cout << left << setw(columnWidth) << "Flight Code";
		cout << left << setw(columnWidth) << "Date";
		cout << left << setw(columnWidth) << "Time";
		cout << left << setw(columnWidth) << "Origin/Destination";
		cout << left << setw(columnWidth) << "Status" << "\n";

		for (const auto& flight : filteredFlights) {
			cout << setw(columnWidth) << flight.code
				<< setw(columnWidth) << flight.date
				<< setw(columnWidth) << flight.time
				<< setw(columnWidth) << flight.originDestination
				<< setw(columnWidth) << flight.status << "\n";

		}
	}
	void searchFlights() {
		int option;

		do {
			cout << "***** Search Flight Menu *****\n";
			cout << "[1] Search Flight by Flight Code\n";
			cout << "[2] Search Flight by Origin/Destination\n";
			cout << "[3] Search Upcoming Flights\n";
			cout << "[4] Return to Main Menu\n";
			cout << "**************************\n";
			cout << "Option (1 - 4): ";
			cin >> option;

			switch (option) {
			case 1:
				searchFlightByFlightCode();
				break;
			case 2:
				searchFlightByOriginDestination();
				break;
			case 3:
				searchUpcomingFlights();
				break;
			case 4:
				// Return to Main Menu
				break;
			default:
				cout << "Invalid option. Please enter a number between 1 and 4.\n";
			}
		} while (option != 4);
	}

	void displayMatchingFlights(function<bool(const Flight&)> condition) {
		// Filter flights based on the given condition
		vector<Flight> matchingFlights;
		copy_if(flights.begin(), flights.end(), back_inserter(matchingFlights), condition);

		// Sort the matching flights
		sort(matchingFlights.begin(), matchingFlights.end(), compareFlights);

		// Display the sorted matching flights
		displayFlightRecords(matchingFlights);
		// Return to the Search Flight Menu
	}

	void searchFlightByFlightCode() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		string flightCode;
		cout << "Enter the Flight Code: ";
		cin >> flightCode;

		// Use the findFlightsByCode function to find the flights
		vector<Flight> matchingFlights = findFlightsByCode(flightCode);

		if (!matchingFlights.empty()) {
			// Display the found flights
			cout << "Flights found:\n";
			displayFlightRecords(matchingFlights);
		}
		else {
			cout << "No flights found with code " << flightCode << ".\n";
		}
	}

	// Function to find flights by their flight code
	// Returns a vector of matching flights (both directions)
	vector<Flight> findFlightsByCode(const string& code) {
		vector<Flight> matchingFlights;

		for (const auto& flight : flights) {
			if (flight.code == code) {
				matchingFlights.push_back(flight);
			}
		}

		return matchingFlights;
	}

	void searchFlightByOriginDestination() {
		string airportCode;

		cout << "Enter the Origin/Destination Airport Code: ";
		cin >> airportCode;

		// Find and display flights matching the input airport code
		displayMatchingFlights([&](const Flight& f) {
			return f.originDestination == airportCode || f.originDestination == airportCode;
			});
		// After displaying, return to the Search Flight Menu
	}

	// Function to search and display upcoming flights
	void searchUpcomingFlights() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		// Get the current date
		time_t now = time(0);
		tm currentTime;

		if (localtime_s(&currentTime, &now) != 0) {
			cerr << "Error: Could not get current time." << endl;
			return;
		}

		int currentYear = currentTime.tm_year + 1900;
		int currentMonth = currentTime.tm_mon + 1;
		int currentDay = currentTime.tm_mday;
		int currentHour = currentTime.tm_hour;
		int currentMinute = currentTime.tm_min;

		cout << "Current Date and Time: " << currentYear << "/" << currentMonth << "/" << currentDay << " " << currentHour << ":" << currentMinute << endl;

		// Filter upcoming flights based on the current date and time
		vector<Flight> upcomingFlights;
		for (const auto& f : flights) {
			int flightYear, flightMonth, flightDay, flightHour, flightMinute;
			if (sscanf_s(f.date.c_str(), "%d/%d/%d", &flightDay, &flightMonth, &flightYear) != 3 ||
				sscanf_s(f.time.c_str(), "%d:%d", &flightHour, &flightMinute) != 2) {
				cerr << "Error: Could not parse date or time for flight " << f.code << "." << endl;
				continue;
			}



			if (
				(flightMonth > currentMonth) ||
				(flightMonth == currentMonth && flightDay > currentDay) ||
				(flightMonth == currentMonth && flightDay == currentDay && flightHour > currentHour) ||
				(flightMonth == currentMonth && flightDay == currentDay && flightHour == currentHour && flightMinute > currentMinute)) {
				upcomingFlights.push_back(f);
			}
		}

		// Sort the upcoming flights using std::sort with a custom comparator
		sort(upcomingFlights.begin(), upcomingFlights.end(), compareFlights);

		if (!upcomingFlights.empty()) {
			cout << "Upcoming Flights found:\n";
			displayFlightRecords(upcomingFlights);
		}
		else {
			cout << "No upcoming flights found.\n";
		}
	}






	void displayFlightRecords(const vector<Flight>& flightsToDisplay) {
		const int columnWidth = 20;

		cout << "\nFlight Records:\n";
		cout << left << setw(columnWidth) << "Flight Code";
		cout << left << setw(columnWidth) << "Date";
		cout << left << setw(columnWidth) << "Time";
		cout << left << setw(columnWidth) << "Origin/Destination";
		cout << left << setw(columnWidth) << "Status";
		cout << left << setw(columnWidth) << "Direction" << "\n";

		for (const auto& flight : flightsToDisplay) {
			cout << setw(columnWidth) << flight.code << setw(columnWidth) << flight.date << setw(columnWidth) << flight.time
				<< setw(columnWidth) << flight.originDestination << setw(columnWidth) << flight.status
				<< setw(columnWidth) << flight.direction << "\n";
		}
	}


	void EditFlights() {
		int option2;

		do {
			cout << "***** Edit Flights Menu *****\n";
			cout << "[1] Add a new flight\n";
			cout << "[2] Edit an existing flight (status)\n";
			cout << "[3] Delete an existing flight\n";
			cout << "[4] Delete all cancelled flights\n";
			cout << "[5] Return to Main Menu\n";
			cout << "*****************************\n";
			cout << "Option (1 - 5): ";
			cin >> option2;

			switch (option2) {
			case 1:
				addNewFlight();
				break;
			case 2:
				editExistingFlight();
				break;
			case 3:
				deleteExistingFlight();
				break;
			case 4:
				deleteAllCancelledFlights();
				break;
			case 5:
				// Return to Main Menu
				break;
			default:
				cout << "Invalid option. Please enter a number between 1 and 5.\n";
			}
		} while (option2 != 5);
	}

	void addNewFlight() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		Flight newFlight;
		string newstatus;
		cout << "Enter Flight Code: ";
		cin >> newFlight.code;

		// Check for duplicate flight records
		if (findFlightsByCode(newFlight.code).size() > 0) {
			cout << "Error: Duplicate flight code. Flight not added.\n";
			return;
		}

		cout << "Enter Date (dd/mm/yy): ";
		cin >> newFlight.date;

		cout << "Enter Time (hh:mm): ";
		cin >> newFlight.time;

		cout << "Enter Origin/Destination: ";
		cin >> newFlight.originDestination;


		cout << "Enter Status: ";
		cin.ignore(); // Clear newline character from the buffer
		getline(cin, newstatus);
		// Update the flight status
		newFlight.status = newstatus;

		int i = 0;
		for (const auto& flight : flights) {
			if (flight.status == newFlight.status) {
				flights[i].status = newstatus;
			}
			i++;
		}





		cout << "Enter Direction (Arrival/Departing): ";
		cin >> newFlight.direction;

		// Add the new flight
		flights.push_back(newFlight);
		cout << "Flight added successfully.\n";

		// Display the updated data
		displayLoadedData();
	}

	void editExistingFlight() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		string flightCode;
		cout << "Enter Flight Code to edit: ";
		cin >> flightCode;

		// Find flights with the given flight code
		vector<Flight> matchingFlights = findFlightsByCode(flightCode);

		if (matchingFlights.empty()) {
			cout << "Error: No flights found with the given flight code.\n";
			return;
		}

		// If there are multiple flights with the same code, let the user choose one
		int choice;
		if (matchingFlights.size() > 1) {
			cout << "Multiple flights found with the same code. Choose a flight to edit:\n";
			displayFlightRecords(matchingFlights);
			cout << "Enter the corresponding number: ";
			cin >> choice;

			// Validate user input
			if (choice < 1 || choice > matchingFlights.size()) {
				cout << "Invalid choice. Edit operation canceled.\n";
				return;
			}

			// Adjust the index to match vector indexing
			choice--;
		}
		else {
			// Only one flight found, use it directly
			choice = 0;
		}

		// Edit flight status
		string newStatus;


		cout << "Enter the new flight status:  ";
		cin.ignore(); // Clear newline character from the buffer
		getline(cin, newStatus);
		// Update the flight status
		matchingFlights[choice].status = newStatus;

		int i = 0;
		for (const auto& flight : flights) {
			if (flight.code == matchingFlights[choice].code) {
				flights[i].status = newStatus;
			}
			i++;
		}
		// Display the updated data for the selected flight
		displayLoadedData(); // Assuming displayLoadedData1 is the appropriate function
		cout << "Flight status edited successfully.\n";
	}




	void deleteExistingFlight() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		string flightCode;
		cout << "Enter Flight Code to delete: ";
		cin >> flightCode;

		// Find flights with the given flight code
		vector<Flight> matchingFlights = findFlightsByCode(flightCode);

		if (matchingFlights.empty()) {
			cout << "Error: No flights found with the given flight code.\n";
			return;
		}

		// If there are multiple flights with the same code, let the user choose one
		if (matchingFlights.size() > 1) {
			int choice;
			cout << "Multiple flights found with the same code. Choose a flight to delete:\n";
			displayFlightRecords(matchingFlights);
			cout << "Enter the corresponding number: ";
			cin >> choice;

			if (choice < 1 || choice > matchingFlights.size()) {
				cout << "Invalid choice. Deletion operation canceled.\n";
				return;
			}

			// Adjust the index to match vector indexing
			choice--;
			deleteFlight(matchingFlights[choice]);
		}
		else {
			// Only one flight found, delete it directly
			deleteFlight(matchingFlights[0]);
		}

		// Display the updated data
		displayLoadedData();
	}

	void deleteFlight(Flight& flight) {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		cout << "Deleting Flight Code: " << flight.code << "\n";
		flights.erase(remove_if(flights.begin(), flights.end(), [&](const Flight& f) {
			return f.code == flight.code;
			}), flights.end());

		cout << "Flight deleted successfully.\n";
	}

	void deleteAllCancelledFlights() {
		if (!dataLoaded) {
			cout << "Error: Please load starting data first.\n";
			return;
		}

		char confirmDelete;
		cout << "Are you sure you want to delete all cancelled flights? (y/n): ";
		cin >> confirmDelete;

		if (confirmDelete == 'y' || confirmDelete == 'Y') {
			// Erase all flights with status "Cancelled"
			flights.erase(remove_if(flights.begin(), flights.end(), [](const Flight& f) {
				return f.status == "Cancelled";
				}), flights.end());
			displayLoadedData();
			cout << "All cancelled flights deleted successfully.\n";

		}
		else if (confirmDelete == 'n' || confirmDelete == 'N') {
			cout << "Deletion canceled. No flights deleted.\n";
		}
		else {
			cout << "Invalid input. Please enter 'y' or 'n'.\n";
		}
	}




	// Function to display personal details of group members
	void displayGroupDetails() {
		const int columnWidth = 16;
		const int columnWidth2 = 15;
		const int columnWidth3 = 19;



		cout << setw(columnWidth) << "Student Name:" << setw(columnWidth) << " [Ng Wing In] " << setw(columnWidth) << " [Chan Wai Lok] " << setw(columnWidth) << " [Au Cheuk Shing] " << setw(columnWidth) << " [Law Kwai Cheung] " << setw(columnWidth) << " [WONG Tsz Fung] " << "\n";
		cout << setw(columnWidth) << "Student ID:" << setw(columnWidth2) << " [23048563S] " << setw(columnWidth2) << " [23049479S] " << setw(columnWidth2) << " [23047947S] " << setw(columnWidth3) << " [23049768S] " << setw(columnWidth3) << " [23043094S] " << "\n";
		cout << setw(columnWidth) << "Tutorial Group:" << setw(columnWidth) << "[103 Group 2]" << "\n";

	}
	// Repeat the above lines for each group member
};


int main() {
	FlightScheduleManagementSystem system;
	system.run();

	return 0;
}