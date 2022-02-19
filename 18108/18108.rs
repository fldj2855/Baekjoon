fn main() {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();

    let numbers = x.trim().parse::<i64>().unwrap();
    println!("{}", numbers-543);
}