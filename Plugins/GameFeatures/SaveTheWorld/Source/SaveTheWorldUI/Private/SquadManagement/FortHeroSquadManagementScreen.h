// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SquadManagement/FortSquadManagementScreenBase.h"
#include "FortHeroSquadManagementScreen.generated.h"

class UFortCharacter;
class UFortHeroSquadBonusPerksWidgetBase;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroSquadManagementScreen : public UFortSquadManagementScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void PlayFeedbackForSlottingPerson(UFortCharacter* Character, int32 SlotIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen")
	FDataTableRowHandle ManageDefendersInputActionRowHandle;

	UPROPERTY(BlueprintReadOnly, Export, Category="Squad Management Screen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHeroSquadBonusPerksWidgetBase> BonusPerksWidget;

};

