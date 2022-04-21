/*
** EPITECH PROJECT, 2021
** terminal_bde
** File description:
** get_password.c
*/

#include "../include/bde.h"
#include <termios.h>

char *my_getpass(void)
{
    int size_malloc = 20;
    char *password = malloc(sizeof(char) * size_malloc);
    static struct termios oldt, newt;
    int c = 0;
    int i = 0;

    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    if (tcsetattr( STDIN_FILENO, TCSANOW, &newt) != 0) {
        perror("tcsetattr");
        return (NULL);
    }
    printf("Password: ");
    while((c = getchar()) != '\n') {
        write(1, "\b*", 2);
         password[i++] = c;
        if (i >= size_malloc - 1) {
            size_malloc += 20;
            password = (char *)realloc(password, sizeof(char) * size_malloc);
        }
    }
    password[i] = '\0';
    if (tcsetattr( STDIN_FILENO, TCSANOW, &oldt) != 0) {
        perror("tcsetattr");
        return (NULL);
    }
    return (password);
}

// char *my_getpass(void)
// {
//     struct termios oflags, nflags;
//     char *password = malloc(sizeof(char) * 40);

//     tcgetattr(fileno(stdin), &oflags);
//     nflags = oflags;
//     nflags.c_lflag &= ~ECHO;
//     nflags.c_lflag |= ECHONL;
//     if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
//         perror("tcsetattr");
//         return NULL;
//     }

//     printf("Password: ");
//     fgets(password, 40, stdin);
//     password[strlen(password) - 1] = 0;

//     if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
//         perror("tcsetattr");
//         return NULL;
//     }
//     return (password);
// }
