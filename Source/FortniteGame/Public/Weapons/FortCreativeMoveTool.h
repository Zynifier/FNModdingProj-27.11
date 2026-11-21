// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "FortCreativeOptionVariableBase.h"
#include "Weapons/FortWeapon.h"
#include "FortCreativeMoveTool.generated.h"

class AActor;
class AFortCreativeHeatmapThermometerPreview;
class AFortCreativeMoveTool;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortVolume;
class AFortWeapon;
class APlayerController;
class AStaticMeshActor;
class UDataTable;
class UDeleteObjects;
class UFortCreativeOption;
class UFortGameplayAbility;
class UFortItemDefinition;
class UFortObjectMoverInputComponent;
class UFortPlaysetItemDefinition;
class ULevelRecordSpawner;
class UMaterial;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMeshComponent;
class UObject;
class UObjectInteractionBehavior;
class UPlaysetPreview;
class UStaticMesh;
enum class EBuildingAsPropSetting : uint8;
enum class EHitTraceRule : uint8;
enum class EScaleAxis : uint8;
enum class ESelectionProperty : uint8;
enum class ETransformationType : uint8;

UENUM(BlueprintType)
enum class EAddToSelectionResult : uint8
{
	Added = 0,
	Removed = 1,
	AtLimit = 2,
	None = 3,
};

UENUM()
enum class EBuildingAsPropSetting : uint8
{
	None = 0,
	SnapToEdge = 1,
	SnapToCenter = 2,
};

UENUM(BlueprintType)
enum class ECameraSpaceHoldPosition : uint8
{
	AsPickup = 0,
	Left = 1,
	Center = 2,
	Right = 3,
};

UENUM(BlueprintType)
enum class EHitTraceRule : uint8
{
	Visibility = 0,
	Terrain = 1,
	None = 2,
};

UENUM(BlueprintType)
enum class EHitTraceType : uint8
{
	Single = 0,
	Multi = 1,
};

UENUM(BlueprintType)
enum class EMoveToolPlacementCheckResult : uint8
{
	// Position has not been tested yet

	Untested = 0,
	// Valid position

	Valid = 1,
	// Invalid position

	Invalid = 2,
	// Over Budget

	OverBudget = 3,
};

UENUM(BlueprintType)
enum class EScaleAxis : uint8
{
	All = 0,
	X = 1,
	Y = 2,
	Z = 3,
};

UENUM(BlueprintType)
enum class ESelectionProperty : uint8
{
	SingleObject = 0,
	SingleObjectMoveOnGrid = 1,
	MultipleObjects = 2,
	MultipleObjectsMoveOnGrid = 3,
	None = 4,
};

UENUM(BlueprintType)
enum class ETransformationType : uint8
{
	Translation = 0,
	Rotation = 1,
	Scale = 2,
	None = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddedSelectedActor, AActor*, SelectedActor, int32, NumSelectedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishedSpawningSelectedActors);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMoveToolBuildingAsPropSettingChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolDropToFloorChanged, bool, bDropToFloorOn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolFocusChanged, AActor*, FocusedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolInteractionStarted, UObjectInteractionBehavior*, InteractionMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMoveToolInteractionStopped);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolLineOfSightBlockingChanged, EHitTraceRule, HitTraceRule);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMoveToolPrecisionChanged, bool, bPrecisionOn, uint8, GridSnapIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolRotationAxisChanged, uint8, RotationAxisIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolRotationModified, FQuat, currentRotationOffset);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolScaleAxisChanged, EScaleAxis, ScaleAxis);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolScaleInsteadOfRotateChanged, bool, bScalingOn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolScaleModified, FVector, currentScale);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolScalingToggled, bool, bScalingActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveToolTransformationModeChanged, ETransformationType, TransformationType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemovedSelectedActor, AActor*, DeselectedActor, int32, NumSelectedActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectedActorsCleared);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectionPropertyChanged, ESelectionProperty, SelectionProperty);

USTRUCT()
struct FActorAndTimePair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

	UPROPERTY()
	FDateTime SpawnTime;

};

