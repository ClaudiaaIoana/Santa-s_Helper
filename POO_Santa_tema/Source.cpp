#define _CRT_SECURE_NO_WARNINGS
#include"Controler.h"
#include"IException.h"
using namespace std;

int main()
{
	//pentru a intra pe o anumifra functionalitate se apasa numarul corespunzator liniei pe care este afisata
	// ex la meniul de start pentru Login se apasa 1 iar pentru Register 2 si exit 3 si tot asa si la celelalte meniuri
	//unde trebuie introduse atribute si se afla scrie intre paranteze <> variante trebuie trecuta exact cum apare varianta dorita

	try {
		Controler::getInstance()->startApp();
	}
	catch (ExceptionFile& e)
	{
		e.print();
	}

	Controler::destroyInstance();

	return 0;
}