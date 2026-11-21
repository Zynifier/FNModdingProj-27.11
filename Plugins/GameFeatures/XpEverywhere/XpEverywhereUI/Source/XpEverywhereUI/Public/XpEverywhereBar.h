// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "XpEverywhereBar.generated.h"

class UFortSocialAvatarIcon;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UXpEverywhereBar : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void DoneUpdatingXpBar();

	UFUNCTION(BlueprintPure)
	int32 GetTotalXpRequiredForLevel(const int32 InLevel) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnXpBarInitialized(int32 CurrentXP, int32 CurrentLevel, int32 CurrentRemainingRestXP);

	UFUNCTION(BlueprintImplementableEvent)
	void OnXpBarUpdated(int32 ShownXP, int32 ShownLevel, int32 NewDesiredXP, int32 NewDesiredLevel, int32 NewRemainingRestXP);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="XpEverywhereBar")
	bool bXpBarAlwaysActive;

	UPROPERTY(BlueprintReadOnly, Export, Category="XpEverywhereBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> SocialAvatarIcon;

};

