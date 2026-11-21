// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Input/Events.h"
#include "Math/MathFwd.h"
#include "SpecialEventInputHelperComponent.generated.h"

class UInputComponent;

UENUM(BlueprintType)
enum class ESpecialEventInputActionBindType : uint8
{
	/** Just consume the input, which will prevent the base behavior.  Don't broadcast SpecialEventInputPressDelegate. */
	Consume = 0,
	/** Bind to the input.  Base behavior is overridden by SpecialEventInputPressDelegate. */
	Bind = 1,
	/** Leave the base behavior as is */
	None = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecialEventAnyKeyPressed, const FName&, KeyName);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpecialEventInputPress, const FName&, ActionName, const bool, bPressed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecialEventInputUpdate, const FVector&, InputVector);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecialEventTouchInput, const FPointerEvent&, MouseEvent);

USTRUCT(BlueprintType)
struct FSpecialEventInputHelperActionBindData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventInputHelperActionBindData")
	ESpecialEventInputActionBindType PressBindType;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventInputHelperActionBindData")
	ESpecialEventInputActionBindType ReleaseBindType;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class USpecialEventInputHelperComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PopInputComponent();

	UFUNCTION(BlueprintCallable)
	void PushInputComponent();

	UFUNCTION(BlueprintCallable)
	void SetEnableAnyKey(bool bEnable);

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="Special Event Move Input Updated"))
	FSpecialEventInputUpdate SpecialEventInputUpdateDelegate;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="Special Event Look Input Updated"))
	FSpecialEventInputUpdate SpecialEventLookInputUpdateDelegate;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="Special Event Gyro Input Updated"))
	FSpecialEventInputUpdate SpecialEventGyroInputUpdateDelegate;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventInputPress SpecialEventInputPressDelegate;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventAnyKeyPressed AnyKeyPressedDelegate;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventTouchInput SpecialEventTouchStartDelegate;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventTouchInput SpecialEventTouchEndDelegate;

protected:
	UPROPERTY(EditAnywhere, Category="SpecialEventInputHelperComponent")
	bool bBlockInput;

	UPROPERTY(EditAnywhere, Category="SpecialEventInputHelperComponent")
	bool bConsumeMoveInput;

	UPROPERTY(EditAnywhere, Category="SpecialEventInputHelperComponent")
	bool bConsumeLookInput;

	UPROPERTY(EditAnywhere, Category="SpecialEventInputHelperComponent")
	int32 Priority;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventInputHelperComponent")
	TMap<FName, FSpecialEventInputHelperActionBindData> InputActionMap;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventInputHelperComponent")
	bool bAllowRepeatAnyKeyEvents;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventInputHelperComponent", meta=(EditCondition="bAllowRepeatAnyKeyEvents"))
	float MinTimeBetweenRepeatAnyKeyEvents;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventInputHelperComponent")
	TArray<FName> IgnoredAnyKeyEventKeyNames;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> InputComp;

};

