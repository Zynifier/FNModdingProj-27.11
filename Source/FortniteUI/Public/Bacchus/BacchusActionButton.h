// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Mobile/BacchusButton.h"
#include "UI/Bacchus/BacchusHudTypes.h"
#include "BacchusActionButton.generated.h"

class UUserWidget;

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UBacchusActionButton : public UBacchusButton
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void AddActionMappings(TArray<FBacchusActionIconMapping> NewActionMappings);

	UFUNCTION()
	FORTNITEUI_API void OnCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget);

	UPROPERTY(EditAnywhere, Category="BacchusActionButton")
	TArray<FBacchusActionIconMapping> ActionMapping;

	UPROPERTY(EditAnywhere, Category="BacchusActionButton")
	FName TempActionMapping;

	UPROPERTY(EditAnywhere, Category="BacchusActionButton")
	TArray<FGameplayTag> ItemsAllowingClickThrough;

	UPROPERTY(EditAnywhere, Category="BacchusActionButton")
	bool bCapturesInput;

};

