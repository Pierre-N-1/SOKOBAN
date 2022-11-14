package gui;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JToolBar;

public class FenetrePrincipale extends JFrame {

	private JPanel contentPane;
	private JTextField txtNumniveau;
	private JMenuBar menuBar;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					FenetrePrincipale frame = new FenetrePrincipale();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public FenetrePrincipale() {
		setTitle("Menu principal");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		java.awt.Dimension screenSize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
		setBounds((screenSize.width-640)/2, (screenSize.height-480)/2, 640, 480);
		
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		JMenu mnNiveaux = new JMenu("Niveaux");
		menuBar.add(mnNiveaux);
		
		JMenuItem mntmModifierNiveau = new JMenuItem("Modifier niveau");
		mntmModifierNiveau.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// Création de la boite en mémoire
				DialogModifierNiveau maBoite = new DialogModifierNiveau();
				
				// Affichage de la boite
				 maBoite.setVisible(true);
			}
		});
		mnNiveaux.add(mntmModifierNiveau);
		
		JMenu mnParametres = new JMenu("Paramètres");
		menuBar.add(mnParametres);
		
		JMenu mnAide = new JMenu("Aide");
		menuBar.add(mnAide);
		
		JMenuItem mntmAProposDe = new JMenuItem("A propos de");
		mntmAProposDe.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// Création de la boite en mémoire
				DialogAProposDe maBoite = new DialogAProposDe();
				
				// Affichage de la boite
				 maBoite.setVisible(true);
			}
		});
		mnAide.add(mntmAProposDe);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		txtNumniveau = new JTextField();
		txtNumniveau.setBounds(113, 46, 401, 21);
		contentPane.add(txtNumniveau);
		txtNumniveau.setColumns(10);
		
		JButton btnValider = new JButton("Valider");
		btnValider.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnValider.setBounds(113, 102, 103, 27);
		contentPane.add(btnValider);
		
		JToolBar toolBar = new JToolBar();
		toolBar.setBounds(12, -3, 111, 21);
		contentPane.add(toolBar);
		
		JButton btnNewButton = new JButton("New button");
		toolBar.add(btnNewButton);
	}
}
