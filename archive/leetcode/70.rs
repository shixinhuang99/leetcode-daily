use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    n: i32,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::climb_stairs(self.n)
    }
}

struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        // f(x) = f(x - 1) + f(x - 2)
        // (x - 2, x - 1, x)
        let mut f = (0, 0, 1);

        for _ in 1..=n {
            f.0 = f.1;
            f.1 = f.2;
            f.2 = f.0 + f.1;
        }

        f.2
    }
}
