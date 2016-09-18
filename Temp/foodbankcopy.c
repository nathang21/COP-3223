#include <stdlib.h>
#include <stdio.h>
#include <string.h>


 main (void)
{

int choice, donation_amount[100], donation_quantity, donation_count=0, i, found, request_amount[100], request_quantity, request_count=0;
char word[20], donations_inv_type[100][20], request_inv_type[100][20];

                //Show user the menu
                printf("Welcome to the Food Bank Program\n\n 1. Enter a Donation\n 2. Enter a Request\n 3. Fulfill the Earliest Request\n 4. Print Status Report\n 5. Exit\n\nEnter Your Choice: ");
                scanf("%d", &choice);

                //Run selected option and keep on going until stopped.
                while (choice != 5)
    {





    //Execute enter a donation
    if (choice == 1)
    {

               //Ask user for inventory type and amount
                printf("\n  Making a Donation\n");
                printf("Enter inventory type: ");
                scanf("%s", &word);
                printf("Enter the amount: ");
                scanf("%d", &donation_quantity);
                found=-99;



                 //Is word in or not?

                  for(i=0; i<donation_count; i++)
                  {
                     if(strcmp(donations_inv_type[i], word)==0)
                     found=i;
                  }

                  if (found == -99)
                  {
                      strcpy(donations_inv_type[i], word);
                      donation_amount[i]=donation_quantity;
                      donation_count++;
                  }
                  else
                  {
                      donation_amount[found]+=donation_quantity;
                  }


                  //Show user that donation has been added

                  printf("\nDonation Added.\n\n");

    }





    //Execute enter a request

    else if (choice == 2){
                printf("\n  Making a Request   \n");
                //Ask user for inventory type and amount.
                printf("Enter inventory type:");
                scanf("%s", &word);
                printf("Enter the amount:");
                scanf("%d", &request_quantity);

                found=-99;

                //Is word in or not?

                  for(i=0; i<request_count; i++)
                  {
                      if(strcmp(request_inv_type[i], word)==0)
                      found=i;
                  }

                  if (found == -99)
                  {
                      strcpy(request_inv_type[i], word);
                      request_amount[i]=request_quantity;
                      request_count++;
                  }
                  else
                  {
                      request_amount[found]+=request_quantity;
                  }

                  printf("\nRequest Added\n\n");

    }





    //Execute Fulfill the earliest request

    else if (choice == 3)
    {

                //Check if request_count and donation count is 0
                if (request_count == 0)
                   {
                       //Message 1
                       printf("\nNo Requests have been made.\n\n");
                   }
                    else if (donation_count == 0)
                     {
                       //Message 2
                       printf("\nNo Donations have been made.\n\n");
                     }

                //Check if req_inv_type's 0 positi0n entry is not found in don_inv_type.

                else
                        {
                         found=-99;
                                   for (i=0; i<donation_count; i++)
                                    {
                                     if (strcmp(donations_inv_type[i],request_inv_type[0])==0)
                                      found=i;
                                    }

                                     if (found == -99)
                                     {
                                     //Message 3
                                     printf("\nCannot be Fulfilled, No %s has been donated yet.\n\n",request_inv_type[0] );
                                     }
                                     else
                                     {  //Show user that request was found and fulfilled.
                                        if (donation_amount[found]==request_amount[0])
                                        {
                                           //Message 4 #1
                                           printf("\nRequest Fulfilled\n\n");

                                           //Delete earliest request
                                           for (i=1;i<request_count;i++)
                                           {
                                               strcpy(request_inv_type[i-1], request_inv_type[i]);
                                               //Copy lower value into a higher position
                                               request_amount[i-1] = request_amount[i];
                                           }
                                           //Lower Request Count
                                           request_count--;

                                            //Delete Fulfilled Donation

                                            for (i=found; i<donation_count - 1; i++)
                                            {
                                                strcpy(donations_inv_type[i], donations_inv_type[i+1]);
                                                donation_amount[i]=donation_amount[i+1];
                                            }
                                            //Lower Donation Count
                                            donation_count--;
                                         }
                                        else if (donation_amount[found]>request_amount[0]){
                                              donation_amount[found] -= request_amount[0];
                                              //Reduce the donation table's amount
                                              //Remove Request
                                              for (i=1;i<request_count; i++)
                                              {
                                                   strcpy(request_inv_type[i-1], request_inv_type[i]);
                                                   //Copy the lower value into a higher position.
                                                   request_amount[i-1] = request_amount[i];
                                              }
                                              request_count -- ;

                                              //Message 4 #2
                                              printf("\nRequest Fulfilled\n\n");

                                         }
                                         else{
                                               // Remove Donation and Reduce Request
                                               request_amount[0] -= donation_amount[found];
                                               for (i=found;i<donation_count - 1;i++)
                                               {
                                                   strcpy(donations_inv_type[i], donations_inv_type[i+1]);
                                                   donation_amount[i]= donation_amount[i+1];
                                               }

                                               //Message 5
                                               printf("\nPartially Fulfilled\n\n");

                                               donation_count -- ;
                                         }
                                       }
                         }


    }






    //Execute print status report

   else if (choice == 4)
    {
                //Print Donation table
                printf("\nDonation Table\n\n");
                for(i=0; i<donation_count; i++)
                         {
                           printf("%s ", donations_inv_type[i]);
                           printf("%d \n", donation_amount[i]);
                         }
                //Print Request Table
                printf("\nRequest Table\n\n");
                for(i=0; i<request_count; i++)
                         {
                           printf("%s ", request_inv_type[i]);
                           printf("%d \n\n", request_amount[i]);
                         }
    }
    else
                //Show user error message for invalid entry.
                printf("\nNot a valid choice, entry must be between 1 and 5. Please try again.\n\n");

                //Repromt the menu
                printf("Welcome to the Food Bank Program\n\n 1.Enter a Donation\n 2.Enter a Request\n 3.Fulfill the Earliest Request\n 4.Print Status Report\n 5.Exit\n\nEnter Your Choice: ");
                scanf("%d", &choice);


    }
                //Print Goodbye Message
                printf("\n\nThank You for running the software. Bye for now\n\n");


system("pause");
return 0;
}
