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

    // Test per aggiunta di nodi
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
    @Test
    public void testAddEdge_g1(){
        g1.addNode(0);
        g1.addNode(1);
        g1.addNode(2);
        g1.addNode(3);
        g1.addNode(4);
        assertTrue(g1.addEdge(0, 1, 5));
        assertTrue(g1.addEdge(1, 2, 5));
        assertTrue(g1.addEdge(1, 3, 5));
        assertTrue(g1.addEdge(1, 4, 5));
        assertFalse(g1.addEdge(0, 1, 5));
        assertFalse(g1.addEdge(1, 2, 5));
        assertFalse(g1.addEdge(1, 3, 5));
        assertFalse(g1.addEdge(1, 4, 5));
    }

    @Test
    public void testAddEdge_g2(){
        g2.addNode(0);
        g2.addNode(1);
        g2.addNode(2);
        g2.addNode(3);
        g2.addNode(4);
        assertTrue(g2.addEdge(0, 1, 3));
        assertTrue(g2.addEdge(1, 2, 3));
        assertTrue(g2.addEdge(1, 3, 3));
        assertTrue(g2.addEdge(1, 4, 3));
        assertFalse(g2.addEdge(0, 1, 3));
        assertFalse(g2.addEdge(1, 2, 3));
        assertFalse(g2.addEdge(1, 3, 3));
        assertFalse(g2.addEdge(1, 4, 3));
    }

    @Test
    public void testAddEdge_g3(){
        g3.addNode(0);
        g3.addNode(1);
        g3.addNode(2);
        g3.addNode(3);
        g3.addNode(4);
        assertTrue(g3.addEdge(0, 1, 7));
        assertTrue(g3.addEdge(1, 2, 7));
        assertTrue(g3.addEdge(1, 3, 7));
        assertTrue(g3.addEdge(1, 4, 7));
        assertFalse(g3.addEdge(0, 1, 7));
        assertFalse(g3.addEdge(1, 2, 7));
        assertFalse(g3.addEdge(1, 3, 7));
        assertFalse(g3.addEdge(1, 4, 7));
    }

    @Test
    public void testAddEdge_g4(){
        g4.addNode(0);
        g4.addNode(1);
        g4.addNode(2);
        g4.addNode(3);
        g4.addNode(4);
        assertTrue(g4.addEdge(0, 1, 5));
        assertTrue(g4.addEdge(1, 2, 5));
        assertTrue(g4.addEdge(1, 3, 5));
        assertTrue(g4.addEdge(1, 4, 5));
        assertFalse(g4.addEdge(0, 1, 5));
        assertFalse(g4.addEdge(1, 2, 5));
        assertFalse(g4.addEdge(1, 3, 5));
        assertFalse(g4.addEdge(1, 4, 5));
    }

    // Test per la rimozione di nodi
    @Test
    public void testRemoveNode_g1(){
        g1.addNode(i1);
        g1.addNode(i2);
        g1.addNode(i3);
        assertTrue(g1.removeNode(i1));
        assertTrue(g1.removeNode(i2));
        assertTrue(g1.removeNode(i3));
        assertFalse(g1.removeNode(i1));
        assertFalse(g1.removeNode(i2));
        assertFalse(g1.removeNode(i3));
    }

    @Test
    public void testRemoveNode_g2(){
        g2.addNode(i1);
        g2.addNode(i2);
        g2.addNode(i3);
        assertTrue(g2.removeNode(i1));
        assertTrue(g2.removeNode(i2));
        assertTrue(g2.removeNode(i3));
        assertFalse(g2.removeNode(i1));
        assertFalse(g2.removeNode(i2));
        assertFalse(g2.removeNode(i3));
    }

    @Test
    public void testRemoveNode_g3(){
        g3.addNode(i1);
        g3.addNode(i2);
        g3.addNode(i3);
        assertTrue(g3.removeNode(i1));
        assertTrue(g3.removeNode(i2));
        assertTrue(g3.removeNode(i3));
        assertFalse(g3.removeNode(i1));
        assertFalse(g3.removeNode(i2));
        assertFalse(g3.removeNode(i3));
    }

    @Test
    public void testRemoveNode_g4(){
        g4.addNode(i1);
        g4.addNode(i2);
        g4.addNode(i3);
        assertTrue(g4.removeNode(i1));
        assertTrue(g4.removeNode(i2));
        assertTrue(g4.removeNode(i3));
        assertFalse(g4.removeNode(i1));
        assertFalse(g4.removeNode(i2));
        assertFalse(g4.removeNode(i3));
    }

    // Test per la rimozione di archi
    @Test
    public void testRemoveEdge_g1(){
        g1.addNode(0);
        g1.addNode(1);
        g1.addNode(2);
        g1.addNode(3);
        g1.addNode(4);
        g1.addEdge(0, 1, 5);
        g1.addEdge(1, 2, 5);
        g1.addEdge(1, 3, 5);
        g1.addEdge(1, 4, 5);
        assertTrue(g1.removeEdge(0, 1));
        assertTrue(g1.removeEdge(1, 2));
        assertTrue(g1.removeEdge(1, 3));
        assertTrue(g1.removeEdge(1, 4));
        assertFalse(g1.removeEdge(0, 1));
        assertFalse(g1.removeEdge(1, 2));
        assertFalse(g1.removeEdge(1, 3));
        assertFalse(g1.removeEdge(1, 4));
    }

    @Test
    public void testRemoveEdge_g2(){
        g2.addNode(0);
        g2.addNode(1);
        g2.addNode(2);
        g2.addNode(3);
        g2.addNode(4);
        g2.addEdge(0, 1, 3);
        g2.addEdge(1, 2, 3);
        g2.addEdge(1, 3, 3);
        g2.addEdge(1, 4, 3);
        assertTrue(g2.removeEdge(0, 1));
        assertTrue(g2.removeEdge(1, 2));
        assertTrue(g2.removeEdge(1, 3));
        assertTrue(g2.removeEdge(1, 4));
        assertFalse(g2.removeEdge(0, 1));
        assertFalse(g2.removeEdge(1, 2));
        assertFalse(g2.removeEdge(1, 3));
        assertFalse(g2.removeEdge(1, 4));
    }

    @Test
    public void testRemoveEdge_g3(){
        g3.addNode(0);
        g3.addNode(1);
        g3.addNode(2);
        g3.addNode(3);
        g3.addNode(4);
        g3.addEdge(0, 1, 7);
        g3.addEdge(1, 2, 7);
        g3.addEdge(1, 3, 7);
        g3.addEdge(1, 4, 7);
        assertTrue(g3.removeEdge(0, 1));
        assertTrue(g3.removeEdge(1, 2));
        assertTrue(g3.removeEdge(1, 3));
        assertTrue(g3.removeEdge(1, 4));
        assertFalse(g3.removeEdge(0, 1));
        assertFalse(g3.removeEdge(1, 2));
        assertFalse(g3.removeEdge(1, 3));
        assertFalse(g3.removeEdge(1, 4));
    }

    @Test
    public void testRemoveEdge_g4(){
        g4.addNode(0);
        g4.addNode(1);
        g4.addNode(2);
        g4.addNode(3);
        g4.addNode(4);
        g4.addEdge(0, 1, 5);
        g4.addEdge(1, 2, 5);
        g4.addEdge(1, 3, 5);
        g4.addEdge(1, 4, 5);
        assertTrue(g4.removeEdge(0, 1));
        assertTrue(g4.removeEdge(1, 2));
        assertTrue(g4.removeEdge(1, 3));
        assertTrue(g4.removeEdge(1, 4));
        assertFalse(g4.removeEdge(0, 1));
        assertFalse(g4.removeEdge(1, 2));
        assertFalse(g4.removeEdge(1, 3));
        assertFalse(g4.removeEdge(1, 4));
    }

    // Test per calcolo numero di nodi
    @Test
    public void testNumNodes_g1(){
        g1.addNode(1);
        g1.addNode(2);
        g1.addNode(3);
        g1.addNode(4);
        assertEquals(4, g1.numNodes());
    }

    @Test
    public void testNumNodes_g2(){
        g2.addNode(1);
        g2.addNode(2);
        g2.addNode(3);
        g2.addNode(4);
        assertEquals(4, g2.numNodes());
    }

    @Test
    public void testNumNodes_g3(){
        g3.addNode(1);
        g3.addNode(2);
        g3.addNode(3);
        g3.addNode(4);
        assertEquals(4, g3.numNodes());
    }

    @Test
    public void testNumNodes_g4(){
        g4.addNode(1);
        g4.addNode(2);
        g4.addNode(3);
        g4.addNode(4);
        assertEquals(4, g4.numNodes());
    }

    // Test per calcolo numero di archi
    @Test
    public void testNumEdges_g1(){
        g1.addNode(1);
        g1.addNode(2);
        g1.addNode(3);
        g1.addNode(4);
        g1.addEdge(1, 2, 5);
        g1.addEdge(1, 3, 5);
        g1.addEdge(1, 4, 5);
        assertEquals(3, g1.numEdges());
    }

    @Test
    public void testNumEdges_g2(){
        g2.addNode(1);
        g2.addNode(2);
        g2.addNode(3);
        g2.addNode(4);
        g2.addEdge(1, 2, 3);
        g2.addEdge(1, 3, 3);
        g2.addEdge(1, 4, 3);
        assertEquals(3, g2.numEdges());
    }

    @Test
    public void testNumEdges_g3(){
        g3.addNode(1);
        g3.addNode(2);
        g3.addNode(3);
        g3.addNode(4);
        g3.addEdge(1, 2, 7);
        g3.addEdge(1, 3, 7);
        g3.addEdge(1, 4, 7);
        assertEquals(3, g3.numEdges());
    }

    @Test
    public void testNumEdges_g4(){
        g4.addNode(1);
        g4.addNode(2);
        g4.addNode(3);
        g4.addNode(4);
        g4.addEdge(1, 2, 5);
        g4.addEdge(1, 3, 5);
        g4.addEdge(1, 4, 5);
        assertEquals(3, g4.numEdges());
    }

    // Test per ottenere i nodi
}