// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortChallengeBundleScheduleItem.generated.h"

class UFortChallengeBundleScheduleDefinition;

UCLASS(Transient, MinimalAPI, BlueprintType)
class UFortChallengeBundleScheduleItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	void GetAchievedCount(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle")
	float GetPercentageComplete() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundle", meta=(DisplayName="Get Schedule Definition"))
	UFortChallengeBundleScheduleDefinition* GetScheduleDefinitionBP() const;

private:
	UPROPERTY()
	TArray<FString> Granted_Bundles;

};

