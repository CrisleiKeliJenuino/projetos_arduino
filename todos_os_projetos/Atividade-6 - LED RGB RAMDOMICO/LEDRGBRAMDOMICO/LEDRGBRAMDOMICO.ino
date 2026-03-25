// LED RGB - RAMDOMICO

int rPin = 4;
int gPin = 2;
int bPin = 3;

int rVal = 0;
int gVal = 0;
int bVal = 0;
void setup()
{
  pinMode(bPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
}

void loop()
{
  analogWrite(rPin, rVal);
  analogWrite(bPin, bVal);
  analogWrite(gPin, gVal); 

	rVal = random(0,255);
	gVal = random(0,255);
	bVal = random(0,255); 
  
delay(1000); 
}