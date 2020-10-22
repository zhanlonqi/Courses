import java.util.*;

public class ex02
{
	
 public static void main(String args[])
 {
  int length=args.length;
	Arrays.sort(args,new StringComparator());
  //通过命令行参数输入多个字符串
  //对字符串进行排序，按字母顺序降序排列
  for(int i=0;i<length;i++)
   System.out.println(args[i]);
 }
}
class StringComparator implements Comparator<String>{
		@Override 
		public int compare(String s1,String s2){
			return -1*s1.compareTo(s2);
		}
	}