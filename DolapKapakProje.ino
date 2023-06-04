//Test kodu delayler yok
#define STEP_DELAY_TIME 1
#define trigPin 4
#define echoPin 2
long sure, mesafe;
boolean dolapKapak;
int turSayisi = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.println("Arduino İle Mesafe Sensörü Uygulaması Başlatılıyor...");
}

void loop() {
  olcum();
  if (mesafe < 5) {
    dolapKapak = false;
  }
  if (mesafe > 5) {
    dolapKapak = true;
    delay(1000);
    olcum();
    if (dolapKapak == true) {
      if (mesafe > 5) {
        for (int i = 0; i <= 5200; i++) {
          olcum();
          if (mesafe > 5) {
            run_motor();
            turSayisi++;
          }
        }
        for (int i = 0; i<=turSayisi;i++) {
          olcum();
          if (mesafe < 5) {
            run_motorgeri();
          }
        }
        turSayisi = 0;
      }
    }
  }
}
void run_motorgeri() {
  {
    step4B();
    delay(STEP_DELAY_TIME);
    step4A();
    delay(STEP_DELAY_TIME);
    step3B();
    delay(STEP_DELAY_TIME);
    step3A();
    delay(STEP_DELAY_TIME);
    step2B();
    delay(STEP_DELAY_TIME);
    step2A();
    delay(STEP_DELAY_TIME);
    step1B();
    delay(STEP_DELAY_TIME);
    step1A();
    delay(STEP_DELAY_TIME);
  }
}

void run_motor() {
  {
    step1A();
    delay(STEP_DELAY_TIME);
    step1B();
    delay(STEP_DELAY_TIME);
    step2A();
    delay(STEP_DELAY_TIME);
    step2B();
    delay(STEP_DELAY_TIME);
    step3A();
    delay(STEP_DELAY_TIME);
    step3B();
    delay(STEP_DELAY_TIME);
    step4A();
    delay(STEP_DELAY_TIME);
    step4B();
    delay(STEP_DELAY_TIME);
  }
}

void step1A() {
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
}

void step1B() {
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
}

void step2A() {
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
}

void step2B() {
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
}

void step3A() {
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
}

void step3B() {
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
}

void step4A() {
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
}

void step4B() {
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
}

void olcum() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure / 2) * 0.0343;
  Serial.print(mesafe);
  Serial.println(" cm uzakta");
  delay(3);
}