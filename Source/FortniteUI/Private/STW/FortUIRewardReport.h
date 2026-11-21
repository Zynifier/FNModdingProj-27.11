// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortUIRewardReport.generated.h"

class UFortLocalPlayer;

UCLASS(BlueprintType)
class UFortUIRewardReport : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Reward Report")
	int32 GetRewardedChestIndex() const;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> LocalPlayer;

	UPROPERTY(Transient)
	int32 RewardDisplayLevel;

};

