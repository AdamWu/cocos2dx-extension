--[[
    A*寻路算法，目前只适用于 01图, 0可通行， 1不可通行
--]]

local heap = require("framework/core/bheap")

local function f_min(a,b)
    return a.f < b.f 
end

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

local min = math.min
local max = math.max
local abs = math.abs
local floor = math.floor

local AStar = {}

-- 地图、起始点、终点
function AStar:init(map, startPoint, endPoint, four_dir)
    self.startPoint = startPoint
    self.endPoint   = endPoint
    self.map        = map
    self.cost       = 10 -- 单位花费
    self.cost2      = 14 -- 对角线长
    self.open_list  = heap(f_min)
    --self.close_list = {}
    self.mapRows    = #map
    self.mapCols    = #map[1]
    self.four_dir   = four_dir -- 使用4方向的寻路还是八方向的寻路

    --print(table.inspect(self.map))

    self.nodes = {}
    for i = 1, self.mapRows do
        for j = 1, self.mapCols do
            table.insert(self.nodes, 
            {
                father = nil,
                row = i,
                col = j,
                g = 0, 
                h = 0,
                f = 0,
                state = 0,   -- 0: 1:open 2:closed
            })
        end
    end
end

-- begin with 1
function AStar:getIndex(row, col)
	return (row-1)*self.mapCols + col
end

-- begin with 1
function AStar:getRowAndColByIndex(index)
	local row = floor((index-1)/self.mapCols)
	return row+1, index - row * self.mapCols
end

-- 搜索路径 ,核心代码
function AStar:searchPath()
    -- 验证终点是否为阻挡，如果为阻挡，则直接返回空路径
    if self.map[self.endPoint.row][self.endPoint.col] ~= 0 then
    	print("error end point, can not reach!")
        return nil
    end

    -- 把第一节点加入
    local idx = self:getIndex(self.startPoint.row, self.startPoint.col)
    self.open_list:push(self.nodes[idx])
    
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
    while not self.open_list:empty() do
        -- check
        local node = self.open_list:pop()
        node.state = 2

        if node.row == self.endPoint.row and node.col == self.endPoint.col then
            -- 找到路径
            return self:buildPath(node)
        end

        for i = 1, #dir do
            local row = node.row + dir[i][1]
            local col = node.col + dir[i][2]
            local idx = self:getIndex(row, col)

            if check(row, col) then
                local g, h, f = self:getCost(node, row, col, (row ~= node.row and col ~= node.col))
                local newNode = self.nodes[idx]

                if newNode.state == 0 then
                    -- add new node
                    newNode.father = node
                    newNode.g = g
                    newNode.h = h
                    newNode.f = f
                    newNode.state = 1
    				self.open_list:push(newNode)
                elseif newNode.state == 1 then
                    -- alreay in openlist
                    if newNode.f > f then
                        -- a better way then update 
                        newNode.father = node
                        newNode.g = g
                        newNode.h = h
                        newNode.f = f
                    end
                else
                    -- in closelist
                end
            end
        end
    end

    -- 不存在路径
    print("not available!")
    return nil 
end

function AStar:getCost(father, row, col, isdiag)
    local g, h

    if isdiag then
        g = father.g + self.cost2
    else 
        g = father.g + self.cost
    end

    -- 估计值h
    if self.four_dir then
        h = self:manhattan(row, col)
    else
        h = self:diagonal(row, col)
    end

    return g, h, (g+h)
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
    local h = abs(row - self.endPoint.row) + abs(col - self.endPoint.col)
    return h * self.cost
end

-- 对角线估价法,先按对角线走，一直走到与终点水平或垂直平行后，再笔直的走
function AStar:diagonal(row, col)
    local dx = abs(row - self.endPoint.row)
    local dy = abs(col - self.endPoint.col)
    local minD = min(dx, dy)
    return minD * self.cost2 + (dx + dy - 2 * minD) * self.cost
end

return AStar