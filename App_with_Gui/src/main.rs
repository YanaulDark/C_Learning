use tokio::fs::File;
use tokio::io::AsyncReadExt;

#[tokio::main]
async fn main() {
    let mut file = File::open("~/C_Learning/README.md")
        .await
        .expect("Not working. Ooops");
    let mut contents = String::new();

    file.read_to_string(&mut contents)
        .await
        .expect("Again? This code not working, fuuuuuck.");

    println!("{}", contents);
}
