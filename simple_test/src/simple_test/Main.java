package simple_test;

class Test {

    int i = 10;
    String s = "test";
}

public class Main {

    public static void main(String[] args) {
        Test test = new Test();
        Object[] obj = new Object[1];
        obj[0] = test;
        test.i = 20;
        Test nt = (Test) obj[0];
        System.out.println(nt.i);
        test.s = "XXX";
        System.out.println(nt.s);
    }
}
