#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<math.h>
#include<fstream.h>
#include<iomanip.h>
#include<ctype.h>

struct item
{
 int icd,ipr;
 char inm[30];
}i1;

struct bill
{
 int itcd,qt,itpr;
 char itnm[30];
}b1;

int table[11];

void display();
void app();
int chkitm(int);
void design();
void add(int,int);
void maindis();
int readcat();
void view();
void catview(int);
void dlt();
void edit();
void adm();
int ent();
int intr(int,int);
void billing();
void orderbill();
void prebill();
void main()
{
  clrscr();
  display();
}
int ent()
{
 char a[10];
 int s=0,j=0,f;
 while(j==0)
 {
  f=0;
  gets(a);
  if(strcmp(a,"-1")==0)
   s=-1;
  else
  {
  //s=(s*10)+a[i];
  for(int i=0;i<strlen(a);i++)
  {
   if(!(a[i]>='0' && a[i]<='9'))
   {
    f=1;
    cout<<"Invalid Entry...\nTry Again  :";
    break;
   }
  }//for
  if(f!=1)
    break;
  }//else of a=-1;
 }//while
 for(int i=0;i<strlen(a);i++)
 {
  s=(s*10)+((int)a[i]-48);
 }

 return s;
}
int intr(int x,int y)
{
  int ca;
  char cr[10];
  gets(cr);
  //printf("\n%d",cr[0]);
  if(strlen(cr)==1)
  {
   if((cr[0]>=(48+x)) && (cr[0]<=(48+y)))
   {
    ca=(int)cr[0]-48;
   }
   else
   {
    ca=0;
   }
  }

  else
   ca=0;
  return ca;
}
void design()
{
  ofstream f;
  int k,cat;
  //i=variable which controls loop if we do i=0 then loop will break
  //cat=1
   maindis();
   // switch below this adds entry of given catagory
   cout<<"\t\t\t\tDESIGN MENU\n";
   cout<<"\t\t\t\t-----------\n";
   cat=readcat();
   if(cat>0 && cat<6)
   {
    cout<<"\n\nAll entries in given catagory will be deleted \n\n Are you sure want to continue ?(1 for yes/0 for no):";
    k=intr(0,1);
    if(k==1)
    {
     ofstream f1;
     switch(cat)
     {
      case 1:
       cout<<"Please enter details for SOUP catagory :\n";
       f1.open("soup.txt",ios::out);
       f1.close();
       add(cat,101);
       catview(cat);
       design();
       break;
      case 2:
       cout<<"Please enter details for STARTER catagory :\n";
       f1.open("starter.txt",ios::out);
       f1.close();
       add(cat,201);
       catview(cat);
       design();
       break;
      case 3:
       cout<<"Please enter details for SABJI catagory :\n";
       f1.open("sabji.txt",ios::out);
       f1.close();
       add(cat,301);
       catview(cat);
       design();
       break;
      case 4:
       cout<<"Please enter details for BREAD catagory :\n";
       f1.open("bread.txt",ios::out);
       f1.close();
       add(cat,401);
       catview(cat);
       design();
       break;
      case 5:
       cout<<"Please enter details for DESERT catagory :\n";
       f1.open("desert.txt",ios::out);
       f1.close();
       add(cat,501);
       catview(cat);
       design();
       break;
      default:
       adm();
       break;
     }//switch cataggory
    }//if(k==1)
    else
     design();
   }//if(cat)
   else
     adm();
}//design fn
void add(int c,int icod)
{
   ofstream fout;
   int j=1;
   i1.icd=icod;
   switch(c)
   {
    case 1:
     fout.open("soup.txt",ios::app | ios::binary);
     break;
    case 2:
     fout.open("starter.txt",ios::app | ios::binary);
     break;
    case 3:
     fout.open("sabji.txt",ios::app | ios::binary);
     break;
    case 4:
     fout.open("bread.txt",ios::app | ios::binary);
     break;
    case 5:
     fout.open("desert.txt",ios::app | ios::binary);
     break;
   }//switch cataggory

   //j is variable which controls loop of different entries in same catagories.
   maindis();
   while(j==1)
   {
    maindis();
    cout<<"Item code = "<<i1.icd;
    cout<<"\nPlease enter name of item :";
    gets(i1.inm);
    cout<<"Plaese enter price of item :";
    i1.ipr=ent();
    fout.write((char *) & i1,sizeof(item));
    //cout<<"icd="<<i1.icd<<"\nipr="<<i1.ipr;
    cout<<"\n\nDo you want to add another entry ?\n(1 for yes/0 for no):";
    j=intr(0,1);
    //fout<<'\n';
    i1.icd++;
   }//while(j==1)
   /*  fin.read((char *) & i1,sizeof(item));
     cout<<"\nipr="<<i1.ipr<<"\nicd="<<i1.icd;*/

   fout.close();
}//void add
void maindis()
{
  clrscr();
  cout<<"\n--------------------------------------------------------------------------------\n";
  cout<<"\t\t\t\tHOTEL BLUEMOON\n";
  cout<<"  \t\t\t\t\tMade By : Jainam Shah & TheSagar007\n";
  cout<<"--------------------------------------------------------------------------------\n";
}
void adm()
{
    int ch;
    maindis();
    cout<<"1.NEW MENU DESIGN\n2.NEW ITEM ENTRY\n3.EDIT ITEM\n4.DELETE ITEM\n5.VIEW MENU\n";
    cout<<"--------------------------------------------------------------------------------\n";
    cout<<"Enter choice (1-5) OR (6) to  exit : ";
    ch=intr(1,5);
    switch(ch)
    {
     case 1:
	design();
	break;
     case 2:
	app();
	break;
     case 3:
       edit();
	break;
     case 4:
	dlt();
	break;
     case 5:
	view();
	break;
     default :
	display();
     }//switch
}
void display()
{
  int ch;
  //back :
  maindis();
  cout<<"1.ADMINISTRATION LOGIN";
  cout<<"\n2.MANAGER LOGIN";
  cout<<"\n3.DAY LOGIN";
  cout<<"\n4.Exit";
  cout<<"\n--------------------------------------------------------------------------------\n";
  cout<<"Enter choice of login : ";
  ch=intr(1,3);
  switch(ch)
  {
   case 1:
	    adm();
     break;
   case 2:
     billing();
     break;
   case 3:
     for(int k=0;k<10;k++)
       table[k]=0;
       display();
      break;
   default:
    clrscr();
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\tTHANK YOU\n\n\t\t\t  -----Jainam Shah-----\n\n\t\t\t  -----TheSagar007-----";
    getch();
    break;
  }
}//display

