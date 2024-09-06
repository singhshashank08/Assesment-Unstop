#include <iostream>
#include <vector>

using namespace std;

// Function to check if consecutive seats are available in a row
bool areSeatsAvailable(const vector<int>& row, int numSeats, int& startIndex)
{
    int consecutiveCount = 0;
    for (int i = 0; i < row.size(); i++) {
        if (row[i] == 0) { // Check if seat is available
            consecutiveCount++;
            if (consecutiveCount == numSeats) {
                startIndex = i - numSeats + 1; // Set the starting index for reservation
                return true;
            }
        } else {
            consecutiveCount = 0;
        }
    }
    return false;
}

// Function to reserve seats in a row from a specific index
void reserveSeatsInRow(vector<int>& row, int startIndex, int numSeats)
{
    for (int i = startIndex; numSeats > 0; i++, numSeats--) {
        row[i] = 1; // Reserve the seat
    }
}

// Function to count total available seats
int countAvailableSeats(const vector<vector<int>>& coach)
{
    int availableSeats = 0;
    for (const vector<int>& row : coach) {
        for (int seat : row) {
            if (seat == 0)
                availableSeats++;
        }
    }
    return availableSeats;
}

// Function to reserve seats in a train coach
bool reserveSeats(vector<vector<int>>& coach, int numSeats)
{
    // Check if enough seats are available
    int totalAvailableSeats = countAvailableSeats(coach);
    if (numSeats > totalAvailableSeats) {
        cout << "Not enough seats available." << endl;
        return false;
    }

    int rows = coach.size();
    
    // Check if seats can be reserved in one row
    for (int i = 0; i < rows; i++) {
        int startIndex = -1;
        if (areSeatsAvailable(coach[i], numSeats, startIndex)) {
            // Reserve seats in the row
            reserveSeatsInRow(coach[i], startIndex, numSeats);
            cout << "Seats reserved successfully in one row." << endl;
            return true;
        }
    }

    // If seats cannot be reserved in one row, book nearby seats
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coach[i].size() && numSeats > 0; j++) {
            if (coach[i][j] == 0) {
                coach[i][j] = 1; // Reserve the seat
                numSeats--;
            }
        }
    }

    cout << "Seats reserved nearby." << endl;
    return true;
}

// Function to display the coach seating arrangement
void displayCoach(const vector<vector<int>>& coach)
{
    for (const vector<int>& row : coach) {
        for (int seat : row) {
            cout << seat << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> coach(12, vector<int>(7, 0)); // Initialize coach with 12 rows and 7 seats in each row
    coach[11].resize(3); // Last row has 3 seats

    int numBookings;
    cout << "Enter the number of bookings: ";
    cin >> numBookings;

    for (int i = 0; i < numBookings; i++) {
        int numSeats;
        cout << "Enter the number of seats to reserve: ";
        cin >> numSeats;

        if (reserveSeats(coach, numSeats)) {
            cout << "Updated seating arrangement:" << endl;
            displayCoach(coach);
        }
        cout << endl;
    }

    return 0;
}
