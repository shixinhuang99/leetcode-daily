#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut map: Vec<[usize; 26]> = vec![];

        for word in words {
            let mut item = [0; 26];
            for byte in word.bytes() {
                item[(byte - b'a') as usize] += 1;
            }
            map.push(item);
        }

        let mut ret = vec![];

        for i in 0..26 {
            let mut min = 101;
            for item in &map {
                min = min.min(item[i]);
            }
            for _ in 0..min {
                ret.push(char::from(i as u8 + b'a').to_string());
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
