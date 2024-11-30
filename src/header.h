#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_SIZE 50
#define MAX_PASSWORD_SIZE 50
#define MAX_COUNTRY_SIZE 100
#define MAX_TRANSACTION_TYPE_SIZE 10

struct Date {
  int month, day, year;
};

struct Record {
  int id;
  int userId;
  char name[MAX_USERNAME_SIZE];
  char country[MAX_COUNTRY_SIZE];
  int phone;
  char accountType[MAX_TRANSACTION_TYPE_SIZE];
  int accountNbr;
  double amount;
  struct Date deposit;
  struct Date withdraw;
};

struct User {
  int id;
  char name[MAX_USERNAME_SIZE];
  char password[MAX_PASSWORD_SIZE];
};

// authentication functions
void initMenu(struct User *u);
void loginMenu(char a[MAX_USERNAME_SIZE], char pass[MAX_PASSWORD_SIZE]);
void registerMenu(char a[MAX_USERNAME_SIZE], char pass[MAX_PASSWORD_SIZE]);
const char *getPassword(struct User u);

// system function
void createNewAccount(struct User u);
void mainMenu(struct User u);
void checkAllAccounts(struct User u);
void updateAccountInformation(struct User u);
void checkAccountDetails(struct User u);
void makeTransaction(struct User u);
void removeAccount(struct User u);
void transferOwnership(struct User u);
void handleFailedLogin(struct User *u);
void handleFailedRegistration(char a[MAX_USERNAME_SIZE], char pass[MAX_PASSWORD_SIZE]);
bool checkValid(char str[]);
bool isNumber(int num);
int isValidDate(int month, int day, int year);
void clearInputBuffer();
int isLeapYear(int year);
int isValidPhoneNumber(const char* phone);
int getMenuChoice(int max_choice);