public class ex01
{
 public static void main(String args[ ])
 {
  char ch;
  int i;

  for(i=9312;i<9322;i++)
  {
   //��1����iת��Ϊchar�������ݲ���ֵ��ch
	ch=(char)i;
   System.out.print("   "+ch);
  }
  System.out.println();
  for(ch=9332+(0);ch<9342+(0);ch++)
  {
   //��2�������ch�ܷ�ֱ�������Ϊʲô��
   System.out.print("   "+ch);
  }
  System.out.println();

  for(ch=0x3220;ch<0x322A;ch++)
  {
   //��3�������ch�ܷ�ֱ�������Ϊʲô��
   System.out.print("   "+ch);
  }
  System.out.println();

  for(ch='0';ch<='9';ch++)
  {
   //��4����chת��Ϊint�������ݲ���ֵ��i
	i=ch-'0';
   System.out.print("    "+i);
  }
  System.out.println();
 }
}