// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "Building/BuildingTypes.h"
#include "TimeOfDay/FortDayPhase.h"
#include "MissionTypes.generated.h"

class AActor;
class ABuildingActor;
class ABuildingContainer;
class ABuildingRift;
class ABuildingSMActor;
class AController;
class AFortAthenaCreativeSupplyDrop;
class AFortMinigame;
class AFortMission;
class AFortObjectiveBase;
class AFortPawn;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortTimeOfDayManager;
class APlayerState;
class UDataAsset;
class UFortAthenaCreativeSupplyDropOpenedParams;
class UFortBuildingContainerOpenedParams;
class UFortBuildingDamagedParams;
class UFortBuildingDestroyedParams;
class UFortBuildingEditedParams;
class UFortBuildingUpgradedParams;
class UFortCreativePickupFishedParams;
class UFortCreativePlayerStateParams;
class UFortCreativeRaceCheckpointActivatedParams;
class UFortDayPhaseChangeParams;
class UFortEnemyKilledParams;
class UFortItemCollectedParams;
class UFortItemCraftedParams;
class UFortItemDroppedParams;
class UFortMinigameEventParams;
class UFortMissionBuildingDamagedParams;
class UFortMissionConfigData;
class UFortMissionEventParams;
class UFortMissionFailedParams;
class UFortMissionForceSuccessParams;
class UFortMissionNeutralCompleteParams;
class UFortMissionSucceededParams;
class UFortNewPlayerHasBegunPlayParams;
class UFortNewPlayerParams;
class UFortObjectiveFailedParams;
class UFortObjectiveNeutralCompleteParams;
class UFortObjectiveSucceededParams;
class UFortPawnDiedParams;
class UFortPlayerBuiltParams;
class UFortPlayerDBNOEnterParams;
class UFortPlayerDBNOInterrogatedParams;
class UFortPlayerDBNORevivedParams;
class UFortPlayerDiedParams;
class UFortPlayerExitParams;
class UFortPlayerReconnectedParams;
class UFortPlayerSpawnedParams;
class UFortSchematicItemDefinition;
class UFortToggledCursorModeParams;
class UFortToggledEditModeParams;
class UFortWorldItemDefinition;
class UObject;
enum class EFortDayPhase : uint8;

UENUM(BlueprintType)
enum class EFortMissionAudibility : uint8
{
	UseVisibility = 0,
	Audible = 1,
	Inaudible = 2,
};

UENUM(BlueprintType)
enum class EFortMissionStatus : uint8
{
	// Was freshly created

	Created = 0,
	// Started but not completed

	InProgress = 1,
	// Successfully cleared

	Succeeded = 2,
	// Attempted but failed

	Failed = 3,
	// Neutral completion of the mission (neither win nor loss)

	NeutralCompletion = 4,
	// Quit the mission before completion

	Quit = 5,
	// there is no current status

	Max_None = 6 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
namespace EFortMissionType
{
	enum Type
	{
		// Only one Primary mission can be running at a time

		Primary = 0,
		// Secondary missions can be started at any time

		Secondary = 1,
		// Not defined yet or used for array length counts

		Max_None = 2 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
enum class EFortMissionVisibilityOverride : uint8
{
	Visible = 0,
	Invisible = 1,
	Max_None = 2 UMETA(DisplayName="No Override"),
};

UENUM(BlueprintType)
namespace EFortObjectiveRequirement
{
	enum Type
	{
		/** This objective is optional and is not necessary to complete the mission */
		Optional = 0,
		/** This objective is required to be successfully completed to complete the mission. Failing causes the mission to immediately fail */
		Required = 1,
		/** This objective is required to complete the mission but it is allowed to fail. Failing does not cause the mission to fail */
		RequiredButCanFail = 2,
	};
}

UENUM(BlueprintType)
enum class EFortObjectiveStatus : uint8
{
	// Was freshly created

	Created = 0,
	// Started but not completed

