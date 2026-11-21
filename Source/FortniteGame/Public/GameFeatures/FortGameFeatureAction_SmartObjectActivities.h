// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "ScalableFloat.h"
#include "FortGameFeatureAction_SmartObjectActivities.generated.h"

class APawn;
class UFortAthenaAISmartObjectActivity;

USTRUCT()
struct FGameFeatureSmartObjectActivityInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SmartObject", meta=(AllowAbstract="True"))
	TSoftClassPtr<APawn> TargetPawn;

	UPROPERTY(EditDefaultsOnly, Category="SmartObject")
	uint8 bAllowChildOf : 1;

	UPROPERTY(EditDefaultsOnly, Category="SmartObject", meta=(AllowPrivateAccess="true"))
	TArray<TSoftClassPtr<UFortAthenaAISmartObjectActivity>> SmartObjectActivitiesToAdd;

	UPROPERTY(EditDefaultsOnly, Category="SmartObject")
	FScalableFloat Enabled;

};

UCLASS(MinimalAPI, meta=(DisplayName="SmartObject : Add Activities for AI"))
class UFortGameFeatureAction_SmartObjectActivities : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnAIPawnSpawned(APawn* Pawn, const int32 RequestID);

	UPROPERTY(EditAnywhere, Category="SmartObject")
	TArray<FGameFeatureSmartObjectActivityInfo> SmartObjectActivitiesInfo;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UFortAthenaAISmartObjectActivity>> SmartObjectActivitiesLoaded;

};

