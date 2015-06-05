--[[
	common func init
--]]

-----------------------------------------------------------
-- get the num of all elements in a table
-----------------------------------------------------------
function table.maxlen(t)   
	local count = 0
	for _ in pairs(t) do count = count + 1 end
	return count
end
table.count = table.maxlen

-----------------------------------------------------------
-- map all elements in func
-----------------------------------------------------------
function table.map(t, func)
	for k, v in pairs(t) do t[k] = func(v) end
	return t
end

-----------------------------------------------------------
-- map all sorted elements in func
-----------------------------------------------------------
function table.imap(t, func)
	for i, v in ipairs(t) do t[i] = func(v) end
	return t
end

-----------------------------------------------------------
-- copy of a table
-----------------------------------------------------------
function table.copy(t)
	local ret = {}
	for k, v in pairs(t) do ret[k] = v end
	return setmetatable(ret, getmetatable(t))
end

-----------------------------------------------------------
-- deep copy of a table
-----------------------------------------------------------
function table.dcopy(t)
	local ret = {}
	for k,v in pairs(t) do 
		if( type(v) == "table" ) then
			ret[k] = table.deepCopy(v)
		else
			ret[k] = v
		end		
	end
	return setmetatable(ret, getmetatable(t))
end

-----------------------------------------------------------
-- merge all elements in two tables
-----------------------------------------------------------
function table.merge(a, b, overwrite)
	for k, v in pairs(b) do
	if not a[k] or overwrite then a[k] = v end      
	end

	return a
end

-----------------------------------------------------------
-- merge all sorted elements in two tables
-----------------------------------------------------------
function table.append(a, b)
	for _, v in ipairs(b) do a[#a + 1] = v end

	return a
end

-----------------------------------------------------------
-- reverse all sorted elements in a table
-----------------------------------------------------------
function table.reverse(t)
	local len = #t + 1

	for i = 1, math.floor(#t / 2) do
		t[i], t[len - i] = t[len - i], t[i]
	end

	return t
end

-----------------------------------------------------------
-- splicing: remove elements from a table
-----------------------------------------------------------
function table.splice(tbl, start, length)
	length = length or 1
	start = start or 1
	local endd = start + length
	local spliced = {}
	local remainder = {}
	for i,elt in ipairs(tbl) do
	  if i < start or i >= endd then
	     table.insert(spliced, elt)
	  else
	     table.insert(remainder, elt)
	  end
	end
	return spliced, remainder
end


-----------------------------------------------------------
-- split a string using a pattern
-----------------------------------------------------------
function string.split(str, delimiter)
    if (delimiter=='') then return false end
    local pos,arr = 0, {}
    -- for each divider found
    for st,sp in function() return string.find(str, delimiter, pos, true) end do
        table.insert(arr, string.sub(str, pos, st - 1))
        pos = sp + 1
    end
    table.insert(arr, string.sub(str, pos))
    return arr
end

-----------------------------------------------------------
-- split a string using a pattern
-----------------------------------------------------------
function string.split2(str, delimiter)
    local arr = {}
    string.gsub(str, '[^' .. delimiter ..']+', function(w) table.insert(arr, w) end )
    return arr
end

-----------------------------------------------------------
-- get length of a string in utf8
-----------------------------------------------------------
function string.utf8len(str)
    local len  = #str
    local left = len
    local cnt  = 0
    local arr  = {0, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc}
    while left ~= 0 do
        local tmp = string.byte(str, -left)
        local i   = #arr
        while arr[i] do
            if tmp >= arr[i] then
                left = left - i
                break
            end
            i = i - 1
        end
        cnt = cnt + 1
    end
    return cnt
end


-------------------------------------------------------------
-- fill string with 0
-------------------------------------------------------------
function string.zfill(str, n)
	if not str then return nil, "the string is nil" end

	if n == nil then return str end

	return string.format("%0"..n.."s", str)
end


