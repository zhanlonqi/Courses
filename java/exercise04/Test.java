//用多线程模拟三个人排队买电影票（每张5元），
//售票员只有3张5元钞票，
//三个买票人按前后顺序分别是张某（拿着20元钞票）、李某（拿着10元钞票）和赵某（拿着5元钞票）。

//三个买票过程（一个过程包括买票人出钱到售票员找钱给票）的多线程交叉同步问题
import java.util.*;
class MoneyBox {   //售票员钱箱
    int num_5;
    int num_10;
    int num_20;
    public MoneyBox(int num_5,int num_10,int num_20){
        this.num_5=num_5;
        this.num_10=num_10;
        this.num_20=num_20;
    }
}

class BuyAndSell extends Thread {
    MoneyBox mb;
    String name;
    int num_5;
    int num_10;
    int num_20;
    public BuyAndSell(MoneyBox mb,String name,int num_5,int num_10,int num_20){
        this.mb=mb;
        this.name=name;
        this.num_5=num_5;
        this.num_10=num_10;
        this.num_20=num_20;
    }
    public void run(){//优先找大纸币 优先给小纸币

        System.out.println("MoneyBox: "+mb.num_5+" 5$ "+mb.num_10+" 10$ "+mb.num_20+" 20$");
        if(num_5!=0){
            System.out.println("Receive a 5$ ");
            mb.num_5++;
        }
        else if(num_10!=0){
            if(mb.num_5>0){
                System.out.println("Receive a 10$");
                mb.num_10++;
                mb.num_5--;
                System.out.println("Give out a 5$ change");
            }
            else{
                System.out.println("No change left ,waitting");
                this.suspend();
            }
        }
        else if(num_20!=0){
            if(mb.num_10>0&&mb.num_5>0){
                System.out.println("Receive a 20$");
                mb.num_20++;
                mb.num_5--;
                mb.num_10--;
            }
            else {
                System.out.println("No change left ,waitting ");
                this.suspend();
            }
        }
        else {

        }
    }
}


public class Test {
    public static void main(String args[ ]) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Please input number of money");
        MoneyBox mb=new MoneyBox(sc.nextInt(),sc.nextInt(),sc.nextInt());
        System.out.println("  "+ mb.num_10+"  "+mb.num_5+" "+mb.num_20);
        System.out.println("Please input the number costomer ");
        int num_costomer=sc.nextInt();
        List<BuyAndSell> costomers=new ArrayList<BuyAndSell>();
        for(int i=0;i<num_costomer;i++){
            System.out.println("Please input information of costomer"+i+" (name 5 10 20) ");
            costomers.add(new BuyAndSell(mb,(String)sc.next(),sc.nextInt(),sc.nextInt(),sc.nextInt()));
        }
        for(int i=0;i<num_costomer;i++){
            costomers.get(i).run();
        }
    }
}