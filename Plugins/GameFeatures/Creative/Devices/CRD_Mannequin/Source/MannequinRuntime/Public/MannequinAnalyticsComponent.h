// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MannequinAnalyticsComponent.generated.h"

class AFortPlayerController;
class UFortItemDefinition;
enum class ECreativeMannequinAnalyticsInteractType : uint8;

UENUM(BlueprintType)
enum class ECreativeMannequinAnalyticsInteractType : uint8
{
	/** Player equipped a skin from the mannequin */
	Equip = 0,
	/** Player opened the store from the mannequin */
	OpenStore = 1,
};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class MANNEQUINRUNTIME_API UMannequinAnalyticsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	virtual void FireMannequinAnalytics_Interact(AFortPlayerController* Controller, const ECreativeMannequinAnalyticsInteractType InteractType, const UFortItemDefinition* Character, const UFortItemDefinition* BackBling) const;

};

