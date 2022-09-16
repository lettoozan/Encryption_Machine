#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    int i, j, choice;
    char key[26];
    char plain_text[100];
    char cipher_text[100];

    while(1)
    {
        printf("\n\n ============================");
        printf("\n ||                        ||");
        printf("\n ||   ENCRYPTION MACHINE   ||");
        printf("\n ||        ver. 1.0        ||");
        printf("\n ||                        ||");
        printf("\n ============================");
        printf("\n");
        printf("****** MAIN MENU ******\n");
        printf("[1] Enter Key \n");
        printf("[2] Encrypt message\n");
        printf("[3] Decrypt message\n");
        printf("[4] Exit\n\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                back:
                printf("Please enter the key: ");
                scanf("%s", &key);
                if (strlen(key) < 26)
                {
                    printf("ERROR: Key must contain 26 characters.\n\n");
                    goto back;
                }
                for (i = 0; i <= 25; i++)
                {
                    for (j = 0; j <= 25; j++)
                    {
                        if (key[i] == key[j] && i != j)
                        {
                            printf("ERROR: Key must not contain repeated characters.\n\n");
                            goto back;
                        }
                        
                    }
                    
                }
                for (i = 0; i <= 25; i++)
                {
                    if (isalpha(key[i]))
                    {
                        continue;
                    }
                    else
                    {
                        printf("ERROR: Key must contain only alphabetic characters.\n\n");
                        goto back;
                    }
                }
            break;
            case 2:
                printf("Enter a plain text (max 100 characters): ");
                fgets(plain_text, 100, stdin);

                printf("The cipher text is: ");
                for (i = 0; i < strlen(plain_text); i++)
                {
                    if (isalpha(plain_text[i]))
                    {
                        if(plain_text[i] >= 'a' && plain_text[i] <= 'z')
                        {
                            cipher_text[i] = key[plain_text[i] - 'a'];//
                            printf("%c", tolower(cipher_text[i]));
                        }
                        else if(plain_text[i] >= 'A' && plain_text[i] <= 'Z')
                        {
                            cipher_text[i] = key[plain_text[i] - 'A']; //
                            printf("%c", toupper(cipher_text[i]));
                        }
                    }
                    else
                    {
                        printf("%c", plain_text[i]);
                    }
                }
            break;
            case 3:
                printf("\nEnter a cipher text (max 100 characters): ");
                fgets(cipher_text, 100, stdin);

                printf("\nThe cipher text is: ");
                for (i = 0; i < strlen(cipher_text); i++)
                {
                    if (isalpha(cipher_text[i]))
                    {
                        for (j = 0; j <= 26; j++)
                        {
                            if (toupper(cipher_text[i]) == toupper(key[j]))
                            {
                                if (isupper(cipher_text[i]))
                                    printf("%c", 'A' + j);
                                else
                                    printf("%c", 'a' + j);
                            }
                        }
                    }
                    else
                    {
                    printf("%c", cipher_text[i]);
                    }
                }
            break;
            case 4:
                printf("Exiting the program...");
                exit(0);
            break;
            default:
            printf("ERROR: Invalid choice!\n");
            break;
        }
    }
    return 0;
}