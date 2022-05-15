#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define F(B,C,D) ((B & C) | (~B & D))
#define G(B,C,D) ((B & D) | (C & ~D))
#define H(B,C,D) (B ^ C ^ D)
#define I(B,C,D) (C ^ (B | ~D))

#define FF(A, B, C, D, M, S, K){\
	A += K + M + F(B,C,D);\
	A = ((A << S) | (A >> (32 - (S))));\
	A += B;}

#define GG(A, B, C, D, M, S, K){\
	A += K + M + G(B,C,D);\
	A = ((A << S) | (A >> (32 - (S))));\
	A += B;}

#define HH(A, B, C, D, M, S, K){\
	A += K + M + H(B,C,D);\
	A = ((A << S) | (A >> (32 - (S))));\
	A += B;}

#define II(A, B, C, D, M, S, K){\
	A += K + M + I(B,C,D);\
	A = ((A << S) | (A >> (32 - (S))));\
	A += B;}




int CountChar(char string[]){
	int chars = 0;
	while (1){
		if (string[chars] == '\0') break;
		chars++;
	}
	return chars;
}

int IntLength(int chars, int *div){
	int mod = (8*chars % 512);
	*div = 8*chars/512;
	if (mod >= 448){
		*div = *div +1;
	}
	return (*div+1)*16;
}

void Rounds(unsigned int *A,unsigned int *B,unsigned int *C,unsigned int *D, unsigned long int K[],int S[],unsigned int message[], int div){

	FF(*A, *B, *C, *D, message[div + 0], S[0], K[0]);
	FF(*D, *A, *B, *C, message[div + 1], S[1], K[1]);
	FF(*C, *D, *A, *B, message[div + 2], S[2], K[2]);
	FF(*B, *C, *D, *A, message[div + 3], S[3], K[3]);

	FF(*A, *B, *C, *D, message[div + 4], S[4], K[4]);
	FF(*D, *A, *B, *C, message[div + 5], S[5], K[5]);
	FF(*C, *D, *A, *B, message[div + 6], S[6], K[6]);
	FF(*B, *C, *D, *A, message[div + 7], S[7], K[7]);

	FF(*A, *B, *C, *D, message[div + 8], S[8], K[8]);
	FF(*D, *A, *B, *C, message[div + 9], S[9], K[9]);
	FF(*C, *D, *A, *B, message[div + 10], S[10], K[10]);
	FF(*B, *C, *D, *A, message[div + 11], S[11], K[11]);

	FF(*A, *B, *C, *D, message[div + 12], S[12], K[12]);
	FF(*D, *A, *B, *C, message[div + 13], S[13], K[13]);
	FF(*C, *D, *A, *B, message[div + 14], S[14], K[14]);
	FF(*B, *C, *D, *A, message[div + 15], S[15], K[15]);

	GG(*A, *B, *C, *D, message[div + 1], S[16], K[16]);
	GG(*D, *A, *B, *C, message[div + 6], S[17], K[17]);
	GG(*C, *D, *A, *B, message[div + 11], S[18], K[18]);
	GG(*B, *C, *D, *A, message[div + 0], S[19], K[19]);

	GG(*A, *B, *C, *D, message[div + 5], S[20], K[20]);
	GG(*D, *A, *B, *C, message[div + 10], S[21], K[21]);
	GG(*C, *D, *A, *B, message[div + 15], S[22], K[22]);
	GG(*B, *C, *D, *A, message[div + 4], S[23], K[23]);

	GG(*A, *B, *C, *D, message[div + 9], S[24], K[24]);
	GG(*D, *A, *B, *C, message[div + 14], S[25], K[25]);
	GG(*C, *D, *A, *B, message[div + 3], S[26], K[26]);
	GG(*B, *C, *D, *A, message[div + 8], S[27], K[27]);

	GG(*A, *B, *C, *D, message[div + 13], S[28], K[28]);
	GG(*D, *A, *B, *C, message[div + 2], S[29], K[29]);
	GG(*C, *D, *A, *B, message[div + 7], S[30], K[30]);
	GG(*B, *C, *D, *A, message[div + 12], S[31], K[31]);

	HH(*A, *B, *C, *D, message[div + 5], S[32], K[32]);
	HH(*D, *A, *B, *C, message[div + 8], S[33], K[33]);
	HH(*C, *D, *A, *B, message[div + 11], S[34], K[34]);
	HH(*B, *C, *D, *A, message[div + 14], S[35], K[35]);

	HH(*A, *B, *C, *D, message[div + 1], S[36], K[36]);
	HH(*D, *A, *B, *C, message[div + 4], S[37], K[37]);
	HH(*C, *D, *A, *B, message[div + 7], S[38], K[38]);
	HH(*B, *C, *D, *A, message[div + 10], S[39], K[39]);

	HH(*A, *B, *C, *D, message[div + 13], S[40], K[40]);
	HH(*D, *A, *B, *C, message[div + 0], S[41], K[41]);
	HH(*C, *D, *A, *B, message[div + 3], S[42], K[42]);
	HH(*B, *C, *D, *A, message[div + 6], S[43], K[43]);

	HH(*A, *B, *C, *D, message[div + 9], S[44], K[44]);
	HH(*D, *A, *B, *C, message[div + 12], S[45], K[45]);
	HH(*C, *D, *A, *B, message[div + 15], S[46], K[46]);
	HH(*B, *C, *D, *A, message[div + 2], S[47], K[47]);

	II(*A, *B, *C, *D, message[div + 0], S[48], K[48]);
	II(*D, *A, *B, *C, message[div + 7], S[49], K[49]);
	II(*C, *D, *A, *B, message[div + 14], S[50], K[50]);
	II(*B, *C, *D, *A, message[div + 5], S[51], K[51]);

	II(*A, *B, *C, *D, message[div + 12], S[52], K[52]);
	II(*D, *A, *B, *C, message[div + 3], S[53], K[53]);
	II(*C, *D, *A, *B, message[div + 10], S[54], K[54]);
	II(*B, *C, *D, *A, message[div + 1], S[55], K[55]);

	II(*A, *B, *C, *D, message[div + 8], S[56], K[56]);
	II(*D, *A, *B, *C, message[div + 15], S[57], K[57]);
	II(*C, *D, *A, *B, message[div + 6], S[58], K[58]);
	II(*B, *C, *D, *A, message[div + 13], S[59], K[59]);

	II(*A, *B, *C, *D, message[div + 4], S[60], K[60]);
	II(*D, *A, *B, *C, message[div + 11], S[61], K[61]);
	II(*C, *D, *A, *B, message[div + 2], S[62], K[62]);
	II(*B, *C, *D, *A, message[div + 9], S[63], K[63]);
}


