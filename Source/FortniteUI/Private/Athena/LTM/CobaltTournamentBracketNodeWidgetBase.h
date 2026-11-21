// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltTournamentBracketNodeWidgetBase.generated.h"

enum class EBracketNodeState : uint8;

UENUM(BlueprintType)
enum class EBracketNodeState : uint8
{
	LocalTeam = 0,
	// represents the local player's team's current position in the bracket

	EnemyTeam = 1,
	// represents the enemy team's current position in the bracket

	Neutral = 2,
};

UCLASS()
class UCobaltTournamentBracketNodeWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleBracketNodeStateSet_BP(EBracketNodeState NewState);

	UPROPERTY(BlueprintReadOnly, Category="CobaltTournamentBracketNodeWidgetBase")
	EBracketNodeState CurrentBracketNodeState;

};

