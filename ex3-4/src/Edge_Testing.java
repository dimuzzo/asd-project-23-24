import static org.junit.Assert.assertEquals;
import org.junit.Before;
import org.junit.Test;

public class Edge_Testing{
    private Integer i1, i2;
    private String s1, s2, l1, l2;
    private Edge<Integer, String> e1;
    private Edge<String, String> e2;

    @Before
    public void createNewEdge(){
        i1 = 15;
        i2 = 25;
        s1 = "elodia";
        s2 = "isola";
        l1 = "label1";
        l2 = "label2";
        e1 = new Edge<>(i1, i2, l1);
        e2 = new Edge<>(s1, s2, l2);
    }

    // Test for Integer Edges
    @Test
    public void testGetStart_Int(){
        assertEquals(e1.getStart(), i1);
    }

    @Test
    public void testGetEnd_Int(){
        assertEquals(e1.getEnd(), i2);
    }

    @Test
    public void testGetLabel_Int(){
        assertEquals(e1.getLabel(), l1);
    }

    // Test for String Edges
    @Test
    public void testGetStart_String(){
        assertEquals(e2.getStart(), s1);
    }

    @Test
    public void testGetEnd_String(){
        assertEquals(e2.getEnd(), s2);
    }

    @Test
    public void testGetLabel_String(){
        assertEquals(e2.getLabel(), l2);
    }

}