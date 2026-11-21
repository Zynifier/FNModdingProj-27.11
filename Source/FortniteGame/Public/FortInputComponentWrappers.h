// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineBaseTypes.h"
#include "FortInputComponentWrappers.generated.h"

class AFortPlayerController;
class APlayerController;
class UInputComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreativeInput);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlaysetGrenadeTarget);

USTRUCT(BlueprintType)
struct FInputEventBinding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="InputEventBinding")
	FName ActionName;

	UPROPERTY(EditDefaultsOnly, Category="InputEventBinding")
	TEnumAsByte<EInputEvent> InputEvent;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortPossessedPropInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Prop Hunt")
	virtual void PopPossessedPropInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Prop Hunt")
	virtual void PushPossessedPropInputMode(APlayerController* PlayerController);

	UPROPERTY(BlueprintAssignable, Category="Prop Hunt")
	FOnCreativeInput OnPossessedPropCancel;

	UPROPERTY(BlueprintAssignable, Category="Prop Hunt")
	FOnCreativeInput OnPossessedPropPlace;

	UPROPERTY(BlueprintAssignable, Category="Prop Hunt")
	FOnCreativeInput OnPossessedPropMakeNoise;

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> FortPossessedPropInputComponent;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortDataDrivenPossessedPropInputComponent : public UFortPossessedPropInputComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortDataDrivenPossessedPropInputComponent")
	TArray<FInputEventBinding> PossessedPropPlaceBindings;

	UPROPERTY(EditDefaultsOnly, Category="FortDataDrivenPossessedPropInputComponent")
	TArray<FInputEventBinding> PossessedPropMakeNoiseBindings;

	UPROPERTY(EditDefaultsOnly, Category="FortDataDrivenPossessedPropInputComponent")
	TArray<FInputEventBinding> PossessedPropCancelBindings;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortObjectMoverInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Move Tool|Scale")
	bool IsEmptyInputComponentActive();

	UFUNCTION(BlueprintCallable, Category="Move Tool")
	void PopAllInputModes(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Equipped")
	void PopCreativeMoveToolEquippedInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Scale")
	void PopEmptyInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Move Buildings On Grid")
	void PopMoveBuildingsOnGridInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Move Objects Freely")
	void PopMoveObjectsFreelyInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Multi Select")
	void PopMultiSelectMoveBuildingsOnGridModeInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Multi Select")
	void PopMultiSelectMoveObjectsFreelyModeInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Playset Preview")
	void PopPlaysetPreviewInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Equipped")
	void PopPropPossessorEquippedInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Rotation")
	void PopRotationInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Scale")
	void PopScaleInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Translation")
	void PopTranslationInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Equipped")
	void PushCreativeMoveToolEquippedInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Scale")
	void PushEmptyInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Move Buildings On Grid")
	void PushMoveBuildingsOnGridInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Move Objects Freely")
	void PushMoveObjectsFreelyInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Multi Select")
	void PushMultiSelectMoveBuildingsOnGridModeInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Multi Select")
	void PushMultiSelectMoveObjectsFreelyModeInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Playset Preview")
	void PushPlaysetPreviewInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Equipped")
	void PushPropPossessorEquippedInputComponent(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Rotation")
	void PushRotationInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Scale")
	void PushScaleInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Move Tool|Translation")
	void PushTranslationInputMode(APlayerController* PlayerController);

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnDuplicateBuildingActorPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnDuplicateBuildingActorReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolLetGo;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolCopyGrabOrDuplicatePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolCopyGrabOrDuplicateReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateClockwisePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateClockwiseReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateCounterclockwisePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateCounterclockwiseReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateSingleClockwisePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateSingleClockwiseReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateSingleCounterclockwisePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolRotateSingleCounterclockwiseReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolSwitchRotationAxisPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolSwitchRotationAxisReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnTouchMoveToolResetRotationPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolMirror;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolPushPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolPushReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolPullPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolPullReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolDropToFloor;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolExitPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolExitReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolDeletePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolDeleteReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolChangePrecisionLevelPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolChangePrecisionLevelReleased;

	UPROPERTY(BlueprintAssignable, Category="Playset Preview")
	FOnCreativeInput OnPlaysetPreviewPlace;

	UPROPERTY(BlueprintAssignable, Category="Playset Preview")
	FOnCreativeInput OnPlaysetPreviewPushPressed;

	UPROPERTY(BlueprintAssignable, Category="Playset Preview")
	FOnCreativeInput OnPlaysetPreviewPushReleased;

	UPROPERTY(BlueprintAssignable, Category="Playset Preview")
	FOnCreativeInput OnPlaysetPreviewPullPressed;

	UPROPERTY(BlueprintAssignable, Category="Playset Preview")
	FOnCreativeInput OnPlaysetPreviewPullReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolScaleUpPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolScaleUpReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolScaleDownPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolScaleDownReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolSwitchScaleAxisPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnTouchMoveToolResetScalePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolSwitchScaleAxisReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnCycleTransformationModeUpPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnCycleTransformationModeDownPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnSelectTranslationModePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnSelectRotationModePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnSelectScaleModePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMultiSelectPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMultiSelectReleased;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnClearMultiSelectPressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolHitTraceRulePressed;

	UPROPERTY(BlueprintAssignable, Category="Move Tool")
	FOnCreativeInput OnMoveToolHitTraceRuleReleased;

	UPROPERTY(BlueprintReadWrite, Category="FortObjectMoverInputComponent")
	TObjectPtr<AFortPlayerController> OwningPC;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> CreativeMoveToolEquippedInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PropPossessorEquippedInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> MoveObjectsFreelyModeInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> MultiSelectMoveObjectsFreelyModeInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> MoveBuildingsOnGridModeInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> MultiSelectMoveBuildingsOnGridModeInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> TranslationInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> RotationInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> ScaleInputComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> EmptyInputComponent;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PlaysetPreviewModeInputComponent;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortPlaysetGrenadeInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Playset Greande")
	void PopPlaysetGrenadeInputMode(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Playset Grenade")
	void PushPlaysetGrenadeInputMode(APlayerController* PlayerController);

	UPROPERTY(BlueprintAssignable, Category="Playset Greande")
	FOnPlaysetGrenadeTarget OnPlaysetGrenadeTarget;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PlaysetGrenadeInputComponent;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortRiftBubblePossessedPropInputComponent : public UFortPossessedPropInputComponent
{
	GENERATED_BODY()

};

