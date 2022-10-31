import java.lang.Math;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Point {
    double x, y;

    //构造方法
    Point(double _x, double _y) {
        this.x = _x;
        this.y = _y;
    }

    public double getDistance(Point p) {
        double d = sqrt(pow(x - p.x, 2) + pow(y - p.y , 2));
        return d;
    }

    public static void main(String[] args) {
        Point p1 = new Point(3.0, 4.0);
        Point origin = new Point(0.0, 0.0);
        System.out.println(p1.getDistance(origin));
    }
}
