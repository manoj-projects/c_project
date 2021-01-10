typedef struct stock{

int itemcode;
float qty;
char txn;

}STOCK;

/*------------stockTxn Prototypes ---------- */

void Reciept(char txn);
void ListTransaction();

float cl(int itemcode);
void StockList();

