#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>
//#include <android/log.h>
//#include <jni.h>
#include "hpdf.h"

//#define  LOG_TAG    "png2pdf"
//#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
//#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

struct HeadInfo
{
	char HIname[32];
	char HIsex[32];
	char HIspeed[32];
	char HIhr[32];
	char HIpvcs[32];
	char HIdoctor[32];
	char HIid[32];
	char HIgain[32];
	char HIst1[32];
	char HIst2[32];
	char HItime[32];
	char HImsg[32];
};

struct HeadInfo gHI;
char g_analysismsg[64];

jmp_buf env;
#ifdef HPDF_DLL
void  __stdcall
#else
void
#endif
error_handle(HPDF_STATUS errorno,	HPDF_STATUS detail_no, void* user_data)
{
	longjmp(env, 1);
	//LOGE("error_handle error occur errorno = %d\n", errorno);
}

void write_bottom(HPDF_Page page, HPDF_Font font){
	 
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    
	HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetFontAndSize(page, font, 12);
    /*
     * Rotating text
     */
    angle1 = -90;                   /* A rotation of 30 degrees. */
    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-20, 500);
    HPDF_Page_ShowText (page, "12��ͬ���ĵ�ͼ���浥");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                15, 230);
    HPDF_Page_ShowText (page, "ע�����в����������辭��ҽ������ȷ��");
    HPDF_Page_EndText (page);

	HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                15, 820);
    HPDF_Page_ShowText (page, "ZTE����");
    HPDF_Page_EndText (page);
    
    
}

void write_head(HPDF_Page page, HPDF_Font font, const char* name, const char* sex,
	const char* speed, const char* hr, const char* pvcs, const char* doctor, 
	const char* id, const char* gain, const char* st1, const char* st2, const char* time){
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    int GAP1 = 40;
    int BASE1 = 130;
    int GAP2 = 60;
    int BASE2 = 130;
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    printf("height = %f, width = %f\n", height, width);
    
	HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetFontAndSize(page, font, 10);//12
    /*
     * Rotating text
     */
    angle1 = -90;                   /* A rotation of 30 degrees. */
    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
    
    //name
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1);
    HPDF_Page_ShowText (page, name);
    HPDF_Page_EndText (page);
    //sex
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 720-BASE1);
    HPDF_Page_ShowText (page, sex);
    HPDF_Page_EndText (page);
    //speed
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 650-BASE1);
    HPDF_Page_ShowText (page, speed);
    HPDF_Page_EndText (page);
    //hr
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 570-BASE1);
    HPDF_Page_ShowText (page, hr);
    HPDF_Page_EndText (page);
    //pvcs
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 500-BASE1);
    HPDF_Page_ShowText (page, pvcs);
    HPDF_Page_EndText (page);
    //doctor
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 450-BASE1);
    HPDF_Page_ShowText (page, doctor);
    HPDF_Page_EndText (page);
    
    //analysis
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 350-BASE1);
    HPDF_Page_ShowText (page, g_analysismsg);
    HPDF_Page_EndText (page);
    
    //id
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 820-BASE2);
    HPDF_Page_ShowText (page, id);
    HPDF_Page_EndText (page);
    //gain
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 630-BASE2);
    HPDF_Page_ShowText (page, gain);
    HPDF_Page_EndText (page);
    //st1
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 530-BASE2);
    HPDF_Page_ShowText (page, st1);
    HPDF_Page_EndText (page);
    //st2
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 470-BASE2);
    HPDF_Page_ShowText (page, st2);
    HPDF_Page_EndText (page);
    //time
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 400-BASE2);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
	
	// HPDF_Page_BeginText (page);
    // HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                // width-GAP2-20, 450-BASE1);
    // HPDF_Page_ShowText (page, doctor);
    // HPDF_Page_EndText (page);
	
	// HPDF_Page_BeginText (page);
    // HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                // width-GAP2-20, 400-BASE2-90);
    // HPDF_Page_ShowText (page, time);
    // HPDF_Page_EndText (page);
}

float coefficientECG = 0.8f;
float coefficientV = 0.2f;

// float ratio = 0.02f;
// float ratio_v = 0.05f;

