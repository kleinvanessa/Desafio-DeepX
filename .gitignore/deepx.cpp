#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

int X=0,Y=0,num_rovers=0,rover=0,i=0,j=0;//X e Y são as coordenadas superiores direita; num_rovers é a quantidade de rovers que o usuário quer usar; rover é a variavel de controle de rover atual; ie j são variaveis auxiliares;

struct rovers{ //struct paa armezenar todos os parametros de cada rover

  int veti[2],vetf[2]; //veti armazena posição x e y inicial do rover e vetf armazena posição final x e y do rover
  char diri[1],dirf[1],movimento[1000];//diri armazena a direção inicial o rover e dirf armazena direção final do rover;movimento é o vetor que armazena os moviemntos do rover

};

struct rovers r[1000];//para definir indice pra cada rover


using namespace std;


void movimentos(){//função que analisa a direção e os moviemntos do rover para saber as alterações do rover

  for(i=0;i<num_rovers;i++){

    r[i].vetf[0] = r[i].veti[0]; // faz a posição x  final ser iguais a inicial 
    r[i].vetf[1] = r[i].veti[1]; //faz a posição y  final ser iguais a inicial
    r[i].dirf[0] = toupper(r[i].diri[0]);//faz a direção final ser igual a inicial
    r[i].diri[0] = toupper(r[i].diri[0]);
    for(j=0;j<strlen(r[i].movimento);j++){

      switch (r[i].dirf[0]){//variavel direção

        case 'N' : //NORTE
          if(toupper(r[i].movimento[j])=='L'){//quando estiver direcionado pro norte e o movimento for esquerda, o rover se direciona para a direção oeste(W)

            r[i].dirf[0] = 'W';
      
          }

          if(toupper(r[i].movimento[j])=='R'){//quando direção atual é norte e movimento é para direita, posição atual fica para leste(E)

            r[i].dirf[0] = 'E';
          }

          if(toupper(r[i].movimento[j])=='M'){//quando direção atual é norte e moviemnto é pra frente, faz y = y +1, ou seja, sobe uma posição em y.
            
            r[i].vetf[1] = r[i].vetf[1] + 1; //y = y +1;
            if(r[i].vetf[1] < 0 || r[i].vetf[1] > Y){ //se a coordenada sair do quadro de coordenadas escolhido, fica na posição onde está

              r[i].vetf[1] = r[i].vetf[1] - 1;
            }
          }

          break;

        case 'E' :
          if(toupper(r[i].movimento[j])=='L'){

            r[i].dirf[0] = 'N';
          }

          if(toupper(r[i].movimento[j])=='R'){

            r[i].dirf[0] = 'S';
          }

          if(toupper(r[i].movimento[j])=='M'){

            r[i].vetf[0] = r[i].vetf[0] + 1; //x = x +1;
            if(r[i].vetf[0] < 0 || r[i].vetf[0] > X){ //se a coordenada sair do quadro de coordenadas escolhido, fica na posição onde está

              r[i].vetf[0] = r[i].vetf[0] - 1;
            }         

          }
          break;

        case 'W' :
          if(toupper(r[i].movimento[j])=='L'){
  
            r[i].dirf[0] = 'S';

          }

          if(toupper(r[i].movimento[j])=='R'){

            r[i].dirf[0] = 'N';
          }

          if(toupper(r[i].movimento[j])=='M'){

            r[i].vetf[0] = r[i].vetf[0] - 1; //x = x -1;
            if(r[i].vetf[0] < 0 || r[i].vetf[0] > Y){ //se a coordenada sair do quadro de coordenadas escolhido, fica na posição onde está

              r[i].vetf[0] = r[i].vetf[0] + 1;
            }
            
          }
          break;
        case 'S' :
          if(toupper(r[i].movimento[j])=='L'){

            r[i].dirf[0] = 'E';
          }

          if(toupper(r[i].movimento[j])=='R'){

            r[i].dirf[0] = 'W';
          }

          if(toupper(r[i].movimento[j])=='M'){

            r[i].vetf[1] = r[i].vetf[1] - 1; //y = y -1;
            if(r[i].vetf[1] < 0 || r[i].vetf[1] > Y){ //se a coordenada sair do quadro de coordenadas escolhido, fica na posição onde está

              r[i].vetf[1] = r[i].vetf[1] + 1;
            }        

          }
          break;
        default: 
          cout<<"\nEssa direção não existe"<<endl;
          break;

      }
    }
  }
}
 

int main(){

  cout<<"\nPADRÃO DE ENTRADA (EXEMPLO):\n5 5  *coordenadas canto superior direito,coloque espaço entre os numeros\n1 2 N *posição inicial do rover, coloque espaço entre eles\nLMLMRMLMRLM *sem espaço entre as letras,movimentos do rover: L - esquerda ; R - direita ; M - frente"<<endl;
  cout<<"\n - Insira conforme o padrão o numero de rovers desejado:";
  cin>>num_rovers;
  cout<<"\n - Insira conforme o padrão o par de coordenadas X e Y superior direita:\n";
  cin>> X >> Y ;
  cout<<"\nX ="<< X << "\nY="<<Y;
  for(rover=0;rover<num_rovers;rover++){
      
    cout<<"\n - Insira conforme o padrão a posição x,y e direção, respectivamente do rover "<<rover<<" : \n"<<endl;
    cin>>r[rover].veti[0]>>r[rover].veti[1]>>r[rover].diri[0];
    if(r[rover].veti[0] >= 0 && r[rover].veti[0] <= X && r[rover].veti[1]>=0 && r[rover].veti[1] <=Y){ 

      cout<<"\n - Insira conforme o padrão os movimentos do rover:\n";
      cin>>r[rover].movimento;
       
    }
    else{
      cout<<"\n\n\n";
      cout<<"\n*********************************************************************";
      cout<<"\n* POSIÇÕES FORA DAS COORDENADAS DISPONÍVEIS,DIGITE NOVAMENTE!!!!!!!!*";
      cout<<"\n*********************************************************************"<<endl<<endl;
      rover--;
    }
      
  }
 
  movimentos();
  cout<<"\n\n\nRESULTADO:\n"<<endl;
  for(i=0;i<num_rovers;i++){
    cout<<"\nROVER "<<i<<":\n"<<"\nINICIAL = ["<<r[i].veti[0]<<" "<<r[i].veti[1]<<" "<<r[i].diri[0]<<"]"<<"\t\t\t\tFINAL = ["<<r[i].vetf[0]<<" "<<r[i].vetf[1]<<" "<<r[i].dirf[0]<<"]"<<endl;
  }

    
  return(0);

}
