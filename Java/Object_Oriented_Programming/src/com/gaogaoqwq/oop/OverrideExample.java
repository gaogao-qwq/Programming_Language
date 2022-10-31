package com.gaogaoqwq.oop;

public class OverrideExample {
    public static void main(String[] args) {
        Horse h = new Horse();
        Plane p = new Plane();
        h.run();
        h.getVehicle();
        p.run();
    }
}

/**
 * Vehicle类
 */
class Vehicle {
    public void run() {
        System.out.println("Run!");
    }

    public Vehicle getVehicle(){
        System.out.println("Vehicle get!");
        return null;
    }
}

/**
 * Horse类是Vehicle类的子类
 */
class Horse extends Vehicle {
    /*重写父类run方法*/
    @Override
    public void run() {
        System.out.println("Horse run!");
    }
    /*重写父类getVehicle方法*/
    @Override
    public Horse getVehicle() {
        return new Horse();
    }
}

/**
 * Plane类是Vehicle类的子类
 */
class Plane extends Vehicle {
    /*重写父类run方法*/
    @Override
    public void run() {
        System.out.println("Plane fly!");
    }
}