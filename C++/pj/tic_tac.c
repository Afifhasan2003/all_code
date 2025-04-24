#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {

     char a=' ',b=' ', c=' ',
          d=' ',e=' ', f=' ', 
          g=' ', h=' ',i=' ';
     int turn=1, move=0, player, again;
     char input;
    printf("1 or 2 player: ");
    scanf("%d", &player); 
    if(player>2 || player<1){
    
        printf("invalid player number");
        return 0;
        }
    
    

     while (1)
     {
        
        

        printf(" \n %c | %c |%c ",a,b,c);
        printf("\n---|---|--- \n");
        printf(" %c | %c |%c ",d,e,f);
        printf("\n---|---|--- \n");
        printf(" %c | %c |%c \n",g,h,i);
        
        if (a==b && b==c && a != ' '|| d==e && e==f && d != ' '|| g==h && h==i && i != ' '|| 
            a==d && d==g && a != ' '|| b==e && e==h && e != ' '|| c==f && f==i && i != ' '||
            a==e && e==i && a != ' '|| c==e && e==g && e != ' ' )
                                                            
        {
            // printf(" player %d won",turn==1? 2:1);
            if (turn==1)
            {
                printf("Player 2 won");
            } else printf("Player 1 won");
            
            
            printf("\n \n Want to play again? 1 for yes, 0 for no: ");
            scanf("%d", &again);
            if (again)
            {
                 a=' ',b=' ', c=' ',d=' ',e=' ', f=' ', g=' ', h=' ',i=' '; 
                 move=0;turn=1;
                continue;
            } else if (again==0)
            {   
                printf("program closing");
                
                break;
            }
            
            
            



        }
        if (move>=9)
        {
            printf("\n!!this game is a draw!!");

            printf("\n \n Want to play again? 1 for yes, 0 for no: ");
            scanf("%d", &again);
            if (again==1)
            {
                a=' ',b=' ', c=' ',d=' ',e=' ', f=' ', g=' ', h=' ',i=' ';
                move=0;turn=1;
                continue;
            } else if (again==0)
            {
                printf("Program closing");
                break;
            }





        }
        if (player==1 && turn==2)
        {   
            char com;
            while (1)
            {



                if (a=='0' && b=='0' && c==' ') {input='3'; break; }
            else if(a=='0' && c=='0' && b==' ') {input='2'; break; }
            else if(b=='0' && c=='0' && a==' ') {input='1'; break; }
            else if(d=='0' && e=='0' && f==' ') {input='6'; break; }
            else if(d=='0' && f=='0' && e==' ') {input='5'; break; }
            else if(e=='0' && f=='0' && d==' ') {input='4'; break; }
            else if(g=='0' && h=='0' && i==' ') {input='9'; break; }
            else if(g=='0' && i=='0' && h==' ') {input='8'; break; }
            else if(h=='0' && i=='0' && g==' ') {input='7'; break; }
            else if(a=='0' && d=='0' && g==' ') {input='7'; break; }
            else if(a=='0' && g=='0' && d==' ') {input='4'; break; }
            else if(d=='0' && g=='0' && a==' ') {input='1'; break; }
            else if(b=='0' && e=='0' && h==' ') {input='8'; break; }
            else if(b=='0' && h=='0' && e==' ') {input='5'; break; }
            else if(e=='0' && h=='0' && b==' ') {input='2'; break; }
            else if(c=='0' && f=='0' && i==' ') {input='9'; break; }        
            else if(c=='0' && i=='0' && f==' ') {input='6'; break; }
            else if(f=='0' && i=='0' && c==' ') {input='3'; break; }
            else if(a=='0' && e=='0' && i==' ') {input='9'; break; }
            else if(a=='0' && i=='0' && e==' ') {input='5'; break; }
            else if(e=='0' && i=='0' && a==' ') {input='1'; break; }
            else if(c=='0' && e=='0' && g==' ') {input='7'; break; }
            else if(c=='0' && g=='0' && e==' ') {input='5'; break; }
            else if(e=='0' && g=='0' && c==' ') {input='3'; break; }



            else if(a=='*' && b=='*' && c==' ') {input='3'; break; }
            else if(a=='*' && c=='*' && b==' ') {input='2'; break; }
            else if(b=='*' && c=='*' && a==' ') {input='1'; break; }
            else if(d=='*' && e=='*' && f==' ') {input='6'; break; }
            else if(d=='*' && f=='*' && e==' ') {input='5'; break; }
            else if(e=='*' && f=='*' && d==' ') {input='4'; break; }
            else if(g=='*' && h=='*' && i==' ') {input='9'; break; }
            else if(g=='*' && i=='*' && h==' ') {input='8'; break; }
            else if(h=='*' && i=='*' && g==' ') {input='7'; break; }
            else if(a=='*' && d=='*' && g==' ') {input='7'; break; }
            else if(a=='*' && g=='*' && d==' ') {input='4'; break; }
            else if(d=='*' && g=='*' && a==' ') {input='1'; break; }
            else if(b=='*' && e=='*' && h==' ') {input='8'; break; }
            else if(b=='*' && h=='*' && e==' ') {input='5'; break; }
            else if(e=='*' && h=='*' && b==' ') {input='2'; break; }
            else if(c=='*' && f=='*' && i==' ') {input='9'; break; }        
            else if(c=='*' && i=='*' && f==' ') {input='6'; break; }
            else if(f=='*' && i=='*' && c==' ') {input='3'; break; }
            else if(a=='*' && e=='*' && i==' ') {input='9'; break; }
            else if(a=='*' && i=='*' && e==' ') {input='5'; break; }
            else if(e=='*' && i=='*' && a==' ') {input='1'; break; }
            else if(c=='*' && e=='*' && g==' ') {input='7'; break; }
            else if(c=='*' && g=='*' && e==' ') {input='5'; break; }
            else if(e=='*' && g=='*' && c==' ') {input='3'; break; }
            
                
                



                srand(time(0));
            int temp=rand() %10;

            input='0' + temp;
            com=input;
                                    
        if (input=='1' && a==' ') break;
        else if (input=='3' && c==' ') break;
        else if (input=='2' && b==' ') break;
        else if (input=='4' && d==' ') break;
        else if (input=='5' && e==' ') break;
        else if (input=='6' && f==' ') break;
        else if (input=='7' && g==' ') break;
        else if (input=='8' && h==' ') break;
        else if (input=='9' && i==' ') break;
            }
            
        }
        
        if( player==2 || (player==1 && turn==1)){
            printf("Player %d give input: ",turn);
            scanf(" %c", &input);
            }
            if (input=='Q' || input=='q')
            {
                printf("Program closing");
                return 0;
            }
            

        if (input=='1' && a==' ')  if(turn==1) a='*';
                                        else a='0';

        else if (input=='2' && b==' ') if(turn==1) b='*';
                                        else b='0';
        
        else if (input=='3' && c==' ')  if(turn==1) c='*';
                                        else c='0';

        else if (input=='4' && d==' ')  if(turn==1) d='*';
                                        else d='0';

        else if (input=='5' && e==' ')  if(turn==1) e='*';
                                        else e='0';

        else if (input=='6' && f==' ')  if(turn==1) f='*';
                                        else f='0';

        else if (input=='7' && g==' ')  if(turn==1) g='*';
                                        else g='0';

        else if (input=='8' && h==' ')  if(turn==1) h='*';
                                        else h='0';

        else if (input=='9' && i==' ')  if(turn==1) i='*';
                                        else i='0';

        else {
                printf("\n ! invalid move");
                continue;
                }

        move++;
        if (turn==1)
        {
            turn=2;
        }
        else turn=1;
        
        
  
     }
return 0;
}