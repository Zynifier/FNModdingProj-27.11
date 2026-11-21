// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortQuestItemDefinition_Athena.h"

EFortQuestSubtype UFortQuestItemDefinition_Athena::GetQuestSubtype() const
{
	return EFortQuestSubtype();
}

TSoftObjectPtr<UFortTandemCharacterData> UFortQuestItemDefinition_Athena::GetSoftTandemCharacterData() const
{
	return TSoftObjectPtr<UFortTandemCharacterData>();
}

UFortTandemCharacterData* UFortQuestItemDefinition_Athena::GetTandemCharacterData() const
{
	return nullptr;
}
