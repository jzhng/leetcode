// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {
  public:
    int get(int index) const;
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 10000;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (target <= reader.get(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return reader.get(l) == target ? l : -1;
    }
};

int main() {

}