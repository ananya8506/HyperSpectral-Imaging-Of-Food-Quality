#include "SparkFun_AS7265X.h" // Click here to get the library
AS7265X sensor;

#include <Wire.h>

int selectedLED = 0;  // Variable to store selected LED (1 for White, 2 for UV, 3 for IR)
int currentSelection = 12; // Default current selection in mA

void setup() {
  Serial.begin(9600);
  Serial.println("AS7265x Spectral Triad Example with LED Selection");

  if(sensor.begin() == false)
  {
    Serial.println("Sensor does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }

  // Increase I2C speed
  Wire.setClock(400000);

  // Allow the user to choose which LED to activate
  Serial.println("Select LED to control: ");
  Serial.println("1 - White LED");
  Serial.println("2 - UV LED");
  Serial.println("3 - IR LED");
  
  while(Serial.available() == 0) {} // Wait for user input
  selectedLED = Serial.parseInt();  // Read the user's input
  
  Serial.read(); // Clear any remaining input
  
  // Allow user to select current for the chosen LED
  Serial.println("Enter current level (12 for 12.5mA, 25 for 25mA, 50 for 50mA, 100 for 100mA): ");
  while(Serial.available() == 0) {} // Wait for user input
  currentSelection = Serial.parseInt();
  Serial.read();  // Clear any remaining input

  // Make sure the current is within the allowed range
  if (currentSelection != 12 && currentSelection != 25 && currentSelection != 50 && currentSelection != 100) {
    Serial.println("Invalid current. Setting to default (12.5mA).");
    currentSelection = 12;
  }

  // Set gain and measurement mode as needed
  sensor.setGain(AS7265X_GAIN_16X); // Set gain to 16x (can be modified)
  sensor.setMeasurementMode(AS7265X_MEASUREMENT_MODE_6CHAN_ONE_SHOT); // One-shot mode for all 6 channels

  // Set integration cycles (measurement time)
  sensor.setIntegrationCycles(1); // Fastest measurement cycle: 2*2.8ms = 5.6ms
  
  // Activate the selected LED with the user-defined current
  setLED(selectedLED, currentSelection);

  // Disable indicator for clarity
  sensor.disableIndicator();

  Serial.println("A,B,C,D,E,F,G,H,I,J,K,L,R,S,T,U,V,W");
}

void loop() {
  sensor.takeMeasurementsWithBulb(); // Take measurements while the selected LED is active

  // Print out the calibrated readings
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
  delay(1000); // Delay between measurements
}

// Function to activate the selected LED and set the current
void setLED(int led, int current) {
  // Turn off all LEDs first to ensure only one is active
  sensor.disableBulb(AS7265x_LED_WHITE);  
  sensor.disableBulb(AS7265x_LED_UV);     
  sensor.disableBulb(AS7265x_LED_IR);     

  switch (led) {
    case 1:
      Serial.println("Activating White LED...");
      sensor.enableBulb(AS7265x_LED_WHITE);  // Enable the White LED
      setLEDCurrent(current, AS7265x_LED_WHITE);  // Set current for the White LED
      break;
    case 2:
      Serial.println("Activating UV LED...");
      sensor.enableBulb(AS7265x_LED_UV);  // Enable the UV LED
      setLEDCurrent(current, AS7265x_LED_UV);  // Set current for the UV LED
      break;
    case 3:
      Serial.println("Activating IR LED...");
      sensor.enableBulb(AS7265x_LED_IR);  // Enable the IR LED
      setLEDCurrent(current, AS7265x_LED_IR);  // Set current for the IR LED
      break;
    default:
      Serial.println("Invalid selection. Defaulting to White LED.");
      sensor.enableBulb(AS7265x_LED_WHITE);  // Default to the White LED
      setLEDCurrent(12, AS7265x_LED_WHITE);  // Default to 12.5mA current for the White LED
      break;
  }
}

// Helper function to set the current for a specific LED
void setLEDCurrent(int current, uint8_t ledType) {
  switch (current) {
    case 12:
      sensor.setBulbCurrent(AS7265X_LED_CURRENT_LIMIT_12_5MA, ledType);
      break;
    case 25:
      sensor.setBulbCurrent(AS7265X_LED_CURRENT_LIMIT_25MA, ledType);
      break;
    case 50:
      sensor.setBulbCurrent(AS7265X_LED_CURRENT_LIMIT_50MA, ledType);
      break;
    case 100:
      sensor.setBulbCurrent(AS7265X_LED_CURRENT_LIMIT_100MA, ledType);
      break;
    default:
      sensor.setBulbCurrent(AS7265X_LED_CURRENT_LIMIT_12_5MA, ledType);  // Default to 12.5mA
      break;
  }
}

