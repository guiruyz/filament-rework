#include <string.h>
#define sentido 2  
#define pulso 3
#define enable 4
int velocidade = 20;  // varia de 1 a 99
void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 5; i++) pinMode(i, OUTPUT); 
  digitalWrite(enable, LOW);                      
}
void loop() {
  Comando();  // A função que irá interpretar o comando escrito no vetor resposta[] e realizar a ação.
}

void Comando() {  //Função que interpreta o que está escrito no vetor resposta e transforma em um comando para o motor de passo.
  int passos;
  //passos = atoi(strtok(resposta, " "));
  Serial.println(passos);
  digitalWrite(sentido, HIGH);
  digitalWrite(pulso, HIGH);
  delay(100 / velocidade);
  digitalWrite(pulso, LOW);
  delay(100 - velocidade);
  }
}