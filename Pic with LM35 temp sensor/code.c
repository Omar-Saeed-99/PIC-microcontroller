#define _XTAL_FREQ  8000000UL      //  MHz

int tenth,degree,units;

int AN0RES = 0;
double Temperature,doub,iptr,Voltage;
void ADC_Init();
int ADC_Read(int);

void main(void) {
unsigned char segments_code[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};

  ADC_Init();
  TRISA = 0xFF;              // PORTA is input
  TRISC = 0x00;              // PORTA is output
  TRISB = 0x00;              // PORTB is output
  PORTB = 0x00;              // Initially Clear All The 8-Pins
  TRISD = 0x00;              // PORTA is output
  PORTD = 0x00;

  while(1)
  {
    // Read The ADC
    AN0RES = ADC_Read(0); // Read Analog Channel 0
    // Calculate The Temperature
    Voltage = AN0RES * 0.0048828;
    Temperature = Voltage / 0.01;
    tenth = Temperature/10;
    units = Temperature - (tenth*10);


    PORTB = segments_code[tenth];


    PORTD = segments_code[units];

    if ( PORTB == segments_code[2] & PORTD == segments_code[5]){

      PORTC = 0b00000001;
        //
    }
    else if (Temperature >= 26) {
       PORTC = 0b00000010;
    }
    else{
    PORTC = 0x00;
    }

    Delay_ms(100);


  }
  /*
  void ADC_Init()
{
  ADCON0 = 0b0100001; // Turn ADC ON, Select AN0 Channel, ADC Clock = Fosc/8
  ADCON1 = 0b11000000; // All 8 Channels Are Analog, Result is "Right-Justified"
  // ADC Clock = Fosc/8
}

 int ADC_Read(int ANC)
{
  if(ANC<0 || ANC>7) // Check Channel Number Validity
  { return 0;}
  ADCON0 &= 0x11000101; // Clear The Channel Selection Bits
  ADCON0 |= ANC<<3; // Select The Required Channel (ANC)
  // Wait The Aquisition Time
  Delay_us(30); // The Minimum Tacq = 20us, So That should be enough
  ADCON0.GO_DONE = 1; // Start A/D Conversion
  while(ADCON0.GO_DONE==1); // Polling GO_DONE Bit
  // Provides Delay Until Conversion Is Complete
  return ((ADRESH << 8) + ADRESL); // Return The Right-Justified 10-Bit Result
}
*/
