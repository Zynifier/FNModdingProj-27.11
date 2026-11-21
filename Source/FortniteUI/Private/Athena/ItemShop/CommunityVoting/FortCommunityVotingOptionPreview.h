// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingOptionPreview.generated.h"

class UCommonBorder;
class UCommonLoadGuard;
class UCommonTextBlock;
class UFortCommunityVotingManager;
class UImage;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingOptionPreview : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayHoveredAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayUnhoveredAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayVotingAnimation();

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCommunityVotingManager> VotingManager;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ShortDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> CommonBorder_Owned;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_Owned;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> LoadGuard;

};

