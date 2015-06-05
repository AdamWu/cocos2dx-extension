local Util = {}

function Util:bytesToString(bytes)
	local s = {}
 	for i=1, table.getn(bytes) do
		if bytes[i] > 0 then
			table.insert(s, string.char(bytes[i]))
		end
	end
  	return table.concat(s)
end

-- [_begin, _end]内随机产生不同数
function random_diff(_begin, _end, num)
	if num > _end - _begin + 1 then return nil end

	local t = {}
	while(true) do
		if #t >= num then break end

		local r = math.random(_begin, _end)
		local bHas = false
		for k, v in ipairs(t) do
			if v == r then
				bHas = true
				break
			end
		end
		if not bHas then
			table.insert(t, r)
		end
	end

	return t
end

return Util