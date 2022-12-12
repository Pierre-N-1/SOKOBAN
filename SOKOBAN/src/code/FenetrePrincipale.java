package gui;

/*
 * 
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
ArthurGuillot
 * 
 */
import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.GridBagLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JToolBar;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridBagConstraints;

public class FenetrePrincipale extends JFrame {

	private JPanel contentPane;
	private JTextField txtNumniveau;
	private JMenuBar menuBar;
	private Partie P;


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
		//TITRE ET DIMENSONS DE LA FENETRE
		setTitle("Menu principal");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		java.awt.Dimension screenSize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
		setBounds((screenSize.width-640)/2, (screenSize.height-480)/2, 640, 480);
		
		//BARRE DE MENU
		menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		//MENU NIVEAUX - MENU PARAMETRES - MENU AIDE
		JMenu mnNiveaux = new JMenu("Niveaux");
		menuBar.add(mnNiveaux);
		JMenu mnParametres = new JMenu("Paramètres");
		menuBar.add(mnParametres);
		JMenu mnAide = new JMenu("Aide");
		menuBar.add(mnAide);
		
		P = new Partie();
		P.lancerNiveau(1);
		//System.out.print(System.getProperty("user.dir"));
		
		//ITEM MODIFIER NIVEAU - ACCES BOITE DE DIALOGUE MODIFIER NIVEAU
		JMenuItem mntmModifierNiveau = new JMenuItem("Changer de niveau");
		mntmModifierNiveau.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				TextListener maBoite = new TextListener(); // Création de la boite en mémoire
				maBoite.setVisible(true); // Affichage de la boite
				
				int niv = P.config.trouve_niveau(maBoite.text);
				if (niv != -1) {
					maBoite.errorMsg.setText("");
					P.lancerNiveau(niv);
				}
				else {
					
				}
				
			}
		});
		mnNiveaux.add(mntmModifierNiveau);
		
		
		//ITEM A PROPOS DE - ACCES BOITE DE DIALOGUE A PROPOS DE
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
		
		//CONTENEUR PRINCIPAL DE LA FENETRE
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new GridBagLayout());
		
		//IMAGE DE FOND
		JLabel label = new JLabel();
		label.setIcon(new ImageIcon(":/images/background.jpg"));
		add(label);
		
		//CHAMP TEXTUEL
		txtNumniveau = new JTextField();
		txtNumniveau.setBounds(113, 46, 401, 21);
		contentPane.add(txtNumniveau);
		txtNumniveau.setColumns(10);
		
		//BOUTON VALIDER
		JButton btnValider = new JButton("Valider");
		btnValider.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			}
		});
		btnValider.setBounds(113, 102, 103, 27);
		contentPane.add(btnValider);
		
		//BARRE D'OUTILS
		JToolBar toolBar = new JToolBar();
		toolBar.setBounds(12, -3, 111, 21);
		contentPane.add(toolBar);
		
		//BOUTON PRECEDENT
		JButton btnPrecedent = new JButton("Précédent");
		toolBar.add(btnPrecedent);
	}
}
