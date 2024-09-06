import java.util.Comparator;
import java.io.*;
import java.util.*;

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
      if(contains(e)){
        return false;
      }
      heap.add(e);
      int index = heap.size() - 1;
      indexMap.put(e, index);
      heapifyUp(index);
      return true;
    }

    public boolean contains(E e){
      return indexMap.containsKey(e);
    }

    public E top(){
      if (empty()){ 
        return null;
      }
        return heap.get(0);
    }

    public void pop(){
      if (empty()){ 
        return;
      }
      int last_index = heap.size() - 1;
      swap(0, last_index);
      indexMap.remove(heap.get(last_index));
      heap.remove(last_index);
      if(!empty()){
        heapifyDown(0);
      }
    }

    public boolean remove(E e){
      Integer index = indexMap.get(e);
      if (index == null){ 
        return false;
      }
      int last_index = heap.size() - 1;
      swap(index, last_index);
      indexMap.remove(e);
      heap.remove(last_index);
      if(!empty() && (index < heap.size())){
        heapifyUp(index);
        heapifyDown(index);
      }
      return true;
    }

    public void heapifyUp(int index) {
      while (index > 0) {
          int parent = (index - 1) / 2;
          if (compare(heap.get(index), heap.get(parent)) < 0){
            swap(index, parent);
            index = parent;
          }
          else{
            break;
          }
      }
    }

    public void heapifyDown(int index) {
      int smallest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;

      if (left < heap.size() && compare(heap.get(left), heap.get(smallest)) < 0){
          smallest = left;
      }
      if (right < heap.size() && compare(heap.get(right), heap.get(smallest)) < 0){
          smallest = right;
      }
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
        return comparator.compare(a, b);
    } 
}