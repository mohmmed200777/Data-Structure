template <class data>
class ArrayList
{
int capacity;
int lenght;
data *p;

public :
ArrayList(int size);
ArrayList(ArrayList & deep);
ArrayList &operator=(ArrayList & deep);
~ArrayList();
bool isEmpty();
bool isFull();
int getSize();
int getLenght();
bool isItemEqual(int loc,data val);
void insertEnd(data val);
void insertAt(int loc,data val);
void removeAt(int loc);
int seqserch(data val);
void removeItem(data val);
void removeAll(data val);
void retriveAt(int loc,data &val);
void replaceAt(int loc,data val);
void clearlist();
void reserve();
void print();
};