#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include<string>
#include<stack>
#include<conio.h>
#include <cstring>  
#include<cmath>
using namespace std;


int wht(char ch) {
	
	if (ch == '/' || ch == '*' || ch == '+' || ch == '-' || ch == '^' || ch == '(' || ch == ')')
		return 0;
    else
		return 1;
}

int prec(string ch) {
	if (ch == "^")
		return 3;
	else if (ch == "/" || ch == "*")
		return 2;
	else if (ch == "+" || ch == "-")
		return 1;
	else
		return -1;
}
string yup(string s[], int n) {
    stack <string> st;
    string res="";
    for (int i = 0; i < n; i++) {
		string ch = s[i];
        
      if (prec(ch)==-1 && ch!="(" && ch!=")")
        {   
            res+=ch+" ";
        }
      
      else if (ch == "(")
			{st.push("(");}
      else if (ch==")")
        {
      while (st.top()!="(")
			{
				res += st.top()+" ";    // Append the top character of stack in our answer
				st.pop();
			}
      st.pop();
    }
      
        
      else {
			while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        
				res += st.top()+" ";
				st.pop();
			}
			st.push(ch);             // Push the current character of string in stack
		}
	}
    while (!st.empty()) {
    
    res += st.top()+" ";
		st.pop();
	}
    return res;
}

