#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DAYS 7
#define TIMES 12
#define SEAT_TYPES 4
#define SEATS_PER_TYPES 6
#define MAX_PASSENGERS 100
#define NAME_LENGHT 50
#define PHONE_LENGHT 20
char passengers_first_name[MAX_PASSENGERS][NAME_LENGHT];
char passengers_last_name[MAX_PASSENGERS][NAME_LENGHT];
char passengers_phone[MAX_PASSENGERS][PHONE_LENGHT];
int passenger_count = 0;
void Register(){
    char First_Name[50], Last_Name[50], Phone_Number[20];//variables to store the passenger details
    if (passenger_count>=MAX_PASSENGERS){
        printf("Registration is full. NO more passengers can registered.");
    }
    printf("Please Enter you First Name:\n");
    scanf("%s", &passengers_first_name[passenger_count]);
    printf(" PLease Enter your Last Name:\n");
    scanf("%s", &passengers_last_name[passenger_count]);
    printf("Please Enter your Phone Number:\n");
    scanf("%S", &passengers_phone[passenger_count]);
    printf("Registration Successful!\n");
    passenger_count++;
    const char* days[DAYS] ={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};//days of the week(7 days)
   const int times[TIMES] ={1,2,3,4,5,6,7,8,9,10,11,12};//flight times in hours(12 hours)
   int Flight[DAYS][TIMES];//2D array to store the days and times for flights(7 days and 12 hours)
   for(int day=0; day<DAYS; day++){
    for(int time=0; time<TIMES; time++){
        Flight[day][time] =1;// flights that are available
    }
   }
   printf("Flight Schedule:\n");//display the flight schedule
   for (int day=0; day<DAYS; day++){
    printf("%s:", days[day]);
  for (int time=0; time<TIMES; time++){
    if (Flight[day][time]=1)/*1 means true */{
        printf("%d:00\t", times[time]);
    }
   }
    printf("\n");
    printf("\n");
    }
    const char* type[SEAT_TYPES] ={"Economy", "Premium Economy","Business Class", "First Class"};//types of seats available
    char available_seats[SEATS_PER_TYPES]= {'A', 'B', 'C', 'D', 'E', 'F'};//available seats
    int Seats[SEAT_TYPES][SEATS_PER_TYPES];//2D array to store seats types and seats available
    for(int types=0; types<SEAT_TYPES; types++){
        for(int available=0; available<6; available++){
            Seats[types][available] = 1;//1 means true = available
        }
    }

    printf("Available Seats ID with the type:\n");
  for(int types=0; types<SEAT_TYPES; types++){
        printf("%s:\t",type[types]);
   for(int available=0; available<SEATS_PER_TYPES; available++){
        if (Seats[types][available]==1){
        printf("%c,", available_seats[available]);
   }
  }printf("\n");
  }
int selected_day, selected_time, seat_type, seat_number;
printf(" Please enter the day of the flight (For example: 0=Sunday, 1=Monday, ect.)(0-6):\n");
scanf("%d",&selected_day);
if (selected_day<0 || selected_day>=DAYS){
    printf("Please re-enter the correct day\n");
    scanf("%d",&selected_day);
}
printf("Please enter the time of the flight (1-12):\n");
scanf("%d",&selected_time);
if (selected_time<1 || selected_time>=TIMES){
    printf("PLease re-enter the correct time\n");
    scanf("%d",&selected_time);
}
    if ( seat_type<0 || seat_type>SEAT_TYPES){
        printf("Please enter the correct type of seats:\n");
        scanf("%d", &seat_type);
}
printf("0=Economy, 1=Premium Economy, 2=Business Class, 3=First Class:\n");
printf("Please enter the type of seat(0-3):\n");
scanf("%d", &seat_type);
if (seat_type<0 || seat_type>=SEAT_TYPES){
    printf("Please re-enter the correct type of seats:\n");
    scanf("%d", &seat_type);
}
printf("Please enter the seat number(0-5):\n");
scanf("%d", &seat_number);
if (seat_number<0 || seat_number>=SEATS_PER_TYPES){
    printf("Please re-enter the correct number of seats:\n");
    scanf("%d", &seat_type);
}
if(Flight[selected_day][selected_time]==1 && Seats[seat_type][seat_number]==1)/*to check it the flight and seat are available*/{
    Seats[seat_type][seat_number]=0;//you can book this seat
    printf("Seat booked successfully!\n");
}
else {
    printf("Sorry, the selected seat is not available.\n");
    printf("please choose another seat:\n");
    scanf("%d", &seat_number);
}
if (Flight[selected_day][selected_time-1] ==1 && Seats[seat_type][seat_number]==1){
    Seats[seat_type][seat_number]=0; //you can book the this seat
    printf("\n Seat booked successfully!\n");
    printf("Booking Details:\n");
    printf("Name: %s %s\n", &First_Name, &Last_Name);
    printf("Phone: %S\n", &Phone_Number);
    printf("Flight Day: %s\n", days[selected_day]);
    printf("Flight Time: %d:00\n", selected_time);
    printf("Seat: %s, Number %c\n", type[seat_type], available_seats[seat_number]);
    }
    else {
        printf("Sorry, the selected seat is not available. Please restart the registration.\n");
    }
}
void Edit_flight(){
   char First_Name[50], Last_Name[50], Phone_Number[20];//variables to store the passenger details
    printf("Please Enter you First Name:\n");
    scanf("%s", &First_Name);
    printf(" PLease Enter your Last Name:\n");
    scanf("%s", &Last_Name);
    printf("Please Enter your Phone Number:\n");
    scanf("%S", &Phone_Number);
    //searching for passenger record
    int found = 0;
    for (int i = 0; i < passenger_count; i++) {
        if (strcmp(passengers_first_name[i], &First_Name) == 0 &&
            strcmp(passengers_last_name[i], &Last_Name) == 0 &&
            strcmp(passengers_phone[i], &Phone_Number) == 0) {
            found = 1;
}
    printf("Passenger record found!\n");
    printf(" Allowing changes in the current Booking Details:\n");
    scanf("%s", passengers_first_name[i]);
            printf("Enter new Last Name:\n");
            scanf("%s", passengers_last_name[i]);
            printf("Enter new Phone Number:\n");
            scanf("%s", passengers_phone[i]);

            printf("Details updated successfully!\n");
            return;
        }
    // Allow passenger to edit booking details
    int selected_day, selected_time, seat_type, seat_number;
    const char* days[DAYS] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char* type[SEAT_TYPES] = {"Economy", "Premium Economy", "Business Class", "First Class"};
    char available_seats[SEAT_TYPES] = {'A', 'B', 'C', 'D', 'E', 'F'};

    printf("Please enter the new day of the flight (0=Sunday, 1=Monday, etc.):\n");
    scanf("%d", &selected_day);
    while (selected_day < 0 || selected_day >= DAYS) {
        printf("Invalid day. Please re-enter:\n");
        scanf("%d", &selected_day);
    }
    printf("Select the new seat type (0=Economy, 1=Premium Economy, 2=Business Class, 3=First Class):\n");
    scanf("%d", &seat_type);
    while (seat_type < 0 || seat_type >= SEAT_TYPES) {
        printf("Invalid seat type. Please re-enter:\n");
        scanf("%d", &seat_type);
    }

    printf("Please enter the new seat number (0-5):\n");
    scanf("%d", &seat_number);
    while (seat_number < 0 || seat_number >= SEATS_PER_TYPES) {
        printf("Invalid seat number. Please re-enter:\n");
        scanf("%d", &seat_number);
        // Update booking
    printf("Booking updated successfully!\n");
    printf("Updated Booking Details:\n");
    printf("Name: %s %s\n", &First_Name, &Last_Name);
    printf("Phone: %s\n", &Phone_Number);
    printf("Flight Day: %s\n", days[selected_day]);
    printf("Flight Time: %d:00\n", selected_time);
    printf("Seat: %s, %c\n", type[seat_type], available_seats[seat_number]);
}
}
void List_passengers(){
    if (passenger_count==0){
       printf("No passengers have been registered yet.\n");
       return;
}
    printf("\n Passengers List\n");
    printf("ID\tFirst Name\tLast Name\tPhone Number\n");
   for (int i = 0; i < passenger_count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", i + 1, passengers_first_name[i], passengers_last_name[i], passengers_phone[i]);
    }
}
void Delete_passengers(){
    if (passenger_count==0){
        printf("No passengers habe been registered yet.\n");
    }
    int id;
    printf("\nPassenger List\n");
    printf("ID\tFirst Name\tLast Name\tPhone Number\n");
    for (int i = 0; i < passenger_count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", i + 1, passengers_first_name[i], passengers_last_name[i], passengers_phone[i]);
    }
    printf("Enter the ID of the passenger to delete (1-%d): ", passenger_count);
    scanf("%d", &id);
    printf("Enter the ID of the passenger to delete (1-%d): ", passenger_count);
    scanf("%d", &id);
    if (id < 1 || id > passenger_count) {
        printf("Invalid ID. Please try again.\n");
        return;
    }
    for (int i = id; i < passenger_count - 1; i++) {
        strcpy(passengers_first_name[i], passengers_first_name[i + 1]);
        strcpy(passengers_last_name[i], passengers_last_name[i + 1]);
        strcpy(passengers_phone[i], passengers_phone[i + 1]);
    }

    passenger_count--;
    printf("Passenger record deleted successfully.\n");
}
void Search_passenger(){
    if (passenger_count == 0) {
        printf("No passengers have been registered yet.\n");
        return;
    }

    char search_name[NAME_LENGHT], search_phone[PHONE_LENGHT];
    int choice, found = 0;
    printf("Search Passenger:\n");
    printf("1. By First Name\n");
    printf("2. By Last Name\n");
    printf("3. By Phone Number\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the First Name to search: ");
            scanf("%s", search_name);
            for (int i = 0; i < passenger_count; i++) {
                if (strcmp(passengers_first_name[i], search_name) == 0) {
                    printf("Passenger Found:\n");
                    printf("ID: %d, Name: %s %s, Phone: %s\n", i + 1, passengers_first_name[i], passengers_last_name[i], passengers_phone[i]);
                    found = 1;
                }
            }
            break;
        case 2:
            printf("Enter the Last Name to search: ");
            scanf("%s", search_name);
            for (int i = 0; i < passenger_count; i++) {
                if (strcmp(passengers_last_name[i], search_name) == 0) {
                    printf("Passenger Found:\n");
                    printf("ID: %d, Name: %s %s, Phone: %s\n", i + 1, passengers_first_name[i], passengers_last_name[i], passengers_phone[i]);
                    found = 1;
                }
            }
            break;
            case 3:
            printf("Enter the Phone Number to search: ");
            scanf("%s", search_phone);
            for (int i = 0; i < passenger_count; i++) {
                if (strcmp(passengers_phone[i], search_phone) == 0) {
                    printf("Passenger Found:\n");
                    printf("ID: %d, Name: %s %s, Phone: %s\n", i + 1, passengers_first_name[i], passengers_last_name[i], passengers_phone[i]);
                    found = 1;
                }
            }
            break;
            default:
            printf("Invalid choice. Returning to main menu.\n");
            return;
    }

    if (!found) {
        printf("No passenger found with the provided details.\n");
    }
}
int main()
{
  int choice;
  printf("\t\t\t\t\t\t\tWelcome to our Airline Reservation System\n");
  printf("1. Register a Flight.\n");
  printf("2. Edit a Flight.\n");
  printf("3. List the passenger that registered\n");
  printf("4. Delete this record\n");
  printf("5. Search for record\n");
  printf("6. Exit.\n");
  printf("Please enter your choice:");
  scanf("%d", &choice);
  switch(choice){
  case 1:
      Register();
      break;
  case 2:
       Edit_flight();
       break;
  case 3:
        List_passengers();
        break;
  case 4:
        Delete_passengers();
        break;
  case 5:
        Search_passenger();
        break;
  case 6:
    printf("Exiting the system. Thank you!\n");
    exit(0);
  default:
    printf("Invalid choice. Exiting.\n");
    exit(0);
  }
    return 0;
}
