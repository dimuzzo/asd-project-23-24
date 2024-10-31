import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class Edge_Testing_Runner{
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(Edge_Testing.class);
        
        System.out.println("Total number of tests: " + result.getRunCount());
        System.out.println("Total number of tests failed: " + result.getFailureCount());
        System.out.println("Total number of tests passed: " + (result.getRunCount() - result.getFailureCount()));
        System.out.println("Total test duration: " + result.getRunTime() + " ms");
    
        for(Failure failure : result.getFailures())
        {			
            System.out.println("The test failed for this reason: " + failure.getMessage());
        }		
        System.out.println("The test is successful? " + result.wasSuccessful());
    }
}