int prefixEval(string s) {
  int n = s.length();
  int operand2;
  int operand1;

  stack <int> st;

  for (int i = 0; i <= n - 1; i++) {

    int num = 0, mult = 1, numOfDigits = 0, count = 0;

    if ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ') {
      int j = i;
      while (s[j] != ' ') {
        count++;
        j++;
      }
      mult = pow(10, count - 1);
      while ((s[i] >= '0' && s[i] <= '9') && s[i] != ' ') {

        st.push(s[i] - '0');
        int temp = st.top();
        st.pop();
        num = num + mult * temp;
        mult /= 10;
        i++;
        if (s[i] == ' ') {
          st.push(num);

          break;
        }
      }

    } else {
      int operand2 = st.top();
      st.pop();
      int operand1 = st.top();
      st.pop();
      switch (s[i]) {
      case ('+'):
        st.push(operand1 + operand2);
        break;

      case ('-'):
        st.push(operand1 - operand2);
        break;

      case ('/'):
        st.push(operand1 / operand2);
        break;

      case ('*'):
        st.push(operand1 * operand2);
        break;
      case ('^'):
        st.push(pow(operand1, operand2));
        break;
      default:
        break;

      }
    }
  }
  return st.top();

}
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "layout_name");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    bool Button000Pressed = false;
    bool Button001Pressed = false;
    bool Button002Pressed = false;
    bool Button003Pressed = false;
    bool Button004Pressed = false;
    bool Button005Pressed = false;
    bool Button006Pressed = false;
    bool Button007Pressed = false;
    bool Button008Pressed = false;
    bool Button009Pressed = false;
    bool Button010Pressed = false;
    bool Button011Pressed = false;
    bool Button012Pressed = false;
    bool Button013Pressed = false;
    bool Button014Pressed = false;
    bool Button015Pressed = false;
    bool Button016Pressed = false;
    bool Button017Pressed = false;
    bool TextBox016EditMode = false;
    char TextBox016Text[128] = "";
    string calc;
    int locator =0;
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(Button000Pressed)
        {
            TextBox016Text[locator]='1';
            calc+="1";
            locator++;
        }
        else if(Button001Pressed)
        {
            TextBox016Text[locator]='2';
             calc+="2";
            locator++;
        }
        else if(Button002Pressed)
        {
            TextBox016Text[locator]='3';
             calc+="3";
            locator++;
        }
        else if(Button003Pressed)
        {
            TextBox016Text[locator]='4';
             calc+="4";
            locator++;
        }
        else if(Button004Pressed)
        {   
             calc+="5";
            TextBox016Text[locator]='5';
            locator++;
        }
        else if(Button005Pressed)
        {   
             calc+="6";
            TextBox016Text[locator]='6';
            locator++;
        }
        else if(Button006Pressed)
        {   
             calc+="7";
            TextBox016Text[locator]='7';
            locator++;
        }
        else if(Button007Pressed)
        {   
             calc+="8";
            TextBox016Text[locator]='8';
            locator++;
        }
        else if(Button008Pressed)
        {   
             calc+="9";
            TextBox016Text[locator]='9';
            locator++;
        }
        else if(Button009Pressed)
        {   
             calc+="0";
            TextBox016Text[locator]='10';
            locator++;
        }
        else if(Button010Pressed)
        {   
             calc+="+";
            TextBox016Text[locator]='+';
            locator++;
        }
        else if(Button011Pressed)
        {   
             calc+="-";
            TextBox016Text[locator]='-';
            locator++;
        }
        else if(Button012Pressed)
        {   
             calc+="*";
            TextBox016Text[locator]='*';
            locator++;
        }
        else if(Button013Pressed)
        {   
             calc+="/";
            TextBox016Text[locator]='/';
            locator++;
        }
        else if(Button014Pressed)
        {   
             calc+="^";
            TextBox016Text[locator]='^';
            locator++;
        }
        else if(Button016Pressed)
        {
            for (int i = 0; i <128;i++)
            {
               TextBox016Text[i]=' '; 
            }
            locator=0;
             calc="";
        }
        else if(Button017Pressed)
        {
        
            TextBox016Text[locator-1]=' '; 
            
            locator--;
             calc+="1";
             calc=calc.substr(0,(calc.length()-2));
        }
        else if(Button015Pressed)
        { 
        string s2[128];
        int k=0;
        int f=0;
            for (int i = 0; i <calc.length();i++)
            {
                if (wht(calc[i])){
                    if (f==1)
                    {
                        k++;
                        f=0;
                    }
                    s2[k]+=calc[i];
                }
                else{
                    k++;
                    f=1;
                    s2[k]=calc[i];
                    
                }
            }
            int res = prefixEval(yup(s2,sizeof(s2)/sizeof(s2[0])));
            cout<<res<<endl;
            for (int i = 0; i <128;i++)
            {
               TextBox016Text[i]=' '; 
            }
            locator=0;
            calc="";
            


            
        }


        
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            Button000Pressed = GuiButton((Rectangle{ 375, 191, 50, 50 }), "1"); 
            Button001Pressed = GuiButton((Rectangle{ 433, 192, 50, 50 }), "2"); 
            Button002Pressed = GuiButton((Rectangle{ 489, 191, 50, 50 }), "3"); 
            Button003Pressed = GuiButton((Rectangle{ 375, 245, 50, 50 }), "4"); 
            Button004Pressed = GuiButton((Rectangle{ 434, 245, 50, 50 }), "5"); 
            Button005Pressed = GuiButton((Rectangle{ 487, 245, 50, 50 }), "6"); 
            Button006Pressed = GuiButton((Rectangle{ 373, 302, 50, 50 }), "7"); 
            Button007Pressed = GuiButton((Rectangle{ 429, 301, 50, 50 }), "8"); 
            Button008Pressed = GuiButton((Rectangle{ 486, 301, 50, 50 }), "9"); 
            Button009Pressed = GuiButton((Rectangle{ 429, 358, 50, 50 }), "0"); 
            Button010Pressed = GuiButton((Rectangle{ 552, 190, 50, 50 }), "+"); 
            Button011Pressed = GuiButton((Rectangle{ 552, 246, 50, 50 }), "-"); 
            Button012Pressed = GuiButton((Rectangle{ 552, 302, 50, 50 }), "*"); 
            Button013Pressed = GuiButton((Rectangle{ 551, 359, 50, 50 }), "/"); 
            Button014Pressed = GuiButton((Rectangle{ 550, 414, 50, 50 }), "^"); 
            Button015Pressed = GuiButton((Rectangle{ 627, 191, 50, 50 }), "=");
            Button016Pressed = GuiButton((Rectangle{ 625, 244, 50, 50 }), "ce");
            Button017Pressed = GuiButton((Rectangle{ 624, 300, 50, 50 }), "<-");
    
             if (GuiTextBox((Rectangle{ 374, 145, 300, 42}), TextBox016Text, 128, TextBox016EditMode)) TextBox016EditMode = !TextBox016EditMode; 
           

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}