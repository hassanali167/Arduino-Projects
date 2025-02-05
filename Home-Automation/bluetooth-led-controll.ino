char Incoming_value = 0;
int led1=3;
int led2=4;
int led3=5;
int socket=6;

void setup() {
  // put your setup code  here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(socket,OUTPUT);
}

void  loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()  > 0)
    {
      Incoming_value = Serial.read();
      Serial.println(Incoming_value);
      
      if (Incoming_value == '1'){
        digitalWrite(13,HIGH);
        digitalWrite(led1,HIGH);
        
      }
        
      else if(Incoming_value == '2')
      {
        digitalWrite(13,LOW);
         digitalWrite(led1,LOW);
    }


    else if(Incoming_value == '3')
      {
        digitalWrite(13,HIGH);
         digitalWrite(led2,HIGH);
    }

    else if(Incoming_value == '4')
      {
        digitalWrite(13,LOW);
         digitalWrite(led2,LOW);
    }

    else if(Incoming_value == '5')
      {
        digitalWrite(13,HIGH);
         digitalWrite(led3,HIGH);
    }

    else if(Incoming_value == '6')
      {
        
        digitalWrite(13,LOW);
         digitalWrite(led3,LOW);
    }






     else if(Incoming_value == '7')
      {
        digitalWrite(13,HIGH);
         digitalWrite(socket,HIGH);
    }

    else if(Incoming_value == '8')
      {
        
        digitalWrite(13,LOW);
         digitalWrite(socket,LOW);
    }



    
    else{
      digitalWrite(13,LOW);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(socket,LOW);
    }
}
}
    
