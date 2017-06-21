#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <math.h>

//#include <android/log.h>
//#include <jni.h>
//#define  LOG_TAG    "pdf"
//#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
//#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
//#include <iconv.h>
#include "hpdf.h"

struct HeadInfo
{
	char HIname[32];
	char HIID[32];
	char HIage[32];
	char HIgestation[32];
	char HItime[64];
};

struct HeadInfo gHI;

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

void init_gHI()
{
	memset(gHI.HIname,0,32);
	memset(gHI.HIID,0,32);
	memset(gHI.HIage,0,32);
	memset(gHI.HIgestation,0,32);
	memset(gHI.HItime,0,64);
}

//int code_convert(char *from_charset,char *to_charset,char *inbuf,int inlen,char *outbuf,int outlen)
//{
//	iconv_t cd;
//	int rc;
//	char **pin = &inbuf;
//	char **pout = &outbuf;
//	
//	cd = iconv_open(to_charset,from_charset);
//    if (cd==0)
//            return -1;
//    memset(outbuf,0,outlen);
//    if (iconv(cd,pin,&inlen,pout,&outlen) == -1)
//            return -1;
//    iconv_close(cd);
//    return 0;
//}

//char *convertString(const char * fromCode, const char * toCode, const char * source)
//{
//	LOGI("fromCode = %s", fromCode);
//	LOGI("toCode = %s", toCode);
//	LOGI("source = %s", source);
//	size_t retlen = 0;
//	size_t inbytesleft = strlen(source);
//	if (!strncmp(fromCode, "UTF-16LE", 8))
//	{
//		inbytesleft = wcslen((wchar_t *)source) * 2;
//	}
//	size_t outbytesleft = inbytesleft * 4 + 2;
//	retlen = outbytesleft;
//	char *tmp = (char*)malloc(outbytesleft);
//
//	char * inbuf = (char *)source;
//	char * outbuf = (char *)tmp;
//
//	iconv_t cd = iconv_open(toCode, fromCode);
//	size_t errorNo = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
//	retlen -= outbytesleft;
//
//	if (errorNo == -1)
//	{
//		LOGI("111");
//		memcpy(tmp, source, inbytesleft);
//	}
//	else
//	{
//		LOGI("222");
//		memset(tmp + retlen, 0, outbytesleft);
//	}
//	iconv_close(cd);
//	
//	LOGI("tmp = %s", tmp);
//	FILE *fp1;
//    fp1 = fopen("/sdcard/ttttt.txt", "w+");
//	
//    fwrite(tmp, strlen(tmp), 1, fp1);
//	
//	fclose(fp1);
//	return tmp;
//}

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
    
    //HPDF_Page_BeginText (page);
    //HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
    //            width-20, 490);
    //HPDF_Page_ShowText (page, "电脑胎儿监护图");
    //HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-20, 490);
    HPDF_Page_ShowText (page, "广东省妇幼保健院/电脑胎儿监护图");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                15, 230);
    HPDF_Page_ShowText (page, "注：所有参数各结论需经过医生最终确认");
    HPDF_Page_EndText (page);

	//HPDF_Page_BeginText (page);
    //HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
    //            15, 820);
    //HPDF_Page_ShowText (page, "ZTE中兴");
    //HPDF_Page_EndText (page);
}
//评分表
void write_arbitroid(HPDF_Page page, HPDF_Font font)
{
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    int GAP1 = 80;
    int BASE1 = 10;
    int GAP2 = 100;
    int GAP3 = 120;
    int GAP4 = 140;
    int GAP5 = 160;
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetFontAndSize(page, font, 10);//12
    
        /*
     * Rotating text
     */
    angle1 = -90;                   /* A rotation of 30 degrees. */
    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
    
	HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1);
    HPDF_Page_ShowText (page, "Kreb 'S评分表");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 815-BASE1);
    HPDF_Page_ShowText (page, "评分");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 812-BASE1);
    HPDF_Page_ShowText (page, "0分");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 812-BASE1);
    HPDF_Page_ShowText (page, "1分");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 812-BASE1);
    HPDF_Page_ShowText (page, "2分");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 775-BASE1);
    HPDF_Page_ShowText (page, "胎心率基线");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 780-BASE1);
    HPDF_Page_ShowText (page, "<100或 >180");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 787-BASE1);
    HPDF_Page_ShowText (page, "100-119,161-180");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 770-BASE1);
    HPDF_Page_ShowText (page, "120-160");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 700-BASE1);
    HPDF_Page_ShowText (page, "变异振幅");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 685-BASE1);
    HPDF_Page_ShowText (page, "<5");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 700-BASE1);
    HPDF_Page_ShowText (page, "5-9, >25");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 693-BASE1);
    HPDF_Page_ShowText (page, "10-25");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 640-BASE1);
    HPDF_Page_ShowText (page, "变异频率");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 625-BASE1);
    HPDF_Page_ShowText (page, "<3");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 628-BASE1);
    HPDF_Page_ShowText (page, "3-6");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 625-BASE1);
    HPDF_Page_ShowText (page, ">6");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 587-BASE1);
    HPDF_Page_ShowText (page, "加速(次/30分钟)");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 553-BASE1);
    HPDF_Page_ShowText (page, "0");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 558-BASE1);
    HPDF_Page_ShowText (page, "1-4");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 558-BASE1);
    HPDF_Page_ShowText (page, ">=5");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 507-BASE1);
    HPDF_Page_ShowText (page, "减速(次/30分钟)");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 478-BASE1);
    HPDF_Page_ShowText (page, ">=2");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 472-BASE1);
    HPDF_Page_ShowText (page, "1");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 490-BASE1);
    HPDF_Page_ShowText (page, "无或早减");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 425-BASE1);
    HPDF_Page_ShowText (page, "胎动次数");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 408-BASE1);
    HPDF_Page_ShowText (page, "0");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 412-BASE1);
    HPDF_Page_ShowText (page, "1-4");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP5, 412-BASE1);
    HPDF_Page_ShowText (page, ">=5");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 365-BASE1);
    HPDF_Page_ShowText (page, "结果: Kreb 'S评分          分");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3-10, 365-BASE1);
    HPDF_Page_ShowText (page, "NST        有反应        无反应        正弦曲线            不满意");
    HPDF_Page_EndText (page);
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-20, 365-BASE1);
    HPDF_Page_ShowText (page, "OCT        OST或NS-CST    阳性         阴性      可疑      不满意");
    HPDF_Page_EndText (page);
}

