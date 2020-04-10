#include<reg51.h>
// function door protype
void door(int,int,int);
//initialize motor pins and they are in separate port so don't try to mix them in the same port will make conflict
sbit m1_pin1 = P3^0;			
sbit m1_pin2 = P3^1;
//function delay protype
void delay(int);
void main()
{ //void
	do{	//do
		door(1500,1,0);		
	} //do
	while(1);  //infinite loop
} //void
//delay function, used frequancy= 12MHz, to get one sec: delay(200);   
// the more seconds you want increase it by muliply (no of sec you want*200) 
void delay(unsigned int count)
{
    int i,j;
    for(i=0; i<count; i++)
			for(j=0; j<925; j++);
}
// I believe that this function will be good when calling elevator but as i explained the last part can be modified with buttons
void door(int req_delay_floor,int a,int b){
	m1_pin1 = a; //if a=1,b=0	so motor rotates unti-clockwise (downstaries) & if a=0,b=1 so motor rotates clockwise (upstaries)
    m1_pin2 = b;
/*we assume to take 7.5 sec from floor to another so 
to reach one floor: req_delay_floor	= 1500
to reach two floor: req_delay_floor	= 3000
to reach three floor: req_delay_floor	= 4500
to reach four floor: req_delay_floor	= 6000
*/
	delay(req_delay_floor);	  
	m1_pin1 = 0; //stop motor
    m1_pin2 = 0;
	//
	delay(400);
	P2=0x09; //0001		90 degree indicate that door open
	delay(1000); // 5sec
	P2=0x00;
	P2=0x06; 		//-90 degree indicate that door close	 
	delay(50); //2.5sec
	// all the above lines for open and close the door and don't try to delet any comment as the entire logic won't work :((
	if(P2=0x06){
		m1_pin1 = 0; 
	    m1_pin2 = 0;
		delay(500);
		}
	// motor will stop for about 3 sec then the entire loop will begin again, i had tried  alot of methods to make this function more portable but i can't
}

