#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn freq_alphabets(s: String) -> String {
		let mut stack = vec![];
		let mut ret = String::new();
		let diff_a_i = b'a' - b'1';
		let diff_j_z = b'j' - 10;

		for ch in s.bytes() {
			if stack.len() >= 2 {
				if ch == b'#' {
					let mut s = String::new();
					s.push(char::from(stack[0]));
					s.push(char::from(stack[1]));
					if let Ok(num) = s.parse::<u8>() {
						ret.push(char::from(num + diff_j_z));
					}
					stack.clear();
				} else {
					let byte = stack[0];
					stack[0] = stack[1];
					stack.pop();
					ret.push(char::from(byte + diff_a_i));
					stack.push(ch);
				}
			} else {
				stack.push(ch);
			}
		}

		if !stack.is_empty() {
			for byte in stack {
				ret.push(char::from(byte + diff_a_i));
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

	#[test_case("10#11#12", "jkab")]
	#[test_case("1326#", "acz")]
	fn test_solution(s: &str, ans: &str) {
		assert_eq!(Solution::freq_alphabets(s.to_string()), ans.to_string());
	}
}
