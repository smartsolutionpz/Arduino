


/************************* USB COMUNICATION INIT ***********************/
#define USBDELAY 50
bool receive = 0;

typedef struct packet {
  uint8_t bat_temp;
  uint8_t bat_volt;
  uint8_t throttle;
};


/************************* VOID SETUP ***********************/
void setup()
{

  Serial.begin(9600);
pinMode(13, OUTPUT);

}

/************************* SEND DATA TO JETSON ***********************/
int USBTransmit(int v1, int v2, int v3) {
  if (!Serial.availableForWrite())
    return 0;
  packet pack;
  pack.bat_temp = v1;
  pack.bat_volt = v2;
  pack.throttle = v3;
  size_t x = Serial.write((byte*) &pack, sizeof(pack));
  Serial.flush();

  if (x == sizeof(pack)) return 1;
  else return 0;
}


/************************* RECEIVE DATA FROM JETSON ***********************/
int USBReceive() {
  Serial.flush();
  if (!Serial.available())
    return 0;
  size_t bytes = 3;
  byte buff[bytes];
  int x = Serial.readBytes(buff, bytes);
  if (x != bytes) return 0;
  return 1;
}

//ISCRIVITI :)

/************************* VOID LOOP ***********************/
void loop()
{
  if (!receive) {
    if (USBTransmit(10, 12, 14))
      receive = 1;
    digitalWrite(12,HIGH);
    delay(USBDELAY);
  } else
  {
    if (USBReceive())
      receive = 0;
    digitalWrite(12,LOW);
    delay(USBDELAY);
  }


  /*CANTransmit();
    String UID = getUID();
    if (!isAuthenticated)
    authenticate(UID);
    else
    deauthenticate(UID);
  */
}
