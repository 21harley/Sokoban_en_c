#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/* sokoban por john llanes inicio 22-10-2019 */

int x1=15;int y1=23;
int xp=0 ,yp=0,caja=0,f=0;

void gotoxy(int x,int y)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}

void Color(int c)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void cambio(int m[x1][y1],int m1[x1][y1]){
	int i,j;	
	for(i=0;i<x1;i++){
		for(j=0;j<y1;j++){
			m[i][j]=m1[i][j];if(m1[i][j]==4) caja++;
		}
	}
}
void recarga(int m[x1][y1],int ficha[30][2]){
	int i=0,j=0,aux=0,aux1=0;f=0;
	for(i=0;i<30;i++){
        aux=ficha[i][0];
        aux1=ficha[i][1];
        if(aux!=0&&aux1!=0){
        	if(m[aux][aux1]==0){
        	m[aux][aux1]=5;f++;
		   }else if(m[aux][aux1]==5){
		   	f++;
		   }else if(m[aux][aux1]==7) f++; 
		} 

	}
}
void mapaCarga(int t,int m[x1][y1],int ficha[30][2]){
  caja=0;
  int  m1[15][23]={  0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,0,1,4,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,1,1,0,0,4,1,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,1,0,0,4,0,4,0,1,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,1,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,
	                 0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,0,0,5,5,1,
	                 0,0,0,1,0,4,0,0,4,0,0,0,0,0,0,0,0,0,0,0,5,5,1,
	                 0,0,0,1,1,1,1,1,0,1,1,1,0,1,7,1,1,0,0,0,5,5,1,
	                 0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,
					 0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					 
  int  m2[15][23]={  0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,4,0,0,0,0,4,1,1,1,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,1,1,0,5,5,1,0,0,0,1,0,0,0,0,0,0,
	                 0,0,0,0,0,0,0,0,1,4,5,5,5,0,0,0,1,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,1,1,0,7,5,5,1,0,0,1,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,4,0,0,4,0,4,0,0,1,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,1,0,1,1,1,4,0,0,1,0,0,0,0,0,0,
	                 0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,
					 0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
					 
  int  m3[15][23]={  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,
	                 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,
	                 0,0,0,0,0,0,0,0,0,0,1,1,0,4,0,0,4,0,0,1,0,0,0,
	                 0,0,0,0,0,0,1,1,1,1,1,0,4,0,0,4,0,4,0,1,1,1,1,
	                 0,0,0,0,0,0,1,0,4,0,0,0,0,0,4,4,0,0,1,1,1,5,1,
	                 0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,5,5,1,
	                 0,0,0,0,0,0,1,1,7,1,0,0,1,0,0,0,0,1,1,5,5,0,1,
	                 0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,5,5,0,0,1,
	                 0,0,0,0,0,0,1,0,0,1,4,0,1,1,0,1,1,1,5,5,5,5,1,
	                 0,0,0,0,0,0,1,1,1,1,0,0,4,0,4,0,0,1,1,1,5,5,1,
					 0,0,0,0,0,0,0,0,0,1,1,0,0,4,0,4,0,0,4,5,5,5,1,
					 0,0,0,0,0,0,0,0,0,0,1,0,4,4,0,0,4,0,0,5,5,5,1,
					 0,0,0,0,0,0,0,0,0,0,1,0,0,0,4,0,4,0,0,1,1,1,1,
					 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0};					 					 
	switch(t){
		case 1:cambio(m,m1);break;
		
		case 2:cambio(m,m2);break;
		
		case 3:cambio(m,m3);break;
	}
	int i=0,j=0,cont=0;
	for(i=0;i<30;i++){
		for(j=0;j<2;j++){
			ficha[i][j]=0;
		}
	}
	for(i=0;i<x1;i++){
		for(j=0;j<y1;j++){
			if(m[i][j]==5){
				ficha[cont][0]=i;ficha[cont][1]=j;cont++;f++;
			}
		}
	}
}
int chequeo(int ficha[30][2],int x,int y){
	int i,j,aux1,aux;
	for(i=0;i<30;i++){
		aux=ficha[i][0];
		aux1=ficha[i][1];
		if(aux==0&&aux1==0) break;
		if(x==aux&&y==aux1){
			return 0;
		}
	}
	return 1;
}

void mostrar(int m[x1][y1],int x, int y,int ficha[30][2]){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(m[i][j]==0){
				Color(7);printf("  ");
			}else if(m[i][j]==1){
				Color(8);printf("||");
			}else if(m[i][j]==7){
				Color(9);printf("II"); xp=i;yp=j;
			}else if(m[i][j]==4){
				if(chequeo(ficha,i,j)==0){
					Color(12);
				}else Color(14);
				printf("[]");
			}else if(m[i][j]==5){
			    Color(4);printf("__");
			}
		}
		printf("\n");
	}
}
int perdio(int m[x1][y1],int ficha[30][2]){
	int i,j;int gameOver=0,ban=0;
	for(i=0;i<x1;i++)
	{
		for(j=0;j<y1;j++){
			if(m[i][j]==4){
				if((m[i-1][j-1]==4||m[i-1][j-1]==1)&&(m[i-1][j]==4||m[i-1][j]==1)&&(m[i][j-1]==4||m[i][j-1]==1)){
                    ban=1;
				}
				if((m[i][j-1]==4||m[i][j-1]==1)&&(m[i+1][j-1]==4||m[i+1][j-1]==1)&&(m[i+1][j]==4||m[i+1][j]==1)){
					ban=2;
				}
				if((m[i][j+1]==4||m[i][j+1]==1)&&(m[i+1][j+1]==4||m[i+1][j+1]==1)&&(m[i+1][j]==4||m[i+1][j]==1)){
					ban=3;
				}
				if((m[i-1][j+1]==4||m[i-1][j+1]==1)&&(m[i][j+1]==4||m[i][j+1]==1)&&(m[i-1][j]==4||m[i-1][j]==1)){
					ban=4;
				}
				if(chequeo(ficha,i,j)>0&&ban>0){
					gameOver=1;return ban;
				}
			}
			ban=0;
		}
	}
	return gameOver;
}

