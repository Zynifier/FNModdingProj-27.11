// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/BuildingActor.h"
#include "BuildingRift.generated.h"

class AFortAIPawn;
class UBillboardComponent;
class UEnvQuery;
class UFortSpectateClickableMapIcon;
class USphereComponent;

UENUM()
namespace EFortRiftSlotStatus
{
	enum Type
	{
		Reserved = 0,
		Occupied = 1,
		Max_None = 2,
	};
}

UENUM()
enum class EFortRiftSpawnSlotSelectionMode : uint8
{
	Random = 0,
	BestScore = 1,
};

UENUM(BlueprintType)
enum class ERiftCosmeticState : uint8
{
	None = 0,
	Intro = 1,
	Idle = 2,
	RampUp = 3,
	ShouldDie = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBuildingRiftSpawnedAISignature);

USTRUCT()
struct FFortRiftReservationHandle
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(IgnoreForMemberInitializationTest))
	int32 RiftReservationID;

};

USTRUCT()
struct FFortRiftReservation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bDesiredVisible : 1;

	UPROPERTY()
	uint8 bDesiredActive : 1;

	UPROPERTY()
	FFortRiftReservationHandle ReservationHandle;

};

USTRUCT()
struct FFortSpawnSlotData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector SpawnSlotLocation;

	UPROPERTY()
	TObjectPtr<AFortAIPawn> OccupyingAI;

	UPROPERTY()
	TEnumAsByte<EFortRiftSlotStatus::Type> SlotStatus;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class ABuildingRift : public ABuildingActor, public IFortMarkableActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BlueprintHideRift();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BlueprintHideVFX();

	UFUNCTION(NetMulticast, Unreliable)
	FORTNITEGAME_API void BroadcastRiftSpawningAI();

	UFUNCTION(BlueprintCallable, Category="BuildingRift")
	FORTNITEGAME_API void DestroyNearbyBuildings(bool bDestroyOnlyPlayerBuiltBuildings);

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API void NotifyAIPawnSpawned(AFortAIPawn* SpawnedAI, const FVector& SpawnSlotLocation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BuildingRift")
	FORTNITEGAME_API void OnActivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="BuildingRift")
	FORTNITEGAME_API void OnActivated_Server();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BuildingRift")
	FORTNITEGAME_API void OnDeactivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="BuildingRift")
	FORTNITEGAME_API void OnDeactivated_Server();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Spawning")
	FORTNITEGAME_API void OnFinishedEncounterSpawn(AFortAIPawn* SpawnedAI);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BuildingRift")
	FORTNITEGAME_API void OnPlaced();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BuildingRift")
	FORTNITEGAME_API void OnRemoved();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_RiftIsActive();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_RiftIsVisible();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BuildingRift")
	FORTNITEGAME_API void OnSpawnAI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="BuildingRift")
	FORTNITEGAME_API void OnStartedEncounterSpawn(AFortAIPawn* SpawnedAI);

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetNewEQSData(UEnvQuery* NewEnvironmentQuery, TArray<FEnvNamedValue> NewQueryParams);

	UPROPERTY()
	float DistToTarget;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	bool bSendMissionEvents;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	bool bDelayDeath;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	EFortRiftSpawnSlotSelectionMode SlotSelectionMode;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BP_Cosmetic_Idle();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BP_Cosmetic_Intro();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BP_Cosmetic_RampUp();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BP_Cosmetic_ShouldDie();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void StartEnvironmentQuery();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float MinSpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float MaxSpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float CosmeticStateIdleDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float IntroToBeginSpawningDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	TObjectPtr<UEnvQuery> EnvironmentQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	TArray<FEnvNamedValue> QueryParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float QueryRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float QueryMinDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	bool bOverrideQueryMinDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Special Actor Settings")
	bool bRegisterAsASpecialActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Special Actor Settings")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor Settings")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor Settings")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor Settings")
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor Settings")
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Actor Settings")
	bool bShouldDrawCompassIcon;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	bool bSpawnUsingRiftRotation;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	float SpawnPointRadius;

	UPROPERTY(Transient)
	FName SpecialActorID;

	UPROPERTY()
	TArray<FVector> FreeSpawnSlots;

	UPROPERTY()
	TArray<FFortSpawnSlotData> UsedSpawnSlots;

	UPROPERTY(ReplicatedUsing=OnRep_RiftIsVisible)
	bool bRiftIsVisible;

	UPROPERTY(ReplicatedUsing=OnRep_RiftIsActive)
	bool bRiftIsActive;

	UPROPERTY()
	bool bIsReadyToSpawnAI;

	UPROPERTY(Transient)
	bool bHasBeenInitialized;

	UPROPERTY()
	bool bHasBadRiftSlots;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	bool bRecalculateSpawnPointsPeriodically;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	float SpawnPointEvaluationInterval;

	UPROPERTY(BlueprintAssignable)
	FOnBuildingRiftSpawnedAISignature OnBuildingRiftSpawnedAI;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift")
	bool bCreateOverlapSphere;

	UPROPERTY(EditDefaultsOnly, Category="BuildingRift", meta=(EditCondition="bCreateOverlapSphere"))
	FScalableFloat OverlapSphereRadius;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USphereComponent> OverlapSphereComponent;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	FName DestructionLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	FRotator LootDropTossDirection;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	float LootDropConeHalfAngle;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	float LootDropSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Marking")
	FVector MarkerPositionOffset;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CosmeticState, Category="BuildingRift")
	ERiftCosmeticState CosmeticState;

	UPROPERTY(EditDefaultsOnly, Export, Category="Spectate", meta=(EditInline="true"))
	TObjectPtr<UFortSpectateClickableMapIcon> SpectatorMapIcon;

private:
	UFUNCTION()
	FORTNITEGAME_API void OnGameDifficultyChanged();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_CosmeticState();

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

	UPROPERTY(Transient)
	TArray<FFortRiftReservation> RiftReservations;

};

