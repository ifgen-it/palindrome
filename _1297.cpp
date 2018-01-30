#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	cout << "Input string. Program will find longest palindrom in it:\n";
char S[1002] ;
//cin >> S;
gets(S);
char* p = &S[0];
char* pPivot = nullptr;
char* pHead = nullptr;
char* pTail = nullptr;

int Dist = 0;
int PalSize =0;
int FinPalSize = 1;
char* Palind = nullptr;
char* FinPalind = p;
bool Find = false;
bool NeedRepeat = false;

// ищем четные палиндромы
while ( *(p+1) ){
//	bool P3 = *(p+2) && (*p == *(p+2) ) ;
	bool P2 = *p == *(p+1) ;
	
/*	 if ( P3 ){
		pHead = p;
		pTail = p+2;
		PalSize = 3;
		Find = true;
	
	}*/
		 if ( P2 ){
		pHead = p;
		pTail = p+1;
		PalSize = 2;
		Find = true;
	}
	else {
		Find = false;
	}
	
	if (Find){
		
		int NotBegin = Dist;
		while ( (NotBegin > 0) && *(pTail+1) ){
			
		   if ( *(pHead-1) == *(pTail+1) ){
		   	pHead--;
		   	pTail++;
		   	NotBegin--;
		   	PalSize+=2;
		   }
		   else break;	
		}
		Palind = pHead;
		if (PalSize>FinPalSize) {
			FinPalSize = PalSize;
			FinPalind = Palind;
		}	
}  
	    	p++;
	        Dist++;	
}

p = &S[0];
Dist = 0;
PalSize = 0;

//ищем нечетные палиндромы

while ( *(p+1) ){
	bool P3 = *(p+2) && (*p == *(p+2) ) ;
//	bool P2 = *p == *(p+1) ;
	
	 if ( P3 ){
		pHead = p;
		pTail = p+2;
		PalSize = 3;
		Find = true;
	
	}
		
	else {
		Find = false;
	}
	
	if (Find){
		
		int NotBegin = Dist;
		while ( (NotBegin > 0) && *(pTail+1) ){
			
		   if ( *(pHead-1) == *(pTail+1) ){
		   	pHead--;
		   	pTail++;
		   	NotBegin--;
		   	PalSize+=2;
		   }
		   else break;	
		}
		Palind = pHead;
		if (PalSize>FinPalSize) {
			FinPalSize = PalSize;
			FinPalind = Palind;
		}	
}  
	    	p++;
	        Dist++;	
}



//печать Палиндрома
for (int i = 0; i < FinPalSize; i++){
	cout << *FinPalind;
	FinPalind++;
}
cout<<endl;

system("pause");
	return 0;
}