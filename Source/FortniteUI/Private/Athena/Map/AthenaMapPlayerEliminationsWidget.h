// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Components/FortPlayerStateComponent_Habanero.h"
#include "AthenaMapPlayerEliminationsWidget.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapPlayerEliminationsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ResetRankedProgress();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRankedProgress(const FRankedProgressReplicatedData& RankedProgress);

	UPROPERTY(EditDefaultsOnly, Category="AthenaMapPlayerEliminationsWidget")
	FGameplayTag PlayerBotTag;

private:
	UPROPERTY(EditDefaultsOnly, Category="Material Paramaters", meta=(DisplayName="Player Icon Texture"))
	FName ParamName_PlayerIconTexture;

	UPROPERTY(EditDefaultsOnly, Category="Material Paramaters", meta=(DisplayName="Player Icon Background Color"))
	FName ParamName_PlayerIconBackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMapPlayerEliminationsWidget", meta=(AllowPrivateAccess))
	bool bIsLocalPlayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlayerIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapPlayerEliminationsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapPlayerEliminationsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ElimCount;

};

