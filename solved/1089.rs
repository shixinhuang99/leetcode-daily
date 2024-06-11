#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let mut i = 0;
        let len = arr.len();

        while i < len - 1 {
            if arr[i] == 0 {
                arr.insert(i, 0);
                i += 2;
            } else {
                i += 1;
            }
        }

        arr.truncate(len);
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(vec![1,0,2,3,0,4,5,0], vec![1,0,0,2,3,0,0,4])]
    #[test_case(vec![1,2,3], vec![1,2,3])]
    #[test_case(vec![0,0,0], vec![0,0,0])]
    #[test_case(vec![1,1,0], vec![1,1,0])]
    #[test_case(vec![0], vec![0])]
    #[test_case(vec![1], vec![1])]
    fn test_solution(mut arr: Vec<i32>, ans: Vec<i32>) {
        Solution::duplicate_zeros(&mut arr);
        assert_eq!(arr, ans);
    }
}
