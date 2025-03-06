#include<stdio.h>
#include<string.h>

#define MAX_USERS 10
#define CREADENTAIL_LENGTH 30
typedef struct{
    char username[CREADENTAIL_LENGTH];
    char password[CREADENTAIL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void user_register();
int user_login();

void login_creadentials(char* username, char* password);
void fixed_fgets_input(char*);

int main(){
    int option;
    int user_index;
    while(1){
    printf("\nWelcome to the User Management..");
    printf("\n1. Register");
    printf("\n2. Login");
    printf("\n3. Exit");
    printf("\nSelect the option: ");
    scanf("%d", &option);
    getchar();

    switch (option)
    {
    case 1:
        user_register();
        break;
    case 2:
        user_index = user_login();
        if (user_index >= 0)
        {
            printf("\nLogin Successful, Welcome %s!", users[user_index].username);
        }
        else
        {
            printf("\nLogin failed, Invalid username or password");
        }
        
        break;
    case 3:
        printf("\nExit Program ");
        return 0;
        break;
    
    default:
        printf("\nInvalid option, Please try again!!");
        break;
    }
    }
    return 0;
}

void user_register(){
    if (user_count == MAX_USERS)
    {
        printf("\nMaximum %d users are supported, No more users are registration allowed!!");
    }
    int new_index = user_count;
    printf("\nRegister a New User");
    login_creadentials(users[new_index].username, users[new_index].password);
    user_count++;
    printf("\nRegistration Successfull");
}

int user_login(){
    char username[CREADENTAIL_LENGTH];
    char password[CREADENTAIL_LENGTH];
    login_creadentials(username, password);
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username)==0 && strcmp(password, users[i].password)==0)
        {
            return i;
        }
        
    }
    
    return -1;
}

void login_creadentials(char* username, char* password){
    printf("\nEnter the username: ");
    fgets(username, CREADENTAIL_LENGTH, stdin);
    fixed_fgets_input(username);

    printf("Enter the password: ");
    fgets(password, CREADENTAIL_LENGTH, stdin);
}

void fixed_fgets_input(char* string){
    int index = strcspn(string, "\n");
    string[index] = '\0';
}