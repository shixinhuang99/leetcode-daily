#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let mut ret = vec![];
        let mut prefix = 0;

        for n in nums {
            prefix = ((prefix << 1) + n) % 5;
            ret.push(prefix == 0);
        }

        ret
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
