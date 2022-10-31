package com.gaogaoqwq.oop;

public class ExtendExample {
    public static void main(String[] args) {
        Student s1 = new Student("田所浩二", 114514, "homo");
        /*
          instanceof是二元运算符，左侧为对象，右侧为类，当左侧对象是右侧类或子类所创建对象时，返回true；
          否则，返回false。
         */
        System.out.println(s1 instanceof Student);
        System.out.println(s1 instanceof Person);
    }
}

/**
 * 当不写extends关键字的时候，默认会继承Object类。子类继承父类，可以得到父类的全部属性和方法（除了父类的构造方法），
 * 但不一定能够直接访问（如父类的私有属性和方法）
 */
class Person /*extends Object*/ {
    String name;
    int height;
    public void rest() {
        System.out.println("have a rest!");
    }
}

/**类的继承，此处Student类是Person类的子类*/
class Student extends Person {
    String major;

    public void Study() {
        System.out.println("Studying!");
        rest();
        System.out.println(this.name);
    }

    public Student(String name, int height, String major) {
        this.major = major;
        this.name = name;
        this.height = height;
    }
}