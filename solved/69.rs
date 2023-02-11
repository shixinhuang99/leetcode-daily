use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args {
    x: i32,
}

pub type Answer = i32;

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        Solution::john_carmack_sqrt(self.x)
    }
}

struct Solution;

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x == 0 || x == 1 {
            return x;
        }

        let mut xn = x >> 1;

        loop {
            let xn_next = (xn + x / xn) >> 1;
            if xn_next >= xn {
                break;
            }
            xn = xn_next;
        }

        xn
    }

    pub fn john_carmack_sqrt(x: i32) -> i32 {
        let x_half = 0.5f64 * x as f64;

        let mut i = (x as f64).to_bits();
        i = 0x5FE6EC85E7DE30DA_u64 - (i >> 1);

        let mut f = f64::from_bits(i);

        f = f * (1.5 - x_half * f * f);
        f = f * (1.5 - x_half * f * f);
        f = f * (1.5 - x_half * f * f);

        (1.0f64 / f) as i32
    }
}
