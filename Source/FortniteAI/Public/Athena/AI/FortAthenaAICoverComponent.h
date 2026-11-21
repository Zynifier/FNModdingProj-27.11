// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Math/MathFwd.h"
#include "FortAthenaAICoverComponent.generated.h"

class AAIController;
class ABuildingActor;
class UNavigationQueryFilter;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortAthenaAICoverComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortAthenaAICoverComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAICoverComponent", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> CoverPositionFilterClass;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FVector CoverBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	float CoverOffset;

private:
	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedController;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingActor> LastBuildingActorUsedForCover;

};

