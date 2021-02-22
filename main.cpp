#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>


HWND edit1;
HWND edit2;
HWND static_result;

bool isEdit = false;
int state = 0;

bool igual = false;

#define BUTTON_ADD          001
#define BUTTON_SUBSTRACT    002
#define BUTTON_MULTIPLY     003
#define BUTTON_DIVIDY       004
#define BUTTON_RAIZCUADRADA 005
#define BUTTON_FACTORIAL    006
#define BUTTON_ELEVATE      123
#define BUTTON_ANS          8
#define BUTTON_IGUAL        9
#define BUTTON_INS          10

#define EDIT_NUMBER_UNO     100
#define EDIT_NUMBER_DOS     101

#define BUTTON_NUMBER_UNO    200
#define BUTTON_NUMBER_DOS    201
#define BUTTON_NUMBER_TRES   202
#define BUTTON_NUMBER_CUATRO 203
#define BUTTON_NUMBER_CINCO  204
#define BUTTON_NUMBER_SEIS   205
#define BUTTON_NUMBER_SIETE  206
#define BUTTON_NUMBER_OCHO   207
#define BUTTON_NUMBER_NUEVE  208
#define BUTTON_NUMBER_ZERO   209

long double adding(long double a,long double b) {
	return a + b;
}

long double substracting(long double a,long double b) {
	return a - b;
}

long double multiply(long double a,long double b) {
	return a * b;
}

long double dividy(long double a,long double b) {
	return a / b;
}

long double raiz_cuadrada(long double a) {
	return sqrt(a);
}

long double elevating(long double a,long double b) {
	return pow(a,b);
}

long double factorial(long double a) {
	for(int i = a-1; i > 0; i--) {
		a *= i;
	}
	return a;
}
/*
std::string getText(HWND hwnd){

	GetWindowText(hwnd)
}*/

void resultado(HWND hwnd);

void UpdateControls(HWND hwnd,int index) {
	
	switch(index) {

		case BUTTON_ADD:
			state = BUTTON_ADD;
			isEdit = true;
			
			if(igual){
				resultado(hwnd);
			}
			
			break;
		case BUTTON_SUBSTRACT:
			state = BUTTON_SUBSTRACT;
			isEdit = true;
			
			
			if(igual){
				resultado(hwnd);
			}
			
			break;
		case BUTTON_MULTIPLY:
			state = BUTTON_MULTIPLY;
			isEdit = true;
			
			if(igual){
				resultado(hwnd);
			}
			
			break;
		case BUTTON_DIVIDY:
			state = BUTTON_DIVIDY;
			isEdit = true;
			
			if(igual){
				resultado(hwnd);
			}
			
			break;
		case BUTTON_RAIZCUADRADA:
			state = BUTTON_RAIZCUADRADA;
			isEdit = true;
			
			if(igual){
				resultado(hwnd);
			}
			
			break;
		case BUTTON_ELEVATE:
			state = BUTTON_ELEVATE;
			isEdit = true;
			
			if(igual){
				resultado(hwnd);
			}
			break;
		case BUTTON_FACTORIAL:
			state = BUTTON_FACTORIAL;
			isEdit = true;
			
			if(igual){
				resultado(hwnd);
			}
			break;
	}
	
}

void UpdateControlsExt(HWND hwnd,int index){
	
	char res1[100];
	GetWindowText((!isEdit) ? edit1 : edit2,res1,100);
	
	std::string text = res1;
	
	igual = false;
	
	switch( index ){
		
		case BUTTON_NUMBER_UNO:
			text += "1";
			break;
		
		case BUTTON_NUMBER_DOS:
			text += "2";
			break;
		
		case BUTTON_NUMBER_TRES:
			text += "3";
			break;
		
		case BUTTON_NUMBER_CUATRO:
			text += "4";
			break;
		
		case BUTTON_NUMBER_CINCO:
			text += "5";
			break;
		
		case BUTTON_NUMBER_SEIS:
			text += "6";
			break;
		
		case BUTTON_NUMBER_SIETE:
			text += "7";
			break;
		
		case BUTTON_NUMBER_OCHO:
			text += "8";
			break;
		
		case BUTTON_NUMBER_NUEVE:
			text += "9";
			break;
		
		case BUTTON_NUMBER_ZERO:
			text += "0";
			break;
		
	}
	
	SetWindowText((!isEdit) ? edit1 : edit2,text.c_str());
}

