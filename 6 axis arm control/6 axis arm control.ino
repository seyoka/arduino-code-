 #include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(3, 4); // RX, TX

Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  
Servo servo5;  
Servo servo6;  
Servo servo7;  


int s1Vel = 15;     
int s2Vel = 25; 
int s4Vel = 20; 
int s5Vel = 20; 
int s6Vel = 15; 
int s7Vel = 15; 

int index=0;

int velG=25;


int s1Act,s2Act,s3Act,s4Act,s5Act,s6Act,s7Act;         
int s1Ant,s2Ant,s3Ant,s4Ant,s5Ant,s6Ant,s7Ant;         
int s1[50],s2[50],s3[50],s4[50],s5[50],s6[50],s7[50];  

String bt,btS;


void setup(){
  Serial.begin(115200);
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(10);
  servo1.attach(5,510,1200);  
  servo2.attach(11,650,1400);  
  servo3.attach(6,650,1400);  
  servo4.attach(7,650,1400);  
  servo5.attach(8,650,1400);  
  servo6.attach(9,800,1290);  
  servo7.attach(10,700,1290);  
  
  s1Ant=90;  //BASE
  servo1.write(s1Ant);
  
  s2Ant=100; 
  s3Ant=80;  
  servo2.write(s2Ant); 
  servo3.write(s3Ant);
  
  s4Ant=115; //CODO1
  servo4.write(s4Ant);
  
  s5Ant=60;  
  servo5.write(s5Ant);
  
  s6Ant=90; 
  servo6.write(s6Ant);
  
  s7Ant=60; //GRIPPER
  servo7.write(s7Ant);
  
  delay(50);
}

