use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    column_title: String,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::title_to_number(self.column_title)
    }
}

struct Solution;

impl Solution {
    pub fn title_to_number(column_title: String) -> i32 {
        let mut ans: i32 = 0;
        let mut exp: u32 = 0;

        for ele in column_title.bytes().rev() {
            ans += (ele - b'A' + 1) as i32 * 26_i32.pow(exp);
            exp += 1;
        }

        ans
    }
}