USTRUCT()
struct FActorAndTransformPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

private:
	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	bool bHasValidTransform;

};

USTRUCT()
struct FAgingActorArray
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FActorAndTimePair> AgingActors;

};

USTRUCT()
struct FCreativePooledMID
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> MID;

	UPROPERTY()
	TObjectPtr<UMaterialInterface> OriginalMaterial;

};

USTRUCT(BlueprintType)
struct FCreativeSelectedActorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeSelectedActorInfo")
	TObjectPtr<AActor> Actor;

	UPROPERTY()
	FTransform UnscaledActorToSelectionAtDragStart;

	UPROPERTY()
	FVector ScaleAtDragStart;

	UPROPERTY()
	FVector DragStartGridSnapPoint;

	UPROPERTY()
	float OriginalRelevancyDistance;

	UPROPERTY()
	bool bWasCollisionEnabled;

	UPROPERTY()
	bool bWasDormant;

	UPROPERTY()
	bool bSpawnedFromSaveRecord;

	UPROPERTY()
	int32 LogicalConnectionChainIndex;

};

USTRUCT()
struct FCreativeToolClasses : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CreativeToolClasses", meta=(ClassReference))
	FName ClassPath;

};

USTRUCT()
struct FCreativeToolObjectInteractionRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CreativeToolObjectInteractionRow")
	TObjectPtr<UDataTable> AllowedClasses;

	UPROPERTY(EditDefaultsOnly, Category="CreativeToolObjectInteractionRow")
	TObjectPtr<UDataTable> ForbiddenClasses;

};

USTRUCT()
struct FFlashCountedActorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FCreativeSelectedActorInfo> Actors;

	UPROPERTY()
	int8 FlashCounter;

};

USTRUCT()
struct FLogicalConnectionChain
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> LogicalConnectedActors;

};

USTRUCT()
struct FMoveToolSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bAllowGravityOnPlace;

	UPROPERTY()
	bool bIsScalingInsteadOfRotating;

};

USTRUCT(BlueprintType)
struct FOriginalAndSpawnedPair
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="OriginalAndSpawnedPair")
	TObjectPtr<AActor> OriginalActor;

	UPROPERTY(BlueprintReadOnly, Category="OriginalAndSpawnedPair")
	TObjectPtr<AActor> SpawnedActor;

	UPROPERTY(BlueprintReadOnly, Category="OriginalAndSpawnedPair")
	bool bSpawnedActorIsForPreview;

};

USTRUCT()
struct FPlaysetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortPlaysetItemDefinition> Playset;

	UPROPERTY()
	int8 FlashCounter;

};

USTRUCT()
struct FValidPlacementPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

	UPROPERTY()
	bool bIsPlacementValid;

};

