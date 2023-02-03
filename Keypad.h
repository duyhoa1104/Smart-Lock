#define KEYPAD_H

//khai bao cac cot
#define COT_1  PIN_D4
#define COT_2  PIN_D5
#define COT_3  PIN_D6
#define COT_4  PIN_D7

//khai bao cac hang
#define HANG_1  input(PIN_C7)
#define HANG_2  input(PIN_C6)
#define HANG_3  input(PIN_C5) 
#define HANG_4  input(PIN_C4)

void _DieuKhienCot(char TenCot, int1 TrangThai);
void _KhoiDongBanPhim(void);
char _QuetPhimNhan(void);

void _DieuKhienCot(char TenCot, int1 TrangThai)
{
   switch(TenCot)
   {
      case 1:
      {
         output_bit(COT_1,TrangThai);
         break;
      }
      case 2:
      {
         output_bit(COT_2,TrangThai);
         break;
      }
      case 3:
      {
         output_bit(COT_3,TrangThai);
         break;
      }
      case 4:
      {
         output_bit(COT_4,TrangThai);
         break;
      }
   }
}

void _KhoiDongBanPhim(void)
{
   char i;
   for(i=1;i<=4;i++)
   {
      _DieuKhienCot(i,1);
   }
}

//!char ReadColStatus()
//!{
//!    char ucData='p';
//!    while('p' != ucData)
//!    {
//!        ucData = _QuetPhimNhan();
//!    }
//!    return ucData;
//!}

char _QuetPhimNhan(void)
{
   signed char Key=-1;
   const char PhimPhan[16]=
   {
      '1','4','7','*',
      '2','5','8','0',
      '3','6','9','e',
      '\f','\b','d','u'
   };
   
   //quet cot 1
   _DieuKhienCot(1,0); //ban dau bat cot di
   // sau do quet cac hang
   if(HANG_1==0)//Khi nhan phim 
   {
      while(HANG_1==0);
      Key=1;
   }
   else if(HANG_2==0)//Khi nhan phim 
   {
      while(HANG_2==0);
      Key=2;
   }
   else if(HANG_3==0)//Khi nhan phim 
   {
      while(HANG_3==0);
      Key=3;
   }
   else if(HANG_4==0)//Khi nhan phim 
   {  
      while(HANG_4==0);
      Key=4;
   }
   //tat cot
   _DieuKhienCot(1,1);
   
   //quet cot 2
   _DieuKhienCot(2,0); //ban dau bat cot di
   // sau do quet cac hang
   if(HANG_1==0)//Khi nhan phim 
   {
      while(HANG_1==0);
      Key=5;
   }
   else if(HANG_2==0)//Khi nhan phim 
   {
      while(HANG_2==0);
      Key=6;
   }
   else if(HANG_3==0)//Khi nhan phim 
   {
      while(HANG_3==0);
      Key=7;
   }
   else if(HANG_4==0)//Khi nhan phim 
   {
      while(HANG_4==0);
      Key=8;
   }
   //tat cot
   _DieuKhienCot(2,1);
   
   //quet cot 3
   _DieuKhienCot(3,0); //ban dau bat cot di
   // sau do quet cac hang
   if(HANG_1==0)//Khi nhan phim 
   {
      while(HANG_1==0);
      Key=9;
   }
   else if(HANG_2==0)//Khi nhan phim 
   {
      while(HANG_2==0);
      Key=10;
   }
   else if(HANG_3==0)//Khi nhan phim 
   {
      while(HANG_3==0);
      Key=11;
   }
   else if(HANG_4==0)//Khi nhan phim 
   {
      while(HANG_4==0);
      Key=12;
   }
   //tat cot
   _DieuKhienCot(3,1);
   
   //quet cot 4
   _DieuKhienCot(4,0); //ban dau bat cot di
   // sau do quet cac hang
   if(HANG_1==0)//Khi nhan phim 
   {
      while(HANG_1==0);
      Key=13;
   }
   else if(HANG_2==0)//Khi nhan phim 
   {
      while(HANG_2==0);
      Key=14;
   }
   else if(HANG_3==0)//Khi nhan phim 
   {
      while(HANG_3==0);
      Key=15;
   }
   else if(HANG_4==0)//Khi nhan phim 
   {
      while(HANG_4==0);
      Key=16;
   }
   //tat cot
   _DieuKhienCot(4,1);
   
   if(Key==-1) return -1;
   return PhimPhan[Key-1];
}