//表格标注
void write_gridlabel(HPDF_Page page, HPDF_Font font, float type, int pagecount)
{
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    int GAP1 = 190;
    int BASE1 = 27;
    int GAP2 = 210;
    int GAP3 = 400;
    int GAP4 = 448;

    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetFontAndSize(page, font, 10);//12
    
    //int type = 1;
    char s[100];
    //itoa(GAP1,s,10);  //把a转到s中,10是十进制
    char time[100];
    char pageinfo[100];
    
    sprintf(pageinfo,"第1页  共%d页",pagecount);
    
    if((type-1)<0){
    	sprintf(s,"速率：30min/页");
    }
    else if((type-1)>0&&(type-2)<0){
    	sprintf(s,"速率：20min/页");
    }
    else{
    	sprintf(s,"速率：%.1fcm/min",type);
	}
        /*
     * Rotating text
     */
    angle1 = -90;                   /* A rotation of 30 degrees. */
    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
    
	HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1);
    HPDF_Page_ShowText (page, "胎心率图");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1-80);
    HPDF_Page_ShowText (page, s);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1-180);
    HPDF_Page_ShowText (page, pageinfo);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 460-BASE1);
    HPDF_Page_ShowText (page, "200");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*2, 460-BASE1);
    HPDF_Page_ShowText (page, "180");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*4, 460-BASE1);
    HPDF_Page_ShowText (page, "160");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*6, 460-BASE1);
    HPDF_Page_ShowText (page, "140");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*8, 460-BASE1);
    HPDF_Page_ShowText (page, "120");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*10, 460-BASE1);
    HPDF_Page_ShowText (page, "100");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*12, 458-BASE1);
    HPDF_Page_ShowText (page, "80");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*14, 458-BASE1);
    HPDF_Page_ShowText (page, "60");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 832-BASE1);
    HPDF_Page_ShowText (page, "时间:");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1);
    sprintf(time,"%.1f分",6/type);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1-180);
    sprintf(time,"%.1f分",12/type);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1-180*2);
    sprintf(time,"%.1f分",18/type);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1-180*3);
    sprintf(time,"%.1f分",24/type);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3-35, 820-BASE1);
    HPDF_Page_ShowText (page, "宫缩图");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 460-BASE1);
    HPDF_Page_ShowText (page, "100");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*2, 458-BASE1);
    HPDF_Page_ShowText (page, "80");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*4, 458-BASE1);
    HPDF_Page_ShowText (page, "60");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*6, 458-BASE1);
    HPDF_Page_ShowText (page, "40");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*8, 458-BASE1);
    HPDF_Page_ShowText (page, "20");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*10, 456-BASE1);
    HPDF_Page_ShowText (page, "0");
    HPDF_Page_EndText (page);
}