	InProgress = 1,
	// Successfully cleared

	Succeeded = 2,
	// Attempted but failed

	Failed = 3,
	// Neutral completion of the objective (neither win nor loss)

	NeutralCompletion = 4,
	// there is no current status

	Max_None = 5 UMETA(DisplayName="None"),
};

USTRUCT()
struct FFortFinderProperty
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TFieldPath<FProperty> Property;

	UPROPERTY()
	FString Value;

};

USTRUCT(BlueprintType)
struct FFortMissionEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	FName EventType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	FGameplayTagContainer ObjectiveHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	TObjectPtr<UObject> EventFocus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	TObjectPtr<UDataAsset> EventContent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	TObjectPtr<AActor> EventInstigator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	int32 GenericInt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	float GenericFloat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	FText GenericText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	FGuid MissionGuid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MissionEvent")
	TObjectPtr<UFortMissionEventParams> Params;

};

USTRUCT()
struct FFortMissionInstancedConfigDataBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTagQuery Query;

	UPROPERTY(Transient)
	TObjectPtr<UFortMissionConfigData> ConfigData;

};

USTRUCT()
struct FFortMissionInstancedConfigData
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FFortMissionInstancedConfigDataBucket> ConfigDataBuckets;

};

USTRUCT(BlueprintType)
struct FFortPlacementActorFinderEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor", meta=(DisplayName="Actor To Spawn", MustImplement="/Script/FortniteGame.FortSpawnableByPlacementSystemInterface"))
	TSoftClassPtr<AActor> BuildingToSpawn;

	UPROPERTY()
	TSubclassOf<ABuildingActor> BuildingClassToFind_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor")
	TArray<TSubclassOf<ABuildingActor>> BuildingClassesToFind;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor")
	FGameplayTagContainer PreferredTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor", meta=(DisplayName="Exclusion Tags"))
	FGameplayTagContainer ExlusionTags;

	UPROPERTY()
	TArray<FFortFinderProperty> RequiredProperties;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor")
	bool bIgnoreCollisionCheck;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor")
	bool bSnapToGrid;

};

USTRUCT(BlueprintType)
struct FFortPlacementActorFinderInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor", meta=(ClampMin="0.0"))
	float DistanceRangeMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor", meta=(ClampMin="1.0"))
	float DistanceRangeMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementActor")
	TArray<FFortPlacementActorFinderEntry> BuildingData;

};

USTRUCT()
struct FFortPlacementDistanceRequirements
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Distance", meta=(ClampMin="0.0"))
	float DistanceRangeMin;

	UPROPERTY(EditDefaultsOnly, Category="Distance", meta=(ClampMin="1.0"))
	float DistanceRangeMax;

};

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMissionEventParams : public UObject
{
	GENERATED_BODY()

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortAthenaCreativeSupplyDropOpenedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPawn*& OutPawn, AFortAthenaCreativeSupplyDrop*& OutAthenaCreativeSupplyDrop) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPawn* InPawn, AFortAthenaCreativeSupplyDrop* InAthenaCreativeSupplyDrop, UFortAthenaCreativeSupplyDropOpenedParams*& ThisParam);

private:
	UPROPERTY()
	TObjectPtr<AFortPawn> Pawn;

	UPROPERTY()
	TObjectPtr<AFortAthenaCreativeSupplyDrop> AthenaCreativeSupplyDrop;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortBuildingContainerOpenedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerPawn*& OutPlayerPawn, ABuildingContainer*& OutBuildingContainer) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerPawn* InPlayerPawn, ABuildingContainer* InBuildingContainer, UFortBuildingContainerOpenedParams*& ThisParam);

