// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentSelector.h"
#include "Math/MathFwd.h"
#include "AI/FortNavSystem.h"
#include "AI/NavAreas/FortNavArea.h"
#include "AI/NavAreas/FortNavAreaAutomatic.h"
#include "FortReleaseVersion.h"
#include "AthenaNavSystem.generated.h"

class AAthenaNavInvokerBox;
class UBuildingStructuralSupportSystem;
class UObject;
class USceneComponent;
class UWorld;

UENUM()
enum class EInBoundsState : uint8
{
	NoBounds = 0,
	NotInBounds = 1,
	InBounds = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnNavGenerationFinished, USceneComponent*, Component);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNavSystemLockReleased);

USTRUCT()
struct FBoxNavInvoker
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AAthenaNavInvokerBox> Invoker;

};

USTRUCT()
struct FNavDataSetVariantSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Navigation")
	TSoftObjectPtr<UWorld> Level;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(ClampMin="0", UIMin="0"))
	uint32 OceanFloodLevel;

};

USTRUCT()
struct FOverriddenSupportedAgentsByReleaseVersion
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Navigation")
	FFortReleaseVersion StartVersion;

	UPROPERTY(EditAnywhere, Category="Navigation")
	FFortReleaseVersion EndVersion;

	UPROPERTY(EditAnywhere, Category="Navigation")
	FNavAgentSelector OverriddenSupportedAgentsMask;

};

UCLASS(MinimalAPI)
class UAthenaNavSystem : public UFortNavSystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Navigation", meta=(WorldContext="WorldContextObject"))
	static bool IsInitialNavigationLockActive(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	static void RegisterNavGenerationObserver(USceneComponent* Component, FOnNavGenerationFinished Event);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	static void UnregisterNavGenerationObserver(USceneComponent* Component);

private:
	UPROPERTY(EditAnywhere, Category="Navigation")
	TArray<FNavDataSetVariantSettings> NavDataSetVariants;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bUseNavDataSetVariants : 1;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bMarkBuildingFoundationDirty : 1;

	UPROPERTY()
	uint8 bSupportRuntimeNavmeshDisabling : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Navigation")
	float NavGenerationObserverCheckInterval;

	UPROPERTY(EditDefaultsOnly, Config, Category="Navigation Enforcing")
	uint8 bAllowStaticNavigationInvokerBoxes : 1;

	UPROPERTY()
	TArray<FBoxNavInvoker> BoxInvokers;

	UPROPERTY()
	TArray<FBox> NavOctTreeInclusionBounds;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UBuildingStructuralSupportSystem> StructuralSupportSystem;
#endif

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAI_API UAthenaNavSystemConfig : public UFortNavSystemConfig
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Navigation", meta=(AllowPrivateAccess="true", EditCondition="bUseNavDataSetVariants"))
	uint8 DebugVariantIndex;
#endif

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true", EditCondition="bUseNavDataSetVariants"))
	TArray<FNavDataSetVariantSettings> NavDataSetVariants;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bUseNavDataSetVariants : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bDiscardNavDataFromSublevels : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bUseNavigationInvokers : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true", EditCondition="bUseNavigationInvokers"))
	uint8 bAllowStaticNavigationInvokerBoxes : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bLazyOctree : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bUseNavOctTreeInclusionBounds : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bPrioritizeNavigationAroundSpawners : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bResetDirtyAreasOnInitialBuildingRelease : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bSupportRuntimeNavmeshDisabling : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	uint8 bNavOctreeUnlockedByDefaultWhenNotPreloadingNavData : 1;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true", InlineEditConditionToggle))
	uint8 bConfigureDirtyAreaWarningSizeThreshold : 1;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bUseDirtyAreaFilterFunction : 1;

	UPROPERTY(EditAnywhere, Category="Navigation Enforcing")
	double InvokersMaximumDistanceFromSeed;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true", EditCondition="bConfigureDirtyAreaWarningSizeThreshold"))
	float DirtyAreaWarningSizeThreshold;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	TArray<FOverriddenSupportedAgentsByReleaseVersion> OverriddenSupportedAgentsByReleaseVersion;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	bool bSuspendNavmeshWhenNoPossibleUsers;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	TArray<FName> AllowedNavBoundsUniqueActorTags;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(AllowPrivateAccess="true"))
	FNavAgentSelector EnableAutoNavConfigForAgent;

};

UCLASS()
class FORTNITEAI_API UFortNavArea_MetaReplacement : public UFortNavArea
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortNavArea_ObstacleReplacement : public UFortNavArea
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortNavArea_TempWallReplacement : public UFortNavAreaAutomatic
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortNavArea_WallCornerReplacement : public UFortNavArea
{
	GENERATED_BODY()

};