void write_head(HPDF_Page page, HPDF_Font font, const char* ID, const char* name,
	const char* time, const char* age, const char* gestation)
{
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    int GAP1 = 40;
    int BASE1 = 10;
    int GAP2 = 60;
    int BASE2 = 10;
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
    HPDF_Page_ShowText (page, ID);
    HPDF_Page_EndText (page);
    //sex
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 580-BASE1);
    HPDF_Page_ShowText (page, name);
    HPDF_Page_EndText (page);
    //speed
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 350-BASE1);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    //id
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 820-BASE2);
    HPDF_Page_ShowText (page, age);
    HPDF_Page_EndText (page);
    //gain
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 580-BASE2);
    HPDF_Page_ShowText (page, gestation);
    HPDF_Page_EndText (page);
    //签名
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 350-BASE2);
    HPDF_Page_ShowText (page, "签名:");
    HPDF_Page_EndText (page);
    //日期
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 200-BASE2);
    HPDF_Page_ShowText (page, "日期:");
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
	X = 130+60*index;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
	for(i = height-25, j = 0; i > height/2+10 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		
		HPDF_Page_MoveTo (page, X+arr[j]*0.8, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*0.8, i-0.6);
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
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 1.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 1.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*0.8, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*0.8, i-0.6);
		HPDF_Page_Stroke (page);
		//HPDF_Page_Fill (page);
	}
}
//绘制胎心率曲线图
void drawFHRcurve(HPDF_Doc pdf, HPDF_Page page, int* arr, int len, float type)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 149;
	float space = 0.25*type;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	for(i = height-58, j = 0; i >= 22 && j < len-1; i-=space, j++)
	{
		if(arr[j]<50){
			arr[j] = 50;
		}
		if(arr[j+1]<50){
			arr[j+1] = 50;
		}
		HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*1.2, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*1.2, i-space);
		HPDF_Page_Stroke (page);
		//HPDF_Page_Fill (page);
	}
}
//绘制宫缩曲线图
void drawUCcurve(HPDF_Doc pdf, HPDF_Page page, int* arr, int len, float type)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 30;
	float space = 0.25*type;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	for(i = height-55, j = 0; i >= 25 && j < len-1; i-=space, j++)
	{
		HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0, 0.0);
		HPDF_Page_MoveTo (page, X+arr[j]*1.2, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*1.2, i-space);
		HPDF_Page_Stroke (page);
		//HPDF_Page_Fill (page);
	}
}

//绘制标识胎动
void drawQuickening(HPDF_Doc pdf, HPDF_Page page, int* arr, int len, float type)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    float x, y;
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
    int i;
    x = 209;
    //y = 815;
    for(i=0;i<len-1;i++){
	    if(arr[i]>(24/type*120)){
	    	break;
	    }
	    y = (785 - (arr[i]*0.25*type));
		HPDF_Page_SetLineWidth (page, 3);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.6, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0.6, 0);
		HPDF_Page_MoveTo (page, x, y);
	    HPDF_Page_LineTo (page, x+9, y);
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
	X = 130+60*index;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetRGBFill (page, 0, 0, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	for(i = height/2-5, j = 0; i >= 25 && j < len-1; i-=0.6, j++)
	{
		HPDF_Page_SetLineWidth (page, 1.5);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*0.2, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*0.2, i-0.6);
		HPDF_Page_Stroke (page);
	}
}
//绘制评分表
void print_arbitroid(HPDF_Doc pdf, HPDF_Page page)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    float x, y, x1, y1;
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
    x = 430;
    x1 = x;
    int i;
	for(i=1;i<6;i++){
		HPDF_Page_SetLineWidth (page, 1.0);
		HPDF_Page_MoveTo (page, x, 370);
        HPDF_Page_LineTo (page, x, 810);
        HPDF_Page_Stroke (page);
		x += 20;
	}
	
	y = 810;
	y1 = 510;
	HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 30;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 80;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 60;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 60;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 80;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 80;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);
    y -= 50;
    HPDF_Page_SetLineWidth (page, 1.0);
	HPDF_Page_MoveTo (page, x1, y);
    HPDF_Page_LineTo (page, y1, y);
    HPDF_Page_Stroke (page);

}

//type 0-1厘米/分钟 1-2厘米/分钟 2-3厘米/分钟 3-20分钟/页 4-30分钟/页

const HPDF_REAL distance[5] = {28.31649831649831, 56.63299663299662, 84.94949494949493,
	38.22727272727272, 25.48484848484848};
const HPDF_REAL margins = 38.227;
const HPDF_REAL step[5] = {0.1179854096520763,0.2359708193041526,0.3539562289562289,
	0.159280303030303,0.10618686868686868};


