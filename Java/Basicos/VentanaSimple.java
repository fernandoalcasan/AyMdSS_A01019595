import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class VentanaSimple extends JFrame
{   
    public VentanaSimple()
    {
        setBounds(50,50,500,500);
        JLabel l = new JLabel("Escribe tu nombre:");
        JLabel saludo = new JLabel("");
        JTextField nombre = new JTextField();
        JButton boton = new JButton("Saludo");
        
        nombre.setSize(100,100);
        nombre.setBounds(200, 200, 40, 40);
        setLayout(new FlowLayout());
        add(saludo);
        add(l);
        add(boton);
        add(nombre);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        
        boton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                String name = nombre.getText();
                saludo.setText("hola " + name);
            }
        });
        
        setVisible(true);
    }
    
    public static void main(String[] args) 
    {
        VentanaSimple v = new VentanaSimple();
        
    }
    
}
