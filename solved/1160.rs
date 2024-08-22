#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        use std::collections::HashMap;

        let mut map: HashMap<char, usize> = HashMap::new();

        for ch in chars.chars() {
            map.entry(ch).and_modify(|cnt| *cnt += 1).or_insert(1);
        }

        let mut ret = 0;

        let can_spell = move |word: &str| -> bool {
            let mut once_map = map.clone();
            for ch in word.chars() {
                if let Some(cnt) = once_map.get_mut(&ch) {
                    if *cnt == 0 {
                        return false;
                    }
                    *cnt -= 1;
                } else {
                    return false;
                }
            }
            true
        };

        for word in words {
            if can_spell(&word) {
                ret += word.len();
            }
        }

        ret as i32
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(vec!["cat","bt","hat","tree"],"atach", 6)]
    #[test_case(vec!["hello","world","leetcode"],"welldonehoneyr", 10)]
    fn test_solution(words: Vec<&str>, chars: &str, ans: i32) {
        assert_eq!(
            Solution::count_characters(
                words.to_elements_owned(),
                chars.to_string()
            ),
            ans
        );
    }
}
