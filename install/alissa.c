/**
 * @file alissa.c
 * @author Corbin Graham
 * @brief An app for Alissa!
 * @version 0.1
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


int reg_update()
{
    // Sleep (Seconds)
    // sleep(3600);    // 1 Hour
    system("echo \"Checking for updates.\"");
    
}

int main(int argc, char *argv[])
{
    printf("App is not ready...\n");

    reg_update();

    return 0;
}

#endif