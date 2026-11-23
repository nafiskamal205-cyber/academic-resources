
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DONORS 500

// Contact information
struct Contact
{
    char phone[20];
    char city[30];
    char area[50];
};

// Donor information
struct Donor
{
    int donorID;
    char name[50];
    int age;
    char gender[15];
    char bloodGroup[5];
    struct Contact contact;
};

// Global donor records
struct Donor donors[MAX_DONORS];
int donorCount = 0;
int nextDonorID = 1001;

// Function prototypes
void displayHeader(void);
void displayMenu(void);
void readText(char text[], int size);
void readNonEmpty(char text[], int size, char message[]);
int readInteger(char message[], int min, int max);
int sameText(const char a[], const char b[]);
void normalizeBloodGroup(char bloodGroup[]);
int isValidBloodGroup(char bloodGroup[]);
void loadDonors(void);
int saveDonors(void);
void displayDonor(struct Donor *donor);
void registerDonor(void);
void viewAllDonors(void);
void searchDonor(void);
void updateDonor(void);
int findDonorIndex(int donorID);

// Main function
int main(void)
{
    int choice;

    loadDonors();
    displayHeader();

    while(1)
    {
        displayMenu();

        choice = readInteger("Enter your choice: ", 1, 5);

        switch(choice)
        {
            case 1:
                registerDonor();
                break;

            case 2:
                viewAllDonors();
                break;

            case 3:
                searchDonor();
                break;

            case 4:
                updateDonor();
                break;

            case 5:
                printf("\n========================================\n");
                printf("       THANK YOU FOR USING OUR SYSTEM\n");
                printf("              GOODBYE!\n");
                printf("========================================\n");
                return 0;
        }
    }
}

