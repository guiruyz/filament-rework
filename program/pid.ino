#include <PID_v1.h>
#include <Thermistor.h> //Include thermistor library

Thermistor temp(0); 
int Pot1 = A1;
int pwmS = 9;

//PID paramters
double Setpoint;  // Desired temperature in degrees Celsius
double Input, Output;
double Kp = 1.26;  // Proportional constant
double Ki = 0.43;  // Integral constant
double Kd = 0.21;  // Derivative constant

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

bool setdir = LOW;

void setup() {
  Serial.begin(9600);
  Input = 0;
  Setpoint = 230.0;
  
  analogWrite (pwmS, 0); 

  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 255);  // Output limits for relay control
  myPID.SetSampleTime(1000);     // Sample time in milliseconds

  digitalWrite(7,setdir);
  
}

void loop() {
  Input = temperatureRead();
  myPID.Compute();
  analogWrite (pwmS, Output); 
  Serial.print(Output);
  Serial.println(" seted\n\r"); 
  delay(500);
}

double temperatureRead (){ 
  double temperature = temp.getTemp(); //VARIÁVEL DO TIPO INTEIRO QUE RECEBE O VALOR DE TEMPERATURA CALCULADO PELA BIBLIOTECA
  Serial.print("Temperatura: "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(temperature); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
  Serial.println("*C"); //IMPRIME O TEXTO NO MONITOR SERIAL
  delay(1); 
  return temperature;
}
