import java.util.*;
import java.io.*;
import java.util.Comparator;
import java.util.ArrayList;

public class PriorityQueue<E> implements AbstractQueue<E>{
    private List<E> heap;
    private Comparator<E> comparator;
    private HashMap<E, Integer> indexMap;

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
      int current_index = heap.size() - 1;
      indexMap.put(e, current_index);
      heapifyUp(current_index);
      return true;
    }

    public boolean contains(E e){
      return indexMap.containsKey(e);
    }

    public E top(){
      if (empty()){ 
        throw new NoSuchElementException("Top: priority queue is empty.");
      }
        return heap.get(0);
    }

    public void pop(){
      if (empty()){ 
        throw new NoSuchElementException("Pop: priority queue is empty.");
      }
      int last_index = heap.size() - 1;
      swapAndMap(0, last_index);
      indexMap.remove(heap.get(last_index));
      heap.remove(last_index);
      if(!empty()){
        heapifyDown(0);
      }
    }

    public boolean remove(E e){
      if(!contains(e)){
        return false;
      }
      int index_to_remove = indexMap.get(e);
      int last_index = heap.size() - 1;
      if(index_to_remove != last_index){
        swapAndMap(index_to_remove, last_index);
      }
      indexMap.remove(e);
      heap.remove(last_index);
      if(!empty() && (index_to_remove < heap.size())){
        heapifyUp(index_to_remove);
        heapifyDown(index_to_remove);
      }
      return true;
    }

    public void heapifyUp(int current_index) {
      while (current_index > 0) {
          int parent_index = (current_index - 1) / 2;
          if (compare(heap.get(current_index), heap.get(parent_index)) < 0){
            swapAndMap(current_index, parent_index);
            current_index = parent_index;
          }
          else break;
      }
    }

    public void heapifyDown(int current_index) {
      int smallest_index = current_index;
      int leftchild_index = 2 * current_index + 1;
      int rightchild_index = 2 * current_index + 2;
    
      if (leftchild_index < heap.size() && compare(heap.get(leftchild_index), heap.get(smallest_index)) < 0){
          smallest_index = leftchild_index;
      }
      if (rightchild_index < heap.size() && compare(heap.get(rightchild_index), heap.get(smallest_index)) < 0){
          smallest_index = rightchild_index;
      }
      if (smallest_index != current_index) {
          swapAndMap(current_index, smallest_index);
          heapifyDown(smallest_index);
      }
    }

    public void swapAndMap(int index_i, int index_j) {
        E temp_index = heap.get(index_i);
        heap.set(index_i, heap.get(index_j));
        heap.set(index_j, temp_index);
        indexMap.put(heap.get(index_i), index_i);
        indexMap.put(heap.get(index_j), index_j);
    }

    public int compare(E a, E b) {
        return comparator.compare(a, b);
    } 

    @Override
    public String toString(){
      StringBuilder heapString = new StringBuilder();
      for(E e : heap){
        heapString.append(e).append(" ");
      }
      return heapString.toString();
    }
}