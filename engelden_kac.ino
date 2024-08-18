#include <NewPing.h>//kütüphane tanımlıyo

#define in1 5
#define in2 6
#define enA 7

#define in3 8
#define in4 9
#define enB 10


#define trig 12
#define echo 13
#define max_mesafe 100

NewPing dalga(trig, echo, max_mesafe);

unsigned int uzaklik;
unsigned int on_uzaklik;
unsigned int sol_uzaklik;
unsigned int sag_uzaklik;
unsigned int zaman;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
 delay(500);
 digitalWrite(enA, 2);//
 digitalWrite(enB, 2);//
 sensor_olcum();
  on_uzaklik = uzaklik;
  if (on_uzaklik > 15 || on_uzaklik == 0){//
    ileri();
  }
  else{
    dur();

   sensor_olcum();
    sol_uzaklik = uzaklik;

   sensor_olcum();
    sag_uzaklik = uzaklik;

    if (sag_uzaklik > sol_uzaklik)
    {
      sag();
     delay(300);
      ileri();
    }
    else if (sol_uzaklik > sag_uzaklik)
    {
      sol();
     delay(300);
      ileri();
    }
    if (sol_uzaklik = sag_uzaklik)
    {
      geri();
    }
  }
}

void ileri()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); // Sol motorun PWM sinyalini yükseltir
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(200);
}

void geri()
{
 digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

 digitalWrite(in3, HIGH); 
 digitalWrite(in4, LOW);
  delay(200);
}
void sol() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
  delay(200); // Bu süreyi değiştirdim, sağ tekerleğe eşit olacak şekilde ayarlayabilirsiniz
}

void sag() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  delay(200); // Bu süreyi değiştirdim, sol tekerleğe eşit olacak şekilde ayarlayabilirsiniz
}

void dur()
{

 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW); 


 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW); 
  delay(200);

}
void sensor_olcum()
{
  delay(50);
  zaman = dalga.ping();
  uzaklik = zaman / US_ROUNDTRIP_CM;
}