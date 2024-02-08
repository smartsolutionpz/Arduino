const int SPin[4] = {3, 4, 5, 6}; // 4 Pin usati per inviare il codice binario
const int EPin = 2; /* Pin Enable
                      - se impostato HIGH interrotto fisicamente il collegamento tra il pin SIG e quello Yxx scelto
                      - se impostato LOW viene stabilito il collegamento tra il pin SIG e quello Yxx scelto */

const int SIG = 9; // SIG pin

const int STable[16][4] = {
  // Crea un Array con i valori binari da richiamare in base al canale Y scelto
  // s0, s1, s2, s3, canale
  {0,  0,  0,  0}, // Y0
  {1,  0,  0,  0}, // Y1
  {0,  1,  0,  0}, // Y2
  {1,  1,  0,  0}, // Y3
  {0,  0,  1,  0}, // Y4
  {1,  0,  1,  0}, // Y5
  {0,  1,  1,  0}, // Y6
  {1,  1,  1,  0}, // Y7
  {0,  0,  0,  1}, // Y8
  {1,  0,  0,  1}, // Y9
  {0,  1,  0,  1}, // Y10
  {1,  1,  0,  1}, // Y11
  {0,  0,  1,  1}, // Y12
  {1,  0,  1,  1}, // Y13
  {0,  1,  1,  1}, // Y14
  {1,  1,  1,  1}  // Y15
};

void YSelect(int Y){
  digitalWrite(SPin[0], STable[Y][0]);
  digitalWrite(SPin[1], STable[Y][1]);
  digitalWrite(SPin[2], STable[Y][2]);
  digitalWrite(SPin[3], STable[Y][3]);
}

void setup() {
  pinMode(EPin, OUTPUT);// Inizializza EPin come OUTPUT
  digitalWrite(EPin, LOW); // presetta EPin LOW, leggere la nota all'inizio del programma per i dettagli
  
  pinMode(SIG, OUTPUT); // Inizializza SIG come OUTPUT
  digitalWrite(SIG, HIGH); // Presetta SIG HIGH, serve per il nostro esperimeto poi andrà settato a seconda delle necessità

  for (int i = 0; i < 4; i++)
  {
    pinMode(SPin[i], OUTPUT); // Inizializza tutti gli Spin come OUTPUT
    digitalWrite(SPin[i], LOW); // Setta tutti gli Spin LOW
  }
}

void loop() {
  for (int i=0; i<16; i++) {
    YSelect(i); // modificare il valore da 0 a 15 per cegliere quale pin Y selezionare
    //delay(50);
  }
}