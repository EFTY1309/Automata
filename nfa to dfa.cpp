#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void nfatodfa(string s)
{
  cout<<"Transitions states of DFA are"<<endl;

  string s1="a";

  for(int i=0;i<s.length();i++)
  {
   if(s1=="a")
   {
     if(s[i]=='0')
     {
        s1="a";
        cout<<"(a,0)->a"<<endl;
     }
     else if(s[i]=='1')
     {
         s1="ab";
         cout<<"(a,1)->ab"<<endl;

     }
   }

  else if(s1=="ab")
   {
     if(s[i]=='0')
     {
        s1="a";
        cout<<"(ab,0)->a"<<endl;
     }
     else if(s[i]=='1')
     {
         s1="abc";
         cout<<"(ab,1)->abc"<<endl;

     }
   }

   else if(s1=="abc")
   {
     if(s[i]=='0')
     {
        s1="a";
        cout<<"(abc,0)->a"<<endl;
     }
     else if(s[i]=='1')
     {
         s1="abcd";
         cout<<"(abc,1)->abcd"<<endl;

     }
   }

   else if(s1=="abcd")
   {
     if(s[i]=='0')
     {
        s1="ad";
        cout<<"(abcd,0)->ad"<<endl;
     }
     else if(s[i]=='1')
     {
         s1="abcd";
         cout<<"(abcd,1)->abcd"<<endl;

     }
   }

   else if(s1=="ad")
   {
     if(s[i]=='0')
     {
        s1="ad";
        cout<<"(ad,0)->ad"<<endl;
     }
     else if(s[i]=='1')
     {
         s1="abd";
         cout<<"(ad,1)->abd"<<endl;

     }
   }

   else if(s1=="abd")
   {
     if(s[i]=='0')
     {
        s1="ad";
        cout<<"(abd,0)->ad"<<endl;
     }
     else if(s[i]=='1')
     {
         s1="abcd";
         cout<<"(abd,1)->abcd"<<endl;

     }
   }



  }
}






int main()
{
int i;
char str[MAX],f='a';
printf("Enter string = ");
scanf("%s",str);
for ( i=0;str[i]!='\0';i++)
{
 switch(f)
 {
   case 'a':

if(str[i]=='0')
{
f='a';
printf("(a,0)>>>>> a\n");
}
else if(str[i]=='1'&& str[i+1]=='1'&& str[i+2]=='1')
{
f='b';
printf("(a,1)>>>>> b\n");
}
else
{
f='a';
printf("(a,1)>>>>> a\n");
}

break;

case 'b':

 if(str[i]=='1')
{
f='c';
printf("(b,1)>>>>> c\n");
}
break;

case 'c':

 if(str[i]=='1')
{
f='d';
printf("(c,1)>>>>> d\n");
}
break;

case 'd':

if(str[i]=='0')
{
f='d';
printf("(d,0)>>>>> d\n");
}
else if(str[i]=='1')
{
f='d';
printf("(d,1)>>>>> d\n");
}
break;
}
}

if(f=='d')
{
  printf("This string is ACCEPTED\n");
  nfatodfa(str);
}

else
printf("This string is not ACCEPTED\n");
return 0;
}
