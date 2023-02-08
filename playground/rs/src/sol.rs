use std::error::Error;
use std::fs::File;
use std::io::BufReader;
use std::path::Path;

use serde::Deserialize;

#[derive(Deserialize, Debug)]
struct TestCase {
    //
}

fn read_josn_input<P>(path: P) -> Result<Vec<TestCase>, Box<dyn Error>>
where
    P: AsRef<Path>,
{
    let file = File::open(path)?;
    let reader = BufReader::new(file);

    let json_input = serde_json::from_reader(reader)?;

    Ok(json_input)
}

pub fn run() {
    let json_input = read_josn_input("input.json").unwrap();

    for (i, test_case) in json_input.into_iter().enumerate() {
        println!("---case {}---", i + 1);
        let res = 0;
        println!("---result: {:?}---", res);
    }
}

struct Solution;

impl Solution {
    //
}
