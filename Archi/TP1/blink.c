unsigned char* p5dir;
unsigned char* p5out;
volatile unsigned int i;

int main(void)
{
	//initialisation de la diode
	p5dir = (unsigned char*) 50;
	*p5dir=2;

	p5out=(unsigned char*) 49;

	while(1)
	{
		//software delay
		for(i=0; i<20000; i++){}
		
		//allumer
		*p5out=2;

		//software delay
		for(i=0; i<20000; i++){}
		
		//eteindre
		*p5out=0;
	}

}
