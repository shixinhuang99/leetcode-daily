#[cfg(test)]
mod utils;

pub struct Solution;

// start
static LEAP_YEARS: [i32; 32] = [
	1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016,
	2020, 2024, 2028, 2032, 2036, 2040, 2044, 2048, 2052, 2056, 2060, 2064,
	2068, 2072, 2076, 2080, 2084, 2088, 2092, 2096,
];

fn parse_date(date: String) -> [i32; 3] {
	let mut ret: [i32; 3] = [0; 3];
	for (i, s) in date.split('-').enumerate() {
		ret[i] = s.parse::<i32>().unwrap();
	}
	ret
}

fn count_leap_year(year: i32) -> i32 {
	let mut count = 0;

	for y in &LEAP_YEARS {
		if *y > year {
			break;
		}
		count += 1;
	}

	count
}

fn count_days(date: String) -> i32 {
	let mut days = 0;

	let [y, mut m, d] = parse_date(date);
	m -= 1;

	let dy = y - 1971 - 1;
	let leap_year_count = count_leap_year(y - 1);
	days += dy * 365 + leap_year_count;

	const MDS: [i32; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
	if m > 0 {
		days += MDS.iter().take(m as usize).sum::<i32>();
		if m > 1 && LEAP_YEARS.contains(&y) {
			days += 1;
		}
	}

	days += d;

	days
}

impl Solution {
	pub fn days_between_dates(date1: String, date2: String) -> i32 {
		(count_days(date1) - count_days(date2)).abs()
	}
}
// end

#[cfg(test)]
mod tests {
	use super::*;
	use test_case::test_case;
	use utils::*;

	#[test_case(S!("2019-06-29"), S!("2019-06-30"), 1)]
	#[test_case(S!("2020-01-15"), S!("2019-12-31"), 15)]
	fn test_solution(date1: String, date2: String, ans: i32) {
		assert_eq!(Solution::days_between_dates(date1, date2), ans);
	}
}
