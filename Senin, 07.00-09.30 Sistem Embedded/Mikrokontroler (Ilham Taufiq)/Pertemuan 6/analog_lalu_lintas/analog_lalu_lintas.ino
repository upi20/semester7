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
  analogWrite(merah, random(56+200));
  analogWrite(kuning, random(156+100));
  analogWrite(hijau, random(256));
  //digitalWrite(merah, HIGH);
  delay(100);
  
  //digitalWrite(merah, LOW);
  
  //digitalWrite(kuning, HIGH);
  //delay(1000);
  
  //digitalWrite(kuning, LOW);
  
  //digitalWrite(hijau, HIGH);
  //delay(3000);
  
  //digitalWrite(hijau, LOW);
}
