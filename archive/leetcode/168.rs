use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    column_number: i32,
}

pub type Answer = String;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::convert_to_title(self.column_number)
    }
}

struct Solution;

impl Solution {
    pub fn convert_to_title(column_number: i32) -> String {
        let mut ans: Vec<u8> = Vec::new();
        let mut column_number = column_number;

        while column_number > 0 {
            column_number -= 1;

            let quotient = column_number / 26;
            let modulo = column_number - quotient * 26;

            ans.push((modulo as u8) + b'A');
            column_number = quotient;
        }

        ans.reverse();
        String::from_utf8(ans).unwrap()
    }
}
