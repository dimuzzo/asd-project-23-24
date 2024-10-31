import java.util.HashMap;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class PriorityQueue<E> implements AbstractQueue<E>{
    private ArrayList<E> heap;
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
      int currentIndex = heap.size() - 1;
      indexMap.put(e, currentIndex);
      heapifyUp(currentIndex);
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
      int lastIndex = heap.size() - 1;
      swapAndMap(0, lastIndex);
      indexMap.remove(heap.get(lastIndex));
      heap.remove(lastIndex);
      if(!empty()){
        heapifyDown(0);
      }
    }

    public boolean remove(E e){
      if(!contains(e)){
        return false;
      }
      int indexToRemove = indexMap.get(e);
      int lastIndex = heap.size() - 1;
      if(indexToRemove != lastIndex){
        swapAndMap(indexToRemove, lastIndex);
      }
      indexMap.remove(e);
      heap.remove(lastIndex);
      if(!empty() && (indexToRemove < heap.size())){
        heapifyUp(indexToRemove);
        heapifyDown(indexToRemove);
      }
      return true;
    }

    private void heapifyUp(int index) {
      while (index > 0) {
          int parentIndex = (index - 1) / 2;
          if (compareIndex(index, parentIndex) < 0){
            swapAndMap(index, parentIndex);
            index = parentIndex;
          }
          else break;
      }
    }

    private void heapifyDown(int index) {
      int smallestIndex = index;
      int leftChildIndex = 2 * index + 1;
      int rightChildIndex = 2 * index + 2;
    
      if (leftChildIndex < heap.size() && compareIndex(leftChildIndex, smallestIndex) < 0){
          smallestIndex = leftChildIndex;
      }
      if (rightChildIndex < heap.size() && compareIndex(rightChildIndex, smallestIndex) < 0){
          smallestIndex = rightChildIndex;
      }
      if (smallestIndex != index) {
          swapAndMap(index, smallestIndex);
          heapifyDown(smallestIndex);
      }
    }

    private void swapAndMap(int index1, int index2) {
        E tempIndex = heap.get(index1);
        heap.set(index1, heap.get(index2));
        heap.set(index2, tempIndex);
        indexMap.put(heap.get(index1), index1);
        indexMap.put(heap.get(index2), index2);
    }

    private int compareIndex(int index1, int index2) {
        return comparator.compare(heap.get(index1), heap.get(index2));
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