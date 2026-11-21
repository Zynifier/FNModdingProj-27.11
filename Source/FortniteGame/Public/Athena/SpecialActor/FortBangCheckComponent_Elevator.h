// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/SpecialActor/FortEventLevelNavigationBangCheckComponent.h"
#include "FortBangCheckComponent_Elevator.generated.h"

class UFortChallengeBundleItemDefinition;
class UFortQuestItemDefinition;

USTRUCT()
struct FBangCheckData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BangCheckData")
	TObjectPtr<UFortQuestItemDefinition> AlterQuest;

	UPROPERTY(EditAnywhere, Category="BangCheckData")
	TObjectPtr<UFortQuestItemDefinition> EgoQuest;

	UPROPERTY(EditAnywhere, Category="BangCheckData")
	TObjectPtr<UFortChallengeBundleItemDefinition> BundleSeeRoom;

	UPROPERTY(EditAnywhere, Category="BangCheckData")
	FGameplayTag IntroTag;

	UPROPERTY(EditAnywhere, Category="BangCheckData")
	FGameplayTag RoomBangTag;

};

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortBangCheckComponent_Elevator : public UFortEventLevelNavigationBangCheckComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortBangCheckComponent_Elevator")
	TArray<FBangCheckData> ABChoiceQuests;

};

