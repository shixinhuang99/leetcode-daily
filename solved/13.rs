use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    s: String,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(&self) -> Self::Output {
        Solution::roman_to_int(self.s.clone())
    }
}

struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut last = 0;
        let mut ans = 0;

        for byte in s.bytes().rev() {
            let curr = match byte {
                b'I' => 1,
                b'V' => 5,
                b'X' => 10,
                b'L' => 50,
                b'C' => 100,
                b'D' => 500,
                b'M' => 1000,
                _ => unreachable!(),
            };

            if last > curr {
                ans -= curr;
            } else {
                ans += curr;
            }

            last = curr;
        }

        ans
    }
}
