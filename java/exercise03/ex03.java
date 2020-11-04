//封装分数

//按要求补全程序（可以根据需要添加其他代码），并上机调试
//将调试通过的程序抄写到实验报告上

class CNumber   //封装分数类
{
 private long a;   //分数的分母
 private long b;   //分数的分子
 private char f;   //分数的符号（正、负号）

 public CNumber(long x,long y)   //x, y可以是任意整数
 {
  if(x!=0)
  {
   if(x>0 && y>=0)
   {
    a=x;
    b=y;
    f='+';
   }
   else
    if(x>0 && y<0)
    {
     a=x;
     b=-y;
     f='-';
    }
    else
     if(x<0 && y>=0)
     {
      a=-x;
      b=y;
      f='-';
     }
     else
     {
      a=-x;
      b=-y;
      f='+';
     }
   simpleCNumber();   //将分数化为最简分数
  }
  else
  {
   System.out.println("分母不能为0");
   System.exit(0);
  }
 }

 public long getA()
 {
  return a;
 }

 public long getB()
 {
  return b;
 }

 public char getChar()
 {
  return f;
 }

 public void simpleCNumber()
 {
  //将分数化为最简分数
  long min=a<b?a:b;
  for(int i=2;i<=min;i++){
    if(a%i==0&&b%i==0){
        a=a/i;
        b=b/i;
        simpleCNumber();
        return;
    }
  }
 }

 public CNumber add(CNumber oper)
 {
  //分数的加法
  long base=a*oper.getA();
  long up=(f=='+'?1:-1)*b*oper.getA()+(oper.getChar()=='+'?1:-1)*oper.getB()*a;
  return new  CNumber(base,up);
 }

 public CNumber sub(CNumber oper)
 {
   //分数的减法
   return add(new CNumber(oper.getA(),oper.getB()*(oper.getChar()=='+'?-1:1)));
 }

 public CNumber muti(CNumber oper)
 {
  //分数的乘法
  long base=a*oper.getA();
  long up=b*oper.getB()*(oper.getChar()==getChar()?1:-1);
  return new CNumber(base,up);
 }

 public CNumber div(CNumber oper)
 {
  //分数的除法
  long base=oper.getB();
  long up=oper.getA()*(oper.getChar()=='+'?1:-1);
  return muti(new CNumber(base,up));
}

 public String toString()
 {
  //重写Oject类的toString方法，按照常规格式将分数转换为字符串
  return getChar()+""+getB()+"/"+getA();
 }
}

public class ex03
{
 public static void main(String args[])
 {
  CNumber num1=new CNumber(7,4);
  CNumber num2=new CNumber(5,-4);
  System.out.println("num1="+num1);
  System.out.println("num2="+num2);

  CNumber num4=num1.add(num2);
  System.out.println("num1+num2="+num4);

  num4=num1.sub(num2);
  System.out.println("num1-num2="+num4);

  num4=num1.muti(num2);
  System.out.println("num1*num2="+num4);

  num4=num1.div(num2);
  System.out.println("num1/num2="+num4);
 }
}