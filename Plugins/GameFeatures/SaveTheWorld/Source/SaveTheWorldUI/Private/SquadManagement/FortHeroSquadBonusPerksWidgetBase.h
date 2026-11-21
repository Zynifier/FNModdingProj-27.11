// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SquadManagement/FortSquadStatDetailsWidget.h"
#include "FortHeroSquadBonusPerksWidgetBase.generated.h"

class UFortPerkWidget_NUI;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroSquadBonusPerksWidgetBase : public UFortSquadStatDetailsWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortHeroSquadBonusPerksWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPerkWidget_NUI> SupportBonusPerkWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHeroSquadBonusPerksWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPerkWidget_NUI> TacticalBonusPerkWidget;

};

