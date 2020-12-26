class MyThread extends Thread{
    public void run(){
        int i=0;
        while(true)
            synchronized(this){
                if(i<3){
                    System.out.println("MyThread: "+i);
                    i++;
                }
                else
                    break;
            }
    }
}
class test1{
    public static void main(String args[]){
        System.out.println("Main Thread is beginning.");
        MyThread tt = new MyThread();
        tt.start();
        try{ tt.join(); }
        catch(Exception e) { }
        System.out.println("Main Thread is ending.");
    }
}