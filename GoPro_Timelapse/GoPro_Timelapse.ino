// some parts taken from http://www.genotronex.com/
#include <SoftwareSerial.h>// import the serial library
#include <Servo.h>
Servo myservo;// values 0-180
SoftwareSerial Genotronex(11, 10); // RX, TX
int redledpin=13;
int greenledpin = 12;
int BluetoothData; // the data given from Computer
int buzzerPin = 3;

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On");
  pinMode(redledpin,OUTPUT);
  myservo.attach(5); //set pin 5 as the servo pin
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenledpin, OUTPUT);
}

void loop() {
  digitalWrite(greenledpin,HIGH);
  // put your main code here, to run repeatedly:
   if (Genotronex.available())
   {
      BluetoothData=Genotronex.read(); //read data that's sent via bluetooth
      
      digitalWrite(greenledpin,HIGH); //light up green led to signal waiting for a command
      if (BluetoothData=='1')
      {
        //beeping noise
        analogWrite(buzzerPin, 20);  
        delay(1000);
        analogWrite(buzzerPin, 0);
        
        digitalWrite(greenledpin,LOW); //turn off green led
        
        for(int i=1000;i<=2000;i++) //angle when at 0 degrees is 1000 and at 180 is 2000
          {
             digitalWrite(redledpin,HIGH); //red led blinking
             myservo.writeMicroseconds(i); // move at desired angle
             delay(500); //wait till camera takes picture
             digitalWrite(redledpin,LOW); //red led blinking
             digitalWrite(greenledpin,0);
             delay(500);
          }
      }
      if (BluetoothData=='2')
      {
        //beeping noise
        analogWrite(buzzerPin, 20);  
        delay(1000);
        analogWrite(buzzerPin, 0);
        
        digitalWrite(greenledpin,LOW);//turn off green led
        
        for(int i=1000;i<=2000;i++)//angle when at 0 degrees is 1000 and at 180 is 2000
          {
             digitalWrite(redledpin,HIGH);//red led blinking
             myservo.writeMicroseconds(i);// move at desired angle
             delay(1000);//wait till camera takes picture
             digitalWrite(redledpin,LOW);//red led blinking
             digitalWrite(greenledpin,0);//turn off green led
             delay(1000);
          }
      }
      if (BluetoothData=='5')
      {
        //beeping noise
        analogWrite(buzzerPin, 20);  
        delay(1000);
        analogWrite(buzzerPin, 0);
        
        digitalWrite(greenledpin,LOW);//turn off green led
        
        for(int i=1000;i<=2000;i++)//angle when at 0 degrees is 1000 and at 180 is 2000
          {
             digitalWrite(redledpin,HIGH);//red led blinking
             myservo.writeMicroseconds(i);// move at desired angle
             delay(2500);//wait till camera takes picture
             digitalWrite(redledpin,LOW);//red led blinking
             digitalWrite(greenledpin,0);//turn off green led
             delay(2500);
          }
      }
    }
    delay(100);// prepare for next data
}
