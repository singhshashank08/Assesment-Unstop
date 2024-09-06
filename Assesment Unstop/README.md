
# Unstop's SDE Challenge


## Problem Statement

1. There are 80 seats in a coach of a train with only 7 seats in a row and last row of only 3
seats. For simplicity, there is only one coach in this train.
2. One person can reserve up to 7 seats at a time.
3. If a person is reserving seats, the priority will be to book them in one row.
4. If seats are not available in one row then the booking should be done in such a way that the
nearby seats are booked.
5. User can book as many tickets as s/he wants until the coach is full.
6. You don’t have to create login functionality for this application.

## Solution

The scenario involves a train coach with 80 seats, arranged in multiple rows. Each seat is either empty ('0') or booked ('1'). The seat arrangement is represented by a string named "all_seats" with a length of 80, where each character denotes the status of a specific seat.
The "all_seats" string is stored in a database, ensuring that any changes made to the seat reservations are saved. This allows the program to persist seat reservation status between runs.
The areSeatsAvailable() function checks if a particular row has a block of consecutive empty seats that can accommodate a specified number of seats. It takes the row of seats (row) and the desired number of seats (numSeats) as input.
The reserveSeats() function is responsible for handling seat reservations in the train coach. It takes two parameters: the full seat arrangement (coach) and the desired number of seats (numSeats).
By storing the seat arrangement as the "all_seats" string in the database, the program can maintain the current seat status across different sessions. This enables continuity of reservations even after restarting or closing the application.



