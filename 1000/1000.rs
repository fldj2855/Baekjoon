fn main() {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();

    let mut numbers = x.trim().split(' ');
    let a = numbers.next().unwrap().parse::<i64>().unwrap();
    let b = numbers.next().unwrap().parse::<i64>().unwrap();
    println!("{}", a+b);
}