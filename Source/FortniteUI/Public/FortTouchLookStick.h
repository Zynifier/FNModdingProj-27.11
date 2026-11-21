// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "FortTouchLookStick.generated.h"

class UBacchusActionButton;
class UImage;
class USizeBox;

UCLASS()
class UFortTouchLookStick : public UBacchusHUDElement
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="UI")
	bool GetShowAllTimeTime() const;

	UFUNCTION(BlueprintPure, Category="UI")
	float GetSize() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="UI")
	bool IsFireButtonUnderTouch(FVector2D TouchPosition) const;

	UFUNCTION()
	void OnFireFromIndexStopped(const int32 StopFireIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Touch")
	void SetFiringState(bool IsFiring);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetSize(float NewSize);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetTouchStickPositionAbsolute(FVector2D TouchPosition);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetTouchStickPositionLocal(FVector2D TouchPosition);

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> MainSizeBox;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Touch")
	TSoftObjectPtr<UImage> FireImageRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Touch")
	FVector2D FireImageAbsoluteOffset;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTouchLookStick", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBacchusActionButton> Button_DBNOCarryThrow;

};

