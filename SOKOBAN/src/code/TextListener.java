package gui;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TextListener extends JFrame {

	//créer un JTextField
	JTextField textField = new JTextField("Appuyez sur Entrée");
	JTextField errorMsg = new JTextField("Code incorrect");
	String text = "";

	//Lancement de l'application
	public static void main(String[] args) {
		new TextListener().setVisible(true);
	}

	//Créer la boîte
	public TextListener() {
		//ajouter le listener sur le JTextField
	    textField.addActionListener(new ActionListener() {
	      //capturer un événement sur le JTextField
	      public void actionPerformed(ActionEvent e) {
	    	  text = textField.getText();
	      }
	    });
	    
	    //ajouter le JTextField au frame
	    getContentPane().add(textField);
	    
	    textField.addKeyListener (new KeyAdapter() {
	         public void keyPressed(KeyEvent e) {
	           int key = e.getKeyCode();
	           if (key == KeyEvent.VK_ENTER) {
	              Toolkit.getDefaultToolkit().beep();
	              if (errorMsg.getText() == "") {
	            	  dispose();
	              }
	              else {
	            	  getContentPane().add(errorMsg);
	              }
	              }
	           }
	         }
	      );
	    
	    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    setLocationRelativeTo(null);
	    setSize(300,100);
	}

}
