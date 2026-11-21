// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "FortTouchMoveStick.generated.h"

class UFortAutorunLockZone;
class UImage;
class USizeBox;

UCLASS()
class UFortTouchMoveStick : public UBacchusHUDElement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool AllowMobileImprovedAutorun();

	UFUNCTION(BlueprintPure, Category="UI")
	float GetHalfHeight() const;

	UFUNCTION(BlueprintPure, Category="UI")
	FVector2D GetStickPosition() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Touch")
	void HandleTouchEnded();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Touch")
	void HandleTouchStarted();

	UFUNCTION(BlueprintPure, Category="UI")
	bool IsLocked() const;

	UFUNCTION(BlueprintPure, Category="UI")
	bool IsTouched() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayAutorunLockZone(bool bShouldShowArrow);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Touch")
	void SetMovementLockStatus(bool MovementIsLocked);

	UFUNCTION(BlueprintCallable, Category="Touch")
	void SetStickPosition(FVector2D NewPosition);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Touch")
	void SetStickPositionBP(FVector2D NewPosition);

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortTouchMoveStick", meta=(ScriptName="IsTouchedValue"))
	bool bIsTouched;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	uint8 bMoveStickIsLocked : 1;

	UPROPERTY(BlueprintReadOnly, Category="Widget Props")
	bool bAlwaysShowWhenTouched;

	UPROPERTY(BlueprintReadOnly, Category="Touch")
	float TouchStartTime;

	UPROPERTY(BlueprintReadOnly, Category="Touch")
	float LastTouchTime;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D TouchStartPos;

	UPROPERTY(BlueprintReadWrite, Category="Touch")
	FVector2D MoveStickPos;

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag AlwaysShowPropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag AutorunLockZoneSizePropertyTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_AutorunLockZoneHidden;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_AutorunDirectionArrowSpaceSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_AutorunLockZoneSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAutorunLockZone> AutorunLockZone;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_AutorunDirectionArrow;

	UPROPERTY(EditDefaultsOnly, Category="AutorunLockZone")
	float DefaultAutorunLockZoneSize;

	UPROPERTY(EditDefaultsOnly, Category="AutorunLockZone")
	float DefaultAutorunLockZoneTopPadding;

};

