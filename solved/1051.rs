#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut cnt = 0;
        let mut expected = heights.clone();

        expected.sort_unstable();

        for i in 0..heights.len() {
            if heights[i] != expected[i] {
                cnt += 1;
            }
        }

        cnt
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
