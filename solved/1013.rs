#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let sum: i32 = arr.iter().sum();
        if sum % 3 != 0 {
            return false;
        }
        let ave = sum / 3;
        let mut sub_sum = 0;
        let mut count = 0;
        for n in arr {
            sub_sum += n;
            if sub_sum == ave {
                sub_sum = 0;
                count += 1;
            };
        }
        count >= 3
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(&[0,2,1,-6,6,-7,9,1,2,0,1], true; "1")]
    #[test_case(&[0,2,1,-6,6,7,9,-1,2,0,1], false; "2")]
    #[test_case(&[3,3,6,5,-2,2,5,1,-9,4], true; "3")]
    #[test_case(&[0,0,0,0], true; "4")]
    #[test_case(&[1,-1,1,-1], false; "5")]
    fn test_solution(arr: &[i32], ans: bool) {
        assert_eq!(Solution::can_three_parts_equal_sum(arr.to_vec()), ans);
    }
}
