
#define trigPin 2
#define echoPin 3
#define Voltage A1
long i=0;
long Speed;
double x;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(Voltage,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long durationindigit;
  double distanceincm;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
durationindigit = pulseIn(echoPin, HIGH);
distanceincm = (durationindigit/5) / 29.1;
//for speed in cm/s:
if(distanceincm<=15&&distanceincm>=5){
  i=i+1;
}
if(i>0)
Speed=(1000000/i);
//intensity variation:
if(distanceincm<=80){
  if(distanceincm<=19.8&&distanceincm>=0){
    digitalWrite(Voltage, HIGH);}
    else if(distanceincm<20.2&&distanceincm>19.8)
    digitalWrite(Voltage, LOW);
    else
    {x=(pow(4.5,1.33))*(exp(-((log(4.5)/60)*distanceincm)));
    analogWrite(Voltage, x);}
    
  }
  else
  digitalWrite(Voltage, LOW);
  if(Speed>0&&Speed<=(25/9))
  delay(5000/Speed);
  
  
}
