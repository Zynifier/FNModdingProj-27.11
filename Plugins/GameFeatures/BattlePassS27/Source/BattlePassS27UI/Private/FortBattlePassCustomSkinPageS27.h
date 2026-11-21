// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomSkin/FortBattlePassCustomSkinPageBase.h"
#include "FortBattlePassCustomSkinPageS27.generated.h"

class UFortBattlePassTutorialTooltip;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBattlePassCustomSkinPageS27 : public UFortBattlePassCustomSkinPageBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	FString ClaimBaseItemTooltip_ClaimCheckTemplateId;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassTutorialTooltip> TutorialTooltip_ClaimBaseItem;

};

