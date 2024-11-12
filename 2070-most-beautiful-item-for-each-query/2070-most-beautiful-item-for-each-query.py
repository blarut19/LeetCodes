class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        ans = [0] * len(queries)
        # Sort by beauty decreasing, then by price increasing.
        items = sorted(items, key=lambda item: item[1], reverse=True)
        items = sorted(items, key=lambda item: item[0])
        # Find redundant items. Redundant items are items such that there exists an item that is cheaper but is more beautiful.
        max_beauty = items[0][1]
        to_leave = []
        for i, item in enumerate(items):
            price, beauty = item
            if max_beauty <= beauty:
                to_leave.append(i)
                max_beauty = beauty
        # Get rid of redundant items.
        items = [items[i] for i in to_leave]
        # Find the most expensive item for each query. Previous steps gurantee that such item is the most beaufitul.
        for i, query in enumerate(queries):
            max_beauty = 0
            for item in items:
                if query < item[0]:
                    break
                max_beauty = max(item[1], max_beauty)
            ans[i] = max_beauty
        return ans