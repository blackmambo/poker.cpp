//Winston Hope, Jr.
//Programming II, Program # 5
//This will deal two five card poker hand
//and then determine the winner from amongst handss
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include<conio.h>//single character input... 
				//...without the use of carriage return
				
using namespace std;


void shuffle( int [][ 13 ] );

void deal(int[],int[],int[],int[]);

void print(int[],int[]);

int Ppair(int[],int[]);

int Twopair(int[],int[]);

int threeofkind(int[],int[]);

int fourofkind(int[],int[]);

int flush(int[],int[]);

int straight(int[],int[]);

void clear_deck(int[],int[],int[],int[]);

int Tie_Check(int[],int[],int);

int deck[ 4 ][ 13 ] = { 0 };



const char *suit[ 4 ] =  
      { "Hearts", "Diamonds", "Clubs", "Spades" };

   const char *face[ 13 ] = 
      { "Ace", "Deuce", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };

const char *type[7]={"none","pair","twopairs","threeofkind",
                     "fourofkind","flush","straight"};
char A=3,B=4,C=5,D=6;



int main()
{
	char welcome[]={"Welcome to Poker!."
					"        ...where aces are low.\n\n"};
					/////////////////////////////////////

	//printng a welcome screen
	/////////////////////////////////////////////
	for(int move=0;welcome[move]!='\0';move++)
	{
		cout<<welcome[move];
		for(int timer=0;timer<9999980;timer++);
		
		if(move==7||move==10||move==18)
		cout<<endl;	
	}

	///////////////////////////////////////////	
	cout<<"\n\nDo you want to run the Poker program?\n"
		<<"'y' for -yes-, any key for -no-: ";
	
	cout<<endl;
	int answer=getch();//single character imput
	cout<<endl;

	if(answer!='y')
		return 0;
	///////////////////////////////////////////////////

   int t=5;
   int hand1[5],hand2[5],hand3[5],hand4[5]; 
		
	int handtype1,handtype2;
	///////////////////////

	srand( time(NULL) );
	///////////////////
    
	shuffle( deck );
	///////////////////

    deal(hand1,hand2,hand3,hand4);
	///////////////////////

	cout<<"Player One:\n\n";
	/////////////////////////

	print(hand1,hand2);//Print the first hand
	cout<<endl;
	///////////////////////
	
    handtype1=Ppair(hand2,hand1);//Begin hand classificatiosn process	
    cout<<endl;
	//////////////////////////////
   
    cout<<"Player Two:\n\n";
	/////////////////////////////////

    print(hand3,hand4);//Print the second hand
    cout<<endl;
	cout<<endl;	
	///////////////////////////////////

	handtype2=Ppair(hand4,hand3); 
    ////////////////////////////////////  
   
   cout<<"Player One:	Player Two:"
	   <<"\n"<<type[handtype1]
	   <<"		"<<type[handtype2]<<endl;
   ////////////////////////////////////////////////////////

   if(handtype1>handtype2)
   cout<<"\nPlayer one Wins!\n\n";
   //////////////////////////////

   if(handtype1<handtype2)
   cout<<"\nPlayer two Wins!\n\n";
   ///////////////////////////////
   
   if(handtype1==handtype2)
		Tie_Check(hand2,hand4,handtype1);
   ////////////////////////////////////
    
    cout<<"\nPress 'e' to exit.\n"
        <<"Press any key to continue.";
	//////////////////////////////////////////////
        
    clear_deck(hand1,hand2,hand3,hand4);
	////////////////////////////////////////
   
    cout<<endl;
    int again=getch();
	///////////////////
    
    if(again=='e')
       return 0;
	   ////////
             
    system("cls");       
      main();
	  //////
    

   return 0;
}
//////////////////////////////////////////////////////
void shuffle( int wDeck[][ 13 ] )
{
   int row,column;

   for ( int card = 1; card <= 52; card++ ) {
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 );

      wDeck[ row ][ column ] = card;
   }
}
//////////////////////////////////////////////////////////////////
void deal(int ahand[5],int bhand[5],int chand[5],int dhand[5])
{    
  int x=0,y=0;//counter for each hand

	for ( int card = 1; card <=10; card++ )

      for ( int row = 0; row <= 3; row++ )

         for ( int column = 0; column <= 12; column++ )
			//this will deal the hands one by ones
			 if ( deck[ row ][ column ] == card )
			 {

				 if(card%2==1){
                    ahand[x]=row;
                    bhand[x]=column;
                    x++; 
				 }
                 else
					{
                   	chand[y]=row;
                    dhand[y]=column;
                    y++;
                    }
             }
               
}
//\\///////////////\\\\\\\\\\\\\\\\\\\//
void print(int hand1[5],int hand2[5])
{
      for ( int num=0; num<5; num++ )
			{
               cout << setw( 5 )<< setiosflags( ios::right )
                    << face[hand2[num]] << " of "
                    << setw( 8 )<< setiosflags( ios::left )
                    << suit[hand1[num]];

			  	   if(hand1[num]==0)
					    cout<<A;

				   if(hand1[num]==1)
					    cout<<B;

				   if(hand1[num]==2)
					    cout<<C;

				   if(hand1[num]==3)
					    cout<<D;		   			   
			   
					cout<<endl;			
	  	}              
}
/////////////////////////////////////////////////
int Ppair(int phand[5],int qhand[5])
{
     int frequency[13]={0},keep=0;
     
     int track;
    //first arrange the array in ascending osrder
     for(int b=0;b<4;b++)
     for(int c=0;c<4;c++)
       if(phand[c]<phand[c+1])
        {
           track=phand[c+1];
           phand[c+1]=phand[c];
           phand[c]=track;
        }
        
         
      //this is to find out how mand of each faces there iss     
     for(int p=0;p<5;p++)
             ++frequency[phand[p]];

     for(int p2=0;p2<=12;p2++)
     {
	   //using frequency to check for a pair
             if(frequency[p2]==2)
             {
                  keep+=2;                 
             }
     }    
      if(keep==2)//if there is only one pair
       {
       cout<<"Player has a pair!\n\n";
       return 1;
       }
	  //if there is no pair...
	  //check to two pairs
       else
      return Twopair(phand,qhand);
}
/////////////////////////////////////////////////////////
int Twopair(int phand[5],int qhand[5])
{
     int frequency[13]={0},keep=0;
     
     for(int p=0;p<5;p++)
             ++frequency[phand[p]];

     for(int p2=0;p2<=12;p2++)
     {
             if(frequency[p2]==2)
             {
                 keep+=2;
                 
             }
     }   
     if(keep==4)//Only if there are two pairs
       {
        cout<<"Player has two pairs!\n\n";
       return 2;
       }
	 //if there are no two pairs...
	 //check for three of a kind
       else
       return threeofkind(phand,qhand);
}
//////////////////////////////////////////////////////
int threeofkind(int phand[5],int qhand[5])
{
     int frequency[13]={0},keep=0;
     
     for(int p=0;p<5;p++)
             ++frequency[phand[p]];
             
     for(int p2=0;p2<=12;p2++)
     {
             if(frequency[p2]==3)
             {
                  keep+=3;                 
             }
     }
      if(keep==3)//if there is three of a kind
       {
       cout<<"Player has three of a kind!\a\a\n\n";
       return 3;
       }

       else//if there is no three of a kind...
		   //check for four of a kind
       return fourofkind(phand,qhand);
}
////////////////////////////////////////////////
int fourofkind(int phand[5],int qhand[5])
{
     int frequency[13]={0},keep=0;
     
    for(int p=0;p<5;p++)
             ++frequency[phand[p]];
             
     for(int p2=0;p2<=12;p2++)
     {
             if(frequency[p2]==4)
             {
                  keep+=4; 
                  break;                
             }
     }
      if(keep==4)//if there is a four of a kind
       {
       cout<<"\a\aPlayer has four of a kind\n\n";
       return 4;
       }
       else //if there is no four of a kind//
		   //check for a flush

       return flush(phand,qhand);
}
///////////////////////////////////////////////////////
int flush(int phand[5],int qhand[5])
{
     int frequency[13]={0},keep=0;
     
    for(int p=0;p<5;p++)//using the suit in this 
						//case to determine if						 
						//hand is a flush
             ++frequency[qhand[p]];
             
     for(int p2=0;p2<=12;p2++)
     {
             keep=frequency[p2];
             if(keep==5)
             {
              break;      
             }
     }
      if(keep==5) //if there is a flush
       {
       cout<<"Player has a flush!\a\a\n\n";
       return 5;
       }
       else//if there is no flush...
		   //check for a straight
       return straight(phand,qhand);
}
//////////////////////////////////////////////////////
int straight(int phand[5],int qhand[5])
{
     int frequency[5]={0},keep=0, x,y,z;
     
	 //checking to make sure that hand is not a flush
     for(int suit_count=0;suit_count<5;suit_count++)
             ++frequency[qhand[suit_count]];
     
	 /*a straight is determined by checking:
	 if the next value is one more than the 
	 previous value.....*/
     for(int p=0;p+1<5;p++)
     {      
		x=phand[p]; y=phand[p+1];
		/*...if the next value is not one less than
		the previous value, 'z' will be assingned 
		the value '1' to indocate that there is no 'straight'*/
        if(x+1!=y||frequency[p]==5)
        {
          z=1;
          break;          
        }
     }  
     if(z==1)//if there is no 'straight'...
			 //return zero to indicate that...
			 //there was no match for any
			 //hand type
     {
      return 0;
     }    
     else//if there is a a 'straight'...
		 //...return '6' to indicate so
      {
       cout<<"Player has a straight!\a\a\n\n";
       return 6;
       }
}
/////////////////////////////////////////////////////
//clearing the deck and hands
void clear_deck(int Hand1[5],int Hand2[5],
                int Hand3[5],int Hand4[5])
{
     for(int a=0;a<=3;a++)
     for(int b=0;b<=12;b++)
     deck[a][b]=0;

     for(int c=0;c<5;c++){
     Hand1[c]=0;Hand2[c]=0;
     Hand3[c]=0;Hand4[c]=0;}
}
     
