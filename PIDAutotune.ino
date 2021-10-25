byte valor=55;//valor de 55 combinacion a 6 bits binario 110111 
long valor1=0;
long lectura[160]={};
long enteros[160]={};
float calculo[160]={};
float d,m,L,T,Kp,Td,Ti;
float error_pas,error_pas2=0;
long lee,ac,dc;
long sum,maxvalor,posicion=0;


void setup() {
// put your setup code here, to run once:
//all outputs (1:output)
  DDRD = B11111111;//all as output
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  digitalWrite(13,LOW);
  delay(500);//delay de arranque 
  PORTL = valor;

  for (int a=0;a<160;a++){//lee y almacena
    PORTL = valor;//carga valor al puerto l pines del 49 al 42
    lee=analogRead(A15);
    lectura[a]=lee;
    Serial.println(lectura[a]);
    delay(90);//tiempo de muestreo 30ms para evitar valores repetidos
  }


  for(int b=0; b<160 ; b++){//deriva
    sum=b+1;
    ac=lectura[sum];
    dc=lectura[b];
    d=((ac-dc)/0.09);//valor siguente menos anterior entre tiempo de muestreo
    calculo[b]=d;
    if(maxvalor<calculo[b]){   //Encontrar valor máximo y su posición en el vector
      maxvalor=enteros[b];
      posicion=b;}
    delay(30);
  }

  digitalWrite(13,HIGH);

  for(int c=0; c<=160; c++){
  Serial.println(calculo[c]);
  delay(30);
  }
  
  m = (calculo[posicion+1]-calculo[posicion])/((0.09*(posicion+1))-(0.09*posicion));   //Calculo de la pendiente
  
  L = ((0.09*posicion)-calculo[posicion])/m;
  T = ((calculo[160]-calculo[posicion])/m)+(0.09*posicion)-L;
  
  Kp = 1.2*(T/L);   //Ganancias del PID
  Ti = 2*L;
  Td = 0.5*L;
  
  PORTL = 0;//carga valor al puerto l pines del 49 al 42
  delay(20000);//tiempo de descarga del filtro

  for(int g=0; g<=160; g++){
    error = 152 - analogRead(A15);
    deri_a = error - error_pas;
    integ = (0.09*error) + error_pas2;
    deriv = deri_a/0.09;
    error_pas = deri_a;
    error_pas2 = error;
    PID = (Kp*error) + ((Kp/Ti)*integ) + ((Kp*Td)*deriv); 
  }
}
