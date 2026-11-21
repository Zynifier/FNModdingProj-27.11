// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "PostGamePlacementOverlay.generated.h"

class AFortGameplayMutator;
class UFortPostGameScreen;

UENUM(BlueprintType)
enum class EPostGamePlacement : uint8
{
	/** show the player that they won */
	Win = 0,
	/** show the player that they lost */
	Lose = 1,
	/** show the player that they tied */
	Tie = 2,
	/** do not show the player how they placed */
	NoPlacement = 3,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UPostGamePlacementOverlay : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void FadeOutOverlay();

	UFUNCTION()
	FORTNITEUI_API bool ShouldShow() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Post Game Flow", meta=(DisplayName="Screen Index Changed"))
	FORTNITEUI_API void BP_ScreenIndexChanged(const int32 NewIndex, UFortPostGameScreen* NewScreen);

	UFUNCTION(BlueprintNativeEvent, Category="Post Game Flow", meta=(DisplayName="Should Show"))
	FORTNITEUI_API bool BP_ShouldShow() const;

	UFUNCTION()
	FORTNITEUI_API void LocalPlacementChanged();

	UFUNCTION()
	FORTNITEUI_API virtual bool NativeShouldShow() const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void ShowLosingPlacement();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void ShowTiePlacement();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void ShowWinningPlacement();

	UPROPERTY(EditDefaultsOnly, Category="PostGamePlacementOverlay")
	TSubclassOf<AFortGameplayMutator> MutatorClassToWaitFor;

};

