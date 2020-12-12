//用多线程模拟三个人排队买电影票（每张5元），
//售票员只有3张5元钞票，
//三个买票人按前后顺序分别是张某（拿着20元钞票）、李某（拿着10元钞票）和赵某（拿着5元钞票）。

//三个买票过程（一个过程包括买票人出钱到售票员找钱给票）的多线程交叉同步问题
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;


class MoneyBox {   //售票员钱箱
    int price=5,max_wait_time=10;
    int num_cash[]=new int[3];
    int cash_value[]={5,10,20};
    List<customer> customers;
    static int num_customer=0;
    public MoneyBox(int num_5,int num_10,int num_20,List<customer> customers){
        num_cash[0]=num_5;
        num_cash[1]=num_10;
        num_cash[2]=num_20;
        this.customers=customers;
    }
    public synchronized void sell(){ 
        System.out.println("Starting to treat customer"+(num_customer+1));
        customer c=customers.get(num_customer++);
        int error=0;
        int sum=0;
        for(int i=0;i<c.num_cash.length&&sum<price;i++){
            while(sum<price&&c.num_cash[i]>0){
                sum+=cash_value[i];
                System.out.println("Receive  a $"+cash_value[i]);
                num_cash[i]++;
                c.num_cash[i]--;
            }
        }
        System.out.println("There are  "+num_cash[0]+" $5 ,"+num_cash[1]+" $10 ," +num_cash[2]+" $20");
        error=sum-price;
        int temp_error=error;
        int temp[]=new int[num_cash.length];
        while(temp_error>0&&max_wait_time>0){
            temp_error=error;
            for(int i=c.num_cash.length-1;i>=0&&error>0;i--){
                while(temp_error>0&&temp[i]<num_cash[i]&&temp_error-cash_value[i]>=0){
                    temp_error-=cash_value[i];
                    temp[i]++;
                }
            }
            try{
                if(temp_error>0){
                    System.out.println(num_customer+" : No enough changes ,please wait !");
                    max_wait_time--; 
                }
                wait();   
            }catch(Exception e){
                e.printStackTrace();
            }

        }
        if(max_wait_time<=0){
            System.out.println("Time out "+" leave");
            return;
        }
        System.out.println("Give out  "+temp[0]+" 5$ ,"+temp[1]+" 10$  ,"+temp[2]+ "  20$ " );
        for(int i=0;i<num_cash.length;i++){
            num_cash[i]-=temp[i];
        }
        notifyAll();
}  
 }

class BuyAndSell implements Runnable {
    MoneyBox mb;
    List<customer> customers;
    int max_wait_time=10;
    
    public BuyAndSell(MoneyBox mb){
        this.mb=mb;
    }
    public void run(){
        mb.sell();
    };//优先找大纸币 优先给小纸币

}

class customer{
    String name;
    int num_cash[]=new int[3];
    public customer(String name,int num_5,int num_10,int num_20){
        this.num_cash[0]=num_5;
        this.num_cash[1]=num_10;
        this.num_cash[2]=num_20;
    }
}


public class Test {
    public static void main(String args[ ]) throws Exception {
        File file=new File("/home/zhan/work/Courses/java/exercise04/config.txt");
        FileReader fr=new FileReader(file);
        BufferedReader br=new BufferedReader(fr);
        String s;
        String temp[];
        int num_costomer=Integer.parseInt(br.readLine());
        List<customer> customers=new ArrayList<customer>();
        List<Thread> threads=new ArrayList<>();
        

        for(int i=0;i<num_costomer;i++){
            temp=br.readLine().split(" ");
            customers.add(new customer(temp[0],Integer.parseInt(temp[1]),Integer.parseInt(temp[2]),Integer.parseInt(temp[3])));
        }
        temp=br.readLine().split(" ");
        MoneyBox mb=new MoneyBox(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]),Integer.parseInt(temp[2]),customers);
        BuyAndSell bs=new BuyAndSell(mb);
        for(int i=0;i<num_costomer;i++){
            threads.add(new Thread(bs,""+i));
            threads.get(i).start();
        }
    }
}