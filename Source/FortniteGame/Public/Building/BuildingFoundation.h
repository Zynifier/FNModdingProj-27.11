// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "Styling/SlateBrush.h"
#include "Building/BuildingFoundationStreamingData.h"
#include "Building/BuildingSMActor.h"
#include "BuildingFoundation.generated.h"

class AActor;
class ABuildingFoundation;
class AFortHLODSMActor;
class ALODActor;
class UBuildingGroup;
class ULevelStreaming;
class UMaterialInstanceDynamic;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2DDynamic;
class UWorld;

UENUM()
enum EBuildingFoundationType
{
	BFT_3x3 = 0,
	BFT_5x5 = 1,
	BFT_5x10 = 2,
	// Invalid type

	BFT_None = 3,
};

UENUM()
enum class EDynamicFoundationEnabledState : uint8
{
	// A default state that is neither enabled or disabled so that regardless of what changes on the server manipulate a start enabled foundation as part of begin play, the actual state gets replicated

	Unknown = 0,
	// The foundation is enabled

	Enabled = 1,
	// The foundation is disabled

	Disabled = 2,
};

UENUM(BlueprintType)
enum class EDynamicFoundationType : uint8
{
	// The foundation will always be in the same spot and enabled.

	Static = 0,
	// The foundation can be disabled and begins enabled at the position it is placed.

	StartEnabled_Stationary = 1,
	// The foundation can be moved and disabled, it begins enabled but must have its transform set before it will be loaded.

	StartEnabled_Dynamic = 2,
	// The foundation can be moved and enabled, but begins disabled. If it is to be moved the transform must be set before it is enabled.

	StartDisabled = 3,
};

USTRUCT()
struct FBuildingFoundationLODActorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> VisibilityMaterial;

	UPROPERTY()
	TObjectPtr<UTexture2DDynamic> VisibilityTexture;

};

USTRUCT()
struct FDynamicBuildingFoundationRepData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FRotator Rotation;

	UPROPERTY()
	FVector Translation;

	UPROPERTY()
	EDynamicFoundationEnabledState EnabledState;

};

UCLASS(Abstract, MinimalAPI, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingSMActorClassData)
class ABuildingFoundation : public ABuildingSMActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Foundation")
	bool DoesBuildingFoundationContainActor(AActor* Actor) const;

	UFUNCTION(BlueprintCallable)
	void EditorOnlyAddAdditionalWorld(UPARAM(ref) FString& LevelPackageName);

	UFUNCTION(BlueprintCallable)
	bool EditorOnlyAddTransformToPreviewLevel(const FTransform& DeltaTransform);

	UFUNCTION(BlueprintCallable)
	void EditorOnlyClearAdditionalWorlds();

	UFUNCTION(BlueprintCallable)
	static void EditorOnlyEnterBatchPreview();

	UFUNCTION(BlueprintCallable)
	static void EditorOnlyExitBatchPreview();

	UFUNCTION(BlueprintCallable)
	TArray<FString> EditorOnlyGetAdditionalWorlds();

	UFUNCTION(BlueprintCallable)
	bool EditorOnlyLoadPreviewLevel(bool bCreateLevelInstance);

	UFUNCTION(BlueprintCallable)
	bool EditorOnlyRemoveAdditionalWorld(UPARAM(ref) FString& LevelToRemove);

	UFUNCTION(BlueprintCallable)
	bool EditorOnlyUnloadPreviewLevel();

#if WITH_EDITOR
	UFUNCTION(BlueprintPure)
	bool GetPreviewFoundationLevelInEditor() const;
#endif

	UFUNCTION(BlueprintPure)
	bool GetStreamedInActors(TArray<AActor*>& StreamedInActors) const;

	UFUNCTION(BlueprintCallable)
	void HideHLODProxies();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetDynamicFoundationEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetDynamicFoundationTransform(const FTransform& NewTransform);

	UFUNCTION(BlueprintCallable)
	void ShowHLODProxies();

	UFUNCTION(BlueprintCallable, Category="Foundation UI")
	void UpdateMinimapDetailsLocation(const FVector& InLocation);

	UPROPERTY()
	TEnumAsByte<EBuildingFoundationType> FoundationType;

	UPROPERTY(EditAnywhere, Category="Foundation")
	FGameplayTagQuery BuildingGroupFilter;

	UPROPERTY(EditAnywhere, Category="HLOD")
	float ProxyMeshMaxDrawDistanceMultiplier;

