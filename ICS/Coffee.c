
#include <stdio.h>

#define SIZE 7

// Coffee names and prices
char *coffeeNames[SIZE] = {
    "Espresso",
    "Americano",
    "Cappuccino",
    "Latte",
    "Mocha",
    "Cold Coffee",
    "Frappe"
};

float coffeePrices[SIZE] = {
    120, 150, 180, 200, 220, 180, 250
};

int quantities[SIZE] = {0};

// Function declarations
void displayMenu(void);
void takeOrder(void);
void generateBill(void);

int main()
{
    printf("================================================\n");
    printf("                 COFFEE HOUSE\n");
    printf("             FRESH COFFEE, FRESH MOMENTS\n");
    printf("================================================\n");
    printf("              COFFEE SHOP BILLING SYSTEM\n");
    printf("================================================\n");

    printf("\nPress ENTER to create a new bill...");
    getchar();

    takeOrder();
    generateBill();

    return 0;
}

// Display coffee menu
void displayMenu(void)
{
    int i;

    printf("\n================= COFFEE MENU =================\n");
    printf(" No.       Coffee Name             Price\n");
    printf("------------------------------------------------\n");

    for (i = 0; i < SIZE; i++)
    {
        printf(" %d.        %-20s Tk. %.2f\n",
               i + 1, coffeeNames[i], coffeePrices[i]);
    }

    printf(" 0.        Finish\n");
    printf("================================================\n");
}

// Take coffee orders
void takeOrder(void)
{
    int choice, quantity;

    do
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("\nOrder completed!\n");
        }
        else if (choice >= 1 && choice <= SIZE)
        {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity > 0)
            {
                quantities[choice - 1] += quantity;

                printf("\nSelected Item: %s\n",
                       coffeeNames[choice - 1]);

                printf("Price: Tk. %.2f\n",
                       coffeePrices[choice - 1]);

                printf("Quantity: %d\n", quantity);

                printf("Item Total: Tk. %.2f\n",
                       coffeePrices[choice - 1] * quantity);
            }
            else
            {
                printf("Invalid quantity! Try again.\n");
            }
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);
}

// Calculate bill and print receipt
void generateBill(void)
{
    int i, hasOrder = 0;
    static int orderNumber = 1;

    float subtotal = 0;
    float discount = 0;
    float vat = 0;
    float totalBill;
    float cash, change;

    // Calculate subtotal
    for (i = 0; i < SIZE; i++)
    {
        subtotal += coffeePrices[i] * quantities[i];

        if (quantities[i] > 0)
        {
            hasOrder = 1;
        }
    }

    if (hasOrder == 0)
    {
        printf("\nNo items selected. Bill cancelled.\n");
        return;
    }

    // Calculate discount
    if (subtotal >= 500)
    {
        discount = subtotal * 0.05;
    }

    // Calculate VAT after discount
    vat = (subtotal - discount) * 0.05;

    // Calculate final bill
    totalBill = subtotal - discount + vat;

    // Display bill summary
    printf("\n================================================\n");
    printf("                  BILL SUMMARY\n");
    printf("================================================\n");

    printf("Subtotal:                  Tk. %.2f\n", subtotal);
    printf("Discount (5%%):             Tk. %.2f\n", discount);
    printf("VAT (5%%):                  Tk. %.2f\n", vat);

    printf("------------------------------------------------\n");
    printf("TOTAL BILL:                Tk. %.2f\n", totalBill);
    printf("================================================\n");

    // Receive cash
    do
    {
        printf("\nEnter received cash: Tk. ");
        scanf("%f", &cash);

        if (cash < totalBill)
        {
            printf("Insufficient cash! Please enter again.\n");
        }

    } while (cash < totalBill);

    // Calculate change
    change = cash - totalBill;

    // Print final receipt
    printf("\n================================================\n");
    printf("                 COFFEE HOUSE\n");
    printf("                 CUSTOMER RECEIPT\n");
    printf("================================================\n");

    printf("Order No: %03d\n", orderNumber++);

    printf("------------------------------------------------\n");
    printf("Coffee Name          Qty        Total\n");
    printf("------------------------------------------------\n");

    for (i = 0; i < SIZE; i++)
    {
        if (quantities[i] > 0)
        {
            printf("%-20s %-10d Tk. %.2f\n",
                   coffeeNames[i],
                   quantities[i],
                   coffeePrices[i] * quantities[i]);
        }
    }

    printf("------------------------------------------------\n");

    printf("Subtotal:                  Tk. %.2f\n", subtotal);
    printf("Discount:                  Tk. %.2f\n", discount);
    printf("VAT:                       Tk. %.2f\n", vat);

    printf("------------------------------------------------\n");

    printf("TOTAL BILL:                Tk. %.2f\n", totalBill);
    printf("Cash Received:             Tk. %.2f\n", cash);
    printf("Change:                    Tk. %.2f\n", change);

    printf("================================================\n");
    printf("             THANK YOU FOR VISITING!\n");
    printf("                PLEASE COME AGAIN\n");
    printf("================================================\n");
}

