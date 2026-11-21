// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortLeaderboardContext.generated.h"

UCLASS()
class FORTNITEUI_API UFortLeaderboardContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Leaderboards")
	bool CanShowGlobalLeaderboards() const;

	UFUNCTION(BlueprintPure, Category="Leaderboards")
	bool CanShowLeaderboards() const;

	UFUNCTION(BlueprintPure, Category="Stats")
	bool CanShowStats() const;

};

