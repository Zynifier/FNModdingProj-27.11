// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestTools/FortQuestToolTemplatesLibrary.h"

TMap<FName, FFortQuestToolTemplatesRow> UFortQuestToolTemplatesLibrary::GetQuestTemplateNamesFromTableForType(const UDataTable* QuestTemplatesTable, const FName QuestTemplateTypeName)
{
	return TMap<FName, FFortQuestToolTemplatesRow>();
}

TArray<FFortQuestToolTemplatesRowDataPair> UFortQuestToolTemplatesLibrary::GetQuestTemplateRowsBySeasonNumber(const UDataTable* QuestTemplatesTable, const int32 SeasonNum)
{
	return TArray<FFortQuestToolTemplatesRowDataPair>();
}

UFortQuestItemDefinition* UFortQuestToolTemplatesLibrary::LoadQuestTemplateFromRow(const FFortQuestToolTemplatesRow& RowData)
{
	return nullptr;
}

UFortQuestItemDefinition* UFortQuestToolTemplatesLibrary::LoadQuestTemplateFromTableByRowName(const UDataTable* QuestTemplatesTable, const FName TemplateRowName)
{
	return nullptr;
}

UFortQuestItemDefinition* UFortQuestToolTemplatesLibrary::LoadQuestTemplateFromTableBySeasonAndType(const UDataTable* QuestTemplatesTable, const int32 SeasonNum, const FName QuestTemplateTypeName)
{
	return nullptr;
}
