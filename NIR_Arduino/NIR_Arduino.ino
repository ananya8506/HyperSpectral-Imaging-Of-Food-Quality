#include "SparkFun_AS7265X.h" //Click here to get the library: http://librarymanager/All#SparkFun_AS7265X
AS7265X sensor;

#include <Wire.h>

const int readingsToTake = 15; // Define the number of readings to take before prompting for input
int readingsCount = 0;

float sumA = 0, sumB = 0, sumC = 0, sumD = 0, sumE = 0, sumF = 0;
float sumG = 0, sumH = 0, sumI = 0, sumJ = 0, sumK = 0, sumL = 0;
float sumR = 0, sumS = 0, sumT = 0, sumU = 0, sumV = 0, sumW = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("AS7265x Spectral Triad Example");

  Serial.println("Point the Triad away and press Enter to begin with illumination...");
  while (!Serial.available()) {} // Wait for user to press Enter
  while (Serial.read() != '\n') {} // Consume any additional characters until Enter is pressed

  if (!sensor.begin()) {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while (1);
  }

  /////////****** TO SHOW TEMP *********///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Wire.setClock(400000);

  int oneSensorTemp = sensor.getTemperature(); //Returns the temperature of master IC
  Serial.print("Main IC temp: ");
  Serial.println(oneSensorTemp);

  float threeSensorTemp = sensor.getTemperatureAverage(); //Returns the average temperature of all three ICs
  Serial.print("Average IC temp: ");
  Serial.println(threeSensorTemp, 2);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  sensor.disableIndicator(); //Turn off the blue status LED

  /////////////////////////////ENABLE LEDs ALL THE TIME/////////////////////////
  sensor.enableBulb(AS7265x_LED_WHITE);
  sensor.enableBulb(AS7265x_LED_IR);
  sensor.enableBulb(AS7265x_LED_UV);  
  ///////////////////////////////////////////////////////////////////////////////
  
  Serial.println("Reading No.,A,B,C,D,E,F,G,H,I,J,K,L,R,S,T,U,V,W");
}

void loop() {
  sensor.takeMeasurementsWithBulb(); //This is a hard wait while all 18 channels are measured

  Serial.print(readingsCount + 1); // Print reading number

  Serial.print(",");

  Serial.print(sensor.getCalibratedA());
  Serial.print(",");
  Serial.print(sensor.getCalibratedB());
  Serial.print(",");
  Serial.print(sensor.getCalibratedC());
  Serial.print(",");
  Serial.print(sensor.getCalibratedD());
  Serial.print(",");
  Serial.print(sensor.getCalibratedE());
  Serial.print(",");
  Serial.print(sensor.getCalibratedF());
  Serial.print(",");

  Serial.print(sensor.getCalibratedG());
  Serial.print(",");
  Serial.print(sensor.getCalibratedH());
  Serial.print(",");
  Serial.print(sensor.getCalibratedI());
  Serial.print(",");
  Serial.print(sensor.getCalibratedJ());
  Serial.print(",");
  Serial.print(sensor.getCalibratedK());
  Serial.print(",");
  Serial.print(sensor.getCalibratedL());
  Serial.print(",");

  Serial.print(sensor.getCalibratedR());
  Serial.print(",");
  Serial.print(sensor.getCalibratedS());
  Serial.print(",");
  Serial.print(sensor.getCalibratedT());
  Serial.print(",");
  Serial.print(sensor.getCalibratedU());
  Serial.print(",");
  Serial.print(sensor.getCalibratedV());
  Serial.print(",");
  Serial.print(sensor.getCalibratedW());
  Serial.print(",");

  Serial.println();

  // Accumulate readings for averages
  sumA += sensor.getCalibratedA();
  sumB += sensor.getCalibratedB();
  sumC += sensor.getCalibratedC();
  sumD += sensor.getCalibratedD();
  sumE += sensor.getCalibratedE();
  sumF += sensor.getCalibratedF();
  sumG += sensor.getCalibratedG();
  sumH += sensor.getCalibratedH();
  sumI += sensor.getCalibratedI();
  sumJ += sensor.getCalibratedJ();
  sumK += sensor.getCalibratedK();
  sumL += sensor.getCalibratedL();
  sumR += sensor.getCalibratedR();
  sumS += sensor.getCalibratedS();
  sumT += sensor.getCalibratedT();
  sumU += sensor.getCalibratedU();
  sumV += sensor.getCalibratedV();
  sumW += sensor.getCalibratedW();

  readingsCount++;

  if (readingsCount >= readingsToTake) {
    // Calculate averages
    float avgA = sumA / readingsToTake;
    float avgB = sumB / readingsToTake;
    float avgC = sumC / readingsToTake;
    float avgD = sumD / readingsToTake;
    float avgE = sumE / readingsToTake;
    float avgF = sumF / readingsToTake;
    float avgG = sumG / readingsToTake;
    float avgH = sumH / readingsToTake;
    float avgI = sumI / readingsToTake;
    float avgJ = sumJ / readingsToTake;
    float avgK = sumK / readingsToTake;
    float avgL = sumL / readingsToTake;
    float avgR = sumR / readingsToTake;
    float avgS = sumS / readingsToTake;
    float avgT = sumT / readingsToTake;
    float avgU = sumU / readingsToTake;
    float avgV = sumV / readingsToTake;
    float avgW = sumW / readingsToTake;

    // Print averages
    Serial.println("Averages:");
    Serial.print("Average A: ");
    Serial.println(avgA);
    Serial.print("Average B: ");
    Serial.println(avgB);
    Serial.print("Average C: ");
    Serial.println(avgC);
    Serial.print("Average D: ");
    Serial.println(avgD);
    Serial.print("Average E: ");
    Serial.println(avgE);
    Serial.print("Average F: ");
    Serial.println(avgF);
    Serial.print("Average G: ");
    Serial.println(avgG);
    Serial.print("Average H: ");
    Serial.println(avgH);
    Serial.print("Average I: ");
    Serial.println(avgI);
    Serial.print("Average J: ");
    Serial.println(avgJ);
    Serial.print("Average K: ");
    Serial.println(avgK);
    Serial.print("Average L: ");
    Serial.println(avgL);
    Serial.print("Average R: ");
    Serial.println(avgR);
    Serial.print("Average S: ");
    Serial.println(avgS);
    Serial.print("Average T: ");
    Serial.println(avgT);
    Serial.print("Average U: ");
    Serial.println(avgU);
    Serial.print("Average V: ");
    Serial.println(avgV);
    Serial.print("Average W: ");
    Serial.println(avgW);

    // Reset accumulators and readings count
    sumA = sumB = sumC = sumD = sumE = sumF = 0;
    sumG = sumH = sumI = sumJ = sumK = sumL = 0;
    sumR = sumS = sumT = sumU = sumV = sumW = 0;
    readingsCount = 0;

    Serial.println("Press Enter to take another set of readings...");
    while (Serial.available() <= 0) {} // Wait for user to press Enter
    while (Serial.read() != '\n') {} // Consume any additional characters until Enter is pressed
  }
}
