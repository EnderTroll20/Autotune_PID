//variables globales
int valor;
int numero;
int x,p,x1,x2;
int valores[200]={};
float derivada[200]={}; 
float diff;
void setup() {
  
    Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(A0,INPUT);

 digitalWrite(2,0); 
 digitalWrite(3,0); 
 digitalWrite(4,0); 
 digitalWrite(5,0); 
 digitalWrite(6,0); 
 digitalWrite(7,0); 
 digitalWrite(8,0); 
 digitalWrite(9,0); 
}
 
int binario(int x)                //funcion entre setup y loop
{
 digitalWrite(2,bitRead(x,7)); 
 digitalWrite(3,bitRead(x,6)); 
 digitalWrite(4,bitRead(x,5)); 
 digitalWrite(5,bitRead(x,4)); 
 digitalWrite(6,bitRead(x,3)); 
 digitalWrite(7,bitRead(x,2)); 
 digitalWrite(8,bitRead(x,1)); 
 digitalWrite(9,bitRead(x,0)); 
}

void loop() {
 
    Serial.println("inicio"); 
    valor=0;                   
    numero=binario(valor);
     delay(1000);
    
    for(int i=0; i<200 ; i++){
    valor=53;                   
    numero=binario(valor);
    x=analogRead(A0);
    valores[i]=x;
    Serial.println(x);
    delay(10);
   }
    
    Serial.println("ya guardé");
    Serial.println("Estoy derivando, espera");

        for(int z=0; z<200 ; z++){
          x1=valores[z+1];
          x2=valores[z];
          diff=(x1-x2)/0.01;
          derivada[z]=diff;
          delay(10);
          }

     Serial.println("derivé");
     Serial.println("mostraré");

          for(int w=0; w<200 ; w++){
          Serial.println(derivada[w]);
          delay(10);
          }

       Serial.println("YA QUEDÓ REY, YA QUEDÓ PAPS");   
  }
