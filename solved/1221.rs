#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut r = 0;
        let mut l = 0;
        let mut cnt = 0;

        for ch in s.chars() {
            if ch == 'R' {
                r += 1;
            } else if ch == 'L' {
                l += 1;
            }
            if r == l {
                cnt += 1;
                r = 0;
                l = 0;
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

    fn test_solution() {}
}