void print_grid(HPDF_Doc pdf, HPDF_Page page, int type = 0)
{
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    HPDF_REAL x, y;
	const HPDF_UINT16 DASH_MODE1[] = {2};
    //HPDF_Page_SetFontAndSize (page, font, 5);
    //HPDF_Page_SetGrayFill (page, 0.4);
    HPDF_Page_SetGrayStroke (page, 0.8);

    /* Draw horizontal lines */
	y = margins;//绿色区域

	while(y <= height-margins){
		HPDF_Page_SetLineWidth (page, 3);
		HPDF_Page_SetRGBStroke (page, 0.757, 1.0, 0.757);
		HPDF_Page_SetRGBFill (page, 0.757, 1, 0.757);
		HPDF_Page_MoveTo (page, 281, y);
        HPDF_Page_LineTo (page, width-254, y);
        HPDF_Page_Stroke (page);
		y += 3;
	}
	
	HPDF_Page_SetGrayStroke (page, 0.8);
	y = margins;//横线
	while(y <= height-margins){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 209, y);
        HPDF_Page_LineTo (page, width-194, y);
        HPDF_Page_Stroke (page);
		y += distance[type];
	}
	

	HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);//设置虚线
	y = margins+distance[type]/2;//横线
	while(y <= height-margins){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 209, y);
        HPDF_Page_LineTo (page, width-194, y);
        HPDF_Page_Stroke (page);
		y += distance[type];
	}
	
	HPDF_Page_SetDash (page, NULL, 0, 0);//实线
	//
	x = 209;//竖线
	while(x <= width-194){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, margins);
        HPDF_Page_LineTo (page, x, height-margins);
        HPDF_Page_Stroke (page);
		x += 28.3;
	}
	HPDF_Page_SetDash (page, NULL, 0, 0);//实线
	
	//绘制宫缩  横线
	y = margins;
	while(y <= height-margins){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 30, y);
        HPDF_Page_LineTo (page, width-445, y);
        HPDF_Page_Stroke (page);
		y += distance[type];
	}
	//
	HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);

/////	
	y = margins+distance[type]/2;//横线
	while(y <= height-margins){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 30, y);
        HPDF_Page_LineTo (page, width-445, y);
        HPDF_Page_Stroke (page);
		y += distance[type];
	}
	HPDF_Page_SetDash (page, NULL, 0, 0);
	
	x = 30;
	while(x <= width-445){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, margins);
        HPDF_Page_LineTo (page, x, height-margins);
        HPDF_Page_Stroke (page);
		x += 12*2;
	}
	HPDF_Page_SetDash (page, NULL, 0, 0);

	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineWidth (page, 2.0);
	HPDF_Page_MoveTo (page, 27, margins);
    HPDF_Page_LineTo (page, 27, height-margins);
    HPDF_Page_Stroke (page);
   
    HPDF_Page_SetGrayFill (page, 0);
    HPDF_Page_SetGrayStroke (page, 0);
}



//翻页图表
void print_grid2(HPDF_Doc pdf, HPDF_Page page)
{
    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    HPDF_UINT x, y;
	const HPDF_UINT16 DASH_MODE1[] = {2};
    HPDF_Page_SetGrayStroke (page, 0.8);

    /* Draw horizontal lines */
	y = 67;//绿色区域

	while(y <= height-55){
		HPDF_Page_SetLineWidth (page, 3);
		HPDF_Page_SetRGBStroke (page, 0.757, 1.0, 0.757);
		HPDF_Page_SetRGBFill (page, 0.757, 1, 0.757);
		HPDF_Page_MoveTo (page, 341, y);
        HPDF_Page_LineTo (page, width-194, y);
        HPDF_Page_Stroke (page);
		y += 3;
	}
	
	HPDF_Page_SetGrayStroke (page, 0.8);
	y = 65;//竖直线
	while(y <= height-55){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 269, y);
        HPDF_Page_LineTo (page, width-134, y);
        HPDF_Page_Stroke (page);
		y += 30;
	}
	
	HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);
	//虚线横线
	x = 269;
	while(x <= width-134){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, 20+43);
        HPDF_Page_LineTo (page, x, height-57);
        HPDF_Page_Stroke (page);
		x += 12*2;
	}
	HPDF_Page_SetDash (page, NULL, 0, 0);
	x = 281;//实线横线
	while(x <= width-134){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, 20+43);
        HPDF_Page_LineTo (page, x, height-57);
        HPDF_Page_Stroke (page);
		x += 12*2;
	}

	HPDF_Page_SetDash (page, NULL, 0, 0);
	
	//绘制宫缩背景图标
	y = 65;
	while(y <= height-55){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, 90, y);
        HPDF_Page_LineTo (page, width-385, y);
        HPDF_Page_Stroke (page);
		y += 30;
	}
	//
	HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);

	HPDF_Page_SetDash (page, NULL, 0, 0);
	
	x = 30+60;
	while(x <= width-385){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, 20+43);
        HPDF_Page_LineTo (page, x, height-56);
        HPDF_Page_Stroke (page);
		x += 12*2;
	}
	//
	HPDF_Page_SetDash (page, DASH_MODE1, 1, 1);
	x = 42+60;
	while(x <= width-385){
		HPDF_Page_SetLineWidth (page, 0.5);
		HPDF_Page_MoveTo (page, x, 20+43);
        HPDF_Page_LineTo (page, x, height-56);
        HPDF_Page_Stroke (page);
		x += 12*2;
	}
	HPDF_Page_SetDash (page, NULL, 0, 0);

	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineWidth (page, 2.0);
	HPDF_Page_MoveTo (page, 27, 20);
    HPDF_Page_LineTo (page, 27, height-26);
    HPDF_Page_Stroke (page);
   
    HPDF_Page_SetGrayFill (page, 0);
    HPDF_Page_SetGrayStroke (page, 0);
}

