public class User {
    int id;
    String name;
    String pwd;

    //构造方法重载，IDEA中也可以直接生成构造方法而不需要自己敲(Alt + Insert)
    public User() {}
    public User(int id) {
        this.id = id;
    }
    public User(int id, String name) {
        this.id = id;
        this.name = name;
    }
    public User(int id, String name, String pwd) {
        this.id = id;
        this.name = name;
        this.pwd = pwd;
    }

    public static void main(String[] args) {
        User u = new User();
        User u1 = new User(114514);
        User u2 = new User(114514, "田所浩二");
        User u3 = new User(114514, "田所浩二", "1145141919810");
    }
}
