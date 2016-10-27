#include <cstring>
#include <cstdio>
#include <cmath>


typedef unsigned short    UINT16;    //store pixel rgb data
typedef unsigned char    BYTE;    //store r\g\b data



int main(){
    UINT16 pattern[1000][1000];    //16bit 640*480 rgb image.
    BYTE rgb[3];
    BYTE r;                        //rgb variable
    BYTE g;
    BYTE b;

    FILE *fp_read;
    fp_read = fopen( "1.bmp", "r" );    //open the source bitmap

    if( fp_read == NULL )
    {
        printf( "can't open files!" );
        return 0;
    }

    char bmp_head[54];
    //读出BMP头，抛弃不要
    fread( bmp_head, sizeof(char)*54, 1, fp_read );

    for ( int i = 0 ; i < 480; i++ )
        for ( int j=0 ; j < 640; j++ )
        {
            fread( rgb, 3, 1, fp_read );        //read rgb data of a pixel

            r = rgb[0];
            g = rgb[1];
            b = rgb[2];

            pattern[j][i] = ( ( r&0xf8 ) << 8 ) | ( ( g&0xfc ) << 3 ) | ( ( b&0xf8 ) >> 3 );
        }

    fclose(fp_read);
    freopen( "pic.txt", "w", stdout );
    for ( int i = 0; i < 480; i++ )
        for ( int j = 0; j < 640; j++ ) printf( "%d%c", pattern[j][i], j == 9 ? '\n' : ' ' );
    return 0;
    fclose(stdout);
}
