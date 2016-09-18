// Arup Guha
// 10/3/08
// Code from Array lecture for COP 3223 - reads in numbers into an array
//                                 and prints them out in reverse order.
int main() {

     int index, test_scores[5];
     
     // Read in scores into the array.
     printf("Please enter 5 test scores.\n");
     for (index=0; index < 5; index++)
          scanf("%d", &test_scores[index]);
     
      // Print them out by going through the array in backwards.
      printf("Here are the scores in reverse order: ");
      for (index=4; index >= 0; index--)
          printf("%d  ", test_scores[index]);
          
      system("PAUSE");
      return 0;

}