private:
	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

	UPROPERTY()
	TObjectPtr<ABuildingContainer> BuildingContainer;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortBuildingDamagedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(ABuildingActor*& _Building, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AController*& _DamagedBy, float& _DamageAmount);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(ABuildingActor* _Building, EFortBuildingType::Type _BuildingType, AController* _DamagedBy, float _DamageAmount, UFortBuildingDamagedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<ABuildingActor> Building;

	UPROPERTY()
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY()
	TObjectPtr<AController> DamagedBy;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortBuildingDestroyedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(ABuildingActor*& _Building, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AController*& _Destroyer);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(ABuildingActor* _Building, EFortBuildingType::Type _BuildingType, AController* _Destroyer, UFortBuildingDestroyedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<ABuildingActor> Building;

	UPROPERTY()
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY()
	TObjectPtr<AController> Destroyer;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortBuildingEditedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(ABuildingActor*& _OriginalBuilding, ABuildingActor*& _NewBuilding, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AFortPlayerController*& _Editor);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(ABuildingActor* _OriginalBuilding, ABuildingActor* _NewBuilding, EFortBuildingType::Type _BuildingType, AFortPlayerController* _Editor, UFortBuildingEditedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<ABuildingActor> OriginalBuilding;

	UPROPERTY()
	TObjectPtr<ABuildingActor> NewBuilding;

	UPROPERTY()
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> Editor;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortBuildingUpgradedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(ABuildingActor*& _OriginalBuilding, ABuildingActor*& _NewBuilding, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AFortPlayerController*& _Editor);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(ABuildingActor* _OriginalBuilding, ABuildingActor* _NewBuilding, EFortBuildingType::Type _BuildingType, AFortPlayerController* _Editor, UFortBuildingUpgradedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<ABuildingActor> OriginalBuilding;

	UPROPERTY()
	TObjectPtr<ABuildingActor> NewBuilding;

	UPROPERTY()
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> Editor;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortCreativePickupFishedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(APlayerState*& OutPlayerState, AFortPickup*& OutPickup) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(APlayerState* InPlayerState, AFortPickup* InPickup, UFortCreativePickupFishedParams*& ThisParam);

private:
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY()
	TObjectPtr<AFortPickup> Pickup;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortCreativePlayerStateParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(APlayerState*& OutPlayerState) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(APlayerState* InPlayerState, UFortCreativePlayerStateParams*& ThisParam);

private:
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortCreativeRaceCheckpointActivatedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(APlayerState*& OutPlayerState, AActor*& OutRaceCheckpoint) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(APlayerState* InPlayerState, AActor* InRaceCheckpoint, UFortCreativeRaceCheckpointActivatedParams*& ThisParam);

private:
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY()
	TObjectPtr<AActor> RaceCheckpoint;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortCreativeRiftOverlapParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> RiftSpawn;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> Player;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortCreativeRiftSpawnParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> RiftSpawn;

	UPROPERTY()
	bool bResumeRift;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortDayPhaseChangeParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortTimeOfDayManager*& _LightingAndFogManager, EFortDayPhase& _NewDayPhase);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortTimeOfDayManager* _LightingAndFogManager, EFortDayPhase _NewDayPhase, UFortDayPhaseChangeParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortTimeOfDayManager> LightingAndFogManager;

	UPROPERTY()
	EFortDayPhase NewDayPhase;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortEnemyKilledParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPawn*& _KilledPawn, AFortPlayerController*& _KilledBy);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPawn* _KilledPawn, AFortPlayerController* _KilledBy, UFortEnemyKilledParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPawn> KilledPawn;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> KilledBy;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortItemCollectedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(UFortWorldItemDefinition*& _CollectedItemDefinition, AFortPlayerController*& _CollectedBy, int32& _AmountCollected);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(const UFortWorldItemDefinition* _CollectedItemDefinition, AFortPlayerController* _CollectedBy, int32 _AmountCollected, UFortItemCollectedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> CollectedItemDefinition;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> CollectedBy;

	UPROPERTY()
	int32 AmountCollected;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortItemCraftedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(UFortSchematicItemDefinition*& _SchematicDefinition, AFortPlayerController*& _CraftedBy, int32& _AmountCrafted, bool& _bItemWasQuickCrafted);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(const UFortSchematicItemDefinition* _SchematicDefinition, AFortPlayerController* _CraftedBy, int32 _AmountCrafted, bool _bItemWasQuickCrafted, UFortItemCraftedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<UFortSchematicItemDefinition> SchematicDefinition;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> CraftedBy;

	UPROPERTY()
	int32 AmountCrafted;

	UPROPERTY()
	bool bItemWasQuickCrafted;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortItemDroppedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(UFortWorldItemDefinition*& _DroppedItemDefinition, AFortPlayerController*& _DroppedBy, int32& _AmountCollected);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(const UFortWorldItemDefinition* _DroppedItemDefinition, AFortPlayerController* _DroppedBy, int32 _AmountCollected, UFortItemDroppedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> DroppedItemDefinition;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> DroppedBy;

	UPROPERTY()
	int32 AmountDropped;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMinigameEventParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortMinigame*& OutMinigame, APlayerState*& OutPlayerState) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortMinigame* InMinigame, APlayerState* InPlayerState, UFortMinigameEventParams*& ThisParam);

protected:
	UPROPERTY()
	TObjectPtr<AFortMinigame> Minigame;

	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMissionBuildingDamagedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AActor*& _Actor, AController*& _DamagedBy, float& _DamageAmount);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AActor* _Actor, AController* _DamagedBy, float _DamageAmount, UFortMissionBuildingDamagedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AActor> Actor;

	UPROPERTY()
	TObjectPtr<AController> DamagedBy;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMissionFailedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortMission*& _FailedMission);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortMission* _FailedMission, UFortMissionFailedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortMission> FailedMission;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMissionForceSuccessParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(float& _FractionCompleted);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(float _FractionCompleted, UFortMissionForceSuccessParams*& ThisParam);

	UPROPERTY()
	float FractionCompleted;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMissionNeutralCompleteParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortMission*& _NeutrallyCompletedMission);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortMission* _NeutrallyCompletedMission, UFortMissionNeutralCompleteParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortMission> NeutrallyCompletedMission;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortMissionSucceededParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortMission*& _SucceededMission);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortMission* _SucceededMission, UFortMissionSucceededParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortMission> SucceededMission;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortNewPlayerHasBegunPlayParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _NewPlayerPC);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _NewPlayerPC, UFortNewPlayerHasBegunPlayParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> NewPlayerPC;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortNewPlayerParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _NewPlayerController);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _NewPlayerController, UFortNewPlayerParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> NewPlayerController;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortObjectiveFailedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortObjectiveBase*& _FailedObjective);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortObjectiveBase* _FailedObjective, UFortObjectiveFailedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortObjectiveBase> FailedObjective;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortObjectiveNeutralCompleteParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortObjectiveBase*& _NeutrallyCompletedObjective);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortObjectiveBase* _NeutrallyCompletedObjective, UFortObjectiveNeutralCompleteParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortObjectiveBase> NeutrallyCompletedObjective;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortObjectiveSucceededParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortObjectiveBase*& _SucceededObjective);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortObjectiveBase* _SucceededObjective, UFortObjectiveSucceededParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortObjectiveBase> SucceededObjective;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPawnDiedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPawn*& OutKilledPawn, AController*& OutKilledController, AController*& OutKilledBy, FGameplayTagContainer& OutTags);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPawn* InKilledPawn, AController* InKilledController, AController* InKilledBy, FGameplayTagContainer InTags, UFortPawnDiedParams*& ThisParam);

