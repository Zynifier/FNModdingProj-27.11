// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "FortInteractInterface.h"
#include "FortControllerComponent_Interaction.generated.h"

class AActor;
class AController;
class APawn;
class UAudioComponent;
class UFortInteractContextInfo;
class UObject;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class EInteractionOrigin : uint8
{
	Camera = 0,
	Character = 1,
};

UENUM(BlueprintType)
enum class ETouchInteractMode : uint8
{
	Off = 0,
	InWorld = 1,
	Buttons = 2,
};

USTRUCT(BlueprintType)
struct FInteractionPointOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionPointOptions")
	EInteractionOrigin InteractionOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionPointOptions")
	float InteractDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionPointOptions")
	float InteractHighlightDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InteractionPointOptions")
	float InteractExtentRadius;

};

USTRUCT()
struct FServerLongInteractInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Target;

};

UCLASS(Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Interaction : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject"))
	void AddInteractionPointOptions(const FInteractionPointOptions& Options, UObject* ContextObject, float Priority, bool bEnabled = true);

	UFUNCTION(BlueprintCallable)
	bool BP_ServerAttemptInteractInternal(APawn* InteractingPawn, float InInteractDistance, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, TInteractionType InteractType = IT_Simple, UObject* OptionalObjectData = nullptr, EInteractionBeingAttempted InteractionBeingAttempted = FirstInteraction);

	UFUNCTION(BlueprintCallable)
	void FixupInteractionWidgetsOnUnzoom();

	UFUNCTION(BlueprintPure, Category="Interact")
	AActor* GetInteractActor() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Interact")
	UFortInteractContextInfo* K2_GetInteractResponse();

	UFUNCTION()
	virtual void OnEnterAircraft(AController* EnteringController);

	UFUNCTION()
	virtual void OnExitAircraft(AController* ExitingController);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject"))
	void RemoveInteractionPointOptions(UObject* ContextObject);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyEndLongUse(AActor* ReceivingActor, bool bUseCompleted);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyStartLongUse(AActor* ReceivingActor);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject"))
	void SetInteractionPointOptionsEnabled(UObject* ContextObject, bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="Interact")
	void SetShouldAutoOpenSwingingDoors(const bool bOpenSwingingDoorsAutomatically);

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerAttemptInteract(AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, TInteractionType InteractType, UObject* OptionalObjectData, EInteractionBeingAttempted InteractionBeingAttempted, int32 RequestId);

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ActorPendingNonInteraction;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_Interaction")
	float ClearActorPendingNonInteractionTime;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> LongInteractAudioComponents;

	UPROPERTY(Instanced)
	TObjectPtr<UFortInteractContextInfo> PossibleInteractContextInfo;

	UPROPERTY()
	TObjectPtr<UFortInteractContextInfo> InteractResponse;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> InteractActor;

	UPROPERTY()
	FServerLongInteractInfo LongInteractValidateInfo;

	UPROPERTY(Transient)
	float MobileUpdateCachedInteractActorsCooldown;

	UPROPERTY(Config)
	float MobileUpdateCachedInteractActorsCooldownLength;

	UPROPERTY(Transient)
	ETouchInteractMode TouchInteractMode;

	UPROPERTY(Config)
	float InteractTracesCapsuleReductionPct;

	UPROPERTY(Config)
	bool bInteractTraceStartsAtClosestPointDistance;

	UPROPERTY(Config)
	bool bFilterInteractTracesBehindMyFortPawn;

	UPROPERTY(Config)
	bool bFilterInteractTracesBehindMyFortPawnOtherThanBuildingActors;

	UPROPERTY(Config)
	bool bDoNotFilterBuildingActorsThatAreAttachedToPawn;

	UPROPERTY(Config)
	bool bFilterInteractTracesBehindMyFortPawnOnlyWithMultipleResults;

	UPROPERTY(Config)
	bool bInteractTracesWithStartPenetratingBlock;

	UPROPERTY(Config)
	bool bUseReticleAimingIfInitialBlockingInteractTraceBehindMyFortPawn;

	UPROPERTY(Config)
	bool bAllowRetryUse;

	UPROPERTY(Transient)
	bool bTapInteractEnabled;

	UPROPERTY(Transient)
	bool bAthena;

	UPROPERTY(Transient)
	bool bShouldBlockInteractionsForAllVehiclePassengers;

	UPROPERTY()
	TObjectPtr<UFortInteractContextInfo> AutoDoorInteractResponse;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> CurrentlyHighlightedActors;

	UPROPERTY()
	TMap<FGameplayTag, int32> InteractionTagHistory;

private:
	UFUNCTION(Client, Reliable)
	void ClientAddInteractionPointOptions(const FInteractionPointOptions& ContextObject, UObject* Caller, float Priority);

	UFUNCTION(Client, Reliable)
	void ClientDisableTracingFromPlayerOnFail();

	UFUNCTION(Client, Reliable)
	void ClientEnableTracingFromPlayerOnFail(float InInteractDistanceFromPlayer);

	UFUNCTION(Client, Reliable)
	void ClientRemoveInteractionPointOptions(UObject* ContextObject);

	UFUNCTION(Client, Reliable)
	void ClientSetInteractionPointOptionsEnabled(UObject* ContextObject, bool bEnabled);

};

