//用多线程模拟三个人排队买电影票（每张5元），
//售票员只有3张5元钞票，
//三个买票人按前后顺序分别是张某（拿着20元钞票）、李某（拿着10元钞票）和赵某（拿着5元钞票）。

//三个买票过程（一个过程包括买票人出钱到售票员找钱给票）的多线程交叉同步问题
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;


class MoneyBox {   //售票员钱箱
    int price=5;
    int num_cash[]=new int[3];
    int cash_value[]={5,10,20};
    public MoneyBox(int num_5,int num_10,int num_20){
        num_cash[0]=num_5;
        num_cash[1]=num_10;
        num_cash[2]=num_20;
    }
 }

class BuyAndSell implements Runnable {
    MoneyBox mb;
    List<customer> customers;
    int max_wait_time=10;
    static int num_customer=0;
    public BuyAndSell(MoneyBox mb,List<customer> customers){
        this.mb=mb;
        this.customers=customers;
    }
    public void run(){
        sell();
    };//优先找大纸币 优先给小纸币
    private synchronized void sell(){ 
        System.out.println("Starting to treat customer"+(num_customer+1));
        customer c=customers.get(num_customer++);
        int error=0;
        int sum=0;
        for(int i=0;i<c.num_cash.length&&sum<mb.price;i++){
            while(sum<mb.price&&c.num_cash[i]>0){
                sum+=mb.cash_value[i];
                System.out.println("Receive  a $"+mb.cash_value[i]);
                mb.num_cash[i]++;
                c.num_cash[i]--;
            }
        }
        System.out.println("There are  "+mb.num_cash[0]+" $5 ,"+mb.num_cash[1]+" $10 ," +mb.num_cash[2]+" $20");
        error=sum-mb.price;
        int temp_error=error;
        int temp[]=new int[mb.num_cash.length];
        while(temp_error>0&&max_wait_time>0){
            temp_error=error;
            for(int i=c.num_cash.length-1;i>=0&&error>0;i--){
                while(temp_error>0&&temp[i]<mb.num_cash[i]&&temp_error-mb.cash_value[i]>=0){
                    temp_error-=mb.cash_value[i];
                    temp[i]++;
                }
            }
            try{
                if(temp_error>0){
                    System.out.println(num_customer+" : No enough changes ,please wait !");
                    max_wait_time--; 
                }
                wait(1);
            }catch(Exception e){
                e.printStackTrace();
            }

        }
        if(max_wait_time<=0){
            System.out.println("Time out "+" leave");
            return;
        }
        System.out.println("Give out  "+temp[0]+" 5$ ,"+temp[1]+" 10$  ,"+temp[2]+ "  20$ " );
        for(int i=0;i<mb.num_cash.length;i++){
            mb.num_cash[i]-=temp[i];
        }
}  
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
        temp=br.readLine().split(" ");
        MoneyBox mb=new MoneyBox(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]),Integer.parseInt(temp[2]));
        int num_costomer=Integer.parseInt(br.readLine());
        List<customer> customers=new ArrayList<customer>();
        List<Thread> threads=new ArrayList<>();
        //List<BuyAndSell> threads=new ArrayList<>();
        BuyAndSell bs=new BuyAndSell(mb, customers);

        for(int i=0;i<num_costomer;i++){
            temp=br.readLine().split(" ");
            customers.add(new customer(temp[0],Integer.parseInt(temp[1]),Integer.parseInt(temp[2]),Integer.parseInt(temp[3])));
        }
        for(int i=0;i<num_costomer;i++){

            threads.add(new Thread(bs,""+i));
            threads.get(i).start();
        }
    }
}