//翻页表格文字
void write_turnpage_gridlabel(HPDF_Page page, HPDF_Font font, float type, int index, int pagecount)
{
	float angle1;
    float angle2;
    float rad1;
    float rad2;
    int GAP1 = 190-60;
    int BASE1 = 27;
    int GAP2 = 210-60;
    int GAP3 = 400-60;
    int GAP4 = 448-60;
    float passtime = ((24/type)*(index-1));

    HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    
    HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetFontAndSize(page, font, 10);//12
    
    //int type = 1;
    char s[100];
    //itoa(GAP1,s,10);  //把a转到s中,10是十进制
    char time[100];
    char pageinfo[100];
    sprintf(pageinfo,"第%d页  共%d页", index, pagecount);
    
    if((type-1)<0){
    	sprintf(s,"速率：30min/页");
    }
    else if((type-1)>0&&(type-2)<0){
    	sprintf(s,"速率：20min/页");
    }
    else{
    	sprintf(s,"速率：%.1fcm/min",type);
	}
        /*
     * Rotating text
     */
    angle1 = -90;                   /* A rotation of 30 degrees. */
    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
    
	HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1);
    HPDF_Page_ShowText (page, "胎心率图");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1-80);
    HPDF_Page_ShowText (page, s);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP1, 820-BASE1-180);
    HPDF_Page_ShowText (page, pageinfo);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2, 460-BASE1);
    HPDF_Page_ShowText (page, "200");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*2, 460-BASE1);
    HPDF_Page_ShowText (page, "180");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*4, 460-BASE1);
    HPDF_Page_ShowText (page, "160");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*6, 460-BASE1);
    HPDF_Page_ShowText (page, "140");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*8, 460-BASE1);
    HPDF_Page_ShowText (page, "120");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*10, 460-BASE1);
    HPDF_Page_ShowText (page, "100");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*12, 458-BASE1);
    HPDF_Page_ShowText (page, "80");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP2-12*14, 458-BASE1);
    HPDF_Page_ShowText (page, "60");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 832-BASE1);
    HPDF_Page_ShowText (page, "时间:");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1);
    sprintf(time,"%.1f分",6/type+passtime);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1-180);
    sprintf(time,"%.1f分",12/type+passtime);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1-180*2);
    sprintf(time,"%.1f分",18/type+passtime);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3, 640-BASE1-180*3);
    sprintf(time,"%.1f分",24/type+passtime);
    HPDF_Page_ShowText (page, time);
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP3-35, 820-BASE1);
    HPDF_Page_ShowText (page, "宫缩图");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4, 460-BASE1);
    HPDF_Page_ShowText (page, "100");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*2, 458-BASE1);
    HPDF_Page_ShowText (page, "80");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*4, 458-BASE1);
    HPDF_Page_ShowText (page, "60");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*6, 458-BASE1);
    HPDF_Page_ShowText (page, "40");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*8, 458-BASE1);
    HPDF_Page_ShowText (page, "20");
    HPDF_Page_EndText (page);
    
    HPDF_Page_BeginText (page);
    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                width-GAP4-12*10, 456-BASE1);
    HPDF_Page_ShowText (page, "0");
    HPDF_Page_EndText (page);

}

//绘制翻页胎心率曲线图
void drawTurnPageFHRcurve(HPDF_Doc pdf, HPDF_Page page, int* arr, int len, float type, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 209;
	float space = 0.25*type;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	int startpoint = (int)((24/type)*120*(index-1));
	for(i = height-57, j = startpoint; i >= 22 && j < (startpoint+len-1); i-=space, j++)
	{
		if(arr[j]<50){
			arr[j] = 50;
		}
		if(arr[j+1]<50){
			arr[j+1] = 50;
		}
		HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0.0, 0);
		HPDF_Page_MoveTo (page, X+arr[j]*1.2, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*1.2, i-space);
		HPDF_Page_Stroke (page);
		//HPDF_Page_Fill (page);
	}
}
//绘制翻页宫缩曲线图
void drawTurnPageUCcurve(HPDF_Doc pdf, HPDF_Page page, int* arr, int len, float type, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
	float i;
	int Y;
	int j;
	float X;
	X = 90;
	float space = 0.25*type;
	HPDF_Page_SetGrayStroke (page, 0);
	HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
	int startpoint = (int)((24/type)*120*(index-1));
	for(i = height-57, j = startpoint; i >= 25 && j < (startpoint+len-1); i-=space, j++)
	{
		HPDF_Page_SetLineWidth (page, 0.2);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.0, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0, 0.0);
		HPDF_Page_MoveTo (page, X+arr[j]*1.2, i);
		HPDF_Page_LineTo (page,  X+arr[j+1]*1.2, i-space);
		HPDF_Page_Stroke (page);
		//HPDF_Page_Fill (page);
	}
}

