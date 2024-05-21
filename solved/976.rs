#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        use std::cmp::Reverse;

        nums.sort_unstable_by_key(|v| Reverse(*v));

        for chunk in nums.windows(3) {
            let a = chunk[0];
            let b = chunk[1];
            let c = chunk[2];
            if a < b + c && b < a + c && c < a + b {
                return a + b + c;
            }
        }

        0
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    fn test_solution() {
        //
    }
}
