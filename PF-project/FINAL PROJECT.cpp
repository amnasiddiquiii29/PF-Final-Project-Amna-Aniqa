

#include <iostream>
#include <string>
using namespace std;

const int maxTravellers = 10;
const int maxDuration = 30;

// displays the menu for user
void displayMenu()
{
	cout << "Choose an option" << endl;
	cout << "1. Plan a trip" << endl;
	cout << "2.View available destinations" << endl;
	cout << "3.exit" << endl;
}

// shows list of available destinations with prices
void viewDestination()
{
	cout << "No.\tDestination\tAccomodation\tTransport\tFood\n";
	cout << "1\tMurree\t\t9000\t\t4000\t\t3000\n";
	cout << "2\tHunza\t\t12,000\t\t15,000\t\t3,000\n";
	cout << "3\tSwat\t\t8,000\t\t6,000\t\t2,000\n";
	cout << "4\tNaran\t\t10,000\t\t8,000\t\t2,500\n";
}

// takes input (trip details) from user and validates input
void planTrip(int& travellers, int& duration, int& destination)
{
	cout << " Enter Destination:\t (1=Murree, 2=Hunza, 3=Swat, 4=Naran" << endl;
	cin >> destination;
	while (destination != 1 && destination != 2 && destination != 3 && destination != 4)
	{
		cout << "Invalid destination please enter again" << endl;
		cin >> destination;
	}

	cout << "Enter no. of travellers (1-10)" << endl;
	cin >> travellers;
	while (travellers < 1 || travellers > maxTravellers)
	{
		cout << "Invalid no. please enter again" << endl;
		cin >> travellers;
	}

	cout << "enter duration in days" << endl;
	cin >> duration;
	while (duration < 1 || duration > maxDuration)
	{
		cout << "Invalid input please enter again";
		cin >> duration;
	}
}

// calculate the costs
void calculateCost(int travellers, int duration, int destination, double& rooms, double& accomodation, double& nights, double& transport, double& food, double& total)
{
	// Murree
	const int MURREE_TRANSPORT = 4000;
	const int MURREE_FOOD = 3000;
	const int MURREE_ACCOMMODATION = 9000;

	// Hunza
	const int HUNZA_TRANSPORT = 15000;
	const int HUNZA_FOOD = 3000;
	const int HUNZA_ACCOMMODATION = 12000;

	// Swat
	const int SWAT_TRANSPORT = 6000;
	const int SWAT_FOOD = 2000;
	const int SWAT_ACCOMMODATION = 8000;

	// Naran
	const int NARAN_TRANSPORT = 8000;
	const int NARAN_FOOD = 2500;
	const int NARAN_ACCOMMODATION = 10000;

	rooms = (travellers + 1) / 2;
	nights = (duration > 1) ? (duration - 1) : 0;

	if (destination == 1)
	{
		accomodation = rooms * nights * MURREE_ACCOMMODATION;
		transport = travellers * MURREE_TRANSPORT;
		food = travellers * duration * MURREE_FOOD;
	}
	else if (destination == 2)
	{
		accomodation = rooms * nights * HUNZA_ACCOMMODATION;
		transport = travellers * HUNZA_TRANSPORT;
		food = travellers * duration * HUNZA_FOOD;
	}
	else if (destination == 3)
	{
		accomodation = rooms * nights * SWAT_ACCOMMODATION;
		transport = travellers * SWAT_TRANSPORT;
		food = travellers * duration * SWAT_FOOD;
	}
	else if (destination == 4)
	{
		accomodation = rooms * nights * NARAN_ACCOMMODATION;
		transport = travellers * NARAN_TRANSPORT;
		food = travellers * duration * NARAN_FOOD;
	}

	total = accomodation + transport + food;
}

// ask user to enter activities and calculate activity cost
void selectActivities(double& cost, int travellers)
{
	bool a1 = false, a2 = false, a3 = false, a4 = false, a5 = false;
	cost = 0;

	cout << "Activities price" << endl;
	cout << "1. Sightseeing (600)" << endl;
	cout << "2. Hiking (1200)" << endl;
	cout << "3. Boating (1100)" << endl;
	cout << "4. Museum (350)" << endl;
	cout << "5. Adventure (1800)" << endl;
	cout << "0. Done" << endl;

	int choice = -1;
	while (choice != 0)
	{
		cout << "Select no. of activities (1-5), or 0 for none/to exit): " << endl;
		cin >> choice;

		if (choice == 1) {
			if (a1)
				cout << "Already added" << endl;
			else { a1 = true; cost = cost + 600; cout << "Added" << endl; }
		}
		else if (choice == 2) {
			if (a2)
				cout << "Already added" << endl;
			else { a2 = true; cost = cost + 1200; cout << "Added" << endl; }
		}
		else if (choice == 3) {
			if (a3)
				cout << "Already added" << endl;
			else { a3 = true; cost = cost + 1100; cout << "Added" << endl; }
		}
		else if (choice == 4) {
			if (a4)
				cout << "Already added" << endl;
			else { a4 = true; cost = cost + 350; cout << "Added" << endl; }
		}
		else if (choice == 5) {
			if (a5)
				cout << "Already added" << endl;
			else { a5 = true; cost = cost + 1800; cout << "Added" << endl; }
		}
		else if (choice != 0) {
			cout << "Invalid choice" << endl;
		}
	}

	cost = cost * travellers;
}

// checks whether the total is within the budget or not
void checkBudget(double total, double cost, double& totalBill)
{
	double budget = 0, remaining = 0;
	string budgetStatus;
	totalBill = total + cost;

	cout << "Enter your budget: " << endl;
	cin >> budget;
	while (budget <= 0)
	{
		cout << "Invalid budget. Please enter a value greater than 0 ";
		cin >> budget;
	}

	if (budget >= totalBill) {
		budgetStatus = "within the limit";
		remaining = budget - totalBill;
	}
	else {
		budgetStatus = "limit exceeded";
		remaining = totalBill - budget;
	}

	cout << "Budget Status: " << budgetStatus << endl;
	cout << "Remaining: " << remaining << endl;
}

// displays the output
void displayresult(double accomodation, double transport, double food, double activitiesCost, double totalBill)
{
	cout << "accomodation cost=" << accomodation << endl;
	cout << "transport cost=" << transport << endl;
	cout << "food cost=" << food << endl;
	cout << "activities cost=" << activitiesCost << endl;
	cout << "total cost=" << totalBill << endl;
}

int main()
{
	int choice = 0;
	displayMenu();
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Invalid choice please enter again";
		cin >> choice;
	}

	if (choice == 2)
	{
		viewDestination();
	}
	if (choice == 1)
	{
		int travellers = 0, duration = 0, destination = 0;
		double rooms = 0, nights = 0, accomodation = 0, transport = 0, food = 0, total = 0, cost = 0, totalBill = 0;

		planTrip(travellers, duration, destination);
		calculateCost(travellers, duration, destination, rooms, accomodation, nights, transport, food, total);
		cout << "Accommodation: " << accomodation << endl;
		cout << "Food: " << food << endl;
		cout << "Transport: " << transport << endl;
		cout << "Total: " << total << endl;
		selectActivities(cost, travellers);
		checkBudget(total, cost, totalBill);
		displayresult(accomodation, transport, food, cost, totalBill);
	}
	if (choice == 3)
	{
		cout << "Goodbye! Thank you for using the trip planner." << endl;
		return 0;
	}

	return 0;
}
