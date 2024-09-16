import java.util.Comparator;
import java.util.NoSuchElementException;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertArrayEquals;
import org.junit.Before;
import org.junit.Test;

public class Graph_Testing{
    private Integer i1, i2, i3, i4;
    Graph<Integer, Integer> g1;
    Graph<Integer, Integer> g2;
    Graph<Integer, Integer> g3;
    Graph<Integer, Integer> g4;

    @Before
    public void createGraph(){
        i1 = 10;
        i2 = 30;
        i3 = 50;
        i4 = 70;
        g1 = new Graph<>(false, false);
        g2 = new Graph<>(false, true);
        g3 = new Graph<>(true, false);
        g4 = new Graph<>(true, true);
    }

    // Test per aggiunta nodi
    @Test
    public void testAddNode_g1(){
        assertTrue(g1.addNode(i1));
        assertTrue(g1.addNode(i2));
        assertTrue(g1.addNode(i3));
        assertTrue(g1.addNode(i4));
        assertFalse(g1.addNode(i1)); // Il nodo esiste già
        assertFalse(g1.addNode(i3)); // Il nodo esiste già
    }

    @Test
    public void testAddNode_g2(){
        assertTrue(g2.addNode(i1));
        assertTrue(g2.addNode(i2));
        assertTrue(g2.addNode(i3));
        assertTrue(g2.addNode(i4));
        assertFalse(g2.addNode(i2)); // Il nodo esiste già
        assertFalse(g2.addNode(i4)); // Il nodo esiste già
    }

    @Test
    public void testAddNode_g3(){
        assertTrue(g3.addNode(87));
        assertTrue(g3.addNode(45));
        assertTrue(g3.addNode(23));
        assertTrue(g3.addNode(104));
        assertFalse(g3.addNode(104)); // Il nodo esiste già
        assertFalse(g3.addNode(45)); // Il nodo esiste già
    }

    @Test
    public void testAddNode_g4(){
        assertTrue(g4.addNode(99));
        assertTrue(g4.addNode(88));
        assertTrue(g4.addNode(66));
        assertTrue(g4.addNode(33));
        assertFalse(g4.addNode(88)); // Il nodo esiste già
        assertFalse(g4.addNode(99)); // Il nodo esiste già
    }

    // Test per l'aggiunta di archi

}