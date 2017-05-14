#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char *argv[]);

int main( int argc, char *argv[]) {
	unsigned char pBuffer[1024];
	char sFOut[32]; sFOut[0]='\0';
	char *sMsg="Sorry, you're not deemed smart enough to use a shell - back to your GUI, n00b !\n";
	int iCfg = open( ".nullshrc", O_RDONLY);
	if ( iCfg <= 0) {
		strcpy( sFOut, "/dev/null");
	} else close( iCfg);
//	Output, /dev/null or stdout
	int iOut = sFOut[0] ? open( sFOut, O_WRONLY|O_APPEND) : 1;
	int bDone=0;
	while ( !bDone) {
		ssize_t iRd = read( 0, pBuffer, 1024);
		if ( iRd > 0) {
			if ( iOut == 1) {
				write( iOut, sMsg, strlen(sMsg));
			} else write( iOut, pBuffer, iRd);
		} else bDone=1;
	}
	if (iOut != 1) close( iOut);
	return( 0);
}
