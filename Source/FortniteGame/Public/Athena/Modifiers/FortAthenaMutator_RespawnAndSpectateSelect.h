// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_SpectateBeforeRespawn.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_RespawnAndSpectateSelect.generated.h"

class AActor;
class AFortAthenaMutator_RespawnAndSpectateSelect;
class UFortCameraMode;
class UObject;
class UTexture2D;
enum class EFortSafeZoneState : uint8;

UENUM()
enum class ERespawnAndSpectateClientEventId : uint8
{
	/** Tells the client to show the respawn select screen UI */
	ShowUI = 0,
	/** Tells the client to hide the respawn select screen UI */
	HideUI = 1,
	/** Tells the client to modify the UI when respawning becomes available */
	ShowRespawnAvailableUI = 2,
	/** Number of total values, not to be used */
	MAX = 3 UMETA(Hidden),
};

UENUM()
enum class ERespawnAndSpectateServerPayloadId : uint8
{
	/** The player has chosen to spectate this respawn/spectate target */
	SpectateTargetSelected = 0,
	/** The player has chosen to respawn at this respawn/spectate target */
	RespawnTargetSelected = 1,
	/** The player has chosen to spectate and respawn this item */
	SpectateAndRespawnTargetSelected = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRespawnAndSpectateSelectAvailableOptionsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRespawnAndSpectateSelectPlayerRespawned);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRespawnAndSpectateSelectRespawnBecameAvailable);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRespawnAndSpectateSelectSetSpectateId, int32, SpectateId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRespawnAndSpectateSelectSetVisibility, bool, bNewVisibility);

USTRUCT()
struct FRespawnAndSpectateTargetData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_RespawnAndSpectateSelect> OwningMutator;

	UPROPERTY()
	uint8 bEnabled : 1;

	UPROPERTY(NotReplicated)
	uint8 bPrevAvailableOnClient : 1;

	UPROPERTY(NotReplicated)
	uint8 bPrevEnabledOnClient : 1;

	UPROPERTY()
	uint8 bShouldBeSelectedByDefault : 1;

	UPROPERTY()
	uint8 bHiddenAndAutoSelectedFallback : 1;

	UPROPERTY()
	float PostDeathDisableTime;

protected:
	UPROPERTY()
	int32 Id;

	UPROPERTY()
	int32 DisplayPriority;

	UPROPERTY()
	uint8 Team;

	UPROPERTY()
	TObjectPtr<AActor> RespawnTargetActor;

	UPROPERTY(NotReplicated)
	TObjectPtr<AActor> CameraActor;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_RespawnAndSpectateSelect : public AFortAthenaMutator_SpectateBeforeRespawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const bool GetCanPlayerSelectRespawnTargetBeforeTheyCanRespawn() const;

protected:
	UFUNCTION()
	void OnRep_ManagerObject();

	UFUNCTION()
	void OnRep_RespawnTargetDataArray();

	UFUNCTION()
	void OnSafeZoneStateChanged(EFortSafeZoneState InSafeZoneState);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bShouldBeActive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bShouldSetClientReadyOnRespawnPlayerFailSafe;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bCanPlayerSelectRespawnTargetBeforeTheyCanRespawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bAllowRespawnOnLivingTeammates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bAllowRespawnOnLivingSquadmates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bCreateDefaultSpawnLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat bShowDefaultSpawnLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_RespawnAndSpectateSelect")
	TSubclassOf<AActor> DefaultSpawnLocationCameraClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FText DefaultRespawnLabelText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	TObjectPtr<UTexture2D> DefaultRespawnTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RandomRespawnRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RespawnBaseRotationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RandomRespawnRotationDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RespawnHeightOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat MinRespawnHeightAboveGround;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat ForceRespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat DeadTargetAvailabilityTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	int32 DisplayPriority_Teammate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spectate")
	TSubclassOf<UFortCameraMode> CameraModeOverrideForNonPlayers;

	UPROPERTY(ReplicatedUsing=OnRep_RespawnTargetDataArray)
	TArray<FRespawnAndSpectateTargetData> RespawnTargetDataArray;

	UPROPERTY(Replicated)
	bool bAreAllRespawnTargetsAvailableToAllPlayersCheat;

	UPROPERTY(ReplicatedUsing=OnRep_ManagerObject)
	TObjectPtr<UObject> ManagerObject;

	UPROPERTY(BlueprintAssignable)
	FRespawnAndSpectateSelectSetVisibility RespawnAndSpectateSelectSetVisibility;

	UPROPERTY(BlueprintAssignable)
	FRespawnAndSpectateSelectSetSpectateId RespawnAndSpectateSelectSetSpectateId;

	UPROPERTY(BlueprintAssignable)
	FRespawnAndSpectateSelectAvailableOptionsChanged RespawnAndSpectateSelectAvailableOptionsChanged;

	UPROPERTY(BlueprintAssignable)
	FRespawnAndSpectateSelectPlayerRespawned RespawnAndSpectateSelectPlayerRespawned;

	UPROPERTY(BlueprintAssignable)
	FRespawnAndSpectateSelectRespawnBecameAvailable RespawnAndSpectateSelectRespawnBecameAvailable;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_RespawnAndSpectateSelect")
	float ScreenFadeOutDeathCamTime;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_RespawnAndSpectateSelect", meta=(EditCondition="ScreenFadeOutDeathCamTime>0"))
	float ScreenFadeInSpectateCamTime;

};

UCLASS()
class UFortCheatManager_RespawnAndSpectateSelect : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RespawnScreenToggleMakeAllRespawnTargetsAvailableToAllPlayers();

};

UINTERFACE()
class URespawnAndSpectateSelectManager : public UInterface
{
	GENERATED_BODY()
};

class IRespawnAndSpectateSelectManager
{
	GENERATED_BODY()

};

