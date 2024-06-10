#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut ret: Vec<char> = vec![];

        for ch in s.chars() {
            if ret.last().is_some_and(|last| *last == ch) {
                ret.pop();
            } else {
                ret.push(ch);
            }
        }

        ret.into_iter().collect()
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case("abbaca", "ca")]
    #[test_case("azxxzy", "ay")]
    fn test_solution(s: &str, ans: &str) {
        assert_eq!(Solution::remove_duplicates(s.to_string()), ans);
    }
}
