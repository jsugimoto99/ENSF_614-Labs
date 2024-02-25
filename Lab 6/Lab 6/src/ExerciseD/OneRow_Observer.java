package ExerciseD;

import java.util.ArrayList;

/**
 * The `OneRow_Observer` class is an observer that displays data from a `DoubleArrayListSubject` in a single row.
 * 
 * @author Jeremy Sugimoto
 * 
 */
public class OneRow_Observer implements Observer {

    private DoubleArrayListSubject subject; // The subject to observe

    /**
     * Constructs a `OneRow_Observer` with the specified subject and registers itself with the subject.
     *
     * @param mydata The `DoubleArrayListSubject` subject to observe.
     */
    public OneRow_Observer(DoubleArrayListSubject mydata) {
        this.subject = mydata;
        this.subject.register(this);
    }

    /**
     * Displays the updated data in a single row.
     *
     * @param data The data to be displayed.
     */
    private void display(ArrayList<Double> data) {
        System.out.println("Notification to One Row Observer: Data Changed:");
        for (int i = 0; i < data.size(); i++) {
            System.out.printf(data.get(i) + " ");
        }
        System.out.println();
    }

    /**
     * Called when the subject's data is updated, and it displays the updated data in a single row.
     *
     * @param data The updated data received from the subject.
     */
    @Override
    public void update(ArrayList<Double> data) {
        display(data);
    }
}