void resultado(HWND hwnd){
	
	char res1[100];
	char res2[100];

	GetWindowText(edit1,res1,100);
	GetWindowText(edit2,res2,100);


	long double dres1 = atof(res1);
	long double dres2 = atof(res2);

	long double Res;

	switch(state) {

		case BUTTON_ADD:
			Res = adding(dres1 , dres2);
			break;
		case BUTTON_SUBSTRACT:
			Res = substracting(dres1 , dres2);
			break;
		case BUTTON_MULTIPLY:
			Res = multiply(dres1 , dres2);
			break;
		case BUTTON_DIVIDY:
			Res = dividy(dres1 , dres2);
			break;
		case BUTTON_RAIZCUADRADA:
			Res = raiz_cuadrada(dres1);
			break;
		case BUTTON_ELEVATE:
			Res = elevating(dres1,dres2);
			break;
		case BUTTON_FACTORIAL:
			Res = factorial(dres1);
			break;
	}

	std::stringstream ResString;
	std::string str;

	ResString<<Res;
	ResString>>str;

	SetWindowText(static_result , str.c_str());

}

void AddControls(HWND hwnd);

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {

		case WM_CREATE: {

			AddControls(hwnd);

			break;
		}

		case WM_COMMAND: {

			switch(LOWORD(wParam)) {

				case EDIT_NUMBER_UNO: {
					
					isEdit = false;
					
					break;
				}
				
				case EDIT_NUMBER_DOS: {
					
					isEdit = true;
					
					break;
				}
				
				case BUTTON_ADD: {

					UpdateControls(hwnd,BUTTON_ADD);

					break;
				}

				case BUTTON_SUBSTRACT: {

					UpdateControls(hwnd,BUTTON_SUBSTRACT);

					break;
				}

				case BUTTON_MULTIPLY: {

					UpdateControls(hwnd,BUTTON_MULTIPLY);

					break;
				}

				case BUTTON_DIVIDY: {

					UpdateControls(hwnd,BUTTON_DIVIDY);

					break;
				}

				case BUTTON_RAIZCUADRADA: {

					UpdateControls(hwnd,BUTTON_RAIZCUADRADA);

					break;
				}
				
				case BUTTON_ELEVATE: {
					
					UpdateControls(hwnd,BUTTON_ELEVATE);
					
					break;
				}
				
				case BUTTON_FACTORIAL: {
					
					UpdateControls(hwnd,BUTTON_FACTORIAL);
					
					break;
				}
				
				case BUTTON_ANS: {
					
					char res1[100];
					
					GetWindowText(static_result,res1,100);
					SetWindowText(edit1 , res1);
					
					break;
				}
				
				case BUTTON_NUMBER_UNO: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_UNO);
					
					break;
				}
				
				case BUTTON_NUMBER_DOS: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_DOS);
					
					break;
				}
				
				case BUTTON_NUMBER_TRES: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_TRES);
					
					break;
				}
				case BUTTON_NUMBER_CUATRO: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_CUATRO);
					
					break;
				}
				
				case BUTTON_NUMBER_CINCO: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_CINCO);
					
					break;
				}
				
				case BUTTON_NUMBER_SEIS: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_SEIS);
					
					break;
				}
				
				case BUTTON_NUMBER_SIETE: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_SIETE);
					
					break;
				}
				
				case BUTTON_NUMBER_OCHO: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_OCHO);
					
					break;
				}
				
				case BUTTON_NUMBER_NUEVE: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_NUEVE);
					
					break;
				}
				
				case BUTTON_NUMBER_ZERO: {
					
					UpdateControlsExt(hwnd,BUTTON_NUMBER_ZERO);
					
					break;
				}
				
				case BUTTON_IGUAL: {
					
					if(!igual){
						igual = true;
					}
					
					resultado(hwnd);
					
					break;
				}
				
				case BUTTON_INS: {
					
					SetWindowText(edit2,"");
					SetWindowText(edit1,"");
					SetWindowText(static_result,"");
					
					break;
				}
				
			}

			break;
		}

		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc;
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = CreateSolidBrush(RGB(100,100,130));
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Calculadora",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
	                      CW_USEDEFAULT,
	                      CW_USEDEFAULT,
	                      640,
	                      480,
	                      NULL,NULL,hInstance,NULL);
	
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	while(GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


void AddControls(HWND hwnd) {

	CreateWindow("BUTTON","",WS_VISIBLE | WS_CHILD | BS_GROUPBOX, 80,80,140,50 , hwnd , 0 , 0 , 0);
	CreateWindow("BUTTON","",WS_VISIBLE | WS_CHILD | BS_GROUPBOX, 230,80,140,50 , hwnd , 0 , 0 , 0);
	CreateWindow("BUTTON","",WS_VISIBLE | WS_CHILD | BS_GROUPBOX, 380,80,140,50 , hwnd , 0 , 0 , 0);

	edit1 = CreateWindow("EDIT","",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL, 100,100,100,20 , hwnd , (HMENU) EDIT_NUMBER_UNO , 0 , 0);
	edit2 = CreateWindow("EDIT","",WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL, 250,100,100,20 , hwnd , (HMENU) EDIT_NUMBER_DOS , 0 , 0);
	static_result = CreateWindow("EDIT","", WS_VISIBLE | WS_CHILD , 400,100,100,20 , hwnd , 0 , 0 , 0);

	CreateWindow("BUTTON","+" ,WS_VISIBLE | WS_CHILD , 80,160,60,40 , hwnd , (HMENU) BUTTON_ADD       , 0 , 0);
	CreateWindow("BUTTON","--",WS_VISIBLE | WS_CHILD , 80,210,60,40 , hwnd , (HMENU) BUTTON_SUBSTRACT , 0 , 0);
	CreateWindow("BUTTON","x" ,WS_VISIBLE | WS_CHILD , 80,260,60,40 , hwnd , (HMENU) BUTTON_MULTIPLY  , 0 , 0);
	CreateWindow("BUTTON","%" ,WS_VISIBLE | WS_CHILD , 80,310,60,40 , hwnd , (HMENU) BUTTON_DIVIDY    , 0 , 0);

	CreateWindow("BUTTON","  2 __\n   / x" ,WS_VISIBLE | WS_CHILD | BS_MULTILINE, 450,160,60,40 , hwnd , (HMENU) BUTTON_RAIZCUADRADA , 0 , 0);
	CreateWindow("BUTTON","    y\nx",WS_VISIBLE | WS_CHILD | BS_MULTILINE, 450,210,60,40 , hwnd , (HMENU) BUTTON_ELEVATE , 0 , 0);
	CreateWindow("BUTTON","! x",WS_VISIBLE | WS_CHILD, 450,260,60,40 , hwnd , (HMENU) BUTTON_FACTORIAL , 0 , 0);
	CreateWindow("BUTTON","ans",WS_VISIBLE | WS_CHILD, 450,310,60,40 , hwnd , (HMENU) BUTTON_ANS , 0 , 0);
	
	CreateWindow("BUTTON","1" ,WS_VISIBLE | WS_CHILD , 180,160,60,40 , hwnd , (HMENU) BUTTON_NUMBER_UNO       , 0 , 0);
	CreateWindow("BUTTON","2" ,WS_VISIBLE | WS_CHILD , 250,160,60,40 , hwnd , (HMENU) BUTTON_NUMBER_DOS       , 0 , 0);
	CreateWindow("BUTTON","3" ,WS_VISIBLE | WS_CHILD , 320,160,60,40 , hwnd , (HMENU) BUTTON_NUMBER_TRES      , 0 , 0);
	CreateWindow("BUTTON","4" ,WS_VISIBLE | WS_CHILD , 180,210,60,40 , hwnd , (HMENU) BUTTON_NUMBER_CUATRO    , 0 , 0);
	CreateWindow("BUTTON","5" ,WS_VISIBLE | WS_CHILD , 250,210,60,40 , hwnd , (HMENU) BUTTON_NUMBER_CINCO     , 0 , 0);
	CreateWindow("BUTTON","6" ,WS_VISIBLE | WS_CHILD , 320,210,60,40 , hwnd , (HMENU) BUTTON_NUMBER_SEIS      , 0 , 0);
	CreateWindow("BUTTON","7" ,WS_VISIBLE | WS_CHILD , 180,260,60,40 , hwnd , (HMENU) BUTTON_NUMBER_SIETE     , 0 , 0);
	CreateWindow("BUTTON","8" ,WS_VISIBLE | WS_CHILD , 250,260,60,40 , hwnd , (HMENU) BUTTON_NUMBER_OCHO      , 0 , 0);
	CreateWindow("BUTTON","9" ,WS_VISIBLE | WS_CHILD , 320,260,60,40 , hwnd , (HMENU) BUTTON_NUMBER_NUEVE     , 0 , 0);
	CreateWindow("BUTTON","0" ,WS_VISIBLE | WS_CHILD , 250,310,60,40 , hwnd , (HMENU) BUTTON_NUMBER_ZERO      , 0 , 0);
	
	CreateWindow("BUTTON","=" ,WS_VISIBLE | WS_CHILD , 180,310,60,40 , hwnd , (HMENU) BUTTON_IGUAL            , 0 , 0);
	CreateWindow("BUTTON","ins" ,WS_VISIBLE | WS_CHILD , 320,310,60,40 , hwnd , (HMENU) BUTTON_INS              , 0 , 0);
	
}






