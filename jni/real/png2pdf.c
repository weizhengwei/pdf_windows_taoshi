#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>
#include <android/log.h>
#include <jni.h>
#include "hpdf.h"

#define  LOG_TAG    "png2pdf"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

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
                width-20, 550);
    HPDF_Page_ShowText (page, "12导同步心电图报告单");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                10, 230);
    HPDF_Page_ShowText (page, "注：所有参数各结论需经过医生最终确认");
    HPDF_Page_EndText (page);

	HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                10, 820);
    HPDF_Page_ShowText (page, "ZTE中兴");
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
    HPDF_Page_SetFontAndSize(page, font, 12);
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
}

float coefficientECG = 0.8f;
float coefficientV = 0.2f;
void drawcurve(HPDF_Doc pdf, HPDF_Page page, float* arr, int len, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 80+60*index;
	for(i = height, j = 0; i > height/2+5 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.0);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		HPDF_Page_MoveTo (page, X+arr[j]*0.8, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*0.8, i-0.6);
		HPDF_Page_Stroke (page);
	}
}

void drawcurveV(HPDF_Doc pdf, HPDF_Page page, float* arr, int len, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	int k;
	float i;
	int Y;
	int j;
	float X;
	X = 80+60*index;
	for(i = height/2-5, j = 0; i >= 0, j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.0);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		HPDF_Page_MoveTo (page, X+arr[j]*0.2, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*0.2, i-0.6);
		HPDF_Page_Stroke (page);
	}
}


void print_grid(HPDF_Doc pdf, HPDF_Page page)
{
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    HPDF_Font font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_UINT x, y;

    HPDF_Page_SetFontAndSize (page, font, 5);
    HPDF_Page_SetGrayFill (page, 0.5);
    HPDF_Page_SetGrayStroke (page, 0.8);

    /* Draw horizontal lines */
	y = 10;
	while(y < height){
		HPDF_Page_SetLineWidth (page, 1.0);
		HPDF_Page_MoveTo (page, 15, y);
        HPDF_Page_LineTo (page, width-150, y);
        HPDF_Page_Stroke (page);
		y += 15;
	}
	x = 0;
	while(x < width-135){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, 0);
        HPDF_Page_LineTo (page, x, height-15);
        HPDF_Page_Stroke (page);
		x += 15;
	}

    HPDF_Page_SetGrayFill (page, 0);
    HPDF_Page_SetGrayStroke (page, 0);
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
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	print_grid(pdf, page);
	drawcurve(pdf, page, arrecgI, len, 5);
	drawcurve(pdf, page, arrecgII, len, 4);
	drawcurve(pdf, page, arrecgIII, len, 3);
	drawcurve(pdf, page, arrecgaVR, len, 2);
	drawcurve(pdf, page, arrecgaVL, len, 1);
	drawcurve(pdf, page, arrecgaVF, len, 0);
	
	drawcurveV(pdf, page, arrecgV1, len, 5);
	drawcurveV(pdf, page, arrecgV2, len, 4);
	drawcurveV(pdf, page, arrecgV3, len, 3);
	drawcurveV(pdf, page, arrecgV4, len, 2);
	drawcurveV(pdf, page, arrecgV5, len, 1);
	drawcurveV(pdf, page, arrecgV6, len, 0);
	
	write_bottom(page, font);
	write_head(page, font, "姓名：欧阳锋子", "性别：男", "波速：25mm/s", "HR：80bmp", "PVCs:10", "医生：王博士", "身份证号：135164251636943648", "增益：10mm/mV", "ST1：0mv", "ST2:10mv","检测时间：2016-01-17 14:01");
	HPDF_SaveToFile (pdf, filename);

    HPDF_Free (pdf);
}

/*
static char* jstringToChar(JNIEnv *env, jstring jstr)
{
    char * rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("UTF-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte * ba = env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen > 0)
    {
        rtn = (char*)malloc(alen+1); //new char[alen+1];
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    env->ReleaseByteArrayElements(barr,ba,0);
    return rtn;
}*/
/*
JNIEXPORT void JNICALL Java_com_tyky_medical_healthbox_backHistory_EgcHistoryActivity_convertToPdf(JNIEnv* env,
		jobject obj, jstring picPath, jstring pdfPath);

void Java_com_tyky_medical_healthbox_backHistory_EgcHistoryActivity_convertToPdf(JNIEnv* env,
		jobject obj, jstring picPath, jstring pdfPath)
{
	//const char* pngpath = jstringToChar(env, picPath);
	//const char* pdfpath = jstringToChar(env, pdfPath);

	const char *pngpath = (*env)->GetStringUTFChars(env, picPath, 0);
	const char *pdfpath = (*env)->GetStringUTFChars(env, pdfPath, 0);

	png2pdf(pngpath, pdfpath);
	(*env)->ReleaseStringUTFChars(env, picPath, pngpath);
	(*env)->ReleaseStringUTFChars(env, pdfPath, pdfpath);
}
*/
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
}

// JNIEXPORT void Java_com_tyky_medical_healthbox_activities_setting_EcgReoprtActivity_PrintEcgData(JNIEnv* env,
		// jobject obj, jstring picPath, jstring pdfPath);
// void Java_com_tyky_medical_healthbox_activities_setting_EcgReoprtActivity_PrintEcgData(JNIEnv* env,
		// jobject obj, jstring picPath, jstring pdfPath)
// {
	
// }


//根据java过来的ecg数据，绘制曲线
// JNIEXPORT void  Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragment_PrintEcgPDF(JNIEnv* env, jobject obj, jstring pdfPath,jfloatArray Arr);
JNIEXPORT void   Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragment_PrintEcgPDF(JNIEnv* env, jobject obj, jstring pdfPath, jfloatArray ArrEcgI, jfloatArray ArrEcgII, jfloatArray ArrEcgIII, jfloatArray ArrEcgaVR, jfloatArray ArrEcgaVL, jfloatArray ArrEcgaVF,
jfloatArray ArrEcgV1, jfloatArray ArrEcgV2, jfloatArray ArrEcgV3, jfloatArray ArrEcgV4, jfloatArray ArrEcgV5, jfloatArray ArrEcgV6);

void Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_EcgCheckupFragment_PrintEcgPDF(JNIEnv* env, jobject obj, jstring pdfPath, jfloatArray ArrEcgI, jfloatArray ArrEcgII, jfloatArray ArrEcgIII, jfloatArray ArrEcgaVR, jfloatArray ArrEcgaVL, jfloatArray ArrEcgaVF,
jfloatArray ArrEcgV1, jfloatArray ArrEcgV2, jfloatArray ArrEcgV3, jfloatArray ArrEcgV4, jfloatArray ArrEcgV5, jfloatArray ArrEcgV6)
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
	
	
	ecg2pdf(pdfpath, arrecgI, length, arrecgII, arrecgIII, arrecgaVR, arrecgaVL, arrecgaVF, 
		arrecgV1, arrecgV2, arrecgV3, arrecgV4, arrecgV5, arrecgV6);
	(*env)->ReleaseStringUTFChars(env, pdfPath, pdfpath);
}


#ifdef TEST
int main()
{
	png2pdf("test.png", "test.pdf");
	return 0;
}
#endif