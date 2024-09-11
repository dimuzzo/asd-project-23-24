import java.util.Comparator;
import java.util.NoSuchElementException;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertArrayEquals;
import org.junit.Before;
import org.junit.Test;

public class Edge_Testing{
    private Integer i1, i2, i3;
    private String s1, s2, s3;
    private Edge<Integer, String> e1;
    private Edge<String, String> e2;

    @Before
    public void createEdge(){
        i1 = 15;
        i2 = 25;
        i3 = 40;
        s1 = "elodia";
        s2 = "isola";
        s3 = "MappaConcetti";
        e1 = new Edge<Integer, String>(i1, i2, s1);
        e2 = new Edge<String, String>(s1, s2, s3);
    }

    // Test per gli Integer
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
        assertEquals(e1.getLabel(), s1);
    }

    // Test per gli String
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
        assertEquals(e2.getLabel(), s3);
    }

}