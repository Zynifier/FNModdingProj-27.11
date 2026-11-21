// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortRequirementsInfo.generated.h"

class UFortItemDefinition;
class UFortQuestItemDefinition;

USTRUCT(BlueprintType)
struct FFortRequirementsInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo")
	int32 CommanderLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo", meta=(DisplayName="Min Personal Power Rating"))
	int32 PersonalPowerRating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo")
	int32 MaxPersonalPowerRating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo", meta=(DisplayName="Min Party Power Rating"))
	int32 PartyPowerRating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo")
	int32 MaxPartyPowerRating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo")
	TArray<TObjectPtr<UFortQuestItemDefinition>> ActiveQuestDefinitions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo", meta=(DisplayName="CompletedQuestDefinition"))
	TObjectPtr<UFortQuestItemDefinition> QuestDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRequirementsInfo", meta=(DisplayName="CompletedQuestObjectiveStatHandle"))
	FDataTableRowHandle ObjectiveStatHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortRequirementsInfo")
	TObjectPtr<UFortQuestItemDefinition> UncompletedQuestDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRequirementsInfo")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRequirementsInfo")
	FString EventFlag;

};

