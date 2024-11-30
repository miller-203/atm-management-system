#include "header.h"

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void mainMenu(struct User u)
{
  while (1)
  {
    int option;
    system("clear");
    printf("\n\n\t\t======= ATM =======\n");
    printf("\n\t\t-->> Feel free to choose one of the options below, %s <<--\n", u.name);
    printf("\n\t\t[1]- Create a new account");
    printf("\n\t\t[2]- Update account information");
    printf("\n\t\t[3]- Check accounts");
    printf("\n\t\t[4]- Check list of owned account");
    printf("\n\t\t[5]- Make transaction");
    printf("\n\t\t[6]- Remove existing account");
    printf("\n\t\t[7]- Transfer ownership");
    printf("\n\t\t[8]- Exit\n\n\n");
    printf("\n\t\t-->> Enter your choice: ");

    if (scanf("%d", &option) != 1)
    {
      while (getchar() != '\n')
        ;
      continue;
    }

    if (option == 1)
    {
      createNewAccount(u);
      break;
    }
    else if (option == 2)
    {
      updateAccountInformation(u);
      break;
    }
    else if (option == 3)
    {
      checkAccountDetails(u);
      break;
    }
    else if (option == 4)
    {
      checkAllAccounts(u);
      break;
    }
    else if (option == 5)
    {
      makeTransaction(u);
      break;
    }
    else if (option == 6)
    {
      removeAccount(u);
      break;
    }
    else if (option == 7)
    {
      transferOwnership(u);
      break;
    }
    else if (option == 8)
    {
      exit(1);
      break;
    }
    else
    {
      printf("Invalid input! Please enter valid option!.\n");
      continue;
    }
  }
};

void initMenu(struct User *u)
{
  int r = 0;
  int option;
  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\t-->> Feel free to login / register :");
  printf("\n\t\t[1]- login");
  printf("\n\t\t[2]- register");
  printf("\n\t\t[3]- exit\n\n\n");
  printf("\n\t\t-->> Enter your choice : ");
  while (!r)
  {
    if (scanf("%d", &option) != 1 || option < 1 || option > 3)
    {
      while (getchar() != '\n')
        ;
      printf("Invalid input! Please enter 1 or 2 or 3.\n");
      continue;
    }

    if (option == 1)
    {
      loginMenu(u->name, u->password);
      if (strcmp(u->password, getPassword(*u)) == 0)
      {
        printf("\n\nPassword Match!");
      }
      else
      {
        printf("\n\t\tWrong password or username\n");
        handleFailedLogin(u);
      }
      r = 1;
      break;
    }
    else if (option == 2)
    {
      registerMenu(u->name, u->password);
      r = 1;
      break;
    }
    else if (option == 3)
    {
      exit(1);
      break;
    }
  }
};

int main()
{
  struct User u;

  initMenu(&u);
  mainMenu(u);
  return 0;
}
