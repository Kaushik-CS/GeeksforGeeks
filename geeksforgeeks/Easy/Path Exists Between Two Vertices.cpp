
class Solution:
    def checkPath(self, adj, u, v):
        visited = [False] * len(adj)

        def dfs(node):
            if node == v:
                return True

            visited[node] = True

            for neighbor in adj[node]:
                if not visited[neighbor]:
                    if dfs(neighbor):
                        return True

            return False

        return dfs(u)
