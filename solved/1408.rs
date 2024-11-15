#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn string_matching(mut words: Vec<String>) -> Vec<String> {
		words.sort_unstable_by_key(|word| word.len());

		let mut ret = vec![];

		for (i, word) in words.iter().enumerate() {
			if words[i..].iter().skip(1).any(|ohter| ohter.contains(word)) {
				ret.push(word.clone());
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

	fn test_solution() {}
}
