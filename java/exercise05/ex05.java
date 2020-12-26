import java.util.*;


import java.awt.*;

import java.awt.event.*;
 class myWindowListener extends WindowAdapter{
    public void windowClosing(WindowEvent e){
        Window w=e.getWindow();
        w.setVisible(false);
        w.dispose();
        System.exit(0);
    }
}

class myButtonListener1 implements ActionListener{
    Label l;
    TextField f1,f2;
    public myButtonListener1(Label l,TextField f1,TextField f2){
        this.l=l;
        this.f1=f1;
        this.f2=f2;
}
    public void actionPerformed(ActionEvent e){
        int ans=Integer.parseInt(f1.getText())*Integer.parseInt(f2.getText());
        String s="两个数的乘积是"+ans;
        l.setText(s);
    }
}

class myButtonListener2 implements ActionListener{
    public void actionPerformed(ActionEvent e){
        f.setVisible(false);
        f.dispose();
        System.exit(0);  
    }
}


class Test {
    
    void init(){
    Frame f=new Frame();
    
    Label l=new Label("请先输入两个数");
    TextField t1=new TextField();
    TextField t2=new TextField();
    Button b=new Button("确定");
    Button exit=new Button("退出");


    l.setBounds(140,50,200,50);
    t1.setBounds(60, 100, 100, 40);
    t2.setBounds(210,100,100,40);
    b.setBounds(140,200,80,40);
    b.setBackground(Color.GREEN);
    exit.setBounds(140,260,80,40);
    exit.setBackground(Color.GREEN);

    f.add(t1);
    f.add(t2);
    f.add(l);
    f.add(b);
    f.add(exit);

    f.setSize(400,400);
    f.addWindowListener(new myWindowListener());
    b.addActionListener(new myButtonListener1(l,t1,t2));
    exit.addActionListener(new myButtonListener2());
    f.setLayout(null);
    f.setVisible(true);
}
}
public class ex05{
    public static void main(String[] args){
        (new Test()).init();
    }
}