//绘制翻页标识胎动
void drawTurnPageQuickening(HPDF_Doc pdf, HPDF_Page page, int* arr, int len, float type, int index)
{
	HPDF_REAL height = HPDF_Page_GetHeight (page);
    HPDF_REAL width = HPDF_Page_GetWidth (page);
    float x, y;
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetRGBFill (page, 0, 0, 0);
    HPDF_Page_SetLineJoin(page, HPDF_ROUND_JOIN);
    int i;
    x = 269;
    int startpoint = (int)((24/type)*120*(index-1));
    int endpoint = (int)((24/type)*120*index);
    //y = 815;
    for(i=0;i<len-1;i++){
	    if(i<startpoint||i>endpoint){
	    	break;
	    }
	    y = (785 - ((arr[i]-startpoint)*0.25*type));
		HPDF_Page_SetLineWidth (page, 3);
		HPDF_Page_SetRGBStroke (page, 0.0, 0.8, 0.0);
		HPDF_Page_SetRGBFill (page, 0, 0.8, 0);
		HPDF_Page_MoveTo (page, x, y);
	    HPDF_Page_LineTo (page, x+9, y);
	    HPDF_Page_Stroke (page);
    }
}
//
//void print_flag(HPDF_Doc pdf, HPDF_Page page, HPDF_Font font)
//{
//    HPDF_REAL height = HPDF_Page_GetHeight (page);
//    HPDF_REAL width = HPDF_Page_GetWidth (page);
//    char* colume1[] = {"aVF", "aVL", "aVR", "III", "II", "I"};
//    char* colume2[] = {"V6", "V5", "V4", "V3", "V2", "V1"};
//    HPDF_UINT x, y;
//	float angle1;
//    float angle2;
//    float rad1;
//    float rad2;
//    HPDF_Page_SetGrayStroke (page, 0);
//
//	HPDF_Page_SetTextRenderingMode (page, HPDF_FILL);
//    HPDF_Page_SetRGBFill (page, 0, 0, 0);
//    HPDF_Page_SetFontAndSize(page, font, 12);
//    /*
//     * Rotating text
//     */
//    angle1 = -90;                   /* A rotation of 30 degrees. */
//    rad1 = angle1 / 180 * 3.141592; /* Calcurate the radian value. */
//        
//    /* Draw horizontal lines */
//    int flag_width = 10;
//    int flag_height = 28;//30
//	int base = 0;
//    int i;
//	base = 10;
//    for(i = 0; i < 6; i++){
//    	float X = 110+62*i;
//    	HPDF_Page_SetLineWidth (page, 1.0);
//		HPDF_Page_MoveTo (page, X, height-10);
//	    HPDF_Page_LineTo (page, X, height-15);
//	    HPDF_Page_MoveTo (page, X, height-15);
//	    HPDF_Page_LineTo (page, X+flag_height, height-15);
//	    HPDF_Page_LineTo (page, X+flag_height, height-20);
//	    HPDF_Page_LineTo (page, X, height-20);
//	    HPDF_Page_LineTo (page, X, height-25);
//	    HPDF_Page_Stroke (page);
//	    
//	    HPDF_Page_BeginText (page);
//	    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
//	                X+flag_height, height-10);
//	    HPDF_Page_ShowText (page, colume1[i]);
//	    HPDF_Page_EndText (page);
//    }    
//    base = -8;
//    for(i = 0; i < 6; i++){
//    	float X = 110+62*i;
//    	HPDF_Page_SetLineWidth (page, 1.0);
//		HPDF_Page_MoveTo (page, X, height/2-base);
//	    HPDF_Page_LineTo (page, X, height/2-(base+5));
//	    HPDF_Page_MoveTo (page, X, height/2-(base+5));
//	    HPDF_Page_LineTo (page, X+flag_height, height/2-(base+5));
//	    HPDF_Page_LineTo (page, X+flag_height, height/2-(base+10));
//	    HPDF_Page_LineTo (page, X, height/2-(base+10));
//	    HPDF_Page_LineTo (page, X, height/2-(base+15));
//	    HPDF_Page_Stroke (page);
//	    
//	    HPDF_Page_BeginText (page);
//	    HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
//	                X+flag_height, height/2-base);
//	    HPDF_Page_ShowText (page, colume2[i]);
//	    HPDF_Page_EndText (page);
//    }
//	
//	float X = 45;
//	HPDF_Page_SetLineWidth (page, 1.0);
//	HPDF_Page_MoveTo (page, X, height-10);
//	HPDF_Page_LineTo (page, X, height-15);
//	HPDF_Page_MoveTo (page, X, height-15);
//	HPDF_Page_LineTo (page, X+flag_height, height-15);
//	HPDF_Page_LineTo (page, X+flag_height, height-20);
//	HPDF_Page_LineTo (page, X, height-20);
//	HPDF_Page_LineTo (page, X, height-25);
//	HPDF_Page_Stroke (page);
//	
//	HPDF_Page_BeginText (page);
//	HPDF_Page_SetTextMatrix (page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
//				X+flag_height, height-10);
//	HPDF_Page_ShowText (page, "II");
//	HPDF_Page_EndText (page);
//   // HPDF_Page_SetGrayFill (page, 0);
//   // HPDF_Page_SetGrayStroke (page, 0);
//}

