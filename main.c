#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define I 30
#define J 30
#define T 50
int main(){
  
	int map[I][J];
	int i = 0;
	int j = 0;
	int x = 15;
	int y = 15;
	bool b = true;
  bool print = true;
	char control = 0;

  system("cls");


	for(i = 0;i < I;i++){
		for(j = 0;j < J;j++){
			map[i][j] = 0;
		}
	}
while(1){
      Sleep(T);
      if (kbhit())
      {
          control = getch();
            
          switch ((int)control){
              case 122: // Z key
                  if(y > 0){
                   	y--;
                  }    
                  print = true; 
                  break;
              case 115: // S key.
                if(y < I-1){
                   	y++;
                  } 
                  print = true;
                  break;
              case 113: // Q key.
                if(x > 0){
                   	x--;
                  }    
                  print = true;
                  break;
              case 100: // D key.
                if(x < J-1){
                   	x++;
                  }        
                  print = true;
                  break;                    
              default:
                	break;                   
            }
        }
        map[x][y] = 1;
        
        if(print == true){
          system("cls");
          for(i = 0;i < I;i++){
			       for(j = 0;j < J;j++){
				        if(map[j][i] == 1){                 
				 	        printf("\033[1;32m");
                  printf("@");
                  printf("\033[0;35m"); 
                  printf("|");
				        }
				        else{    
                  printf("\033[0;35m");         
					        printf("_|");                 
				        }
			       }
			
			     printf("\n");
        }
  print = false;
		    }
	map[x][y] = 0;
  print = false;

    }

	return 0;
}
