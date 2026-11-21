// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Components/PawnComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "SpecialEventTypes.h"
#include "SpecialEventCursorPawnComponent.generated.h"

class AFortPlayerController;
class AHUD;
class APawn;
class APlayerController;
class UCameraComponent;
class UCanvas;
class UCommonInputSubsystem;
class UObject;
class USpecialEventCursorPawnComponent;
class USpecialEventInputHelperComponent;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSpecialEventCursorPawnComponent_OnCursorModeChanged, USpecialEventCursorPawnComponent*, CursorPawnComponent, const FGameplayTag&, NewCursorModeTag, const FGameplayTag&, OldCursorModeTag);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSpecialEventCursorPawnComponent_OnDesiredVisibilityChanged, USpecialEventCursorPawnComponent*, CursorPawnComponent, const FGameplayTag&, CursorModeTag, const bool, bShouldBeVisible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSpecialEventCursorPawnComponent_OnViewportLocationChanged, USpecialEventCursorPawnComponent*, CursorPawnComponent, const FVector2D&, NormalizedLocation, const FVector2D&, ViewportLocation);

USTRUCT(BlueprintType)
struct FSpecialEventCursorMode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	bool bAllowDebugCursorDrawing;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FSpecialEventMathEaseData GamepadMoveEaseData;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat GamepadMoveSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FSpecialEventMathEaseData TouchMoveEaseData;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat TouchMoveSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	float TouchDeadzoneTreshold;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	float TouchAttenuator;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat MinCursorPercentForAdditiveRotationPitch;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat MinCursorPercentForAdditiveRotationYaw;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat MaxAdditiveRotationPitch;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat MaxAdditiveRotationYaw;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat AdditiveRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat ZoomInInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat ZoomOutInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat ZoomAdditiveFOV;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat GamepadZoomMoveSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	FScalableFloat TouchZoomMoveSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorMode")
	bool bAllowTrace;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventCursorMode")
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventCursorMode")
	FScalableFloat SweepRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventCursorMode")
	FScalableFloat TraceDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventCursorMode")
	FScalableFloat bTraceComplex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventCursorMode")
	FScalableFloat RecenterAfterNoInputDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialEventCursorMode")
	FScalableFloat RecenterInterpSpeed;

};

USTRUCT()
struct FSpecialEventCursorStackEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag CursorModeTag;

	UPROPERTY()
	TWeakObjectPtr<UObject> InstigatingObject;

};

UINTERFACE(BlueprintType, Blueprintable)
class USpecialEventCursorInstigatorInterface : public UInterface
{
	GENERATED_BODY()
};

class ISpecialEventCursorInstigatorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Visuals")
	bool SpecialEventCursorTrace(FHitResult& OutHitResult, USpecialEventCursorPawnComponent* CursorPawnComponent, const FGameplayTag& CursorModeTag, const UCameraComponent* CameraComponent, const FVector& CursorWorldDirection);

};

