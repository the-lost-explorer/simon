int temp;
static unsigned char transfer; 
static unsigned int check_number;

void idle(){
	while(START==0) //Wait for user to start
		;
	
}

void start_game(){
	P1 = 0;
	START_O = 1;
	for(temp=0;temp<game_number;temp++){
			P1 = xbyte[randbyte[temp]];
			delay(1000);
			P1 = 0;
	}
	P1 = 0;
	game_number++;
	check_number = game_number - 1;
	P2 = game_number;
	START_O = 0;
}

int check_game(unsigned int transfer, int temp){
	if(transfer==xbyte[randbyte[temp]]){
		P2 = 0x16;
		CORRECT = 1;
		return 1;
	}else{
		P1 = ~transfer;
		P2 = xbyte[randbyte[temp]];
		game_number = 1;
		GAMEOVER = 1;
		CORRECT = 0;
		return 0;
	}
}

void get(){
	CORRECT = 0;
	GAMEOVER = 0;
	for(temp=0;temp<check_number;temp++){
		while(P0==0xFF)
			;
		transfer = ~P0;
		P1 = ~P0;
		delay(1000);
		while(P0!=0xFF)
			;
		
		if(check_game(transfer, temp) == 0){
			break;
		}
	}
}