//int ecg2pdf(const char* filename, float* arrecgI, int len, float* arrecgII, float* arrecgIII, float* arrecgaVR, float* arrecgaVL, float* arrecgaVF, 
//		float* arrecgV1, float* arrecgV2, float* arrecgV3, float* arrecgV4, float* arrecgV5, float* arrecgV6);

//生成电脑胎儿检测图PDF文件  参数  filename:生成文件名（包涵路径）  arrFHR:胎心率数组（0.5秒一个数据）  arrUC:宫缩数据   arrQuickening:胎动数据（按照0.5秒一个点计算第几个点发生胎动）
int ecg2pdf(const char* filename, int len, int* arrFHR, int* arrUC, int* arrQuickening,int quickeningLen, float type)
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
	
	int count = 24/type*120;
	
	int drawcount = 0;
	if(len>count){
		drawcount = count;
	}
	else{
		drawcount = len;
	}
	float fcount = count;
	float ii = len/fcount;
	int pagecount = (int)ii;
	if(ii-pagecount>0){
		pagecount++;
	}
	printf(" %f\n",ii);
	printf(" %d\n",pagecount);
	
	HPDF_SetCompressionMode(pdf, HPDF_COMP_ALL);
	
	HPDF_UseCNSFonts(pdf);
    HPDF_UseCNTFonts(pdf);
    HPDF_UseCNTEncodings(pdf);
    HPDF_UseCNSEncodings(pdf);
    
	font = HPDF_GetFont(pdf, "SimHei", "GBK-EUC-H");
	page = HPDF_AddPage(pdf);
	HPDF_Page_SetRotate(page, 270);
	
	print_grid(pdf, page);//第一页表格
	
	print_arbitroid(pdf, page);//绘制评分表
	write_arbitroid(page, font);//评分文字
	write_gridlabel(page, font, type, pagecount);//表格标注
	
	drawQuickening(pdf, page, arrQuickening, 10, type);//绘制标识胎动
	
	drawFHRcurve(pdf, page, arrFHR, drawcount,type);//绘制胎心率曲线图
	drawUCcurve(pdf, page, arrUC, drawcount,type);//绘制宫缩曲线图
	
	write_bottom(page, font);
	write_head(page, font, "档案号：1012726(5)", "姓名：欧阳锋子", "监护时间: 2015-07-15  10:57:00~11:21:24(监护中)", "年龄:31", "孕周:37+6");
	//write_head(page,font,gHI.HIID,gHI.HIname, gHI.HItime,gHI.HIage, gHI.HIgestation);

	for(int i=1;(ii-i)>0;i++){
		
		printf("new page %d\n",i);
		HPDF_Page page2 = HPDF_AddPage(pdf);
		HPDF_Page_SetRotate(page2, 270);
		print_grid2(pdf, page2);//后面页表格
		write_bottom(page2, font);
		write_turnpage_gridlabel(page2,font,type,i+1,pagecount);
		int drawpoint;
		if((len-(24/type)*120*(i+1))>0){
			drawpoint = (24/type)*120;
		}
		else{
			drawpoint = len - (24/type)*120*(i);
		}
		printf("drawpoint %d\n",drawpoint);
		drawTurnPageFHRcurve(pdf, page2, arrFHR, drawpoint, type, i+1);
		drawTurnPageUCcurve(pdf, page2, arrUC, drawpoint, type ,i+1);
		drawTurnPageQuickening(pdf, page2, arrQuickening, 10, type, i+1);
	}
	
	HPDF_SaveToFile (pdf, filename);
    HPDF_Free (pdf);
}

