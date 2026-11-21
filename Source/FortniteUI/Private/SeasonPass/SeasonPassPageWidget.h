// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SeasonPassPageWidget.generated.h"

UCLASS(meta=(DisableNativeTick))
class USeasonPassPageWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="SeasonPassPageWidget")
	bool ContainsLevel(int32 Level);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="SeasonPassPageWidget")
	void NavigatePageLeft();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="SeasonPassPageWidget")
	void NavigatePageRight();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="SeasonPassPageWidget")
	void ScreenShown();

protected:
	UFUNCTION(BlueprintPure, Category="SeasonPassPageWidget")
	int32 GetCurrentSeasonNumber() const;

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelPanel")
	void OnBattlePassChanged();

	UFUNCTION(BlueprintPure, Category="SeasonPassPageWidget")
	bool OwnsSeasonPass() const;

	UFUNCTION(BlueprintCallable, Category="SeasonPassPageWidget")
	bool ShouldPlayInto(int32 FirstLevel);

};

