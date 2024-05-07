use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    nums: Vec<i32>,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::majority_element(self.nums)
    }
}

struct Solution;

impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut count = 0;

        for ele in nums {
            if count == 0 {
                ans = ele
            }
            if ans == ele {
                count += 1
            } else {
                count -= 1
            }
        }

        ans
    }
}
