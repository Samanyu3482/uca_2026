import java.util.*;
public class RobotMessageTracker{

	public static HashSet<String> set = new HashSet<>();
	public static void shouldPrintMessage( long timeStamp, String message ){
		
		// complete this message
		if ( !set.contains(message) ){
			System.out.println(message);
			set.add(message);
		}
	}

	public static void main(String args[]){
		RobotMessageTracker logger = new RobotMessageTracker();
		logger.shouldPrintMessage(1, "foo");
		logger.shouldPrintMessage(2, "hi");
		logger.shouldPrintMessage(3, "foo");
	}
}