UCLASS(MinimalAPI, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortCreativeMoveTool : public AFortWeapon
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientAddItemToMoveToolComplete(AFortPlayerControllerAthena* FortPC);

	UFUNCTION(BlueprintPure)
	static bool DoesBoxOverlapTerrain(const AActor* WorldContextObject, const FBox Box);

	UFUNCTION(BlueprintPure, Category="CreativeMoveTool")
	bool GetAllowGravityOnPlace() const;

	UFUNCTION(BlueprintPure, Category="CreativeMoveTool")
	float GetAverageScaleModifier() const;

	UFUNCTION(BlueprintPure)
	bool GetClientNeedsToProcessNewlyPlacedActors() const;

	UFUNCTION(BlueprintPure)
	UFortObjectMoverInputComponent* GetCreativeMoveToolInputComponent() const;

	UFUNCTION(BlueprintPure, Category="CreativeMoveTool")
	EHitTraceRule GetCurrentHitTraceRule();

	UFUNCTION(BlueprintPure)
	uint8 GetGridSnapIndex() const;

	UFUNCTION(BlueprintPure)
	TArray<FVector> GetGridSnapRatios() const;

	UFUNCTION(BlueprintPure, Category="CreativeMoveTool")
	int32 GetMultiselectLimit();

	UFUNCTION(BlueprintPure)
	uint8 GetRotationAxisIndex() const;

	UFUNCTION(BlueprintPure)
	EScaleAxis GetSelectedScaleAxis() const;

	UFUNCTION(BlueprintPure)
	bool GetShouldAutoTractorBeam() const;

	UFUNCTION(BlueprintPure)
	bool GetShouldUsePrecisionGridSnapping() const;

	UFUNCTION(BlueprintPure)
	float GetTargetTractorBeamOffset() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleDropToFloorPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleDuplicateActorPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleDuplicateActorReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleExitPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleExitReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePullPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePullReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePushPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePushReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleResetRotationPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateClockwisePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateClockwiseReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateCounterclockwisePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateCounterclockwiseReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateSwitchAxisPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateSwitchAxisReleased();

	UFUNCTION()
	void IncrementOrWrapHitTraceRuleOnClient();

	UFUNCTION(BlueprintPure, Category="CreativeMoveTool")
	bool IsRunningOnOwningClient() const;

	UFUNCTION(Server, Reliable)
	void ServerAddItemToMoveTool(AFortPlayerControllerAthena* FortPC, const UFortItemDefinition* PlaysetToSpawn, bool bUseVolume);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveSelectionSet(const FTransform NewSelectionToWorld, const bool bShouldUpdateOwningClient);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpawnActorWithTransform(AActor* ActorToSpawn, FTransform TargetTransform, const bool bAllowOverlap, const bool bAllowGravity, const bool bIgnoreStructuralIssues, const bool bForPreviewing);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpawnSelectedActorsWithTransform(const bool bAllowOverlap, const bool bAllowGravity, const bool bIgnoreStructuralIssues, const bool bForPreviewing, const bool bNotifyOwnerOnFailure);

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolInteractionStarted OnMoveToolInteractionStarted;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolInteractionStopped OnMoveToolInteractionStopped;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolRotationAxisChanged OnMoveToolRotationAxisChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolScaleAxisChanged OnMoveToolScaleAxisChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolLineOfSightBlockingChanged OnMoveToolLineOfSightBlockingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolDropToFloorChanged OnMoveToolDropToFloorChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolPrecisionChanged OnMoveToolPrecisionChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolTransformationModeChanged OnMoveToolTransformationModeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolScaleInsteadOfRotateChanged OnMoveToolScaleInsteadOfRotateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAddedSelectedActor OnAddedSelectedActor;

	UPROPERTY(BlueprintAssignable)
	FOnAddedSelectedActor OnCouldNotAddReachedSelectionLimit;

	UPROPERTY(BlueprintAssignable)
	FOnRemovedSelectedActor OnRemovedSelectedActor;

	UPROPERTY(BlueprintAssignable)
	FOnSelectedActorsCleared OnSelectedActorsCleared;

	UPROPERTY(BlueprintAssignable)
	FOnSelectionPropertyChanged OnSelectionPropertyChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolScalingToggled OnMoveToolScalingToggled;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolScaleModified OnMoveToolScaleModified;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolRotationModified OnMoveToolRotationModified;

	UPROPERTY(BlueprintAssignable)
	FOnMoveToolBuildingAsPropSettingChanged OnMoveToolBuildingAsPropSettingChanged;

	UPROPERTY(Transient)
	TObjectPtr<AActor> HoveredActor;

protected:
	UFUNCTION()
	void AdjustOptionsBasedOnSelectionProperty(ESelectionProperty UpdatedSelectionProperty);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	bool CanUtilizeMoveToolSpawningFunctionality();

	UFUNCTION(Client, Reliable)
	void ClientDeactiveWeaponAndState();

	UFUNCTION(Client, Reliable)
	void ClientStartInteracting(UObjectInteractionBehavior* NewActiveMovementMode, const TArray<FCreativeSelectedActorInfo>& NewSelectedActors, const FTransform& NewSelectionToWorld, const FBox& NewSelectionSpaceActorBounds);

	UFUNCTION(Client, Reliable)
	void ClientStopInteracting();

	UFUNCTION(BlueprintCallable)
	virtual void DeactiveWeaponAndState();

	UFUNCTION()
	void Finished_CutDuplicateStartInteractingOnServer();

	UFUNCTION()
	void Finished_DuplicateStartInteractingOnServer();

	UFUNCTION(BlueprintPure)
	UObjectInteractionBehavior* GetActiveMovementMode() const;

	UFUNCTION(BlueprintPure, Category="CreativeMoveTool")
	AFortVolume* GetCurrentVolume(const bool bMustHavePermissions);

	UFUNCTION(BlueprintPure)
	void GetValidQueuedActorsAsArray(TArray<AActor*>& ValidQueuedActors);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleActivateRotationModePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleActivateScaleModePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleActivateTranslateModePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleActorSelectedForQueuePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleActorSelectedForQueueReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleActorSelectedHeldDownLongEnough();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleClearMultiSelectQueuePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleCopyPickupPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleCopyPickupReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleDeleteHeldDownLongEnough();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleDeletePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleDeleteReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleExitHeldDownLongEnough();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleExitOrDeletePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleHitTraceRuleHeldDownLongEnough();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleHitTraceRulePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleHitTraceRuleReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleMirrorPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePickupPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePlaysetPreviewPlace();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePrecisionModePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandlePrecisionModeReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleResetScalePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateSingleClockwisePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateSingleClockwiseReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateSingleCounterclockwisePressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleRotateSingleCounterclockwiseReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleScaleDownPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleScaleDownReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleScaleSwitchAxisPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleScaleSwitchAxisReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleScaleUpPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleScaleUpReleased();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleTransformModeDownPressed();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void HandleTransformModeUpPressed();

	UFUNCTION()
	void HandleTurboDeleteAction();

	UFUNCTION(BlueprintPure)
	bool IsMultiSelecting();

	UFUNCTION(BlueprintPure)
	bool IsMultiselectingMoveOnGrid();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastForceMoveActor(AActor* ActorToMove, const FTransform NewTransform);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastForceMoveActorExceptOwningClient(AActor* ActorToMove, const FTransform NewTransform);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastUpdateSelectionSetExceptServer(const FTransform NewTransformToWorld);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastUpdateSelectionSetExceptServerAndOwningClient(const FTransform NewTransformToWorld);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnAddedToQuickbar(const TArray<UMeshComponent*>& Components);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnAllowGravityToggleChanged(bool bAllowGravity);

	UFUNCTION()
	void OnClientInstigatorWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void OnClientInstigatorWeaponUnequipped();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="InputEvents")
	void OnCopyOrPickupFailed();

	UFUNCTION()
	void OnCreativeQuickmenuEnabledChanged(bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnHighlightSelectedActor(AActor* SelectedActor, const TArray<UMeshComponent*>& SelectedComponents);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnHoverChanged(const TArray<UMeshComponent*>& NewHoveredComponents, const TArray<UMeshComponent*>& UnhoveredComponents, UObjectInteractionBehavior* ObjectInteraction);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnInteractionFinished(const TArray<UMeshComponent*>& Components);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnInteractionStarted(const TArray<UMeshComponent*>& Components);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnObjectPlacement(const TArray<UMeshComponent*>& Components, FOriginalAndSpawnedPair NewlyPlacedActorPair);

	UFUNCTION(BlueprintCallable, Category="CreativeMoveTool")
	void OnPlaysetSelected(UFortPlaysetItemDefinition* SelectedPlayset);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnRemoveHighlightSelectedActor(AActor* SelectedActor, const TArray<UMeshComponent*>& SelectedComponents);

	UFUNCTION()
	void OnRep_ActiveMovementModeReplicateToRemoteClients();

	UFUNCTION()
	void OnRep_AllowGravityOnPlace();

	UFUNCTION()
	void OnRep_BuildingsAsPropsSnapToCenter();

	UFUNCTION()
	void OnRep_CutActors();

	UFUNCTION()
	void OnRep_DisableCollisionActors();

	UFUNCTION()
	void OnRep_NewlyPlacedActors();

	UFUNCTION()
	void OnRep_SelectedActorsReplicateToRemoteClients();

	UFUNCTION()
	void OnRep_SelectionProperty();

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnValidPlacementChanged(bool bValidPlacement);

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnValidPlacementChangedActorInstance(AActor* ActorForPlacement, bool ValidPlacement);

	UFUNCTION()
	void OnWantedAlwaysMoveFreely(UFortCreativeOption* CreativeOption, uint8 Index);

	UFUNCTION()
	void OnWantedCameraSpacePositioning(UFortCreativeOption* CreativeOption, uint8 Index);

	UFUNCTION()
	void OnWantedHitTraceRule(UFortCreativeOption* CreativeOption, uint8 Index);

	UFUNCTION()
	void OnWantedIgnoreRecentlyPlacedTime(UFortCreativeOption* CreativeOption, uint8 Index);

	UFUNCTION()
	void OnWantsAutoTractorBeamChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UFUNCTION()
	void OnWantsGravityOnPlace(UFortCreativeOption* CreativeOption, uint8 Index);

	UFUNCTION()
	void OnWantsPrecisionGridSnapping(UFortCreativeOption* CreativeOption, uint8 Index);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void PopCreativeMoveToolEquippedInputComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="InputEvents")
	void PushCreativeMoveToolEquippedInputComponent();

	UFUNCTION()
	void QueuedActorDestroyed(AActor* DestroyedActor);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerActorDeselected(AActor* Actor, AFortPlayerController* InstigatorPlayer);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerActorSelected(AActor* Actor, AFortPlayerController* InstigatorPlayer);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerBatchDestroyActors(const TArray<AActor*>& ActorsToDestroy);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerClearMovementMode(const bool bExited);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerDestroyActor(AActor* ActorToDestroy);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDuplicateStartInteracting(const TArray<AActor*>& Actors, const FTransform DragStart);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOnNewlyPlacedActorProcessedByClient(FOriginalAndSpawnedPair NewlyPlacedActorPair);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerPlaceActorsAndClearMovementMode(FTransform TargetTransformForBuildings);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerResetScale();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSendProgressTimerCue(float Duration);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetAllowGravity(bool bAllow);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetAlwaysMoveFreely(EBuildingAsPropSetting NewSetting);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStartInteracting(const TArray<AActor*>& Actors, const FTransform DragStart);

	UFUNCTION(Server, Reliable)
	void ServerStartReselectTimer();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateLocale(const FString& UpdatedLocale);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateMirrored(bool bMirrored);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdatePrecisionMode(bool bPrecisionMode, uint8 PrecisionModeIndex);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateRotation(FQuat ClientRotation, bool bNewIsRotateClockwisePressed, bool bNewIsRotateCounterclockwisePressed);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateRotationAxis(uint8 AxisIndex);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateScaleAxis(EScaleAxis SelectedAxis);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateScalePressed(bool bNewIsScaleUpPressed, bool bNewIsScaleDownPressed);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateTractorBeam(float NewTargetTractorBeamOffset, bool bNewIsPushPressed, bool bNewIsPullPressed);

	UFUNCTION(BlueprintCallable)
	void SetLastBoundController(APlayerController* Controller);

	UFUNCTION(BlueprintCallable, Category="CreativeMoveTool")
	void SetTargetingState(bool bNewTargetingState);

	UFUNCTION(BlueprintCallable, Category="CreativeMoveTool")
	void SetupMIDForComponent(UMeshComponent* MeshComponent);

	UFUNCTION(Server, Reliable, WithValidation)
	void SpawnPlaysetVolumeOnServer(const UFortPlaysetItemDefinition* Playset, const FVector& SpawnLocation, const FRotator& SpawnRotation);

	UFUNCTION()
	void TurboBuildAttemptToPlace();

	UFUNCTION(BlueprintCallable)
	void UnholsterWeapon();

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortObjectMoverInputComponent> CreativeMoveToolInputComponent;

	UPROPERTY()
	TArray<FOriginalAndSpawnedPair> SpawnHelperNewlyPlacedActors;

	UPROPERTY()
	TArray<FActorAndTransformPair> ToDuplicateActors;

	UPROPERTY(BlueprintAssignable)
	FOnFinishedSpawningSelectedActors OnFinishedSpawningSelectedActors;

	UPROPERTY(BlueprintAssignable)
	FOnFinishedSpawningSelectedActors OnFinishedSpawningPreviewActors;

	UPROPERTY(BlueprintAssignable)
	FOnFinishedSpawningSelectedActors OnFinishedSpawningForCut;

	UPROPERTY(ReplicatedUsing=OnRep_SelectedActorsReplicateToRemoteClients)
	TArray<FCreativeSelectedActorInfo> SelectedActorsReplicateToRemoteClients;

	UPROPERTY(ReplicatedUsing=OnRep_ActiveMovementModeReplicateToRemoteClients, Export, meta=(EditInline="true"))
	TObjectPtr<UObjectInteractionBehavior> ActiveMovementModeReplicateToRemoteClients;

	UPROPERTY(EditAnywhere, Category="CreativeMoveTool")
	float MaxRange;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UObjectInteractionBehavior> ActiveMovementMode;

	UPROPERTY(Replicated)
	bool bIsPreviewingMove;

	UPROPERTY(EditAnywhere, Replicated, Export, Category="CreativeMoveTool", meta=(EditInline="true"))
	TArray<TObjectPtr<UObjectInteractionBehavior>> InteractionBehaviors;

	UPROPERTY(Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UDeleteObjects> DeleteObjectsInteractionBehavior;

	UPROPERTY(BlueprintReadWrite, Replicated, Export, Category="CreativeMoveTool", meta=(EditInline="true"))
	TObjectPtr<UPlaysetPreview> PlaysetPreviewInteractionBehavior;

	UPROPERTY()
	ETransformationType CurrentTransformationType;

	UPROPERTY()
	TArray<FCreativeSelectedActorInfo> SelectedActors;

	UPROPERTY()
	TArray<FLogicalConnectionChain> ServerSelectedActorLogicalConnections;

	UPROPERTY(Replicated)
	FVector ScaleModifier;

	UPROPERTY()
	FTransform SelectionToWorld;

	UPROPERTY()
	FBox SelectionSpaceActorsBounds;

	UPROPERTY()
	bool bIsScaleUpPressed;

	UPROPERTY()
	bool bIsMultiselectEnabled;

	UPROPERTY(EditAnywhere, Category="FortCreativeMoveTool")
	bool bIsQuickbarSupported;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeMoveTool")
	bool bIsImmersiveEditModeEnabled;

	UPROPERTY(ReplicatedUsing=OnRep_SelectionProperty)
	ESelectionProperty SelectionProperty;

	UPROPERTY()
	bool bIsScaleDownPressed;

	UPROPERTY()
	bool bIsPushPressed;

	UPROPERTY()
	bool bIsPullPressed;

	UPROPERTY()
	bool bIsAutoTractorBeamRunning;

	UPROPERTY()
	bool bIsRotateClockwisePressed;

	UPROPERTY()
	bool bIsRotateCounterclockwisePressed;

	UPROPERTY()
	bool bIsScalingInsteadOfRotating;

	UPROPERTY()
	FQuat TargetRotationOffset;

	UPROPERTY()
	FQuat RotationOffset;

	UPROPERTY()
	TArray<FRotator> RotationAxes;

	UPROPERTY()
	uint8 RotationAxisIndex;

	UPROPERTY()
	EScaleAxis SelectedScaleAxis;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMoveTool", meta=(EditInline="true"))
	TSet<TObjectPtr<UMeshComponent>> HoveredComponents;

	UPROPERTY()
	TMap<TObjectPtr<UMeshComponent>, float> ComponentsToReclaimMIDsFrom;

	UPROPERTY()
	TArray<FCreativePooledMID> AllMIDs;

	UPROPERTY(EditAnywhere, Category="CreativeMoveTool")
	float MaxUnhoverAnimationTime;

	UPROPERTY(ReplicatedUsing=OnRep_NewlyPlacedActors)
	TArray<FOriginalAndSpawnedPair> NewlyPlacedActors;

	UPROPERTY(ReplicatedUsing=OnRep_CutActors)
	FFlashCountedActorInfo CutActors;

	UPROPERTY(Transient)
	TArray<FCreativeSelectedActorInfo> CutActorsPrereplication;

	UPROPERTY(ReplicatedUsing=OnRep_DisableCollisionActors)
	TArray<TObjectPtr<AActor>> DisableCollisionActors;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> DisableCollisionActorsPrereplication;

	UPROPERTY()
	TSet<TObjectPtr<AActor>> AlreadyProcessedNewlyPlacedActorsOnClient;

	UPROPERTY()
	FAgingActorArray RecentlyPlacedAgingActors;

	UPROPERTY()
	bool bShouldDestroyPropsWhenPlacing;

	UPROPERTY(ReplicatedUsing=OnRep_AllowGravityOnPlace)
	bool bAllowGravityOnPlace;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantsGravityOnPlace;

	UPROPERTY(EditAnywhere, Category="FortCreativeMoveTool")
	bool bShouldUsePrecisionGridSnapping;

	UPROPERTY(EditAnywhere, Category="FortCreativeMoveTool")
	uint8 GridSnapIndex;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantsPrecisionGridSnapping;

	UPROPERTY(EditAnywhere, Category="FortCreativeMoveTool")
	TArray<FVector> GridSnapRatios;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	bool bDoesRequireCreatePermission;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	EHitTraceType TraceType;

	UPROPERTY(Replicated)
	bool bClientNeedsToProcessNewlyPlacedActors;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantedHitTraceRule;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	FGameplayTagContainer MoveToolActivatedTags;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	FGameplayTag ProgressTimerCueTag;

	UPROPERTY()
	TObjectPtr<ULevelRecordSpawner> ActiveRecordSpawner;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	TSubclassOf<AFortVolume> VolumeClassToSpawn;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantedIgnoreRecentlyPlacedTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildingsAsPropsSnapToCenter, Category="FortCreativeMoveTool")
	bool bBuildingsAsPropsSnapToCenter;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantedAlwaysMoveFreely;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantedCameraSpacePositioning;

	UPROPERTY(EditAnywhere, Category="Options")
	FCreativeOptionVariableBase WantsAutoTractorBeam;

	UPROPERTY()
	AFortCreativeHeatmapThermometerPreview* CreativeHeatmapThermometerPreview;

	UPROPERTY(EditAnywhere, Category="FortCreativeMoveTool")
	FGameplayTagContainer WeaponEquipContextTags;

	UPROPERTY(Transient)
	FString PlacementLocale;

