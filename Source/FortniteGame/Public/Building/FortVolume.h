// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortMutatorContext.h"
#include "Building/BuildingTypes.h"
#include "Building/FortSpatialGameplayInterface.h"
#include "Building/FortVolumeAccessorInterface.h"
#include "Building/SpatialGameplay/SpatialGameplayTypes.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortHUDMessageData.h"
#include "GameplayVolume.h"
#include "FortVolume.generated.h"

class AActor;
class AAthenaNavInvokerBox;
class AController;
class AFortAthenaCreativePortal;
class AFortMinigame;
class AFortMissionStormShield;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortVolume;
class APawn;
class UActorComponent;
class UAsyncTaskQueue;
class UCreativeIslandResourceManagerComponent;
class UDevicesDataTrackingComponent;
class UFortPlayerSaveComponent;
class UFortPlaysetItemDefinition;
class UFortVolumeObjectTrackingComponent;
class UFortVolumePersistenceOptions;
class UPrimitiveComponent;
class UStaticMeshComponent;
enum class EFortVolumeType : uint8;

UENUM(BlueprintType)
enum class EActorFilterPolicy : uint8
{
	/*	Destroy actors that don't have a volume reference */
	POL_FilterActorsWithoutVolumeReference = 0,
	/*	Previewing is primarily used by the creative move tool.
		Adding these actors can skew is in valid volume tests giving incorrect results.	*/
	POL_IgnorePreviewActors = 1,
};

UENUM(BlueprintType)
enum class EVolumeShape : uint8
{
	Sphere = 0,
	Box = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorEnterAtLocation, AActor*, Actor, const FVector&, Location);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnActorEnterExitVolume, AActor*, Actor, UActorComponent*, ActorComponent, APawn*, InstigatorPawn, AFortVolume*, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishVolumeClear);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRestrictionEnabledChanged, bool, bEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowHUDMessage, FHUDMessageData, MessageData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawningFromSaveFinish);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerWidgetActorUpdated, const AActor*, TimerWidgetActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTrackingComponentReplicated);

USTRUCT()
struct FVolumeActorStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<TEnumAsByte<EFortBuildingType::Type>, int32> BuildingTypeCounts;

};

UCLASS(Config=Game, MinimalAPI)
class AFortVolume : public AGameplayVolume, public IFortMutatorOwner, public IFortVolumeAccessor, public IFortSpatialGameplayInterface, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddActor(AActor* ActorToAdd);

	UFUNCTION(BlueprintCallable, Category="Volume")
	void DestroyVolume();

	UFUNCTION(BlueprintPure)
	FString GetAccountIdOwnerOfIsland() const;

	UFUNCTION(BlueprintPure, Category="Volume")
	virtual TArray<AActor*> GetActorsWithinVolumeByClass(TSubclassOf<AActor> ActorClass) const;

	UFUNCTION(BlueprintPure, Category="Volume")
	virtual const UFortPlaysetItemDefinition* GetCurrentPlayset() const;

	UFUNCTION(BlueprintPure, Category="Volume")
	UFortVolumePersistenceOptions* GetFortVolumePersistenceOptions() const;

	UFUNCTION(BlueprintPure)
	EFortVolumeType GetFortVolumeType() const;

	UFUNCTION(BlueprintPure, Category="Volume")
	AFortMinigame* GetMinigame() const;

	UFUNCTION(BlueprintPure, Category="Volume")
	int32 GetNumPlayersInVolume() const;

	UFUNCTION(BlueprintPure)
	UFortVolumeObjectTrackingComponent* GetObjectTrackingComponent() const;

	UFUNCTION(BlueprintPure, Category="Volume")
	virtual UStaticMeshComponent* GetStaticMesh() const;

	UFUNCTION(BlueprintPure)
	bool GetUserGeneratedContentRestricted() const;

	UFUNCTION(BlueprintPure, Category="Volume")
	bool HasVolumeBoundsBlocked() const;

	UFUNCTION(BlueprintCallable, Category="Volume")
	bool IsPlayerAllowedInVolume(AFortPlayerController* NewUser);

	UFUNCTION(BlueprintPure)
	virtual bool IsReadOnly() const;

	UFUNCTION(BlueprintPure)
	bool IsReady() const;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Volume")
	void ServerClearVolume();

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortVolume", meta=(EditInline="true"))
	TObjectPtr<UDevicesDataTrackingComponent> DevicesDataTrackingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	TObjectPtr<UFortPlaysetItemDefinition> OverridePlayset;

	UPROPERTY(BlueprintReadOnly, Category="Volume")
	uint8 bDestroyingActors : 1;

	UPROPERTY(Transient, BlueprintAssignable)
	FOnFinishVolumeClear OnFinishVolumeClear;

	UPROPERTY(EditAnywhere, Category="Volume")
	TSubclassOf<AAthenaNavInvokerBox> NavInvokerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Volume")
	TArray<TObjectPtr<AFortMissionStormShield>> StormShields;

	UPROPERTY(Transient, BlueprintAssignable, BlueprintCallable, Category="HUD Message")
	FOnShowHUDMessage OnShowHUDMessage;

	UPROPERTY(BlueprintAssignable)
	FOnRestrictionEnabledChanged OnUserGeneratedContentRestrictionChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	uint8 bShouldTrackObjects : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	uint8 bShouldIgnoreTransientObjectLimits : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	uint8 bAddToFortVolumeGrid : 1;

	UPROPERTY(EditDefaultsOnly, Category="Volume")
	TArray<EActorFilterPolicy> ActorFilterPolicies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Volume")
	FScalableFloat IsHotfixablyEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Volume")
	EVolumeShape BoundsShape;

