// Modified version to include entire Alphabet A-Z instead of just A-E.
// Only a few minor changes.
// Original program was coded to make this addition simple


#include <stdio.h>
#include <ctype.h>
int main()
{

    // Set all Variables
    int index, freq[26], c, stars, maxfreq;

      // Initialize all values on freq array to 0
      for (index=0; index<26; index++)
      {
        freq[index] = 0;
      }

      // Get Alphabet input from user, stop when 7 is detected
      while ( (c = getchar()) != '7')
        {
        if (isalpha(c))
                {
                    freq[tolower(c)-'a'] += 1;
                    freq[tolower(c)-'a' + 1]--;
                }
        }

      // Initizlizes maxfreq to 0 (or whatever the "Z which is 25" counter is at) temporarily
      maxfreq = freq[25];

      // Counts backward from Z checking each letter counter to find the maximum
      for (index = 25; index >= 0; index--)
      {
        if (freq[index] > maxfreq)
          maxfreq = freq[index];
      }

      // Utilizes the maxfreq value to determine the total length of stars+spaces overall
      // Then calculates how many stars each line should have
      // Prints out Visualization
      printf("Alphabet A-Z\n");
      for (index=0; index<26; index++)
      {
        for (stars=0; stars< (maxfreq - freq[index]); stars++)
           {
               // Prints Cooresponding # of Spaces per line
               printf(" ");
           }
        for (stars=0; stars< (freq[index]); stars++)
           {
               // Prints Cooresponding # of Starts per line
               printf("*");

           }

        // Prints Letter to signify the Row its on
        // Calulates the value by Adding the index value to the ASCII value of A
        printf("%c  \n", ('A' + index) );
        printf(" \n");

      }
      return 0;
}
