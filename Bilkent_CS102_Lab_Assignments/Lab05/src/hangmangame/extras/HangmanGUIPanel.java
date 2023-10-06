package hangmangame.extras;

import cs102.hangman.HangmanModel;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JPanel;

/**
 * Collection of UI components to form a complete Hangman game. 
 * View components implement IHangmanView, so they can automatically update
 * whenever the hangmanModel associated with changes, changes.
 * Other components are hangman controllers that update the model.
 * @author david, ata.seren
 */
public class HangmanGUIPanel extends JPanel 
{
   //properties
   HangmanModel hm;
   TextFieldControlPanel textPanelControl;
   NewGameButtonControl newGameControl;
   LabelsHangmanView labelsHangman;
   GallowsHangmanView gallowsHangman;
   HangmanLetterButtonControls keyboard;
   LetterButtonListener listener;
   
   //constructors
   public HangmanGUIPanel( HangmanModel hm) 
   {
      setPreferredSize( new Dimension( 1000, 500) );
      setLayout( new BorderLayout() );
      setBackground(Color.YELLOW);
      
      this.hm = hm;
      textPanelControl = new TextFieldControlPanel(hm);
      newGameControl = new NewGameButtonControl(hm);
      labelsHangman = new LabelsHangmanView();
      gallowsHangman = new GallowsHangmanView(hm);
      this.keyboard = new HangmanLetterButtonControls( hm);
      this.listener = new LetterButtonListener( hm);

      add(textPanelControl, BorderLayout.NORTH);
      hm.addView(newGameControl);
      add(newGameControl, BorderLayout.SOUTH);
      hm.addView(labelsHangman);
      add(labelsHangman, BorderLayout.WEST);
      hm.addView(gallowsHangman);
      add( gallowsHangman, BorderLayout.CENTER);     
      hm.addView( keyboard);
      keyboard.addActionListener( listener);
      add( keyboard, BorderLayout.EAST);     
   }   
}
