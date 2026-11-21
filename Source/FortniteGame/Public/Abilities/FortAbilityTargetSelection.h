// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortAbilityTargetingSourceEnum.h"
#include "FortTargetSelectionEnums.h"
#include "FortAbilityTargetSelection.generated.h"

class UObject;
class UPrimitiveComponent;

UENUM()
enum class EFortAbilityTargetSelectionUsage : uint8
{
	BothTargetingAndCanHit = 0,
	OnlyTargeting = 1,
	OnlyCanHit = 2,
};

USTRUCT()
struct FFortAbilityCanHitParameters
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortTargetFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	TEnumAsByte<EFortTargetSelectionFilter::Type> ActorTypeFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	TSubclassOf<UObject> ActorClassFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeInstigator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bUseTrapsOwningPawnAsInstigator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeRequester : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAllAttachedToInstigator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAthenaVehicleOfInstigator : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAllAttachedToRequester : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeTargetsInEditMode : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludePawnFriends : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeFriendlyAI : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection", meta=(EditCondition="bExcludeFriendlyAI", EditConditionHides))
	uint8 bIncludeRiddenAI : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAllAI : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludePawnNeutrals : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludePawnEnemies : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeNonPawnFriends : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeNonPawnEnemies : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bConsiderFriendlyFireWhenExcludingFriends : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeDBNOPawns : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeFallingPawns : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeWaterVolumes : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeWaterBodies : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAthenaVehicleOccupiedBySource : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAthenaVehicleUnoccupied : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAthenaVehicleOccupied : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeAthenaVehicleFromObstructionChecks : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeWithoutNavigationCorridor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeNonPlayerBuiltPieces : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludePlayerBuiltPieces : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeNonBGABuildings : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeNonBlockingHits : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeProjectiles : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bTraceComplexCollision : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bExcludeLandscape : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	uint8 bConsiderPhysicsPawnsAsNonPlayerPawns : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	FGameplayTagContainer ExclusionGameplayTags;

};

USTRUCT(BlueprintType)
struct FFortAbilityTargetSelection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	TEnumAsByte<EFortTargetSelectionShape::Type> Shape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FString CustomShapeComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	EFortTargetSelectionTestType TestType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	EFortAbilityTargetingSource PrimarySource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	EFortAbilityTargetingSource SecondarySource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FScalableFloat Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FVector HalfExtents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	bool bAlignShapeEdgeToSourceLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FScalableFloat ConeYawAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FScalableFloat ConePitchAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FScalableFloat ConeMinRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	FFortTargetFilter TargetFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	bool bExcludeObstructedByWorld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	bool bShouldAttachedActorsObstructTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	bool bCreateHitResultWhenNoTargetsFound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	bool bUseProjectileRotationForDamageZones;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	EFortAbilityTargetSelectionUsage TargetSelectionUsage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	int32 MaxTargets;

};

USTRUCT(BlueprintType)
struct FFortAbilityTargetSelectionList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	TArray<FFortAbilityTargetSelection> List;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	uint8 bStopAtFirstSuccess : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection", meta=(EditCondition="bStopAtFirstSuccess"))
	uint8 bKeepCheckingListOnIndestructibleHit : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TargetSelection")
	FGameplayTagContainer AbilityTargetBlockedGameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	uint8 bUseWeaponRanges : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection")
	uint8 bUseMaxYawAngleToTarget : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TargetSelection", meta=(EditCondition="bUseMaxYawAngleToTarget"))
	float MaxYawAngleToTarget;

};

USTRUCT()
struct FVisibilityTestPoint
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> Component;

};