protected:
	UFUNCTION()
	void OnLevelShown();

	UFUNCTION()
	void OnLevelStreamedIn();

	UFUNCTION()
	void OnLevelStreamedOut();

	UFUNCTION()
	virtual void OnRep_LevelToStream();

	UFUNCTION()
	virtual void OnRep_ServerStreamedInLevel();

	UFUNCTION()
	void OnStaticLevelShown();

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	TSoftObjectPtr<UStaticMesh> EditorStaticMesh;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, DuplicateTransient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> EditorVisualizationComponent;
#endif

	UPROPERTY(EditAnywhere, Category="Foundation")
	TArray<TObjectPtr<UBuildingGroup>> BuildingGroups;

	UPROPERTY(EditAnywhere, Category="Foundation")
	TArray<TSoftObjectPtr<UWorld>> AdditionalWorlds;

	UPROPERTY(EditAnywhere, Category="Foundation")
	FVector BuildingDeconstructorOrigin;

	UPROPERTY(EditAnywhere, Category="Foundation")
	FVector BuildingDeconstructorExtent;

	UPROPERTY(EditAnywhere, Category="Foundation")
	uint8 bConditionalFoundation : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerStreamedInLevel)
	uint8 bServerStreamedInLevel : 1;

	UPROPERTY(EditAnywhere, Category="Foundation")
	uint8 bShowHLODWhenDisabled : 1;

	UPROPERTY(EditAnywhere, Category="Foundation")
	uint8 bFlipXAxis : 1;

	UPROPERTY(EditAnywhere, Category="Foundation")
	uint8 bFlipYAxis : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Foundation")
	uint8 bRequiredForWarmupPhaseInPIE : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Foundation")
	uint8 bPreviewFoundationLevelInEditor : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, AdvancedDisplay, Category="Foundation")
	uint8 bPreviewUsingLevelInstance : 1;
#endif

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bOverrideNavigationGraphCells : 1;

	UPROPERTY(EditAnywhere, Category="Navigation")
	uint8 bHasExcludedZone : 1;

	UPROPERTY(EditAnywhere, Category="HLOD")
	uint8 bForceDitheringTransition : 1;

	UPROPERTY(Transient)
	uint8 bStreamingDataBasedBounds : 1;

	UPROPERTY(Transient)
	EDynamicFoundationEnabledState FoundationEnabledState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Foundation")
	EDynamicFoundationType DynamicFoundationType;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(EditCondition="bHasExcludedZone"))
	int32 NavExclusionMinX;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(EditCondition="bHasExcludedZone"))
	int32 NavExclusionMaxX;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(EditCondition="bHasExcludedZone"))
	int32 NavExclusionMinY;

	UPROPERTY(EditAnywhere, Category="Navigation", meta=(EditCondition="bHasExcludedZone"))
	int32 NavExclusionMaxY;

	UPROPERTY()
	FBox StreamingBoundingBox;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LevelToStream)
	FName LevelToStream;

	UPROPERTY(EditAnywhere, Category="Foundation UI", meta=(Categories="Athena.Location.POI, Location.POI, Apollo.Location.POI"))
	FGameplayTag MapLocationTag;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	FSlateBrush LandIcon;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	FVector LandIconWorldOffset;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	FText MapLocationText;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	FVector MapLocationTextOffset;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	float LandIconAdditionalRenderYaw;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	bool bRotateLandIconWorldOffset;

	UPROPERTY()
	FVector MapLocationOverride;

	UPROPERTY(EditAnywhere, Category="Foundation UI")
	bool bShadowLayer;

	UPROPERTY(Transient)
	FBuildingFoundationStreamingData StreamingData;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortHLODSMActor>> SpawnedLODActors;

	UPROPERTY(Transient)
	TArray<float> SpawnedLODActorsMinDrawDistances;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortHLODSMActor>> ChildSpawnedLODActors;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ALODActor>> HLODActors;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingFoundation> ParentFoundation;

	UPROPERTY(Transient)
	TObjectPtr<ULevelStreaming> LevelStreamInfo;

private:
	UFUNCTION()
	void OnRep_DynamicFoundationRepData();

	UPROPERTY(ReplicatedUsing=OnRep_DynamicFoundationRepData)
	FDynamicBuildingFoundationRepData DynamicFoundationRepData;

	UPROPERTY(Transient)
	FTransform DynamicFoundationTransform;

	UPROPERTY(NonPIEDuplicateTransient)
	FGuid FoundationGUID;

};