int main(){
	int S[] = {
		7,12,17,22,
		7,12,17,22,
		7,12,17,22,
		7,12,17,22,

		5,9,14,20,
		5,9,14,20,
		5,9,14,20,
		5,9,14,20,

		4,11,16,23,
		4,11,16,23,
		4,11,16,23,
		4,11,16,23,

		6,10,15,21,
		6,10,15,21,
		6,10,15,21,
		6,10,15,21
	};
	unsigned int A = 0x67452301, B = 0xefcdab89, C = 0x98badcfe, D = 0x10325476;
	unsigned int Astart, Bstart, Cstart, Dstart;
	char password[] = {"test"};
	int chars = CountChar(password);
	int div;
	int intsize = IntLength(chars, &div);
	unsigned int * padded = malloc(intsize * sizeof(int));
	int z = 0;
	unsigned long int msglgth = chars * 8;
	int i;
	int charloop = 0;
	int appended = 0;
	while(z<(intsize - 2)){
		i =4;
		while(i > 0){
			if (charloop == chars && appended == 0){
				padded[z] += 128<<((charloop%4)*8);
				appended = 1;
			}
			i--;
			if(4 * (charloop/4)+(3-charloop%4) < chars){
				padded[z] += (password[4 * (charloop/4)+(3-charloop%4)]<<(i*8));
			}
			charloop++;
		}
		z++;
	}


	z=0;
	padded[intsize - 2] = msglgth;
	padded[intsize - 1] = msglgth>>32;
	double Kdoub[64];
	unsigned long int K[64];
	while(z<64){
		Kdoub[z] = fabs(sin(z+1))*4294967296;
		K[z] = (unsigned long int) Kdoub[z];
		z++;
	}
	int divtemp = 0;
	while (divtemp <= div){
		Astart = A;
		Bstart = B;
		Cstart = C;
		Dstart = D;
		Rounds(&A, &B, &C, &D, K, S, padded, divtemp*16);
		divtemp++;
		A += Astart;
		B += Bstart;
		C += Cstart;
		D += Dstart;

	}
	free(padded);
	printf("The MD5hash of %s is ", password);
	printf("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x\n", A&0xff, (A>>8)&0xff, (A>>16)&0xff, (A>>24)&0xff, B&0xff, (B>>8)&0xff, (B>>16)&0xff, (D>>24)&0xff, C&0xff, (C>>8)&0xff, (C>>16)&0xff, (C>>24)&0xff, D&0xff, (D>>8)&0xff, (D>>16)&0xff, (D>>24)&0xff);
	return 0;
}


