// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSeasonDataWidget.generated.h"

class UAthenaChallengeRewards;
class UFortSocialAvatarIcon;

UCLASS(meta=(DisableNativeTick))
class UFortSeasonDataWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSeasonDataWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassOwned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLevelChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSuperCharged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatedRestedState(const bool bIsRested);

	UPROPERTY(BlueprintReadOnly, Category="FortSeasonDataWidget")
	float CurrentProgress;

	UPROPERTY(BlueprintReadOnly, Category="FortSeasonDataWidget")
	int32 CurrentXP;

	UPROPERTY(BlueprintReadOnly, Category="FortSeasonDataWidget")
	int32 XpToNextLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortSeasonDataWidget")
	int32 CurrentLevel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSeasonDataWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewards> LevelRewards;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> SocialAvatarIcon;

};

