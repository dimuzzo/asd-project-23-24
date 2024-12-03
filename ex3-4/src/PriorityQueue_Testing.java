import java.util.Comparator;
import java.util.NoSuchElementException;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

public class PriorityQueue_Testing{

    class IntegerComparator implements Comparator<Integer>{
        @Override
        public int compare(Integer i1, Integer i2){
            return i1.compareTo(i2);
        }
    }

    class StringComparator implements Comparator<String>{
        @Override
        public int compare(String s1, String s2){
            return s1.compareTo(s2);
        }
    }

    private Integer i1, i2, i3;
    private String s1, s2, s3;
    private PriorityQueue<Integer> pq_Int;
    private PriorityQueue<String> pq_String;

    @Before
    public void createPriorityQueue(){
        i1 = 2;
        i2 = 7;
        i3 = -26;

        s1 = "Jan";
        s2 = "publicService";
        s3 = "stringOrNot";

        this.pq_Int = new PriorityQueue<Integer>(new IntegerComparator());
        this.pq_String = new PriorityQueue<String>(new StringComparator());
    }

    // Tests for Integer Priority Queue
    @Test
    public void testEmptyQueue_Int() {
        assertTrue(pq_Int.empty());  
    }

    @Test
    public void testPush_Int() {
        assertTrue(pq_Int.push(i1));  
        assertFalse(pq_Int.empty()); 
        assertEquals(i1, pq_Int.top()); 
    }

    @Test
    public void testPushDuplicate_Int() {
        assertTrue(pq_Int.push(i2));
        assertFalse(pq_Int.push(i2));  
    }

    @Test
    public void testTop_Int() {
        pq_Int.push(i1);
        pq_Int.push(i2);
        pq_Int.push(i3);
        assertEquals(i3, pq_Int.top());  
        assertTrue(pq_Int.top() == i3);
    }

    @Test
    (expected = NoSuchElementException.class)
    public void testTopOnEmptyQueue_Int() {
        pq_Int.top();  
    }

    @Test
    public void testPop_Int() {
        pq_Int.push(i1);
        pq_Int.push(i2);
        pq_Int.push(i3);
        pq_Int.pop();
        assertTrue(pq_Int.top() != i3); 
    }

    @Test
    (expected = NoSuchElementException.class)
    public void testPopOnEmptyQueue_Int() {
        pq_Int.pop();  
    }

    @Test
    public void testContains_Int() {
        pq_Int.push(i1);
        pq_Int.push(i2);
        assertTrue(pq_Int.contains(i1));
        assertFalse(pq_Int.contains(i3)); 
    }

    @Test
    public void testRemove_Int() {
        pq_Int.push(i1);
        pq_Int.push(i2);
        assertTrue(pq_Int.remove(i1));
        assertFalse(pq_Int.contains(i1));  
    }

    // Tests for String Priority Queue
    @Test
    public void testEmptyQueue_String() {
        assertTrue(pq_String.empty());  
    }

    @Test
    public void testPush_String() {
        assertTrue(pq_String.push(s1));  
        assertFalse(pq_String.empty());  
    }

    @Test
    public void testPushDuplicate_String() {
        assertTrue(pq_String.push(s1));
        assertFalse(pq_String.push(s1));  
    }

    @Test
    public void testTop_String() {
        pq_String.push(s1);
        pq_String.push(s2);
        pq_String.push(s3);
        assertEquals(s1, pq_String.top()); 
    }

    @Test
    (expected = NoSuchElementException.class)
    public void testTopOnEmptyQueue_String() {
        pq_String.top();  
    }

    @Test
    public void testPop_String() {
        pq_String.push(s1);
        pq_String.push(s2);
        pq_String.push(s3);
        pq_String.pop();
        assertTrue(pq_String.top() != s1);
    }

    @Test
    (expected = NoSuchElementException.class)
    public void testPopOnEmptyQueue_String() {
        pq_String.pop();  
    }

    @Test
    public void testContains_String() {
        pq_String.push(s1);
        pq_String.push(s2);
        assertTrue(pq_String.contains(s1));
        assertFalse(pq_String.contains(s3));  
    }

    @Test
    public void testRemove_String() {
        pq_String.push(s1);
        pq_String.push(s2);
        assertTrue(pq_String.remove(s1));
        assertFalse(pq_String.contains(s1));
    }
}