protected:
	UPROPERTY()
	TObjectPtr<AFortPawn> KilledPawn;

	UPROPERTY()
	TObjectPtr<AController> KilledController;

	UPROPERTY()
	TObjectPtr<AController> KilledBy;

	UPROPERTY()
	FGameplayTagContainer Tags;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerAbandonParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl AbandoningPlayerId;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerBuiltParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(ABuildingActor*& _Building, TEnumAsByte<EFortBuildingType::Type>& _BuildingType, AFortPlayerController*& _Builder);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(ABuildingActor* _Building, EFortBuildingType::Type _BuildingType, AFortPlayerController* _Builder, UFortPlayerBuiltParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<ABuildingActor> Building;

	UPROPERTY()
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> Builder;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerDBNOEnterParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerPawn*& _KilledPlayer, AController*& _KilledBy);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerPawn* _KilledPlayer, AController* _KilledBy, UFortPlayerDBNOEnterParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> KilledPlayer;

	UPROPERTY()
	TObjectPtr<AController> KilledBy;

};

UCLASS(NotPlaceable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerDBNOInterrogatedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerPawn*& OutInterrogatedPlayer, AController*& OutInterrogatedBy) const;

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerPawn* InInterrogatedPlayer, AController* InInterrogatedBy, UFortPlayerDBNOInterrogatedParams*& ThisParam);

