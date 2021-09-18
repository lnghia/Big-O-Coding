import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collection;
import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Codeforces_510C solver = new Codeforces_510C();
        solver.solve(in, out);
        out.close();
    }

    static class Codeforces_510C {
        InputReader in;
        OutputWriter out;

        public void solve(InputReader in_, OutputWriter out_) {
            in = in_;
            out = out_;

            int n = in.nextInt();
            String[] names = new String[n];

            for (int i = 0; i < n; i++) {
                names[i] = in.next();
            }

            ArrayList<Integer>[] lexicographical = setUpLexicographical(names);

            if (lexicographical == null) {
                out.println("Impossible");
                return;
            }

            String result = topoSort(lexicographical);

            if (result == null) {
                out.println("Impossible");
                return;
            }

            out.println(result);
        }

        private String topoSort(ArrayList<Integer>[] lexicographical) {
            int[] inDeg = new int[26];
            StringBuilder result = new StringBuilder();
            Queue<Integer> zeroInDegQueue = new LinkedList<>();

            for (int u = 0; u < 26; u++) {
                for (int v : lexicographical[u]) {
                    ++inDeg[v];
                }
            }

            for (int u = 0; u < 26; u++) {
                if (inDeg[u] == 0) {
                    zeroInDegQueue.add(u);

                }
            }

            while (!zeroInDegQueue.isEmpty()) {
                int u = zeroInDegQueue.poll();
                result.append((char) (u + 97));

                for (int v : lexicographical[u]) {
                    --inDeg[v];
                    if (inDeg[v] == 0) {
                        zeroInDegQueue.add(v);
                    }
                }
            }

            for (int i = 0; i < 26; i++) {
                if (inDeg[i] != 0) {
                    return null;
                }
            }

            return result.toString();
        }

        private ArrayList<Integer>[] setUpLexicographical(String[] names) {
            ArrayList<Integer>[] lexicographical = new ArrayList[26];
            boolean[][] relation = new boolean[26][26];

            for (int u = 0; u < 26; u++) {
                lexicographical[u] = new ArrayList<>();
            }

            for (int u = 0; u < 26; u++) {
                for (int v = 0; v < 26; v++) {
                    relation[u][v] = false;
                }
            }

            boolean flag;

            for (int i = 0; i < names.length - 1; i++) {
                flag = false;
                int minSize = Math.min(names[i].length(), names[i + 1].length());

                for (int j = 0; j < minSize; ++j) {
                    if (names[i].charAt(j) != names[i + 1].charAt(j)) {
                        relation[names[i].charAt(j) - 97][names[i + 1].charAt(j) - 97] = true;
                        flag = true;
                        break;
                    }
                }

                if (!flag && (names[i].length() > names[i + 1].length())) {
                    return null;
                }
            }

            for (int u = 0; u < 26; u++) {
                for (int v = 0; v < 26; v++) {
                    if (relation[u][v]) {
                        lexicographical[u].add(v);
                    }
                }
            }

            return lexicographical;
        }

    }

    static class InputReader {
        private final int BUFFER_SIZE = 32768;
        private InputStream stream;
        private byte[] buffer = new byte[BUFFER_SIZE + 1];
        private int pointer = 1;
        private int readLength = 0;
        private int lastWhiteSpace = '\n';

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private byte nextRawByte() {
            if (pointer > readLength) {
                pointer = 1;

                try {
                    readLength = stream.read(buffer, 1, BUFFER_SIZE);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }

                if (readLength == -1) return -1;
            }

            return buffer[pointer++];
        }

        public int nextChar() {
            int c = nextRawByte();

            while (isWhiteSpace(c)) {
                c = nextRawByte();
            }

            return c;
        }

        public int nextInt() {
            int c = nextChar();
            int sign = 1;

            if (c == '-') {
                sign = -1;
                c = nextRawByte();
            }

            int abs = 0;

            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                abs = c - '0' + abs * 10;
                c = nextRawByte();
            } while (!isWhiteSpace(c));

            lastWhiteSpace = c;

            return abs * sign;
        }

        public String nextString() {
            int c = nextChar();

            if (c == -1) return null;

            StringBuilder builder = new StringBuilder();

            do {
                builder.append((char) c);
                c = nextRawByte();
            } while (!isWhiteSpace(c));

            return builder.toString();
        }

        public String next() {
            return nextString();
        }

        public boolean isWhiteSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class OutputWriter {
        private PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (Object object : objects) {
                writer.print(object);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}