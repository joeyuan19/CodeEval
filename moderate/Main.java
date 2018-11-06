import java.io.*;

public class Main {
    public static String[] toLarge(int n) {
        if (n == 0) {
        	String[] s =  {
                "-**--",
                "*--*-",
                "*--*-",
                "*--*-",
                "-**--",
                "-----",
            };
        	return s;
        } else if (n == 1) {
        	String[] s =  {
                "--*--",
                "-**--",
                "--*--",
                "--*--",
                "-***-",
                "-----",
            };
        	return s;
        } else if (n == 2) {
        	String[] s =  {
                "***--",
                "---*-",
                "-**--",
                "*----",
                "****-",
                "-----",
            };
        	return s;
        } else if (n == 3) {
        	String[] s =  {
                "***--",
                "---*-",
                "-**--",
                "---*-",
                "***--",
                "-----",
            };
        	return s;
        } else if (n == 4) {
        	String[] s =  {
                "-*---",
                "*--*-",
                "****-",
                "---*-",
                "---*-",
                "-----",
            };
        	return s;
        } else if (n == 5) {
        	String[] s =  {
                "****-",
                "*----",
                "***--",
                "---*-",
                "***--",
                "-----",
            };return s;
        } else if (n == 6) {
        	String[] s =  {
                "-**--",
                "*----",
                "***--",
                "*--*-",
                "-**--",
                "-----",
            };return s;
        } else if (n == 7) {
        	String[] s =  {
                "****-",
                "---*-",
                "--*--",
                "-*---",
                "-*---",
                "-----",
            };
        	return s;
        } else if (n == 8) {
        	String[] s =  {
                "-**--",
                "*--*-",
                "-**--",
                "*--*-",
                "-**--",
                "-----",
            };
        	return s;
        } else if (n == 9) {
            String[] s = {
                "-**--",
                "*--*-",
                "-***-",
                "---*-",
                "-**--",
                "-----",
            };
        	return s;
        } else {
        	String[] s = {"","","","","",""};
        	return s;
        }
    }
    public static void numToString(String s) {
        String[] arr = {"","","","","",""}, num;
        int i, j;
        for (i = 0; i < s.length(); i++) {
        	if (s.charAt(i) <= '9' && s.charAt(i) >= '0') {
        		num = toLarge(Integer.parseInt(""+s.charAt(i)));
        		for (j = 0; j < num.length; j++) {
        			arr[j] += num[j];
        		}
        	}
        }
        for (i = 0; i < arr.length; i++) {
        	System.out.println(arr[i]);
        }
    }
    public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            numToString(line);
        }
        buffer.close();
    }
}
