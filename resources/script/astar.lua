--[[
    A*寻路算法，目前只适用于 01图, 0可通行， 1不可通行
--]]

-- 行走的4个方向
local four_dir = {
    {1, 0},
    {0, 1},
    {0, -1},
    {-1, 0},
}

-- 行走的8个方向
local eight_dir = {
    {1, 1},
    {1, 0},
    {1, -1},
    {0, 1},
    {0, -1},
    {-1, 1},
    {-1, 0},
    {-1, -1}
}

local AStar = {}

-- 地图、起始点、终点
function AStar:init(map, startPoint, endPoint, four_dir)
    self.startPoint = startPoint
    self.endPoint   = endPoint
    self.map        = map
    self.cost       = 10 -- 单位花费
    self.cost2      = 14 -- 对角线长
    self.open_list  = {}
    self.close_list = {}
    self.mapRows    = #map
    self.mapCols    = #map[1]
    self.four_dir   = four_dir -- 使用4方向的寻路还是八方向的寻路

    --print(table.inspect(self.map))
end

-- 搜索路径 ,核心代码
function AStar:searchPath()
    -- 验证终点是否为阻挡，如果为阻挡，则直接返回空路径
    if self.map[self.endPoint.row][self.endPoint.col] ~= 0 then
    	print("error end point, can not reach!")
        return nil
    end

    -- 把第一节点加入
    local startNode = {}  
    startNode.row = self.startPoint.row
    startNode.col = self.startPoint.col
    startNode.g = 0
    startNode.h = 0
    startNode.f = 0
    table.insert(self.open_list, startNode)
    
    -- 检查边界、障碍点 
    local check = function(row, col)
        if 1 <= row and row <= self.mapRows and 1 <= col and col <= self.mapCols then
            if self.map[row][col] == 0 or (row == self.endPoint.row and col == self.endPoint.col) then
                return true
            end
        end

        return false
    end

    local dir = self.four_dir and four_dir or eight_dir
    while table.count(self.open_list) > 0 do
        local node = self:getMinNode()
        if node.row == self.endPoint.row and node.col == self.endPoint.col then
            -- 找到路径
            return self:buildPath(node)
        end

        for i = 1, #dir do
            local row = node.row + dir[i][1]
            local col = node.col + dir[i][2]
            if check(row, col) then
                local curNode = self:getFGH(node, row, col, (row ~= node.row and col ~= node.col))
                local openNode, openIndex = self:nodeInOpenList(row, col)
                local closeNode, closeIndex = self:nodeInCloseList(row, col)

                if not openNode and not closeNode then
                    -- 不在OPEN表和CLOSE表中
                    -- 添加特定节点到 open list
                    table.insert(self.open_list, curNode)
                elseif openNode then
                    -- 在OPEN表
                    if openNode.f > curNode.f then
                        -- 更新OPEN表中的估价值
                        self.open_list[openIndex] = curNode
                    end
                else
                    -- 在CLOSE表中
                    if closeNode.f > curNode.f then
                        table.insert(self.open_list, curNode)
                        table.remove(self.close_list, closeIndex)
                    end
                end
            end
        end

        -- 节点放入到 close list 里面
        table.insert(self.close_list, node)
    end

    -- 不存在路径
    print("not available!")
    return nil 
end

-- 获取 f ,g ,h, 最后参数是否对角线走
function AStar:getFGH(father, row, col, isdiag)
    local node = {}
    local cost = self.cost
    if isdiag then
        cost = self.cost2
    end

    node.father = father
    node.row = row
    node.col = col
    node.g = father.g + cost
    -- 估计值h
    if self.four_dir then
        node.h = self:manhattan(row, col)
    else
        node.h = self:diagonal(row, col)
    end
    node.f = node.g + node.h  -- f = g + h 
    return node
end


-- 判断节点是否已经存在 open list 里面
AStar.nodeInOpenList = function(self, row, col)
    for i = 1, #self.open_list do
        local node = self.open_list[i]
        if node.row == row and node.col == col then
            return node, i   -- 返回节点和下标
        end
    end

    return nil
end

-- 判断节点是否已经存在 close list 里面
AStar.nodeInCloseList = function(self, row, col)
    for i = 1, #self.close_list do
        local node = self.close_list[i]
        if node.row == row and node.col == col then
            return node, i
        end
    end

    return nil
end

-- 在open_list中找到最佳点,并删除
AStar.getMinNode = function(self)
    if #self.open_list < 1 then
        return nil
    end

    local min_node = self.open_list[1]
    local min_i = 1
    for i,v in ipairs(self.open_list) do
        if min_node.f > v.f then
            min_node = v
            min_i = i
        end
    end

    table.remove(self.open_list, min_i)
    return min_node
end

-- 计算路径
function AStar:buildPath(node)
	print("AStar.buildPath")
    local path = {}
    local sumCost = node.f -- 路径的总花费
    while node do
        path[#path + 1] = {row = node.row, col = node.col}
        node = node.father
    end

    return path, sumCost
end

-- 估价h函数
-- 曼哈顿估价法（用于不能对角行走）
function AStar:manhattan(row, col)  
    local h = math.abs(row - self.endPoint.row) + math.abs(col - self.endPoint.col)
    return h * self.cost
end

-- 对角线估价法,先按对角线走，一直走到与终点水平或垂直平行后，再笔直的走
function AStar:diagonal(row, col)
    local dx = math.abs(row - self.endPoint.row)
    local dy = math.abs(col - self.endPoint.col)
    local minD = math.min(dx, dy)
    return (dx + dy - 2 * minD) * self.cost + minD * self.cost2
end

return AStar