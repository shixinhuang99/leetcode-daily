#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
		struct Tmp {
			idx: i32,
			count: i32,
		}

		let mut ranks = vec![];

		for (i, row) in mat.iter().enumerate() {
			let mut count = 0;
			for v in row {
				if *v == 1 {
					count += 1;
				} else {
					break;
				}
			}
			ranks.push(Tmp {
				idx: i as i32,
				count,
			});
		}

		ranks.sort_unstable_by(|a, b| {
			if a.count == b.count {
				return a.idx.cmp(&b.idx);
			}
			a.count.cmp(&b.count)
		});

		ranks.into_iter().take(k as usize).map(|v| v.idx).collect()
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
