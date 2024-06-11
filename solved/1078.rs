#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn find_ocurrences(
        text: String,
        first: String,
        second: String,
    ) -> Vec<String> {
        let words: Vec<&str> = text.split_ascii_whitespace().collect();

        let ret = words
            .windows(3)
            .filter_map(|chunk| {
                if chunk[0] == first && chunk[1] == second {
                    Some(chunk[2].to_string())
                } else {
                    None
                }
            })
            .collect();

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
