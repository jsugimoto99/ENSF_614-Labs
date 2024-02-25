package Exercise_E_and_F;

import java.awt.AlphaComposite;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

/**
 * This class represents a decorator that adds a semi-transparent colored "glass" overlay to a wrapped component.
 * 
 * @author Jeremy Sugimoto
 * 
 */
public class ColouredGlassDecorator extends Decorator {
    private Component component; // The component to be decorated
    private int x;              // X-coordinate of the glass overlay
    private int y;              // Y-coordinate of the glass overlay
    private int width;          // Width of the glass overlay
    private int height;         // Height of the glass overlay

    /**
     * Constructs a ColouredGlassDecorator with the specified component, position, and size of the glass overlay.
     *
     * @param component The component to be decorated.
     * @param x         The X-coordinate of the glass overlay.
     * @param y         The Y-coordinate of the glass overlay.
     * @param width     The width of the glass overlay.
     * @param height    The height of the glass overlay.
     */
    public ColouredGlassDecorator(Component component, int x, int y, int width, int height) {
        super(component);    // Call the constructor of the superclass (Decorator)
        this.component = component;   // Initialize the wrapped component
        this.x = x;          // Initialize X-coordinate
        this.y = y;          // Initialize Y-coordinate
        this.width = width;  // Initialize overlay width
        this.height = height; // Initialize overlay height
    }

    /**
     * Draws the semi-transparent colored "glass" overlay around the wrapped component and delegates the drawing to the wrapped component.
     *
     * @param g The Graphics object used for drawing.
     */
    @Override
    public void draw(Graphics g) {
        // Delegate the drawing to the wrapped component (draw the underlying component)
        component.draw(g);
        
        Graphics2D g2d = (Graphics2D) g;   // Cast Graphics to Graphics2D for advanced drawing
        Color ogColor = g2d.getColor();   // Store the original color
        
        g2d.setColor(Color.green);  // Set the color of the glass overlay to green
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1 * 0.1f)); // Set transparency
        
        // Draw the semi-transparent colored overlay rectangle
        g2d.fillRect(x, y, width, height);
        
        // Reset the color to the original color
        g2d.setColor(ogColor);
    }
}
