/* Bibliotecas */ //<>//
import java.util.LinkedList;

/* Constantes */
final int OBSTACULO = 0;
final int ROBO = -2;
final int ESPACO_VAZIO = -1;
final int DESTINO = -3;
final int DIMENSAOMATRIZ = 50;
final int N_OBSTACULOS = DIMENSAOMATRIZ * 4;

/* Variaveis Globais */
int[][] matriz = new int[DIMENSAOMATRIZ][DIMENSAOMATRIZ];

/* Estruturas de Dados */
LinkedList<int[]> Caminho = new LinkedList<>();

/* Funcao desenhadora */
void draw() {
  
  background(255);
  int cols = width / DIMENSAOMATRIZ;
  int rows = height / DIMENSAOMATRIZ;

  for (int i = 0; i < DIMENSAOMATRIZ; i++) {
    for (int j = 0; j < DIMENSAOMATRIZ; j++) {
      
      float x = i * cols;
      float y = j * rows;
      
      fill(255-matriz[i][j]*25);
      rect(x, y, cols, rows);
       
      if(matriz[i][j] == 0) {
        fill(115,115,115);
        rect(x, y, cols, rows);
      }
            
      if(matriz[i][j] == -2) {
        fill(255,0,0);
        rect(x, y, cols, rows);
      }
      
      if(matriz[i][j] == -3) {
        fill(0,255,0);
        rect(x, y, cols, rows);
      }
      
      if(matriz[i][j] >= 1) {
      fill(150, 0, 50+matriz[i][j]*10);
      rect(x, y, cols, rows);
      }
      
      fill(0);
      textAlign(CENTER, CENTER);
      text(matriz[i][j], x + cols / 2, y + rows / 2);
    }
  }
  
  //parte da função para desenhar o menor caminho do robo até o destino
  for(int i = 0; i < Caminho.size(); i++) {
    
    int[] posicao = Caminho.get(i);
    float x = posicao[0] * cols;
    float y = posicao[1] * rows;
    
    fill(0,0,255);
    rect(x, y, cols, rows);
    
    fill(0,0,0);
    textAlign(CENTER, CENTER);
    text(matriz[posicao[0]][posicao[1]], x + cols / 2, y + rows / 2);
  }
}

void setup() {
  size(800,800);
  thread("main"); 
}

/* Funcao que cria o grid e inicia ja com as posicoes dos obstaculos, robo e destino */
public int[][] CriaMapa(int DIMENSAOMATRIZ) {
  
  int linha, coluna; 
  boolean aux = true;
    
  //cria a matriz e inicializa com -1
  int[][] matriz = new int[DIMENSAOMATRIZ][DIMENSAOMATRIZ];
      for(int i = 0; i < DIMENSAOMATRIZ; i++)
        for(int j = 0; j < DIMENSAOMATRIZ; j++) matriz[i][j] = ESPACO_VAZIO;
        
  //obstáculo
  for (int i = 0; i < N_OBSTACULOS; i++) {
    linha = (int)random(DIMENSAOMATRIZ);
    coluna = (int)random(DIMENSAOMATRIZ);
    matriz[linha][coluna] = OBSTACULO;  
  }
  
  //robo
  while(aux == true){
    linha = (int)random(DIMENSAOMATRIZ);
    coluna = (int)random(DIMENSAOMATRIZ);
    if(matriz[linha][coluna] == ESPACO_VAZIO) {
       matriz[linha][coluna] = ROBO;
       aux = false;
    }
  }
  
  aux = true;
  
  //destino
  while(aux == true){
    linha = (int)random(DIMENSAOMATRIZ);
    coluna = (int)random(DIMENSAOMATRIZ);
    if(matriz[linha][coluna] == ESPACO_VAZIO) {
       matriz[linha][coluna] = DESTINO;
       aux = false;
    }
  }
  
  return matriz;
}

public void WaveFront(int[][] matriz) {
  
  int aux = 0;
  int destino = -3;
  boolean Robo_Nao_Encontrado = true;
  
  while(Robo_Nao_Encontrado == true) {
    //percorre a matriz
    for(int i = 0; i < DIMENSAOMATRIZ; i++) {
      for(int j = 0; j < DIMENSAOMATRIZ; j++) {
        if(matriz[i][j] == destino) {
          //marca os adjacentes de acordo com o peso e para quando encontrar o robo
          
           if(i-1 >= 0 && i-1 < DIMENSAOMATRIZ && j >= 0 && j < DIMENSAOMATRIZ){
            if(matriz[i-1][j] == ESPACO_VAZIO) matriz[i-1][j] = aux + 1;
            else if(matriz[i-1][j] == ROBO) Robo_Nao_Encontrado = false;
           }
          
           if(i+1 >= 0 && i+1 < DIMENSAOMATRIZ && j >= 0 && j < DIMENSAOMATRIZ){
            if(matriz[i+1][j] == ESPACO_VAZIO) matriz[i+1][j] = aux + 1;
            else if(matriz[i+1][j] == ROBO) Robo_Nao_Encontrado = false;
           }
          
           if(i >= 0 && i < DIMENSAOMATRIZ && j-1 >= 0 && j-1 < DIMENSAOMATRIZ){
            if(matriz[i][j-1] == ESPACO_VAZIO) matriz[i][j-1] = aux + 1;
            else if(matriz[i][j-1] == ROBO) Robo_Nao_Encontrado = false;
           }
          
           if(i >= 0 && i < DIMENSAOMATRIZ && j+1 >= 0 && j+1 < DIMENSAOMATRIZ){
            if(matriz[i][j+1] == ESPACO_VAZIO) matriz[i][j+1] = aux + 1;
            else if(matriz[i][j+1] == ROBO) Robo_Nao_Encontrado = false;
           }
          }       
        }
      }
    aux++;
    destino = aux;
    delay(250);  
  }
 }

