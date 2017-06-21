#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "hpdf.h"

jmp_buf env;

void error_handle(HPDF_STATUS errorno,
	HPDF_STATUS detail_no, void* user_data)
{
	longjmp(env, 1);
}

void draw_image(HPDF_Doc pdf, const char* filename,
	float x, float y)
{
	const char* FILE_SEPARATOR = "/";

	HPDF_Page page = HPDF_GetCurrentPage(pdf);
	HPDF_Image image;

	image = HPDF_LoadPngImageFromFile(pdf, filename);
	HPDF_Page_DrawImage(page, image, x, y, 
		HPDF_Page_GetWidth(image), HPDF__Page_GetHeight(image));
}


int png2pdf(const char* pngname, const char* filename)
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
	font = HPDF_GetFont(pdf, "Helvetica", NULL);
	page = HPDF_AddPage(pdf);
	HPDF_Page_SetWidth(page, 550);
	HPDF_Page_SetHeight(page, 650);

	draw_image(pdf, pngname, 100, HPDF_Page_GetHeight (page) - 10);
	HPDF_SaveToFile (pdf, filename);

    HPDF_Free (pdf);
    return 0;
}

int main(){
	
	return 0;
}
/*

char buf[128];
const char *str = (*env)->GetStringUTFChars(env, prompt, 0);
printf("%s", str);
(*env)->ReleaseStringUTFChars(env, prompt, str);



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
