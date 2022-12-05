package gui;

import java.awt.event.*;
import javax.swing.*;

public class TextListener extends JFrame {

	//créer un JTextField
	JTextField textField = new JTextField("Appuyez sur Entrée");

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		new TextListener().setVisible(true);
	}

	/**
	 * Create the frame.
	 */
	public TextListener() {
		//ajouter le listener sur le JTextField
	    textField.addActionListener(new ActionListener() {
	      //capturer un événement sur le JTextField
	      public void actionPerformed(ActionEvent e) {
	    	  String text = textField.getText();
	      }
	    });
	    //ajouter le JTextField au frame
	    getContentPane().add(textField);
	    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    setLocationRelativeTo(null);
	    setSize(300,100);
	}

}
