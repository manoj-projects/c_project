#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "stockTxn.h"
#include "storeitem.h"

char stkfilename[]="./stocktxn.bin";


/*------------Reciept Entry and Issue Function ---------- */
void Reciept(char txn)
{
  FILE *f;
  
   STOCK stk;
   char itemname[31];
   int itemfound;
   char opt;
   
f=fopen(stkfilename,"ab");

printf("\nEnter the itemcode :");
scanf("%d",&stk.itemcode);

fflush(stdin);

itemfound=GetItemName(stk.itemcode,itemname);

if (itemfound==0)
{
printf("\nInvalid ITEM code");
return;
}

printf("ItemName : %-s",itemname);
printf("\nIs this item name is correct?(Y/N)");
scanf("%c",&opt);

if(opt=='N'||opt=='n')
return;

printf("\nReceipt Qty :");
scanf("%f",&stk.qty);

fflush(stdin);

stk.txn=txn;

fwrite(&stk,sizeof(STOCK),1,f);
fclose(f);
}


/*------------List Transcation Function ---------- */

void ListTransaction()
{
FILE *f;
STOCK item;
float rt=0,it=0,r,i,stk=0;
char itemname[31];
int itemcode,itemfound;

printf("\nEnter the itemcode :");
scanf("%d",&itemcode);
fflush(stdin);
itemfound=GetItemName(itemcode,itemname);


if (itemfound==0)
{
printf("\nInvalid ITEM code");
return;
}
printf("Selected Item:     %-s\n",itemname);
f=fopen(stkfilename,"rb");
while(fread(&item,sizeof(STOCK),1,f))
{
if(item.itemcode==itemcode)
{
r=0;
i=0;
if(item.txn=='R')
    r=item.qty;
else
    i=item.qty; 
rt +=r;
it +=i;
printf("\n%-10s",item.txn=='R'?"Receipt":"Issue") ;

if(r!=0)
  printf("     %10.3f",r);
else
  printf("%10s       %10.3f","",i); 
		
}
}
if((rt>0||it>0) !=0)
{
printf("\n%10s        --------    --------","");
printf("\nTotal:         %10.3f  %10.3f",rt,it);

if((rt-it)!=0)
{
if(rt>it)
printf("\n\ncl.stock:      %10.3f",rt-it);
else
printf("\n\ncl.stock: %10s       %10.3f","",it-rt);
}
}
else 
	printf("\n\nNo transaction found.");
fclose(f);
}

/*------------closed Stock Function ---------- */
float cl(int itemcode)
{
FILE *f;
STOCK item;

float stk=0;
f=fopen(stkfilename,"rb");

while(fread(&item,sizeof(STOCK),1,f))
{

	if(item.itemcode==itemcode)
	{
	stk +=(item.txn=='R')?item.qty: -item.qty;
	}

}
fclose(f);
return stk;
}


/*------------Stock List Function ---------- */

void StockList()
{
int i;
STOREITEM item;
float cs;

STOREITEM *items=GetStoreItems();
int itemcount =GetItemsCount();

for(i=0;i<itemcount;i++)
{
	item=items[i];
	cs=cl(item.itemcode);
	if(cs!=0)
	printf("\n%d  %-20s %7.3f",item.itemcode,item.itemname,cs);

}


getch();
}

