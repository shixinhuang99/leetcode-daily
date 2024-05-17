#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let vvc: Vec<Vec<char>> =
            strs.into_iter().map(|s| s.chars().collect()).collect();

        let mut ret = 0;

        for i in 0..vvc[0].len() {
            let mut j = 0;
            while j < vvc.len() - 1 {
                if vvc[j][i] > vvc[j + 1][i] {
                    ret += 1;
                    break;
                }
                j += 1;
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

    fn test_solution() {
        //
    }
}
