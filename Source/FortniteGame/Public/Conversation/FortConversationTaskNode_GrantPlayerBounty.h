// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationTaskNode_GrantStaticQuest.h"
#include "FortConversationTaskNode_GrantPlayerBounty.generated.h"

class UFortUrgentQuestItemDefinition;

UCLASS(Abstract, BlueprintType)
class UFortConversationTaskNode_GrantPlayerBounty : public UFortConversationTaskNode_GrantStaticQuest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(AssetBundles="Equipped", DisplayName="Target Quest To Grant"))
	TSoftObjectPtr<UFortUrgentQuestItemDefinition> TargetQuestToGrantPtr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FGameplayTagQuery TargetFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat Price;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat NumberOfPlayersToSelectFrom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat MediumThreatRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat HighThreatRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat ThreatRefreshRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(HideInConversationNode))
	FScalableFloat AllowPoaching;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(AssetBundles="Equipped", DisplayName="Protector Quest To Grant"))
	TSoftObjectPtr<UFortUrgentQuestItemDefinition> ProtectorQuestToGrantPtr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Bounty", meta=(AssetBundles="Equipped", DisplayName="Poached Quest To Grant"))
	TSoftObjectPtr<UFortUrgentQuestItemDefinition> PoachedQuestToGrantPtr;

};

