#include <stdio.h>
#include <cstdlib>

int main() {

     int temp_score, game_score, total_score; 
     int level, done = 0; 

     total_score = 0; //Initialize player's total score.

     //Continue playing games until user fails to earn a free game     
     while (done == 0)
      {
          // Initialize player's game score and level.
          game_score = 0;
          
          // Tabulate game score for all 5 levels
          for (level=1; level<=5; level++) {
               printf("What was your score on level %d?\n",level);
               scanf("%d", &temp_score);
               game_score = game_score + temp_score;
          }
          
          // Compute new total score and stop if player has failed 
          // to earn a free game.
          total_score = total_score + game_score;
          if (game_score < 100000) 
               done = 1;
          else
                printf("Congratulations, you have won a free game!\n");
     }

     printf("Game Over! Your total score is %d\n", total_score);
     
system("pause");
     return 0;
}