private:
	UFUNCTION()
	void OnRep_ConnectedActorStates();

	UPROPERTY()
	FOnFinishedSpawningSelectedActors OnFinishedSpawningDelegate;

	UPROPERTY(Transient)
	TMap<AActor*, AActor*> PreviewToOriginalActors;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	FGameplayTag GameplayTagMoveToolHoldPositionCenter;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnMoveToolFocusChanged OnMoveToolFocusChanged;

	UPROPERTY(ReplicatedUsing=OnRep_ConnectedActorStates)
	TArray<FValidPlacementPair> ConnectedActorStates;

	UPROPERTY(EditAnywhere, Replicated, Category="FortCreativeMoveTool")
	bool bAlwaysMoveFreely;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("CreativeMoveTool"), meta=(BlueprintSpawnableComponent))
class UObjectInteractionBehavior : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	void EndCreativeInteraction();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	void ExitCreativeInteraction(const bool bShouldClearActiveInteractionMode = false);

	UFUNCTION(BlueprintCallable, Category="CreativeMoveTool")
	void GetSelectedActors(TArray<AActor*>& SelectedActors);

	UFUNCTION(BlueprintCallable, Category="CreativeMoveTool")
	void GetSelectedActorsMeshComponents(TArray<UMeshComponent*>& Components);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	void HandleDuplicateActor();

	UFUNCTION(BlueprintNativeEvent)
	bool IsActorClassAllowed(TSubclassOf<UObject> Class);

	UFUNCTION(BlueprintNativeEvent)
	bool IsActorClassForbidden(TSubclassOf<UObject> Class);

	UFUNCTION()
	virtual bool IsSelectionSetInValidPosition();

	UFUNCTION(BlueprintImplementableEvent, Category="CreativeMoveTool")
	void OnObjectPlacement(const TArray<UMeshComponent*>& Components, FOriginalAndSpawnedPair NewlyPlacedActorPair);

	UFUNCTION(BlueprintCallable)
	void PlayGameplayAbility(const TSubclassOf<UFortGameplayAbility> ActivatedAbilityClass);

	UFUNCTION(BlueprintNativeEvent, Category="CreativeMoveTool")
	void ReceiveSpawnedActor(AActor* SpawnedActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	void StartCreativeInteractionOnClient();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	void StartCreativeInteractionOnServer();

	UFUNCTION(BlueprintNativeEvent, Category="CreativeMoveTool")
	void TickMovementMode();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="CreativeMoveTool")
	void TriggerInteractionBehavior();

	UPROPERTY(EditDefaultsOnly, Category="ObjectInteractionBehavior")
	FColor HoverReticleColor;

	UPROPERTY(EditDefaultsOnly, Category="ObjectInteractionBehavior")
	FColor ActiveReticleColor;

