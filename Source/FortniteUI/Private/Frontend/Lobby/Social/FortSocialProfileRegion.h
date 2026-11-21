// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialProfilePanel.h"
#include "FortSocialProfileRegion.generated.h"

class UCommonTextBlock;
class USizeBox;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileRegion : public UFortSocialProfileSubPanel
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Region;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_Separator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Language;

};

