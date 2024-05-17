#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        use std::collections::HashSet;

        let mut set: HashSet<i32> = HashSet::new();

        for n in nums {
            if !set.insert(n) {
                return n;
            }
        }

        panic!();
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
