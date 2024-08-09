#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        address.replace('.', "[.]")
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case("1.1.1.1", "1[.]1[.]1[.]1")]
    #[test_case("255.100.50.0", "255[.]100[.]50[.]0")]
    fn test_solution(address: &str, answer: &str) {
        assert_eq!(Solution::defang_i_paddr(address.to_string()), answer);
    }
}