float ratio = 0.8f;
float ratio_v = 0.2f;
//��һ�� I,II,III
void drawcurve(HPDF_Doc pdf, HPDF_Page page, float* arr, int len, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 130+60*index;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
	for(i = height-25, j = 0; i > height-220 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		
		// HPDF_Page_MoveTo (page, X+arr[j]*0.8, i);
		// HPDF_Page_LineTo (page,  X+arr[j+1]*0.8, i-0.6);
		HPDF_Page_MoveTo (page, X+arr[j]*ratio, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*ratio, i-0.6);
		
		HPDF_Page_Stroke (page);
	}
}
//�ڶ��� aVR,aVL,aVF
void drawcurve_column(HPDF_Doc pdf, HPDF_Page page, float* arr, int len, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 130+60*index;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
	for(i = height-230, j = 0; i > height/2+10 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		
		// HPDF_Page_MoveTo (page, X+arr[j]*0.8, i);
		// HPDF_Page_LineTo (page,  X+arr[j+1]*0.8, i-0.6);
		HPDF_Page_MoveTo (page, X+arr[j]*ratio, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*ratio, i-0.6);
		
		HPDF_Page_Stroke (page);
	}
}



void drawbottomcurve(HPDF_Doc pdf, HPDF_Page page, float* arr, int len)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 60;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	for(i = height-25, j = 0; i >= 25 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*ratio, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*ratio, i-0.6);
		HPDF_Page_Stroke (page);
		//HPDF_Page_Fill (page);
	}
}

//������ V1,V2,V3
void drawcurveV(HPDF_Doc pdf, HPDF_Page page, float* arr, int len, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	int k;
	float i;
	int Y;
	int j;
	float X;
	X = 130+60*index;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetRGBFill (page, 0, 0, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	for(i = height/2-5, j = 0; i >= height/2-210 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*ratio_v, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*ratio_v, i-0.6);
		HPDF_Page_Stroke (page);
	}
}

//������ V4,V5,V6
void drawcurveV_column(HPDF_Doc pdf, HPDF_Page page, float* arr, int len, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	int k;
	float i;
	int Y;
	int j;
	float X;
	X = 130+60*index;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetRGBFill (page, 0, 0, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	for(i = height/2-220, j = 0; i >= 25 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*ratio_v, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*ratio_v, i-0.6);
		HPDF_Page_Stroke (page);
	}
}


void print_grid(HPDF_Doc pdf, HPDF_Page page)
{
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    HPDF_UINT x, y;
	const HPDF_UINT16 DASH_MODE1[] = {2};
    //HPDF_Page_SetFontAndSize (page, font, 5);
    //HPDF_Page_SetGrayFill (page, 0.4);
 //   HPDF_Page_SetGrayStroke (page, 0.8);

    /* Draw horizontal lines */
	//y = 20;
	//while(y <= height-25){
	//	HPDF_Page_SetLineWidth (page, 0.5);
	//	HPDF_Page_MoveTo (page, 30, y);
    //    HPDF_Page_LineTo (page, width-100, y);
    //    HPDF_Page_Stroke (page);
	//	y += 15;
	//}
	//
	//HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);
	HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);
	y = 20;
	while(y <= height-25){
		HPDF_Page_SetLineWidth (page, 0.1);
		HPDF_Page_MoveTo (page, 30, y);
        HPDF_Page_LineTo (page, width-100, y);
        HPDF_Page_Stroke (page);
		y += 3;
	}
	//HPDF_Page_SetDash (page, NULL, 0, 0);
	HPDF_Page_SetRGBStroke (page, 0, 0, 0);
	//
	//x = 30;
	//while(x <= width-100){
	//	HPDF_Page_SetLineWidth (page, 0.5);
	//	HPDF_Page_MoveTo (page, x, 20);
    //    HPDF_Page_LineTo (page, x, height-26);
    //    HPDF_Page_Stroke (page);
	//	x += 15;
	//}
	//HPDF_Page_SetRGBStroke (page, 0.20, 0.20, 0.20);
	//
	//HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);
	x = 30;
	while(x <= width-100){
		HPDF_Page_SetLineWidth (page, 0.1);
		HPDF_Page_MoveTo (page, x, 20);
        HPDF_Page_LineTo (page, x, height-26);
        HPDF_Page_Stroke (page);
		x += 3;
	}
	HPDF_Page_SetRGBStroke (page, 0, 0, 0);
	
		y = 20;
	while(y <= height-25){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 30, y);
        HPDF_Page_LineTo (page, width-100, y);
        HPDF_Page_Stroke (page);
		y += 15;
	}
	
		x = 30;
	while(x <= width-100){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, 20);
        HPDF_Page_LineTo (page, x, height-26);
        HPDF_Page_Stroke (page);
		x += 15;
	}
	
	//HPDF_Page_SetDash (page, NULL, 0, 0);
	//
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineWidth (page, 3.0);
	HPDF_Page_MoveTo (page, 28, 20);
    HPDF_Page_LineTo (page, 28, height-26);
    HPDF_Page_Stroke (page);

   // HPDF_Page_SetGrayFill (page, 0);
   //HPDF_Page_SetGrayStroke (page, 0);
}


