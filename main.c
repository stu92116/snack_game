#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Graphics.h"
#include "Sound.h"
int width=940, height=640;
int s_x[100]= {0},s_y[100]= {0},s_len;
int s_x_2[100]= {0},s_y_2[100]= {0},s_len_2;
int food_x,food_y,is_food=0,is_food_head,is_food_head_2;
int food_head_x,food_head_y,food_head_x_2,food_head_y_2;
int speed,sec,level_speed;
char c,d,play=1;   //move用，初始設定向右
char grade_char[6]= {0},grade_char_2[6]= {0};
char speed_char[6]= {0};
int grade_int,grade_int_2;
int level;
char level_char[6]= {0};
int winner;
char f,e;
char close=1;
void sound_initial()
{
    s_loadSound("eat_food.wav",1);
    s_loadSound("gameover.wav",2);
}
void s_initial()
{
    int i;
    s_len=6;
    s_x[s_len-1]=30;
    s_y[s_len-1]=30;
    for(i=s_len-2; i>=0; i--)
    {
        s_x[i]=s_x[i+1]+20;
        s_y[i]=30;
    }
    c='6';
    d='6';
    speed=300;
    grade_int=0;
    for(i=0; i<10; i++)
    {
        grade_char[i]=0;
        speed_char[i]=0;
        level_char[i]=0;
    }
    level=1;

}
void s_initial_2()
{
    int i;
    s_len=4;
    s_x[s_len-1]=30;
    s_y[s_len-1]=30;
    for(i=s_len-2; i>=0; i--)
    {
        s_x[i]=s_x[i+1]+20;
        s_y[i]=30;
    }

    s_len_2=4;
    s_x_2[s_len-1]=590;
    s_y_2[s_len-1]=590;
    for(i=s_len-2; i>=0; i--)
    {
        s_x_2[i]=s_x_2[i+1]-20;
        s_y_2[i]=590;
    }
    c='6';
    d='6';
    f='a';
    e='a';
    speed=300;
    grade_int=0;
    grade_int_2=0;
    for(i=0; i<10; i++)
    {
        grade_char[i]=0;
        speed_char[i]=0;
        grade_char_2[i]=0;
    }
    winner=0;
}
void trans_grade(int num,char S[])
{

    int i,n=0,temp;
    temp=num;
    do
    {
        n++;
        temp/=10;
    }
    while(temp!=0);
    for(i=0; i<n; i++)
        S[i]=num/(int)(pow(10,n-i-1))%10+48;
}
void dis_arram()
{
    g_rectangle(20-3,25-8,width*(600.0/940)+3,height-25+8,0,0,0,3);
    //遊戲邊界
    g_line(30+width*(600.0/940),0,30+width*(600.0/940),height,128,138,135,2);
    //中間分隔線-直
    g_line(30+width*(600.0/940),height*(250.0/640),width,height*(250.0/640),128,138,135,2);
    //中間分隔線-橫
    g_putText(width*(1-310.0/940)+5,height*(290.0/640),"Game explain",1.3,255,0,0,3);
    //遊戲說明
    g_putText(width*(1-310.0/940)+5,height*(330.0/640),"Use + to increase the",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(355.0/640),"snake moving speed.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(395.0/640),"Use P to pause.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(420.0/640),"Press any key to resume.",0.75,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(460.0/640),"Use ESC to menu.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(500.0/640),"Use 8 5 4 6 to move.",0.8,138,43,236,2);

    g_putText(width*(1-310.0/940)+5,height*(40.0/640),"SCORE",1.3,255,0,0,3);
    //得分
    g_putText(width*(1-310.0/940)+5,height*(80.0/640),"Grade :",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(120.0/640),"Speed :",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(160.0/640),"Level :",0.8,138,43,236,2);
}
void dis_arram_2()
{
    g_rectangle(20-3,25-8,width*(600.0/940)+3,height-25+8,0,0,0,3);
    //遊戲邊界
    g_line(30+width*(600.0/940),0,30+width*(600.0/940),height,128,138,135,2);
    //中間分隔線-直
    g_line(30+width*(600.0/940),height*(250.0/640),width,height*(250.0/640),128,138,135,2);
    //中間分隔線-橫
    g_putText(width*(1-310.0/940)+5,height*(290.0/640),"Game explain",1.3,255,0,0,3);
    //遊戲說明
    g_putText(width*(1-310.0/940)+5,height*(330.0/640),"Use + to increase the",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(355.0/640),"and - to decrease the",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(380.0/640),"snake moving speed.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(420.0/640),"Use P to pause.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(460.0/640),"Press any key to resume.",0.75,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(500.0/640),"Use ESC to menu.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(540.0/640),"1P Use 8,5,4,6 move.",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(580.0/640),"2P Use w,s,a,d move.",0.8,138,43,236,2);


    g_putText(width*(1-310.0/940)+5,height*(40.0/640),"SCORE",1.3,255,0,0,3);
    //得分
    g_putText(width*(1-310.0/940)+5,height*(80.0/640),"1P Grade :",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(120.0/640),"2P Grade :",0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+5,height*(160.0/640),"Speed :",0.8,138,43,236,2);
}
void print_snack_food()
{
    int i=0;

    g_lineStart(s_x[0],s_y[0],0,0,255,10);
    for(i=0; i<s_len; i++)
    {
        g_lineTo(s_x[i],s_y[i]);
        g_circle(s_x[i],s_y[i],10,0,0,255,-1);
    }

    if(is_food==1)
        g_circle(food_x,food_y,10,255,0,0,-1);

    g_show();

    g_lineStart(s_x[0],s_y[0],255,255,255,10);
    for(i=0; i<s_len; i++)
    {
        g_lineTo(s_x[i],s_y[i]);
        g_circle(s_x[i],s_y[i],10,255,255,255,-1);
    }
}
void print_snack_food_2()
{
    int i=0;

    g_lineStart(s_x[0],s_y[0],0,0,255,10);

    for(i=0; i<s_len; i++)
    {
        g_lineTo(s_x[i],s_y[i]);
        g_circle(s_x[i],s_y[i],10,0,0,255,-1);
    }
    g_lineStart(s_x_2[0],s_y_2[0],0,255,255,10);
    for(i=0; i<s_len_2; i++)
    {
        g_lineTo(s_x_2[i],s_y_2[i]);
        g_circle(s_x_2[i],s_y_2[i],10,0,255,255,-1);
    }

    if(is_food==1)
        g_circle(food_x,food_y,10,255,0,0,-1);

    g_show();

    g_lineStart(s_x[0],s_y[0],255,255,255,10);
    for(i=0; i<s_len; i++)
    {
        g_lineTo(s_x[i],s_y[i]);
        g_circle(s_x[i],s_y[i],10,255,255,255,-1);
    }
    g_lineStart(s_x_2[0],s_y_2[0],255,255,255,10);
    for(i=0; i<s_len_2; i++)
    {
        g_lineTo(s_x_2[i],s_y_2[i]);
        g_circle(s_x_2[i],s_y_2[i],10,255,255,255,-1);
    }
}
void print_grade_speed()
{
    trans_grade(grade_int,grade_char);
    trans_grade(1000-speed,speed_char);
    trans_grade(level,level_char);
    g_rectangle(width*(1-310.0/940)+150,height*(50.0/640),width,height*(180.0/640),255,255,255,-1);
    g_putText(width*(1-310.0/940)+150,height*(80.0/640),grade_char,0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+150,height*(120.0/640),speed_char,0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+150,height*(160.0/640),level_char,0.8,138,43,236,2);
}
void print_grade_speed_2()
{
    trans_grade(grade_int,grade_char);
    trans_grade(grade_int_2,grade_char_2);
    trans_grade(1000-speed,speed_char);

    g_rectangle(width*(1-310.0/940)+150,height*(50.0/640),width,height*(180.0/640),255,255,255,-1);
    g_putText(width*(1-310.0/940)+150,height*(80.0/640),grade_char,0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+150,height*(120.0/640),grade_char_2,0.8,138,43,236,2);
    g_putText(width*(1-310.0/940)+150,height*(160.0/640),speed_char,0.8,138,43,236,2);
}
void s_move(char c)
{
    if((d+c)!=('6'+'4')&&(d+c)!=('8'+'5'))  //判斷是否移動不合理
    {
        switch(c)
        {
        case 27:
            play=0;
            break;
        case '+':
            speed-=20;
            if(speed<10)
                speed=10;
            break;
        case '-':
            speed+=20;
            if(speed>level_speed)
                speed=level_speed;
            break;
        case 'p':
            g_waitKey(0);
            break;
        case '8':
        case '5':
        case '4':
        case '6':
            d=c;
            break;
        }
    }

    int i;
    for(i=s_len-1; i>0; i--)
    {
        s_x[i]=s_x[i-1];
        s_y[i]=s_y[i-1];
    }

    switch(d)
    {
    case '8':
        s_y[0]-=20;
        break;
    case '5':
        s_y[0]+=20;
        break;
    case '4':
        s_x[0]-=20;
        break;
    case '6':
        s_x[0]+=20;
        break;
    default:
        printf("move error c is %c\n",c);
    }
}
void s_move_2(char c)
{
    e=c;
    if((d+c)!=('6'+'4')&&(d+c)!=('8'+'5'))  //判斷是否移動不合理
    {
        switch(c)
        {
        case 27:
            play=0;
            break;
        case '+':
            speed-=20;
            if(speed<10)
                speed=10;
            break;
        case '-':
            speed+=20;
            if(speed>600)
                speed=600;
            break;
        case 'p':
            g_waitKey(0);
            break;
        case '8':
        case '5':
        case '4':
        case '6':
            d=c;
            break;
        default:
            //printf("not s1");
            break;
        }
    }
    if((e+f)!=('w'+'s')&&(e+f)!=('a'+'d'))  //判斷是否移動不合理
    {
        switch(e)
        {
        case 27:
            play=0;
            break;
        case '+':
            speed-=20;
            if(speed<10)
                speed=10;
            break;
        case 'p':
            g_waitKey(0);
            break;
        case 'w':
        case 's':
        case 'a':
        case 'd':
            f=e;
            break;
        default:
            //printf("not s2");
            break;
        }
    }

    int i;
    for(i=s_len-1; i>0; i--)
    {
        s_x[i]=s_x[i-1];
        s_y[i]=s_y[i-1];
    }
    for(i=s_len_2-1; i>0; i--)
    {
        s_x_2[i]=s_x_2[i-1];
        s_y_2[i]=s_y_2[i-1];
    }

    switch(d)
    {
    case '8':
        s_y[0]-=20;
        break;
    case '5':
        s_y[0]+=20;
        break;
    case '4':
        s_x[0]-=20;
        break;
    case '6':
        s_x[0]+=20;
        break;
    default:
        printf("move s1 error c is %c\n",c);
    }
    switch(f)
    {
    case 'w':
        s_y_2[0]-=20;
        break;
    case 's':
        s_y_2[0]+=20;
        break;
    case 'a':
        s_x_2[0]-=20;
        break;
    case 'd':
        s_x_2[0]+=20;
        break;
    default:
        printf("move s2 error c is %c\n",c);
    }
}
int is_gameover()
{
    int i;
    if(s_x[0]<20||s_x[0]>width*(600.0/940)||s_y[0]<25||s_y[0]>height-25)
    {
        return 1;
    }
    for(i=1; i<s_len; i++)
    {
        if(s_x[i]==s_x[0]&&s_y[i]==s_y[0])
            return 1;
    }
    return 0;
}
int is_gameover_2()
{
    if(s_x[0]==s_x_2[0]&&s_y[0]==s_y_2[0])
    {
        winner=0;
        return 1;
    }
    int i;
    if(s_x[0]<20||s_x[0]>width*(600.0/940)||s_y[0]<25||s_y[0]>height-25)
    {
        winner=2;
        return 1;
    }
    if(s_x_2[0]<20||s_x_2[0]>width*(600.0/940)||s_y_2[0]<25||s_y_2[0]>height-25)
    {
        winner=1;
        return 1;
    }
    for(i=1; i<s_len; i++)
    {
        if(s_x[i]==s_x[0]&&s_y[i]==s_y[0])
        {
            winner=2;
            return 1;
        }
    }
    for(i=1; i<s_len_2; i++)
    {
        if(s_x_2[i]==s_x_2[0]&&s_y_2[i]==s_y_2[0])
        {
            winner=1;
            return 1;
        }
    }
    for(i=1; i<s_len; i++)
    {

        if(s_x[i]==s_x_2[0]&&s_y[i]==s_y_2[0])
        {
            winner=1;
            return 1;
        }
    }
    for(i=1; i<s_len_2; i++)
    {
        if(s_x_2[i]==s_x[0]&&s_y_2[i]==s_y[0])
        {
            winner=2;
            return 1;
        }
    }

    return 0;
}
void food_rand()
{
    if(is_food==0)
    {
        food_x=((int)(fabs(rand()*time(NULL)/7))%29+1)*20+10;
        food_y=((int)(fabs(rand()*time(NULL)/5))%30+1)*20+10;
        is_food=1;
    }

}
void s_eat_food()
{
    if(s_x[0]==food_x&&s_y[0]==food_y)
    {
        s_playSound(1,0,1);
        is_food_head=1;
        is_food=0;
        food_head_x=food_x;
        food_head_y=food_y;
        grade_int+=10;
    }
    if(is_food_head==1)
    {
        if(s_x[s_len-1]==food_head_x&&s_y[s_len-1]==food_head_y)
        {
            s_move(c);
            s_x[s_len]=food_head_x;
            s_y[s_len]=food_head_y;
            s_len++;
            is_food_head=0;
        }
    }

}
void s_eat_food_2()
{
    if(s_x[0]==food_x&&s_y[0]==food_y)
    {
        s_playSound(1,0,1);
        is_food_head=1;
        is_food=0;
        food_head_x=food_x;
        food_head_y=food_y;
        grade_int+=10;
    }
    if(is_food_head==1)
    {
        if(s_x[s_len-1]==food_head_x&&s_y[s_len-1]==food_head_y)
        {
            s_move_2(c);
            s_x[s_len]=food_head_x;
            s_y[s_len]=food_head_y;
            s_len++;
            is_food_head=0;
        }
    }
    if(s_x_2[0]==food_x&&s_y_2[0]==food_y)
    {
        s_playSound(1,0,1);
        is_food_head_2=1;
        is_food=0;
        food_head_x_2=food_x;
        food_head_y_2=food_y;
        grade_int_2+=10;
    }
    if(is_food_head_2==1)
    {
        if(s_x_2[s_len_2-1]==food_head_x_2&&s_y_2[s_len_2-1]==food_head_y_2)
        {
            s_move_2(c);
            s_x_2[s_len_2]=food_head_x_2;
            s_y_2[s_len_2]=food_head_y_2;
            s_len_2++;
            is_food_head_2=0;
        }
    }
}
void is_level()
{
    switch(grade_int/10)
    {
    case 2:
        level_speed=210;
        speed=210;
        level=2;
        break;
    case 5:
        level_speed=150;
        speed=150;
        level=3;
        break;
    case 10:
        level_speed=120;
        speed=120;
        level=4;
        break;
    case 20:
        level_speed=100;
        speed=100;
        level=5;
        break;
    case 30:
        level_speed=80;
        speed=80;
        level=6;
        break;
    case 40:
        level_speed=60;
        speed=60;
        level=7;
        break;
    case 50:
        level_speed=40;
        speed=40;
        level=8;
        break;
    case 60:
        level_speed=30;
        speed=30;
        level=9;
        break;
    case 100:
        level_speed=20;
        speed=20;
        level=10;
        break;
    default:
        printf("is_level error\n");
        break;
    }


}
void p_1()
{

    g_clear(255,255,255);
    //清除繪圖視窗影像並塗滿顏色

    dis_arram();

    s_initial();
    while(play)
    {
        food_rand();

        s_eat_food();

        print_snack_food();
        is_level();
        print_grade_speed();
        c=g_waitKey(speed);
        s_move(c);


        if(is_gameover())
        {
            s_playSound(2, 0, 1);
            //printf("GAME OVER\n");
            break;
        }
    }
    if(play)
    {
        g_loadFromFile("GameOver.png");
        g_saveToMemory(1);
        g_show();
        g_waitKey(1200);
        g_waitKey(0);
    }
}
void p_2()
{

    g_clear(255,255,255);
    //清除繪圖視窗影像並塗滿顏色

    dis_arram_2();

    s_initial_2();
    while(play)
    {
        food_rand();

        s_eat_food_2();

        print_snack_food_2();
        print_grade_speed_2();

        c=g_waitKey(speed);
        //printf("after c is%d\n",c);
        s_move_2(c);

        if(is_gameover_2())
        {
            s_playSound(2, 0, 1);
            //printf("GAME OVER\n");
            break;
        }
    }
    if(play)
    {
        g_loadFromFile("GameOver.png");
        g_saveToMemory(1);
        g_show();
        g_waitKey(800);
        //g_waitKey(0);
        switch(winner)
        {
        case 0:
            g_loadFromFile("both_loose.png");
            g_saveToMemory(1);
            g_show();
            g_waitKey(0);
            break;
        case 1:
            g_loadFromFile("p1_win.png");
            g_saveToMemory(1);
            g_show();
            g_waitKey(0);
            break;
        case 2:
            g_loadFromFile("p2_win.png");
            g_saveToMemory(1);
            g_show();
            g_waitKey(0);
            break;
        }
    }
}
int main()
{
    s_initSound();
    sound_initial();
    while(close)
    {
        char input=0;
        play=1;
        g_init("貪吃蛇",height,width);
        g_clear(0,0,0);
        g_loadFromFile("choose.png");
        g_saveToMemory(1);
        do
        {
            g_show();
            input=g_waitKey(0);
        }
        while(input!='1'&&input!='2'&&input!=27);
        g_clear(255,255,255);
        switch(input)
        {
        case '1':
            while(play)
            {
                dis_arram();
                g_loadFromFile("start.png");
                g_saveToMemory(1);
                g_show();
                g_waitKey(0);
                p_1();
            }
            break;
        case '2':
            while(play)
            {
                dis_arram_2();
                g_loadFromFile("start.png");
                g_saveToMemory(1);
                g_show();
                g_waitKey(0);
                p_2();
            }
            break;
        case 27:
            close=0;
            break;
        default:
            printf("gamemood change fail\n");
            break;
        }

    }
    g_clear(0,0,0);
    g_loadFromFile("leave.png");
    g_saveToMemory(1);
    g_show();
    g_waitKey(700);
    g_close();
    return 0;
}
