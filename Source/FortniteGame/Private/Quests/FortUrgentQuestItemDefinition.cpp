// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortUrgentQuestItemDefinition.h"

const FUrgentQuestData& UFortUrgentQuestItemDefinition::GetUrgentQuestData() const
{
	static FUrgentQuestData Dummy;
	return Dummy;
}