void print_flag(HPDF_Doc pdf, HPDF_Page page, HPDF_Font font)
{
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    char* colume1[] = {"III", "II", "I"};
    char* colume2[] = {"aVF", "aVL", "aVR"};
    char* colume3[] = {"V3", "V2", "V1"};
   	char* colume4[] = {"V6", "V5", "V4"};
    HPDF_UINT x, y;
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    HPDF_Page_SetGrayStroke (page, 0);

	HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetFontAndSize(page, font, 12);
    /*
     * Rotating text
     */
    angle1 = -90;                   /* A rotation of 30 degrees. */
    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
        
    /* Draw horizontal lines */
    int flag_width = 10;
    int flag_height = 30;//30
	int base = 0;
    int i;
	base = 10;
    for(i = 0; i < 3; i++){
    	float X = 172+124*i;
    	HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_MoveTo (page, X, height-10);
	    HPDF_Page_LineTo (page, X, height-15);
	    HPDF_Page_MoveTo (page, X, height-15);
	    HPDF_Page_LineTo (page, X+flag_height, height-15);
	    HPDF_Page_LineTo (page, X+flag_height, height-20);
	    HPDF_Page_LineTo (page, X, height-20);
	    HPDF_Page_LineTo (page, X, height-25);
	    HPDF_Page_Stroke (page);
	    
	    HPDF_Page_BeginText (page);
	    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
	                X+flag_height, height-10);
	    HPDF_Page_ShowText (page, colume1[i]);
	    HPDF_Page_EndText (page);
    }
    
    int temp_height = height-210;
    for(i = 0; i < 3; i++){
    	float X = 172+124*i;
    	HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_MoveTo (page, X, temp_height-10);
	    HPDF_Page_LineTo (page, X, temp_height-15);
	    HPDF_Page_MoveTo (page, X, temp_height-15);
	    HPDF_Page_LineTo (page, X+flag_height, temp_height-15);
	    HPDF_Page_LineTo (page, X+flag_height, temp_height-20);
	    HPDF_Page_LineTo (page, X, temp_height-20);
	    HPDF_Page_LineTo (page, X, temp_height-25);
	    HPDF_Page_Stroke (page);
	    
	    HPDF_Page_BeginText (page);
	    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
	                X+flag_height, temp_height-10);
	    HPDF_Page_ShowText (page, colume2[i]);
	    HPDF_Page_EndText (page);
    }
    
    base = -8;
    for(i = 0; i < 3; i++){
    	float X = 172+124*i;
    	HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_MoveTo (page, X, height/2-base);
	    HPDF_Page_LineTo (page, X, height/2-(base+5));
	    HPDF_Page_MoveTo (page, X, height/2-(base+5));
	    HPDF_Page_LineTo (page, X+flag_height, height/2-(base+5));
	    HPDF_Page_LineTo (page, X+flag_height, height/2-(base+10));
	    HPDF_Page_LineTo (page, X, height/2-(base+10));
	    HPDF_Page_LineTo (page, X, height/2-(base+15));
	    HPDF_Page_Stroke (page);
	    
	    HPDF_Page_BeginText (page);
	    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
	                X+flag_height, height/2-base);
	    HPDF_Page_ShowText (page, colume3[i]);
	    HPDF_Page_EndText (page);
    }
    
    temp_height = height/2-200;
    for(i = 0; i < 3; i++){
    	float X = 172+124*i;
    	HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_MoveTo (page, X, temp_height-10);
	    HPDF_Page_LineTo (page, X, temp_height-15);
	    HPDF_Page_MoveTo (page, X, temp_height-15);
	    HPDF_Page_LineTo (page, X+flag_height, temp_height-15);
	    HPDF_Page_LineTo (page, X+flag_height, temp_height-20);
	    HPDF_Page_LineTo (page, X, temp_height-20);
	    HPDF_Page_LineTo (page, X, temp_height-25);
	    HPDF_Page_Stroke (page);
	    
	    HPDF_Page_BeginText (page);
	    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
	                X+flag_height, temp_height-10);
	    HPDF_Page_ShowText (page, colume4[i]);
	    HPDF_Page_EndText (page);
    }
	
	float X = 45;
	HPDF_Page_SetLineWidth (page, 0.2);
	HPDF_Page_MoveTo (page, X, height-10);
	HPDF_Page_LineTo (page, X, height-15);
	HPDF_Page_MoveTo (page, X, height-15);
	HPDF_Page_LineTo (page, X+flag_height, height-15);
	HPDF_Page_LineTo (page, X+flag_height, height-20);
	HPDF_Page_LineTo (page, X, height-20);
	HPDF_Page_LineTo (page, X, height-25);
	HPDF_Page_Stroke (page);
	
	HPDF_Page_BeginText (page);
	HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
				X+flag_height, height-10);
	HPDF_Page_ShowText (page, "II");
	HPDF_Page_EndText (page);
   // HPDF_Page_SetGrayFill (page, 0);
   // HPDF_Page_SetGrayStroke (page, 0);
}

