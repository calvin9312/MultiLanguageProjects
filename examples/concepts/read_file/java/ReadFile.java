import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;

public class ReadFile {
	public static void main (String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader("program_files/unsorted_numbers.csv"));
			try {
				String line = reader.readLine();
			
				while(line != null) {
					System.out.println(line);
					line = reader.readLine();
				}
			} catch (FileNotFoundException ex) {

			} catch (IOException ex) {

			} finally {
				reader.close();
			}
		} catch (FileNotFoundException ex) {

		} catch (IOException ex) {

		}
	}
} 
