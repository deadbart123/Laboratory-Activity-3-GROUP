//  define the pins we’re using for the temp sensor, LDR, and LED
#define TEMP_SENSOR_PIN A0
#define LDR_PIN A2
#define LED_PIN 12

// set thresholds for temperature and brightness 
const float TEMP_THRESHOLD = 50.0;  
const int BRIGHTNESS_THRESHOLD = 220; 

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Make the led pin an output
  Serial.begin(9600); 
}

// this function reads the temperature from Temperature Sensor
float readTemperature() {
  int sensorValue = analogRead(TEMP_SENSOR_PIN);  
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert that to voltage
  float temperatureC = (voltage - 0.5) * 100.0;  
  return temperatureC; 
}

// this function gets the brightness from the photoresistor
int readBrightness() {
  return analogRead(LDR_PIN);  
}

void loop() {
  float temperature = readTemperature();  // grab the current temperature and  current brightness
  int brightness = readBrightness();  

  // print out the readings for a quick check
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  Serial.print("Brightness: ");
  Serial.println(brightness);

  // If both readings are above the thresholds,  blink the led
  if (temperature >= TEMP_THRESHOLD && brightness >= BRIGHTNESS_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  // Turn on the led
    delay(100);  
    digitalWrite(LED_PIN, LOW);  // turn it off
    delay(100);  
  } else {
    digitalWrite(LED_PIN, LOW);  //  keep the led off if no fire
  }
  
  delay(50);  
}
