impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for (i, x) in nums.iter().enumerate() {
            for (j, y) in nums.iter().enumerate() {
                if i != j && x + y == target  {
                    return vec![i as i32, j as i32];
                }
            }
        }
        vec![]
    }
}

struct Solution {}
fn main() {
    let nums = vec![2, 7, 11, 15];
    let target = 9;
    let res = Solution::two_sum(nums, target);
    println!("{:?}", res);
}
