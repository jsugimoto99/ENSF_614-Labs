package ExerciseD;

import java.util.ArrayList;

/**
 * The `ThreeColumnTable_Observer` class is an observer that displays data from a `DoubleArrayListSubject` in a tabular format
 * with three columns and a dynamically determined number of rows.
 * 
 * @author Jeremy Sugimoto
 * 
 */
public class ThreeColumnTable_Observer implements Observer {

    private DoubleArrayListSubject subject; // The subject to observe

    /**
     * Constructs a `ThreeColumnTable_Observer` with the specified subject and registers itself with the subject.
     *
     * @param mydata The `DoubleArrayListSubject` subject to observe.
     */
    public ThreeColumnTable_Observer(DoubleArrayListSubject mydata) {
        this.subject = mydata;
        this.subject.register(this);
    }

    /**
     * Displays the updated data in a tabular format with three columns and a dynamically determined number of rows.
     *
     * @param data The data to be displayed.
     */
    private void display(ArrayList<Double> data) {
        System.out.println("Notification to Three-Column Table Observer: Data Changed:");
        int numCol = 3;
        int numRows = (int) Math.ceil(data.size() / (double) numCol);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCol; j++) {
                int index = i * numCol + j;
                if (index < data.size()) {
                    System.out.print(data.get(index) + " ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Called when the subject's data is updated, and it displays the updated data in the tabular format.
     *
     * @param data The updated data received from the subject.
     */
    @Override
    public void update(ArrayList<Double> data) {
        display(data);
    }
}
