// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "Components/FortWeaponComponent.h"
#include "KatanaTargetingComponent.generated.h"

class AActor;
class ABuildingActor;
class UFortGameplayAbility;
class UGameplayAbility;
enum class EFortKatanaPrimaryAttackVariation : uint8;

UENUM(BlueprintType)
enum class EFortKatanaPrimaryAttackVariation : uint8
{
	// The first strike in the on ground primary attack sequence

	OnGroundFirst = 0,
	// The second strike in the on ground primary attack sequence

	OnGroundSecond = 1,
	// The primary attack that occurs just after the player touches the ground after an in air strike

	InAir = 2,
};

USTRUCT(BlueprintType)
struct FFortKatanaDashTargetingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortKatanaDashTargetingInfo")
	FVector DashDirection;

	UPROPERTY(BlueprintReadOnly, Category="FortKatanaDashTargetingInfo")
	float DashDistance;

	UPROPERTY(BlueprintReadOnly, Category="FortKatanaDashTargetingInfo")
	TWeakObjectPtr<AActor> DashBlockingActor;

	UPROPERTY(BlueprintReadOnly, Category="FortKatanaDashTargetingInfo")
	bool bWasDashDirectionAdjusted;

	UPROPERTY(BlueprintReadOnly, Category="FortKatanaDashTargetingInfo")
	TArray<AActor*> DamagedActors;

	UPROPERTY(BlueprintReadOnly, Category="FortKatanaDashTargetingInfo")
	float OutOfRangePercent;

};

USTRUCT(BlueprintType)
struct FFortKatanaPrimaryAttackVariationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortKatanaPrimaryAttackVariationInfo")
	FScalableFloat Range;

	UPROPERTY(EditDefaultsOnly, Category="FortKatanaPrimaryAttackVariationInfo")
	FScalableFloat OffsetFromTarget;

	UPROPERTY(EditDefaultsOnly, Category="FortKatanaPrimaryAttackVariationInfo")
	FFortAbilityTargetSelectionList TargetSelectionList;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UKatanaTargetingComponent : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Katana|Dash")
	bool PerformDashTargeting(FFortKatanaDashTargetingInfo& OutDashTargetingInfo);

	UFUNCTION(BlueprintCallable, Category="Katana|Primary Attack")
	FVector PerformPrimaryAttackTargeting(const EFortKatanaPrimaryAttackVariation AttackVariation);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	TSubclassOf<UGameplayAbility> KatanaTechniqueAbilityClass;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FScalableFloat DashDistance;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FScalableFloat AdditionalDashForwardAttackRange;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FScalableFloat AdditionalOutOfRangeDetection;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FScalableFloat DashOffsetFromTarget;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FScalableFloat PropRemainingHealthToDestroy;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FScalableFloat BuildingRemainingHealthToDestroy;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FGameplayTagContainer DashBlockingBuildingTags;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	TSet<TSubclassOf<ABuildingActor>> DashBlockingBuildingClasses;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FFortAbilityTargetSelectionList PawnTargetSelectionList;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	TEnumAsByte<ECollisionChannel> DashTraceChannel;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	float ObstructionOverlapBoxHalfSize;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FFortTargetFilter ObstructionTargetFilter;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	FGameplayTagContainer DashBlockIgnoreTags;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Katana|Dash")
	bool bDebugDashTraces;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Katana|Primary Attack")
	TMap<EFortKatanaPrimaryAttackVariation, FFortKatanaPrimaryAttackVariationInfo> PrimaryAttackVariationInfos;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Primary Attack")
	float PrimaryAttackMinForwardMovement;

	UPROPERTY(EditDefaultsOnly, Category="Katana|Primary Attack")
	TEnumAsByte<ECollisionChannel> PrimaryAttackObstructionTraceChannel;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Katana|Primary Attack")
	bool bDebugPrimaryAttackTraces;
#endif

private:
	UPROPERTY(Transient)
	UFortGameplayAbility* CachedTechniqueAbilityCDO;

};

