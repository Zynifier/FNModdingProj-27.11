// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortVisibilityComponent.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EFortVisibilityBehavior : uint8
{
	Proximity = 0,
	// Radius based distance checks w/ LOS/Facing optional

	OnceSeenAlwaysSeen = 1,
	// Proximity based with memory about which teams seen me

	AlwaysSeen = 2,
	// Always seen

	Invalid = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVisibilityChanged, AActor*, Actor, uint8, TeamObserving, bool, bVisible);

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UFortVisibilityComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility")
	uint8 bRegisterWithVisibilityManager : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility", meta=(EditCondition="bRegisterWithVisibilityManager"))
	uint8 bObserver : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility", meta=(EditCondition="bRegisterWithVisibilityManager"))
	uint8 bDistanceCheck2D : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility", meta=(EditCondition="bRegisterWithVisibilityManager"))
	uint8 bCheckFacing : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility", meta=(EditCondition="bRegisterWithVisibilityManager"))
	uint8 bCheckLOS : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility", meta=(EditCondition="bRegisterWithVisibilityManager"))
	uint8 bRevealWithMap : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visibility", meta=(EditCondition="bRegisterWithVisibilityManager"))
	EFortVisibilityBehavior VisibilityBehavior;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnVisibilityChanged OnVisibilityChangedEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VisibleDistance", meta=(EditCondition="bRegisterWithVisibilityManager"))
	float Radius;

};

