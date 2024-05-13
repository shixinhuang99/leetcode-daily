#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn sort_array_by_parity_ii(mut nums: Vec<i32>) -> Vec<i32> {
        let mut even = 0;
        let mut odd = 1;

        loop {
            while even < nums.len() && nums[even] % 2 == 0 {
                even += 2;
            }
            while odd < nums.len() && nums[odd] % 2 != 0 {
                odd += 2;
            }
            if even >= nums.len() || odd >= nums.len() {
                break;
            }
            nums.swap(even, odd);
        }

        nums
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(&[888,505,627,846], &[888,505,846,627])]
    #[test_case(&[2,2,2,2,1,1,1,1], &[2,1,2,1,2,1,2,1])]
    #[test_case(&[1,1,1,1,2,2,2,2], &[2,1,2,1,2,1,2,1])]
    fn test_solution(nums: &[i32], ans: &[i32]) {
        assert_eq!(Solution::sort_array_by_parity_ii(nums.to_vec()), ans);
    }
}
