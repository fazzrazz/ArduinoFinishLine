//Make variables that save the times for each switch
unsigned int tempoG = 0; 
unsigned int tempoY = 0;
unsigned int tempoR = 0;
//Make variables to read each switch
int gs = 0;
int ys = 0;
int rs = 0;
//Variables used to check when all three switches are pressed
int g = 0;
int y = 0;
int r = 0;

void setup()
{
  //define the pins as either input or output
  //inputs are the switches
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  //outputs for the LED's
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //Output for speaker
  pinMode(2,OUTPUT);

}

void loop()
{
  //Define variables to read the switches
  gs = digitalRead(3);
  ys = digitalRead(4);
  rs = digitalRead(5);
  

 //If the pin reads a high, which means the switch has been pressed,
  if (gs == HIGH) 
  {
    tempoG = millis(); //record the time
    g = 1; //and set a variable to one
  }
 //Repeat the above function for the other two switches
  if (ys == HIGH)
  {
    tempoY = millis();
    y = 1;
  }

  if (rs == HIGH)
  {
    tempoR = millis();
    r = 1;
  }

  
//Once all variables are set to one
//Which means all switches are pressed
  if ( g == 1 && y == 1 && r == 1)
  {

  //compare each time to determine which came first
  //This block is for the green switch time
    if (tempoG < tempoY && tempoG < tempoR)
    {
      digitalWrite(12, HIGH);//Display the result, This one is if it came in first
    }

    if (tempoG < tempoY && tempoG > tempoR)
    {
      digitalWrite(13, HIGH);//If time is second fastest
    }

    if (tempoG > tempoY && tempoG < tempoR)
    {
      digitalWrite(13, HIGH);//Also if the time is second fastest
    }

    if (tempoG > tempoY && tempoG > tempoR)
    {
      digitalWrite(13, HIGH);//If the time is the slowest
      digitalWrite(12, HIGH);
    }


  //This block is to compare the yellow switch time
    if (tempoY < tempoG && tempoY < tempoR)
    {
      digitalWrite(8, HIGH);
    }

    if (tempoY < tempoG && tempoY > tempoR)
    {
      digitalWrite(9, HIGH);
    }

    if (tempoY > tempoG && tempoY < tempoR)
    {
      digitalWrite(9, HIGH);
    }

    if (tempoY > tempoG && tempoY > tempoR)
    {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
    }



  //This block is to compare the red switch time
    if (tempoR < tempoY && tempoR < tempoG)
    {
      digitalWrite(10, HIGH);
    }

    if (tempoR < tempoY && tempoR > tempoG)
    {
      digitalWrite(11, HIGH);
    }

    if (tempoR > tempoY && tempoR < tempoG)
    {
      digitalWrite(11, HIGH);
    }

    if (tempoR > tempoY && tempoR > tempoG)
    {
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
    }


  //Powers the speaker once the results are shown on the LED's
   digitalWrite(2,HIGH);
   delay(1000);
   digitalWrite(2,LOW);
   delay(10);
   

  }


}
