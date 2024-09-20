#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// functions
void generate__Bill__Header(char *name, char *date)
{
    printf("\n\n");
    printf("\t\t=======================================\n");
    printf("\t\t\t     R-RESTAURANT         \n");
    printf("\t\t=======================================\n");
    printf("\t\tDATE: %s\n", date);
    printf("\t\tORDER BY: %s\n", name);
    printf("\t\t---------------------------------------\n");
    printf("\t\tITEM\t\tQUANTITY\tTOTAL\n");
    printf("\t\t---------------------------------------\n");
}

void generate__bill__body(char *item, int quantity, float price)
{

    printf("\t\t%s\t\t%d\t\t$%.2f\n", item, quantity, price * quantity);
}

void generate__bill__footer(float total)
{
    float discount_amount = total * 0.1;
    float amount_after_discount = total - discount_amount;
    float cgst_amount = 0.09 * amount_after_discount;
    float final_bill_amount = amount_after_discount + 2 * cgst_amount;

    printf("\t\t---------------------------------------\n");
    printf("\t\t             Bill Summary         \n");
    printf("\t\t---------------------------------------\n");
    printf("\t\tTotal Amount:\t\t\t$%.2f\n", total);
    printf("\t\tDiscount (10%%):\t\t\t-$%.2f\n", discount_amount);
    printf("\t\tAmount After Discount:\t\t$%.2f\n", amount_after_discount);
    printf("\t\tCGST (9%%):\t\t\t$%.2f\n", cgst_amount);
    printf("\t\tSGST (9%%):\t\t\t$%.2f\n", cgst_amount);
    printf("\t\t=======================================\n");
    printf("\t\tFinal Bill Amount:\t\t$%.2f\n", final_bill_amount);
    printf("\t\t=======================================\n");
}

// struct

struct items
{
    char item[20];
    float price;
    int quantity;
};
struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

int main()
{
    // variables declaration
    float total;
    int option, number_of_items;
    // char saveOrder = 'n';
    char user_continue = 'y';

    struct orders order;
    // struct orders read_order;
    // FILE *fp;

    // programme

    while (user_continue == 'y' || user_continue == 'Y')
    {
        system("cls");
        printf("\n");
        printf("============================================\n");
        printf("\t    ORDER WITH R-RESTAURANT\n");
        printf("============================================\n");
        printf("\n");

        printf(" 1) CREATE ORDER\n");
        // printf("\n 2) GET ORDERS\n");
        // printf("\n 3) FIND ORDER\n");
        printf("\n 2) EXIT\n");

        printf("\n\t => CHOSE OPTION : ");
        scanf("%d", &option);
        fgetc(stdin);

        printf("\n============================================\n");
        switch (option)
        {
        case 1:
            // printf("\033[2J"); //to clean the window/terminal
            system("cls");
            printf("\nEnter Your Name Please : ");
            fgets(order.customer, 50, stdin);
            order.customer[strlen(order.customer) - 1] = 0;
            strcpy(order.date, __DATE__);

            printf("\nPlease Enter the Number of Items : ");
            scanf("%d", &number_of_items);
            order.numOfItems = number_of_items;

            printf("\n\t\t----\n");

            for (int i = 0; i < number_of_items; i++)
            {
                fgetc(stdin);
                printf("\nEnter the Item | %d | : ", i + 1);
                fgets(order.itm[i].item, 20, stdin);
                order.itm[i].item[strlen(order.itm[i].item) - 1] = 0;
                printf("\nEnter the Quantity : ");
                scanf("%d", &order.itm[i].quantity);
                printf("\nEnter the Price : ");
                scanf("%f", &order.itm[i].price);
                printf("\n\t\t----\n");

                total += order.itm[i].quantity * order.itm[i].price;
            }
            generate__Bill__Header(order.customer, order.date);
            for (int i = 0; i < order.numOfItems; i++)
            {
                generate__bill__body(order.itm[i].item, order.itm[i].quantity, order.itm[i].price);
            }
            generate__bill__footer(total);

            // printf("\n\n Do you want to save this order ? (y) | (n) : ");
            // scanf(" %c", &saveOrder);

            // if (saveOrder == 'y' || saveOrder == 'Y')
            // {
            //     fp = fopen("order.dat", "a+");

            //     if (fp == NULL)
            //     {
            //         printf("\nError: Could not open file for saving the order.");
            //         break;
            //     }
            //     fwrite(&order, sizeof(struct orders), 1, fp);

            //     if (fwrite != 0)
            //     {
            //         printf("\nYOUR ORDER SECCESSFULLY SAVED !!");
            //     }
            //     else
            //     {
            //         printf("\nAN ERROR WHILE SAVIND TRY AGAIN LATER");
            //     }

            //     fclose(fp);
            // }
            break;
            // case 2:
            //     system("cls");
            //     fp = fopen("order.dat", "r");

            //     if (fp == NULL)
            //     {
            //         printf("\nError: Could not open file for reading orders.");
            //         break;
            //     }
            //     printf("============================================\n");
            //     printf("\t      ***YOUR ORDERS***\n");
            //     printf("============================================\n");

            //     while (fread(&read_order, sizeof(struct orders), 1, fp))
            //     {
            //         float Total = 0;
            //         generate__Bill__Header(read_order.customer, read_order.date);
            //         for (int i = 0; i < read_order.numOfItems; i++)
            //         {
            //             generate__bill__body(read_order.itm[i].item, read_order.itm[i].quantity, read_order.itm[i].price);
            //             Total += read_order.itm[i].quantity * read_order.itm[i].price;
            //         }
            //         generate__bill__footer(Total);
            //     }
            //     fclose(fp);
            //     break;

        case 2:
            printf("\n COME BACK AGAIN :)");
            exit(0);
            break;

        default:
            printf("\n UNKOUWN OPTION");
            break;
        }

        printf("\n DO YOU WANT TO MAKE ANOTHER ORDER (y) | (n) : ");
        scanf(" %c", &user_continue);
    }

    printf("\n\n");
    printf("\n=================PROGRAMME-END===============\n");
    printf("\n\n");

    return 0;
}