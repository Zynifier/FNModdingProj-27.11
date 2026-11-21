// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/TimerHandle.h"
#include "Input/Events.h"
#include "Layout/Geometry.h"
#include "Math/MathFwd.h"
#include "FortTouchControlRegion.generated.h"

class UCurveFloat;
class UFortAutorunLockZone;
class UFortTouchLookStick;
class UFortTouchMoveStick;
class UUserWidget;
enum class EFortTouchControlRegion : uint8;

UENUM(BlueprintType)
enum class EFortControlType : uint8
{
	None = 0,
	CameraAndMovement = 1,
	Picking = 2,
	COUNT = 3,
};

UENUM(BlueprintType, meta=(ScriptName="FortTouchControlRegionType"))
enum class EFortTouchControlRegion : uint8
{
	MovePlayer = 0,
	RotateCamera = 1,
	NoRegion = 2,
	COUNT = 3,
};

UENUM(BlueprintType)
enum class ETouchState : uint8
{
	None = 0,
	WaitingForStart = 1,
	Started = 2,
	Active = 3,
	COUNT = 4,
};

USTRUCT()
struct FOnVirtualJoysticksTouchEndedData
{
	GENERATED_BODY()

};

USTRUCT()
struct FOnVirtualJoysticksTouchMovedData
{
	GENERATED_BODY()

};

USTRUCT()
struct FOnVirtualJoysticksTouchStartedData
{
	GENERATED_BODY()

};

USTRUCT()
struct FTouchMove
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEUI_API UFortTouchControlRegion : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRegionTouchEnded(const EFortTouchControlRegion Region, const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRegionTouchMoved(const EFortTouchControlRegion Region, const FGeometry& InGeometry, const FPointerEvent& InGestureEvent, const FVector2D& MoveDelta);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRegionTouchStarted(const EFortTouchControlRegion Region, const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

protected:
	UFUNCTION(BlueprintPure, Category="Move Player Touch Region Helpers")
	float GetTouchStickRange() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void MovePlayerRegionTick(const FGeometry& InGeometry, const float DeltaTime);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnAdditionalTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnAdditionalTouchLost(int32 PointerIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnAdditionalTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION()
	void OnBuildModeChanged(bool bBuildModeEnabled);

	UFUNCTION()
	void OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnMovePlayerRegionTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnMovePlayerRegionTouchLost(int32 PointerIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnMovePlayerRegionTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnMovePlayerRegionTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnRotatePlayerRegionTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnRotatePlayerRegionTouchLost(int32 PointerIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnRotatePlayerRegionTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent, const FVector2D& MoveDelta);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void OnRotatePlayerRegionTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION()
	void ResetTouchState();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Move Player Touch Region Handlers")
	void RotatePlayerRegionTick(const FGeometry& InGeometry, const float DeltaTime);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Visuals")
	void SetFeedbackPosition(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent);

	UFUNCTION(BlueprintCallable, Category="Move Player Touch Region Handlers")
	void SetLockOnStickPosition(FVector2D LocalPos);

	UFUNCTION(BlueprintCallable, Category="Move Player Touch Region Helpers")
	void SetMoveStickPos(FVector2D NewMoveStickPos);

	UFUNCTION(BlueprintCallable, Category="Move Player Touch Region Handlers")
	void UpdateLockOnStickOrigin(FVector2D LocalPos, bool IsTouchStartEvent);

	UFUNCTION(BlueprintCallable, Category="Move Player Touch Region Handlers")
	void UpdateLockOnStickPosition(FVector2D LocalPos);

	UPROPERTY()
	FTimerHandle AutorunLockDelayHandle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortTouchMoveStick> RegisteredTouchMoveStick;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortTouchLookStick> RegisteredTouchLookStick;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAutorunLockZone> RegisteredAutoRunLockTarget;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D LastMovePlayerRegionTouchOrigin;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D MovePlayerRegionTouchEndPos;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D MoveVector;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	uint8 bLastLookTouchWasTap : 1;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	uint8 bIsLockedOn : 1;

	UPROPERTY(BlueprintReadOnly, Category="Touch")
	float MoveStickLastTouchTime;

	UPROPERTY(BlueprintReadOnly, Category="Touch")
	FVector2D MovePlayerRegionLastTouchPos;

	UPROPERTY(BlueprintReadOnly, Category="Touch")
	FVector2D RotateCameraRegionLastTouchPos;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D RotateCameraPlayerRegionLastTouchDiff;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	float RotateCameraLastTouchTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Touch")
	TObjectPtr<UCurveFloat> RotateInertiaCurve;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D RotateStickPosition;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D LockOnStickOrigin;

	UPROPERTY(BlueprintReadOnly, Category="Touch")
	FVector2D LockOnStickCurrentPos;

};

