#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        use std::cmp::Ordering::*;
        use std::collections::HashMap;

        let mut map: HashMap<char, usize> = HashMap::new();

        map.insert(' ', 0);

        for (i, ch) in order.chars().enumerate() {
            map.insert(ch, i + 1);
        }

        for chunk in words.windows(2) {
            let mut iter_i = chunk[0].chars();
            let mut iter_j = chunk[1].chars();

            loop {
                let ch_i = iter_i.next().unwrap_or(' ');
                let ch_j = iter_j.next().unwrap_or(' ');

                if ch_i == ' ' && ch_j == ' ' {
                    break;
                }

                match map.get(&ch_i).unwrap().cmp(map.get(&ch_j).unwrap()) {
                    Greater => return false,
                    Equal => continue,
                    Less => break,
                }
            }
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

    #[test_case(&["hello","leetcode"],"hlabcdefgijkmnopqrstuvwxyz", true)]
    #[test_case(&["word","world","row"],"worldabcefghijkmnpqstuvxyz", false)]
    #[test_case(&["apple","app"],"abcdefghijklmnopqrstuvwxyz", false)]
    fn test_solution(words: &[&str], order: &str, ans: bool) {
        assert_eq!(
            Solution::is_alien_sorted(
                str_slice_to_string_vec(words),
                order.to_string()
            ),
            ans
        );
    }
}
