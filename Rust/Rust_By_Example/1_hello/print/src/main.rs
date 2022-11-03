// 打印操作由 std::fmt 里面所定义的一系列宏来处理，包括：

// format!：将格式化文本写到字符串。
// print!：与 format! 类似，但将文本输出到控制台（io::stdout）。
// println!: 与 print! 类似，但输出结果追加一个换行符。
// eprint!：与 print! 类似，但将文本输出到标准错误（io::stderr）。
// eprintln!：与 eprint! 类似，但输出结果追加一个换行符。

// 这些宏都以相同的做法解析文本。有个额外优点是格式化的正确性会在编译时检查。

fn main() {
    // 注意变量内容会被转换成字符串输出
    // 在1后面加类型可以改变类型
    println!("here is a number {}", 1f64);

    // 和 Python 类似，可以在 {} 中加上位置参数
    println!("{0}即是{1}，{1}即是{0}。", "空", "色");
    // 也可以用命名参数
    println!("{greetings}，我是{name}。", greetings = "大家好啊", name = "电棍");

    // 在 ':' 后面指定特殊的格式输出，如：
    println!("{:b}分之{:b}的人了解二进制，另外一半则不了解。", 2, 1);
    // HEX:16 DEC:10 OCT:8 BIN:2 {:x}为小写英文字母，{:X}为大写
    println!("十进制数{}的二进制数为：{:b}，八进制数为：{:o}，十六进制数为：{:x}", 114514, 114514, 114514, 114514);
    // 更多格式化相关请查文档：https://rustwiki.org/zh-CN/std/fmt/index.html

    // 向右对齐并左补字符
    println!("{number:->width$}", number=1, width=7);
    // 居中
    println!("{number:-^width$}", number=1, width=7);
    // 左对齐
    println!("{number:-<width$}", number=1, width=7);

    // 对于 Rust 自带类型，简单的格式化输出足矣，然而像结构体则需要更复杂的方式处理
    #[allow(dead_code)]
    struct Structure(i32);
    // 下面语句无法运行。
    // println!("This struct `{}` won't print...", Structure(3));

    // 上面的代码都使用了 fmt::Display
    // fmt::Debug：使用 {:?} 标记。格式化文本以供调试使用。
    // fmt::Display：使用 {} 标记。以更优雅和友好的风格来格式化文本。

    let pi = 3.1415926;
    // 保留三位小数
    println!("{:.3}", pi);
}