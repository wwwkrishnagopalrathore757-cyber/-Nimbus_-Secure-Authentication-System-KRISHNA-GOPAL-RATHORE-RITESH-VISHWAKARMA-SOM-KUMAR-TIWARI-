#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char username[50];
    char password[100];
};

struct user  *user_list = NULL;
static int user_count = 0;


void register_user() 
{
    // Implementation for user registration
    struct user new_user;

    
    user_list = realloc(user_list, (user_count + 1) * sizeof(struct user));
    if (user_list == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    user_list[user_count] = new_user;
    user_count++;


    printf("-----------Register----------------\n");
    printf("Enter a username: \n");
    scanf("%s", new_user.username);

    while(validate_password(new_user.password))
    {
    printf("Enter a password: \n");
    scanf("%s", new_user.password);
    validate_password(new_user.password); //prompts the user to enter a strong password
    }

    printf("User %s registered successfully!\n", new_user.username);

}

void login_user() 
{
    // Implementation for user login
    struct user login_user;
    printf("-----------Login----------------\n");
    printf("Enter your username: \n");
    scanf("%s", login_user.username);
    printf("Enter your password: \n");
    scanf("%s", login_user.password);
    if(user_count == 0) 
    {
        printf("No users registered. Please register first.\n");
        return;
    }
    else
    {
        for(int i = 0; i < user_count; i++) 
        {
            if(strcmp(user_list[i].username, login_user.username) == 0 && strcmp(user_list[i].password, login_user.password) == 0) 
            {
                printf("Login successful! Welcome %s\n", login_user.username);
                return;
            }
        }
        printf("Invalid username or password. Please try again.\n");
    }

    
}