// Display heading
void displayHeader(void)
{
    printf("\n============================================\n");
    printf("         BLOOD DONOR MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("          SAVE LIVES, DONATE BLOOD\n");
    printf("============================================\n");
}

// Display menu
void displayMenu(void)
{
    printf("\n============== MAIN MENU ==============\n");
    printf("1. Register New Donor\n");
    printf("2. View All Donors\n");
    printf("3. Search Donor\n");
    printf("4. Update Donor Information\n");
    printf("5. Exit\n");
    printf("=======================================\n");
}

// Read string input
void readText(char text[], int size)
{
    int ch;
    size_t length;

    if(fgets(text, size, stdin) != NULL)
    {
        length = strlen(text);

        if(length > 0 && text[length - 1] == '\n')
        {
            text[length - 1] = '\0';
        }
        else
        {
            while((ch = getchar()) != '\n' && ch != EOF)
            {
                // Clear extra input
            }
        }
    }
    else
    {
        text[0] = '\0';
    }
}

// Read non-empty string
void readNonEmpty(char text[], int size, char message[])
{
    while(1)
    {
        printf("%s", message);
        readText(text, size);

        if(strlen(text) > 0)
        {
            return;
        }

        printf("Input cannot be empty! Try again.\n");
    }
}

// Read integer with validation
int readInteger(char message[], int min, int max)
{
    char input[50];
    char *end;
    long value;

    while(1)
    {
        printf("%s", message);
        readText(input, sizeof(input));

        value = strtol(input, &end, 10);

        while(isspace((unsigned char)*end))
        {
            end++;
        }

        if(end != input && *end == '\0' &&
           value >= min && value <= max)
        {
            return (int)value;
        }

        printf("Invalid input! Enter a number between %d and %d.\n",
               min, max);
    }
}

// Compare strings without case sensitivity
int sameText(const char a[], const char b[])
{
    int i = 0;

    while(a[i] != '\0' && b[i] != '\0')
    {
        if(tolower((unsigned char)a[i]) !=
           tolower((unsigned char)b[i]))
        {
            return 0;
        }

        i++;
    }

    return a[i] == '\0' && b[i] == '\0';
}

// Convert blood group to uppercase
void normalizeBloodGroup(char bloodGroup[])
{
    int i;

    for(i = 0; bloodGroup[i] != '\0'; i++)
    {
        bloodGroup[i] = toupper((unsigned char)bloodGroup[i]);
    }
}

// Validate blood group
int isValidBloodGroup(char bloodGroup[])
{
    char validGroups[8][5] =
    {
        "A+", "A-", "B+", "B-",
        "AB+", "AB-", "O+", "O-"
    };

    int i;

    for(i = 0; i < 8; i++)
    {
        if(strcmp(bloodGroup, validGroups[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Load donor records
void loadDonors(void)
{
    FILE *file;

    file = fopen("donors.dat", "rb");

    if(file == NULL)
    {
        donorCount = 0;
        return;
    }

    donorCount = 0;

    while(donorCount < MAX_DONORS &&
          fread(&donors[donorCount],
                sizeof(struct Donor), 1, file) == 1)
    {
        if(donors[donorCount].donorID >= nextDonorID)
        {
            nextDonorID = donors[donorCount].donorID + 1;
        }

        donorCount++;
    }

    fclose(file);
}

// Save donor records
int saveDonors(void)
{
    FILE *file;

    file = fopen("donors.dat", "wb");

    if(file == NULL)
    {
        printf("\nFile opening error!\n");
        return 0;
    }

    if(fwrite(donors, sizeof(struct Donor),
              donorCount, file) != (size_t)donorCount)
    {
        printf("\nCould not save donor records!\n");
        fclose(file);
        return 0;
    }

    if(fclose(file) != 0)
    {
        printf("\nFile closing error!\n");
        return 0;
    }

    return 1;
}

// Display donor information
void displayDonor(struct Donor *donor)
{
    printf("\n========================================\n");
    printf("             DONOR INFORMATION\n");
    printf("========================================\n");

    printf("Donor ID    : %d\n", donor->donorID);
    printf("Name        : %s\n", donor->name);
    printf("Age         : %d\n", donor->age);
    printf("Gender      : %s\n", donor->gender);
    printf("Blood Group : %s\n", donor->bloodGroup);
    printf("Phone       : %s\n", donor->contact.phone);
    printf("City        : %s\n", donor->contact.city);
    printf("Area        : %s\n", donor->contact.area);

    printf("========================================\n");
}

// Register new donor
void registerDonor(void)
{
    struct Donor donor;

    if(donorCount >= MAX_DONORS)
    {
        printf("\nDonor storage is full!\n");
        return;
    }

    printf("\n========== REGISTER NEW DONOR ==========\n");

    donor.donorID = nextDonorID;

    printf("Donor ID: %d\n", donor.donorID);

    readNonEmpty(donor.name, sizeof(donor.name),
                 "Enter Donor Name: ");

    donor.age = readInteger("Enter Age: ", 1, 120);

    readNonEmpty(donor.gender, sizeof(donor.gender),
                 "Enter Gender: ");

    while(1)
    {
        readNonEmpty(donor.bloodGroup,
                     sizeof(donor.bloodGroup),
                     "Enter Blood Group (A+, A-, B+, B-, AB+, AB-, O+, O-): ");

        normalizeBloodGroup(donor.bloodGroup);

        if(isValidBloodGroup(donor.bloodGroup))
        {
            break;
        }

        printf("Invalid blood group! Try again.\n");
    }

    readNonEmpty(donor.contact.phone,
                 sizeof(donor.contact.phone),
                 "Enter Phone Number: ");

    readNonEmpty(donor.contact.city,
                 sizeof(donor.contact.city),
                 "Enter City: ");

    readNonEmpty(donor.contact.area,
                 sizeof(donor.contact.area),
                 "Enter Area: ");

    donors[donorCount] = donor;
    donorCount++;

    if(saveDonors())
    {
        nextDonorID++;

        printf("\nDonor registered successfully!\n");
        printf("Assigned Donor ID: %d\n", donor.donorID);
    }
    else
    {
        donorCount--;
        printf("\nRegistration failed!\n");
    }
}

// View all donors with complete information
void viewAllDonors(void)
{
    int i;

    printf("\n============== ALL DONORS ==============\n");

    if(donorCount == 0)
    {
        printf("\nNo donor records found!\n");
        return;
    }

    for(i = 0; i < donorCount; i++)
    {
        displayDonor(&donors[i]);
    }

    printf("\nTotal Donors: %d\n", donorCount);
}

// Find donor using ID
int findDonorIndex(int donorID)
{
    int i;

    for(i = 0; i < donorCount; i++)
    {
        if(donors[i].donorID == donorID)
        {
            return i;
        }
    }

    return -1;
}

// Search donor using blood group, city and area
void searchDonor(void)
{
    char bloodGroup[5];
    char city[30];
    char area[50];

    int i;
    int found = 0;

    printf("\n========== SEARCH DONOR ==========\n");

    readNonEmpty(bloodGroup, sizeof(bloodGroup),
                 "Enter Blood Group: ");

    normalizeBloodGroup(bloodGroup);

    if(!isValidBloodGroup(bloodGroup))
    {
        printf("\nInvalid blood group!\n");
        return;
    }

    readNonEmpty(city, sizeof(city),
                 "Enter City: ");

    readNonEmpty(area, sizeof(area),
                 "Enter Area: ");

    printf("\n========== SEARCH RESULTS ==========\n");
    printf("Blood Group : %s\n", bloodGroup);
    printf("City        : %s\n", city);
    printf("Area        : %s\n", area);

    for(i = 0; i < donorCount; i++)
    {
        if(strcmp(donors[i].bloodGroup, bloodGroup) == 0 &&
           sameText(donors[i].contact.city, city) &&
           sameText(donors[i].contact.area, area))
        {
            displayDonor(&donors[i]);
            found = 1;
        }
    }

    if(!found)
    {
        printf("\nNo donor found with these details!\n");
    }
}

// Update donor information
void updateDonor(void)
{
    int donorID;
    int index;

    struct Donor oldDonor;

    printf("\n========== UPDATE DONOR INFORMATION ==========\n");

    if(donorCount == 0)
    {
        printf("\nNo donor records available!\n");
        return;
    }

    donorID = readInteger("Enter Donor ID: ", 1, 1000000);

    index = findDonorIndex(donorID);

    if(index == -1)
    {
        printf("\nDonor not found!\n");
        return;
    }

    oldDonor = donors[index];

    printf("\nCurrent Donor Information:");
    displayDonor(&donors[index]);

    printf("\nEnter Updated Information:\n");

    readNonEmpty(donors[index].name,
                 sizeof(donors[index].name),
                 "Enter New Name: ");

    donors[index].age = readInteger("Enter New Age: ", 1, 120);

    readNonEmpty(donors[index].gender,
                 sizeof(donors[index].gender),
                 "Enter New Gender: ");

    while(1)
    {
        readNonEmpty(donors[index].bloodGroup,
                     sizeof(donors[index].bloodGroup),
                     "Enter New Blood Group: ");

        normalizeBloodGroup(donors[index].bloodGroup);

        if(isValidBloodGroup(donors[index].bloodGroup))
        {
            break;
        }

        printf("Invalid blood group! Try again.\n");
    }

    readNonEmpty(donors[index].contact.phone,
                 sizeof(donors[index].contact.phone),
                 "Enter New Phone Number: ");

    readNonEmpty(donors[index].contact.city,
                 sizeof(donors[index].contact.city),
                 "Enter New City: ");

    readNonEmpty(donors[index].contact.area,
                 sizeof(donors[index].contact.area),
                 "Enter New Area: ");

    if(saveDonors())
    {
        printf("\nDonor information updated successfully!\n");
        displayDonor(&donors[index]);
    }
    else
    {
        donors[index] = oldDonor;
        printf("\nUpdate failed! Old information restored.\n");
    }
}

