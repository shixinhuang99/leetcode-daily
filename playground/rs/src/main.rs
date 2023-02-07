use std::fs::File;
use std::io::BufReader;
use std::path::Path;
use std::error::Error;
use serde::Deserialize;

fn main() {
    let json_input = read_josn_input("input.json").unwrap();

    for test_case in json_input {
        //
    }
}

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

struct Solution;

impl Solution {
    //
}
