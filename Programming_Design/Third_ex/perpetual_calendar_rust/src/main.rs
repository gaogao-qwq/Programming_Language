use std::io;

fn main() {
    loop {
        println!("请输入一个年份：");
        let mut year = String::new();
        io::stdin().read_line(&mut year).expect("输入值非法！");
        let year: i32 = match year.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
    }
}
