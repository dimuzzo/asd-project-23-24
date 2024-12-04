import java.util.HashMap;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class PriorityQueue<E> implements AbstractQueue<E> {

    private ArrayList<E> heap; // Heap data structure to store elements
    private Comparator<E> comparator;
    private HashMap<E, Integer> indexMap;

    public PriorityQueue(Comparator<E> comparator) {
        this.heap = new ArrayList<>();  
        this.comparator = comparator;   
        this.indexMap = new HashMap<>(); 
    }

    @Override
    public boolean empty() {
        return heap.isEmpty();
    }

    @Override
    public boolean push(E e) {
        if (contains(e)) return false;  // If the element already in the queue, don't add it
        
        heap.add(e);  
        int currentIndex = heap.size() - 1; 
        indexMap.put(e, currentIndex);  
        heapifyUp(currentIndex);  // Restore the heap property by moving the element up
        return true;
    }

    @Override
    public boolean contains(E e) {
        return indexMap.containsKey(e);  // Use the indexMap for fast look-up
    }

    @Override
    public E top() {
        if (empty()) throw new NoSuchElementException("Top error: priority queue is empty.");
        return heap.get(0); 
    }

    @Override
    public void pop() {
        if (empty()) throw new NoSuchElementException("Pop error: priority queue is empty.");
        
        // Swap the root element (top) with the last element in the heap
        int lastIndex = heap.size() - 1;
        swapAndMap(0, lastIndex);
        
        // Remove the last element (which is now the root) and update the index map
        indexMap.remove(heap.get(lastIndex));
        heap.remove(lastIndex);
        
        // If the heap isn't empty, restore the heap property by heapifying down from the root
        if (!empty()) {
            heapifyDown(0);
        }
    }

    @Override
    public boolean remove(E e) {
        if (!contains(e)) return false;  
        
        int indexToRemove = indexMap.get(e);
        int lastIndex = heap.size() - 1;  
        
        // If the element to remove is not the last element, swap it with the last element
        if (indexToRemove != lastIndex) {
            swapAndMap(indexToRemove, lastIndex);
        }
        
        // Remove the element and update the index map
        indexMap.remove(e);
        heap.remove(lastIndex);
        
        // Restore the heap property: if the removed element wasn't the last, reheapify
        if (!empty() && (indexToRemove < heap.size())) {
            heapifyUp(indexToRemove);    // Try to restore the heap property upwards
            heapifyDown(indexToRemove);  // Try to restore the heap property downwards
        }
        
        return true;
    }

    // Helper method to restore the heap property by moving the element at index upwards
    private void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            
            // If the element at index is smaller than its parent, swap them
            if (compareIndex(index, parentIndex) < 0) {
                swapAndMap(index, parentIndex);
                index = parentIndex;  
            } else break; 
        }
    }

    // Helper method to restore the heap property by moving the element at index downwards
    private void heapifyDown(int index) {
        int smallestIndex = index;
        int leftChildIndex = 2 * index + 1;  
        int rightChildIndex = 2 * index + 2;  
        
        // Compare the left child with the current element and swap if necessary
        if (leftChildIndex < heap.size() && compareIndex(leftChildIndex, smallestIndex) < 0) {
            smallestIndex = leftChildIndex;
        }
        
        // Compare the right child with the current element and swap if necessary
        if (rightChildIndex < heap.size() && compareIndex(rightChildIndex, smallestIndex) < 0) {
            smallestIndex = rightChildIndex;
        }
        
        // If the smallest element is not the current element, swap and recursively heapify down
        if (smallestIndex != index) {
            swapAndMap(index, smallestIndex);
            heapifyDown(smallestIndex);
        }
    }

    // Helper method to swap elements at two indices and update their positions in the index map
    private void swapAndMap(int index1, int index2) {
        E temp = heap.get(index1);  
        heap.set(index1, heap.get(index2));  
        heap.set(index2, temp);
        
        // Update the index map with the new positions of the swapped elements
        indexMap.put(heap.get(index1), index1);
        indexMap.put(heap.get(index2), index2);
    }

    // Helper method to compare two elements at the specified indices using the comparator
    private int compareIndex(int index1, int index2) {
        return comparator.compare(heap.get(index1), heap.get(index2));  
    }
}