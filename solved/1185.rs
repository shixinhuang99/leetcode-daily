#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn day_of_the_week(day: i32, month: i32, mut year: i32) -> String {
		let m = if matches!(month, 1 | 2) {
			year -= 1;
			month + 12
		} else {
			month
		};
		let c = year / 100;
		let y = year % 100;
		let mut ret =
			(c / 4) - (2 * c) + y + (y / 4) + ((13 * (m + 1)) / 5) + day - 1;
		while ret < 0 {
			ret += 7;
		}
		ret %= 7;
		let map = [
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday",
		];
		(map[ret as usize]).to_string()
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
