// V 1
/**
 * @file alissa.c
 * @author Corbin Graham
 * @brief An app for Alissa!
 * @version 0.022
 * @date 2022-03-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Check System Requirements
#ifdef _WIN32
#include <Windows.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Macros
#define URL "https://raw.githubusercontent.com/cdmonkeyguy/Alissa_App/main/install/alissa.c"
#define VERSION 0.022   // version sub_version release patch

int app();

/*
    Auto-Update
*/

int install_update(char *cmd)
{
    if(strcmp(cmd, "temp")) {
        system("cp temp.app app.run && ./app.run app");
    }
    if(strcmp(cmd, "app")) {
        system("rm temp.app");
        app();
    }
    if(strcmp(cmd, "test")) {   // Skip update sequence
        app();
    }
    return 0;
}

int reg_update()
{
    system("echo \"Checking for updates.\"");
    // system("cp app.run temp.app && ./temp.app temp");
    // system("if (find *.run); then echo \"Seems to be updated.\"; else touch app.run; fi");
    system("curl -o temp.c https://raw.githubusercontent.com/cdmonkeyguy/Alissa_App/main/install/alissa.c && gcc temp.c -o temp.app && rm temp.c && ./temp.app temp");
    system("echo Update Complete.");
    return 0;
}

int auto_update()
{
    printf("Waiting to update...\n");
    sleep(7200);    // 2 Hours
    printf("Beginning Auto-Update Sequence.\n");
    reg_update();   // Update from master
    return 0;
}

/*
    ~Auto-Update
*/

int app()
{
    system("clear");
    printf("Welcome to your very own app!  This is the %.3f version.\n", VERSION);

    auto_update();
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc > 1) { install_update(argv[1]); printf("INSTALLING UPDATE!\n"); return -1; }
    if(argc <= 1) {
        printf("App is not ready...\n");
        reg_update();
    }

    return 0;
}

#endif