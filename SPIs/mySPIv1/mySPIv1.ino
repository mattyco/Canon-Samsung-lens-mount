//clock pin 13M
//MOSI pin 11
//MISO pin 12
#define CLK PINB5
#define MOSI PINB3
#define MISO PINB4
byte data_out;
byte data_in=0x00;
byte bit_io(byte data_out){
    byte mask=0x80;
    DDRB=(1<<CLK)|(1<<MOSI)|(0<<MISO);          //Pin define
    PORTB=(1<<CLK);
    delayMicroseconds(100);
    for (byte i=0; i<8; i++){
      PORTB=(0<<CLK)|(((data_out & mask)!=0)<<MOSI);  //write
      delayMicroseconds(8);
      data_in<<=1;      
      PORTB=(1<<CLK);           
      data_in|=((PINB & (1<<MISO))!=0);                 //read
      delayMicroseconds(4);
      if(i==7){
        delayMicroseconds(16);
        PORTB^=(1<<CLK); 
        }
      mask>>=1;     
     }
    return data_in;
}
byte printout(byte data_out, byte data_in){
  Serial.print("Cam:");
  Serial.print(data_out,HEX);
  Serial.print(" << >> ");
  Serial.print("Lens:");
  Serial.print(data_in,HEX);
  Serial.print("\n");
  return 0x00;
}

void setup() {
  Serial.begin(9600);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0x0A;                    //busy poll
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0x0A;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0xCA;                    //Lens info  
  bit_io(data_out); 
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);  
  delayMicroseconds(250);
  data_out=0x13;                //move diaphragm to full
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x80;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);  
  data_out=0x80;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x0A;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0xB0;                //max aperture
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x00;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0x07;                //aperture control by $02
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x13;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x02;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0x07;                //aperture control by $03
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x13;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x03;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);  
  data_out=0x13;                 //reopen diaphragm
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x80;
  bit_io(data_out);
  printout(data_out,data_in);  
  delayMicroseconds(250);
  data_out=0x07;                //aperture control by $04
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x13;
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x04;
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(250);
  data_out=0x13;                //open or close diaphragm to full
  bit_io(data_out);
  printout(data_out,data_in);
  data_out=0x80;
  bit_io(data_out);
  printout(data_out,data_in);  
  delayMicroseconds(250);
  data_out=0x06;                //max focus
  bit_io(data_out);
  printout(data_out,data_in);
  delayMicroseconds(5000);
  data_out=0x05;                //min focus
  bit_io(data_out);
  printout(data_out,data_in);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
