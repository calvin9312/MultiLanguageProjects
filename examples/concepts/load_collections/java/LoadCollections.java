import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.ArrayList;

public class LoadCollections {
	public static void main (String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader("program_files/unsorted_numbers.csv"));
			try {
				String line = reader.readLine();

				while(line != null) {
					System.out.println(line);
					final String[] number_strings = line.split(",");
	
					int[] numbers = new int[number_strings.length];
					for(int i = 0; i < number_strings.length; i++) {
						numbers[i] = Integer.valueOf(number_strings[i]);
					}
				
					String unordered_line = "";
					for(int number : numbers) {
						if(!unordered_line.isEmpty()) {
							unordered_line = unordered_line.concat(", ");
						}
						unordered_line = unordered_line.concat(String.valueOf(number));
					}

					System.out.println("Unordered numbers");
					System.out.println(unordered_line);
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
