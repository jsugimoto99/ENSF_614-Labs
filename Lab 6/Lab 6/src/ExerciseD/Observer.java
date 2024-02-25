package ExerciseD;

import java.util.ArrayList;

/**
 * The `Observer` interface defines a contract for objects that observe changes in a subject's data.
 *
 * @author Jeremy Sugimoto
 */
public interface Observer {

    /**
     * Method to update the observer with new data received from the subject.
     *
     * @param data The updated data received from the subject.
     */
    public void update(ArrayList<Double> data);
}
