#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let mut i = 0;
        let end = arr.len() - 1;

        while i < end && arr[i] < arr[i + 1] {
            i += 1;
        }

        if i == 0 || i == end {
            return false;
        }

        while i < end {
            if arr[i] <= arr[i + 1] {
                return false;
            }
            i += 1;
        }

        true
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
