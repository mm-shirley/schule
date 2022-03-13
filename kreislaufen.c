#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int readInt()
{
        while(1){
                int num;
                char term;

                int scanned_vars = scanf("%d%c", &num, &term );
                if(scanned_vars != 2 || term != '\n'){
                        printf("Invalid input. Please enter a number. \n");
                        scanf("%*[^\n]"); // remove unread input
                }else{
                        return num;
                }
        }
}

int main (void) {
 
	int totalSteps = 0;
	int steps = 0;
	int currentSteps = 0;
	int walls = 0;
	char goOnChoice[4];
	int roomLength;
        int roomWidth;
	int currentWallLength;
        int bombPosition; 

	printf("      ___       __   __         ___\n");
	printf("|  | |__  |    /  ` /  \\  |\\/| |__\n");
	printf("|/\\| |___ |___ \\__, \\__/  |  | |___\n\n"); 
                                    
	printf("Hello, before we start you need to set the length and width of the room. How long should the room be?\n");

	

        // Set room length
	
	roomLength = readInt();
	while (roomLength > 20 || roomLength < 5)  {
                printf("Maximum room length is 20, minimum is 5. Please enter again.\n");
               	roomLength = readInt();
        }       	
 

        // Set room width
        printf ("How wide should the room be?\n");
        roomWidth = readInt();
        while (roomWidth > 20 || roomWidth < 5) {
                printf("Maximum room width is 20, minimum is 5. Please enter again.\n");
                roomWidth = readInt();
        }


	// Set all 4 dimensions of the room
        int dimensions[] = {roomLength, roomWidth, roomLength, roomWidth};

        printf("You set the room to a length of %d and a width of %d.\n", roomLength, roomWidth);
	printf("---------------------------------------------------------------------------------------------\n");

	// Run main loop
	while(1){
		currentWallLength = dimensions[walls];
		bombPosition = rand() % currentWallLength - 1;

		// Walk steps
		while(steps < currentWallLength) {
                	printf("Now you can walk %d steps in this direction. Be careful there are some hidden bombs on your way.\nHow many steps do you want me to go?\n", currentWallLength - steps);
			currentSteps = readInt();
			if(steps + currentSteps < currentWallLength){
				printf("\n");
			} else if(steps + currentSteps > currentWallLength){
                        	printf("\nDoesn't work, you would hit the wall. Please enter a lower value.\n\n");
                        	continue;
                	} else if(currentSteps == currentWallLength) {
				printf("\nYou are not allowed to run the full number of steps at once.\n\n");
				continue;
			}
               		steps = steps + currentSteps;
			if(steps == bombPosition){
				printf("You ran into a bomb! Game Over\n");
				exit(0);
			}
			totalSteps = totalSteps + currentSteps;
        	}

		// Continue walking?
		if (steps == currentWallLength) {
			if(walls == 3){
				printf("---------------------------------------------------------------------------------------------\n");
				printf("You ran a lap!\n");				
				printf("Wanna go again?\n");
				walls = 0;
			}else{
				printf("---------------------------------------------------------------------------------------------\n");
                		printf("You have reached the %i. wall. Would you like to go on?\nType yes to continue walking or no to quit the program\n", walls + 1);
                		walls++;
			}
			scanf("%s", goOnChoice);
        	}
		
		while(strcmp(goOnChoice, "yes")  != 0  && strcmp(goOnChoice, "no") != 0){
                	printf("Invalid input. Please enter yes or no.\n");
                	scanf("%s", goOnChoice);
        	}
		if (strcmp(goOnChoice, "yes") == 0) {
			printf("---------------------------------------------------------------------------------------------\n");
			printf("Rotation\n");
		}else{
			printf("Quit game\n");
			break;
		}
		
		steps = 0;
	}
	printf("Total steps %d\n", totalSteps);
}

