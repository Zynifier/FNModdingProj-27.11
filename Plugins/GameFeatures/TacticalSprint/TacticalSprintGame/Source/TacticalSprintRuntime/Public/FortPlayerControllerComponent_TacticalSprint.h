// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Analytics/FortMatchStatProviderInterface.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "Player/Components/FortSprintOverrideComponentInterface.h"
#include "FortPlayerControllerComponent_TacticalSprint.generated.h"

class ACharacter;
class AFortPawn;
class AFortPlayerPawn;
class AFortWeapon;
class APawn;
class APlayerState;
class UFortMovementMode_BaseExtLogic;
class UFortMovementMode_ELTacSprint;
class UInputComponent;
class UObject;
enum class ESprintLoggingVerbosityLevel : uint8;

UENUM(BlueprintType)
enum class ESprintLoggingVerbosityLevel : uint8
{
	Error = 0,
	Warning = 1,
	Display = 2,
	Log = 3,
	Verbose = 4,
	VeryVerbose = 5,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTacticalSprintEnded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTacticalSprintFailed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTacticalSprintStarted);

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPlayerControllerComponent_TacticalSprint : public UControllerComponent, public IFortSprintOverrideComponentInterface, public IFortMatchStatProviderInterface, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFortPlayerControllerComponent_TacticalSprint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Sprint", meta=(DefaultToSelf="LoggingSource"))
	void LogAndVisualLog(UObject* LoggingSource, ESprintLoggingVerbosityLevel Verbosity, const FString& LogString);

	UFUNCTION(BlueprintCallable, Category="Sprint")
	void PopCustomMovementModeExtensionClass();

	UFUNCTION(BlueprintCallable, Category="Sprint")
	void PushCustomMovementModeExtensionClass(TSubclassOf<UFortMovementMode_ELTacSprint> NewCustomMMExtensionClass);

	UFUNCTION(BlueprintCallable, Category="Sprint")
	void SetIsSprinting(bool bNewIsSprinting);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerControllerComponent_TacticalSprint")
	TSubclassOf<UFortMovementMode_BaseExtLogic> MovementModeExtension;

	UPROPERTY(BlueprintAssignable, Category="Sprint", meta=(AllowPrivateAccess="TRUE"))
	FOnTacticalSprintFailed OnFailedToSprint;

private:
	UFUNCTION()
	void OnAutoRunChanged(bool bAutoRunIsOn);

	UFUNCTION()
	void OnMovementModeChanged(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void OnMutatorUpdated();

	UFUNCTION()
	void OnPawnChanged(AFortPawn* InPawn);

	UFUNCTION()
	void OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UFUNCTION()
	void RegisterMutatorUpdatedDelegate();

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> CurrentBoundPlayerPawn;

	UPROPERTY(Transient)
	uint8 bTacticalSprintEnabled : 1;

	UPROPERTY(Transient)
	uint8 bWantsToTacticalSprint : 1;

	UPROPERTY(Transient)
	uint8 bHandlingMoveForward : 1;

	UPROPERTY(Transient)
	uint8 bIsSprinting : 1;

	UPROPERTY(Transient)
	uint8 bWasInBuildMode : 1;

	UPROPERTY(EditDefaultsOnly, Category="Analytics")
	uint8 bFireAnalyticsEventOnEndPlay : 1;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint")
	FGameplayTag TacticalSprintAbilityGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint")
	FGameplayTag DisableTacticalSprintAbilityGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint")
	FScalableFloat TacticalSprintEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint")
	FScalableFloat TacticalSprintToggleGracePeriod;

	UPROPERTY(BlueprintAssignable, Category="Sprint", meta=(AllowPrivateAccess="TRUE"))
	FOnTacticalSprintStarted OnTacticalSprintStarted;

	UPROPERTY(BlueprintAssignable, Category="Sprint", meta=(AllowPrivateAccess="TRUE"))
	FOnTacticalSprintEnded OnTacticalSprintEnded;

	UPROPERTY(EditDefaultsOnly, Category="Tactical Sprint")
	bool bUseMovementModeExtension;

	UPROPERTY(Transient)
	FTimerHandle StopWantingToSprintTimerReceipt;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> InputComponent;

};

