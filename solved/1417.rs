#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn reformat(s: String) -> String {
		let mut ret = String::new();
		let mut digit = vec![];
		let mut alphabetic = vec![];

		for ch in s.chars() {
			if ch.is_ascii_alphabetic() {
				alphabetic.push(ch);
			} else if ch.is_ascii_digit() {
				digit.push(ch);
			}
		}

		let al = alphabetic.len();
		let dl = digit.len();
		let diff = (al as i32 - dl as i32).abs();

		if !(diff == 0 || diff == 1) {
			return "".to_string();
		}

		for i in 0..al.min(dl) {
			ret.push(alphabetic[i]);
			ret.push(digit[i]);
		}

		if diff == 1 {
			if al > dl {
				if let Some(last) = alphabetic.last() {
					ret.push(*last);
				}
			} else if let Some(last) = digit.last() {
				ret.insert(0, *last);
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
