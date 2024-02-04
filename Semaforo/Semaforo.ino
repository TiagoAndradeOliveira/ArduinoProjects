//EQUIPE 15
/* MEMBROS:
RAFAEL GRAÇA AGUIAR
TIAGO ANDRADE DE OLIVEIRA
ANDERSON DE CASTRO FLORENCIO
MAISON NOGUEIRA VERAS FILHO
ANTONIO PEDRO BERNADO DE SOUSA
*/


#define vermelho 8 //pino 8 pino de output do LED vermelho   
#define amarelo 9  //pino 9 pino de output do LED amarelo
#define verde 10   //pino 10 pino de output do LED verde
#define button 7   //pino 7 pino INPUT do botão liga-desliga

unsigned long TempoAtual;      //Essas variáveis são as declarações de tempo para organizar
unsigned long TempoVermelho=0; //os "liga-desliga" do semáforo, usando millis() para não 
unsigned long TempoAmarelo=0;  // atrapalhar a leitura de outros sinais
unsigned long TempoVerde=0;    //

bool estado1=false; //Essas variaveis booleanas são responsáveis por determinar 
bool estado2=false; //se os leds devem ligar ou não. Pode-se perceber que a lógica
bool estado3=false; //dos timers do semáforo é separado da lógica liga e desliga do semáforo.
bool ligar=false;   //estado1(liga-desliga) LED Vermelho
                    //estado2(liga-desliga) LED Amarelo
void setup()        //estado3(liga-desliga) LED Verde
{
  pinMode(vermelho, OUTPUT); //pino 8 pino de output do LED vermelho
  pinMode(amarelo, OUTPUT);  //pino 9 pino de output do LED amarelo
  pinMode(verde, OUTPUT);    //pino 10 pino de output do LED verde
  pinMode(button, INPUT);    //pino 7 pino INPUT do botão liga-desliga
}

void loop()
{
	TempoAtual=millis(); //essa variável sempre recebe o clock atual do relógio
  
  if(digitalRead(button) == HIGH) //caso o botão seja pressionado:
  {
    estado1 = false; //LED vermelho tem seu estado resetado
    estado2 = false; //LED amarelo tem seu estado resetado
    estado3 = true; //LED verde tem seu estado resetado. Esse valor faz com que em cada
    //novo ciclo, o semáforo comece pelo vermelho e mantenha a ordem de cores correta.
    TempoVermelho = TempoAtual; //clock do LED vermelho é resetado
    TempoVerde = TempoAtual;    //clock do LED verde é resetado
    TempoAmarelo = TempoAtual;  //clock do LED amarelo é resetado
    ligar = !ligar; //O botão recebe o inverso de seu estado atual.
    delay (200);    //pequeno delay para melhorar a detecção do botão
  }else 
    if(ligar == true) //Se o semáforo foi ligado, temos:
    {
     //Lógica para saber se o LED verde deve ligar
  	if(TempoAtual - TempoVerde >=1100 && estado2==false && estado1==false){
         	TempoVerde = TempoAtual;
         	estado3 = !estado3;

    }else //Lógica para saber se o LED vermelho deve ligar
     if(TempoAtual - TempoVermelho >= 1000  && estado3==false 
	 && estado2==false){
      	TempoVermelho = TempoAtual;
      	estado1= !estado1;
	
 	}else//Lógica para saber se o LED amarelo deve ligar 
     if(TempoAtual - TempoAmarelo >=1000 && estado1==false 
	 && estado3==false){
      		TempoAmarelo = TempoAtual;
      		estado2 = !estado2;	
       	}

    }else{ //Se o botão estiver desligado, temos tudo resetado e desligado.
    TempoVermelho = TempoAtual;
    TempoVerde = TempoAtual;
    TempoAmarelo = TempoAtual;
    digitalWrite(vermelho,LOW);
    digitalWrite(verde,LOW);
    digitalWrite(amarelo, LOW);
    estado1 = false;
    estado2 = false;
    estado3 = false;
  }

		//Lógicas, separadas, para saber quais LEDS devem ligar.
		if(estado3 == true && ligar == true){
      	digitalWrite(verde, HIGH);
    	}else{
      		digitalWrite(verde, LOW);
		}

		if(estado1 == true && estado3==false && ligar == true){
      		digitalWrite(vermelho, HIGH);
    	}else{
      		digitalWrite(vermelho, LOW);
    	}

		if(estado2 == true && ligar == true){
      		digitalWrite(amarelo, HIGH);
    	}else{
      		digitalWrite(amarelo, LOW);
    	}

		
}

