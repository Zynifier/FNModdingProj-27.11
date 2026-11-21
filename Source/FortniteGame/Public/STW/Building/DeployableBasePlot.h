// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "Items/FortInventoryOwnerInterface.h"
#include "DeployableBasePlot.generated.h"

class ABuildingActor;
class ADeployableBaseCore;
class ADeployableBasePlot;
class AFortDeployableBasePickup;
class AFortInventory;
class AFortPlayerStart;
class UBoxComponent;
class UFortDeployableBaseRecord;
class UGameplayEffect;
class UPrimitiveComponent;
class USceneComponent;
enum class EDeployableBaseBuildingState : uint8;

UENUM()
enum class EDeployableBaseBoxType : uint8
{
	BuildSpace = 0,
	// the area you can build in

	SaveSpace = 1,
	// the area of buildable space that gets saved

	PlotSpace = 2,
	// the area that encompasses the entire plot

	NumSpaceTypes = 3,
};

UENUM(BlueprintType)
enum class EDeployableBaseBuildingState : uint8
{
	// goal states

	Empty = 0,
	Built = 1,
	Unoccupied = 2,
	// internal states

	WaitingToBuild = 3,
	Building = 4,
	WaitingToDestroy = 5,
	Destroying = 6,
	WaitingToReset = 7,
	Resetting = 8,
};

UENUM()
enum class EDeployableBaseConstructionStatus : uint8
{
	Constructing = 0,
	Destroying = 1,
	Finished = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeployableBaseCoreCreated, ADeployableBasePlot*, Plot, ADeployableBaseCore*, Core);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeployableBaseCoreDestroyed, ADeployableBasePlot*, Plot, ADeployableBaseCore*, Core);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeployableBasePlotSpacesChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOccupantIdChanged, ADeployableBasePlot*, Plot);

USTRUCT()
struct FDeferredActorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingActor> BuildingActor;

	UPROPERTY()
	int32 ActorRecordIndex;

	UPROPERTY()
	FTransform BuildingTransform;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ADeployableBasePlot : public ABuildingGameplayActor, public IFortInventoryOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Deployable Base")
	int32 GetNumOfItemsInPlot() const;

	UFUNCTION(BlueprintPure, Category="Deployable Base")
	const FUniqueNetIdRepl& GetOccupantNetID() const;

	UFUNCTION(BlueprintCallable, Category="Deployable Base")
	AFortPlayerStart* GetPlayerStart();

	UFUNCTION(BlueprintPure, Category="Deployable Base")
	bool IsBuildingActorWithinBuildableSpace(const ABuildingActor* ActorToCheck, const FVector& GridLocation) const;

	UFUNCTION(BlueprintPure, Category="Deployable Base")
	bool IsOccupant(const FUniqueNetIdRepl& UserId) const;

	UFUNCTION(BlueprintPure, Category="Deployable Base")
	bool IsOccupied() const;

	UFUNCTION(BlueprintNativeEvent, Category="Interact Events")
	void OnBuildingStateTransition(EDeployableBaseBuildingState InPreviousState, EDeployableBaseBuildingState InCurrentState);

	UFUNCTION(BlueprintNativeEvent, Category="Interact Events")
	void OnCurrentBuildingStateSet(EDeployableBaseBuildingState InCurrentBuildingState);

	UFUNCTION(BlueprintCallable, Category="Deployable Base")
	void SetContextComponent(UPrimitiveComponent* ContextComponent);

protected:
	UFUNCTION(NetMulticast, Reliable)
	void HandleBuildingStateTransition(EDeployableBaseBuildingState InPreviousState, EDeployableBaseBuildingState InCurrentState);

	UFUNCTION()
	void OnRep_BuildableSpaceExpansionVector();

	UFUNCTION()
	void OnRep_CurrentBuildingState();

	UFUNCTION()
	void OnRep_OccupantNetID();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OccupantNetID)
	FUniqueNetIdRepl OccupantNetID;

	UPROPERTY(Transient)
	FFortCloudSaveInfo OccupantNextCloudSaveInfo;

	UPROPERTY(Transient)
	TObjectPtr<UFortDeployableBaseRecord> OccupantDeployableBaseRecord;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Deployable Base", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> BuildableSpaceComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Deployable Base", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> SavableSpaceComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Deployable Base", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> EntirePlotSpaceComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Deployable Base", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SpawnOffsetComponent;

	UPROPERTY(Transient, Export, meta=(ArraySizeEnum="/Script/FortniteGame.EDeployableBaseBoxType", EditInline="true"))
	TObjectPtr<UBoxComponent> BuildableAreasArray[3];

	UPROPERTY(EditDefaultsOnly, Category="Deployable Base")
	TSoftClassPtr<ADeployableBaseCore> DeployableBaseCoreClass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Deployable Base")
	TObjectPtr<ADeployableBaseCore> DeployableBaseCore;

	UPROPERTY(Transient)
	uint8 bDirty : 1;

	UPROPERTY(Transient)
	uint8 bDirtiedSinceLastWriteToBuffer : 1;

	UPROPERTY(Transient)
	uint8 bCloudFileSavedSinceLastCloudItemUpdate : 1;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentBuildingState, Category="Deployable Base")
	EDeployableBaseBuildingState CurrentBuildingState;

	UPROPERTY(Transient)
	EDeployableBaseBuildingState GoalBuildingState;

	UPROPERTY(BlueprintAssignable)
	FOnOccupantIdChanged OnOccupantIdChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDeployableBaseCoreCreated OnDeployableBaseCoreCreated;

	UPROPERTY(BlueprintAssignable)
	FOnDeployableBaseCoreDestroyed OnDeployableBaseCoreDestroyed;

	UPROPERTY(BlueprintAssignable)
	FOnDeployableBasePlotSpacesChanged OnDeployableBasePlotSpacesChanged;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortDeployableBasePickup>> OutstandingAssociatedPickups;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortInventory> PlotInventory;

	UPROPERTY(Transient)
	int32 DeferredActorIdxToResumeAt;

	UPROPERTY(Transient)
	int32 NumActorsFromRecordDestroyed;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BuildableSpaceExpansionVector)
	FIntVector BuildableSpaceExpansionVector;

	UPROPERTY(EditDefaultsOnly, Category="Deployable Base")
	int32 MaxActorsToCreatePerBuildingCall;

	UPROPERTY(EditDefaultsOnly, Category="Deployable Base")
	int32 MaxActorsToDestroyPerDestroyCall;

	UPROPERTY(EditDefaultsOnly, Category="Deployable Base")
	float DelayBetweenActorRecordBuilding;

	UPROPERTY(EditDefaultsOnly, Category="Deployable Base")
	float DelayBetweenActorRecordDestroying;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStart> PlayerStart;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Deployable Base")
	TSubclassOf<UGameplayEffect> ConstructionTimeEffect;

	UPROPERTY(Transient)
	TArray<FDeferredActorData> DeferredConstructionActors;

private:
	UPROPERTY(Transient, Replicated, meta=(ArraySizeEnum="/Script/FortniteGame.EDeployableBaseBoxType"))
	FBox BuildableAreasStructuralSupportBoxesArray[3];

};

