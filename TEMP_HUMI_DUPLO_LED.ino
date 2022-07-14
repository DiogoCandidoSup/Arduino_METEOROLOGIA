#include "dht.h" 

const int pinoDHT11 = A2;

dht DHT; 
int var = 0;

void setup() 
{
  pinMode(12, OUTPUT); //led vermelho
  pinMode(13, OUTPUT); //led azul

  Serial.begin(9600); 
  delay(2000); //INTERVALO DE 2 SEGUNDO ANTES DE INICIAR
}

void loop() 
{
  
  DHT.read11(pinoDHT11); 
  Serial.print(" Umidade: ");
  Serial.print(DHT.humidity);
  Serial.print("%"); 
  Serial.print(" --- Temperatura: "); 
  Serial.print(DHT.temperature, 0); 
  Serial.println("*C"); 
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR

  if(DHT.temperature >= 30 || DHT.humidity <= 35) //led vermelho, QUENTE E ARIDO
  {
    digitalWrite(12, HIGH); 
    delay(200); 
    digitalWrite(12, LOW); 
    delay(300);
  }

  if(DHT.temperature <= 15 || DHT.humidity >= 70) //led azul, FRIO E HUMIDO
  {
    digitalWrite(13, HIGH); 
    delay(200); 
    digitalWrite(13, LOW); 
    delay(300);
  }
  
}
