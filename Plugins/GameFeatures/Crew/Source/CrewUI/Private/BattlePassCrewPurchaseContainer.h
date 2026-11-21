// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "BattlePassCrewPurchaseContainer.generated.h"

class UBattlePassPurchaseScreen;
class UCommonActivatableWidgetSwitcher;
class UCrewSubscriptionErrorModal;
class UWidgetAnimation;
enum class EBattlePassCrewContentState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBattlePassCrewPurchaseContainer : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnContentStateUpdated(EBattlePassCrewContentState InState, bool bInScreenOpened);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTriggerIntroAnimation(bool bCanClaimRewards);

private:
	UPROPERTY(EditDefaultsOnly, Category="BattlePassCrewPurchaseContainer")
	float CrewUpsellTransitionDelayTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassCrewPurchaseContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_ContentContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassCrewPurchaseContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassPurchaseScreen> BattlePassPurchaseScreen;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animations", meta=(AllowPrivateAccess, BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Intro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animations", meta=(AllowPrivateAccess, BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> QuickIntro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Animations", meta=(AllowPrivateAccess, BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> CrewBenefitsIntro;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassCrewPurchaseContainer", meta=(AllowPrivateAccess))
	TSubclassOf<UCrewSubscriptionErrorModal> CrewSubscriptionErrorModalClass;

};

