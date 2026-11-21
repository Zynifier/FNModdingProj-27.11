// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortCreativeCreditsTeamTitleCard.generated.h"

class UCommonTextBlock;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeCreditsTeamTitleCard : public UCommonButtonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreatorTitle;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreatorName;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreatorDescription;

};

