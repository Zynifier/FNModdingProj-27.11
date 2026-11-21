// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationTaskNode_GrantStaticQuest.h"
#include "FortConversationTaskNode_GrantPlayerDuel.generated.h"

UCLASS(Abstract, BlueprintType)
class UFortConversationTaskNode_GrantPlayerDuel : public UFortConversationTaskNode_GrantStaticQuest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Duel", meta=(HideInConversationNode))
	FGameplayTagQuery TargetFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Duel", meta=(HideInConversationNode))
	FScalableFloat NumberOfPlayersToSelectFrom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Duel", meta=(HideInConversationNode))
	FScalableFloat MediumThreatRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Duel", meta=(HideInConversationNode))
	FScalableFloat HighThreatRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Duel", meta=(HideInConversationNode))
	FScalableFloat ThreatRefreshRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Duel", meta=(HideInConversationNode))
	FScalableFloat AllowPoaching;

};

