package Exercise_E_and_F;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

/**
 * This class represents a decorator that adds a dashed border around a wrapped component.
 *
 * @author Jeremy Sugimoto
 */
public class BorderDecorator extends Decorator {

    private Component component; // The component to be decorated
    private int x;              // X-coordinate of the border
    private int y;              // Y-coordinate of the border
    private int width;          // Width of the border
    private int height;         // Height of the border

    /**
     * Constructs a BorderDecorator with the specified component, position, and size of the border.
     *
     * @param component  The component to be decorated.
     * @param x          The X-coordinate of the border.
     * @param y          The Y-coordinate of the border.
     * @param width      The width of the border.
     * @param height     The height of the border.
     */
    public BorderDecorator(Component component, int x, int y, int width, int height) {
        super(component);    // Call the constructor of the superclass (Decorator)
        this.component = component;   // Initialize the wrapped component
        this.x = x;          // Initialize X-coordinate
        this.y = y;          // Initialize Y-coordinate
        this.width = width;  // Initialize border width
        this.height = height; // Initialize border height
    }

    /**
     * Draws the dashed border around the wrapped component and delegates the drawing to the wrapped component.
     *
     * @param g  The Graphics object used for drawing.
     */
    @Override
    public void draw(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;   // Cast Graphics to Graphics2D for advanced drawing
        Color ogColor = g2d.getColor();   // Store the original color

        float[] dashPattern = {5.0f, 5.0f}; // Define a dash pattern for the border (adjust values as needed)
        BasicStroke dashedStroke = new BasicStroke(
            2.0f,                   // Line thickness
            BasicStroke.CAP_BUTT,   // Line cap style
            BasicStroke.JOIN_MITER, // Line join style
            5.0f,                   // Miter limit
            dashPattern,            // Dash pattern
            0.0f                   // Dash phase
        );

        g2d.setStroke(dashedStroke); // Set the dashed stroke
        g2d.setColor(Color.black);    // Set the border color to black

        // Draw the dashed rectangle
        g2d.drawRect(x, y, width, height);

        // Reset the stroke to avoid affecting other drawing operations
        g2d.setStroke(new BasicStroke(1.0f));

        // Reset the color to the original color
        g2d.setColor(ogColor);

        // Delegate the drawing to the wrapped component
        component.draw(g);
    }
}