int chkitm(int c)
{
  ifstream fin;
  switch(c)
   {
    case 1:
     fin.open("soup.txt",ios::in);
     break;
    case 2:
     fin.open("starter.txt",ios::in);
     break;
     case 3:
     fin.open("sabji.txt",ios::in);
     break;
    case 4:
     fin.open("bread.txt",ios::in);
     break;
    case 5:
     fin.open("desert.txt",ios::in);
     break;
   }//switch cataggory
  int cd;
  while(fin)
  {
     fin.read((char *) & i1,sizeof(item));//to read entries...
     cd=i1.icd;
     //fin.get(ch);
     if(fin.eof())
     {
      break;
     }
  }
  fin.close();
  cd++;
  return cd;
}
void app()
{
 maindis();
 int cdk,c,i;
 cout<<"\t\t\t\tNEW ITEM ENTRY\n";
 cout<<"\t\t\t\t--------------\n";
 c=readcat();
 if(c>0 && c<6)
 {
 cdk=chkitm(c);
 //cout<<"I code :"<<cdk;
 //getch();1212121
 add(c,cdk);
 catview(c);
 app();
 }
 else
   adm();
}
int readcat()
{
 int cat;
 cout<<"\n1. Soup\n2. Starter\n3. Sabji\n4. Bread\n5. Desert\n\nEnter catagory..\nor Press 6 to exit :";
 cat=intr(1,5);
 return cat;
}
void catview(int c)
{
 maindis();
 ifstream fin;
 char ch;
   switch(c)
   {
    case 1:
     fin.open("soup.txt",ios::in);
     cout<<"\n\n\t\t\t\tSOUP catagory\n\n";
     break;
    case 2:
     fin.open("starter.txt",ios::in);
     cout<<"\n\n\t\t\t\tSTARTER catagory\n\n";
     break;
     case 3:
     fin.open("sabji.txt",ios::in);
     cout<<"\n\n\t\t\t\tSABJI catagory\n\n";
     break;
    case 4:
     fin.open("bread.txt",ios::in);
     cout<<"\n\n\t\t\t\tBREAD catagory\n\n";
     break;
    case 5:
     fin.open("desert.txt",ios::in);
     cout<<"\n\n\t\t\t\tDESERT catagory\n\n";
     break;
   }//switch cataggory
 cout<<"\t\titem code  item name                item price\n";
 while(fin)
  {
     if(fin.eof())
     {
      break;
     }
     fin.read((char *) & i1,sizeof(item));//to read entries...
     //fin.get(ch);
     if(fin.eof())
     {
      break;
     }
     cout<<"\n\t\t"<<i1.icd<<"         ";
     cout.setf(ios::left);
     cout<<setw(25)<<i1.inm;
     cout.setf(ios::fixed);
     //cout<<setprecision(2);
     cout<<i1.ipr;
     //cout<<i1.icd<<"  "<<i1.inm<<"  "<<i1.ipr<<'\n';
  }
  fin.close();
  int i;
}//catview
void view()
{
 int ct=1,i;
 maindis();
 while(ct>0 && ct<6)
 {
  maindis();
  cout<<"\t\t\t\tVIEW MENU\n";
  cout<<"\t\t\t\t---------\n";
  cout<<"\nwhich catagory you want to view :";
  ct=readcat();
  if(ct>0 && ct<6)
  {
    catview(ct);
    getch();
  }
  else
  {
    break;
  }
 }
 adm();
}
/*
void dlt()
{
  int cat,q,cnf,i=0;
  maindis();
  cout<<"\t\t\t\tDelete Item\n";
  cout<<"\t\t\t\t-----------\n";
  cat=readcat();
  if(cat>0 && cat<6)
  {
  catview(cat);
  cout<<"\nEnter item code that you want to delete : ";
  q=ent();
  ofstream fout;
  ifstream fin;

  fout.open("temp.txt",ios::out);
  switch(cat)
   {
    case 1:
     fin.open("soup.txt",ios::in);
     break;
    case 2:
     fin.open("starter.txt",ios::in);
     break;
     case 3:
     fin.open("sabji.txt",ios::in);
     break;
    case 4:
     fin.open("bread.txt",ios::in);
     break;
    case 5:
     fin.open("desert.txt",ios::in);
     break;
   }//switch cataggory
   int xx=0;
   while(fin)//while to check wheather the given entry is valid or not
   {
       fin.read((char *) & i1,sizeof(item));//for read entries...
       if(fin.eof())
       {
       break;
       }
       if(i1.icd==q)
       {
	xx=1;
	cout<<"hooo";
       }
   }
  if(xx==1)
  {
   fin.seekg(0);
   while(fin)
   {
       fin.read((char *) & i1,sizeof(item));//for read entries...
       if(fin.eof())
       {
       break;
       }
       if(i1.icd==q)
       {
	 cout<<"\nItemcode : "<<i1.icd;
	 cout<<"\nItem name : "<<i1.inm;
	 cout<<"\nItem price : "<<i1.ipr;
	 cout<<"\nSure,You want to delete this record? (1 for yes/0 for no):";
	 cnf=intr(0,1);
	 if(cnf==0)
	 {
	     fout.write((char *) & i1,sizeof(item));
	     //fout<<'\n';
	 }
       }//if(i1.icd==q)
       else
       {
	    fout.write((char *) & i1,sizeof(item));
	    //fout<<'\n';
       }
   }//while
   fout.close();
   fin.close();
   switch(cat)
   {
    case 1:
      remove("soup.txt");
      rename("temp.txt","soup.txt");
     break;
    case 2:
     remove("starter.txt");
     rename("temp.txt","starter.txt");
     break;
     case 3:
     remove("sabzi.txt");
   rename("temp.txt","sabzi.txt");
     break;
    case 4:
     remove("bread.txt");
   rename("temp.txt","bread.txt");
     break;
    case 5:
     remove("desert.txt");
   rename("temp.txt","desert.txt");
     break;
   }//switch cataggory
   catview(cat);
  }//if(xx==1)
  else
  {
   cout<<"\nEntry not found in given catagory..";
   fout.close();
   fin.close();
  }
   cout<<"\nDo you want to delete another entry ?(1 for yes/0 for no):";
   i=intr(0,1);
   if(i==1)
    dlt();
   else
    adm();
  }//if cat .....1 to 5
  else
  {
    adm();
  }
}//delete
*/

