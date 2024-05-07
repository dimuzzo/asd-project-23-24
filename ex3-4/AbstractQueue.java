import java.util.Comparator;

public interface AbstractQueue<E> {
  public boolean empty(); // controlla se la coda è vuota -- O(1)
  public boolean push(E e); // aggiunge un elemento alla coda -- O(logN)
  public boolean contains(E e); // controlla se un elemento è in coda -- O(1)
  public E top(); // accede all'elemento in cima alla coda -- O(1)
  public void pop(); // rimuove l'elemento in cima alla coda -- O(logN)
  public boolean remove(E e); // rimuove un elemento se presente in coda -- O(logN)
};

public class PriorityQueue<E> implements AbstractQueue<E>{
    public List<E> heap;
    public Comparator<E> comparator;
    public Map<E, Integer> indexMap;

    public PriorityQueue(Comparator<E> comparator){
        this.heap = new ArrayList<>();
        this.comparator = comparator;
        this.indexMap = new HashMap<>();
    }

    public boolean empty(){
      return heap.isEmpty();
    }

    public boolean push(E e){
      heap.add(e);
      indexMap.put(e, heap.size() - 1);
      heapifyUp(heap.size() - 1);
      return true;
    }

    public boolean contains(E e){
      return indexMap.containsKey(e);
    }

    public E top(){
      if (empty()){ 
        throw new NoSuchElementException("Queue is empty");
      }
        return heap.get(0);
    }

    public void pop(){
      if (empty()){ 
        throw new NoSuchElementException("Queue is empty");
      }
      swap(0, heap.size() - 1);
      indexMap.remove(heap.get(heap.size() - 1));
      heap.remove(heap.size() - 1);
      heapifyDown(0);
    }

    public boolean remove(E e){
      Integer index = indexMap.get(e);
      if (index == null){ 
        return false;
      }
      swap(index, heap.size() - 1);
      indexMap.remove(e);
      heap.remove(heap.size() - 1);
      heapifyDown(index);
      return true;
    }

    public void heapifyUp(int index) {
      while (index > 0) {
          int parent = (index - 1) / 2;
          if (compare(heap.get(index), heap.get(parent)) >= 0) break;
          swap(index, parent);
          index = parent;
      }
    }

    public void heapifyDown(int index) {
      int smallest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;

      if (left < heap.size() && compare(heap.get(left), heap.get(smallest)) < 0)
          smallest = left;

      if (right < heap.size() && compare(heap.get(right), heap.get(smallest)) < 0)
          smallest = right;
          if (smallest != index) {
            swap(index, smallest);
            heapifyDown(smallest);
        }
    }

    public void swap(int i, int j) {
        E temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
        indexMap.put(heap.get(i), i);
        indexMap.put(heap.get(j), j);
    }

    public int compare(E a, E b) {
      if (comparator != null) {
          return comparator.compare(a, b);
      } else {
          Comparable<? super E> comparableA = (Comparable<? super E>) a;
          return comparableA.compareTo(b);
      }
    } 
}