int ecg2pdf(const char* filename, float* arrecgI, int len, float* arrecgII, float* arrecgIII, float* arrecgaVR, float* arrecgaVL, float* arrecgaVF, 
		float* arrecgV1, float* arrecgV2, float* arrecgV3, float* arrecgV4, float* arrecgV5, float* arrecgV6)
{
	HPDF_Doc pdf;
	HPDF_Font font;
	HPDF_Page page;
	pdf = HPDF_New(error_handle, NULL);
	if(!pdf)
	{

		return 1;
	}

	if(setjmp(env))
	{
		HPDF_Free(pdf);
		return 1;
	}
	HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
	
	HPDF_UseCNSFonts(pdf);
    HPDF_UseCNTFonts(pdf);
    HPDF_UseCNTEncodings(pdf);
    HPDF_UseCNSEncodings(pdf);
    
	font = HPDF_GetFont(pdf, "SimHei", "GBK-EUC-H");
	page = HPDF_AddPage(pdf);
	//HPDF_Page_SetRotate(page, 90);
	HPDF_Page_SetRotate(page, 270);
	print_grid(pdf, page);
	print_flag(pdf, page, font);
	
	/*drawcurve(pdf, page, arrecgI, len, 5);
	drawcurve(pdf, page, arrecgII, len, 4);
	drawcurve(pdf, page, arrecgIII, len, 3);
	drawcurve(pdf, page, arrecgaVR, len, 2);
	drawcurve(pdf, page, arrecgaVL, len, 1);
	drawcurve(pdf, page, arrecgaVF, len, 0);*/
	
	
	drawcurve(pdf, page, arrecgI, len, 5);
	drawcurve(pdf, page, arrecgII, len, 3);
	drawcurve(pdf, page, arrecgIII, len, 1);
	drawcurve_column(pdf, page, arrecgaVR, len, 5);
	drawcurve_column(pdf, page, arrecgaVL, len, 3);
	drawcurve_column(pdf, page, arrecgaVF, len, 1);
	
	
	drawbottomcurve(pdf, page, arrecgII, len);
	/*drawcurveV(pdf, page, arrecgV1, len, 5);
	drawcurveV(pdf, page, arrecgV2, len, 4);
	drawcurveV(pdf, page, arrecgV3, len, 3);
	drawcurveV(pdf, page, arrecgV4, len, 2);
	drawcurveV(pdf, page, arrecgV5, len, 1);
	drawcurveV(pdf, page, arrecgV6, len, 0);*/
	
	drawcurveV(pdf, page, arrecgV1, len, 5);
	drawcurveV(pdf, page, arrecgV2, len, 3);
	drawcurveV(pdf, page, arrecgV3, len, 1);
	
	drawcurveV_column(pdf, page, arrecgV4, len, 5);
	drawcurveV_column(pdf, page, arrecgV5, len, 3);
	drawcurveV_column(pdf, page, arrecgV6, len, 1);
	//
	write_bottom(page, font);
	write_head(page, font, "������ŷ������", "�Ա���", "���٣�25mm/s", "HR��80bmp", "PVCs:10", "ҽ��������ʿ", "���֤�ţ�135164251636943648", "���棺10����/����", "ST1��0mv", "ST2:10mv","���ʱ�䣺2016-01-17 14:01");
	//write_head(page, font, gHI.HIname, gHI.HIsex, gHI.HIspeed, gHI.HIhr, gHI.HIpvcs, gHI.HIdoctor, gHI.HIid, gHI.HIgain, gHI.HIst1, gHI.HIst2, gHI.HItime);
	HPDF_SaveToFile (pdf, filename);

    HPDF_Free (pdf);
}

