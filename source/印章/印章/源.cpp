/****************************************************************************
**** FileName: demo.c
**** Function: 真彩色 bmp 图片文件的创建
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
/**** The file header of bmp file 文件头*****/
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
/**** The information header of bmp file 信息头*****/
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
/**** The RGB data of bmp file 图像 RGB 数据*****/
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
	printf("请输入一个或多个汉字："); 
	scanf("%s", BM); 
	for (len = 0; BM[len] != '\0'; len++); 
	for (i = 0; i<len; i++) 
		printf("BM[%d]=%x\n", i, BM[i]);//输入"向"，则其编码为 CF F2
	printf("将编码转换成字符并显示：");
	for (i = 0; i<len; i++) 
		sprintf(str + 2 * i, "%x", BM[i]);//编码－＞字符，并存入 str 数组 for(i=0;i<2*len;i++) printf("%c",str[i]); return 0;
}
int main(int argc, char *argv[])
{
	RGBDATA *bmpData = NULL; //图像数据指针
	FILE *fp; //BMP 文件指针
	long i, j, k;
	long width = 140; //图像宽度
	long height = 140; //图像高度
	long dataSize = width * height;
	BITMAPFILEHEADER bmfHeader;
	BITMAPINFOHEADER bmiHeader;
	if (argc<2)
	{
		printf("\n 请指定您要生成的 BMP 文件名！\n");
		printf("\n 方法 1：在 cmd 窗口输入： demo xxxx.bmp 后回车执行！\n");
		printf("\n 方法 2：在 VC 的工程设置中添加参数： xxxx.bmp 后编译运行！\n");
		printf("\n 功能： 根据设定红绿蓝三色分量的值，控制显示不同的彩色条纹！\n\n");
		exit(0);
	}
	printf("\n ******************************************************************\n");
	printf("\n 感谢您使用 BMP 图片文件制作 DEMO 程序 \n");
	printf("\n 作者：李远豪 \n");
	printf("\n 日期：2010 年 5 月 12 日 \n");
	printf("\n 目的：编制印章生成程序时，供参考！ \n");
	printf("\n 功能：根据设定红绿蓝三色分量的值，控制显示不同的彩色条纹！\n\n");
	printf("\n ******************************************************************\n\n");
	//第一步：用命令行中给出的文件名新建一 BMP 文件，此时还是一个空文件
	if ((fp = fopen(argv[1], "wb+")) == NULL)
	{
		printf("Cannot open BMP file!");
		exit(0);
	}
	//第二步：置文件头数据并写入 BMP 文件
	bmfHeader.bfType = 0x4d42;
	bmfHeader.bfSize = 14 + 40 + width * height * 3;
	bmfHeader.bfReserved1 = 0;
	bmfHeader.bfReserved2 = 0;
	bmfHeader.bfoffBits = 0x36;
	fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp);
	//第三步：置信息头数据并写入 BMP 文件
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
	//第四步：置图像数据并写入 BMP 文件
	//分配足够内存，让 bmpData 指向这块内存，用于存放图像各象素点的 RGB 分量值
	if ((bmpData = (RGBDATA*)malloc(width*height * 3)) == NULL)
	{
		printf("bmpData memory malloc error!");
	}
		//先在 bmpData 所指内存中置图像 RGB 数据，然后将所有数据写入 BMP 文件
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			//char ch;	
			//if(ch=='\n'||ch=='\r')break;
			k = (height - i - 1)*width + j;//计算第 i 行第 j 列图像数据在 bmpData[]数组中的位置
			if (i < 14 || j < 14 || i >= height - 14 || j >= width - 14)
			{


				bmpData[k].rgbBlue = 0;
				bmpData[k].rgbGreen = 0;
				bmpData[k].rgbRed = 255;//红色分量值为：255
				continue;
			}
		}
	}
		for (i = 0; i<height; i++)
		{
			for (j = 0; j<width; j++)
			{
				k = (height - i - 1)*width + j;//计算第 i 行第 j 列图像数据在 bmpData[]数组中的位置
				
			}
		}
	fwrite(bmpData, sizeof(RGBDATA), dataSize, fp);//将 bmpData 所指的 RGB 数据一次性写入 BMP 文件
	printf("\n 恭喜您！BMP 文件已经成功生成！\n");
	printf("\n 请在当前目录下查看生成的 BMP 文件%s\n\n", argv[1]);
	free(bmpData); //释放 bmpData 所指的内存空间
	bmpData = NULL; //置 bmpData 为空指针
	fclose(fp); //关闭 fp 所指文件
}