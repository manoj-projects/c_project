#include<stdio.h>
#include<string.h>
#include"storeitem.h"

/*----- Golbal declaration ----- */
STOREITEM items[50];
int itemcount;

char filename[]="./storeitem.bin";

/*------------Intlialize Items Function ---------- */

void IntlializeItems()
{
STOREITEM item;
FILE *f;

f=fopen(filename,"rb");

itemcount=0;

while(fread(&item,sizeof(STOREITEM),1,f))
{
items[itemcount].itemcode=item.itemcode;
strcpy(items[itemcount].itemname,item.itemname);
itemcount++;
}
fclose(f);

}


/*------------List Items Function ---------- */
void ListItems()
{
int i;
STOREITEM item;
printf("\nlist of items");

for(i=0;i<itemcount;i++)
{
item=items[i];
printf("\n%3d  %-30s",item.itemcode,item.itemname);
}

}


/*------------Get Item Name Function ---------- */

int GetItemName(int itemcode, char *itemname)
{
  int flag=0,i;
  for(i=0;i<itemcount;i++)
  if(itemcode == items[i].itemcode)
  {
  flag=1;
  strcpy(itemname,items[i].itemname);
  }
return flag;
}



/*------------Get Store Items Function ---------- */

STOREITEM *GetStoreItems()
{
return items;
}


/*------------Get Items Count Function ---------- */

int GetItemsCount()
{
return itemcount;
}

