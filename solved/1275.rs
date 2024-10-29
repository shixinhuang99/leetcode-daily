#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
	pub fn tictactoe(moves: Vec<Vec<i32>>) -> String {
		let mut board = [[0; 3]; 3];

		for (i, m) in moves.iter().enumerate() {
			let x = m[0] as usize;
			let y = m[1] as usize;
			board[y][x] = if (i + 1) % 2 != 0 {
				1
			} else {
				-1
			};
		}

		fn who_win(sum: i32) -> i32 {
			if sum == 3 {
				0
			} else if sum == -3 {
				1
			} else {
				-1
			}
		}

		fn is_win(board: [[i32; 3]; 3]) -> i32 {
			for row in &board {
				let sum: i32 = row.iter().sum();
				let who = who_win(sum);
				if who != -1 {
					return who;
				}
			}

			for i in 0..3 {
				let mut sum = 0;
				for j in 0..3 {
					sum += board[j][i];
				}
				let who = who_win(sum);
				if who != -1 {
					return who;
				}
			}

			let a = board[0][0] + board[1][1] + board[2][2];
			let who = who_win(a);
			if who != -1 {
				return who;
			}

			let b = board[0][2] + board[1][1] + board[2][0];
			let who = who_win(b);
			if who != -1 {
				return who;
			}

			-1
		}

		let result_map = ["A", "B", "Draw", "Pending"];
		let mut win = is_win(board);
		if win == -1 {
			win = if moves.len() == 9 {
				2
			} else {
				3
			};
		}

		result_map[win as usize].to_string()
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
