// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortVehicleTypes.h"
#include "FortVehicleSeatComponent.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerPawn;
class IFortVehicleUserInterface;
class UAnimInstance;
class UAnimMontage;
class UFortVehicleSeatWeaponComponent;
class UInputComponent;
class USoundBase;

UENUM()
enum ESeatSelectionRule
{
	// Picks between two closest seats, depending on view angle.

	TwoClosest = 0,
	// The seat closest to player proximity.

	ClosestToPlayer = 1,
	// The seat closest to player aim.

	ClosestToAim = 2,
	// Mixed of Default and then ClosestToPlayer if Default fails.

	TwoClosestThenClosestToPlayer = 3,
};

USTRUCT()
struct FActionDefForUI
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ActionDefForUI")
	FName InputAction;

	UPROPERTY(EditAnywhere, Category="ActionDefForUI")
	FName GamepadInputAction;

	UPROPERTY(EditAnywhere, Category="ActionDefForUI")
	FText ActionLabel;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FAthenaCarPlayerSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	FName SeatSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	FName SeatChoiceSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	FName SeatIndicatorSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	FText SeatChoiceDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	FName SeatCollision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	TArray<FName> ExitSockets;

	UPROPERTY(EditAnywhere, Category="Slot")
	FAthenaVehicleShootingCone ShootingCone;

	UPROPERTY(EditAnywhere, Category="Audio")
	TObjectPtr<USoundBase> SoundOnEnter;

	UPROPERTY(EditAnywhere, Category="Audio")
	TObjectPtr<USoundBase> SoundOnExit;

	UPROPERTY(EditAnywhere, Category="Slot", meta=(EditCondition="bUsePerSeatAnimInstanceOverride"))
	TSubclassOf<UAnimInstance> AnimInstanceOverride;

	UPROPERTY(EditAnywhere, Category="Slot", meta=(EditCondition="bUsePerSeatAnimInstanceOverride"))
	TSubclassOf<UAnimInstance> AnimLayerOverride;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bUsePerSeatAnimInstanceOverride : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bIsSelectable : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bUseGroundMotion : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bUseVehicleIsOnGround : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bCanEmote : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bCanCarryDBNOPlayer : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bForceCrouch : 1;

	UPROPERTY(EditAnywhere, Category="Audio")
	uint8 bPlayEnterSoundForTransition : 1;

	UPROPERTY(EditAnywhere, Category="Audio")
	uint8 bPlayExitSoundForTransition : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bIsPushDriver : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bCanOnlyFireWhenTargeting : 1;

	UPROPERTY(EditAnywhere, Category="Slot")
	uint8 bIsOccupantEnclosed : 1;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector ActorSpaceCameraOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector VehicleSpaceCameraOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	float SlopeCompensationCameraOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector StandingFiringOffset;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector CrouchingFiringOffset;

	UPROPERTY(EditAnywhere, Category="Slot")
	FVector EmoteOffset;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> Player;

	UPROPERTY(Transient, NotReplicated)
	TScriptInterface<IFortVehicleUserInterface> ControllerUser;

	UPROPERTY(Transient)
	float PlayerEntryTime;

	UPROPERTY(Transient, NotReplicated)
	float EnterSeatTime;

	UPROPERTY(EditAnywhere, Category="Slot")
	bool bConstrainPawnToSeatTransform;

	UPROPERTY(EditAnywhere, Category="Slot")
	bool bConstrainPawnToSeatDuringTransitionMontage;

	UPROPERTY(EditAnywhere, Category="Slot")
	bool bOffsetPlayerRelativeAttachLocation;

	UPROPERTY(EditAnywhere, Category="Slot")
	bool bUseExitTimer;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleSeatWeaponComponent> WeaponComponent;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraPitchConstraint;

	UPROPERTY(EditAnywhere, Category="Camera")
	float CameraYawConstraint;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ReservingActor;

	UPROPERTY(EditAnywhere, Category="Slot")
	bool bReserved;

	UPROPERTY(EditAnywhere, Category="Input")
	TArray<FActionDefForUI> ActionDefForUI;

	UPROPERTY(EditAnywhere, Category="Slot")
	ESlotEnvironmentExposure EnvironmentExposure;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slot")
	FGameplayTagContainer SeatTags;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle", meta=(Categories="Gameplay.Action.Player.OperatingTurret"))
	FGameplayTag OperatingTurretActionTag;

	UPROPERTY()
	float VehicleApexZ;

	UPROPERTY()
	int32 SeatIndex;

	UPROPERTY()
	int32 ExitSocketIndex;

	UPROPERTY()
	bool bOverrideVehicleExit;

	UPROPERTY()
	FVector SeatTransitionVector;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSeatTransitionMontage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SeatTransitionMontage")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditAnywhere, Category="SeatTransitionMontage", meta=(EditCondition="bUseFromSeatIndex"))
	int32 FromSeatIndex;

	UPROPERTY(EditAnywhere, Category="SeatTransitionMontage", meta=(EditCondition="bUseToSeatIndex"))
	int32 ToSeatIndex;

	UPROPERTY(EditAnywhere, Category="SeatTransitionMontage")
	bool bUseFromSeatIndex;

	UPROPERTY(EditAnywhere, Category="SeatTransitionMontage")
	bool bUseToSeatIndex;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger"))
class UFortVehicleSeatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Player Slot"))
	FAthenaCarPlayerSlot BP_GetPlayerSlot(const int32 SeatIndex) const;

	UFUNCTION(BlueprintPure)
	const TArray<FAthenaCarPlayerSlot>& GetPlayerSlots() const;

	UFUNCTION()
	void OnRep_PlayerSlots();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortVehicleSeatComponent")
	float SeatSwitchCooldown;

	UPROPERTY(Transient)
	bool bHasAnyMountedWeaponSeats;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TSubclassOf<UInputComponent> InputClassOverride;

	UPROPERTY(Transient)
	bool bEnableInputClassOverride;

	UPROPERTY(EditDefaultsOnly, Config, Category="Vehicle")
	FScalableFloat EnableInputClassOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, ReplicatedUsing=OnRep_PlayerSlots, Category="Vehicle")
	TArray<FAthenaCarPlayerSlot> PlayerSlots;

	UPROPERTY()
	TArray<FAthenaCarPlayerSlot> PreviousPlayerSlots;

	UPROPERTY(Transient)
	TArray<FAthenaCarPlayerSlotUnreplicated> PlayerSlotsUnreplicated;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TArray<int32> PlayerSlotPriorityList;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	bool bAlwaysAllowEntry;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle")
	TEnumAsByte<ESeatSelectionRule> SeatSelectionRule;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPawn> PreviousDriver;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> PlayerForCosmetics;

};

