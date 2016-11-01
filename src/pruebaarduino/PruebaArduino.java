/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pruebaarduino;
import com.github.sarxos.webcam.Webcam;
import com.github.sarxos.webcam.WebcamPanel;
import java.awt.Dimension;
import javax.swing.*;


/**
 *
 * @author Manolo
 */
public class PruebaArduino {
    
    public static void main(String[] args) {
        // TODO code application logic here
        /*JPanel panel = new WebcamPanel(Webcam.getDefault());
        JFrame window = new JFrame("Webcam capture");
        Dimension d = new Dimension(400,300);
        window.setPreferredSize(d);
        window.add(panel);
        window.pack();
        window.setVisible(true);*/
        
        FramePrincipal aplicacion = new FramePrincipal("Robot");
        Dimension x = new Dimension(300,150);
        aplicacion.setPreferredSize(x);
        aplicacion.setLocation(400, 0);
        aplicacion.setFocusable(true);
        aplicacion.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        aplicacion.setVisible (true);
        

        
    }
}
