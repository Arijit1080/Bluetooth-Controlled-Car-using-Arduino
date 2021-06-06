char data = 0; 
int lspeed = 254;
int rspeed = 254; 
int local_lspeed = 254;
int local_rspeed = 254;     

int InA1 = 2;
int InB1 = 3;
int InA2 = 4;
int InB2 = 5;

int pwm1 = 6;
int pwm2 = 9;

int relay = 8;
int relay2 = 10;

void setup()
{
    Serial.begin(9600);                                  
    pinMode(InA1, OUTPUT);  
    pinMode(InA2, OUTPUT);
    pinMode(InB1, OUTPUT);
    pinMode(InB2, OUTPUT);
    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(relay, OUTPUT);
    pinMode(relay2, OUTPUT);
    digitalWrite(relay, HIGH);
    digitalWrite(relay2, LOW);
   // analogWrite(3,1020);
    //analogWrite(9,1020);
}
void loop()
{
   if(Serial.available() > 0)      
   {
      data = Serial.read();        
      Serial.print(data);          
      Serial.print("\n");        
      if(data == 'F') 
        { 
          digitalWrite(InA1, HIGH); 
          digitalWrite(InA2, HIGH); 
          digitalWrite(InB1, LOW); 
          digitalWrite(InB2, LOW);
          analogWrite(pwm1,lspeed);
          analogWrite(pwm2,rspeed);
        }
      else if(data == 'B')        
         { 
          digitalWrite(InA1, LOW); 
          digitalWrite(InA2, LOW); 
          digitalWrite(InB1, HIGH); 
          digitalWrite(InB2, HIGH);
          analogWrite(pwm1,lspeed);
          analogWrite(pwm2,rspeed);
        }    
      else if(data == 'L')        
         { 
          digitalWrite(InA1, LOW); 
          digitalWrite(InA2, HIGH); 
          digitalWrite(InB1, HIGH); 
          digitalWrite(InB2, LOW);
          analogWrite(pwm1,lspeed);
          analogWrite(pwm2,rspeed);
        }
      else if(data == 'R')        
        { 
          digitalWrite(InA1, HIGH); 
          digitalWrite(InA2, LOW); 
          digitalWrite(InB1, LOW); 
          digitalWrite(InB2, HIGH);
          analogWrite(pwm1,lspeed);
          analogWrite(pwm2,rspeed);
          
        } 
       /*else if(data == 'G') 
        { 
          digitalWrite(4, LOW); 
          digitalWrite(6, HIGH); 
          digitalWrite(5, LOW); 
          digitalWrite(7, LOW);
          local_lspeed=rspeed/2;
          local_rspeed=rspeed;
          analogWrite(3,lspeed);
          analogWrite(9,rspeed);
        }
       else if(data == 'I') 
        { 
          digitalWrite(4, HIGH); 
          digitalWrite(6, LOW); 
          digitalWrite(5, LOW); 
          digitalWrite(7, LOW);
          local_rspeed=lspeed/2;
          local_lspeed=lspeed;
          analogWrite(3,lspeed);
          analogWrite(9,rspeed);
        }
       else if(data == 'H')        
         { 
          digitalWrite(5, LOW); 
          digitalWrite(7, HIGH); 
          digitalWrite(4, LOW); 
          digitalWrite(6, LOW);
          local_lspeed=rspeed/2;
          local_rspeed=rspeed;
          analogWrite(3,lspeed);
          analogWrite(9,rspeed);
        }
       else if(data == 'J')        
         { 
          digitalWrite(5, HIGH); 
          digitalWrite(7, LOW); 
          digitalWrite(4, LOW); 
          digitalWrite(6, LOW);
          local_rspeed=lspeed/2;
          local_lspeed=lspeed;
          analogWrite(3,lspeed);
          analogWrite(9,rspeed);
        }*/
        else if(data == 'X')
        {
          digitalWrite(relay, LOW);   
        }
         else if(data == 'x')
        {
          digitalWrite(relay, HIGH);   
        }
       else if(data == 'S' ||data == 'D' )        
        { 
          digitalWrite(4, LOW); 
          digitalWrite(6, LOW); 
          digitalWrite(5, LOW); 
          digitalWrite(7, LOW);
          analogWrite(3,lspeed);
          analogWrite(9,rspeed);
        }
        
      else if(data == 'q' || data == 9)        
        { 
          lspeed=254;
          rspeed=254;
        }
      else if(data == '8')        
        { 
          lspeed=225;
          rspeed=225;
        }
        else if(data == '7')        
        { 
          lspeed=200;
          rspeed=200;
        }
        else if(data == '6')        
        { 
          lspeed=175;
          rspeed=175;
        }  
        else if(data == '5')        
        { 
          lspeed=150;
          rspeed=150;
        }
        else if(data == '4')        
        { 
          lspeed=125;
          rspeed=125;
        }
        else if(data == '3')        
        { 
          lspeed=100;
          rspeed=100;
        }  
        else if(data == '2')        
        { 
          lspeed=75;
          rspeed=75;
        }
        else if(data == '1')        
        { 
          lspeed=50;
          rspeed=50;
        } 
         else if(data == 'W')        
        { 
         digitalWrite(relay2, HIGH);
        } 
          else if(data == 'w')        
        { 
         digitalWrite(relay2, LOW);
        }
   }
   /*else
   { 
          digitalWrite(4, LOW); 
          digitalWrite(6, LOW); 
          digitalWrite(5, LOW); 
          digitalWrite(7, LOW);
   }*/
}
