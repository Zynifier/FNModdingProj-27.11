// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "NavigationSystem.h"
#include "FortNavSystem.generated.h"

class AActor;
class AFortNavigationGraph;
class ANavigationData;
class ARecastNavMesh;
class UFortCustomNavLinkGlobalProxy;
class UFortInescapableZoneTracker;
class UFortNavLinkBlockerComponent;
class UFortPathCostEstimator;
class UNavArea;
class UObject;

UENUM()
namespace EFortNamedNavmesh
{
	enum Type
	{
		Husk = 0,
		Smasher = 1,
		MAX = 2,
	};
}

USTRUCT()
struct FMetaNavCachedEntry
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortNavSystem : public UNavigationSystemV1
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AI|Navigation", meta=(WorldContext="WorldContext"))
	static bool IsNavmeshInRadiusInitialized(UObject* WorldContext, const FVector& TestLocation, float TestRadius);

	UPROPERTY()
	TSoftClassPtr<UNavArea> DefaultSmashableArea;

	UPROPERTY()
	TSoftClassPtr<UNavArea> JumpDownArea;

	UPROPERTY()
	TSoftClassPtr<UNavArea> JumpDownSmashableArea2;

	UPROPERTY()
	TSoftClassPtr<UNavArea> JumpDownSmashableArea3;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortCustomNavLinkGlobalProxy>> LinkGlobalProxies;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ARecastNavMesh>> NamedNavmeshes;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNavLinkBlockerComponent>> NavLinkBlockers;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortPathCostEstimator>> PathEstimators;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortInescapableZoneTracker>> InescapableZones;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bAllowAutoRebuild : 1;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bRebuildOnInitialUnlock : 1;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bUsesStreamedInNavLevel : 1;

	UPROPERTY(Config)
	uint8 bUseStaticMeshLinks : 1;

	UPROPERTY(Config)
	uint8 bUseStaticWorldLinksDown : 1;

	UPROPERTY(Config)
	uint8 bUseStaticWorldLinksUp : 1;

	UPROPERTY(Config)
	uint8 bUseJumpLinkActors : 1;

	UPROPERTY(Config)
	uint8 bGenerateWallClimbLinks : 1;

	UPROPERTY(Config)
	uint8 bGenerateClamberLinks : 1;

	UPROPERTY(Config)
	int32 UndermineHorizontalTileLimit;

	UPROPERTY(Config)
	int32 UndermineVerticalTileLimit;

	UPROPERTY(Config)
	float DirtyAreasUpdateFreqInactive;

protected:
	UFUNCTION()
	void OnNavDataRegistered(ANavigationData* NavData);

	UPROPERTY(Transient)
	TObjectPtr<AFortNavigationGraph> NavGraphData;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> CompositePathGoals;

	UPROPERTY(Transient)
	TArray<FBox> AtlasCells;

	UPROPERTY(Transient)
	TArray<FMetaNavCachedEntry> MetaNavCachedAreas;

};

UCLASS()
class UFortNavSystemConfig : public UNavigationSystemModuleConfig
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bAllowAutoRebuild : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bRebuildOnInitialUnlock : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bUsesStreamedInNavLevel : 1;

};

