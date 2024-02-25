package Exercise_E_and_F;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Stroke;

/**
 * 
 * This class represents a decorator that adds a colored frame around a wrapped component.
 * 
 * @author Jeremy Sugimoto
 * 
 */
public class ColouredFrameDecorator extends Decorator {

    private Component component;  // The component to be decorated
    private int x;               // X-coordinate of the frame
    private int y;               // Y-coordinate of the frame
    private int width;           // Width of the frame
    private int height;          // Height of the frame
    private int thickness;       // Thickness of the frame

    /**
     * Constructs a ColouredFrameDecorator with the specified component, position, size, and frame thickness.
     *
     * @param component  The component to be decorated.
     * @param x          The X-coordinate of the frame.
     * @param y          The Y-coordinate of the frame.
     * @param width      The width of the frame.
     * @param height     The height of the frame.
     * @param thickness  The thickness of the frame.
     */
    public ColouredFrameDecorator(Component component, int x, int y, int width, int height, int thickness) {
        super(component);    // Call the constructor of the superclass (Decorator)
        this.component = component;   // Initialize the wrapped component
        this.x = x;          // Initialize X-coordinate
        this.y = y;          // Initialize Y-coordinate
        this.width = width;  // Initialize frame width
        this.height = height; // Initialize frame height
        this.thickness = thickness; // Initialize frame thickness
    }

    /**
     * Draws the colored frame around the wrapped component and delegates the drawing to the wrapped component.
     *
     * @param g  The Graphics object used for drawing.
     */
    @Override
    public void draw(Graphics g) {
        // Draw the colored frame around the wrapped component
        Graphics2D g2d = (Graphics2D) g;  // Cast Graphics to Graphics2D for advanced drawing
        Color ogColor = g2d.getColor();  // Store the original color
        g2d.setColor(Color.red);         // Set the frame color to red
        Stroke oldStroke = g2d.getStroke(); // Store the original stroke (line thickness)
        g2d.setStroke(new BasicStroke(thickness));  // Set the stroke to the specified thickness
        g2d.drawRect(x, y, width, height);  // Draw a rectangle with the specified dimensions
        g2d.setStroke(oldStroke);  // Restore the original stroke
        g2d.setColor(ogColor);  // Reset the color to the original color

        // Delegate the drawing to the wrapped component
        component.draw(g);
    }
}
