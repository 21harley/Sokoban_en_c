#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/* sokoban por john llanes 22-10-2019 */

int x1=12,y1=23;
int xp=0 ,yp=0,caja=0;
void mostrar(int m[x1][y1],int x, int y){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(m[i][j]==0){
				printf("  ");
			}else if(m[i][j]==1){
				printf("||");
			}else if(m[i][j]==7){
				printf("II"); xp=i;yp=j;
			}else if(m[i][j]==4){
				printf("[]");
			}else if(m[i][j]==5){
			    printf("__");
			}
		}
		printf("\n");
	}
}
void cambio(int m[x1][y1],int m1[x1][y1]){
	int i,j;	
	for(i=0;i<x1;i++){
		for(j=0;j<y1;j++){
			m[i][j]=m1[i][j];if(m1[i][j]==4) caja++;
		}
	}
}
void mapaCarga(int t,int m[x1][y1]){
  caja=0;
  int  m1[12][23]={  0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,0,1,4,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,1,1,0,0,4,1,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,0,0,4,0,4,0,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,
	                 0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,5,5,5,1,
	                 0,0,0,1,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,5,5,5,1,
	                 0,0,0,1,1,1,1,1,0,1,1,1,0,1,7,1,1,0,0,5,5,5,1,
	                 0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
					 0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					 
  int  m2[12][23]={  0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,
	                 0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,
	                 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	                 0,0,0,1,1,1,1,1,0,1,1,1,0,1,7,1,1,0,0,0,0,0,1,
	                 0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
					 0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					 
  int  m3[12][23]={  0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,
	                 0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,
	                 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	                 0,0,0,1,1,1,1,1,0,1,1,1,0,1,7,1,1,0,0,0,0,0,1,
	                 0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
					 0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};					 					 
	switch(t){
		case 1:cambio(m,m1);break;
		
		case 2:cambio(m,m2);break;
		
		case 3:cambio(m,m3);break;
	}
}
int perdio(int m[x1][y1]){
	int i,j;int gameOver=0;
	for(i=0;i<x1;i++)
	{
		for(j=0;j<y1;j++){
			if(m[i][j]==4){
				//if()
			}
		}
	}
}
int main(int argc, char *argv[]){
	 int mapa[x1][y1];
     int ult=0,ult1=0,ultC=0,ultC1=0,ban=0;
	mapaCarga(1,mapa);				 
	mostrar(mapa,x1,y1);
    int m=0;
    printf("caja %i \n",caja);
    while(m==0){
    	if(kbhit()){
    		char tecla=getch();
    		tecla=tolower(tecla);
			switch(tecla){
    			case 'w':
					if(mapa[xp-1][yp]==0){
						if(ban==1){
							mapa[xp][yp]=ultC1;mapa[xp-1][yp]=7;ult=0;
						}else mapa[xp][yp]=ult;mapa[xp-1][yp]=7;ult=0;
						ban=0;
					}else if(mapa[xp-1][yp]==5){
						if(ban==1){
						 mapa[xp][yp]=ultC1;mapa[xp-1][yp]=7;ult=5;
    					}else mapa[xp][yp]=ult;mapa[xp-1][yp]=7;ult=5;
    					ban=0;
					}else if(mapa[xp-1][yp]==4&&mapa[xp-2][yp]==0){
						if(ultC!=0){
							mapa[xp][yp]=ultC;mapa[xp-1][yp]=7;mapa[xp-2][yp]=4;ultC=0;
						}else if(ultC1!=0){
							mapa[xp][yp]=ultC1;mapa[xp-1][yp]=7;mapa[xp-2][yp]=4;ultC1=0;
						}else{
							mapa[xp][yp]=ultC;mapa[xp-1][yp]=7;mapa[xp-2][yp]=4;ultC=0;
						}
						ban=1;
					}else if(mapa[xp-1][yp]==4&&mapa[xp-2][yp]==5){
						if(ultC!=5){
							mapa[xp][yp]=ultC;mapa[xp-1][yp]=7;mapa[xp-2][yp]=4;ultC=5;
						}else if(ultC1!=5){
							mapa[xp][yp]=ultC1;mapa[xp-1][yp]=7;mapa[xp-2][yp]=4;ultC1=5;
						}else{
							mapa[xp][yp]=ultC;mapa[xp-1][yp]=7;mapa[xp-2][yp]=4;ultC=5;
						}
						ban=1;
					}	
    			break;
				case 's':
					if(mapa[xp+1][yp]==0){
    					if(ban==1){
						 mapa[xp][yp]=ultC1;mapa[xp+1][yp]=7;ult=0;
    					}else mapa[xp][yp]=ult;mapa[xp+1][yp]=7;ult=0;
    					ban=0;
					}else if(mapa[xp+1][yp]==5){
						if(ban==1){
						 mapa[xp][yp]=ultC1;mapa[xp+1][yp]=7;ult=5;
    					}else mapa[xp][yp]=ult;mapa[xp+1][yp]=7;ult=5;
    					ban=0;
					}else if(mapa[xp+1][yp]==4&&mapa[xp+2][yp]==0){
						if(ultC!=0){
							mapa[xp][yp]=ultC;mapa[xp+1][yp]=7;mapa[xp+2][yp]=4;ultC=0;
						}else if(ultC1!=0){
							mapa[xp][yp]=ultC1;mapa[xp+1][yp]=7;mapa[xp+2][yp]=4;ultC1=0;
						}else{
							mapa[xp][yp]=ultC;mapa[xp+1][yp]=7;mapa[xp+2][yp]=4;ultC=0;
						}
						ban=1;
					}else if(mapa[xp+1][yp]==4&&mapa[xp+2][yp]==5){
						if(ultC!=5){
							mapa[xp][yp]=ultC;mapa[xp+1][yp]=7;mapa[xp+2][yp]=4;ultC=5;
						}else if(ultC1!=5){
							mapa[xp][yp]=ultC1;mapa[xp+1][yp]=7;mapa[xp+2][yp]=4;ultC1=5;
						}else{
							mapa[xp][yp]=ultC;mapa[xp+1][yp]=7;mapa[xp+2][yp]=4;ultC=5;
						}
						ban=1;
					}
				break;
				case 'a':
					if(mapa[xp][yp-1]==0){
    					if(ban==1){
						 mapa[xp][yp]=ultC1;mapa[xp][yp-1]=7;ult=0;
						}else mapa[xp][yp]=ult;mapa[xp][yp-1]=7;ult=0;
						ban=0;
					}else if(mapa[xp][yp-1]==5){
						if(ban==1){
						 mapa[xp][yp]=ultC1;mapa[xp][yp-1]=7;ult=5;
    					}else mapa[xp][yp]=ult;mapa[xp][yp-1]=7;ult=5;
    					ban=0;
					}else if(mapa[xp][yp-1]==4&&mapa[xp][yp-2]==0){
						if(ultC!=0){
							mapa[xp][yp]=ultC;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC=0;
						}else if(ultC1!=0&&ban==1){
							mapa[xp][yp]=ultC1;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC1=0;
						}else if(ban==0&&ult==5){
							mapa[xp][yp]=ultC;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC1=0;
						}
						else{
							mapa[xp][yp]=ultC;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC=0;
						}
						ban=1;
					}else if(mapa[xp][yp-1]==4&&mapa[xp][yp-2]==5){
						if(ultC!=5){
							mapa[xp][yp]=ultC;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC=5;
						}else if(ultC1!=5){
							mapa[xp][yp]=ultC1;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC1=5;
						}else{
							mapa[xp][yp]=ultC;mapa[xp][yp-1]=7;mapa[xp][yp-2]=4;ultC=5;
						}
						ban=1;
					}								
				break;
				case 'd':
					if(mapa[xp][yp+1]==0){
  					    if(ban==1){
						   mapa[xp][yp]=ultC1;mapa[xp][yp+1]=7;ult=0;
						}else mapa[xp][yp]=ult;mapa[xp][yp+1]=7;ult=0;
						ban=0;
					}else if(mapa[xp][yp+1]==5){
						if(ban==1){
						 mapa[xp][yp]=ultC1;mapa[xp][yp+1]=7;ult=5;
    					}else mapa[xp][yp]=ult;mapa[xp][yp+1]=7;ult=5;
    					ban=0;
					}else if(mapa[xp][yp+1]==4&&mapa[xp][yp+2]==0){
						if(ultC!=0){
							mapa[xp][yp]=ultC;mapa[xp][yp+1]=7;mapa[xp][yp+2]=4;ultC=0;
						}else if(ultC1!=0){
							mapa[xp][yp]=ultC1;mapa[xp][yp+1]=7;mapa[xp][yp+2]=4;ultC1=0;
						}else{
							mapa[xp][yp]=ultC;mapa[xp][yp+1]=7;mapa[xp][yp+2]=4;ultC=0;
						}
						ban=1;
					}else if(mapa[xp][yp+1]==4&&mapa[xp][yp+2]==5){
						if(ultC!=5){
							mapa[xp][yp]=ultC;mapa[xp][yp+1]=7;mapa[xp][yp+2]=4;ultC=5;
						}else if(ultC1!=5){
							mapa[xp][yp]=ultC1;mapa[xp][yp+1]=7;mapa[xp][yp+2]=4;ultC1=5;
						}else{
							mapa[xp][yp]=ultC;mapa[xp][yp+1]=7;mapa[xp][yp+2]=4;ultC=5;
						}
						ban=1;
					}
				break;
				case 'q':m=1;break;	
		    }
		  	system("cls");mostrar(mapa,x1,y1);  
		}
	}
	printf("Gracias por jugar :DDD");
	return 0;
}
