// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortTeamMemberEntryBase.h"
#include "FortTeamMemberPedestalFeatInfo.generated.h"

class UCommonTextBlock;
class UFortLazyImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortTeamMemberPedestalFeatInfo : public UFortTeamMemberEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFeatDefinitionSet();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FeatName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FeatDesc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_FeatIcon;

};