void dlt()
{
  int cat,q,cnf;
  maindis();
  cout<<"\t\t\t\tDELETE ITEM\n";
  cout<<"\t\t\t\t---------\n";
  cat=readcat();
  if(cat>0 && cat<6)
  {
  catview(cat);
  cout<<"\nEnter item code that you want to delete : ";
  q=ent();
  ofstream fout;
  ifstream fin;

  fout.open("temp.txt",ios::out);
  switch(cat)
   {
    case 1:
     fin.open("soup.txt",ios::in);
     break;
    case 2:
     fin.open("starter.txt",ios::in);
     break;
     case 3:
     fin.open("sabji.txt",ios::in);
     break;
    case 4:
     fin.open("bread.txt",ios::in);
     break;
    case 5:
     fin.open("desert.txt",ios::in);
     break;
   }//switch cataggory

   while(fin)
   {
       fin.read((char *) & i1,sizeof(item));//for read entries...
       if(fin.eof())
       {
       break;
       }
       if(i1.icd==q)
       {
	 cout<<"\nItemcode : "<<i1.icd;
	 cout<<"\nItem name : "<<i1.inm;
	 cout<<"\nItem price : "<<i1.ipr;
	 cout<<"\nSure,You want to delete this record?(1 for Yes/0 for No) : ";
	 cnf=ent();
	 if(cnf!=1)
	 {
	     fout.write((char *) & i1,sizeof(item));
	     //fout<<'\n';
	 }
       }
       else
       {
	    fout.write((char *) & i1,sizeof(item));
	    //fout<<'\n';
       }
   }//while

   fout.close();
   fin.close();

   switch(cat)
   {
    case 1:
      remove("soup.txt");
      rename("temp.txt","soup.txt");
     break;
    case 2:
     remove("starter.txt");
     rename("temp.txt","starter.txt");
     break;
     case 3:
     remove("sabzi.txt");
   rename("temp.txt","sabzi.txt");
     break;
    case 4:
     remove("bread.txt");
   rename("temp.txt","bread.txt");
     break;
    case 5:
     remove("desert.txt");
   rename("temp.txt","desert.txt");
     break;
   }//switch cataggory
  catview(cat);
  maindis();
  dlt();
  }
  else
   adm();

}//delete
void edit()
{
 int ct,ic,pos,p,i=0;
 char nm[30];
 maindis();
 cout<<"\t\t\t\tEDIT ITEM\n";
 cout<<"\t\t\t\t---------\n";
 cout<<"\nwhich catagory you want to edit :";
 ct=readcat();
 if(ct>0 && ct<6)
 {
   catview(ct);
    cout<<"\nEnter item code u want to edit :";
    ic=ent();
   /* cout<<"\nic="<<ic;
    cout<<"\nct="<<ct;*/
   fstream f1;
   switch(ct)
   {
    case 1:
     f1.open("soup.txt",ios::in | ios::out);
     break;
    case 2:
     f1.open("starter.txt",ios::in | ios::out);
     break;
     case 3:
     f1.open("sabji.txt",ios::in | ios::out);
     break;
    case 4:
     f1.open("bread.txt",ios::in | ios::out);
     break;
    case 5:
     f1.open("desert.txt",ios::in | ios::out);
     break;
   }//switch cataggory
   int xx=0,xxx;
   while(f1)
   {
     if(f1.eof())
      break;
     pos=f1.tellg();
     f1.read((char *) &i1,sizeof(item));
     if(ic==i1.icd)
     {
      cout<<"\n\nItem code :"<<ic;
      cout<<"\nItem name :"<<i1.inm;
      cout<<"\nItem price :"<<i1.ipr<<"\n\n";
      cout<<"Type new item name (type '.' to continue with old name) :";
      gets(nm);
      if(strcmp(nm,".")!=0)
       strcpy(i1.inm,nm);
      cout<<"Enter new price(type -1 to continue with old price) :";
      xxx=ent();
      if(xxx!=-1)
       i1.ipr=xxx;
      f1.seekg(pos);
      f1.write((char *) &i1,sizeof(item));
      xx=1;
      break;
     }//if(ic=i1.icd)
   }//while(f1)
   f1.close();
   if(xx==0)
   {
    cout<<"\nEntry not found in given catagory..";
    getch();
    edit();
   }
   //else
   {
   catview(ct);
   cout<<"\n\nDo you want to edit another entry ? (1 for yes/0 for no):";
   i=intr(0,1);
   if(i==1)
    edit();
   else
    adm();
   }
 }//if(cat)
 else
  adm();
}
void billing()
{
   int j=1,i=1,tb,it,c,p=0;
   maindis();
   table[0]=1;
  cout<<"1.ORDER BILL\n2.PREPARE BILL";
  cout<<"\n--------------------------------------------------------------------------------\n";
  cout<<"Enter choice(1-2) [0 for exit] : ";
  c=intr(1,2);

  switch(c)
  {
   case 1:
	orderbill();
	break;
   case 2:
	prebill();
	break;
   default :
	display();

  }
}

