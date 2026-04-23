#include <stdio.h>
#include <string.h>

#define MAX 50

struct Flight {
    int flightNo;
    char source[30];
    char destination[30];
    int totalSeats;
    int availableSeats;
    float price;
};

struct Flight flights[MAX];
int flightCount = 0;

/* Function to Add Flight */
void addFlight() {
    printf("\nEnter Flight Number: ");
    scanf("%d", &flights[flightCount].flightNo);

    printf("Enter Source: ");
    scanf("%s", flights[flightCount].source);

    printf("Enter Destination: ");
    scanf("%s", flights[flightCount].destination);

    printf("Enter Total Seats: ");
    scanf("%d", &flights[flightCount].totalSeats);

    printf("Enter Ticket Price: ");
    scanf("%f", &flights[flightCount].price);

    flights[flightCount].availableSeats = flights[flightCount].totalSeats;

    flightCount++;
    printf("Flight Added Successfully!\n");
}

/* Function to View Flights */
void viewFlights() {
    if (flightCount == 0) {
        printf("\nNo Flights Available!\n");
        return;
    }

    printf("\nAvailable Flights:\n");
    for (int i = 0; i < flightCount; i++) {
        printf("\nFlight No: %d", flights[i].flightNo);
        printf("\nSource: %s", flights[i].source);
        printf("\nDestination: %s", flights[i].destination);
        printf("\nAvailable Seats: %d", flights[i].availableSeats);
        printf("\nPrice: %.2f\n", flights[i].price);
        printf("---------------------------");
    }
}

/* Function to Book Ticket */
void bookTicket() {
    int fno, found = 0;

    printf("\nEnter Flight Number to Book: ");
    scanf("%d", &fno);

    for (int i = 0; i < flightCount; i++) {
        if (flights[i].flightNo == fno) {
            found = 1;

            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Booking Successful!\n");
                printf("Remaining Seats: %d\n", flights[i].availableSeats);
            } else {
                printf("No Seats Available!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Flight Not Found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n====== Flight Booking System ======");
        printf("\n1. Add Flight");
        printf("\n2. View Flights");
        printf("\n3. Book Ticket");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                viewFlights();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                printf("Thank You!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    return 0;
}