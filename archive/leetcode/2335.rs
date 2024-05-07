use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    amount: Vec<i32>,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::fill_cups(self.amount)
    }
}

struct Solution;

impl Solution {
    pub fn fill_cups(amount: Vec<i32>) -> i32 {
        let mut amount = amount;
        let mut ans = 0;

        while amount.iter().any(|ele| ele.is_positive()) {
            amount.sort_by(|a, b| b.cmp(a));
            amount[0] -= 1;
            amount[1] -= 1;
            ans += 1;
        }

        ans
    }
}
