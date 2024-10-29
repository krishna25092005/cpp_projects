/**
 * @file bus_reservation_system.cpp
 * @author Krishna Chauhan
 * @date 2024-10-29
 * 
 * @brief A simple bus reservation system that allows users to book seats, view reservations, edit reservations, and print tickets.
 * 
 * This program provides a command-line interface for managing bus seat reservations. 
 * Users can perform the following actions:
 * - Book a seat by providing their name and seat number.
 * - View all current reservations.
 * - Edit an existing reservation by changing the passenger's name.
 * - Print a ticket for a specific seat number.
 * 
 * The system uses a vector to store booking information, and each booking includes the passenger's name and seat number.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Booking
{
public:
    string name;
    int seatNo;
    // Add more fields as needed

    Booking(string _name, int _seatNo) : name(_name), seatNo(_seatNo)
    {
        // Initialize other fields as needed
    }
};

class BusBookingSystem
{
private:
    vector<Booking> bookings;

public:
    void bookSeat()
    {
        string name;
        int seatNo;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter seat number: ";
        cin >> seatNo;

        // Add more input fields as needed

        Booking newBooking(name, seatNo);
        bookings.push_back(newBooking);
        cout << "Seat booked successfully.\n";
    }

    void viewReservations()
    {
        if (bookings.empty())
        {
            cout << "No reservations made yet.\n";
            return;
        }

        cout << "All reservations:\n";
        cout << "Seat No.\tName\n";
        for (const auto &booking : bookings)
        {
            cout << booking.seatNo << "\t\t" << booking.name << endl;
        }
    }

    void editReservation()
    {
        int seatToEdit;
        cout << "Enter seat number to edit: ";
        cin >> seatToEdit;

        bool found = false;
        for (auto &booking : bookings)
        {
            if (booking.seatNo == seatToEdit)
            {
                cout << "Enter new name: ";
                cin >> booking.name;
                // Add more fields to edit as needed

                cout << "Reservation edited successfully.\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Reservation not found.\n";
        }
    }

    void printTicket()
    {
        int seatToPrint;
        cout << "Enter seat number to print ticket: ";
        cin >> seatToPrint;

        bool found = false;
        for (const auto &booking : bookings)
        {
            if (booking.seatNo == seatToPrint)
            {
                cout << "Ticket for Seat No. " << booking.seatNo << endl;
                cout << "Passenger Name: " << booking.name << endl;
                // Add more fields to print as needed

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Reservation not found.\n";
        }
    }
};

int main()
{
    BusBookingSystem system;
    int choice;

    do
    {
        cout << "\nMini Bus Booking System\n";
        cout << "1. Book a seat\n";
        cout << "2. View reservations\n";
        cout << "3. Edit a reservation\n";
        cout << "4. Print a ticket\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.bookSeat();
            break;
        case 2:
            system.viewReservations();
            break;
        case 3:
            system.editReservation();
            break;
        case 4:
            system.printTicket();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}