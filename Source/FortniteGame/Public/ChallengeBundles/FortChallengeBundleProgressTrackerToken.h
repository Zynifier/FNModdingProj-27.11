// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortChallengeBundleProgressTrackerToken.generated.h"

USTRUCT()
struct FObjectivePartialCompletionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ObjectiveName;

	UPROPERTY()
	int32 CompletionCount;

};

USTRUCT()
struct FChallengePartialCompletionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString QuestTemplateId;

	UPROPERTY()
	TArray<FObjectivePartialCompletionData> ObjectivData;

};

UCLASS()
class UFortChallengeBundleProgressTrackerToken : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleProgressTrackerToken")
	EItemProfileType ProfileType;

};

