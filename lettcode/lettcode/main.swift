//
//  main.swift
//  lettcode
//
//  Created by 吴孜健 on 2019/12/27.
//  Copyright © 2019 kingdee. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

public class TreeNode {
     public var val: Int
     public var left: TreeNode?
     public var right: TreeNode?
     public init(_ val: Int) {
         self.val = val
         self.left = nil
         self.right = nil
     }
 }


class Solution {
    func strStr(_ haystack: String, _ needle: String) -> Int {

        if needle.count == 0 {
            return 0
        }
        if let range = haystack.range(of: needle) {
             let position:Int =  haystack.distance(from: haystack.startIndex, to: range.lowerBound)
            return position
        } else {
            return -1
        }
       
    }
    
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        for num in 0..<nums.count {
            if nums[num] == target   {
                return num
            } else if target < nums[num] {
                return num+1
            }
        }
        return nums.count
    }
   
    
    func countAndSay(_ n: Int) -> String {
        var res = "1"
        var i = 1
        while i < n  {
            let str = res
            res = ""
            var j = 0
            while j < str.count {
                var k = j
                var c = 0
                while k < str.count && str.findIndex(k) == str.findIndex(j) {
                    k += 1
                    c += 1
                }
                res = res + String(c) + str.findIndex(j)
                j = k
            }
            i += 1
        }
        return res
    }
    
    func maxSubArray(_ nums: [Int]) -> Int {
         var ans = nums[0];
        var sum = 0;
        for index in 0..<nums.count {
            let value = nums[index]
            if(sum > 0) {
                sum += value;
            } else {
                sum = value;
            }
            ans = max(ans, sum);
        }
        return ans;
      
    }
    
    func lengthOfLastWord(_ s: String) -> Int {
        let arraySubstrings: [Substring] = s.split(separator: " ")
        return String(arraySubstrings[arraySubstrings.count-1]).count
    }
    
    func plusOne(_ digits: [Int]) -> [Int] {
        
        var nums = digits
        for i in (0..<nums.count).reversed() {
            nums[i] += 1
            nums[i] = nums[i] % 10
            if nums[i] % 10 != 0 {
                return nums
            }
        }
        
        nums.insert(1, at: 0)
        return nums
    }
    
    func addBinary(_ a: String, _ b: String) -> String {
        var ca = 0
        var i = a.count-1
        var j = b.count-1
        var res = ""
        
        while i >= 0 || j >= 0 {
            var sum = 0
            sum += i >= 0 ? Int(a.findIndex(i))!:0
            sum += j >= 0 ? Int(b.findIndex(j))!:0
            sum += ca
            let p = String(sum%2)
            res = p + res
            ca = sum/2
            
            i -= 1
            j -= 1
        }
        if ca > 0 {
            res = "1" + res
        }
        return res
        
        
    }
    
    func mySqrt(_ x: Int) -> Int {
        if x == 0 {
            return 0
        }
        var left = 0
        var right = x/2
        
        while right > left {
            let mid = (left+right+1) >> 1
            let sq = mid * mid
            if sq > x {
                right = mid-1
            } else {
                left = mid
            }
        }
        return left
    }
    
    func climbStairs(_ n: Int) -> Int {
        var vex = [Int]()
        vex.append(0)
        vex.append(1)
        vex.append(2)
        vex.append(3)
        var i = 4
        while i <= n  {
            vex.append(vex[i-1]+vex[i-2])
            i += 1
        }
        return vex[n]
    }
    
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        var pre = head
        var cur = head
        var tmp = head
        let m = tmp
        while cur != nil {
            let curval = cur!.val
            if curval != pre!.val {
                tmp?.next = cur
                tmp = tmp?.next
            }
            pre = cur!
            cur = cur?.next
            
            
        }
        tmp?.next = nil
        return m
    }
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        
        var newNum = [Int]()
        var i = 0
        var j = 0
        
     
        while i < m && j < n {
            
            if nums1[i] <= nums2[j] {
                newNum.append(nums1[i])
                i += 1
                
            }else {
                newNum.append(nums2[j])
                j += 1
            }
        }
        
            while i < m{
                newNum.append(nums1[i])
                i += 1
            }
        
        while j < n {
            newNum.append(nums2[j])
            j += 1
        }
        
        nums1 = newNum
    }
    
    func isSameTree(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
        if p == nil && q == nil {
            return true
        }
        
        if p == nil || q == nil {
            return false
        }
        
        if p!.val != q!.val {
            return false
        }
        
        return self.isSameTree(p?.left, q?.left) && self.isSameTree(p?.right, q?.right)
         
    }
    
    func isSymmetric(_ root: TreeNode?) -> Bool {
         return isMirror(root, root)
       }
    func isMirror(_ left: TreeNode?, _ right: TreeNode?) -> Bool {
        if left == nil && right == nil {
            return true
        }
        if left == nil || right == nil {
            return false
        }
        return (left!.val == right!.val) && isMirror(left?.left, right?.right) && isMirror(left?.right, right?.left)
    }
    
    func maxDepth(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        } else {
            let leftHeight = maxDepth(root?.left)
            let rightHeight = maxDepth(root?.right)
            return max(leftHeight, rightHeight) + 1
        }
    }
    
    func levelOrderBottom(_ root: TreeNode?) -> [[Int]] {
        if(root == nil) {
            return [[Int]]()
        }
        var result = [[Int]]()
        var queue = [root!,"a"] as [Any]
        var tmp = [Int]()
        while (queue.count>0){
            let node = queue.removeFirst();
            if let a = node as? String {
                if tmp.count>0 {
                    result.insert(tmp, at: 0);
                    tmp = [Int]()
                    queue.append("a")
                    continue;
                }
            } else {
                let treeNode = node as! TreeNode
                tmp.append(treeNode.val);
                if(treeNode.left != nil){
                    queue.append(treeNode.left!);
                }
                if(treeNode.right != nil){
                    queue.append(treeNode.right!);
                }
            }
            
        }
        return result;

      
        
    }
    
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        let root = self.helper(0, nums.count-1, nums)
        return root
    }
    func helper(_ left : Int, _ right :Int, _ nums: [Int]) -> TreeNode? {
        if left > right {
            return nil
        }
        
        let p = (left+right)/2
        let root = TreeNode(nums[p])
        root.left = helper(left, p-1, nums)
        root.right = helper(p+1, right, nums)
        return root
    }
    
    func isBalanced(_ root: TreeNode?) -> Bool {
        if root == nil {
            return true
        }
        
        return abs(height(root?.left)-height(root?.right)) < 2 && isBalanced(root?.left) && isBalanced(root?.right)
    }
    
    func height(_ root: TreeNode?) -> Int {
        if root == nil {
            return -1
        }
        
        return 1+max(height(root?.left), height(root?.right))
    }
    
    
    func minDepth(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0;
        }
        if root?.right == nil && root?.left == nil {
            return 1
        }
        var mDepth = INTPTR_MAX
        if root?.left != nil {
            mDepth = min(minDepth(root?.left), mDepth)
        }
        if root?.right != nil {
            mDepth = min(minDepth(root?.right), mDepth)
        }
        return mDepth+1
       }
    
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
        
        if root == nil {
            return false
        }
        var newSum = sum
        if root != nil {
            newSum = newSum-root!.val
        }
        if root?.right == nil && root?.left == nil  {
            return newSum == 0
        }
        return (hasPathSum(root?.left, newSum)) || (hasPathSum(root?.right, newSum))
        
      
        
    }
    
    func generate(_ numRows: Int) -> [[Int]] {
        var tmp = [Int]()
        var result = [[Int]]()
        if numRows == 1 {
            return [[1]]
        }
        if numRows == 2 {
            return [[1],[1,1]]
        }
        if numRows == 3 {
           return [[1],[1,1],[1,2,1]]
            
        }
        
        var n = 4
        while n <= numRows {
            tmp.append(1)
            var j = n
            while j-2 > 0 {
                if result.count == 0 {
                    result = [[1],[1,1],[1,2,1]]
                }
                let lastArray = result.last
                tmp.append(lastArray![n-j]+lastArray![n-j+1])
                j = j-1
            }
            n = n+1
            tmp.append(1)
            result.append(tmp)
            tmp.removeAll()
        }
        return result
    }
    func getRow(_ rowIndex: Int) -> [Int] {
        var nums = [Int]()
        var i = 1
        nums.append(1)
        while i <= rowIndex {
            nums.append(1)
            var j = i-1
            while j > 0 {
                nums[j] = nums[j] + nums[j-1]
                j = j-1
            }
            i = i+1
        }
    
        return nums
    }
    
    func maxProfit(_ prices: [Int]) -> Int {
        var profit = 0
        var minPrice = INTPTR_MAX
        for n in 0..<prices.count {
            if prices[n] < minPrice {
                minPrice = prices[n]
            } else if prices[n]-minPrice > profit {
                profit = prices[n]-minPrice
            }
        }
        return profit
        
    }
    func maxProfit2(_ prices: [Int]) -> Int {
        var profit = 0
        if prices.count>0 {
          for n in 1..<prices.count {
                    if prices[n]>prices[n-1] {
                        profit = profit + prices[n]-prices[n-1]
                    }
                }
        }
      
        return profit
        
       }
    
    func isPalindrome(_ s: String) -> Bool {
        if s.count > 0 {
            let newStr : String = s.deleteSpecialCharacters().lowercased()
            let tmpStr : String = String(newStr.reversed()).deleteSpecialCharacters()
            return newStr == tmpStr
        } else {
            return true
        }
    }
    func singleNumber(_ nums: [Int]) -> Int {
        
        var a = 0
        for n in 0..<nums.count {
          a = a ^ nums[n]
        }
        return a
    }
      
       
    

}

