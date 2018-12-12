/****************************************************************************
**** FileName: demo.c
**** Function: ���ɫ bmp ͼƬ�ļ��Ĵ���
**** Usage: demo xxxx.bmp
*****************************************************************************/
#include <CONIO.H>
#include <STDLIB.H>
#include <STDIO.H>
#include <MATH.H>
#include <MALLOC.H>
#include <string.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
/**** The file header of bmp file �ļ�ͷ*****/
#include <pshpack2.h> //This file turns 2 byte packing of structures on, then
//sizeof(BITMAPFILEHEADER) = 14, otherwise sizeof(BITMAPFILEHEADER) = 16
typedef struct tagBITMAPFILEHEADER {
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfoffBits;
} BITMAPFILEHEADER;
#include <poppack.h> //This file turns packing of structures off
/**** The information header of bmp file ��Ϣͷ*****/
typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;
	DWORD biWidth;
	DWORD biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompress;
	DWORD biSizeImage;
	DWORD biXPeIsPerMeter;
	DWORD biYPeIsPerMeter;
	DWORD biCIrUsed;
	DWORD biClrImprotant;
} BITMAPINFOHEADER;
/**** The RGB data of bmp file ͼ�� RGB ����*****/
typedef struct tagRGBDATA {
	BYTE rgbBlue;
	BYTE rgbGreen;
	BYTE rgbRed;
} RGBDATA;
char str[200];
int i, len; 
char liter[100][100][100];
int m;
void intput(void) {
	
	unsigned char BM[100]; 
	printf("������һ���������֣�"); 
	scanf("%s", BM); 
	for (len = 0; BM[len] != '\0'; len++); 
	for (i = 0; i<len; i++) 
		printf("BM[%d]=%x\n", i, BM[i]);//����"��"���������Ϊ CF F2
	printf("������ת�����ַ�����ʾ��");
	for (i = 0; i<len; i++) 
		sprintf(str + 2 * i, "%x", BM[i]);//���룭���ַ��������� str ���� for(i=0;i<2*len;i++) printf("%c",str[i]); return 0;
}
int main(int argc, char *argv[])
{
	RGBDATA *bmpData = NULL; //ͼ������ָ��
	FILE *fp; //BMP �ļ�ָ��
	long i, j, k;
	long width = 140; //ͼ����
	long height = 140; //ͼ��߶�
	long dataSize = width * height;
	BITMAPFILEHEADER bmfHeader;
	BITMAPINFOHEADER bmiHeader;
	if (argc<2)
	{
		printf("\n ��ָ����Ҫ���ɵ� BMP �ļ�����\n");
		printf("\n ���� 1���� cmd �������룺 demo xxxx.bmp ��س�ִ�У�\n");
		printf("\n ���� 2���� VC �Ĺ�����������Ӳ����� xxxx.bmp ��������У�\n");
		printf("\n ���ܣ� �����趨��������ɫ������ֵ��������ʾ��ͬ�Ĳ�ɫ���ƣ�\n\n");
		exit(0);
	}
	printf("\n ******************************************************************\n");
	printf("\n ��л��ʹ�� BMP ͼƬ�ļ����� DEMO ���� \n");
	printf("\n ���ߣ���Զ�� \n");
	printf("\n ���ڣ�2010 �� 5 �� 12 �� \n");
	printf("\n Ŀ�ģ�����ӡ�����ɳ���ʱ�����ο��� \n");
	printf("\n ���ܣ������趨��������ɫ������ֵ��������ʾ��ͬ�Ĳ�ɫ���ƣ�\n\n");
	printf("\n ******************************************************************\n\n");
	//��һ�������������и������ļ����½�һ BMP �ļ�����ʱ����һ�����ļ�
	if ((fp = fopen(argv[1], "wb+")) == NULL)
	{
		printf("Cannot open BMP file!");
		exit(0);
	}
	//�ڶ��������ļ�ͷ���ݲ�д�� BMP �ļ�
	bmfHeader.bfType = 0x4d42;
	bmfHeader.bfSize = 14 + 40 + width * height * 3;
	bmfHeader.bfReserved1 = 0;
	bmfHeader.bfReserved2 = 0;
	bmfHeader.bfoffBits = 0x36;
	fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	//������������Ϣͷ���ݲ�д�� BMP �ļ�
	bmiHeader.biSize = 40;
	bmiHeader.biWidth = width;
	bmiHeader.biHeight = height;
	bmiHeader.biPlanes = 1;
	bmiHeader.biBitCount = 24;
	bmiHeader.biCompress = 0;
	bmiHeader.biSizeImage = width * height * 3;
	bmiHeader.biXPeIsPerMeter = 0;
	bmiHeader.biYPeIsPerMeter = 0;
	bmiHeader.biCIrUsed = 0;
	bmiHeader.biClrImprotant = 0;
	fwrite(&bmiHeader, sizeof(BITMAPINFOHEADER), 1, fp);
	//���Ĳ�����ͼ�����ݲ�д�� BMP �ļ�
	//�����㹻�ڴ棬�� bmpData ָ������ڴ棬���ڴ��ͼ������ص�� RGB ����ֵ
	if ((bmpData = (RGBDATA*)malloc(width*height * 3)) == NULL)
	{
		printf("bmpData memory malloc error!");
	}
		//���� bmpData ��ָ�ڴ�����ͼ�� RGB ���ݣ�Ȼ����������д�� BMP �ļ�
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//char ch;	
			//if(ch=='\n'||ch=='\r')break;
			k = (height - i - 1)*width + j;//����� i �е� j ��ͼ�������� bmpData[]�����е�λ��
			if (i < 14 || j < 14 || i >= height - 14 || j >= width - 14)
			{


				bmpData[k].rgbBlue = 0;
				bmpData[k].rgbGreen = 0;
				bmpData[k].rgbRed = 255;//��ɫ����ֵΪ��255
				continue;
			}
		}
	}
		for (i = 0; i<height; i++)
		{
			for (j = 0; j<width; j++)
			{
				k = (height - i - 1)*width + j;//����� i �е� j ��ͼ�������� bmpData[]�����е�λ��
				
			}
		}
	fwrite(bmpData, sizeof(RGBDATA), dataSize, fp);//�� bmpData ��ָ�� RGB ����һ����д�� BMP �ļ�
	printf("\n ��ϲ����BMP �ļ��Ѿ��ɹ����ɣ�\n");
	printf("\n ���ڵ�ǰĿ¼�²鿴���ɵ� BMP �ļ�%s\n\n", argv[1]);
	free(bmpData); //�ͷ� bmpData ��ָ���ڴ�ռ�
	bmpData = NULL; //�� bmpData Ϊ��ָ��
	fclose(fp); //�ر� fp ��ָ�ļ�
}