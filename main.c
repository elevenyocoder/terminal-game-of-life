#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define I 20
#define J 20
#define T 50
int main(){

	int map[I][J];
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	bool b = true;
	char control = 0;

	for(i = 0;i < I;i++){ // fill map with 0
		for(j = 0;j < J;j++){
			map[i][j] = 0;
		}
	}
while(1) 
    {
        Sleep(T); // wait T milliseconds
        system("cls"); // clear terminal 
        if (kbhit())
        {
            control = getch(); //get keyboard input
            
            switch ((int)control){ 
                case 122: // Z key
                   if(y > 0){
                   		y--;
                   }    

                    break;
                case 115: // S key.
                	if(y < I-1){
                   		y++;
                   } 

                    break;
                case 113: // Q key.
                	if(x > 0){
                   		x--;
                   }    

                    break;
                case 100: // D key.
                	if(x < J-1){
                   		x++;
                   }        
                    
                    break;                    
                default:
                	break;                   
            }
        }
        map[x][y] = 1;

        for(i = 0;i < I;i++){ // print game
			for(j = 0;j < J;j++){
				if(map[j][i] == 1){
				 	printf("[]");
				}
				else{
					printf("  ");
				}
			}
			
			printf("\n");

		}
	map[x][y] = 0;

    }

	return 0;
}
