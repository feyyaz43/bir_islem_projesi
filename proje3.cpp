#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

int sayilar[6];
int tut_sayilar[6];
int karisik[6];
int sayici[6];
int hedef;
int deneme_say;
int sonuc_sayi[5][3];
char sonuc_isaret[5];
int sayac_i,sayac_w;
time_t baslangic,bitis;
int sonuc222,sonuc33,sonuc42,sonuc2121,sonuc321,sonuc15,sonuc60;

void sifirla(void)
{
     int i,w;
     for(i=0;i<5;i++){
                      for(w=0;w<3;w++) sonuc_sayi[i][w]=0;
                      sonuc_isaret[i]=0;
                      }
     sayac_i=0;   sayac_w=0;
}

void salla(void)
{
     srand(time(NULL));
     int i;
     for(i=0;i<5;i++)sayilar[i]=rand()%9+1;
     sayilar[5]=25*(rand()%4+1);
     for(i=0;i<6;i++)tut_sayilar[i]=sayilar[i];
     hedef=rand()%900+100;
}


int sayicikontrol(int gelen)
{
    int i;
    for(i=0;i<6;i++){
                     if(sayici[i]==gelen) return 0;
                     }
    return 1;
}

void degistir(void)
{
     
     int a=0;
     for(a=0;a<6;a++)sayici[a]=6;
     int tut;
     a=0;
     while(sayici[5]==6)
                        {
                        tut=rand()%6;
                        if(sayicikontrol(tut)){
                                               sayici[a]=tut;
                                               karisik[tut]=sayilar[a];
                                               ++a;
                                               }
                        }
}

     
void islem222(void)
{
     int dizi222[3];
     int i;
     int is=1;
     int snc;
     
     for(i=0;i<3;i++)
     {
     a1:
     is=rand()%4+1;
     switch(is){
                case 1: dizi222[i]=karisik[2*i] + karisik[2*i+1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2*i];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2*i+1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[i];
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: dizi222[i]=karisik[2*i] - karisik[2*i+1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2*i];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2*i+1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[i];
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: dizi222[i]=karisik[2*i] * karisik[2*i+1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2*i];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2*i+1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[i];
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[2*i+1]==0)goto a1;
                     if(karisik[2*i]%karisik[2*i+1]!=0)goto a1;
                     dizi222[i]=karisik[2*i] / karisik[2*i+1];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[2*i];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[2*i+1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=dizi222[i];
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     }
     a2:
     is=rand()%4+1;
     switch(is){
                case 1: sonuc222=dizi222[0] + dizi222[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: sonuc222=dizi222[0] - dizi222[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: sonuc222=dizi222[0] * dizi222[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(dizi222[1]==0)goto a2;
                     if(dizi222[0]%dizi222[1]!=0)goto a2;
                     sonuc222=dizi222[0] / dizi222[1];
                     sonuc_sayi[sayac_i][sayac_w]=dizi222[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=dizi222[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     ++sayac_i;
     a3:
     is=rand()%4+1;
     switch(is){
                case 1: sonuc222 = snc + dizi222[2];
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: sonuc222 = snc + dizi222[2];
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: sonuc222 = snc + dizi222[2];
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi222[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(dizi222[2]==0)goto a3;
                     if(snc%dizi222[2]!=0)goto a3;
                     sonuc222 = snc + dizi222[2];
                     sonuc_sayi[sayac_i][sayac_w]=snc;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=dizi222[2];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=sonuc222;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
}

void islem33(void)
{
     int dizi33[2];
     int i;
     int is;
     int snc;
     
     for(i=0;i<2;i++)
     {
     a4:
     is=rand()%4+1;
     switch(is){
                case 1: snc=karisik[3*i] + karisik[3*i+1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc=karisik[3*i] - karisik[3*i+1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc=karisik[3*i] * karisik[3*i+1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[3*i+1]==0)goto a4;
                     if(karisik[3*i]%karisik[3*i+1]!=0)goto a4;
                     snc=karisik[3*i] / karisik[3*i+1];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[3*i];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     a5:
     is=rand()%4+1;
     switch(is){
                case 1: dizi33[i] = snc + karisik[3*i+2];
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[i];
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: dizi33[i] = snc - karisik[3*i+2];
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[i];
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: dizi33[i] = snc * karisik[3*i+2];
                        sonuc_sayi[sayac_i][sayac_w]=snc;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[i];
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[3*i+2]==0)goto a5;
                     if(dizi33[i]%karisik[3*i+2]!=0)goto a5;
                     dizi33[i] = snc / karisik[3*i+2];
                     sonuc_sayi[sayac_i][sayac_w]=snc;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+2];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=dizi33[i];
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     }
     a6:
     is=rand()%4+1;
     switch(is){
                case 1: sonuc33 = dizi33[0] + dizi33[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc33;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: sonuc33 = dizi33[0] - dizi33[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc33;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: sonuc33 = dizi33[0] * dizi33[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi33[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc33;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(dizi33[1]==0)goto a6;
                     if(dizi33[0]%dizi33[1]!=0)goto a6;
                     sonuc33 = dizi33[0] / dizi33[1];
                     sonuc_sayi[sayac_i][sayac_w]=dizi33[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=dizi33[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=sonuc33;
                     sonuc_isaret[sayac_i]='/';
                break;
                }   
}

void islem42(void)
{
     int dizi42[4];
     int snc0,snc1,snc2,snc3;
     int i;
     int is;
     
     a7:
     is=rand()%4+1;
     switch(is){
                case 1: snc0=karisik[0] + karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc0;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc0=karisik[0] - karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc0;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc0=karisik[0] * karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc0;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[1]==0)goto a7;
                     if(karisik[0] %karisik[1]!=0)goto a7;
                     snc0=karisik[0] / karisik[1];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc0;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     for(i=2;i<4;i++){
                      a8:
                      is=rand()%4+1;
                      switch(is){
                                 case 1: if(i==2){
                                                  snc1 = snc0 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc0;
                                                  }
                                         if(i==3){
                                                  snc3 = snc1 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc1;
                                         if(i==3) sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         sonuc_isaret[sayac_i]='+';
                                 break;
                                 case 2: if(i==2){
                                                  snc1 = snc0 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc0;
                                                  }
                                         if(i==3){
                                                  snc3 = snc1 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc1;
                                         if(i==3) sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         sonuc_isaret[sayac_i]='-';
                                 break;
                                 case 3: if(i==2){
                                                  snc1 = snc0 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc0;
                                                  }
                                         if(i==3){
                                                  snc3 = snc1 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc1;
                                         if(i==3) sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         sonuc_isaret[sayac_i]='*';
                                 break;
                                 case 4: 
                                      if(karisik[i]==0)goto a8;
                                      if(snc0 % karisik[i]!=0 && i==2)goto a8;
                                      if(snc1 % karisik[i]!=0 && i==3)goto a8;
                                      if(i==2){
                                               snc1 = snc0 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc0;
                                               }
                                      if(i==3){
                                               snc3 = snc1 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                               }
                                      ++sayac_w;
                                      sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                      ++sayac_w;
                                      if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc1;
                                      if(i==3) sonuc_sayi[sayac_i][sayac_w]=snc3;
                                      sonuc_isaret[sayac_i]='/';
                                 break;
                                 }
                      sayac_w=0;
                      ++sayac_i;
                      }
     a9:
     is=rand()%4+1;
     switch(is){
                case 1: snc2 = karisik[4] + karisik[5];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc2 = karisik[4] - karisik[5];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc2 = karisik[4] * karisik[5];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[5]==0)goto a9;
                     if(karisik[4] % karisik[5]!=0)goto a9;
                     snc2 = karisik[4] / karisik[5];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc2;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     a10:
     is=rand()%4+1;
     switch(is){
                case 1: sonuc42 = snc3 + snc2;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc42;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: sonuc42 = snc3 - snc2;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc42;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: sonuc42 = snc3 * snc2;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc42;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(snc2==0)goto a10;
                     if(snc3 % snc2!=0)goto a10;
                     sonuc42 = snc3 / snc2;
                     sonuc_sayi[sayac_i][sayac_w]=snc3;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc2;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=sonuc42;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
}

void islem2121(void)
{
     int dizi2121[4];
     int i;
     int is;
     int snc1,snc2;
     
     dizi2121[1]=karisik[2];
     dizi2121[3]=karisik[5];
     
     for(i=0;i<2;i++){
                      a11:
                       is=rand()%4+1;
                       switch(is){
                                  case 1: dizi2121[i*2] = karisik[i*3] + karisik[3*i+1];
                                          sonuc_sayi[sayac_i][sayac_w]=karisik[i*3];
                                          ++sayac_w;
                                          sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                                          ++sayac_w;
                                          sonuc_sayi[sayac_i][sayac_w]=dizi2121[i*2];
                                          sonuc_isaret[sayac_i]='+';
                                  break;
                                  case 2: dizi2121[i*2] = karisik[i*3] - karisik[3*i+1];
                                          sonuc_sayi[sayac_i][sayac_w]=karisik[i*3];
                                          ++sayac_w;
                                          sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                                          ++sayac_w;
                                          sonuc_sayi[sayac_i][sayac_w]=dizi2121[i*2];
                                          sonuc_isaret[sayac_i]='-';
                                  break;
                                  case 3: dizi2121[i*2] = karisik[i*3] * karisik[3*i+1];
                                          sonuc_sayi[sayac_i][sayac_w]=karisik[i*3];
                                          ++sayac_w;
                                          sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                                          ++sayac_w;
                                          sonuc_sayi[sayac_i][sayac_w]=dizi2121[i*2];
                                          sonuc_isaret[sayac_i]='*';
                                  break;
                                  case 4: 
                                       if(karisik[3*i+1]==0)goto a11;
                                       if(karisik[i*3] % karisik[3*i+1]!=0)goto a11;
                                       dizi2121[i*2] = karisik[i*3] / karisik[3*i+1];
                                       sonuc_sayi[sayac_i][sayac_w]=karisik[i*3];
                                       ++sayac_w;
                                       sonuc_sayi[sayac_i][sayac_w]=karisik[3*i+1];
                                       ++sayac_w;
                                       sonuc_sayi[sayac_i][sayac_w]=dizi2121[i*2];
                                       sonuc_isaret[sayac_i]='/';
                                  break;
                                  }
                        sayac_w=0;
                        ++sayac_i;
                       }
     a12:
     is=rand()%4+1;
     switch(is){
                case 1: snc1 = dizi2121[0] + dizi2121[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi2121[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi2121[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc1 = dizi2121[0] - dizi2121[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi2121[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi2121[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc1 = dizi2121[0] * dizi2121[1];
                        sonuc_sayi[sayac_i][sayac_w]=dizi2121[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=dizi2121[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(dizi2121[1]==0)goto a12;
                     if(dizi2121[0] % dizi2121[1]!=0)goto a12;
                     snc1 = dizi2121[0] / dizi2121[1];
                     sonuc_sayi[sayac_i][sayac_w]=dizi2121[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=dizi2121[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc1;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     for(i=2;i<4;i++){
                      a13:
                      is=rand()%4+1;
                      switch(is){
                                 case 1: if(i==2){
                                                  snc2 = snc1 + dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         if(i==3){
                                                  sonuc2121 = snc2 + dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=dizi2121[i];
                                         ++sayac_w;
                                         if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==3) sonuc_sayi[sayac_i][sayac_w]=sonuc2121;
                                         sonuc_isaret[sayac_i]='+';
                                 break;
                                 case 2: if(i==2){
                                                  snc2 = snc1 - dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         if(i==3){
                                                  sonuc2121 = snc2 - dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=dizi2121[i];
                                         ++sayac_w;
                                         if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==3) sonuc_sayi[sayac_i][sayac_w]=sonuc2121;
                                         sonuc_isaret[sayac_i]='-';
                                 break;
                                 case 3: if(i==2){
                                                  snc2 = snc1 * dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         if(i==3){
                                                  sonuc2121 = snc2 * dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=dizi2121[i];
                                         ++sayac_w;
                                         if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==3) sonuc_sayi[sayac_i][sayac_w]=sonuc2121;
                                         sonuc_isaret[sayac_i]='*';
                                 break;
                                 case 4: 
                                      if(dizi2121[i]==0)goto a13;
                                      if(snc1 % dizi2121[i]!=0 && i==2) goto a13;
                                      if(snc2 % dizi2121[i]!=0 && i==3) goto a13;
                                      sonuc2121 = snc1 / dizi2121[i];
                                      if(i==2){
                                               snc2 = snc1 / dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                               }
                                      if(i==3){
                                               sonuc2121 = snc2 / dizi2121[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                               }
                                      ++sayac_w;
                                      sonuc_sayi[sayac_i][sayac_w]=dizi2121[i];
                                      ++sayac_w;
                                      if(i==2) sonuc_sayi[sayac_i][sayac_w]=snc2;
                                      if(i==3) sonuc_sayi[sayac_i][sayac_w]=sonuc2121;
                                      sonuc_isaret[sayac_i]='/';
                                 break;
                                 }
                      sayac_w=0;
                      ++sayac_i;
                      }
}

void islem321(void)
{
     int snc1,snc2,snc3,snc4;
     int is;
     
     a14:
     is=rand()%4+1;
     switch(is){
                case 1: snc1=karisik[0] + karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc1=karisik[0] - karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc1=karisik[0] * karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[1])goto a14;
                     if(karisik[0] % karisik[1]!=0)goto a14;
                     snc1=karisik[0] / karisik[1];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc1;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     a15:
     is=rand()%4+1;
     switch(is){
                case 1: snc3 = snc1 + karisik[2];
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc3 = snc1 - karisik[2];
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc3 = snc1 * karisik[2];
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[2]==0)goto a15;
                     if(snc1 % karisik[2]!=0)goto a15;
                     snc3 = snc1 / karisik[2];
                     sonuc_sayi[sayac_i][sayac_w]=snc1;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc3;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     a16:
     is=rand()%4+1;
     switch(is){
                case 1: snc2=karisik[3] + karisik[4];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc2=karisik[3] - karisik[4];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc2=karisik[3] * karisik[4];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[3];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[4]==0)goto a16;
                     if(karisik[3] % karisik[4]!=0)goto a16;
                     snc2=karisik[3] / karisik[4];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[3];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[4];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc2;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     a17:
     is=rand()%4+1;
     switch(is){
                case 1: snc4 = snc3 + snc2;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc4 = snc3 - snc2;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc4 = snc3 * snc2;
                        sonuc_sayi[sayac_i][sayac_w]=snc3;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc2;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(snc2==0)goto a17;
                     if(snc3 % snc2!=0)goto a17;
                     snc4 = snc3 / snc2;
                     sonuc_sayi[sayac_i][sayac_w]=snc3;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc2;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc4;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     a18:
     is=rand()%4+1;
     switch(is){
                case 1: sonuc321 = snc4 + karisik[5];
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc321;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: sonuc321 = snc4 - karisik[5];
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc321;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: sonuc321 = snc4 * karisik[5];
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc321;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[5]==0)goto a18;
                     if(snc4 % karisik[5]!=0)goto a18;
                     sonuc321 = snc4 / karisik[5];
                     sonuc_sayi[sayac_i][sayac_w]=snc4;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[5];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=sonuc321;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
}

void islem15(void)
{
     int snc1,snc2,snc3,snc4;
     int is;
     int i;
     
     a19:
     is=rand()%4+1;
     switch(is){
                case 1: snc1=karisik[1] + karisik[2];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc1=karisik[1] - karisik[2];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc1=karisik[1] * karisik[2];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[2]==0)goto a19;
                     if(karisik[1] % karisik[2]!=0)goto a19;
                     snc1=karisik[1] / karisik[2];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[2];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc1;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     for(i=3;i<6;i++){
                      a20:
                      is=rand()%4+1;
                      switch(is){
                                 case 1: if(i==3){
                                                  snc2 = snc1 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         if(i==4){
                                                  snc3 = snc2 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                  }
                                         if(i==5){
                                                  snc4 = snc3 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         if(i==5)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                         sonuc_isaret[sayac_i]='+';
                                 break;
                                 case 2: if(i==3){
                                                  snc2 = snc1 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         if(i==4){
                                                  snc3 = snc2 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                  }
                                         if(i==5){
                                                  snc4 = snc3 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         if(i==5)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                         sonuc_isaret[sayac_i]='-';
                                 break;
                                 case 3: if(i==3){
                                                  snc2 = snc1 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                  }
                                         if(i==4){
                                                  snc3 = snc2 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                  }
                                         if(i==5){
                                                  snc4 = snc3 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                                  }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         if(i==5)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                         sonuc_isaret[sayac_i]='*';
                                 break;
                                 case 4: 
                                      if(karisik[i]==0)goto a20;
                                      if(snc1 % karisik[i]!=0 && i==3)goto a20;
                                      if(snc2 % karisik[i]!=0 && i==4)goto a20;
                                      if(snc3 % karisik[i]!=0 && i==5)goto a20;
                                      if(i==3){
                                               snc2 = snc1 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                               }
                                      if(i==4){
                                               snc3 = snc2 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                               }
                                      if(i==5){
                                               snc4 = snc3 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                               }
                                      ++sayac_w;
                                      sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                      ++sayac_w;
                                      if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                      if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                      if(i==5)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                      sonuc_isaret[sayac_i]='/';
                                 break;
                                 }
                      sayac_w=0;
                      ++sayac_i;
                      }
     a21:
     is=rand()%4+1;
     switch(is){
                case 1: sonuc15 = snc4 + karisik[0];
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc15;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: sonuc15 = snc4 - karisik[0];
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc15;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: sonuc15 = snc4 * karisik[0];
                        sonuc_sayi[sayac_i][sayac_w]=snc4;
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=sonuc15;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[0]==0)goto a21;
                     if(snc4 % karisik[0]!=0)goto a21;
                     sonuc15 = snc4 / karisik[0];
                     sonuc_sayi[sayac_i][sayac_w]=snc4;
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=sonuc15;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
}

void islem60(void)
{
     int snc1,snc2,snc3,snc4;
     int is;
     int i;
     a22:
     is=rand()%4+1;
     switch(is){
                case 1: snc1=karisik[0] + karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='+';
                break;
                case 2: snc1=karisik[0] - karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='-';
                break;
                case 3: snc1=karisik[0] * karisik[1];
                        sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                        ++sayac_w;
                        sonuc_sayi[sayac_i][sayac_w]=snc1;
                        sonuc_isaret[sayac_i]='*';
                break;
                case 4: 
                     if(karisik[1]==0)goto a22;
                     if(karisik[0]% karisik[1]!=0)goto a22;
                     snc1=karisik[0] / karisik[1];
                     sonuc_sayi[sayac_i][sayac_w]=karisik[0];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=karisik[1];
                     ++sayac_w;
                     sonuc_sayi[sayac_i][sayac_w]=snc1;
                     sonuc_isaret[sayac_i]='/';
                break;
                }
     sayac_w=0;
     ++sayac_i;
     for(i=2;i<6;i++){
                      a23:
                      is=rand()%4+1;
                      switch(is){
                                 case 1: if(i==2){
                                                  snc2 = snc1 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                 }
                                         if(i==3){
                                                  snc3 = snc2 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                 }
                                         if(i==4){
                                                  snc4 = snc3 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                                 }
                                         if(i==5){
                                                  sonuc60 = snc4 + karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc4;
                                                 }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==2)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                         if(i==5)sonuc_sayi[sayac_i][sayac_w]=sonuc60;
                                         sonuc_isaret[sayac_i]='+';
                                         
                                 break;
                                 case 2: if(i==2){
                                                  snc2 = snc1 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                 }
                                         if(i==3){
                                                  snc3 = snc2 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                 }
                                         if(i==4){
                                                  snc4 = snc3 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                                 }
                                         if(i==5){
                                                  sonuc60 = snc4 - karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc4;
                                                 }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==2)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                         if(i==5)sonuc_sayi[sayac_i][sayac_w]=sonuc60;
                                         sonuc_isaret[sayac_i]='-';
                                 break;
                                 case 3: if(i==2){
                                                  snc2 = snc1 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                                 }
                                         if(i==3){
                                                  snc3 = snc2 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                                 }
                                         if(i==4){
                                                  snc4 = snc3 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                                 }
                                         if(i==5){
                                                  sonuc60 = snc4 * karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc4;
                                                 }
                                         ++sayac_w;
                                         sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                         ++sayac_w;
                                         if(i==2)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                         if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                         if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                         if(i==5)sonuc_sayi[sayac_i][sayac_w]=sonuc60;
                                         sonuc_isaret[sayac_i]='*';
                                 break;
                                 case 4: 
                                      if(karisik[i]==0)goto a23;
                                      if(snc1 % karisik[i]!=0 && i==2)goto a23;
                                      if(snc2 % karisik[i]!=0 && i==3)goto a23;
                                      if(snc3 % karisik[i]!=0 && i==4)goto a23;
                                      if(snc4 % karisik[i]!=0 && i==5)goto a23;
                                      if(i==2){
                                               snc2 = snc1 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc1;
                                               }
                                      if(i==3){
                                               snc3 = snc2 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc2;
                                               }
                                      if(i==4){
                                               snc4 = snc3 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc3;
                                               }
                                      if(i==5){
                                               sonuc60 = snc4 / karisik[i];  sonuc_sayi[sayac_i][sayac_w]=snc4;
                                               }
                                      ++sayac_w;
                                      sonuc_sayi[sayac_i][sayac_w]=karisik[i];
                                      ++sayac_w;
                                      if(i==2)sonuc_sayi[sayac_i][sayac_w]=snc2;
                                      if(i==3)sonuc_sayi[sayac_i][sayac_w]=snc3;
                                      if(i==4)sonuc_sayi[sayac_i][sayac_w]=snc4;
                                      if(i==5)sonuc_sayi[sayac_i][sayac_w]=sonuc60;
                                      sonuc_isaret[sayac_i]='/';
                                 break;
                                 }
                      sayac_w=0;
                      ++sayac_i;
                      }
}

void sayilari_tekrar_yaz(void);
void islemden_sayi_sil(int);
void ekrana_isaret_yaz(char,int,int);
void ekrana_sayi_yaz(int,int,int);

int main()
{
    int a;
    int gd=DETECT,gm,kod;
    initgraph(&gd,&gm,"");
    kod=graphresult();
    if(kod!=grOk){printf("grafik hatasi :",kod);}
    initwindow(500,606);
    
    int x=mousex();
    int y=mousey();
    
    setcolor(15);
    bar(0,0,500,606);
    
    for(a=0;a<2;a++){
                       setcolor(0);
                       setlinestyle(0,0,7);
                       line(a*500,0,a*500,606);
                       }
    
    for(a=0;a<13;a++){
                      if(a==6 || a==7 || a==8 || a==9 )continue;
                       setcolor(0);
                       setlinestyle(0,0,7);
                       line(0,a*50+2,500,a*50+2);
                       }
    for(a=1;a<=5;a++){
                       setcolor(0);
                       setlinestyle(0,0,7);
                       line(a*83,55,a*83,100);
                       }
    setcolor(0);
    setlinestyle(0,0,7);
    line(330,205,330,606);
    line(417,255,417,450);
    line(330,355,500,355);
    line(330,450,500,450);
    
    setcolor(0);
    settextstyle(1,0,26);
    setbkcolor(15);
    outtextxy(52,12,"VERÝLEN SAYILAR");
    outtextxy(175,114,"HEDEF");
    outtextxy(361,285,"+"); outtextxy(451,285,"-");
    outtextxy(363,387,"*"); outtextxy(453,387,"/");
    settextstyle(1,0,24);
    outtextxy(95,217,"ADIMLAR");
    outtextxy(342,217,"ÝÞLEMLER");
    settextstyle(1,0,23);
    outtextxy(342,465,"SÜRE :");
    outtextxy(342,520,"DENEME :");
    settextstyle(1,0,24);
    outtextxy(375,568,"ÇIKIÞ");
    outtextxy(116,517,"BAÞLA");
    outtextxy(80,568,"YENÝ ÝÞLEM");
    
    int i;
    
    while(1){
             x = mousex();
             y = mousey();
             setlinestyle(0,0,7);
             if(x>0 && x<330 && y>554  &&  y<606){setcolor(0); rectangle(10,560,320,595);}
             else{setcolor(15);  rectangle(10,560,320,595);}
             if(x>330 && x<500 && y>554  &&  y<606){setcolor(0); rectangle(340,560,490,595);}
             else{setcolor(15);  rectangle(340,560,490,595);}
             if(ismouseclick(WM_LBUTTONDOWN)){
                                              PlaySound("button-29.wav",NULL,SND_FILENAME|SND_ASYNC);
                                              getmouseclick(WM_LBUTTONDOWN,x,y);
                                              if(x>0 && x<330 && y>554  &&  y<606){
                                                                                   setcolor(15);
                                                                                   rectangle(10,560,320,595);
                                                                                   setcolor(0);
                                                                                   rectangle(13,563,317,592);  delay(400);
                                                                                   setcolor(15);
                                                                                   rectangle(13,563,317,592);
                                                                                   deneme_say=0;
                                                                                   goto yeni_islem;
                                                                                   }
                                              if(x>330 && x<500 && y>554  &&  y<606){
                                                                                     setcolor(15);
                                                                                     rectangle(340,560,490,595);
                                                                                     setcolor(0);
                                                                                     rectangle(343,563,487,592);  delay(400);
                                                                                     setcolor(15);
                                                                                     rectangle(343,563,487,592);
                                                                                     exit(1);
                                                                                     }
                                              
                                              
                                              clearmouseclick(WM_LBUTTONDOWN);
                                              }
             }
             
    yeni_islem:
    setcolor(15);
    for(i=0;i<6;i++)bar(i*81+14,65,i*82+80,95);
    bar(440,465,495,495);
    bar(460,507,495,548);
    bar(5,256,325,495);
    sifirla();
    salla();
    setcolor(0);
    for(i=0;i<6;i++)ekrana_sayi_yaz(sayilar[i],i*82+10,65);
    ekrana_sayi_yaz(hedef,220,167);

    while(1){
             x = mousex();
             y = mousey();
             setlinestyle(0,0,7);
             if(x>0 && x<330 && y>554  &&  y<606){setcolor(0); rectangle(10,560,320,595);}
             else{setcolor(15);  rectangle(10,560,320,595);}
             if(x>0 && x<330 && y>503  &&  y<555){setcolor(0); rectangle(10,510,320,545);}
             else{setcolor(15);  rectangle(10,510,320,545);}
             if(x>330 && x<500 && y>554  &&  y<606){setcolor(0); rectangle(340,560,490,595);}
             else{setcolor(15);  rectangle(340,560,490,595);}
             if(ismouseclick(WM_LBUTTONDOWN)){
                                              PlaySound("button-29.wav",NULL,SND_FILENAME|SND_ASYNC);
                                              getmouseclick(WM_LBUTTONDOWN,x,y);
                                              if(x>0 && x<330 && y>554  &&  y<606){
                                                                                   setcolor(15);
                                                                                   rectangle(10,560,320,595);
                                                                                   setcolor(0);
                                                                                   rectangle(13,563,317,592);  delay(400);
                                                                                   setcolor(15);
                                                                                   rectangle(13,563,317,592);
                                                                                   deneme_say=0;
                                                                                   goto yeni_islem;
                                                                                   }
                                              if(x>0 && x<330 && y>503  &&  y<555){
                                                                                   setcolor(15);
                                                                                   rectangle(10,510,320,545);
                                                                                   setcolor(0);
                                                                                   rectangle(13,513,317,542);  delay(400);
                                                                                   setcolor(15);
                                                                                   rectangle(13,513,317,542);
                                                                                   ++deneme_say;
                                                                                   goto basla;
                                                                                   }
                                              if(x>330 && x<500 && y>554  &&  y<606){
                                                                                     setcolor(15);
                                                                                     rectangle(340,560,490,595);
                                                                                     setcolor(0);
                                                                                     rectangle(343,563,487,592);  delay(400);
                                                                                     setcolor(15);
                                                                                     rectangle(343,563,487,592);
                                                                                     exit(1);
                                                                                     }
                                              
                                              clearmouseclick(WM_LBUTTONDOWN);
                                              }
             }
    basla:
    setcolor(0);
    for(i=0;i<6;i++)ekrana_sayi_yaz(sayilar[i],i*82+10,65);
    ekrana_sayi_yaz(hedef,220,167);
    ekrana_sayi_yaz(deneme_say,460,519);
    baslangic=time(NULL);
    while(1)
            {
            degistir();
            
            //2-2-2
            sifirla();
            islem222();
            if(sonuc222==hedef)
            goto git;
            
            //3-3
            sifirla();
            islem33();
            if(sonuc33==hedef)
            goto git;
            
            //4-2
            sifirla();
            islem42();
            if(sonuc42==hedef)
            goto git;
            
            //2-1-2-1
            sifirla();
            islem2121();
            if(sonuc2121==hedef)
            goto git;
            
            //3-2-1
            sifirla();
            islem321();
            if(sonuc321==hedef)
            goto git;
            
            //5-1
            sifirla();
            islem15();
            if(sonuc15==hedef)
            goto git;
            
            //6-0
            sifirla();
            islem60();
            if(sonuc60==hedef)
            goto git;
            
            bitis=time(NULL);
            ekrana_sayi_yaz(int(difftime(bitis,baslangic)),440,465);
            if(int(difftime(bitis,baslangic)==20)){
                                                   setcolor(0);
                                                   outtextxy(55,365,"BULUNAMADI");
                                                  while(1){
                                            PlaySound("button-29.wav",NULL,SND_FILENAME|SND_ASYNC);
                                            x = mousex();
                                            y = mousey();
                                            setlinestyle(0,0,7);
                                            if(x>0 && x<330 && y>554  &&  y<606){setcolor(0); rectangle(10,560,320,595);}
                                            else{setcolor(15);  rectangle(10,560,320,595);}
                                            if(x>0 && x<330 && y>503  &&  y<555){setcolor(0); rectangle(10,510,320,545);}
                                            else{setcolor(15);  rectangle(10,510,320,545);}
                                            if(x>330 && x<500 && y>554  &&  y<606){setcolor(0); rectangle(340,560,490,595);}
                                            else{setcolor(15);  rectangle(340,560,490,595);}
                                            if(ismouseclick(WM_LBUTTONDOWN)){
                                                                      getmouseclick(WM_LBUTTONDOWN,x,y);
                                                                      if(x>0 && x<330 && y>554  &&  y<606){
                                                                                                setcolor(15);
                                                                                                rectangle(10,560,320,595);
                                                                                                setcolor(0);
                                                                                                rectangle(13,563,317,592);
                                                                                                delay(400);
                                                                                                setcolor(15);
                                                                                                rectangle(13,563,317,592);
                                                                                                deneme_say=0;
                                                                                                goto yeni_islem;
                                                                                                }
                                                                      if(x>0 && x<330 && y>503  &&  y<555){
                                                                                                setcolor(15);
                                                                                                rectangle(10,510,320,545);
                                                                                                setcolor(0);
                                                                                                rectangle(13,513,317,542);
                                                                                                delay(400);
                                                                                                setcolor(15);
                                                                                                rectangle(13,513,317,542);
                                                                                                ++deneme_say;
                                                                                                goto basla;
                                                                                                           }
                                                                      if(x>330 && x<500 && y>554  &&  y<606){
                                                                                                  setcolor(15);
                                                                                                  rectangle(340,560,490,595);
                                                                                                  setcolor(0);
                                                                                                  rectangle(343,563,487,592);
                                                                                                  delay(400);
                                                                                                  setcolor(15);
                                                                                                  rectangle(343,563,487,592);
                                                                                                  exit(1);
                                                                                                  }
                                                                      
                                                                      clearmouseclick(WM_LBUTTONDOWN);
                                                                                            }
                                                           }
                                                  }
            }
    
    git:
    bitis=time(NULL);
    ekrana_sayi_yaz(int(difftime(bitis,baslangic)),440,465);
 
    for(a=0;a<5;a++){
                     PlaySound("ding.wav",NULL,SND_FILENAME|SND_ASYNC);
                     ekrana_sayi_yaz(sonuc_sayi[a][0],0*100+40,a*50+265);
                     ekrana_isaret_yaz(sonuc_isaret[a],112,a*50+265);
                     ekrana_sayi_yaz(sonuc_sayi[a][1],1*100+40,a*50+265);
                     ekrana_isaret_yaz('=',212,a*50+265);
                     ekrana_sayi_yaz(sonuc_sayi[a][2],2*100+40,a*50+265);
                     islemden_sayi_sil(a);
                     delay(1500);
                     sayilari_tekrar_yaz();
                     delay(100);
                     }
    while(1){
             x = mousex();
             y = mousey();
             setlinestyle(0,0,7);
             if(x>0 && x<330 && y>554  &&  y<606){setcolor(0); rectangle(10,560,320,595);}
             else{setcolor(15);  rectangle(10,560,320,595);}
             if(x>0 && x<330 && y>503  &&  y<555){setcolor(0); rectangle(10,510,320,545);}
             else{setcolor(15);  rectangle(10,510,320,545);}
             if(x>330 && x<500 && y>554  &&  y<606){setcolor(0); rectangle(340,560,490,595);}
             else{setcolor(15);  rectangle(340,560,490,595);}
             if(ismouseclick(WM_LBUTTONDOWN)){
                                              PlaySound("button-29.wav",NULL,SND_FILENAME|SND_ASYNC);
                                              getmouseclick(WM_LBUTTONDOWN,x,y);
                                              if(x>0 && x<330 && y>554  &&  y<606){
                                                                                   setcolor(15);
                                                                                   rectangle(10,560,320,595);
                                                                                   setcolor(0);
                                                                                   rectangle(13,563,317,592);  delay(400);
                                                                                   setcolor(15);
                                                                                   rectangle(13,563,317,592);
                                                                                   deneme_say=0;
                                                                                   goto yeni_islem;
                                                                                   }
                                              if(x>0 && x<330 && y>503  &&  y<555){
                                                                                setcolor(15);
                                                                                rectangle(10,510,320,545);
                                                                                setcolor(0);
                                                                                rectangle(13,513,317,542);
                                                                                delay(400);
                                                                                setcolor(15);
                                                                                rectangle(13,513,317,542);
                                                                                for(i=0;i<6;i++)sayilar[i]=tut_sayilar[i];
                                                                                setcolor(15);
                                                                                for(i=0;i<6;i++)bar(i*81+27,65,i*82+80,95);
                                                                                bar(440,465,495,495);
                                                                                bar(5,256,325,495);
                                                                                sifirla();
                                                                                ++deneme_say;
                                                                                goto basla;
                                                                                }
                                              if(x>330 && x<500 && y>554  &&  y<606){
                                                                                     setcolor(15);
                                                                                     rectangle(340,560,490,595);
                                                                                     setcolor(0);
                                                                                     rectangle(343,563,487,592);  delay(400);
                                                                                     setcolor(15);
                                                                                     rectangle(343,563,487,592);
                                                                                     exit(1);
                                                                                     }
                                              
                                              clearmouseclick(WM_LBUTTONDOWN);
                                              }
             }
    getch();    
}

void sayilari_tekrar_yaz(void)
{
     int i;
     setcolor(0);
     for(i=0;i<6;i++)bar(i*82+17,65,i*82+80,95);
     setcolor(0);
     for(i=0;i<6;i++)if(sayilar[i]!=0)ekrana_sayi_yaz(sayilar[i],i*82+10,65);
}

void islemden_sayi_sil(int gelen)
{
     int i;
     for(i=0;i<6;i++){
                      if(sayilar[i]==sonuc_sayi[gelen][1]){  sayilar[i]=0; break;}
                      }
     for(i=0;i<6;i++){
                      if(sayilar[i]==sonuc_sayi[gelen][0]){  sayilar[i]=sonuc_sayi[gelen][2];  break;}
                      }
}

void ekrana_isaret_yaz(char isaret,int ix,int iy)
{
     char kelime[2];
     setcolor(0);
     kelime[0]='\0';
     kelime[1]='\0';
     kelime[0]=isaret;
     outtextxy(ix,iy,kelime); 
}

void ekrana_sayi_yaz(int gelen_sayi,int yerx,int yery)
{
     char sayi_kelime[11]={'0','1','2','3','4','5','6','7','8','9'};
     char ekran_kelime[6];
     int birler,onlar,yuzler,binler;
     int i,sayi;
     
     setcolor(0);
     for(i=0;i<6;i++)ekran_kelime[i]=0;
     
     if(gelen_sayi<0)sayi=gelen_sayi * -1;
     else sayi=gelen_sayi;
     
     if(sayi<10){
                 if(gelen_sayi<0)  ekran_kelime[0]='-';   else  ekran_kelime[0]=' ';
                 ekran_kelime[1]=sayi_kelime[sayi];
                 ekran_kelime[5]='\0';  ekran_kelime[4]='\0';  ekran_kelime[3]='\0'; ekran_kelime[2]='\0';
                 }
     else if(sayi>=10 && sayi<100){
                                   onlar=sayi/10; birler=sayi%10;
                                   if(gelen_sayi<0)  ekran_kelime[0]='-';  else  ekran_kelime[0]=' ';
                                   ekran_kelime[1]=sayi_kelime[onlar];
                                   ekran_kelime[2]=sayi_kelime[birler];
                                   ekran_kelime[5]='\0';  ekran_kelime[4]='\0';  ekran_kelime[3]='\0';
                                   }
     else if(sayi>=100 && sayi<1000){
                                     yuzler=sayi/100; onlar=(sayi-yuzler*100)/10; birler=sayi%10;
                                     if(gelen_sayi<0)  ekran_kelime[0]='-';  else  ekran_kelime[0]=' ';
                                     ekran_kelime[1]=sayi_kelime[yuzler];
                                     ekran_kelime[2]=sayi_kelime[onlar];
                                     ekran_kelime[3]=sayi_kelime[birler];
                                     ekran_kelime[4]='\0';  ekran_kelime[5]='\0';
                                     }
     else if(sayi>=1000 && sayi<10000){
                                       binler=sayi/1000; yuzler=(sayi-binler*1000)/100;
                                       onlar=(sayi-binler*1000-yuzler*100)/10; birler=sayi%10;
                                       if(gelen_sayi<0)  ekran_kelime[0]='-';  else  ekran_kelime[0]=' ';
                                       ekran_kelime[1]=sayi_kelime[binler];
                                       ekran_kelime[2]=sayi_kelime[yuzler];
                                       ekran_kelime[3]=sayi_kelime[onlar];
                                       ekran_kelime[4]=sayi_kelime[birler];
                                       ekran_kelime[5]='\0';
                                       }
     outtextxy(yerx,yery,ekran_kelime); 
}