class MinStack {

    private var stack : [Int]
    private var min : Int
    /** initialize your data structure here. */
    init() {
        return self
    }
    
    func push(_ x: Int) {
        
    }
    
    func pop() {
        
    }
    
    func top() -> Int {
        
    }
    
    func getMin() -> Int {
        
    }
}

extension String {
    
    func findIndex(_ i: Int)->String {
        
        let index = self.index(self.startIndex, offsetBy: i)
        return String(self[index])
        
    }
    var removeAllSapce: String {
          return self.replacingOccurrences(of: " ", with: "", options: .literal, range: nil)
      }
    func deleteSpecialCharacters() -> String {
        let pattern: String = "[^a-zA-Z0-9\u{4e00}-\u{9fa5}]"
        let express = try! NSRegularExpression(pattern: pattern, options: .caseInsensitive)
        return express.stringByReplacingMatches(in: self, options: [], range: NSMakeRange(0, self.count), withTemplate: "")
    }
}

let s = Solution()
//print(s.countAndSay(4))
//print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
//print(s.plusOne([1,2,3]))
//print(s.addBinary("11", "1"))
//print(s.climbStairs(5))
let h1 = ListNode(1)
let h2 = ListNode(1)
let h3 = ListNode(2)
let h4 = ListNode(3)
let h5 = ListNode(3)
h1.next = h2
h2.next = h3
h3.next = h4
h4.next = h5
//print(s.deleteDuplicates(h1))
var a1 = [2,0]
var a2 = [1]
//print(s.merge(&a1, 1, a2, 1))

let t1 = TreeNode(3)
let t2 = TreeNode(9)
let t3 = TreeNode(20)
let t4 = TreeNode(15)
let t5 = TreeNode(7)
t1.left = t2
t1.right = t3
t3.left = t4
t3.right = t5
//print(s.levelOrderBottom(t1))
//print(s.maxDepth(t1))
let t6 = TreeNode(2)
let t7 = TreeNode(3)
t6.right = t7
//print(s.minDepth(t6))
print(s.getRow(4))
print(s.isPalindrome("A man, a plan, a canal: Panama"))
