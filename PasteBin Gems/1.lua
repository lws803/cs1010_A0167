function onStepIn(cid, item, position, fromPosition)
	local config = {
		level = 30,
		shrines = {
			[7704] = {p = {x=1293, y=1380, z=7}, v = {2, 6}, m = "druid"},
			[7705] = {p = {x=1249, y=1380, z=7}, v = {2, 6}, m = "druid"},
			[7706] = {p = {x=1265, y=1431, z=7}, v = {1, 5}, m = "sorcerer"},
			[7707] = {p = {x=1276, y=1362, z=7}, v = {1, 5}, m = "sorcerer"},
			[7708] = {p = {x=999, y=993, z=7}, v = getPlayerVocation(cid)}
		}
	}
	if(config.shrines[item.actionid]) then
		if(isInArray(config.shrines[item.actionid].v, getPlayerVocation(cid)) == false or getPlayerLevel(cid) < config.level or isPremium(cid) == false) then
			doPlayerSendCancel(cid, "Only premium " .. config.shrines[item.actionid].m .. "s of level " .. config.level .. " or higher are able to enter this portal.")
			doTeleportThing(cid, fromPosition, true)
			return true
		end
		
		doTeleportThing(cid, config.shrines[item.actionid].p)
		doSendMagicEffect(config.shrines[item.actionid].p, CONST_ME_TELEPORT)
		doSendMagicEffect(fromPosition, CONST_ME_POFF)
	end
	return true
end