/*
JNIEXPORT void Java_com_tyky_medical_healthbox_activities_setting_EcgReoprtActivity_PrintToPdf(JNIEnv* env,
		jobject obj, jstring picPath, jstring pdfPath);
void Java_com_tyky_medical_healthbox_activities_setting_EcgReoprtActivity_PrintToPdf(JNIEnv* env,
		jobject obj, jstring picPath, jstring pdfPath)
{
	const char *pngpath = (*env)->GetStringUTFChars(env, picPath, 0);
	const char *pdfpath = (*env)->GetStringUTFChars(env, pdfPath, 0);

	//png2pdf(pngpath, pdfpath);
	(*env)->ReleaseStringUTFChars(env, picPath, pngpath);
	(*env)->ReleaseStringUTFChars(env, pdfPath, pdfpath);
}*/


//����java������ecg���ݣ���������
// JNIEXPORT void  Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragment_PrintEcgPDF(JNIEnv* env, jobject obj, jstring pdfPath,jfloatArray Arr);

/*
JNIEXPORT void   Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragmentShenMai_PrintEcgPDF(JNIEnv* env, jobject obj, jstring pdfPath, jfloatArray ArrEcgI, jfloatArray ArrEcgII, jfloatArray ArrEcgIII, jfloatArray ArrEcgaVR, jfloatArray ArrEcgaVL, jfloatArray ArrEcgaVF,
jfloatArray ArrEcgV1, jfloatArray ArrEcgV2, jfloatArray ArrEcgV3, jfloatArray ArrEcgV4, jfloatArray ArrEcgV5, jfloatArray ArrEcgV6, jfloat ratioecg,
jfloat ratiov);

void Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragmentShenMai_PrintEcgPDF(JNIEnv* env, jobject obj, jstring pdfPath, jfloatArray ArrEcgI, jfloatArray ArrEcgII, jfloatArray ArrEcgIII, jfloatArray ArrEcgaVR, jfloatArray ArrEcgaVL, jfloatArray ArrEcgaVF,
jfloatArray ArrEcgV1, jfloatArray ArrEcgV2, jfloatArray ArrEcgV3, jfloatArray ArrEcgV4, jfloatArray ArrEcgV5, jfloatArray ArrEcgV6, jfloat ratioecg
,jfloat ratiov)
{
	jfloat* arrecgI, *arrecgII, *arrecgIII, *arrecgaVR, *arrecgaVL, *arrecgaVF, 
		*arrecgV1, *arrecgV2, *arrecgV3, *arrecgV4, *arrecgV5, *arrecgV6;
    jint length;
	const char *pdfpath = (*env)->GetStringUTFChars(env, pdfPath, 0);
	length = (*env)->GetArrayLength(env,ArrEcgI);
    arrecgI = (*env)->GetFloatArrayElements(env,ArrEcgI,NULL);
    arrecgII = (*env)->GetFloatArrayElements(env,ArrEcgII,NULL);
	arrecgIII = (*env)->GetFloatArrayElements(env,ArrEcgIII,NULL);
	arrecgaVR = (*env)->GetFloatArrayElements(env,ArrEcgaVR,NULL);
	arrecgaVL = (*env)->GetFloatArrayElements(env,ArrEcgaVL,NULL);
	arrecgaVF = (*env)->GetFloatArrayElements(env,ArrEcgaVF,NULL);
	arrecgV1 = (*env)->GetFloatArrayElements(env,ArrEcgV1,NULL);
	arrecgV2 = (*env)->GetFloatArrayElements(env,ArrEcgV2,NULL);
	arrecgV3 = (*env)->GetFloatArrayElements(env,ArrEcgV3,NULL);
	arrecgV4 = (*env)->GetFloatArrayElements(env,ArrEcgV4,NULL);
	arrecgV5 = (*env)->GetFloatArrayElements(env,ArrEcgV5,NULL);
	arrecgV6 = (*env)->GetFloatArrayElements(env,ArrEcgV6,NULL);
	ratio = ratioecg;
	ratio_v = ratiov;
	ecg2pdf(pdfpath, arrecgI, length, arrecgII, arrecgIII, arrecgaVR, arrecgaVL, arrecgaVF, 
		arrecgV1, arrecgV2, arrecgV3, arrecgV4, arrecgV5, arrecgV6);
	(*env)->ReleaseStringUTFChars(env, pdfPath, pdfpath);
}

JNIEXPORT void  Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragmentShenMai_SetHeadInfo(JNIEnv* env, jobject obj, 
	jbyteArray name, jstring sex, jstring speed, jstring hr, jstring pvcs,	jstring doctor, jstring id, jstring gain, jstring st1, jstring st2,
	jstring time,jbyteArray analysismsg);
	
void Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragmentShenMai_SetHeadInfo(JNIEnv* env, jobject obj, 
	jbyteArray name, jstring sex, jstring speed, jstring hr, jstring pvcs,	jstring doctor, jstring id, jstring gain, jstring st1, jstring st2,
	jstring time,jbyteArray analysismsg)
{
	memset(&gHI, 0, sizeof(gHI));
	memset(g_analysismsg, 0, 64);
	LOGI("SetHeadInfo call in libpdf.so");
	int i = 0;
	
	char* sname = NULL;
	jsize alen = (*env)->GetArrayLength(env,name);//��ȡ����
	jbyte *jbytename =(jbyte*)(*env)->GetByteArrayElements(env,name,JNI_FALSE);
	if(alen>0)
	{
		sname = (char*)malloc(alen+1);
		memcpy(sname,jbytename,alen);
		sname[alen]=0;
	}
	
	char* smsg = NULL;
 	alen = (*env)->GetArrayLength(env,analysismsg);//��ȡ����
	jbyte *jbytemsg =(jbyte*)(*env)->GetByteArrayElements(env,analysismsg,JNI_FALSE);
	if(alen>0)
	{
		smsg = (char*)malloc(alen+1);
		memcpy(smsg,jbytemsg,alen);
		smsg[alen]=0;
	}
	
	

	//const char *sname = (*env)->GetStringUTFChars(env, name, 0);
	const char *ssex = (*env)->GetStringUTFChars(env, sex, 0);
	const char *sspeed = (*env)->GetStringUTFChars(env, speed, 0);
	const char *shr = (*env)->GetStringUTFChars(env, hr, 0);
	const char *spvcs = (*env)->GetStringUTFChars(env, pvcs, 0);
	const char *sdoctor = (*env)->GetStringUTFChars(env, doctor, 0);
	const char *sid = (*env)->GetStringUTFChars(env, id, 0);
	const char *sgain = (*env)->GetStringUTFChars(env, gain, 0);
	const char *sst1 = (*env)->GetStringUTFChars(env, st1, 0);
	const char *sst2 = (*env)->GetStringUTFChars(env, st2, 0);
	const char *stime = (*env)->GetStringUTFChars(env, time, 0);

	//LOGI("sname = %s", sname);
	//LOGI("ssex = %s", ssex);
	//LOGI("sspeed = %s", sspeed);
	//LOGI("shr = %s", shr);
	//LOGI("spvcs = %s", spvcs);
	//LOGI("sdoctor = %s", sdoctor);
	//LOGI("sid = %s", sid);
	//LOGI("sgain = %s", sgain);
	//LOGI("sst1 = %s", sst1);
	//LOGI("sst2 = %s", sst2);
	//LOGI("stime = %s", stime);
	//LOGI("smsg = %s", smsg);
	//strncpy(gHI.HIname, sname, strlen(sname));
	strcat(gHI.HIname, "������");
	strcat(gHI.HIname, sname);
	
	//strncpy(gHI.HIsex, ssex, strlen(ssex));
	if(strcmp(ssex, "1") == 0)
		strcat(gHI.HIsex, "�Ա���");
	else if(strcmp(ssex, "0") == 0)
		strcat(gHI.HIsex, "�Ա�Ů");
	
	//strncpy(gHI.HIspeed, sspeed, strlen(sspeed));
	strcat(gHI.HIspeed, "���٣�");
	strcat(gHI.HIspeed, sspeed);
	
	//strncpy(gHI.HIhr, shr, strlen(shr));
	strcat(gHI.HIhr, "HR��");
	strcat(gHI.HIhr, shr);
	
	//strncpy(gHI.HIpvcs, spvcs, strlen(spvcs));
	strcat(gHI.HIpvcs, "PVCs��");
	strcat(gHI.HIpvcs, spvcs);
	
	//strncpy(gHI.HIdoctor, sdoctor, strlen(sdoctor));
	strcat(gHI.HIdoctor, "ҽ����");
	
	
	strcat(g_analysismsg, "���������");
	strcat(g_analysismsg, smsg);
	
	
	//strncpy(gHI.HIid, sid, strlen(sid));
	strcat(gHI.HIid, "���֤�ţ�");
	strcat(gHI.HIid, sid);
	
	//strncpy(gHI.HIgain, sgain, strlen(sgain));
	strcat(gHI.HIgain, "���棺");
	strcat(gHI.HIgain, sgain);
	
	//strncpy(gHI.HIst1, sst1, strlen(sst1));
	strcat(gHI.HIst1, "ST1��");
	strcat(gHI.HIst1, sst1);
	
	//strncpy(gHI.HIst2, sst2, strlen(sst2));
	strcat(gHI.HIst2, "   ST2��");
	strcat(gHI.HIst2, sst2);
	
	//strncpy(gHI.HItime, stime, strlen(stime));
	strcat(gHI.HItime, "   ���ʱ�䣺");
	strcat(gHI.HItime, stime);
	
	
	
	
	(*env)->ReleaseByteArrayElements(env, name, jbytename, 0);
	(*env)->ReleaseByteArrayElements(env, analysismsg, jbytemsg, 0);
	
	(*env)->ReleaseStringUTFChars(env, sex, ssex);
	(*env)->ReleaseStringUTFChars(env, speed, sspeed);
	(*env)->ReleaseStringUTFChars(env, hr, shr);
	(*env)->ReleaseStringUTFChars(env, pvcs, spvcs);
	(*env)->ReleaseStringUTFChars(env, doctor, sdoctor);
	(*env)->ReleaseStringUTFChars(env, id, sid);
	(*env)->ReleaseStringUTFChars(env, st1, sst1);
	(*env)->ReleaseStringUTFChars(env, st2, sst2);
	(*env)->ReleaseStringUTFChars(env, time, stime);
}
*/


#define COUNT 1500
int main()
{
	float arr[COUNT] = {0};
	for(int i=0;i<COUNT;i++){
		arr[i] = (rand()%50);
		//printf("arr[%d] = %d\n", i, arr[i]);
	}
	ecg2pdf("qqq.pdf", arr, COUNT, arr, arr, arr, arr, arr, 
		arr, arr, arr, arr, arr, arr);
	printf("pdf\n");
	return 0;
}

