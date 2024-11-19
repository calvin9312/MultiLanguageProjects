//package layout;

import javax.swing.SpringLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import java.awt.Container;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.*;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class regexp_validator_gui {
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */
    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("Regular Expression Validator");
        //frame.setTitle("Regular Expression Validator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Set up the content pane.
        Container contentPane = frame.getContentPane();
        SpringLayout layout = new SpringLayout();
        contentPane.setLayout(layout);

        //Create and add the components.
        JButton check_button = new JButton("Check");
        JButton clear_button = new JButton("Clear");
        JLabel label = new JLabel("Pattern : ");
        JTextField textField = new JTextField("", 45);
        JLabel label_text = new JLabel("Text : ");
        JTextField textField_text = new JTextField("", 45);
        contentPane.add(label);
        contentPane.add(textField);
        contentPane.add(label_text);
        contentPane.add(textField_text);
        contentPane.add(check_button);
        contentPane.add(clear_button);

	check_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //your actions
                Pattern pattern = Pattern.compile(textField.getText(), Pattern.CASE_INSENSITIVE);
                Matcher matcher = pattern.matcher(textField_text.getText());
                boolean matchFound = matcher.find();
                if(matchFound) {
		  textField_text.setBackground(Color.GREEN);
                } else {
		  textField_text.setBackground(Color.RED);
                }
            }
        });

	clear_button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //your actions
		  textField.setText("");
		  textField_text.setText("");
		  textField_text.setBackground(Color.WHITE);
            }
        });

        //Adjust constraints for the label so it's at (5,5).
        layout.putConstraint(SpringLayout.WEST, label,
                             5,
                             SpringLayout.WEST, contentPane);
        layout.putConstraint(SpringLayout.NORTH, label,
                             5,
                             SpringLayout.NORTH, contentPane);

        //Adjust constraints for the text field so it's at
        //(<label's right edge> + 5, 5).
        layout.putConstraint(SpringLayout.WEST, textField,
                             5,
                             SpringLayout.WEST, contentPane);
        layout.putConstraint(SpringLayout.NORTH, textField,
                             5,
                             SpringLayout.SOUTH, label);


        //Adjust constraints for the label so it's at (5,5).
        layout.putConstraint(SpringLayout.WEST, label_text,
                             5,
                             SpringLayout.WEST, contentPane);
        layout.putConstraint(SpringLayout.NORTH, label_text,
                             15,
                             SpringLayout.SOUTH, textField);

        //Adjust constraints for the text field so it's at
        //(<label's right edge> + 5, 5).
        layout.putConstraint(SpringLayout.WEST, textField_text,
                             5,
                             SpringLayout.WEST, contentPane);
        layout.putConstraint(SpringLayout.NORTH, textField_text,
                             5,
                             SpringLayout.SOUTH, label_text);

        //Adjust constraints for the text field so it's at
        //(<label's right edge> + 5, 5).
        layout.putConstraint(SpringLayout.WEST, check_button,
                             5,
                             SpringLayout.WEST, contentPane);
        layout.putConstraint(SpringLayout.NORTH, check_button,
                             15,
                             SpringLayout.SOUTH, textField_text);

        //Adjust constraints for the text field so it's at
        //(<label's right edge> + 5, 5).
        layout.putConstraint(SpringLayout.WEST, clear_button,
                             5,
                             SpringLayout.EAST, check_button);
        layout.putConstraint(SpringLayout.NORTH, clear_button,
                             15,
                             SpringLayout.SOUTH, textField_text);


        //Display the window.
	frame.setLocationRelativeTo(null);//center of screen
	frame.getContentPane().setPreferredSize(new Dimension(520, 150));
        frame.pack();
	frame.setMinimumSize( frame.getSize() );
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        //Schedule a job for the event-dispatching thread:
        //creating and showing this application's GUI.
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
}
}

