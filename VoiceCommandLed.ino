String voice="";
int Red= 3;
int Green= 5;
int Blue= 6;
void setup() {
  Serial.begin(9600);
  //pinMode(Red,OUTPUT);
  //Serial.print("Process Start");
}

void loop() {
  while(Serial.available())
  {
   // Serial.print("Process Start");
    delay(10);
    char c= Serial.read();
    if(c=='#')
    {break;}
    voice+=c;
  }
  if(voice.length()>0)
  {
    Serial.println(voice);
    if(voice=="red")
    {
      for(int i=0; i<=255; i++)
      {
        analogWrite(Red, i);
        delay(10);
      }
    }
    if(voice=="red close")
    {  
      for(int j=255; j>=0; j--)
      {
        analogWrite(Red, j);
        delay(10);
      }
    }
    if(voice=="green")
    {
      for(int i=0; i<=255; i++)
      {
        analogWrite(Green, i);
        delay(10);
      }
    }
     if(voice=="green close")
     {
      for(int j=255; j>=0; j--)
      {
        analogWrite(Green, j);
        delay(10);
      }
    }
    if(voice=="blue")
    {
      for(int i=0; i<=255; i++)
      {
        analogWrite(Blue, i);
        delay(10);
      }
    }
     if(voice=="blue close")
     {
      for(int j=255; j>=0; j--)
      {
        analogWrite(Blue, j);
        delay(10);
      }
    }
    if(voice=="chameleon")
    {
    for(int i=50; i<=255; i=i+50)
    {
      for(int j=50; j<=255; j=j+50)
      {
        for(int k=50; k<=255; k=k+50)
        {
          analogWrite(Red,i);
          analogWrite(Blue,j);
          analogWrite(Green,k);
          delay(20);
        }
      }
    }
    
    }
    if(voice=="Chameleon close")
    {
      for(int i=255; i>=0; i--)
      {
          analogWrite(Red,i);
          analogWrite(Blue,i);
          analogWrite(Green,i);
          delay(20);
      }
    }

    voice="";
  }
}
