// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Building/BuildingWeakSpot.h"
#include "Building/FortWeakPointProviderInterface.h"
#include "FortWeakPointComponent.generated.h"

class UFortWeakPointComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortWeakPointHit, const FVector&, HitLocation, const FVector&, HitNormal);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FShouldKillWeakSpotDynamic, const UFortWeakPointComponent*, WeakPointComponent, const FBuildingWeakSpotData&, WeakSpotData);

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeakPointComponent : public USceneComponent, public IFortWeakPointProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable, Category="Building")
	void NetMulticast_HandleOwnerDamaged(FGameplayTag MatchingTag, const FGameplayEventData Payload);

	UFUNCTION(BlueprintCallable)
	void SetWeakPointsEnabled(bool bEnabled);

	UPROPERTY(BlueprintAssignable)
	FFortWeakPointHit OnWeakPointHit;

	UPROPERTY(BlueprintReadWrite, Category="FortWeakPointComponent")
	FShouldKillWeakSpotDynamic ShouldKillWeakSpotDynamic;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EPhysicalSurface> PrimarySurfaceType;

	UPROPERTY(EditDefaultsOnly, Category="FortWeakPointComponent")
	bool bUseComplexForWeakSpots;

	UPROPERTY(EditDefaultsOnly, Category="FortWeakPointComponent")
	bool bWeakPointsEnabled;

};

