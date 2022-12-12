package gui;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class DialogModifierNiveau extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private final JLabel lblMotDePasse = new JLabel("Mot de passe");
	private JTextField txtMotDePasse;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		try {
			DialogModifierNiveau dialog = new DialogModifierNiveau();
			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
			dialog.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Create the dialog.
	 */
	public DialogModifierNiveau() {
		setTitle("Modifier niveau");
		setBounds(100, 100, 450, 300);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		lblMotDePasse.setBounds(12, 33, 84, 17);
		contentPanel.add(lblMotDePasse);
		{
			txtMotDePasse = new JTextField();
			txtMotDePasse.setBounds(114, 31, 161, 21);
			contentPanel.add(txtMotDePasse);
			txtMotDePasse.setColumns(10);
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("OK");
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Annuler");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
					}
				});
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
			}
		}
	}
	
	

}
