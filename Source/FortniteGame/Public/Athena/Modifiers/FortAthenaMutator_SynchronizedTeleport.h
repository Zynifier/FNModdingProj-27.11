// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SynchronizedTeleport.generated.h"

class AController;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UGameplayEffect;
class USynchronizedTeleportPlayerComponent;

UENUM(BlueprintType)
enum class ESynchronizedTeleportHealthAndShieldResetType : uint8
{
	/** Do not execute any code for health or shield */
	None = 0,
	/** Call AFortGameStateAthena::EvaluateHealthAndShieldMutators() to use the settings from our HealthAndShield mutator */
	EvaluateHealthAndShieldMutators = 1,
	/** Set health to max */
	MaxHealth = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClientTeleportComplete, AFortPlayerStateAthena*, FortPlayerStateAthena);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGroupTeleportCompleteForPlayer, AFortPlayerPawn*, FortPlayerPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGroupTeleportComplete);

USTRUCT(BlueprintType)
struct FBeginGroupTeleportParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	FText HudReasonText;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bRespawnPlayers;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bForceKillPlayers;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bAutoReleaseFromStasis;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	float FadeTime;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	ESynchronizedTeleportHealthAndShieldResetType HealthAndShieldResetType;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bResetPlayerInventories;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bRandomizePlayerInventories;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bReinitializePlayerAbilities;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bBlockPickupsDuringTeleport;

	UPROPERTY(EditDefaultsOnly, Category="BeginGroupTeleportParams")
	bool bFadeSound;

};

USTRUCT()
struct FSynchronizedTeleportPlayer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> FortPlayerState;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SynchronizedTeleport : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FBeginGroupTeleportParams DefaultBeginGroupTeleportParams;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FScalableFloat TeleportFailsafeTimeout;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FScalableFloat TeleportFailsafeRetryTime;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FScalableFloat RespawnLocationTolerance;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FGameplayTagContainer EventsToSendOnTeleport;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	TSubclassOf<UGameplayEffect> HidePawnGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FScalableFloat bHoldLoadingScreenUntilGroupTeleportIsComplete;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FScalableFloat StreamInDistanceDuringLoadOverride;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	FScalableFloat bStillInvincibleAfterFailsafeTimer;

	UPROPERTY(EditDefaultsOnly, Category="Teleport")
	TSubclassOf<USynchronizedTeleportPlayerComponent> CustomTeleportPlayerComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SynchronizedTeleport")
	bool bAutoEquipPickAxe;

private:
	UFUNCTION()
	void OnRep_TeleportComplete();

	UPROPERTY(Replicated)
	TArray<int32> InProgressTeleportPlayerIDs;

	UPROPERTY(ReplicatedUsing=OnRep_TeleportComplete)
	bool bTeleportComplete;

	UPROPERTY()
	TArray<TObjectPtr<AController>> PlayersInStasis;

};

