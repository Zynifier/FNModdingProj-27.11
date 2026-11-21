// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FortStormShieldComponent.generated.h"

class AActor;
class AFortMissionStormShield;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStormShieldStatusChanged, bool, bInStorm);

UCLASS(BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("StormShield"), meta=(BlueprintSpawnableComponent))
class UFortStormShieldComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Storm Shield")
	FOnStormShieldStatusChanged OnStormShieldStatusChanged;

	UPROPERTY(Replicated)
	bool bCareAboutEdgeOfStorm;

protected:
	UFUNCTION()
	void OwnerDestroyed(AActor* InOwner);

	UFUNCTION()
	void StormShieldCreated(AFortMissionStormShield* Shield);

	UFUNCTION()
	void StormShieldDestroyed(AActor* DestroyedActor);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm Shield")
	bool bDisabled;

	UPROPERTY(EditDefaultsOnly, Category="Storm Shield", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float DistanceFromEdgeOfStormShield;

};