void orderbill()
{
   int j=1,i=1,tb,it,c=1,p=0;
   maindis();
   cout<<"Enter table num (1-4) : ";
    tb=intr(1,4);
  /*  if(table[tb]==1)
    {
     cout<<"This table is already reserved...\nChoose another table..";
     orderbill();
    }
  else
  {
    */
   ofstream fout;
   ifstream fin;
   table[tb]=1;
   int xx=0;
    switch(tb)
    {
    case 1:
    fout.open("tb1.txt",ios :: app | ios :: binary);
    break;

    case 2:
    fout.open("tb2.txt",ios :: app | ios :: binary);
    break;

    case 3:
    fout.open("tb3.txt",ios :: app | ios :: binary);
    break;

    case 4:
    fout.open("tb4.txt",ios :: app | ios :: binary);
    break;

    default:
    cout<<"Table does not exist...";
    xx=1;
    getch();
    billing();
    break;

    }
   if(xx==0)
   {
   while(c>=1 && c<=5)
   {
    maindis();
    c=readcat();
    if(c<1 || c>5)
    {
      fout.close();
      billing();
      break;
    }//if
    maindis();
     i=1;
   switch(c)
   {
    case 1:
     fin.open("soup.txt",ios::in);
     break;

    case 2:
     fin.open("starter.txt",ios::in);
     break;

    case 3:
     fin.open("sabji.txt",ios::in);
     break;

    case 4:
     fin.open("bread.txt",ios::in);
     break;

    case 5:
     fin.open("desert.txt",ios::in);
     break;

   }//switch cataggory

   while(i==1)
    {
     p=0;
     catview(c);
     cout<<"\nEnter itemcode : ";
     it=ent();

     fin.seekg(0);
     while(fin)
     {
       fin.read((char *) & i1,sizeof(item));//for read entries...
       if(fin.eof())
       {
       break;
       }
       //cout<<"\nItem code ="<<it;
       if(i1.icd==it)
       {
	 strcpy(b1.itnm,i1.inm);
	 b1.itpr=i1.ipr;
	 cout<<"\nEnter Quantity : ";
	 b1.qt=ent();
	 b1.itcd=it;
	 fout.write((char *) & b1,sizeof(item));
	 p=1;
	 //cout<<"\nIn if condition p = "<<p;
	 break;
       }//end if
     }//while fin

     if(p==0)
     {
       cout<<"There is no item of this code";
       fin.close();
       switch(c)
       {
	case 1:
	fin.open("soup.txt",ios::in);
	break;

	case 2:
	fin.open("starter.txt",ios::in);
	break;

	case 3:
	fin.open("sabji.txt",ios::in);
	break;

	case 4:
	fin.open("bread.txt",ios::in);
	break;

	case 5:
	fin.open("desert.txt",ios::in);
	break;

       }//End switch
   }//ifp==0


     cout<<"\nDo you want to order any other item from this cat?(1-0) : ";
     i=intr(0,1);

   }//while i==1
 fin.close();
 }//j==1
 fout.close();
}//if(xx=0)
}//end orderbill



