package ExerciseD;
import java.util.ArrayList;

/**
 * The `DoubleArrayListSubject` class represents a subject in the Observer Pattern. It maintains a list of `Double` data
 * and notifies its observers when changes occur.
 * 
 * @author Jeremy Sugimoto
 * 
 */
public class DoubleArrayListSubject implements Subject {

    private ArrayList<Double> data;     // The list of `Double` data
    private ArrayList<Observer> observers; // The list of observers

    /**
     * Default constructor that initializes the `data` and `observers` lists.
     */
    DoubleArrayListSubject() {
        data = new ArrayList<>();
        observers = new ArrayList<>();
    }

    /**
     * Displays the contents of the `data` list.
     */
    public void display() {
        if (data.isEmpty()) {
            System.out.print("Empty List...");
        } else {
            for (Double val : data) {
                System.out.print(val + " ");
            }
        }
        System.out.println();
    }

    /**
     * Populates the `data` list with values from an array of double and notifies the observers.
     *
     * @param arr An array of double values to populate the `data` list.
     */
    public void populate(double[] arr) {
        for (double value : arr) {
            data.add(value);
        }
        notifyAllObservers();
    }

    /**
     * Sets the value at a specific index in the `data` list and notifies the observers.
     *
     * @param d The new value to be set.
     * @param i The index at which the value should be set.
     */
    public void setData(double d, int i) {
        if (i >= 0 && i < data.size()) {
            data.set(i, d);
            notifyAllObservers();
        }
    }

    /**
     * Adds a new Double value to the `data` list and notifies the observers.
     *
     * @param d The Double value to be added.
     */
    public void addData(double d) {
        data.add(d);
        notifyAllObservers();
    }

    /**
     * Registers an observer with the subject and notifies the new observer.
     *
     * @param obj The observer to be registered.
     */
    @Override
    public void register(Observer obj) {
        observers.add(obj);
        notifyObserver(obj);
    }

    /**
     * Removes an observer from the list of registered observers.
     *
     * @param obj The observer to be removed.
     */
    @Override
    public void remove(Observer obj) {
        observers.remove(obj);
    }

    /**
     * Notifies all registered observers about changes in the `data` list.
     */
    @Override
    public void notifyAllObservers() {
        for (Observer observer : observers) {
            observer.update(data);
        }
    }

    /**
     * Notifies a specific observer about changes in the `data` list.
     *
     * @param obj The observer to be notified.
     */
    @Override
    public void notifyObserver(Observer obj) {
        obj.update(data);
    }
}