void loop() {

     if(Bluetooth.available()>0){
      
        bt = Bluetooth.readString();              
        
        if(bt.startsWith("s1")){                
           btS = bt.substring(2,bt.length());   
           s1Act = btS.toInt();                
           if(s1Ant > s1Act){
              for(int j=s1Ant; j>=s1Act; j--){   
                  servo1.write(j);
                  delay(s1Vel);}}
           else{
              for(int j=s1Ant; j<=s1Act; j++){   
                  servo1.write(j);
                  delay(s1Vel);}}
                  
          s1Ant = s1Act;}                        
        if(bt.startsWith("s2")){                
           btS = bt.substring(2,bt.length());  
           s2Act = btS.toInt();                 
           Serial.println(s2Act); 
           if(s2Ant > s2Act){
              for(int j=s2Ant; j>=s2Act; j--){   
                  servo2.write(j);              
                  servo3.write(180-j);          
                  delay(s2Vel);}}
           else{
              for(int j=s2Ant; j<=s2Act; j++){   
                  servo2.write(j);              
                  servo3.write(180-j);          
                  delay(s2Vel);}}
                  
          s2Ant = s2Act;}                                   

        
        if(bt.startsWith("s4")){                
           btS = bt.substring(2,bt.length());   
           s4Act = btS.toInt();                 
           
           if(s4Ant > s4Act){
              for(int j=s4Ant; j>=s4Act; j--){   
                  servo4.write(j);
                  delay(s4Vel);}}
           else{
              for(int j=s4Ant; j<=s4Act; j++){   
                  servo4.write(j);
                  delay(s4Vel);}}
                  
          s4Ant = s4Act;}                                      

       
           btS = bt.substring(2,bt.length());   
           s5Act = btS.toInt();                 
           
           if(s5Ant > s5Act){
              for(int j=s5Ant; j>=s5Act; j--){   
                  servo5.write(j);
                  delay(s5Vel);}}
           else{
              for(int j=s5Ant; j<=s5Act; j++){   
                  servo5.write(j);
                  delay(s5Vel);}}
                  
          s5Ant = s5Act;}  

      /
        if(bt.startsWith("s6")){                
           btS = bt.substring(2,bt.length());   
           s6Act = btS.toInt();                 
           Serial.println(s6Act);
           if(s6Ant > s6Act){
              for(int j=s6Ant; j>=s6Act; j--){   
                  servo6.write(j);
                  delay(s6Vel);}}
           else{
              for(int j=s6Ant; j<=s6Act; j++){   
                  servo6.write(j);
                  delay(s6Vel);}}
                  
          s6Ant = s6Act;} 

       
        if(bt.startsWith("s7")){                
           btS = bt.substring(2,bt.length());   
           s7Act = btS.toInt();                 
           
           if(s7Ant > s7Act){
              for(int j=s7Ant; j>=s7Act; j--){   
                  servo7.write(j);
                  delay(s7Vel);}}
           else{
              for(int j=s7Ant; j<=s7Act; j++){   
                  servo7.write(j);
                  delay(s7Vel);}}
                  
          s7Ant = s7Act;}  

        //////////////////////////// SAVE //////////////////////////////////////////////////
        if(bt.startsWith("SAVE")){
           s1[index]= s1Ant;
           s2[index]= s2Ant;
           s4[index]= s4Ant;
           s5[index]= s5Ant;
           s6[index]= s6Ant;
           s7[index]= s7Ant;
           index++;}
        ///////////////////////// RESET ///////////////////////////////////////////////////            
        if(bt.startsWith("RESET")){
          //memset se utiliza para rellenar un bloque de memoria con un valor determinado
          //memeset("matriz","dato a rellenar","tamaño de la matriz")
           memset(s1,0,sizeof(s1)); //rellena con el valor de "0" todas las posiciones de la matriz
           memset(s2,0,sizeof(s2));
           memset(s4,0,sizeof(s4));
           memset(s5,0,sizeof(s5));
           memset(s6,0,sizeof(s6));
           memset(s7,0,sizeof(s7)); 
           index=0;}             
        //////////////////////////// RUN ////////////////////////////////////////////////////
        if(bt.startsWith("RUN")){
           
           while(bt.startsWith("RESET") != true){
                 for(int i=0; i<= index-2;i++){                      
                     if(Bluetooth.available()>0){
                        bt = Bluetooth.readString(); 
                        if(bt.startsWith("PAUSE") == true){
                           /                     
                           while(bt.startsWith("RUN") != true){
                                 if(Bluetooth.available()>0){
                                    bt = Bluetooth.readString();
                                    if(bt.startsWith("RESET") == true){
                                       break;}
                                 }
                           }                                            
                        }//end if(PAUSE)
                        if(bt.startsWith("ss")){
                           btS  = bt.substring(2,bt.length());   
                           velG = btS.toInt();}
                     }
                     
                     if(s1[i] == s1[i+1]){}
                     
                     if(s1[i] > s1[i+1]){
                        for(int j = s1[i]; j >= s1[i+1];j--){
                            servo1.write(j);
                            delay(velG);}}
                            
                     if(s1[i] < s1[i+1]){ 
                        for(int j = s1[i]; j <= s1[i+1];j++){
                            servo1.write(j);
                            delay(velG);}} 
                     
                     if(s2[i] == s2[i+1]){}
                     
                     if(s2[i] > s2[i+1]){
                        for(int j = s2[i]; j >= s2[i+1];j--){
                            servo2.write(j);
                            servo3.write(180-j);
                            delay(velG);}}
                            
                     if(s2[i] < s2[i+1]){ 
                        for(int j = s2[i]; j <= s2[i+1];j++){
                            servo2.write(j);
                            servo3.write(180-j);
                            delay(velG);}}
                     
                     if(s4[i] == s4[i+1]){}
                     
                     if(s4[i] > s4[i+1]){
                        for(int j = s4[i]; j >= s4[i+1];j--){
                            servo4.write(j);
                            delay(velG);}}
                            
                     if(s4[i] < s4[i+1]){ 
                        for(int j = s4[i]; j <= s4[i+1];j++){
                            servo4.write(j);
                            delay(velG);}}  
                    
                     if(s5[i] == s5[i+1]){}
                     
                     if(s5[i] > s5[i+1]){
                        for(int j = s5[i]; j >= s5[i+1];j--){
                            servo5.write(j);
                            delay(velG);}}
                            
                     if(s5[i] < s5[i+1]){ 
                        for(int j = s5[i]; j <= s5[i+1];j++){
                            servo5.write(j);
                            delay(velG);}}                                                         
                     
                     if(s6[i] == s6[i+1]){}
                     
                     if(s6[i] > s6[i+1]){
                        for(int j = s6[i]; j >= s6[i+1];j--){
                            servo6.write(j);
                            delay(velG);}}
                            
                     if(s6[i] < s6[i+1]){ 
                        for(int j = s6[i]; j <= s6[i+1];j++){
                            servo6.write(j);
                            delay(velG);}} 
                     
                     if(s7[i] == s7[i+1]){}
                     
                     if(s7[i] > s7[i+1]){
                        for(int j = s7[i]; j >= s7[i+1];j--){
                            servo7.write(j);
                            delay(velG);}}
                            
                     if(s7[i] < s7[i+1]){ 
                        for(int j = s7[i]; j <= s7[i+1];j++){
                            servo7.write(j);
                            delay(velG);}}                                                                                                         
              }                
           }
        }
                 
     }        
}
