import java.util.Scanner;
public class Form {
	public static void main(String args[])
	{
	 String str;int i;int k;char m;int j;
	 Scanner scan=new Scanner(System.in);
	 System.out.println("Enter secret code");
	  str=scan.nextLine();
///////////////////////////////////////////////////////////////////////////	  
     char s[]= new char[100]; //// Character array
        int x=str.length();
	  for(i=0;i<x;i++)
	  {
		  k=(int)str.charAt(i)-10;
		    m=(char)k;
		  s[i]=m;
	  }
	  String str1=new String(s);
	  System.out.println("Encripted Mssg ");
	  System.out.println(str1);
///////////////////////////////////////////////////////////////////////////	  
	  System.out.println("Enter key for Decription ");
	  int key1=scan.nextInt();
	  int u;char r;
	  char s1[]=new char[100];  ////// Character array
	  if(key1==10)
	  {
		int p=str1.length();  
		 for(j=0;j<p;j++)
		 {  
		  u=(int)str1.charAt(j)+10;
		  r=(char)u;
		  s1[j]=r;
		  System.out.print(r);
	     }
	   // String str2=new String(s1);
	    //System.out.println(str2);
	  }  
	  else 
	  {
		  System.out.println("Invalid Key");  
	  }
	}
}