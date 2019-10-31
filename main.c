#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

/* sokoban por john llanes inicio 22-10-2019 */
/* terminado 31-10-2019 1.0*/

int x1=15;int y1=23;       /*mapa*/
int xp=0 ,yp=0,caja=0,f=0; /*jugador*/
typedef char cadena[20];  /*nombre jugador*/

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

struct registro{
	int mund[3];
	cadena jug[3];
};

void mapaCarga(int t,int m[x1][y1],int ficha[30][2],struct registro *r){
  caja=0;int i=0,j=0,cont=0;
 
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
struct jugadorInformacion{
	int mapa[15][23];
	int mov;
	int mundo;
	cadena nombre;
	int estado;
	int ficha[30][2];
};

void juego(struct jugadorInformacion *jugador,struct registro *r){
    char tecla=' ';
    if(jugador->estado==1) jugador->mundo=0;
    while(jugador->mundo<4&&tecla!='q'){
   	 int valorx1=1,valorx2=2,valory1=1,valory2=2,ban=0;
    if(tecla!='r'&&jugador->estado==1) jugador->mundo++;system("cls");
	if(jugador->estado==1) mapaCarga(jugador->mundo,jugador->mapa,jugador->ficha,r);				 
	mostrar(jugador->mapa,x1,y1,jugador->ficha);
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
					if(jugador->mapa[xp+valorx1][yp+valory1]==0){
                        jugador->mapa[xp+valorx1][yp+valory1]=7;jugador->mapa[xp][yp]=ult;ult=0;
					}
					if(jugador->mapa[xp+valorx1][yp+valory1]==5){
						jugador->mapa[xp+valorx1][yp+valory1]=7;jugador->mapa[xp][yp]=ult;ult=5;
					}
					//caso con caja					
					if(jugador->mapa[xp+valorx1][yp+valory1]==4&&jugador->mapa[xp+valorx2][yp+valory2]==0){
						jugador->mapa[xp+valorx1][yp+valory1]=7;jugador->mapa[xp][yp]=ult;jugador->mapa[xp+valorx2][yp+valory2]=4;ult=0;
					}
					if(jugador->mapa[xp+valorx1][yp+valory1]==4&&jugador->mapa[xp+valorx2][yp+valory2]==5){
						jugador->mapa[xp][yp]=ult;jugador->mapa[xp+valorx1][yp+valory1]=7;jugador->mapa[xp+valorx2][yp+valory2]=4;ult=0;
					}
					recarga(jugador->mapa,jugador->ficha);jugador->mov++;	
    			break;
				case 'r':m=1;system("cls");break;
				case 'q':m=1;break;	
		    }
		    if(tecla!='r'||tecla!='q'){
		     recarga(jugador->mapa,jugador->ficha);valorx1=1,valorx2=2,valory1=1,valory2=2;system("cls");mostrar(jugador->mapa,x1,y1,jugador->ficha);
		  	 printf("\n Cajas por apilar:%i  Cantidad de movimientos:%i",f,jugador->mov);
			 int res=perdio(jugador->mapa,jugador->ficha);
		  	 res>0?printf("Perdio :c precione 'r'=reiniciar mundo \n"):printf("\n 'w'=arriba 's'=abajo \n 'a'=izquierda  'd'=derecha \n 'q'=salir 'r'=reiniciar mundo \n");
			}
		}
	}

	int aux=jugador->mundo-1,i;
    for(i=0;i<3;i++){
	 if(i==aux&&r->mund[i]>jugador->mov&&tecla!='q'){
		r->mund[i]=jugador->mov;
		strcpy(r->jug[i],jugador->nombre);
	  }
    }	
	if(f==0){
		printf("Ganastes :DDD \n");jugador->mov=0;actualizar(r);
		system("pause");
	} 
		
   }//mundo
    if(tecla!='q') printf("Gracias por jugar :DDD"); system("pause");
    
}
void cargarRegistro(struct registro *r){
	FILE *registro=fopen("registro.txt","rb");int i,j;
	if(registro==NULL){
		for(i=0;i<3;i++){
  	      r->mund[i]=999999;
  	      strcpy(r->jug[i],"-");
         }
	}else{
		int mundo,mov,cont;char cadena[10];
		while(feof(registro)==0){
			fscanf(registro,"%d %s %d",&mundo,&cadena,&mov);					
			 strcpy(r->jug[mundo-1],cadena);
			 r->mund[mundo-1]=mov;
		}
	}
	fclose(registro);  
}
void actualizar(struct registro *r){//actualisa el registro de puntuaciones
	FILE *regist=fopen("registro.txt","rb");
	struct registro r1;
	int i,j=0;
	if(regist==NULL){
		FILE *registro1=fopen("registro.txt","w");
		for(i=0;i<3;i++){
			fprintf(registro1,"%d %s %d \n",i+1,r->jug[i],r->mund[i]);
		} 
	    fclose(regist);
	    fclose(registro1);
	}else{
		//registro anterior
		int mundo,mov,cont;char cadena[10];
		for(cont=0;cont<3;cont++){
			fscanf(regist,"%d %s %d",&mundo,&cadena,&mov);	
			 strcpy(r1.jug[cont],cadena);
			 r1.mund[cont]=mov;
			
		}
		fclose(regist);
        FILE *registroA=fopen("registro.txt","w");
        for(i=0;i<3;i++){
        	if(r1.mund[i]>r->mund[i]){
        		fprintf(registroA,"%d %s %d \n",i+1,r->jug[i],r->mund[i]);
			}else{
				fprintf(registroA,"%d %s %d \n",i+1,r1.jug[i],r1.mund[i]);
			}
		}
	
	}
	
}
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "spanish");
	struct jugadorInformacion jugador;
    struct registro r;
    int menu=0,primerJuego=0,i;jugador.estado=0;
	char *letra;
	FILE *instruciones;    
    cargarRegistro(&r);
    
    while(menu!=5){
    	system("cls");
    	              printf("+-----------------------------+\n");
    	              printf("|            *Sokoban*        |\n");
    	              printf("|        1)--->Jugar          |\n");
if(jugador.estado!=0) printf("|        2)--->Continuar      |\n"); 
    	              printf("|        3)--->Instruciones   |\n");
    	              printf("|        4)--->Estadisticas   |\n");
    		          printf("|        5)--->Salir          |\n");
    	              printf("+-----------------------------+\n");
		scanf("%i",&menu);
		switch(menu){
			case 1:
				printf("Ingrese el nombre del jugador \n");
				scanf("%s",&jugador.nombre);primerJuego++;
				jugador.estado=1;jugador.mov=0;
				juego(&jugador,&r);/*juego 0*/
			break;
			
			case 2:
				jugador.estado=2;
				juego(&jugador,&r);/*juego 1*/
			break;
			
			case 3:
				/*cargar archivo*/
            instruciones=fopen("Instruciones.txt","rb");
			if(instruciones==NULL){
				printf("No se encontro el archivo \n");
			}else{
				while(feof(instruciones)==0){
					letra=fgetc(instruciones);
					printf("%c",letra);
				}
			}
			fclose(instruciones);
			system("pause");	
			break;
			
			case 4:
				if(primerJuego>0||r.mund[0]>0){
    	              printf("|          Registro mejores puntaciones         |\n");
    	              printf("| mundo |           jugador         |   mov     |\n");
					for(i=0;i<3;i++){
	       				if(r.mund[i]!=999999){ printf("%i           %s                   %i \n",i+1,r.jug[i],r.mund[i]);
				        }else printf(" %i aun sin jugar \n",i+1);
				    }
				}else printf("Juegue una partida \n");
				system("pause");
			   /*cargar archivo*/
			break;
		}		   	    	    	
	}
	return 0;
}