void juego(){
	 int mapa[x1][y1];
	 int ficha[30][2];
     int mundo=0;
     char tecla=' ';
   while(mundo<4&&tecla!='q'){
   	 int valorx1=1,valorx2=2,valory1=1,valory2=2,ban=0;
    if(tecla!='r') mundo++;system("cls");
	mapaCarga(mundo,mapa,ficha);				 
	mostrar(mapa,x1,y1,ficha);
    int m=0,ult=0,ult1=0;
    while(f!=0&&m!=1){
    	if(kbhit()){
    		tecla=getch();
    		tecla=tolower(tecla);
			switch(tecla){
    			case 'w':case 's':case 'a':case 'd':
    				switch(tecla){
    					case 'w':valory1=valory2=0;valorx1=-1;valorx2=-2;break;
    					case 's':valory1=valory2=0;break;
    					case 'a':valorx1=valorx2=0;valory1=-1;valory2=-2;break;
    					case 'd':valorx1=valorx2=0;break;
					} 
    				//case sin caja
					if(mapa[xp+valorx1][yp+valory1]==0){
                        mapa[xp+valorx1][yp+valory1]=7;mapa[xp][yp]=ult;ult=0;
					}
					if(mapa[xp+valorx1][yp+valory1]==5){
						mapa[xp+valorx1][yp+valory1]=7;mapa[xp][yp]=ult;ult=5;
					}
					//caso con caja					
					if(mapa[xp+valorx1][yp+valory1]==4&&mapa[xp+valorx2][yp+valory2]==0){
						mapa[xp+valorx1][yp+valory1]=7;mapa[xp][yp]=ult;mapa[xp+valorx2][yp+valory2]=4;ult=0;
					}
					if(mapa[xp+valorx1][yp+valory1]==4&&mapa[xp+valorx2][yp+valory2]==5){
						mapa[xp][yp]=ult;mapa[xp+valorx1][yp+valory1]=7;mapa[xp+valorx2][yp+valory2]=4;ult=0;
					}
					recarga(mapa,ficha);	
    			break;
				case 'r':m=1;system("cls");break;
				case 'q':m=1;break;	
		    }
		    if(tecla!='r'||tecla!='q'){
		     recarga(mapa,ficha);valorx1=1,valorx2=2,valory1=1,valory2=2;system("cls");mostrar(mapa,x1,y1,ficha);
		  	 printf("\n Cajas por apilar:%i ",f);
		  	 int res=perdio(mapa,ficha);
		  	 res>0?printf("Perdio precione 'r' %i \n",res):printf(" ");
			}
		}
	}
	if(f==0){
		printf("Ganastes :DDD \n");
	} 	
   }
    if(tecla!='q') printf("Gracias por jugar :DDD"); system("pause");
}
struct jugadorInformacion{
	int matriz[15][23];
	int mov;
	int mundo;
	char nombre[20];
};
int main(int argc, char *argv[]){
    int menu=0,estado=0;
    while(menu!=5){
    	system("cls");
    	      printf("+-----------------------------+\n");
    	      printf("|            *Sokoban*        |\n");
    	      printf("|        1)--->Jugar          |\n");
if(estado==1) printf("|        2)--->Continuar      |\n"); 
    	      printf("|        3)--->Instruciones   |\n");
    	      printf("|        4)--->Estadisticas   |\n");
    		  printf("|        5)--->Salir          |\n");
    	      printf("+-----------------------------+\n");
		scanf("%i",&menu);
		switch(menu){
			case 1:
				estado=1;
				juego();/*juego 0*/
			break;
			
			case 2:
				/*juego 1*/
			break;
			
			case 3:
				/*cargar archivo*/
			break;
			
			case 4:
			   /*cargar archivo*/
			break;
		}		   	    	    	
	}
	return 0;
}
