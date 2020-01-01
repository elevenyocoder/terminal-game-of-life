#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define I 30
#define J 30
#define T 1
#define TG 500
int main(){
  
	int map[I][J];
	int i = 0;
	int j = 0;
	int x = 15;
	int y = 15;
  int gen = 0 ;
  int somme = 0;
  bool go = true;
  bool put = false;
	bool b = true;
  bool print = true;

	char control = 0;

  system("cls");


	for(i = 0;i < I;i++){
		for(j = 0;j < J;j++){
			map[i][j] = 0;
		}
	}
while(go){
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
              case 99: // put cellule (C key). 
                  map[x][y] = 2;        
                  put = true;                     
                  print = true;                  
                  break;

              case 32: // run simulation (space key).
                  go = false;
                  print = true;                  
                  break;  

              default:
                	break;                   
            }
        }

        if(print == true){
          if(put == true){
            map[x][y] = 2;
          }     
          else{
            map[x][y] = 1;
          }
          system("cls");
          for(i = 0;i < I;i++){
			       for(j = 0;j < J;j++){
				        if(map[j][i] == 1 ||map[j][i] == 2){                 
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

		    }
  if(map[x][y] == 1){
    map[x][y]=0;

  }       	 
  
  print = false;
  put = false;

  }


  while(1){
    gen ++;
    Sleep(TG);

    for(i = 0;i < I;i++){
        for(j = 0;j < J;j++){
          somme = 0;                
            if(j-1 >= 0 && j-1 < J && i-1 >= 0 && i-1 < I ){
              if(map[j-1][i-1] == 2){
                somme ++; 
              }
            }
            if(i-1 >= 0 && i-1 < I ){
              if(map[j][i-1] == 2){
                somme ++; 
              }
            }
            if(j+1 >= 0 && j+1 < J && i-1 >= 0 && i-1 < I ){
              if(map[j+1][i-1] == 2){
                somme ++; 
              }
            }
            if(j-1 >= 0 && j-1 < J){
              if(map[j-1][i] == 2){
                somme ++; 
              }
            }
            if(j+1 >= 0 && j+1 < J){
              if(map[j+1][i] == 2){
                somme ++; 
              }
            }
            if(j-1 >= 0 && j-1 < J && i+1 >= 0 && i+1 < I ){
              if(map[j-1][i+1] == 2){
                somme ++; 
              }
            }
            if(i+1 >= 0 && i+1 < I){
              if(map[j][i+1] == 2){
                somme ++; 
              }
            }
            if(j+1 >= 0 && j+1 < J && i+1 >= 0 && i+1 < I ){
              if(map[j+1][i+1] == 2){
                somme ++; 
              }
            }

            if(map[j][i] == 2){
              if(somme != 2 && somme != 3){
                map[j][i] = 0;
              }
            }
            else{
              if(somme == 3){
                map[j][i] == 2;
              }
            }
        }             
    }
    system("cls");
    for(i = 0;i < I;i++){
        for(j = 0;j < J;j++){
          if(map[j][i] == 2){                 
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
    printf("\033[1;32m");
    printf("GENERATION : %d",gen);
    printf("\033[0m");  
  }
	return 0;
}


