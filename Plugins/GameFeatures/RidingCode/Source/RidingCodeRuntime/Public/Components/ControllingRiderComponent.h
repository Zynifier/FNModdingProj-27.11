// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RiderComponent.h"
#include "ControllingRiderComponent.generated.h"

class UFortInputComponent;
class UFortInputMappingContext;
class UInputAction;

UENUM(BlueprintType)
enum class ERidingControlInputStyle : uint8
{
	SteeringControl = 0,
	DirectControl = 1,
};

USTRUCT(BlueprintType)
struct FRidingControlInputState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Input")
	float RightAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float ForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsJumping : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsUsingAbility : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsPetting : 1;

};

USTRUCT()
struct FRidingControlInputStateReliable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bIsJumping : 1;

	UPROPERTY()
	uint8 bIsUsingAbility : 1;

	UPROPERTY()
	uint8 bIsPetting : 1;

};

USTRUCT()
struct FRidingControlInputStateUnreliable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 RightAlphaQuantized;

	UPROPERTY()
	uint8 ForwardAlphaQuantized;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class RIDINGCODERUNTIME_API UControllingRiderComponent : public URiderComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FRidingControlInputState& GetControlInputState() const;

protected:
	UFUNCTION()
	void ControllingActor_OnJumpInput(bool bPressed);

	UFUNCTION()
	void ControllingActor_OnMoveForward(float Val);

	UFUNCTION()
	void ControllingActor_OnMoveRight(float Val);

	UFUNCTION()
	void HandleGamepadRidingAbilityPressed();

	UFUNCTION()
	void HandlePettingAbilityPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleRequestPettingStart();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleRequestPettingStop();

	UFUNCTION()
	void HandleRidingAbilityPressed();

	UFUNCTION()
	void HandleRidingAbilityReleased();

	UFUNCTION()
	void HandleSpotActorOrPettingAbilityPressed();

	UFUNCTION()
	void HandleSpotActorOrPettingAbilityReleased();

	UFUNCTION(BlueprintPure)
	bool IsTryingToMove(float Tolerance = 0.000000f) const;

	UFUNCTION()
	void OnRep_ControlInputReliable();

	UFUNCTION()
	void OnRep_ControlInputUnreliable();

	UFUNCTION()
	void OnRep_IsControllingRidable();

	UFUNCTION(Server, Reliable)
	void OnSprintCanceled();

	UFUNCTION()
	void ReloadPressed();

	UFUNCTION(Server, Reliable)
	void ServerCancelPetting();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateControlInputStateReliable(FRidingControlInputStateReliable InputState);

	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerUpdateControlInputStateUnreliable(FRidingControlInputStateUnreliable InputState);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateFromInput(float DeltaTime, const FRidingControlInputState& InputState);

	UPROPERTY(EditDefaultsOnly, Category="Riding|Input")
	TObjectPtr<UFortInputMappingContext> ControllingRidingInputContext;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Input")
	TObjectPtr<UInputAction> RidingAbility;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Input")
	TObjectPtr<UInputAction> GamepadRidingAbility;

	UPROPERTY(BlueprintReadWrite, Category="ControllingRiderComponent")
	bool bCanControlRidable;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsControllingRidable, Category="ControllingRiderComponent")
	bool bIsControllingRidable;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	ERidingControlInputStyle ControlInputStyle;

	UPROPERTY(Transient)
	FRidingControlInputState ReplicatedControlInputState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ControlInputReliable)
	FRidingControlInputStateReliable ReplicatedControlInputStateReliable;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ControlInputUnreliable)
	FRidingControlInputStateUnreliable ReplicatedControlInputStateUnreliable;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortInputComponent> ControllingRiderInputComponent;

	UPROPERTY(Transient)
	float AutoRunDoubleTapTimestamp;

	UPROPERTY(Transient)
	bool bCanBePet;

};

