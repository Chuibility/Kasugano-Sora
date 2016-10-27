#include <cstdio>
#include <fstream>
#include <iostream>
#include <ctime>

#define KEY 12345678

using namespace std;

int Init_C[10], Dual_Timebit[70], Timebit[10], Time_Mod, C_Mod, Constant[260][260];




int main() {
	freopen( "original.txt", "r", stdin );
	freopen( "ciphertext.txt", "w", stdout );
	time_t Now_Time;
	Now_Time = time(NULL);
	Now_Time = Now_Time / 60;
	Time_Mod = Now_Time % 2333;
	int tmpC;
	tmpC = KEY;
	C_Mod = tmpC % 2333;
	for ( int i = 7; i >= 0; i-- ) {
		Init_C[i] = tmpC % 10;
		tmpC = tmpC / 10;
	}

	for ( int i = 0; i < 256; i++ ) {
		int Line = i;
		int _Time = Now_Time + i * 23;
		for ( int i = 7; i >= 0; i-- ) {
			Timebit[( i + Line ) % 8] = _Time % 10;
			_Time = _Time / 10;
		}
		for ( int i = 0; i < 64; i++ ) Dual_Timebit[i] = ( ( ( Timebit[i / 8] + Time_Mod ) * Time_Mod ) * Timebit[i % 8] + C_Mod ) % 256;
		for ( int i = 0; i < 256; i++ ) Constant[Line][i] = ( ( ( Dual_Timebit[i / 64] + Time_Mod ) * Init_C[i / 64] ) % 256 + C_Mod ) % 256;
	}
	/*ofstream fout("key.txt");
	for ( int i = 0; i < 256; i++ ) {
		for ( int j = 0; j < 256; j++ ) fout << Constant[i][j] << endl;
	}*/
	for ( int i = 0; i < 256 * 256; i++ )
		for ( int j = 0; j < 3; j++ ) {
			int tmp;
			scanf( "%d", &tmp );
			printf( "%d%c", ( tmp + Constant[i / 256][i % 256] + j * 255 / 3 ) % 256, j == 2 ? '\n' : ' ' );
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
