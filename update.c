// V 1
/**
 * @file alissa.c
 * @author Corbin Graham
 * @brief An app for Alissa!
 * @version 0.110
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
#include <time.h>

// Macros
#define URL "https://raw.githubusercontent.com/cdmonkeyguy/Alissa_App/main/install/alissa.c"
#define VERSION 0.110   // version sub_version release patch

int app();

/*
    Auto-Update
*/

int reg_update()
{
    system("echo \"Checking for updates.\"");
    // system("cp app.run temp.app && ./temp.app temp");
    // system("if (find *.run); then echo \"Seems to be updated.\"; else touch app.run; fi");
    system("curl -o temp.c https://raw.githubusercontent.com/cdmonkeyguy/Alissa_App/main/install/alissa.c && gcc temp.c -o temp.app && rm temp.c && ./temp.app temp");
    system("echo Update Complete.");
    return 0;
}

int install_update(char *cmd)
{
    if(!strcmp(cmd, "start")) {   // Initial
        reg_update();
    }
    else if(!strcmp(cmd, "temp")) {
        printf("Calling Temp.\n");
        system("cp temp.app app.run && ./app.run app");
    }
    else if(!strcmp(cmd, "app")) {
        printf("Calling App.\n");
        system("rm temp.app");
        app();
    }
    else if(!strcmp(cmd, "test")) {   // Skip update sequence
        app();
    }
    return 0;
}

int auto_update()
{
    printf("Waiting to update...\n");
    // sleep(7200);    // 2 Hours
    sleep(30);
    printf("Beginning Auto-Update Sequence.\n");
    reg_update();   // Update from master
    return 0;
}

/*
    ~Auto-Update
*/

char *random_pickup_line()
{
    char *pickups[] = {
        "Well, here I am. What are your other two wishes?",
        "Hey, my name's Microsoft. Can I crash at your place tonight?",
        "Are you French? Because Eiffel for you.",
        "Do you like raisins? How do you feel about a date?",
        "There is something wrong with my cell phone. It doesn't have your number in it.",
        "If I could rearrange the alphabet, I’d put ‘U’ and ‘I’ together.",
        "Aside from being sexy, what do you do for a living?",
        "I must be a snowflake, because I've fallen for you.",
        "Are you from Tennessee? Because you're the only 10 I see!",
        "If you were a Transformer… you’d be Optimus Fine.",
        "Are you a parking ticket? Because you’ve got FINE written all over you.",
        "I wish I were cross-eyed so I can see you twice.",
        "I must be in a museum, because you truly are a work of art."
    };
    int pickup_size = (sizeof(pickups) / sizeof(pickups[0]));
    int i = (rand() %
           (pickup_size + 1));
    char *line = pickups[i];
    return line;
}

int display_popup(char message[1000])
{
    // 1000c ~ 300 words
    // Maximum size (100) + message(1000)
    char output[1100] = "";
    strcat(output, "osascript -e \'tell app \"System Events\" to display dialog \"");
    strcat(output, message);
    strcat(output, "\"\'");
    system(output);
    return 0;
}

int app()
{
    system("clear");
    printf("Hey cutie!  Welcome to your very own app!  This is the version %.3f!\n", VERSION);

    display_popup(random_pickup_line());
    // printf("Enter a command: ");
    // char in[50];
    // scanf("%s", in);
    // printf("%s\n", in);
    auto_update();
    return 0;
}

int main(int argc, char *argv[])
{
    // if(!strcmp("test", "test")) printf("%d\n", strcmp("test", "test"));
    // printf("%d\n", strcmp("test", "temp"));
    // printf("%d\n", strcmp("test", "app"));
    // printf("%d\n", strcmp("test", "start"));
    // return 0;

    srand(time(NULL));

    if(argc <= 1) return install_update("test");
    if(argc > 1) return install_update(argv[1]);

    return -1;
}

#endif