#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "storeitem.h"
#include "stockTxn.h"

void Menu();


int main()
{
IntlializeItems();
Menu();

}

/*--------MENU function----- */

    void Menu()
	{
	
	 int opt;
	 
	 while(1)
	 {
       system("cls");
	  printf("\n \n      XYZ Corporation");
	  printf("\n####### Stock Management ########");
	  printf("\n    ------------------------------");
	  printf("\n   |     1.Stock Reciept          |");
	  printf("\n    -------------------------------");
	  printf("\n   |     2.Stock Issue            |");
	  printf("\n    ------------------------------");
	  printf("\n   |     3.Stock List             |");
	  printf("\n    ------------------------------");
	  printf("\n   |     4.Stock Transaction List |");
	  printf("\n    ------------------------------");
	  printf("\n   |     5.View store Item        |");
	  printf("\n    ------------------------------");
	  printf("\n   |     6.Exit                   |");
	  printf("\n    ------------------------------");
	  printf("\n\nEnter the choice : ");
	  scanf("%d",&opt);
	  
	  fflush(stdin);
	  
	  switch(opt)
	  { 
	     case 1:
		 Reciept('R');
		 break;
		 case 2:
		 Reciept('I');
		 break;
		 case 3:
		  StockList();
		 break;
		 case 4:
		 ListTransaction();
		 break;
		 case 5:
		 ListItems();
		 break;
		 case 6:
		 return;
		 break;
		 
		 default:
		 printf("Invalid Option");
		 break;
		 
		 
		 
	  }
	  printf("\nPress a key to Continue");
	  getch();
	  
	  }
	
	}


  

