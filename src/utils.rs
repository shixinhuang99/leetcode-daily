use std::error::Error;
use std::fs::File;
use std::io::BufReader;
use std::path::Path;
use std::fmt::Debug;

use serde::{de::DeserializeOwned, Deserialize};
use tabled::{Style, Table, Tabled, Modify, Alignment, object::Columns};
use owo_colors::OwoColorize;

#[derive(Deserialize)]
pub struct TestCase<T, U> {
    pub answer: T,
    pub args: U,
}

pub trait SolutionTrait {
    type Output: Debug;

    fn get_output(self) -> Self::Output;
}

pub fn read_test_cases<P, T, U>(
    path: P,
) -> Result<Vec<TestCase<T, U>>, Box<dyn Error>>
where
    P: AsRef<Path>,
    T: DeserializeOwned,
    U: DeserializeOwned,
{
    let file = File::open(path)?;
    let reader = BufReader::new(file);

    let deserialized_result = serde_json::from_reader(reader)?;

    Ok(deserialized_result)
}

#[derive(Tabled)]
struct TableData {
    args: String,
    answer: String,
    output: String,
    result: String,
}

fn format_result(result: bool) -> String {
    const CORRECT: &'static str = "AC";
    const INCORRECT: &'static str = "WA";

    if result {
        return CORRECT.green().to_string();
    }

    INCORRECT.red().to_string()
}

impl TableData {
    fn new<T, U>(test_case: TestCase<T, U>) -> TableData
    where
        T: DeserializeOwned + Debug,
        U: DeserializeOwned + SolutionTrait + Debug,
    {
        let args = format!("{:?}", test_case.args);
        let answer = format!("{:?}", test_case.answer);
        let output = format!("{:?}", test_case.args.get_output());
        let result = format_result(answer == output);

        TableData {
            args,
            output,
            answer,
            result,
        }
    }
}

pub fn format_table<T, U>(test_cases: Vec<TestCase<T, U>>) -> String
where
    T: DeserializeOwned + Debug,
    U: DeserializeOwned + SolutionTrait + Debug,
{
    let data =
        Vec::from_iter(test_cases.into_iter().map(|case| TableData::new(case)));

    let mut table = Table::new(&data);
    table
        .with(Style::psql())
        .with(Modify::new(Columns::single(3)).with(Alignment::center()));

    table.to_string()
}