protected:
	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> InterrogatedPlayer;

	UPROPERTY()
	TObjectPtr<AController> InterrogatedBy;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerDBNORevivedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerPawn*& _RevivedPlayer, AController*& _RevivedBy);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerPawn* _RevivedPlayer, AController* _RevivedBy, UFortPlayerDBNORevivedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> RevivedPlayer;

	UPROPERTY()
	TObjectPtr<AController> RevivedBy;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerDiedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerPawn*& _KilledPlayer, AController*& _KilledPlayerController, AController*& _KilledBy, FGameplayTagContainer& _Tags);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerPawn* _KilledPlayer, AController* _KilledPlayerController, AController* _KilledBy, FGameplayTagContainer _Tags, UFortPlayerDiedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> KilledPlayer;

	UPROPERTY()
	TObjectPtr<AController> KilledPlayerController;

	UPROPERTY()
	TObjectPtr<AController> KilledBy;

	UPROPERTY()
	FGameplayTagContainer Tags;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerExitParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _ExitingPlayerController);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _ExitingPlayerController, UFortPlayerExitParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> ExitingPlayerController;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerReconnectedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _ReconnectedPlayerPC);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _ReconnectedPlayerPC, UFortPlayerReconnectedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> ReconnectedPlayerPC;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlayerSpawnedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _SpawnedPlayerController);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _SpawnedPlayerController, UFortPlayerSpawnedParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> SpawnedPlayerController;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortRiftBeginOverlapPlayerParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> Rift;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> Player;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortRiftCreatedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> Rift;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortRiftDestroyedParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> Rift;

	UPROPERTY()
	bool bPauseRift;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortRiftEndOverlapPlayerParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> Rift;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> Player;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortStartLeavingZoneParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _PlayerControllerRequestingLeaving);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> PlayerControllerRequestingLeaving;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortToggledCursorModeParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _PlayerThatToggledCursorMode, bool& InCursorMode);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _PlayerThatToggledCursorMode, bool InCursorMode, UFortToggledCursorModeParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> PlayerThatToggledCursorMode;

	UPROPERTY()
	bool bInCursorMode;

};

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortToggledEditModeParams : public UFortMissionEventParams
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="params")
	void BreakParams(AFortPlayerController*& _PlayerThatToggledEditMode, ABuildingSMActor*& EditableActor, bool& InEditMode);

	UFUNCTION(BlueprintCallable, Category="params")
	void SetParams(AFortPlayerController* _PlayerThatToggledEditMode, ABuildingSMActor* InEditableActor, bool InEditMode, UFortToggledEditModeParams*& ThisParam);

	UPROPERTY()
	TObjectPtr<AFortPlayerController> PlayerThatToggledEditMode;

	UPROPERTY()
	TObjectPtr<ABuildingSMActor> EditableActor;

	UPROPERTY()
	bool bInEditMode;

};