//void Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_FuyouCheckupFragment_SetHeadInfo(JNIEnv* env, jobject obj, 
//	jstring ID, jbyteArray name, jstring age, jstring gestation, jstring time)
//{
//	//LOGI("SetHeadInfo call in libpdf.so");
//	int i = 0;
//	jsize alen = (*env)->GetArrayLength(env,name);//获取长度
//	jbyte *jbytename =(jbyte*)(*env)->GetByteArrayElements(env,name,JNI_FALSE);
//	const char *sid = (*env)->GetStringUTFChars(env,ID, 0);
//	const char *sage = (*env)->GetStringUTFChars(env,age, 0);
//	const char *sgestation = (*env)->GetStringUTFChars(env,gestation, 0);
//	const char *stime = (*env)->GetStringUTFChars(env,time, 0);
//	
//	char* sname = NULL;
//	
//	if(alen>0)
//	{
//		sname = (char*)malloc(alen+1);
//		memcpy(sname,jbytename,alen);
//		sname[alen]=0;
//	}
//
//	//FILE *fp1;
//    //fp1 = fopen("/sdcard/tttt.ini", "w+");
//	//
//    //fwrite(sname, strlen(sname), 1, fp1);
//    //fclose(fp1);
//    
//	init_gHI();
//
//	strcat(gHI.HIID, "档案号：");
//	//strcat(gHI.HIID, convertString("UTF-8", "GBK-EUC-H", sid));
//	strcat(gHI.HIID, sid);
//
//	//strncpy(gHI.HIname, sname, strlen(sname));
//	strcat(gHI.HIname, "姓名：");
//	//strcat(gHI.HIname, convertString("UTF-8", "GBK", sname));
//	strcat(gHI.HIname, sname);
//	
//	//strncpy(gHI.HIspeed, sspeed, strlen(sspeed));
//	strcat(gHI.HIage, "年龄：");
//	strcat(gHI.HIage, sage);
//	//strcat(gHI.HIage, convertString("UTF-8", "GBK-EUC-H", sage));
//	
//	//strncpy(gHI.HIhr, shr, strlen(shr));
//	strcat(gHI.HIgestation, "孕周：");
//	strcat(gHI.HIgestation, sgestation);
//	//strcat(gHI.HIgestation, convertString("UTF-8", "GBK-EUC-H", sgestation));
//	
//	//strncpy(gHI.HItime, stime, strlen(stime));
//	strcat(gHI.HItime, "监护时间：");
//	strcat(gHI.HItime, stime);
//	//strcat(gHI.HItime, convertString("UTF-8", "GBK-EUC-H", stime));
//	
//	//(*env)->ReleaseStringUTFChars(env,name, sname);
//	(*env)->ReleaseStringUTFChars(env,age, sage);
//	(*env)->ReleaseStringUTFChars(env,gestation, sgestation);
//	(*env)->ReleaseStringUTFChars(env,time, stime);
//}
//JNIEXPORT void Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_FuyouCheckupFragment_PrintFetalMonitorPDF(JNIEnv* env, jobject obj, jstring pdfPath,
//	jstring ID, jbyteArray name, jstring age, jstring gestation, jstring time,jintArray ArrFHR, jintArray ArrUC);
//
////根据java过来的ecg数据，绘制曲线
//void Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_FuyouCheckupFragment_PrintFetalMonitorPDF(JNIEnv* env, jobject obj, jstring pdfPath,
//	jstring ID, jbyteArray name, jstring age, jstring gestation, jstring time,jintArray ArrFHR, jintArray ArrUC)
//{
//	jint* arrFHR, *arreUC;
//    jint length;
//    
//    Java_com_tyky_medical_healthbox_ui_fragment_healthcheckup_FuyouCheckupFragment_SetHeadInfo(env, obj, ID, name, age, gestation, time);
//	const char *pdfpath = (*env)->GetStringUTFChars(env, pdfPath, 0);
//	length = (*env)->GetArrayLength(env, ArrFHR);
//    arrFHR = (*env)->GetIntArrayElements(env, ArrFHR,NULL);
//    arreUC = (*env)->GetIntArrayElements(env, ArrUC,NULL);
//	
//	ecg2pdf(pdfpath,length, arrFHR, arreUC);
//	(*env)->ReleaseStringUTFChars(env, pdfPath, pdfpath);
//}
//
int main()
{
	const int count = 50;
	int arr[count] = {0};
	for(int i=0;i<count;i++){
		arr[i] = (rand()%210);
		//printf("arr[%d] = %d\n", i, arr[i]);
	}
	int arr1[count] = {0};
	for(int i=0;i<count;i++){
		arr1[i] = (rand()%100);
		//printf("arr[%d] = %d\n", i, arr1[i]);
	}
	int arr2[10] = {100,200,300,400,500,600,700,800,900,1000};
	ecg2pdf("ccc.pdf",count,arr,arr1,arr2, 10, 1.2);
	return 0;
}
//#endif
