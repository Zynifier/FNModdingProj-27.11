// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FabricInteractableInterface.generated.h"

class APlayerController;
class IFabricHoldable;
class UAudioComponent;
class UObject;
class USceneComponent;
enum class EFabricContinuousInteractionDirection : uint8;
enum class EFabricInteractableType : uint8;

UENUM(BlueprintType)
enum class EFabricContinuousInteractionDirection : uint8
{
	Vertical = 0,
	// a knob

	Horizontal = 1,
};

UENUM(BlueprintType)
enum class EFabricInteractableType : uint8
{
	Momentary = 0,
	// a button

	Continuous = 1,
	// a knob

	Cable = 2,
	// a cable

	None = 3,
};

UINTERFACE(BlueprintType)
class FABRICRUNTIME_API UFabricInteractable : public UInterface
{
	GENERATED_BODY()
};

class FABRICRUNTIME_API IFabricInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanInteractWithHoldable(const TScriptInterface<IFabricHoldable>& Holdable);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool DoesInteractionRequireHoldable() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EndInteraction(APlayerController* PlayerController, bool bWasDragAndDropInteraction);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	EFabricContinuousInteractionDirection GetContinuousInteractableDirection();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetContinuousInteractableValueNormalized();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetInteractableComponentLocation(USceneComponent* Interactable);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetInteractableForwardVector(USceneComponent* Interactable);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	EFabricInteractableType GetInteractableType();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UAudioComponent* GetInteractionSFX();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UObject* GetLinkedInteractable();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsFocusDependentOnInteractionContext(APlayerController* Controller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsValidToInteractWith(APlayerController* Controller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnInteractionFocusTargetChanged(APlayerController* Controller, UObject* FocusTarget, bool bIsFocused);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetFocused(bool bIsFocused);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetHitComponent(USceneComponent* HitComponent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetInteractable(bool bInteractable);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartInteraction(APlayerController* Controller);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartSpecialInteraction(APlayerController* Controller);

};

