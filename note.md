- Brian Kernighan's Algorithm

```rust
fn count_ones(mut n: i32) -> i32 {
    let mut count = 0;
    while n != 0 {
        n &= n - 1;
        count += 1;
    }
    count
}
```
