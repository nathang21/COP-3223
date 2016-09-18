// Nathan Guenther
// COP 3223 Section 0001
// Assignment 3
// 10/9/13
// Runs a food bank inventory system for donations, requests, and reports all user selectable.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() // START Main
{
    //   SET ALL THE VARIABLES, ARRAYS & COUNTERS   //
    //----------------------------------------------//
    int option, i, found;
    int donammount[100], doncount = 0, reqammount[100], reqcount = 0, tempammount;
    char dontype[100][20], reqtype[100][20], temptype[20];


    // Display First Time Menu

    //----------------------------------------------//
    //****************** MAIN MENU *****************//
    //                   ---------                  //
    // Displays menu and reads in user's selection  //
    //                                              //
    //--------------------INPUT---------------------//
    printf("Welcome to the Food Bank Program.\n\n");
    printf("1. Add a Donation\n2. Add a Request\n3. Fulfill the earliest Request\n4. Print status report\n5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    // Initialize Array's to 0
    for (i = 0; i < 100; i++)
    {
        donammount[i] = 0;
        reqammount[i] = 0;
    }


    //----------------------------------------------//
    //   ****         MAIN WHILE LOOP        ****   //
    // Allows options to be selected multiple times //
    //----------------------------------------------//
    while (option != 5)
    {
        // _______________ //
        // Make a Donation //
        // *************** //
        if (option == 1)
        {
            // Donation Information
            //----------INPUT---------//
            printf("\nEnter inventory type: ");
            scanf("%s", &temptype);
            printf("Enter the ammount: ");
            scanf("%d", &tempammount);
            found = -99;

            // Check if donation type already exists and adds to list
            for (i = 0; i < doncount; i++)
            {
                if (strcmp(dontype[i], temptype) == 0)
                {
                    found = i;
                }
            }

            // Add New Donation to the List
            if (found == -99)
            {
                strcpy(dontype[i], temptype);
                donammount[i] = tempammount;

                // Raise Donation Count
                doncount++;
            }
            else
            {
                // If donation already present, add to current ammount
                donammount[found] += tempammount;
            }

            // Success
            //----------OUTPUT---------//
            printf("\nDonation Added!\n");
            system("pause");
            printf("\n");

        } // END // Make a Donation

        // _______________ //
        // Make a Request  //
        // *************** //
        else if (option == 2)
        {
            for(i = reqcount; i < reqcount + 1; i++)
            {
                // Request Information
                //----------INPUT---------//
                printf("\nEnter inventory type: ");
                scanf("%s", &temptype);
                printf("Enter the ammount: ");
                scanf("%d", &tempammount);

                strcpy(reqtype[i], temptype);
                reqammount[i] = tempammount;


                // Success
                //----------OUTPUT---------//
                printf("\nRequest Added!\n");
                system("pause");
                printf("\n");
            }

            // Raise Request Count
            reqcount++;

        } // END // Make a Request

        // _________________ //
        // Fulfill a Request //
        // ***************** //
        else if (option == 3)
        {
            printf("\n--------Fulfilling Requests--------\n");

            // Check if no doantions or requests are present
            if (reqcount == 0 && doncount == 0)
            {
                // No Requests or Donations Present
                //----------OUTPUT---------//
                printf("\n\nNo Requests or Donations have been made.\n\n\n");
            }

            else if (reqcount == 0)
            {
                // No Requests Present
                //----------OUTPUT---------//
                printf("\n\nNo Requests have been made.\n\n\n");
            }

            else if (doncount == 0)
            {
                // No Donations Present
                //----------OUTPUT---------//
                printf("\n\nNo Donations have been made.\n\n\n");
            }

            // Search donation database for the current request
            // Check how to handle request
            else
            {
               found = -99;

               // Search inventory
               for (i = 0; i < doncount; i++)
               {
                   if (strcmp(dontype[i], reqtype[0]) == 0)
                   {
                       found = i;
                   }
               }

               // Donation doesn't exist in inventory
               if (found == -99)
               {
                   // Failure
                   //----------OUTPUT---------//
                    printf("\nRequest Cannot be Fulfilled\n\n");
               }

                // Donation exist's in inventory
                else
                {
                    // If Request ammount is exactly the donation inventory
                    if (donammount[found] == reqammount[0])
                    {
                        // Output Success
                        printf("\nRequest Fulfilled\n\n");

                        // Delete the completed Request
                        for (i = 1; i < reqcount; i++)
                        {
                        // Move Request list up to fill in new empty space
                        strcpy(reqtype[i-1], reqtype[i]);
                        reqammount[i-1] = reqammount[i];
                        }

                        // Lower Request Count
                        reqcount--;

                        // Delete Fulfilled Donation
                        for (i = found; i < doncount - 1; i++)
                        {
                        strcpy(dontype[i], dontype[i+1]);
                        donammount[i] = donammount[i+1];
                        }

                        // Lower Donation Count
                        doncount--;
                    }

                    // If Request is smaller than Donation Inventory
                    else if (donammount[found] > reqammount[0])
                    {
                        // Subtract request from current inventory
                        donammount[found] -= reqammount[0];

                        // Delete the completed Request
                        for (i = 1; i < reqcount; i++)
                        {
                            // Move Request list up to fill in new empty space
                            strcpy(reqtype[i-1], reqtype[i]);
                            reqammount[i-1] = reqammount[i];
                        }

                        // Lower Request Count
                        reqcount--;

                        // Success
                        //----------OUTPUT---------//
                        printf("\nRequest Fulfilled\n\n");
                    }

                   // If donation is less than Request
                   else
                   {
                       // Subtract inventory ammount from Request
                       reqammount[0] -= donammount[found];

                       // Delete the used donation inventory
                       for (i = found; i < doncount - 1; i++)
                       {
                           strcpy(dontype[i], dontype[i+1]);
                           donammount[i] = donammount[i+1];
                       }

                       // Partial Success
                       //----------OUTPUT---------//
                       printf("\nRequest Partially Fulfilled\n\n");
                       doncount--;

                   } // END // If donation is less than Request

                } // END // Donation exist's in inventory

            } // END // Search donation database for the current request
             //     // Check how to handle request
                system("pause");
                printf("\n");

        } // END // Fufill Request

        // ____________________ //
        // Print Status Report  //
        // ******************** //
        else if (option == 4)
        {
            // Output Print Donations
            printf("\nPrinting the Donations Table\n\n");
            for(i = 0; i < doncount; i++)
            {
                printf("\t\t%s  ", dontype[i]);
                printf("%d", donammount[i]);
                printf("\n");
            }

            // Output Print Requests
            printf("\nPrinting the Requests Table\n\n");
            for(i = 0; i < reqcount; i++)
            {

                printf("\t\t%s  ", reqtype[i]);
                printf("%d", reqammount[i]);
                printf("\n");
            }

            printf("\n");
            system("pause");
            printf("\n");

        } // END // Print Status Report


        // _______________ //
        //       Exit      //
        // *************** //
        else if (option != 5)
        {
            // Output Error for invalid Option
            printf("\nSorry that is not a valid menu option.\n\n");

        } // End // Exit


        // End of Menu Options


        // Re-display Menu after finishing option
        //----------------------------------------------//
        //****************** MAIN MENU *****************//
        //                   ---------                  //
        // Displays menu and reads in user's selection  //
        //                                              //
        //--------------------INPUT---------------------//
        printf("Welcome to the Food Bank Program.\n\n");
        printf("1. Add a Donation\n2. Add a Request\n3. Fulfill the earliest Request\n4. Print status report\n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

    } // End of While Loop for Menu


    // Output Final Goodbye Message
    printf("\n\nThank You for using the software. Bye for now.\n\n");


    system("pause");
    return 0;

} // END MAIN