/////////////////////////////////////////////////////
int Tie_Check(int hand2[5],int hand4[5],int ht)  
{   
	//local functions
    void pair_arrange(int[],int);
    int tie_breaker(int[],int[],int);
    
    int sum=0,sum2=0; 
    /*if the hands have no match or 
	the hands are both 'straights',
	invoke the tie breaker function 
	without the need to arrainge the
	hands in pairs as there should be no pairs
	in both hands*/
    if(ht==0||ht==6)tie_breaker(hand2,hand4,ht);
    
    else    
{
   pair_arrange(hand2,ht);
   pair_arrange(hand4,ht);
      
   /*the pair arrange function will 
   multiply the first two pairs and 
   assign it to the first element in the array.
   So the following first pair to determine a winner  */
       
       if(hand2[0]>hand4[0])cout<<"Player One Wins!";

       if(hand2[0]<hand4[0])cout<<"Player Two Wins!";

       if(hand2[0]==hand4[0])
			tie_breaker(hand2,hand4,ht);
   }  
      
       return 0; 
}
//////////////////////////////////////////////////////
void pair_arrange(int h2[],int tp)
{
		int ar[5]={0},ar2[5]={0},count=2;
		////////////////////////////

		int frequency[13]={0},
		   a,aa,keep=0;   
		//////////////////////

		for(int q=0;q<5;q++)
		{
		++frequency[h2[q]];
		}

		if(tp==1)//if the hand is a pair
				//the code will group it accoidingly
		{
		for(a=0;a<13;a++)
		{
		  if(frequency[a]==2)
		  {
			 ar[0]=a*2;//take the pair, multiply it by two
						//and assign it to the first
						//element in the array... 
			 break;
		  }
		}
		//...then take the rest and 
		//assign them to each folowing element
		int y=1;
		for(int b=0;b<a;b++)
		{
		 if(frequency[b]==1)
		 {
		  ar[y]=b;
		  y++;
		 }
		}
		
	}
	else

///////////////////////////////
if(tp==2||tp==3)//if the hand is a 'two pair' or 'three of a kind'
					//the subscript will be multiplied by three
{
	  if(tp==3) 
		  count=3;

	   for(aa=0;aa<13;aa++)
		{
		  if(frequency[aa]==count)
		  {
			 ar2[0]=aa*count;
			 break;
		  }
		}
	//////////////////////////////
	   //this is not necessary if 
	   //the hand is a three-of-kind hand
  if(tp!=3)
	{
		int yy=1;

	   for(int bb=aa+1;yy<=1;bb++)
		{

		 if(frequency[bb]==2)
		 {
		  ar[1]=bb*2;//this is for the two pari hand
		  break;
		 }

		}
	 }
	//////////////////////////////
	   int con=2;

	   if(tp==3)
			con=1;

	for(int bb=0;bb<13;bb++)
		{ 

		 if(tp==3&&con==3)//if hand is a 'three-of-kind'
							//the the loop needs to break
							//at two

		  break;  

		 if(frequency[bb]==1)
		 {
		  ar[con]=bb;
		  if(tp==3)con++;
        
		 }
		} 
}
		cout<<endl;   
	///////////////////////////////
	//copying the values back to argument 'h2'...
	//the array containing a hand-no suits, only faces
	  for(int copy=0;copy<5;copy++)
		{
		  h2[copy]=ar[copy];
      
		}
		       
}
///////////////////////////////////////////////////////////////
//this function determines the winner if the pairs are tied
int tie_breaker(int h2[],int h4[],int ty)
{
    int b,add,wild=1;
    
  if(ty==1)add=4;if(ty==2)add=3;
  if(ty==3)add=3;if(ty==4)add=2;
  
  if(ty==0||ty==6){wild=0;add=5;}
         
  //comparing each value elememt by element
  //if the element in one hand is equal to the corresponding
  //element in the other hand, the iteration will
  //continue until there is one that is greater than 
  //of less than to determine the winner.
  //if the iteration terminates and no winner is found,
  //the game is a tie.
         for(b=wild;b<add;b++)
         {
         if(h2[b]>h4[b])
           {
              cout<<"\nPlayer One Wins!\n";
              return 0;
           }
         if(h2[b]<h4[b])
           {
              cout<<"\nPlayer Two Wins!\n";
              return 0;
           }          
          }
           if(b==add)
           {
           cout<<"\nTie Game! Both Players have the same hand\n";
           }

   return 0;     
}

