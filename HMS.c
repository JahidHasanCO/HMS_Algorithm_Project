/*this project name is HMS */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin" //Define a Default Username for Login
#define _Password_ "Admin" //Define a Default Password for Login

struct room
{
    int roomId;
    int floor;
    int bed;
    int window;
    char isBooked;
    double area;
    char AC;
    char VIP;
    struct room *next;
} * head, *tail, *mod, *mid;

// login section
bool loginCheck(char name[], char pass[])

{
    if (strcmp(name, _Username_) == 0) //checking input Username to stored Username
    {
        if (strcmp(pass, _Password_) == 0) //checking input password to stroed Password
        {
            return true; //if Username and Password are matched then it returns a truth value
        }
    }
    else
    {
        return false; //if Username and Password are not matched then it returns a flase value
    }
}

int checkRoomID()
{
    int id;
    struct room *temp_node;
    FILE *fp;
    temp_node = (struct room *)malloc(sizeof(struct room));
    head = temp_node;
    if ((fp = fopen("db\\room.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    while (fread(temp_node, sizeof(*temp_node), 1, fp) == 1)
    {
        id = temp_node->roomId;
    }
    return id;
}

void PrintRoomFromFile()
{
    struct room *temp_node;
    FILE *fp;
    temp_node = (struct room *)malloc(sizeof(struct room));
    head = temp_node;
    if ((fp = fopen("db\\room.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    printf("\n\n                                         All Room Details                                     \n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| Room Id    | Floor  | Bed    | Window   | isBooked   | Area         | AC    | VIP     |\n");
    printf("-----------------------------------------------------------------------------------------\n");
    while (fread(temp_node, sizeof(*temp_node), 1, fp) == 1)
    {
        printf("| %-11d", temp_node->roomId);
        printf("| %-7d", temp_node->floor);
        printf("| %-7d", temp_node->bed);
        printf("| %-9d", temp_node->window);
        printf("| %-11c", temp_node->isBooked);
        printf("| %-13.3lf", temp_node->area);
        printf("| %-6c", temp_node->AC);
        printf("| %-8c|\n", temp_node->VIP);
        printf("-----------------------------------------------------------------------------------------\n");
    }
    fclose(fp);
}

void PrintAvilAbleRoomFromFile()
{
    struct room *temp_node;
    FILE *fp;
    temp_node = (struct room *)malloc(sizeof(struct room));
    head = temp_node;
    if ((fp = fopen("db\\room.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    printf("\n\n                                  Avilable Room Details                              \n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("| Room Id    | Floor  | Bed    | Window   | isBooked   | Area         | AC    | VIP     |\n");
    printf("-----------------------------------------------------------------------------------------\n");
    while (fread(temp_node, sizeof(*temp_node), 1, fp) == 1)
    {
        if (temp_node->isBooked == 'n')
        {
            printf("| %-11d", temp_node->roomId);
            printf("| %-7d", temp_node->floor);
            printf("| %-7d", temp_node->bed);
            printf("| %-9d", temp_node->window);
            printf("| %-11c", temp_node->isBooked);
            printf("| %-13.3lf", temp_node->area);
            printf("| %-6c", temp_node->AC);
            printf("| %-8c|\n", temp_node->VIP);
            printf("-----------------------------------------------------------------------------------------\n");
        }
    }
    fclose(fp);
}

void insert_room_at_last()
{
    FILE *fp;
    if ((fp = fopen("db\\room.bin", "ab")) == NULL)
    {
        printf("\nCan't open file\n");
        exit(1);
    }
    int roomId;
    int floor;
    int bed;
    int window;
    double area;
    char AC;
    char VIP;
    //scanning all details of employee
    printf("Enter Details for Room.\n");
    while (1)
    {
        printf("Enter Room Id: ");
        scanf("%d", &roomId);
        if (roomId > checkRoomID())
        {
            break;
        }
        else
        {
            printf("Enter Room Id Larger Than %d\n", checkRoomID());
        }
    }

    printf("Enter Floor: ");
    scanf("%d", &floor);
    printf("Enter Number of bed: ");
    scanf("%d", &bed);
    printf("Enter number of Window: ");
    scanf("%d", &window);
    printf("Enter Area of Room: ");
    scanf("%lf", &area);
    printf("Have AC (y/n): ");
    scanf(" %c", &AC);
    printf("VIP Room (y/n): ");
    scanf(" %c", &VIP);

    //store value in linklist
    struct room *temp_node;
    temp_node = (struct room *)malloc(sizeof(struct room));
    temp_node->roomId = roomId;
    temp_node->floor = floor;
    temp_node->bed = bed;
    temp_node->window = window;
    temp_node->isBooked = 'n';
    temp_node->area = area;
    temp_node->AC = AC;
    temp_node->VIP = VIP;
    temp_node->next = NULL;
    fwrite(temp_node, sizeof(*temp_node), 1, fp);
    fclose(fp);
}


// //Delete Employees Record By ID
// void search_Room_Record()
// {
//     struct room *temp_node;
//     FILE *fp;
//     temp_node = (struct room *)malloc(sizeof(struct room));

//     if ((fp = fopen("db\\room.bin", "rb")) == NULL)
//     {
//         printf("No such file\n");
//     }
//     fread(temp_node, sizeof(*temp_node), 1, fp);
//     head = temp_node;
//     int value, key;
//     printf("Enter ID: ");
//     scanf("%d", &value);
//     if (0)
//     {
//         printf("\nNot Found\n");
//         mid = NULL;
//     }
//     else
//     {
//         printf("\n\n                                     Search Result                                   \n");
//         printf("-----------------------------------------------------------------------------------------\n");
//         printf("| Room Id    | Floor  | Bed    | Window   | isBooked   | Area         | AC    | VIP     |\n");
//         printf("-----------------------------------------------------------------------------------------\n");
//         printf("| %-11d", mid->roomId);
//         printf("| %-7d", mid->floor);
//         printf("| %-7d", mid->bed);
//         printf("| %-9d", mid->window);
//         printf("| %-11c", mid->isBooked);
//         printf("| %-13.3lf", mid->area);
//         printf("| %-6c", mid->AC);
//         printf("| %-8c|\n", mid->VIP);
//         printf("-----------------------------------------------------------------------------------------\n");
//         mid = NULL;
//     }
// }

// logo function
void printLogo()
{
    //logo using ascii codes

    printf("                      _    _ __  __  _____ \n");
    printf("                     | |  | |  \\/  |/ ____|\n");
    printf("                     | |__| | \\  / | (___  \n");
    printf("                     |  __  | |\\/| |\\___ \\ \n");
    printf("                     | |  | | |  | |____) |\n");
    printf("                     |_|  |_|_|  |_|_____/ \n");
    printf("------------------------------HMS--------------------------\n");
    printf("             a powerfull Hotel management tool           \n");
    printf("                        @jahidhasanCO                      \n");
    printf("\n\n");
}

int main()
{
    head = NULL; //declareing head to Null
    tail = NULL; //Declaring tail to Null
    mod = NULL;
    mid = NULL;

    int option, option6;
    char name[15], pass[15];

    // system("CLS");
    printLogo();

    while (1)
    {
        printf("\nSelect Your Option From Menu.\n");
        printf("------------------------------\n");
        //Options for main Menu.
        printf("1.Rooms\n2.Room Book\n3.Search Book\n4.Edit Book\n5.Delete Room\n6.Admin Panel\n7.Exit\n");
        printf("\nHMS>> ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            PrintRoomFromFile();
            break;
        case 2:
            PrintAvilAbleRoomFromFile();
            break;
        case 3:
            // search_Room_Record();
            break;
        case 4:
            break;
        case 6:
            //this is main loop.
            printf("You need to login first.\n");
            printf("Username: ");
            getchar();
            gets(name); //input username for login
            printf("Password: ");
            gets(pass);
            if (loginCheck(name, pass))
            {
                while (1)
                {
                    printf("\nSelect Option.\n");
                    printf("------------------------------\n");
                    //Options for main Menu.
                    printf("1.Add Room\n2.Edit Room \n3.Delete Room\n4.back\n");
                    printf("\nHMS>> ");
                    scanf("%d", &option6);
                    if (option6 == 4)
                    {
                        break;
                    }
                    switch (option6)
                    {
                    case 1:
                        insert_room_at_last();
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
            }
            break;
        case 7:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}