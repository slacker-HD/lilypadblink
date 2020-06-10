#define XPIN A1
#define YPIN A2
#define ZPIN A3

#define REDPIN1 9
#define GREENPIN1 11
#define BLUEPIN1 10

#define REDPIN2 3
#define GREENPIN2 5
#define BLUEPIN2 6

// #define DEBUG

int Xbase = 0, Ybase = 0, Zbase = 0;
int Xval = 0, Yval = 0, Zval = 0;
void setup()
{
    pinMode(XPIN, INPUT);
    pinMode(YPIN, INPUT);
    pinMode(ZPIN, INPUT);
    pinMode(REDPIN1, OUTPUT);
    pinMode(GREENPIN1, OUTPUT);
    pinMode(BLUEPIN1, OUTPUT);
    pinMode(REDPIN2, OUTPUT);
    pinMode(GREENPIN2, OUTPUT);
    pinMode(BLUEPIN2, OUTPUT);

    for (char i = 0; i < 3; i++)
    {
        Xbase += analogRead(XPIN) / 3;
        Ybase += analogRead(YPIN) / 3;
        Zbase += analogRead(ZPIN) / 3;
    }
#ifdef DEBUG
    Serial.begin(9600);
    Serial.print(Xbase);
    Serial.print(Ybase);
    Serial.println(Zbase);
#endif
}

void loop()
{
    Xval = 0;
    Yval = 0;
    Zval = 0;
    for (char i = 0; i < 3; i++)
    {
        Xval += analogRead(XPIN) / 3;
        Yval += analogRead(YPIN) / 3;
        Zval += analogRead(ZPIN) / 3;
    }

    analogWrite(REDPIN1, 255 - abs(Xval - Xbase) > 252 ? 255 : 255 - abs(Xval - Xbase));
    analogWrite(GREENPIN1, 255 - abs(Yval - Ybase) > 252 ? 255 : 255 - abs(Yval - Ybase));
    analogWrite(BLUEPIN1, 255 - abs(Zval - Zbase) > 252 ? 255 : 255 - abs(Zval - Zbase));

    analogWrite(REDPIN2, 255 - abs(Zval - Zbase) > 252 ? 255 : 255 - abs(Zval - Zbase));
    analogWrite(GREENPIN2, 255 - abs(Yval - Ybase) > 252 ? 255 : 255 - abs(Yval - Ybase));
    analogWrite(BLUEPIN2, 255 - abs(Xval - Xbase) > 252 ? 255 : 255 - abs(Xval - Xbase));

    Xbase = Xval;
    Ybase = Yval;
    Zbase = Zval;

    delay(20);

#ifdef DEBUG
    Serial.print("x");
    Serial.print(Xval);
    Serial.print("\t");
    Serial.print("y");
    Serial.print(Yval);
    Serial.print("\t");
    Serial.print("z");
    Serial.print(Zval);
    Serial.println();
#endif
}