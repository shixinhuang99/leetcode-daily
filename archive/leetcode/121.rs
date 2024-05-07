use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    prices: Vec<i32>,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::max_profit(self.prices)
    }
}

struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min = 10001;
        let mut max = 0;

        for ele in prices {
            max = max.max(ele - min);
            min = min.min(ele);
        }

        max
    }
}
