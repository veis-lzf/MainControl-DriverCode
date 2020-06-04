#ifndef __BSP_LCD_H__
#define __BSP_LCD_H__	
#include <bsp.h>

// LCD��Ҫ������
typedef struct  
{										    
	u16 width;			 // LCD ����
	u16 height;			 // LCD �߶�
	u16 id;				 // LCD ID
	u8  dir;			 // ���������������ƣ�0��������1��������	 
}_lcd_dev; 	  

// LCD����
extern _lcd_dev lcddev;  // ����LCD��Ҫ����

// LCD�Ļ�����ɫ�ͱ���ɫ	   
extern u16  POINT_COLOR; // Ĭ�Ϻ�ɫ    
extern u16  BACK_COLOR;  // ������ɫ.Ĭ��Ϊ��ɫ

//////////////////////////////////////////////////////////////////////////////////	 
//-----------------LCD�˿ڶ���---------------- 
//LCD��ַ�ṹ��
typedef struct
{
	vu16 LCD_REG;
	vu16 LCD_RAM;
} LCD_TypeDef;
		    
#define LCD_BASE        ((u32)(0x60000000 | 0x0001FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)
//////////////////////////////////////////////////////////////////////////////////

// ��Ļ����
#define VERTICAL   0        // ����
#define HORIZONTAL 1        // ����

// �л��������ĺ�
#define __DIR__ VERTICAL    // Ĭ������

// ɨ�跽���� B5 B6 B7
//B5 = 0
#define L2R_U2D  0 // ������,���ϵ���
#define L2R_D2U  1 // ������,���µ���
#define R2L_U2D  2 // ���ҵ���,���ϵ���
#define R2L_D2U  3 // ���ҵ���,���µ���

//B5 = 1
#define U2D_L2R  4 // ���ϵ���,������
#define D2U_L2R  5 // ���µ���,������
#define U2D_R2L  6 // ���ϵ���,���ҵ���
#define D2U_R2L  7 // ���µ���,���ҵ���	 

// ע�⣺ɨ�跽��ֻ֧��B5 = 0 �����������
// ʣ��������������ں�����ת���ɳ���ʵ�֣�����Ҫ�û�ѡ��
#define DFT_SCAN_DIR  L2R_U2D  // Ĭ�ϵ�ɨ�跽��


// ������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 // ��ɫ
#define BRRED 			 0XFC07 // �غ�ɫ
#define GRAY  			 0X8430 // ��ɫ
// GUI��ɫ

#define DARKBLUE      	 0X01CF	// ����ɫ
#define LIGHTBLUE      	 0X7D7C	// ǳ��ɫ  
#define GRAYBLUE       	 0X5458 // ����ɫ
// ������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F // ǳ��ɫ
#define LGRAY 			 0XC618 // ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 // ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 // ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
																			   
void LCD_Init(void);																		// ��ʼ��
void LCD_DisplayOn(void);																	// ����ʾ
void LCD_DisplayOff(void);																	// ����ʾ
void LCD_Clear(u16 Color);	 																// ����
void LCD_SetCursor(u16 Xpos, u16 Ypos);														// ���ù��
void LCD_DrawPoint(u16 x,u16 y);															// ����
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color);												// ���ٻ���
u16  LCD_ReadPoint(u16 x,u16 y); 															// ���� 
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);						 							// ��Բ
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);											// ����
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);		   								// ������
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);		   								// ��䵥ɫ
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);								// ���ָ����ɫ
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode);										// ��ʾһ���ַ�
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);  										// ��ʾһ������
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);								// ��ʾ ����
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);						// ��ʾһ���ַ���,12/16����
void DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, u8 *pData);	// ��ʾһ��RGBͼƬ

// �ڲ�����
u16  Read_ID(void);
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);
u16  LCD_ReadReg(u16 LCD_Reg);
void LCD_WriteRAM_Prepare(void);       // ��ʼ�����ڴ�С
void LCD_WriteREG_Prepare(void);       // д����0x2c
void LCD_WriteRAM(u16 RGB_Code);
void LCD_Display_Dir(u8 dir);								    // ������Ļ��ʾ����
void LCD_Scan_Dir(u8 dir);
void LCD_Set_Window(u16 Xstart,u16 Xend,u16 Ystart,u16 Yend);	// ���ô���					   						   																			 

// LCD�ֱ�������
#define SSD_HOR_RESOLUTION		480		// LCDˮƽ�ֱ���
#define SSD_VER_RESOLUTION		320		// LCD��ֱ�ֱ���

// LCD������������
#define SSD_HOR_PULSE_WIDTH		1		// ˮƽ����
#define SSD_HOR_BACK_PORCH		46		// ˮƽǰ��
#define SSD_HOR_FRONT_PORCH		210		// ˮƽ����

#define SSD_VER_PULSE_WIDTH		1		// ��ֱ����
#define SSD_VER_BACK_PORCH		23		// ��ֱǰ��
#define SSD_VER_FRONT_PORCH		22		// ��ֱǰ��
// ���¼����������Զ�����
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)

#endif  
	 
	 


