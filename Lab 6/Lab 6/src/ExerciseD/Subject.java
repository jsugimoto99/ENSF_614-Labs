package ExerciseD;
/**
 * The `Subject` interface defines a contract for objects that can be observed by one or more observers.
 *
 * @author Jeremy Sugimoto
 */
public interface Subject {

    /**
     * Registers an observer with the subject.
     *
     * @param obj The observer to be registered.
     */
    public void register(Observer obj);

    /**
     * Removes an observer from the subject's list of registered observers.
     *
     * @param obj The observer to be removed.
     */
    public void remove(Observer obj);

    /**
     * Notifies all registered observers of a change in the subject.
     */
    public void notifyAllObservers();

    /**
     * Notifies a specific observer of a change in the subject.
     *
     * @param obj The observer to be notified.
     */
    public void notifyObserver(Observer obj);
}