/*void prebill()
{
  int tb;
  double amt,total=0;
  ifstream fout;

  maindis();
   cout<<"Enter table num (1-4) : ";
    tb=intr(1,4);

   if(table[tb]==1)
   {

     maindis();

    int xx=0;
    switch(tb)
    {
    case 1:
    fout.open("tb1.txt",ios :: in);
    break;

    case 2:
    fout.open("tb2.txt",ios :: in);
    break;

    case 3:
    fout.open("tb3.txt",ios :: in);
    break;

    case 4:
    fout.open("tb4.txt",ios :: in);
    break;

    default:
    cout<<"This table does not exist..";
    xx=1;
    getch();
    billing();
    break;

    }//switch
 if(xx==0)
 {

     cout<<"\n\t\t\t\tBILL(TABLE NO. : "<<tb<<" )\n";
     cout<<"\t\t\t\t--------------------\n\n";
     cout<<"\t     ITEMCODE   ITEMNAME\t\t    PRICE    QUANTITY    AMOUNT\n";
     cout<<"\t     ------------------------------------------------------------------\n";

 while(fout)
 {
     fout.read((char *) & b1,sizeof(item));//for read entries...

    if(fout.eof())
    {
       break;
    }//if
     cout<<"\t     "<<b1.itcd;
     cout.setf(ios::left);
     cout<<"\t"<<setw(27)<<b1.itnm;
     cout.setf(ios::right);
     cout<<setw(4)<<b1.itpr;
     cout.setf(ios::fixed);
     cout<<"\t\t"<<b1.qt;
     amt=b1.itpr*b1.qt;
     cout.setf(ios::right);
     cout<<"\t"<<setw(6)<<amt<<"\n";
     total+=amt;

 }//while fout
 cout<<"\n\n\t\t\t\t\t\t\t        TOTAL : ";
 cout.setf(ios::right);
 cout<<setw(6)<<total;

 fout.close();
 ofstream fin;
    switch(tb)
    {
    case 1:
    fin.open("tb1.txt",ios :: out);
    fin.close();
    break;

    case 2:
    fin.open("tb2.txt",ios :: out);
    fin.close();
    break;

    case 3:
    fin.open("tb3.txt",ios :: out);
    fin.close();
    break;

    case 4:
    fin.open("tb4.txt",ios :: out);
    fin.close();
    break;

    }//switch
    table[tb]=0;
  getch();
  billing();
 }//ifxx=0
 }//if table[tb]
 else
 {
    cout<<"The table is vacant..";
    getch();
    billing();
 }//else


}//prebill()      */

