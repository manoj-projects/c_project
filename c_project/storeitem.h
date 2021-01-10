typedef struct storeitem
{
int itemcode;
char itemname[31];
}STOREITEM;

/*----- Prototype ----- */
void IntlializeItems();
int GetItemName(int itemcode, char *itemname); 
void ListItems();

/*---helper function -----*/
STOREITEM *GetStoreItems();
 int GetItemsCount();

