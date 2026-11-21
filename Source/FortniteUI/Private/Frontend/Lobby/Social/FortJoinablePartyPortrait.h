// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortJoinablePartyPortrait.generated.h"

class UCommonRichTextBlock;
class UCommonVisibilitySwitcher;
class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class UOverlay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortJoinablePartyPortrait : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortJoinablePartyPortrait(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> CommonSwitcher_PortraitState;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyPortrait", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyPortrait", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Portrait;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_RemainingPlayersValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_RemainingPlayers;

	UPROPERTY(EditDefaultsOnly, Category="FortJoinablePartyPortrait")
	FText RemainingPlayersFormat;

};

