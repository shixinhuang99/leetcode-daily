#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn minimum_abs_difference(mut arr: Vec<i32>) -> Vec<Vec<i32>> {
        arr.sort_unstable();

        let mut min = i32::MAX;
        let mut ret: Vec<Vec<i32>> = vec![];

        for chunk in arr.windows(2) {
            let diff = (chunk[0] - chunk[1]).abs();
            if diff < min {
                ret.clear();
                min = diff;
            }
            if diff == min {
                ret.push(chunk.to_vec());
            }
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

    fn test_solution() {}
}
