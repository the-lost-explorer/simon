#include <reg51.h>
#include <ports.h>
#include <delay.h>
#include <data.h>
#include <rand.h>
#include <game.h>
int temp;

//Driver function
void main(){
	//Setting up ports and initialising 
		P3 = 0x00;
		P2 = 0x00;
	init_random_bits();
	//Start-Up animation
	P1 = 0x00;
	for(temp=0;temp<4;temp++){
		P1 = xbyte[temp];
		delay(1000);
		P1 = 0x00;
	}

	while(1){	
		P0 = 0xFF;
		ON = 1;
		
		//Idle until start is pressed
		idle();
		
		//Start game if idling is over
		start_game();
		delay(1000);
		get();
	}
	
}

//printf("Take a sad song and make it better! <3");
	