protected:
	UFUNCTION(BlueprintPure, Category="CreativeInteraction")
	AFortCreativeMoveTool* GetFortCreativeMoveTool() const;

	UFUNCTION(BlueprintPure, Category="CreativeInteraction")
	AFortPlayerController* GetFortPlayerController() const;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	FDataTableRowHandle InteractionClasses;

	UPROPERTY(Transient)
	TArray<TSoftClassPtr<UObject>> ValidAllowedClasses;

	UPROPERTY(Transient)
	TArray<TSoftClassPtr<UObject>> ValidForbiddenClasses;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> StartInteractionAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> EndInteractionAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> TriggerInteractionAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> RotateClockwiseAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> RotateCounterclockwiseAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> MirrorAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> ExitAbility;

	UPROPERTY(EditDefaultsOnly, Category="Ability")
	TSubclassOf<UFortGameplayAbility> FailAbility;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	bool bShouldAddToParent;

	UPROPERTY(EditDefaultsOnly, Category="CreativeMoveTool")
	bool bShouldUseActorToSelection;

	UPROPERTY(EditDefaultsOnly, Category="ObjectInteractionBehavior")
	int32 Priority;

};

UCLASS()
class UDeleteObjects : public UObjectInteractionBehavior
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CreativeMoveTool")
	void GetDeleteActorsMeshComponents(TArray<UMeshComponent*>& Components);

	UFUNCTION(BlueprintCallable)
	void PlayDeleteAnimation();

	UPROPERTY(BlueprintReadWrite, Category="Delete")
	TArray<TObjectPtr<AActor>> DeleteActors;

};

UCLASS()
class UMoveBuildingsOnGrid : public UObjectInteractionBehavior
{
	GENERATED_BODY()

};

UCLASS()
class UMoveObjectsFreely : public UObjectInteractionBehavior
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UPlaysetPreview : public UObjectInteractionBehavior
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_PlaysetToPlace();

	UFUNCTION()
	void UpdatePreviewMeshScale();

	UPROPERTY(BlueprintReadWrite, Category="Playset Preview")
	TObjectPtr<AStaticMeshActor> PreviewPlaysetStaticMeshActor;

	UPROPERTY(EditDefaultsOnly, Category="Playset Preview")
	TObjectPtr<UStaticMesh> PlaysetMesh;

	UPROPERTY(EditDefaultsOnly, Category="Playset Preview")
	TObjectPtr<UMaterial> PlaysetMaterial;

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPreviewLocation(const FVector& NewPreviewLocation);

private:
	UPROPERTY(ReplicatedUsing=OnRep_PlaysetToPlace)
	FPlaysetInfo PlaysetToPlace;

};

UCLASS()
class UPossessPropInteraction : public UObjectInteractionBehavior
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanInteract();

};

