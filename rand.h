unsigned long int lfsr113_Bits(void)		// 40us. period = 2^113
{
	static unsigned long int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
	long int b;
	b  = ((z1 << 6) ^ z1) >> 13;
	z1 = ((z1 & 4294967294U) << 18) ^ b;
	b  = ((z2 << 2) ^ z2) >> 27;
	z2 = ((z2 & 4294967288U) << 2) ^ b;
	b  = ((z3 << 13) ^ z3) >> 21;
	z3 = ((z3 & 4294967280U) << 7) ^ b;
	b  = ((z4 << 3) ^ z4) >> 12;
	z4 = ((z4 & 4294967168U) << 13) ^ b;
	return (z1 ^ z2 ^ z3 ^ z4)%4;
}

void init_random_bits(){
	int i;
	for(i=0;i<25;i++){
		unsigned long int x = lfsr113_Bits();
		randbyte[i] = x;
	}
}



