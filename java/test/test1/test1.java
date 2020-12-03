import java.awt.*;
import java.awt.event.*;

//import jdk.internal.org.objectweb.asm.tree.analysis.Frame;

class MyWindowListener extends WindowAdapter{
    public void windowClosing(WindowEvent e){
        e.getWindow().setVisible(false);
        ((Window)e.getComponent()).dispose();
        System.exit(0);
    }
}

public class test1{
    public static void main(String args[]){
        Frame f=new Frame("fuck");
        f.add(new Button("fuck"));
        f.setSize(300,300);
        f.setVisible(true);
        f.addWindowListener(new MyWindowListener());
    }
}