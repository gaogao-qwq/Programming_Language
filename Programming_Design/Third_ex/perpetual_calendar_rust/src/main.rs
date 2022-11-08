use std::io;

// 造俩全局编译时静态数组当 map 使
const MONTHS:[usize; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
const MONTHS_LEAP:[usize; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

fn compute_date(mut y: usize, mut m: usize, d: usize) -> usize {
    if m < 3 {y -= 1; m += 12;}
    365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306
}

fn generate_calendar(y: usize) -> Vec<[usize; 3]> {
    let mut n = 365;
    let mut date = &MONTHS;
    if (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 {
        n += 1;
        date = &MONTHS_LEAP;
    }

    let mut calendar = vec![[0; 3]; n];
    let mut m = 1;
    let mut d = 1;
    for i in 0..n {
        calendar[i][0] = m;
        calendar[i][1] = d;
        calendar[i][2] = compute_date(y, m, d) % 7;

        d += 1;
        if d > date[m - 1] {
            m += 1;
            d = 1;
        }
    }
    calendar
}

fn print_calendar(calendar: &Vec<[usize; 3]>, y: usize) {
    let mut n = 365;
    if (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 {
        n += 1;
    }

    let mut m = 0;
    let mut d = 0;
    for i in 0..n {
        // 打印月及日历抬头指示
        if m != calendar[i][0] {
            d = 0;
            m += 1;
            print!("\n\n\n");
            println!("{month:>width$}月", month=calendar[i][0], width=11);
            println!(" {0} {1} {2} {3} {4} {5} {6}",
                     "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa");
        }
        // 补齐空格
        while d != calendar[i][2] {
            print!("   ");
            d += 1;
        }
        // 打印日
        print!("{day:>width$}", day=calendar[i][1], width=3);
        d += 1;
        // 换行
        if d > 6 {
            println!();
            d = 0;
        }
    }
}

fn main() {
    loop {
        println!("请输入年份（Ctrl-C 退出）：");
        let mut year = String::new();
        io::stdin().read_line(&mut year).expect("输入值非法！");
        let year: usize = match year.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("输入值非法！\n");
                continue;
            },
        };
        let calendar = generate_calendar(year);
        print_calendar(&calendar, year);
    }
}
