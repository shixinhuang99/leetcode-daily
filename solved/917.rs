#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        let mut vc: Vec<char> = s.chars().collect();
        let mut l = 0;
        let mut r = vc.len() - 1;

        while l < r {
            while l < r && !vc[l].is_ascii_alphabetic() {
                l += 1;
            }
            while l < r && !vc[r].is_ascii_alphabetic() {
                r -= 1;
            }
            vc.swap(l, r);
            l += 1;
            r -= 1;
        }

        String::from_iter(vc)
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case("ab-cd", "dc-ba")]
    #[test_case("a-bC-dEf-ghIj", "j-Ih-gfE-dCba")]
    #[test_case("Test1ng-Leet=code-Q!", "Qedo1ct-eeLg=ntse-T!")]
    fn test_solution(s: &str, ans: &str) {
        assert_eq!(Solution::reverse_only_letters(s.to_string()), ans);
    }
}