void prebill()
{
  int tb;
  double amt,total=0;
  ifstream fout;

  maindis();
   cout<<"Enter table num (1-4) : ";
    tb=intr(1,4);

   /* if(table[tb]==0)
   {
    cout<<"The table is vacant....";
    getch();
    billing();
   }
   else
   { */

   if(table[tb]==1)
   {

     maindis();

    int xx=0;
    switch(tb)
    {
    case 1:
    fout.open("tb1.txt",ios :: in);
    break;

    case 2:
    fout.open("tb2.txt",ios :: in);
    break;

    case 3:
    fout.open("tb3.txt",ios :: in);
    break;

    case 4:
    fout.open("tb4.txt",ios :: in);
    break;

    default:
    cout<<"This table does not exist..";
    xx=1;
    getch();
    billing();
    break;

    }//switch

  int i,sicd[50],sqty[50],spr[50],n=0;
  char *snm;
  char tnm[30];

 while(fout)
 {
    fout.read((char *) & b1,sizeof(item));//for read entries...

    if(fout.eof())
    {
       break;
    }//if
    n++;
 }
 fout.close();

 snm=new char[n];
 i=0;
 switch(tb)
    {
    case 1:
    fout.open("tb1.txt",ios :: in);
    break;

    case 2:
    fout.open("tb2.txt",ios :: in);
    break;

    case 3:
    fout.open("tb3.txt",ios :: in);
    break;

    case 4:
    fout.open("tb4.txt",ios :: in);
    break;

    default:
    cout<<"This table does not exist..";
    xx=1;
    getch();
    billing();
    break;

    }//switch

 while(fout)
 {
     fout.read((char *) & b1,sizeof(item));//for read entries...

    if(fout.eof())
    {
       break;
    }//if

     sicd[i]=b1.itcd;
     strcpy(b1.itnm,tnm);
     puts(tnm);
     //strcpy(b1.itnm,snm[i]);
     spr[i]=b1.itpr;
     sqty[i]=b1.qt;
     i++;

 }//while fout

 for(i=0;i<n;i++)
 {
     cout<<"\n"<<sicd[i];
     cout<<"\t"<<snm[i];
     cout<<"\t"<<spr[i];
     cout<<"\t"<<sqty[i];
 }
 fout.close();





 //--------------------------------------------------------------------





    switch(tb)
    {
    case 1:
    fout.open("tb1.txt",ios :: in);
    break;

    case 2:
    fout.open("tb2.txt",ios :: in);
    break;

    case 3:
    fout.open("tb3.txt",ios :: in);
    break;

    case 4:
    fout.open("tb4.txt",ios :: in);
    break;

    default:
    cout<<"This table does not exist..";
    xx=1;
    getch();
    billing();
    break;

    }//switch
 if(xx==0)
 {

     cout<<"\n\t\t\t\tBILL(TABLE NO. : "<<tb<<" )\n";
     cout<<"\t\t\t\t--------------------\n\n";
     cout<<"\t     ITEMCODE   ITEMNAME\t\t    PRICE    QUANTITY    AMOUNT\n";
     cout<<"\t     ------------------------------------------------------------------\n";

 while(fout)
 {
     fout.read((char *) & b1,sizeof(item));//for read entries...

    if(fout.eof())
    {
       break;
    }//if
     cout<<"\t     "<<b1.itcd;
     cout.setf(ios::left);
     cout<<"\t"<<setw(27)<<b1.itnm;
     cout.setf(ios::right);
     cout<<setw(4)<<b1.itpr;
     cout.setf(ios::fixed);
     cout<<"\t\t"<<b1.qt;
     amt=b1.itpr*b1.qt;
     cout.setf(ios::right);
     cout<<"\t"<<setw(6)<<amt<<"\n";
     total+=amt;

 }//while fout
 cout<<"\n\n\t\t\t\t\t\t\t        TOTAL : ";
 cout.setf(ios::right);
 cout<<setw(6)<<total;

 fout.close();
 ofstream fin;
    switch(tb)
    {
    case 1:
    fin.open("tb1.txt",ios :: out);
    fin.close();
    break;

    case 2:
    fin.open("tb2.txt",ios :: out);
    fin.close();
    break;

    case 3:
    fin.open("tb3.txt",ios :: out);
    fin.close();
    break;

    case 4:
    fin.open("tb4.txt",ios :: out);
    fin.close();
    break;

    }//switch
    table[tb]=0;
  getch();
  billing();
 }//ifxx=0
 }//if table[tb]
 else
 {
    cout<<"The table is vacant..";
    getch();
    billing();
 }//else


}//prebill()