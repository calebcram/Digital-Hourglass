//You’re going to need a number of global variables in your program to get this all working. To start, create a constant named switchPin. This will be the name of the pin your tilt switch is on
const int switchPin = 8;
//Create a variable of type unsigned long, This will hold the time an LED was last changed.
unsigned long previousTime = 0;
//Create a variable for the switch state, and another to hold the previous switch state. You’ll use these two to compare the switch’s position from one loop to the next.
int switchState = 0;
int prevSwitchState = 0;
//Create a variable named led. This will be used to count which LED is the next one to be turned on. Start out with pin 2.
int led = 2;
//The last variable you’re creating is going to be the interval between each LED turning on. This will be be a long datatype. In 10 minutes (the time between each LED turning on) 600,000 milliseconds pass. If you want the delay between lights to be longer or shorter, this is the number you change.
long interval = 600;
//In your setup(), you need to declare the LED pins 2-7 as outputs. A for() loop declares all six as OUTPUT with just 3 lines of code. You also need to declare switchPin as an INPUT.
void setup() 
{
  for(int x = 2; x<8; x++)
  {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}
//When the loop() starts, you’re going to get the amount of time the Arduino has been running with millis() and store it in a local variable named currentTime.
void loop() 
{
  unsigned long currentTime = millis();
  //Using an if() statement, you’ll check to see if enough time has passed to turn on an LED. Subtract the currentTime from the previousTime and check to see if it is greater than the interval variable. If 600,000 milliseconds have passed (10 minutes), you’ll set the variable previousTime to the value of currentTime.
  if(currentTime - previousTime > interval) 
  {
    previousTime = currentTime;
    //previousTime indicates the last time an LED was turned on. Once you’ve set previousTime, turn on the LED, and increment the led variable. The next time you pass the time interval, the next LED will light up.
    digitalWrite(led, HIGH);
    led++;
    //Add one more if statement in the program to check if the LED on pin 7 is turned on. Don’t do anything with this yet. You’ll decide what happens at the end of the hour later.
    if(led == 7)
    {
    }
  }
  //Now that you’ve checked the time, you’ll want to see if the switch has changed its state. Read the switch value into the switchState variable.
  switchState = digitalRead(switchPin);
  //With an if() statement, check to see if the switch is in a diferent position than it was previously. The != evaluation checks to see if switchState does not equal prevSwitchState. If they are diferent, turn the LEDs of, return the led variable to the first pin, and reset the timer for the LEDs by seting previousTime to currentTime.
  if(switchState != prevSwitchState)
  {
    for(int x = 2; x<8; x++)
    {
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  //At the end of the loop(), save the switch state in prevSwitchState , so you can compare it to the value you get for switchState in the next loop().
  prevSwitchState = switchState;
}
