/*this project name is HMS */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define _Username_ "Admin" //Define a Default Username for Login
#define _Password_ "Admin" //Define a Default Password for Login

void modify_Room(int old);

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

struct User
{
    char Name[100];
    int age;
    char phoneNumber[12];
    int bookedRoomID;
    int days;
    double price;
    struct User *next;
} * userHead;

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

//modify function using by ID
void modify_Room(int old)
{

    int option;
    int floor;
    int bed;
    int window;
    char isBooked;
    double area;
    char AC;
    char VIP;

    FILE *fp, *temp;
    fp = fopen("db\\room.bin", "rb");
    temp = fopen("db\\TempRoom.bin", "wb"); //old value
    int pos = 0, key;                       //position and option change value variable

    struct room *current = (struct room *)malloc(sizeof(struct room));
    struct room *temp1 = (struct room *)malloc(sizeof(struct room));
    /* this codindition for first node or last node....
    I mean database has only one node then this condition will be run
    or database has last node to check then this condition will be run
    */
    while (fread(current, sizeof(*current), 1, fp) == 1)
    {

        if (current->roomId == old)
        {
            printf("-----------------------------------------------------------------------------------------\n");
            printf("| Room Id    | Floor  | Bed    | Window   | isBooked   | Area         | AC    | VIP     |\n");
            printf("-----------------------------------------------------------------------------------------\n");
            printf("| %-11d", current->roomId);
            printf("| %-7d", current->floor);
            printf("| %-7d", current->bed);
            printf("| %-9d", current->window);
            printf("| %-11c", current->isBooked);
            printf("| %-13.3lf", current->area);
            printf("| %-6c", current->AC);
            printf("| %-8c|\n", current->VIP);
            printf("-----------------------------------------------------------------------------------------\n");
            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf(" %d", &key);

            while (key == 1)
            {
                printf("\nChoose option for modifie\n");
                printf("--------------------------\n");
                printf("1. Floor change.\n");
                printf("2. Bed change\n");
                printf("3. Window change\n");
                printf("4. Booking change\n");
                printf("5. Area change\n");
                printf("6. AC change\n");
                printf("7. VIP\n");
                printf("8. Exit\n");
                printf("\nChange>> ");
                scanf(" %d", &option);
                if (option == 8)
                {
                    break;
                }

                switch (option)
                {
                case 1:
                    printf("Enter new Floor: ");
                    scanf("%d", &floor);
                    current->floor = floor;
                    break;
                case 2:
                    printf("Enter new Beds Number: ");
                    scanf("%d", &bed);
                    current->bed = bed;
                    break;
                case 3:
                    printf("Enter new Windows Number: ");
                    scanf("%d", &window);
                    current->window = window;
                    break;
                case 4:
                    printf("Upadate Booking: ");
                    scanf(" %c", &isBooked);
                    current->isBooked = isBooked;
                    break;
                case 5:
                    printf("Enter new Area of Room: ");
                    scanf("%lf", &area);
                    current->area = area;
                    break;
                case 6:
                    printf("Update AC Status: ");
                    scanf(" %c", &AC);
                    current->AC = AC;
                    break;
                case 7:
                    printf("Update VIP Status: ");
                    scanf(" %c", &VIP);
                    current->VIP = VIP;
                    break;
                default:
                    printf("\nYou have to choose right option\n");
                    break;
                }
            }
            fwrite(current, 1, sizeof(*current), temp);
        }
        else
        {
            fwrite(current, 1, sizeof(*current), temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("db\\room.bin");
    rename("db\\TempRoom.bin", "db\\room.bin");
}

void modify_RoomBook(int old)
{

    char Name[100];
    int age;
    char phoneNumber[12];
    int bookedRoomID;
    int days;
    double price;

    int option;
    FILE *fp, *temp;
    fp = fopen("db\\customer.bin", "rb");
    temp = fopen("db\\TempCustomer.bin", "wb"); //old value
    int pos = 0, key;                           //position and option change value variable

    struct User *current = (struct User *)malloc(sizeof(struct User));
    struct User *temp1 = (struct User *)malloc(sizeof(struct User));
    /* this codindition for first node or last node....
    I mean database has only one node then this condition will be run
    or database has last node to check then this condition will be run
    */
    while (fread(current, sizeof(*current), 1, fp) == 1)
    {

        if (current->bookedRoomID == old)
        {
            printf("Name: %s\n", current->Name);
            printf("Age: %d\n", current->age);
            printf("Phone Number: %s\n", current->phoneNumber);
            printf("Room Id: %d\n", current->bookedRoomID);
            printf("Days: %d\n", current->days);
            printf("Price: %lf\n", current->price);

            printf("\nDo You want to Modifie this Records?(1 = Yes, 2 = No)\n");
            printf("--------------------------------------------------------\n");
            scanf(" %d", &key);

            while (key == 1)
            {
                printf("\nChoose option for modifie\n");
                printf("--------------------------\n");
                printf("1. Name change.\n");
                printf("2. Age change\n");
                printf("3. Phone Number change\n");
                printf("4. Days change\n");
                printf("5. Price change\n");
                printf("6. Exit\n");
                printf("\nChange>> ");
                scanf(" %d", &option);
                if (option == 6)
                {
                    break;
                }

                switch (option)
                {
                case 1:
                    printf("Enter new Name: ");
                    getchar();
                    gets(Name);
                    strcpy(current->Name, Name);
                    break;
                case 2:
                    printf("Enter new Age: ");
                    scanf("%d", &age);
                    current->age = age;
                    break;
                case 3:
                    printf("Enter new Phone Number: ");
                    getchar();
                    gets(phoneNumber);
                    strcpy(current->phoneNumber, phoneNumber);
                    break;
                case 4:
                    printf("Upadate Days: ");
                    scanf(" %d", &days);
                    current->days = days;
                    break;
                case 5:
                    printf("Enter new Price: ");
                    scanf("%lf", &price);
                    current->price = price;
                    break;
                default:
                    printf("\nYou have to choose right option\n");
                    break;
                }
            }
            fwrite(current, 1, sizeof(*current), temp);
        }
        else
        {
            fwrite(current, 1, sizeof(*current), temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("db\\customer.bin");
    rename("db\\TempCustomer.bin", "db\\customer.bin");
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

void PrintUsersFromFile()
{
    struct User *temp_node;
    FILE *fp;
    temp_node = (struct User *)malloc(sizeof(struct User));
    userHead = temp_node;
    if ((fp = fopen("db\\customer.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    printf("\n\n                                         All Users Details                                     \n");

    while (fread(temp_node, sizeof(*temp_node), 1, fp) == 1)
    {
        printf("\n\nName: %s\n", temp_node->Name);
        printf("Age: %d\n", temp_node->age);
        printf("Phone Number: %s\n", temp_node->phoneNumber);
        printf("Room Id: %d\n", temp_node->bookedRoomID);
        printf("Days: %d\n", temp_node->days);
        printf("Price: %lf\n", temp_node->price);
        printf("-----------------------------------------------------------------------------------------\n");
    }
    fclose(fp);
}

void insert_User_at_last()
{
    FILE *fp;
    if ((fp = fopen("db\\customer.bin", "ab")) == NULL)
    {
        printf("\nCan't open file\n");
        exit(1);
    }
    int roomId;
    char Name[100];
    int age;
    char phoneNumber[12];
    int bookedRoomID;
    int days;
    double price;

    printf("\n\nEnter Customer Details.\n");
    printf("Name: ");
    getchar();
    gets(Name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Phone Number: ");
    getchar();
    gets(phoneNumber);
    printf("Enter Room Id: ");
    scanf("%d", &roomId);
    printf("Ho Many Days for Booked: ");
    scanf(" %d", &days);
    printf("Price: ");
    scanf(" %lf", &price);

    //store value in linklist
    struct User *temp_node;
    temp_node = (struct User *)malloc(sizeof(struct User));
    strcpy(temp_node->Name, Name);
    temp_node->age = age;
    strcpy(temp_node->phoneNumber, phoneNumber);
    temp_node->bookedRoomID = roomId;
    temp_node->days = days;
    temp_node->price = price;
    temp_node->next = NULL;
    fwrite(temp_node, sizeof(*temp_node), 1, fp);
    modify_Room(roomId);

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

    printf("Do You Want to Book Room? (y/n)\n");
    char op;
    scanf(" %c", &op);
    if (op == 'y')
    {
        insert_User_at_last();
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

//Delete  Record By ID
void delete_Room_Record()
{
    int value, key;
    FILE *fp, *temp;

    struct room *myNode = (struct room *)malloc(sizeof(struct room));

    int flag = 0;
    if ((fp = fopen("db\\room.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    if ((temp = fopen("db\\TempRoom.bin", "wb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    printf("Enter Room ID: ");
    scanf("%d", &value);
    while (fread(myNode, sizeof(*myNode), 1, fp) == 1)
    {

        if (myNode->roomId == value)
        {

            printf("\nDo you Really delete this Room Record\n");
            printf("-----------------------------------------------------------------------------------------\n");
            printf("| Room Id    | Floor  | Bed    | Window   | isBooked   | Area         | AC    | VIP     |\n");
            printf("-----------------------------------------------------------------------------------------\n");
            printf("| %-11d", myNode->roomId);
            printf("| %-7d", myNode->floor);
            printf("| %-7d", myNode->bed);
            printf("| %-9d", myNode->window);
            printf("| %-11c", myNode->isBooked);
            printf("| %-13.3lf", myNode->area);
            printf("| %-6c", myNode->AC);
            printf("| %-8c|\n", myNode->VIP);
            printf("-----------------------------------------------------------------------------------------\n");
            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {
                flag = 1;
            }
            else
            {
                fwrite(myNode, 1, sizeof(struct room), temp);
                flag = 1;
            }
        }
        else
        {
            fwrite(myNode, 1, sizeof(struct room), temp);
        }
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis ID not found!\n");
    fclose(fp);
    fclose(temp);
    remove("db\\room.bin");
    rename("db\\TempRoom.bin", "db\\room.bin");
}

void delete_User_Record()
{
    int value, key;
    int id;
    FILE *fp, *temp;

    struct User *myNode = (struct User *)malloc(sizeof(struct User));

    int flag = 0;
    if ((fp = fopen("db\\customer.bin", "rb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    if ((temp = fopen("db\\TempCustomer.bin", "wb")) == NULL)
    {
        printf("No such file\n");
        exit(1);
    }
    printf("Enter Room ID: ");
    scanf("%d", &value);
    while (fread(myNode, sizeof(*myNode), 1, fp) == 1)
    {

        if (myNode->bookedRoomID == value)
        {

            printf("\nDo you Really delete this Room Record\n\n");
            printf("Name: %s\n", myNode->Name);
            printf("Age: %d\n", myNode->age);
            printf("Phone Number: %s\n", myNode->phoneNumber);
            printf("Room Id: %d\n", myNode->bookedRoomID);
            printf("Days: %d\n", myNode->days);
            printf("Price: %lf\n", myNode->price);

            printf("\n\nFor Delete this record (type 1): ");
            scanf("%d", &key);
            //if user input = 1 then delete function will be work
            if (key == 1)
            {
                flag = 1;
                id = myNode->bookedRoomID;
                modify_Room(id);
            }
            else
            {
                fwrite(myNode, 1, sizeof(struct room), temp);
                flag = 1;
            }
        }
        else
        {
            fwrite(myNode, 1, sizeof(struct room), temp);
        }
    }

    if (flag == 0) // if user input not match with database this messege will be show
        printf("\nThis ID not found!\n");
    fclose(fp);
    fclose(temp);
    remove("db\\customer.bin");
    rename("db\\TempCustomer.bin", "db\\customer.bin");

    modify_Room(value);
}

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
    userHead = NULL;

    int option, option5, old;
    char name[15], pass[15];

    // system("CLS");
    printLogo();

    while (1)
    {
        printf("\nSelect Your Option From Menu.\n");
        printf("------------------------------\n");
        //Options for main Menu.
        printf("1.Rooms\n2.Room Book\n3.Edit Book\n4.Delete Book\n5.Admin Panel\n6.Exit\n");
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
            printf("\nEnter Room ID for modifie: ");
            scanf("%d", &old);
            modify_RoomBook(old);
            break;
        case 4:
            delete_User_Record();
            break;
        case 5:
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
                    printf("1.Add Room\n2.Edit Room \n3.Delete Room\n4.Show All Customers\n5.back\n");
                    printf("\nHMS>> ");
                    scanf("%d", &option5);
                    if (option5 == 5)
                    {
                        break;
                    }
                    switch (option5)
                    {
                    case 1:
                        insert_room_at_last();
                        break;
                    case 2:
                        printf("\nEnter Room ID for modifie: ");
                        scanf("%d", &old);
                        modify_Room(old);
                        break;
                    case 3:
                        delete_Room_Record();
                        break;
                    case 4:
                        PrintUsersFromFile();
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
        case 6:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}