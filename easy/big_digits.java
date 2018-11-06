import java.io.*;

public class Main {
    public static String[] toLarge(int n) {
        if (n == 0) {
            String[] s =  {
                "_**__",
                "*__*_",
                "*__*_",
                "*__*_",
                "_**__",
                "_____",
            };
            return s;
        } else if (n == 1) {
            String[] s =  {
                "__*__",
                "_**__",
                "__*__",
                "__*__",
                "_***_",
                "_____",
            };
            return s;
        } else if (n == 2) {
            String[] s =  {
                "***__",
                "___*_",
                "_**__",
                "*____",
                "****_",
                "_____",
            };
            return s;
        } else if (n == 3) {
            String[] s =  {
                "***__",
                "___*_",
                "_**__",
                "___*_",
                "***__",
                "_____",
            };
            return s;
        } else if (n == 4) {
            String[] s =  {
                "_*___",
                "*__*_",
                "****_",
                "___*_",
                "___*_",
                "_____",
            };
            return s;
        } else if (n == 5) {
            String[] s =  {
                "****_",
                "*____",
                "***__",
                "___*_",
                "***__",
                "_____",
            };return s;
        } else if (n == 6) {
            String[] s =  {
                "_**__",
                "*____",
                "***__",
                "*__*_",
                "_**__",
                "_____",
            };return s;
        } else if (n == 7) {
            String[] s =  {
                "****_",
                "___*_",
                "__*__",
                "_*___",
                "_*___",
                "_____",
            };
            return s;
        } else if (n == 8) {
            String[] s =  {
                "_**__",
                "*__*_",
                "_**__",
                "*__*_",
                "_**__",
                "_____",
            };
            return s;
        } else if (n == 9) {
            String[] s = {
                "_**__",
                "*__*_",
                "_***_",
                "___*_",
                "_**__",
                "_____",
            };
            return s;
        } else {
            System.out.println(n);
            String[] s = {"","","","","",""};
            return s;
        }
    }
    public static String numToString(String s) {
        String[] arr = {"","","","","",""}, num;
        int i;
        for (i = 0; i < s.length(); i++) {
            if (s.charAt(i) <= '9' && s.charAt(i) >= '0') {
                num = toLarge(Integer.parseInt(""+s.charAt(i)));
            }
        }
        String tmp = "";
        for (i = 0; i < arr.length; i++) {
            tmp += arr[i] + "\n";
        }
        return tmp;
    }
    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
        }
        buffer.close();
    }
}
