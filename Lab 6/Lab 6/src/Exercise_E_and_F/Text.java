package Exercise_E_and_F;

import java.awt.Color;
import java.awt.Graphics;

/**
 * This class represents a simple text component that can be drawn on the screen.
 * 
 * @author Jeremy Sugimoto
 * 
 */
public class Text implements Component {

    private int x;      // X-coordinate of the text
    private int y;      // Y-coordinate of the text
    private String text; // The text to be displayed

    /**
     * Constructs a Text component with the specified text content, X-coordinate, and Y-coordinate.
     *
     * @param text The text content to be displayed.
     * @param x    The X-coordinate of the text.
     * @param y    The Y-coordinate of the text.
     */
    public Text(String text, int x, int y) {
        this.x = x;      // Initialize the X-coordinate
        this.y = y;      // Initialize the Y-coordinate
        this.text = text; // Initialize the text content
    }

    /**
     * Draws the text on the screen at the specified coordinates with black color.
     *
     * @param g The Graphics object used for drawing.
     */
    @Override
    public void draw(Graphics g) {
        g.setColor(Color.black); // Set the text color to black
        g.drawString(text, x, y); // Draw the text at the specified coordinates
    }
}
