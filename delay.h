void delay_one_ms(void);
void delay(int);

//delay for 1 millisecond 
void delay_one_ms(){

TMOD=0x01;     // timer 0, mode 1
TL0=0x018;      // load TL0

TH0=0x0FC;      // load TH0
TR0=1;         // turn on Timer0

while (TF0==0);           // wait for TF0 to roll over

TR0=0;      // turn off timer
TF0=0;      // clear TF0
}

//delay for times(milliseconds)
void delay(int times){
	int i;
	for(i=0;i<times;i++){
		delay_one_ms();
	}
}