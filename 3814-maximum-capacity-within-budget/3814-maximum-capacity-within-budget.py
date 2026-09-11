class Solution(object):
    def maxCapacity(self, costs, capacity, budget):
        """
        :type costs: List[int]
        :type capacity: List[int]
        :type budget: int
        :rtype: int
        """
        # 1. Combine costs and capacity, then sort by cost
        # We store them as tuples (cost, capacity)
        machines = sorted(zip(costs, capacity))
        
        # Extract sorted lists for easier access
        sorted_costs = [m[0] for m in machines]
        sorted_caps = [m[1] for m in machines]
        n = len(machines)
        
        # 2. Precompute Prefix Max Capacity
        # prefix_max[i] holds the maximum capacity among machines[0...i]
        prefix_max = [0] * n
        current_max = 0
        for i in range(n):
            current_max = max(current_max, sorted_caps[i])
            prefix_max[i] = current_max
            
        ans = 0
        
        # 3. Iterate through each machine and find its best partner
        for i in range(n):
            cost_i = sorted_costs[i]
            cap_i = sorted_caps[i]
            
            # Optimization: If the single machine is already too expensive,
            # we can stop, because all subsequent machines are even more expensive.
            if cost_i >= budget:
                break
            
            # Case A: Pick just this one machine
            ans = max(ans, cap_i)
            
            # Case B: Pick this machine + one other distinct machine
            # We need: cost_partner + cost_i < budget
            # Therefore: cost_partner < budget - cost_i
            remaining_budget = budget - cost_i
            
            # Use Binary Search to find the insertion point for remaining_budget
            # bisect_left gives the index of the first element >= remaining_budget.
            # Everything to the left of this index is strictly < remaining_budget.
            idx = bisect.bisect_left(sorted_costs, remaining_budget)
            
            # We are looking for a partner 'j'. To avoid using the same machine twice
            # and to avoid double counting pairs, we only look for partners to the LEFT (j < i).
            # The valid range of indices in sorted_costs is [0, idx - 1].
            # Combining with j < i, our valid range ends at min(i, idx) - 1.
            
            search_limit = min(i, idx) - 1
            
            if search_limit >= 0:
                # The best partner is simply the one with max capacity in the valid range
                best_partner_cap = prefix_max[search_limit]
                ans = max(ans, cap_i + best_partner_cap)
                
        return ans