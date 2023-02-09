use std::error::Error;
use std::fs::File;
use std::io::BufReader;
use std::path::Path;
use std::fmt::Debug;

use serde::de::DeserializeOwned;
use tabled::{Style, Table, Tabled, Modify, Alignment, object::Columns};
use owo_colors::OwoColorize;

use crate::sol::Input;

fn read_josn_file<P, T>(path: P) -> Result<Vec<T>, Box<dyn Error>>
where
    P: AsRef<Path>,
    T: DeserializeOwned,
{
    let file = File::open(path)?;
    let reader = BufReader::new(file);

    let deserialized_result = serde_json::from_reader(reader)?;

    Ok(deserialized_result)
}

#[derive(Tabled)]
struct TableData {
    case: String,
    output: String,
    answer: String,
    result: String,
}

const CORRECT: &'static str = "✔︎";
const INCORRECT: &'static str = "✘";

fn correct() -> String {
    CORRECT.green().to_string()
}

fn incorrect() -> String {
    INCORRECT.red().to_string()
}

impl TableData {
    fn new<T>(input: Input, output: T) -> TableData
    where
        T: Debug,
    {
        let answer = format!("{:?}", input.answer);
        let output = format!("{:?}", output);
        let result = match answer == output {
            true => correct(),
            false => incorrect(),
        };
        let case = format!("{:?}", input.case);

        TableData {
            case,
            output,
            answer,
            result,
        }
    }
}

pub fn run() {
    let vec_input: Vec<Input> = read_josn_file("input.json").unwrap();
    let mut data: Vec<TableData> = Vec::new();

    for input in vec_input.into_iter() {
        let output = input.get_output();
        data.push(TableData::new(input, output))
    }

    let mut table = Table::new(&data);
    table
        .with(Style::psql())
        .with(Modify::new(Columns::single(3)).with(Alignment::center()));

    println!("{}", table);
}
