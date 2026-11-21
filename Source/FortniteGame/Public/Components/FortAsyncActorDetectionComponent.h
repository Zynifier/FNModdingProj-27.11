// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/EngineTypes.h"
#include "ScalableFloat.h"
#include "FortAsyncActorDetectionComponent.generated.h"

class AActor;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDetectActor, AActor*, DetectedActor, FGameplayAbilityTargetDataHandle, TargetData);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortAsyncActorDetectionComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortAsyncActorDetectionComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintAssignable)
	FOnDetectActor OnDetectActor;

	UPROPERTY(EditAnywhere, Category="FortAsyncActorDetectionComponent")
	TEnumAsByte<ECollisionChannel> CollisionChannel;

	UPROPERTY(EditAnywhere, Category="FortAsyncActorDetectionComponent")
	TArray<TSubclassOf<UObject>> ClassesToConsider;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortAsyncActorDetectionComponent")
	TArray<TObjectPtr<AActor>> RecentlyDetectedActors;

	UPROPERTY(EditAnywhere, Category="FortAsyncActorDetectionComponent")
	FScalableFloat MinimumSpeedToTrigger;

	UPROPERTY(EditAnywhere, Category="FortAsyncActorDetectionComponent")
	float TraceLength;

};