UCLASS(MinimalAPI, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentTick", "Cooking", "Replication", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class USpecialEventCursorPawnComponent : public UPawnComponent, public ISpecialEventCursorInstigatorInterface
{
	GENERATED_BODY()

public:
	USpecialEventCursorPawnComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	bool CanBeVisible() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool ConvertNormalizedToViewportLocation(FVector2D& OutViewportLocation, const FVector2D& NormalizedLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool ConvertNormalizedToWorldLocationAndDirection(FVector& OutWorldLocation, FVector& OutWorldDirection, const FVector2D& NormalizedLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool ConvertViewportToNormalizedLocation(FVector2D& OutNormalizedLocation, const FVector2D& ViewportLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool ConvertViewportToWorldLocationAndDirection(FVector& OutWorldLocation, FVector& OutWorldDirection, const FVector2D& ViewportLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool ConvertWorldToNormalizedLocation(FVector2D& OutNormalizedLocation, const FVector& WorldLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool ConvertWorldToViewportLocation(FVector2D& OutViewportLocation, const FVector& WorldLocation) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	UCameraComponent* GetCameraComponent() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	FVector2D GetCenteredWidgetLocation(UUserWidget* Widget, const FVector2D& ViewportLocation) const;

	UFUNCTION(BlueprintPure)
	const FGameplayTag& GetCurrentCursorModeTag() const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetCurrentHitResult(FHitResult& OutHitResult);

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	UUserWidget* GetCurrentWidget() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	FGameplayTagContainer GetCursorModeTagsForWidget(const UUserWidget* Widget) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	ECommonInputType GetInputType() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	APlayerController* GetLocalController() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	FVector2D GetNormalizedLocation() const;

	UFUNCTION(BlueprintCallable)
	static USpecialEventCursorPawnComponent* GetSpecialEventCursorPawnComponent(const APawn* Pawn, const FGameplayTag& CursorModeTag, const bool bMustBeActive);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetViewportCenter(FVector2D& OutViewportCenter) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetViewportLocation(FVector2D& OutViewportLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetViewportSize(FVector2D& OutViewportSize) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintCosmetic, meta=(ExpandBoolAsExecs="ReturnValue"))
	bool GetWorldLocationAndDirection(FVector& OutWorldLocation, FVector& OutWorldDirection) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	bool IsAdditiveRotationAllowed() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	bool IsLocallyControlled() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic)
	bool IsZoomAllowed() const;

	UFUNCTION(BlueprintCallable)
	void PopAllCursorsForObject(UObject* InstigatingObject, const bool bDeactivateIfStackEmpty);

	UFUNCTION(BlueprintCallable)
	void PopCursor(const FGameplayTag& CursorModeTag, UObject* InstigatingObject, const bool bDeactivateIfStackEmpty);

	UFUNCTION(BlueprintCallable)
	void PushCursor(const FGameplayTag& CursorModeTag, UObject* InstigatingObject, const bool bActivate);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SetAdditiveRotationAllowed(const bool bInAdditiveRotationAllowed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetAllowOnNonOwningClients(const bool bAllow);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void SetZoomAllowed(const bool bInZoomAllowed);

	UPROPERTY(BlueprintAssignable)
	FSpecialEventCursorPawnComponent_OnDesiredVisibilityChanged OnDesiredVisibilityChanged;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventCursorPawnComponent_OnCursorModeChanged OnCursorModeChanged;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventCursorPawnComponent_OnViewportLocationChanged OnViewportLocationChanged;

protected:
	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_bAllowOnNonOwningClients, Category="SpecialEventCursorPawnComponent")
	bool bAllowOnNonOwningClients;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	FGameplayTag DefaultCursorModeTag;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	bool bDefaultCursorModeAutoActivate;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	TMap<FGameplayTag, FSpecialEventCursorMode> CursorModes;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	TSubclassOf<USpecialEventInputHelperComponent> InputHelperClass;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	bool bUseGamepadLookInput;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	bool bUseGamepadMoveInput;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	bool bUseGyroInput;

	UPROPERTY(EditDefaultsOnly, Config, Category="SpecialEventCursorPawnComponent")
	bool bObeyInvertedPitchUserSetting;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	FScalableFloat NonOwningInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventCursorPawnComponent")
	FScalableFloat MinDeltaToSendWorldLocationToServer;

	UPROPERTY(EditDefaultsOnly, Category="AdditiveRotation")
	bool bAdditiveRotationAllowedByDefault;

	UPROPERTY(EditDefaultsOnly, Category="Zoom")
	bool bZoomAllowedByDefault;

	UPROPERTY(EditDefaultsOnly, Category="Zoom")
	FName ZoomActionName;

private:
	UFUNCTION()
	void GyroInputUpdate(const FVector& InInputVector);

	UFUNCTION()
	void InputPressed(const FName& ActionName, const bool bPressed);

	UFUNCTION()
	void LookInputUpdate(const FVector& InInputVector);

	UFUNCTION()
	void MoveInputUpdate(const FVector& InInputVector);

	UFUNCTION()
	void OnHUDPostRender(AHUD* HUD, UCanvas* Canvas);

	UFUNCTION()
	void OnInputMethodChanged(ECommonInputType InputType);

	UFUNCTION()
	void OnLocallyControlledCursorVisibilityChanged(USpecialEventCursorPawnComponent* CursorPawnComponent, const FGameplayTag& CursorModeTag, const bool bShouldBeVisible);

	UFUNCTION()
	void OnRep_bAllowOnNonOwningClients();

	UFUNCTION()
	void OnRep_ReplicatedCursorStackEntry(const FSpecialEventCursorStackEntry& OldCursorStackEntry);

	UFUNCTION()
	void OnRep_ReplicatedWorldLocation();

	UFUNCTION(Server, Unreliable)
	void ServerOnWorldLocationChanged(const FVector& WorldLocation);

	UPROPERTY(Transient)
	TObjectPtr<APawn> OwningPawn;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwningController;

	UPROPERTY()
	TArray<FSpecialEventCursorStackEntry> CursorStack;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedCursorStackEntry)
	FSpecialEventCursorStackEntry ReplicatedCursorStackEntry;

	UPROPERTY()
	TObjectPtr<UCommonInputSubsystem> CommonInputSubsystem;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USpecialEventInputHelperComponent> InputHelperComponent;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedWorldLocation)
	FVector ReplicatedWorldLocation;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UUserWidget>> Widgets;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> AdditiveOffsetCameraComponent;

};