/* Funcao para pegar o menor caminho do robo ate o destino */
public int[][] Caminho(int[][] matriz) {
  
  int menor_numero = 2000000;
  boolean Final_Nao_Encontrado = true;
  int posicao_roboi = 0;
  int posicao_roboj = 0;
  int menor_numeroi = 0;
  int menor_numeroj = 0;
  
  //coloca a posicao do robo nas respectivas variaveis de latitude e longitude
  for(int i = 0; i < DIMENSAOMATRIZ; i++) {
      for(int j = 0; j < DIMENSAOMATRIZ; j++) {
        if(matriz[i][j] == ROBO) { 
         posicao_roboi = i;
         posicao_roboj = j;
        }
      }
  }
  
  //adiciona a posicao do robo na lista do caminho
  Caminho.add(new int[] {posicao_roboi, posicao_roboj});
  
  /*pega o menor vizinho (partindo do robo) e adiciona na lista, depois atualiza a 
  posicao do robo para esse menor vizinho e pega o menor vizinho a partir dessa nova posicao*/
  //Para quando chegar no destino
  while(Final_Nao_Encontrado == true) {
                
          if(posicao_roboi-1 >= 0 && posicao_roboi-1 < DIMENSAOMATRIZ && posicao_roboj >= 0 && posicao_roboj < DIMENSAOMATRIZ) {
            if(matriz[posicao_roboi-1][posicao_roboj] == DESTINO) {
             posicao_roboi = posicao_roboi - 1;
             Caminho.add(new int[] {posicao_roboi, posicao_roboj});
             Final_Nao_Encontrado = false; 
            }
            else if(matriz[posicao_roboi-1][posicao_roboj] < menor_numero && matriz[posicao_roboi-1][posicao_roboj] > 0) {
            menor_numero = matriz[posicao_roboi-1][posicao_roboj];
            menor_numeroi = posicao_roboi - 1;
            menor_numeroj = posicao_roboj;
            }
          }
          
           if(posicao_roboi+1 >= 0 && posicao_roboi+1 < DIMENSAOMATRIZ && posicao_roboj >= 0 && posicao_roboj < DIMENSAOMATRIZ) {
            if(matriz[posicao_roboi+1][posicao_roboj] == DESTINO) {
             posicao_roboi = posicao_roboi + 1;
             Caminho.add(new int[] {posicao_roboi, posicao_roboj});
             Final_Nao_Encontrado = false; 
            }
            else if(matriz[posicao_roboi+1][posicao_roboj] < menor_numero && matriz[posicao_roboi+1][posicao_roboj] > 0) {
            menor_numero = matriz[posicao_roboi+1][posicao_roboj];
            menor_numeroi = posicao_roboi + 1;
            menor_numeroj = posicao_roboj;
            }
          }
           
           if(posicao_roboi >= 0 && posicao_roboi < DIMENSAOMATRIZ && posicao_roboj-1 >= 0 && posicao_roboj-1 < DIMENSAOMATRIZ) {
            if(matriz[posicao_roboi][posicao_roboj-1] ==  DESTINO) {
             posicao_roboj = posicao_roboj - 1;
             Caminho.add(new int[] {posicao_roboi, posicao_roboj});
             Final_Nao_Encontrado = false;
            }
            else if(matriz[posicao_roboi][posicao_roboj-1] > 0 && matriz[posicao_roboi][posicao_roboj-1] < menor_numero){
              menor_numero = matriz[posicao_roboi][posicao_roboj-1];
              menor_numeroi = posicao_roboi;
              menor_numeroj = posicao_roboj - 1;
            }
          }
          
           if(posicao_roboi >= 0 && posicao_roboi < DIMENSAOMATRIZ && posicao_roboj+1 >= 0 && posicao_roboj+1 < DIMENSAOMATRIZ) {
            if(matriz[posicao_roboi][posicao_roboj+1] ==  DESTINO) {
             posicao_roboj = posicao_roboj + 1;  
             Caminho.add(new int[] {posicao_roboi, posicao_roboj});
             Final_Nao_Encontrado = false;
           }
            else if(matriz[posicao_roboi][posicao_roboj+1] > 0 && matriz[posicao_roboi][posicao_roboj+1] < menor_numero) {
              menor_numero = matriz[posicao_roboi][posicao_roboj+1];
              menor_numeroi = posicao_roboi;
              menor_numeroj = posicao_roboj + 1;
            }
          }       
    
    posicao_roboi = menor_numeroi;
    posicao_roboj = menor_numeroj;
    
    //adiciona o menor vizinho, que virou o robo, na lista
    Caminho.add(new int[] {posicao_roboi, posicao_roboj});
    
    delay(250);    
    
  }
  
  return matriz;
}

/* A função recebe a matriz ja preenchida com o caminho e, em conjunto com a 
função Draw, mostra na tela o robô caminhando pelo grid até chegar ao seu destino */
void Simulacao(int[][] matriz) {
   Caminho(matriz);
}

void main() {
  matriz = CriaMapa(DIMENSAOMATRIZ);
  WaveFront(matriz);
  Simulacao(matriz);
}
