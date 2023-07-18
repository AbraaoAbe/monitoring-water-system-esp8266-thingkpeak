#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_VL53L0X.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Configuração do ThingSpeak
char ssid[] = "4XY790KW";
char password[] = "naosei123";
unsigned long channelID = 2216552;
const char* apiKey = "DAQROBQNHR87N9WZ";


// Configuração do sensor
Adafruit_VL53L0X lox;

// Valores fixos de latitude e longitude do overlay
float latitude = 410.0;
float longitude = 450.0;

// Escala personalizada para a distância (0-10)
int minDistance = 330; // Distância mínima
int maxDistance = 160; // Distância máxima
WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Inicialização do sensor
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }

  // Conexão com o Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Configuração do ThingSpeak
  ThingSpeak.begin(client);

  // Leitura e envio dos dados
  readAndSendData();
}

void loop() {
  // Leitura e envio dos dados a cada 30 segundos
  delay(15000);
  readAndSendData();
}

void readAndSendData() {
  // Leitura da distância do sensor
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  // Valor lido do sensor (em milímetros)
  int distance = measure.RangeMilliMeter;

  // Mapeamento da distância para a escala personalizada (0-10)
  int nivel = map(distance, minDistance, maxDistance, 0, 10);

  

  // Envia os dados para o ThingSpeak
  ThingSpeak.setField(1, nivel); // Field 'nivel'
  ThingSpeak.setField(2, latitude); // Field 'latitude'
  ThingSpeak.setField(3, longitude); // Field 'longitude'

  // Envia os dados para o canal
  int response = ThingSpeak.writeFields(channelID, apiKey);
  if (response == 200) {
    Serial.println("Dados enviados com sucesso para o ThingSpeak");
    Serial.println(nivel);
    Serial.println(distance);
  } else {
    Serial.print("Erro no envio dos dados para o ThingSpeak. Código de resposta: ");
    Serial.println(response);
  }
}
