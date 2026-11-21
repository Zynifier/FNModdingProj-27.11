// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/BacchusActionButton.h"
#include "FocusButton.generated.h"

class UPaperSprite;

UCLASS(BlueprintType, Blueprintable)
class UFocusButton : public UBacchusActionButton
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCanUseEventModeFocusChanged(bool bCanUseEventModeFocus);

	UFUNCTION()
	void HandleEventModeFocusingChanged(bool bIsEventModeFocusing);

	UPROPERTY(EditDefaultsOnly, Category="FocusButton")
	TObjectPtr<UPaperSprite> StartFocusingSprite;

	UPROPERTY(EditDefaultsOnly, Category="FocusButton")
	TObjectPtr<UPaperSprite> StopFocusingSprite;

};

