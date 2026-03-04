#include <stdio.h>
#include<string.h>
#define max_space 50

char vehicleNum[max_space][10];
int type[max_space];
int hour[max_space];
int FilledSpace[max_space];

void fees(int i) {
  int totalfees = 0;
  if(type[i] == 1){
    totalfees = hour[i] * 50;
  } else if(type[i] == 2){
    totalfees = hour[i] * 100;
  } else if(type[i] == 3){
    totalfees = hour[i] * 50;
  }
  printf("Total Parking Fee for your vehicle [ %s ] is: %d PKR \n", vehicleNum[i], totalfees);
  printf("\n");
}

void checkIn() {
  
  for(int i = 0; i < max_space; i++){

    if (FilledSpace[i] == 0) {
    
    printf("\nEnter your vehicle Number Plate: ");
    scanf("%s", &vehicleNum[i]);
    
    printf("Choose your vehicle type (1.Bike 2.Car 3.Truck): ");
    scanf("%d", &type[i]);
    
    printf("How many hour you have to park vehicle: ");
    scanf("%d", &hour[i]);
    
    FilledSpace[i] = 1; 
    
    printf("\n--------Check In Receipt--------\n");
    printf("Your Vehicle Number Plate is: %s \n", vehicleNum[i]);
    switch(type[i]) {
      case 1:
      printf("Your Vehicle Type is: Bike\n");
      break;
      case 2:
      printf("Your Vehicle Type is: Car\n");
      break;
      case 3:
      printf("Your Vehicle Type is: Truck\n");
      break;
      default:
      printf("Choose the correct type\n");
    }
    printf("Your Time For parked a vehicle is: %dhrs \n", hour[i]);
    printf("Thanks For Parking Vehicle \n");
    printf("\n");
    return;
    }
  }
}

void checkOut() {

  char getNumber[10];
  printf("Enter your vehicle number: ");
  scanf("%s", &getNumber);

  for(int i = 0; i < max_space; i++) {
    if (FilledSpace[i] == 1 && (strcmp(vehicleNum[i], getNumber) == 0))  {
      printf("\n--------CheckOut Report--------\n");
      printf("Your Vehicle Number Plate is: %s \n", vehicleNum[i]);
      switch(type[i]) {
        case 1:
          printf("Your Vehicle Type is: Bike\n");
          break;
        case 2:
          printf("Your Vehicle Type is: Car\n");
          break;
        case 3:
          printf("Your Vehicle Type is: Truck\n");
          break;
        default:
          printf("Choose the correct type\n");
      }
      fees(i);
      FilledSpace[i] = 0; 
      return;
    }
  }
}

void FreeSpace(){
  int Space = 0;
  for (int i = 0; i < max_space; i++) {
    if(FilledSpace[i] == 1) Space++;   
  }
  printf("\nTotal Filled Slots: %d\n", Space);
  printf("Free Slots: %d \n", max_space - Space);
  printf("\n");
}


int main() {
  int choice;
  
  while(1){
    printf("Welcome to Smart Parking Management System\n");
    printf("1.Check In \n");
    printf("2.Check Out \n");
    printf("3.Free Space \n");
    printf("4.Exit \n");
    printf("Choose any One: ");
    scanf("%d", &choice);
    switch (choice){
      case 1:
        checkIn();
        break;
      case 2:
        checkOut();
        break;
      case 3:
        FreeSpace();
        break;
      case 4:
        return 0;
      default:
        printf("Technical Error!");
    }
  }
}