private:
	UFUNCTION()
	void AddOrRemovePawnAfterVehicleChange(AFortPlayerPawn* FortPawn, AActor* NewVehicle, AActor* OldVehicle);

	UFUNCTION()
	void AddSelfToVolumeManager();

	UFUNCTION()
	void OnRep_CurrentPlayset();

	UFUNCTION()
	void OnRep_ObjectTrackingComponent();

	UFUNCTION()
	void OnRep_UserGeneratedContentRestrictions();

	UFUNCTION()
	void OnRep_VolumeState();

	UFUNCTION()
	void RemoveActorWhenDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void RemoveActorWhenEndPlay(AActor* Actor, const EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void RemoveAthenaPawnWhenDied(AFortPlayerPawnAthena* FortPlayerPawnAthena);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ObjectTrackingComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVolumeObjectTrackingComponent> ObjectTrackingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="Volume", meta=(AllowPrivateAccess="TRUE"))
	uint8 bNeverAllowSaving : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentPlayset)
	TObjectPtr<UFortPlaysetItemDefinition> CurrentPlayset;

	UPROPERTY(Transient)
	FVolumeActorStats ActorStats;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaCreativePortal>> LinkedPortals;

	UPROPERTY(EditAnywhere, Category="Volume", meta=(AllowPrivateAccess="true"))
	uint8 bAdjustNavInvokerSizeToVolume : 1;

	UPROPERTY(EditAnywhere, Category="Volume", meta=(AllowPrivateAccess="true"))
	uint8 bCreateNavOctreeInclusionBound : 1;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> DeferredDestroyActors;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_VolumeState, Category="Volume")
	ESpatialLoadingState VolumeState;

	UPROPERTY(Transient)
	TObjectPtr<UAsyncTaskQueue> TaskQueue;

	UPROPERTY(Transient)
	int32 AIGroupEncounterID;

	UPROPERTY(Config)
	int32 MaxActiveAI;

	UPROPERTY()
	TObjectPtr<AAthenaNavInvokerBox> NavigationInvokerBox;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> TimerWidgetActors;

	UPROPERTY(Transient, BlueprintAssignable, Category="Volume", meta=(AllowPrivateAccess="true"))
	FOnActorEnterExitVolume OnActorEnter;

	UPROPERTY(Transient, BlueprintAssignable, Category="Volume", meta=(AllowPrivateAccess="true"))
	FOnActorEnterExitVolume OnActorExit;

	UPROPERTY(ReplicatedUsing=OnRep_UserGeneratedContentRestrictions)
	bool bUserGeneratedContentRestricted;

	UPROPERTY(Transient, Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeIslandResourceManagerComponent> IslandResourceManagerComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerSaveComponent> PlayerSaveComponent;

	UPROPERTY(Transient, Replicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVolumePersistenceOptions> FortVolumePersistenceOptions;

};

