const int merah = 13;
const int kuning = 12;
const int hijau = 11;

void setup()
{
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}

void loop()
{
  digitalWrite(merah, HIGH);
  delay(2000);
  
  digitalWrite(merah, LOW);
  
  digitalWrite(kuning, HIGH);
  delay(1000);
  
  digitalWrite(kuning, LOW);
  
  digitalWrite(hijau, HIGH);
  delay(3000);
  
  digitalWrite(hijau, LOW);
}
