#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let mut i = 0;
        let mut j = nums.len() - 1;
        let mut k = j;
        let mut ret = vec![0; nums.len()];

        while i <= j {
            if nums[i].abs() >= nums[j].abs() {
                ret[k] = nums[i].pow(2);
                i += 1;
            } else {
                ret[k] = nums[j].pow(2);
                j -= 1;
            }
            k -= 1;
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
