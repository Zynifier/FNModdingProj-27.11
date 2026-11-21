// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "ServerRollQuestTypes.generated.h"

class IQuestDefinitionInterface;

USTRUCT(BlueprintType)
struct FServerRollQuestTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ServerRollQuestTableRow")
	TScriptInterface<IQuestDefinitionInterface> Quest;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FPrimaryAssetId QuestPAID;
#endif

	UPROPERTY(EditAnywhere, Category="ServerRollQuestTableRow")
	FGameplayTag Bucket;

	UPROPERTY(EditAnywhere, Category="ServerRollQuestTableRow")
	float Weight;

	UPROPERTY(EditAnywhere, Category="ServerRollQuestTableRow")
	FGameplayTagQuery PlaylistQuery;

};

